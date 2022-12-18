#ifndef GALACTIC_GENSHIN_H
#define GALACTIC_GENSHIN_H

#include "pixel.h"
#include "libraries/pico_graphics/pico_graphics.hpp"
using namespace pimoroni;

static const int ICON_SIZE = 11;

class Genshin
{
public:
    Genshin();
    ~Genshin();

    void loadIcons();
    void drawIcon(const std::string& name, Point pos, PicoGraphics_PenRGB888& graphics);
    void drawIcons(Point pos, PicoGraphics_PenRGB888& graphics);
private:
    std::unordered_map<std::string, std::vector<std::vector<Pixel>>> icons;
};

#endif //GALACTIC_GENSHIN_H
