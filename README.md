# ansi-escape-demo

A simple cmake based multi-platform project illustrating ansi escape codes.

#### Building

Use catnip in the source directory. You can install this using devkitPro pacman.
On windows under msys2 use `pacman -S catnip`, on linux with native pacman use
`sudo pacman -S catnip`, on linux using devkitPro pacman and macOS use
`sudo dkp-pacman -S catnip`

To build use `catnip -T <toolset>` where toolset is one of 3ds, wii, gamecube
or switch. You can explicitly set a build directory with -B


See https://github.com/devkitPro/catnip/blob/master/README.md for more catnip
usage instructions.