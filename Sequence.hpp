#ifndef GALACTIC_SEQUENCE_H
#define GALACTIC_SEQUENCE_H

#include <vector>
#include <cstdint>
#include "libraries/pico_graphics/pico_graphics.hpp"
#include "galactic_unicorn.hpp"

using namespace pimoroni;

class Sequence
{
public:
    Sequence(GalacticUnicorn& galacticUnicorn, PicoGraphics_PenRGB888& graphics, uint8_t triggerButton);
    ~Sequence();

    void addSequence(const std::function<void()>& drawFunction);
    void begin();
    void draw();
    void progress();
    void checkButtonPress();

private:
    GalacticUnicorn galacticUnicorn;
    PicoGraphics_PenRGB888 graphics;
    uint8_t triggerButton;
    bool pressedButton;

    uint8_t currentSequence = 0;
    std::vector<std::function<void()>> sequences;
};

#endif //GALACTIC_SEQUENCE_H
