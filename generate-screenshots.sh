#!/bin/bash

# Change this depending on what device you're generating the screenshots on
fb_res=1920x1080
fb_depth=8
fb_format=rgba

unl0kr=$1
outdir=screenshots

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

if [[ ! -x $unl0kr ]]; then
    echo "Error: Could not find unl0kr executable at $unl0kr" 1>&2
    exit 1
fi

exec 1>/dev/null
exec 2>/dev/null 

rm -rf "$outdir"
mkdir "$outdir"

for res in ${resolutions[@]}; do
    for theme in light dark; do
        CRYPTTAB_SOURCE=/dev/sda1 $unl0kr -g $res -c unl0kr-screenshots.conf -C unl0kr-screenshots-$theme.conf &
        pid=$!

        sleep 2 

        cat /dev/fb0 > "$outdir/$res"
        convert -size $fb_res -depth $fb_depth $fb_format:"$outdir/$res" -crop $res+0+0 "$outdir/$theme-$res.png"
        rm "$outdir/$res"
        kill -9 $pid
    done
done
