#include "pico/stdlib.h"

#include "libraries/pico_graphics/pico_graphics.hpp"
#include "galactic_unicorn.hpp"
#include "Genshin.hpp"

using namespace std;
using namespace pimoroni;

// create a PicoGraphics framebuffer to draw into
PicoGraphics_PenRGB888 graphics(GalacticUnicorn::WIDTH, GalacticUnicorn::HEIGHT, nullptr);

// create our GalacticUnicorn object
GalacticUnicorn galactic_unicorn;

std::string message = "Cryo";

int main()
{
    stdio_init_all();

    // initialise the GalacticUnicorn object
    galactic_unicorn.init();

    Genshin genshin(galactic_unicorn, graphics);

    genshin.startSequence();

    while(true)
    {
        if(galactic_unicorn.is_pressed(GalacticUnicorn::SWITCH_BRIGHTNESS_UP))
        {
            galactic_unicorn.adjust_brightness(+0.01);
        }

        if(galactic_unicorn.is_pressed(GalacticUnicorn::SWITCH_BRIGHTNESS_DOWN))
        {
            galactic_unicorn.adjust_brightness(-0.01);
        }

        graphics.set_pen(0, 0, 0);
        graphics.clear();

        if(galactic_unicorn.is_pressed(GalacticUnicorn::SWITCH_SLEEP))
        {
            continue;
        }

        genshin.checkSequenceButton();

        // update the display
        galactic_unicorn.update(&graphics);

        sleep_ms(10);
    }

    return 0;
}