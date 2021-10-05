/**
 * Copyright 2021 Johannes Marbach
 *
 * This file is part of unl0kr, hereafter referred to as the program.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */


#include "themes.h"


/**
 * Breezy light (based on KDE Breeze color palette, see https://develop.kde.org/hig/style/color/default/)
 */

ul_theme ul_themes_breezy_light = {
    .window = {
        .bg_color = 0xeff0f1
    },
    .header = {
        .bg_color = 0xfcfcfc,
        .border_width = 1,
        .border_color = 0xbdc3c7,
        .pad = 10,
        .gap = 10
    },
    .keyboard = {
        .bg_color = 0xfcfcfc,
        .border_width = 1,
        .border_color = 0xbdc3c7,
        .pad = 10,
        .gap = 10,
        .keys = {
            .border_width = 1,
            .corner_radius = 5,
            .key_char = {
                .normal = {
                    .fg_color = 0x232629,
                    .bg_color = 0xeff0f1,
                    .border_color = 0xbdc3c7
                },
                .pressed = {
                    .fg_color = 0x232629,
                    .bg_color = 0x3daee9,
                    .border_color = 0x2980b9
                }
            },
            .key_non_char = {
                .normal = {
                    .fg_color = 0x232629,
                    .bg_color = 0xbdc3c7,
                    .border_color = 0x7f8c8d
                },
                .pressed = {
                    .fg_color = 0x232629,
                    .bg_color = 0x3daee9,
                    .border_color = 0x2980b9
                }
            },
            .key_mod_act = {
                .normal = {
                    .fg_color = 0x232629,
                    .bg_color = 0x3daee9,
                    .border_color = 0x2980b9
                },
                .pressed = {
                    .fg_color = 0x232629,
                    .bg_color = 0x3daee9,
                    .border_color = 0x2980b9
                }
            },
            .key_mod_inact = {
                .normal = {
                    .fg_color = 0x232629,
                    .bg_color = 0xbdc3c7,
                    .border_color = 0x7f8c8d
                },
                .pressed = {
                    .fg_color = 0x232629,
                    .bg_color = 0x3daee9,
                    .border_color = 0x2980b9
                }
            }
        }
    },
    .button = {
        .border_width = 1,
        .corner_radius = 5,
        .pad = 5,
        .normal = {
            .fg_color = 0x232629,
            .bg_color = 0xeff0f1,
            .border_color = 0xbdc3c7
        },
        .pressed = {
            .fg_color = 0x232629,
            .bg_color = 0x3daee9,
            .border_color = 0x2980b9
        }
    },
    .textarea = {
        .fg_color = 0x232629,
        .bg_color = 0xfcfcfc,
        .border_width = 1,
        .border_color = 0xbdc3c7,
        .corner_radius = 5,
        .pad = 5,
        .placeholder_color = 0x7f8c8d,
        .cursor = {
            .width = 1,
            .color = 0x232629,
            .period = 700
        }
    },
    .dropdown = {
        .box = {
            .fg_color = 0x232629,
            .bg_color = 0xeff0f1,
            .border_width = 1,
            .border_color = 0xbdc3c7,
            .corner_radius = 5,
            .pad = 5
        },
        .list = {
            .fg_color = 0x232629,
            .bg_color = 0xfcfcfc,
            .selection_fg_color = 0x232629,
            .selection_bg_color = 0x3daee9,
            .border_width = 1,
            .border_color = 0xbdc3c7,
            .corner_radius = 0,
            .pad = 0
        }
    },
    .label = {
        .fg_color = 0x232629
    },
    .msgbox = {
        .fg_color = 0x232629,
        .bg_color = 0xeff0f1,
        .border_width = 1,
        .border_color = 0xbdc3c7,
        .corner_radius = 0,
        .pad = 10,
        .buttons = {
            .pad = 10,
            .gap = 5
        },
        .dimming = {
            .color = 0x232629,
            .opacity = 178
        }
    }
};


/**
 * Breezy dark (based on KDE Breeze Dark color palette, see https://develop.kde.org/hig/style/color/dark/)
 */

ul_theme ul_themes_breezy_dark = {
    .window = {
        .bg_color = 0x31363b
    },
    .header = {
        .bg_color = 0x232629,
        .border_width = 1,
        .border_color = 0x3b4045,
        .pad = 10,
        .gap = 10
    },
    .keyboard = {
        .bg_color = 0x232629,
        .border_width = 1,
        .border_color = 0x3b4045,
        .pad = 10,
        .gap = 10,
        .keys = {
            .border_width = 1,
            .corner_radius = 5,
            .key_char = {
                .normal = {
                    .fg_color = 0xeff0f1,
                    .bg_color = 0x31363b,
                    .border_color = 0x3b4045
                },
                .pressed = {
                    .fg_color = 0xeff0f1,
                    .bg_color = 0x3daee9,
                    .border_color = 0x2980b9
                }
            },
            .key_non_char = {
                .normal = {
                    .fg_color = 0xeff0f1,
                    .bg_color = 0x4d4d4d,
                    .border_color = 0x7f8c8d
                },
                .pressed = {
                    .fg_color = 0xeff0f1,
                    .bg_color = 0x3daee9,
                    .border_color = 0x2980b9
                }
            },
            .key_mod_act = {
                .normal = {
                    .fg_color = 0xeff0f1,
                    .bg_color = 0x3daee9,
                    .border_color = 0x2980b9
                },
                .pressed = {
                    .fg_color = 0xeff0f1,
                    .bg_color = 0x3daee9,
                    .border_color = 0x2980b9
                }
            },
            .key_mod_inact = {
                .normal = {
                    .fg_color = 0xeff0f1,
                    .bg_color = 0x4d4d4d,
                    .border_color = 0x7f8c8d
                },
                .pressed = {
                    .fg_color = 0xeff0f1,
                    .bg_color = 0x3daee9,
                    .border_color = 0x2980b9
                }
            }
        }
    },
    .button = {
        .border_width = 1,
        .corner_radius = 5,
        .pad = 5,
        .normal = {
            .fg_color = 0xeff0f1,
            .bg_color = 0x31363b,
            .border_color = 0x3b4045
        },
        .pressed = {
            .fg_color = 0xeff0f1,
            .bg_color = 0x3daee9,
            .border_color = 0x2980b9
        }
    },
    .textarea = {
        .fg_color = 0xeff0f1,
        .bg_color = 0x232629,
        .border_width = 1,
        .border_color = 0x3b4045,
        .corner_radius = 5,
        .pad = 5,
        .placeholder_color = 0x7f8c8d,
        .cursor = {
            .width = 1,
            .color = 0x232629,
            .period = 700
        }
    },
    .dropdown = {
        .box = {
            .fg_color = 0xeff0f1,
            .bg_color = 0x31363b,
            .border_width = 1,
            .border_color = 0x3b4045,
            .corner_radius = 5,
            .pad = 5
        },
        .list = {
            .fg_color = 0xeff0f1,
            .bg_color = 0x232629,
            .selection_fg_color = 0x232629,
            .selection_bg_color = 0x3daee9,
            .border_width = 1,
            .border_color = 0x3b4045,
            .corner_radius = 0,
            .pad = 0
        }
    },
    .label = {
        .fg_color = 0xeff0f1
    },
    .msgbox = {
        .fg_color = 0xeff0f1,
        .bg_color = 0x31363b,
        .border_width = 1,
        .border_color = 0x3b4045,
        .corner_radius = 0,
        .pad = 10,
        .buttons = {
            .pad = 10,
            .gap = 5
        },
        .dimming = {
            .color = 0x232629,
            .opacity = 178
        }
    }
};
