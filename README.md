Example Project to compile and run bare metal arm code using arm-none-eabi-gcc and qemu.
can be used for running tests using the same compiler as the real hardware.

    cmake -B build .
    cmake --build build
    cmake --build build -t run
