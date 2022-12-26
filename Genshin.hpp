#ifndef GALACTIC_GENSHIN_HPP
#define GALACTIC_GENSHIN_HPP

#include "Color.hpp"
#include "libraries/pico_graphics/pico_graphics.hpp"
#include "Element.hpp"
#include "Sequence.hpp"

using namespace pimoroni;

static const int ICON_SIZE = 11;

class Genshin
{
public:
    Genshin(GalacticUnicorn& galacticUnicorn, PicoGraphics_PenRGB888& graphics);
    ~Genshin();

    static const int ELEMENT_COUNT = 7;
    static Element elements[ELEMENT_COUNT];

    void startSequence();
    void checkSequenceButton();

    void loadIcons();
    void drawElement(const Element& element);
    void drawIcon(const std::string& name, Point pos);
    void drawIcons();
private:
    Sequence* sequence;
    GalacticUnicorn galacticUnicorn;
    PicoGraphics_PenRGB888 graphics;
    std::unordered_map<std::string, std::vector<std::vector<Color>>> icons;

    int iconTail;
    constexpr static const float SCROLL_SPEED = 1.0f;
    std::unordered_map<std::string, Point> movingIcons;
};

#endif //GALACTIC_GENSHIN_HPP
