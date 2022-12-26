#ifndef GALACTIC_ELEMENT_HPP
#define GALACTIC_ELEMENT_HPP

struct ElementType
{
    constexpr static const char* Pyro = "Pyro";
    constexpr static const char* Hydro = "Hydro";
    constexpr static const char* Anemo = "Anemo";
    constexpr static const char* Electro = "Electro";
    constexpr static const char* Dendro = "Dendro";
    constexpr static const char* Cryo = "Cryo";
    constexpr static const char* Geo = "Geo";
};

struct Element
{
    Element(const char* type, Color color): type(type), color(color) {};

    const char* type;
    Color color;
};

namespace element
{
    static const Element Pyro = Element(ElementType::Pyro, Color(217, 124, 70));
    static const Element Hydro = Element(ElementType::Hydro, Color(109, 190, 233));
    static const Element Anemo = Element(ElementType::Anemo, Color(125, 177, 157));
    static const Element Electro = Element(ElementType::Electro, Color(169, 142, 189));
    static const Element Dendro = Element(ElementType::Dendro, Color(167, 193, 82));
    static const Element Cryo = Element(ElementType::Cryo, Color(133, 163, 172));
    static const Element Geo = Element(ElementType::Geo, Color(223, 172, 76));
}

#endif //GALACTIC_ELEMENT_HPP