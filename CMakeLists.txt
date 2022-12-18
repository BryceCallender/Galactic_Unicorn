cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)
include(pimoroni_pico_import.cmake)

set(NAME galactic)

project(${NAME})
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# Initialize the SDK
pico_sdk_init()

include(${PIMORONI_PICO_PATH}/libraries/pico_graphics/pico_graphics.cmake)
include(${PIMORONI_PICO_PATH}/libraries/galactic_unicorn/galactic_unicorn.cmake)
include(${PIMORONI_PICO_PATH}/libraries/bitmap_fonts/bitmap_fonts.cmake)
include(${PIMORONI_PICO_PATH}/libraries/hershey_fonts/hershey_fonts.cmake)

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        )

set(SOURCE_FILES main.cpp Genshin.h Genshin.cpp)

add_executable(${NAME} ${SOURCE_FILES})
target_link_libraries(${NAME}
        pico_stdlib
        pico_graphics
        galactic_unicorn
        )

file(COPY images DESTINATION ${CMAKE_BINARY_DIR})

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})