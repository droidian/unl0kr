#!/bin/bash

# Change this depending on what device you're generating the screenshots on
fb_res=1920x1080
fb_depth=8
fb_format=rgba

unl0kr=$1
outdir=screenshots
config=unl0kr-screenshots.conf

themes=(
    breezy-light
    breezy-dark
    pmos-light
    pmos-dark
)

resolutions=(
    # Nokia N900
    480x800
    800x480
    # Samsung Galaxy A3 2015
    540x960
    960x540
    # Samsung Galaxy Tab A 8.0 2015
    768x1024
    1024x768
    # Pine64 PineTab (landscape)
    1280x800
    # Pine64 PinePhone (landscape)
    1440x720
    # BQ Aquaris X Pro (landscape)
    1920x1080 
)

if [[ ! -f $unl0kr || ! -x $unl0kr ]]; then
    echo "Error: Could not find unl0kr executable at $unl0kr" 1>&2
    exit 1
fi

exec 1>/dev/null
exec 2>/dev/null 

function write_config() {
    cat << EOF > $config
[general]
animations=true

[keyboard]
autohide=false
layout=de
popovers=true

[textarea]
obscured=true

[theme]
default=$1
EOF
}

function nuke_config() {
    rm -f $config
}

trap "nuke_config" EXIT

rm -rf "$outdir"
mkdir "$outdir"

readme="# Unl0kr themes"$'\n'

for theme in ${themes[@]}; do
    write_config $theme

    readme="$readme"$'\n'"## $theme"$'\n\n'
    
    for res in ${resolutions[@]}; do    
        CRYPTTAB_SOURCE=/dev/sda1 $unl0kr -g $res -c unl0kr-screenshots.conf &
        pid=$!

        sleep 1

        cat /dev/fb0 > "$outdir/$res"
        convert -size $fb_res -depth $fb_depth $fb_format:"$outdir/$res" -crop $res+0+0 "$outdir/$theme-$res.png"
        rm "$outdir/$res"
        kill -15 $pid

        readme="$readme<img src=\"$theme-$res.png\" alt=\"$res\" height=\"300\"/>"$'\n'

        sleep 1 # Delay to prevent terminal mode set / reset interference
    done
done

echo -n "$readme" > "$outdir/README.md"
