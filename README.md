# qlock

## Development

### Build

CMake is used to manage builds.

1. `mkdir build && cd build`
2. `cmake ..`
3. `make`
    - If `make` doesn't work off the bat, try `make libopencm3` then `make`.

### Flash

The `.elf` binary can be flashed in one step:

1. `openocd -f board/st_nucleo_f4.cfg -c 'program build/qlock.elf reset exit'`

### Debug

To debug, we need to start an OpenOCD session and then start `gdb`. The `.gdbinit` file in this directory will connect
to `localhost:3333` and load the binary + symbols for debugging.

1. `openocd -f board/st_nucleo_f4.cfg`
2. `arm-none-eabi-gdb`