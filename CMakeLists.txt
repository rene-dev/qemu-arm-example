cmake_minimum_required(VERSION 3.14)
set(CMAKE_TOOLCHAIN_FILE ./arm-none-eabi-gcc.cmake)
enable_language(C ASM)

project(qemu-test)

add_executable(${PROJECT_NAME}.elf
    test.c
    startup.s
)

target_compile_options(${PROJECT_NAME}.elf PRIVATE
    #-mthumb
    #-mcpu=cortex-m3
    -mcpu=arm926ej-s
    #-O2
    #$<$<COMPILE_LANGUAGE:CXX>:-Wno-volatile>
)

add_custom_target(run
    COMMAND qemu-system-arm -M versatilepb -m 128M -nographic -semihosting -kernel ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.elf
)

target_link_options(${PROJECT_NAME}.elf PRIVATE
    -T ${CMAKE_SOURCE_DIR}/test.ld
    --specs=rdimon.specs
    -lrdimon
    -lc
)
