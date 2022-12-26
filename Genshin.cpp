#include "Genshin.hpp"
#include "galactic_unicorn.hpp"

Element Genshin::elements[ELEMENT_COUNT] =
{
    element::Pyro,
    element::Hydro,
    element::Anemo,
    element::Electro,
    element::Dendro,
    element::Cryo,
    element::Geo
};

Genshin::Genshin(GalacticUnicorn& galacticUnicorn, PicoGraphics_PenRGB888& graphics) : galacticUnicorn(galacticUnicorn), graphics(graphics)
{
    iconTail = 53 + (ICON_SIZE * ELEMENT_COUNT); //outside the pixel array + (11 * 7) elements
    Point pos = Point(53, 0);
    for (auto& element: elements)
    {
        movingIcons[element.type] = pos;
        pos.x += ICON_SIZE + 1;
    }
    loadIcons();
}

Genshin::~Genshin()
{

}

void Genshin::loadIcons()
{
    icons["Anemo"] =
    {
        {Color(0, 0, 0), Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),      Color(9, 15, 14),    Color(7, 11, 10),     Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),    Color(0, 0, 0),    Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),     Color(14, 23, 20),   Color(42, 71, 62),   Color(42, 73, 62),   Color(104, 174, 152), Color(33, 56, 49),  Color(0, 0, 0),      Color(0, 0, 0),    Color(0, 0, 0),    Color(0, 0, 0) },
        {Color(0, 0, 0), Color(5, 10, 9),    Color(47, 78, 67),   Color(53, 89, 75),   Color(95, 161, 139), Color(59, 98, 84),    Color(66, 111, 96), Color(0, 0, 0),      Color(0, 0, 0),    Color(0, 0, 0),    Color(0, 0, 0) },
        {Color(1, 2, 2), Color(63, 105, 92), Color(70, 118, 102), Color(92, 155, 134), Color(66, 111, 96),  Color(63, 104, 90),   Color(42, 71, 62),  Color(2, 4, 4),      Color(0, 0, 0),    Color(0, 0, 0),    Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),      Color(40, 68, 58),   Color(47, 78, 68),    Color(31, 53, 45),  Color(55, 92, 80),   Color(59, 98, 86), Color(1, 2, 1),    Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(6, 13, 12),     Color(50, 84, 73),  Color(71, 117, 102), Color(55, 92, 80), Color(60, 99, 86), Color(1, 2, 1) },
        {Color(0, 0, 0), Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),      Color(41, 68, 59),   Color(47, 78, 68),    Color(31, 52, 46),  Color(55, 93, 80),   Color(59, 98, 84), Color(1, 2, 1),    Color(0, 0, 0) },
        {Color(1, 2, 2), Color(64, 107, 92), Color(72, 121, 104), Color(94, 156, 136), Color(65, 109, 94),  Color(63, 104, 90),   Color(43, 71, 61),  Color(2, 4, 4),      Color(0, 0, 0),    Color(0, 0, 0),    Color(0, 0, 0) },
        {Color(0, 0, 0), Color(6, 9, 9),     Color(45, 76, 66),   Color(53, 89, 75),   Color(95, 161, 139), Color(59, 97, 86),    Color(66, 111, 96), Color(0, 0, 0),      Color(0, 0, 0),    Color(0, 0, 0),    Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),     Color(14, 23, 20),   Color(42, 71, 62),   Color(42, 71, 62),   Color(104, 174, 152), Color(32, 56, 48),  Color(0, 0, 0),      Color(0, 0, 0),    Color(0, 0, 0),    Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),      Color(9, 14, 13),    Color(7, 11, 10),     Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),    Color(0, 0, 0),    Color(0, 0, 0) }
    };

    icons["Cryo"] =
    {
        {Color(0, 0, 0),    Color(0, 0, 0),       Color(1, 1, 1),      Color(0, 0, 0),       Color(0, 0, 0),      Color(0, 0, 0),       Color(0, 0, 0),      Color(0, 0, 0),       Color(1, 1, 1),      Color(0, 0, 0),       Color(0, 0, 0) },
        {Color(0, 0, 0),    Color(0, 0, 0),       Color(14, 20, 21),   Color(66, 89, 95),    Color(17, 23, 24),   Color(0, 0, 0),       Color(18, 24, 25),   Color(67, 90, 96),    Color(14, 19, 20),   Color(0, 0, 0),       Color(0, 0, 0) },
        {Color(0, 0, 0),    Color(0, 0, 0),       Color(17, 23, 24),   Color(110, 149, 158), Color(85, 114, 121), Color(26, 35, 37),    Color(86, 115, 122), Color(110, 148, 157), Color(16, 22, 24),   Color(0, 0, 0),       Color(0, 0, 0) },
        {Color(0, 0, 0),    Color(0, 0, 0),       Color(9, 12, 13),    Color(72, 98, 104),   Color(80, 108, 114), Color(29, 40, 42),    Color(80, 108, 114), Color(71, 96, 102),   Color(8, 11, 12),    Color(0, 0, 0),       Color(0, 0, 0) },
        {Color(1, 2, 2),    Color(26, 35, 37),    Color(61, 82, 87),   Color(27, 36, 39),    Color(64, 86, 91),   Color(85, 114, 121),  Color(66, 89, 95),   Color(28, 37, 40),    Color(61, 83, 88),   Color(26, 36, 38),    Color(2, 3, 3) },
        {Color(29, 40, 42), Color(112, 151, 160), Color(94, 126, 134), Color(79, 106, 113),  Color(81, 109, 116), Color(108, 146, 154), Color(87, 118, 125), Color(80, 108, 114),  Color(93, 125, 133), Color(112, 151, 160), Color(29, 40, 42) },
        {Color(2, 3, 3),    Color(26, 36, 38),    Color(61, 83, 88),   Color(27, 36, 39),    Color(64, 86, 91),   Color(86, 115, 122),  Color(67, 91, 97),   Color(28, 37, 40),    Color(61, 82, 87),   Color(26, 35, 37),    Color(1, 2, 2) },
        {Color(0, 0, 0),    Color(0, 0, 0),       Color(8, 11, 12),    Color(71, 96, 102),   Color(80, 108, 114), Color(29, 40, 42),    Color(80, 108, 114), Color(72, 98, 104),   Color(9, 12, 13),    Color(0, 0, 0),       Color(0, 0, 0) },
        {Color(0, 0, 0),    Color(0, 0, 0),       Color(16, 22, 24),   Color(110, 148, 157), Color(86, 115, 122), Color(26, 35, 37),    Color(85, 114, 121), Color(110, 149, 158), Color(17, 23, 24),   Color(0, 0, 0),       Color(0, 0, 0) },
        {Color(0, 0, 0),    Color(0, 0, 0),       Color(14, 19, 20),   Color(67, 90, 96),    Color(18, 24, 25),   Color(0, 0, 0),       Color(17, 23, 24),   Color(66, 89, 95),    Color(14, 20, 21),   Color(0, 0, 0),       Color(0, 0, 0) },
        {Color(0, 0, 0),    Color(0, 0, 0),       Color(1, 1, 1),      Color(0, 0, 0),       Color(0, 0, 0),      Color(0, 0, 0),       Color(0, 0, 0),      Color(0, 0, 0),       Color(1, 1, 1),      Color(0, 0, 0),       Color(0, 0, 0) }
    };

    icons["Dendro"] =
    {
        {Color(0, 0, 0), Color(0, 0, 0),      Color(4, 4, 2),      Color(1, 1, 0),      Color(0, 0, 0),      Color(6, 8, 2),      Color(23, 27, 8),  Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),      Color(37, 45, 12),   Color(104, 127, 37), Color(33, 40, 12),   Color(73, 89, 26),   Color(62, 74, 21), Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),      Color(0, 0, 0),      Color(75, 90, 26),   Color(50, 59, 16),   Color(22, 28, 8),    Color(73, 90, 26), Color(93, 112, 32), Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),      Color(2, 2, 1),      Color(82, 99, 30),   Color(102, 123, 35), Color(119, 144, 43), Color(57, 70, 20), Color(71, 87, 26),  Color(49, 60, 18),   Color(0, 0, 0),      Color(0, 0, 0) },
        {Color(0, 0, 0), Color(6, 9, 3),      Color(19, 24, 7),    Color(91, 109, 31),  Color(34, 40, 12),   Color(0, 0, 0),      Color(24, 31, 9),  Color(7, 8, 2),     Color(122, 149, 43), Color(8, 8, 3),      Color(0, 0, 0) },
        {Color(4, 4, 2), Color(128, 156, 46), Color(158, 192, 56), Color(53, 63, 17),   Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),    Color(0, 0, 0),     Color(46, 56, 16),   Color(104, 124, 37), Color(2, 2, 1) },
        {Color(0, 0, 0), Color(6, 9, 3),      Color(19, 24, 7),    Color(91, 109, 31),  Color(34, 41, 12),   Color(0, 0, 0),      Color(27, 34, 9),  Color(8, 10, 2),    Color(124, 149, 44), Color(8, 8, 3),      Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),      Color(2, 2, 1),      Color(82, 99, 30),   Color(102, 123, 37), Color(119, 145, 42), Color(58, 71, 21), Color(72, 87, 25),  Color(50, 60, 18),   Color(0, 0, 0),      Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),      Color(0, 0, 0),      Color(74, 91, 27),   Color(51, 60, 18),   Color(23, 28, 7),    Color(75, 90, 26), Color(93, 112, 32), Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),      Color(37, 45, 12),   Color(104, 127, 37), Color(31, 39, 11),   Color(73, 89, 26),   Color(61, 74, 21), Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),      Color(4, 4, 2),      Color(1, 1, 0),      Color(0, 0, 0),      Color(6, 8, 2),      Color(23, 27, 7),  Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0) }
    };

    icons["Electro"] =
    {
        {Color(0, 0, 0), Color(0, 0, 0),    Color(0, 0, 0),       Color(0, 0, 0),       Color(0, 0, 0),       Color(0, 0, 0),       Color(0, 0, 0),    Color(0, 0, 0),       Color(0, 0, 0),       Color(0, 0, 0),       Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),    Color(2, 2, 2),       Color(70, 57, 77),    Color(135, 109, 148), Color(135, 110, 149), Color(87, 70, 96), Color(24, 18, 25),    Color(0, 0, 0),       Color(0, 0, 0),       Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),    Color(37, 30, 41),    Color(115, 94, 127),  Color(120, 98, 133),  Color(4, 4, 5),       Color(0, 0, 0),    Color(0, 0, 0),       Color(0, 0, 0),       Color(0, 0, 0),       Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),    Color(21, 17, 23),    Color(174, 141, 192), Color(49, 40, 54),    Color(0, 0, 0),       Color(25, 21, 29), Color(63, 52, 70),    Color(3, 3, 4),       Color(2, 2, 2),       Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),    Color(31, 25, 34),    Color(166, 135, 183), Color(89, 72, 99),    Color(1, 1, 1),       Color(32, 26, 35), Color(175, 142, 193), Color(126, 101, 139), Color(37, 30, 41),    Color(0, 0, 0) },
        {Color(0, 0, 0), Color(8, 7, 8),    Color(1, 1, 2),       Color(36, 28, 38),    Color(15, 12, 16),    Color(118, 96, 131),  Color(55, 45, 60), Color(62, 51, 68),    Color(162, 131, 179), Color(118, 96, 131),  Color(0, 0, 0) },
        {Color(0, 0, 0), Color(74, 61, 82), Color(0, 0, 0),       Color(0, 0, 0),       Color(0, 0, 0),       Color(60, 48, 65),    Color(0, 0, 0),    Color(0, 0, 0),       Color(85, 69, 93),    Color(137, 111, 151), Color(0, 0, 0) },
        {Color(0, 0, 0), Color(76, 61, 84), Color(105, 85, 116),  Color(40, 32, 44),    Color(85, 70, 94),    Color(148, 119, 162), Color(45, 37, 50), Color(0, 0, 0),       Color(80, 66, 88),    Color(73, 60, 80),    Color(0, 0, 0) },
        {Color(0, 0, 0), Color(3, 3, 4),    Color(127, 104, 140), Color(148, 120, 162), Color(144, 118, 159), Color(102, 81, 112),  Color(8, 7, 8),    Color(2, 2, 2),       Color(100, 81, 111),  Color(2, 2, 2),       Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),    Color(2, 2, 2),       Color(58, 47, 64),    Color(14, 10, 14),    Color(0, 0, 0),       Color(0, 0, 0),    Color(12, 9, 12),     Color(4, 4, 4),       Color(0, 0, 0),       Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),    Color(0, 0, 0),       Color(0, 0, 0),       Color(0, 0, 0),       Color(0, 0, 0),       Color(0, 0, 0),    Color(0, 0, 0),       Color(0, 0, 0),       Color(0, 0, 0),       Color(0, 0, 0) }
    };

    icons["Geo"] =
    {
        {Color(0, 0, 0), Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),     Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),      Color(19, 14, 4),    Color(117, 84, 22),  Color(11, 7, 1),     Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),     Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),     Color(0, 0, 0),      Color(33, 24, 7),    Color(83, 61, 15),   Color(190, 137, 38), Color(208, 152, 41), Color(39, 29, 8),    Color(0, 0, 0),      Color(0, 0, 0),     Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),     Color(58, 42, 12),   Color(219, 159, 43), Color(228, 166, 45), Color(77, 55, 14),   Color(75, 55, 14),   Color(202, 147, 41), Color(54, 39, 10),   Color(0, 0, 0),     Color(0, 0, 0) },
        {Color(0, 0, 0), Color(42, 31, 8),   Color(146, 105, 29), Color(95, 68, 19),   Color(144, 104, 28), Color(159, 115, 31), Color(176, 129, 34), Color(56, 40, 10),   Color(157, 114, 32), Color(42, 31, 8),   Color(0, 0, 0) },
        {Color(0, 0, 0), Color(128, 94, 25), Color(7, 4, 0),      Color(212, 154, 43), Color(59, 43, 11),   Color(59, 44, 11),   Color(61, 44, 11),   Color(213, 155, 42), Color(7, 4, 0),      Color(127, 92, 26), Color(0, 0, 0) },
        {Color(0, 0, 0), Color(42, 31, 8),   Color(158, 116, 31), Color(57, 40, 10),   Color(176, 129, 34), Color(159, 115, 31), Color(147, 107, 28), Color(96, 69, 18),   Color(146, 105, 29), Color(41, 31, 7),   Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),     Color(56, 40, 10),   Color(203, 147, 40), Color(77, 56, 14),   Color(77, 55, 14),   Color(228, 166, 45), Color(219, 159, 43), Color(56, 40, 10),   Color(0, 0, 0),     Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),     Color(0, 0, 0),      Color(39, 29, 8),    Color(208, 152, 41), Color(191, 139, 38), Color(83, 61, 15),   Color(31, 23, 5),    Color(0, 0, 0),      Color(0, 0, 0),     Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),      Color(11, 7, 1),     Color(116, 84, 23),  Color(18, 12, 4),    Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),     Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),     Color(0, 0, 0) }
    };

    icons["Hydro"] =
    {
        {Color(0, 0, 0), Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),     Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),      Color(0, 0, 0),      Color(17, 46, 59),   Color(3, 6, 9),      Color(50, 130, 162), Color(3, 9, 11),     Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),     Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),      Color(40, 103, 128), Color(72, 184, 229), Color(11, 26, 34),   Color(17, 45, 57),   Color(0, 1, 1),      Color(36, 95, 118),  Color(0, 0, 0),      Color(0, 0, 0),     Color(0, 0, 0) },
        {Color(0, 0, 0), Color(21, 51, 64),   Color(75, 192, 239), Color(19, 48, 60),   Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(2, 5, 6),      Color(4, 8, 11),     Color(11, 29, 37),  Color(0, 0, 0) },
        {Color(0, 0, 0), Color(48, 123, 153), Color(57, 148, 183), Color(16, 39, 50),   Color(60, 153, 190), Color(0, 0, 0),      Color(40, 105, 130), Color(48, 124, 154), Color(34, 89, 111),  Color(25, 67, 85),  Color(0, 0, 0) },
        {Color(0, 0, 0), Color(57, 148, 183), Color(46, 120, 150), Color(28, 74, 92),   Color(65, 166, 206), Color(0, 0, 0),      Color(70, 179, 223), Color(13, 34, 43),   Color(14, 34, 42),   Color(30, 76, 94),  Color(0, 0, 0) },
        {Color(0, 0, 0), Color(49, 124, 154), Color(61, 155, 193), Color(15, 39, 48),   Color(75, 191, 238), Color(12, 31, 39),   Color(39, 100, 123), Color(59, 150, 188), Color(5, 13, 17),    Color(33, 84, 104), Color(0, 0, 0) },
        {Color(0, 0, 0), Color(19, 48, 59),   Color(76, 194, 241), Color(25, 63, 78),   Color(43, 108, 135), Color(67, 171, 213), Color(29, 74, 93),   Color(24, 61, 76),   Color(47, 120, 148), Color(19, 50, 63),  Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),      Color(38, 95, 119),  Color(73, 188, 234), Color(38, 96, 120),  Color(30, 79, 98),   Color(44, 111, 137), Color(55, 142, 176), Color(35, 89, 111),  Color(0, 0, 0),     Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),      Color(0, 0, 0),      Color(18, 46, 56),   Color(46, 118, 147), Color(57, 148, 183), Color(48, 124, 154), Color(19, 49, 62),   Color(0, 0, 0),      Color(0, 0, 0),     Color(0, 0, 0) },
        {Color(0, 0, 0), Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),     Color(0, 0, 0) }
    };

    icons["Pyro"] =
    {
        {Color(0, 0, 0),  Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),     Color(0, 0, 0),     Color(0, 0, 0),     Color(0, 0, 0),     Color(0, 0, 0) },
        {Color(0, 0, 0),  Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),     Color(0, 0, 0),      Color(6, 3, 1),      Color(74, 36, 17),  Color(59, 30, 14),  Color(0, 0, 0),     Color(0, 0, 0),     Color(0, 0, 0) },
        {Color(0, 0, 0),  Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),     Color(29, 14, 7),    Color(152, 76, 35),  Color(132, 66, 30), Color(117, 58, 26), Color(59, 30, 14),  Color(0, 0, 0),     Color(0, 0, 0) },
        {Color(0, 0, 0),  Color(0, 0, 0),     Color(0, 0, 0),      Color(41, 21, 10),  Color(219, 111, 51), Color(230, 117, 54), Color(133, 66, 31), Color(126, 65, 29), Color(117, 58, 26), Color(6, 4, 2),     Color(0, 0, 0) },
        {Color(0, 0, 0),  Color(0, 0, 0),     Color(98, 49, 22),   Color(192, 97, 45), Color(145, 74, 34),  Color(124, 63, 28),  Color(52, 27, 12),  Color(152, 76, 35), Color(93, 46, 22),  Color(104, 53, 23), Color(0, 0, 0) },
        {Color(13, 7, 3), Color(178, 90, 41), Color(230, 117, 54), Color(152, 76, 35), Color(175, 88, 41),  Color(80, 41, 18),   Color(121, 61, 28), Color(0, 0, 0),     Color(42, 21, 10),  Color(111, 55, 25), Color(37, 18, 9) },
        {Color(0, 0, 0),  Color(13, 7, 3),    Color(34, 16, 8),    Color(104, 53, 25), Color(151, 76, 36),  Color(114, 57, 27),  Color(172, 86, 40), Color(112, 56, 27), Color(79, 39, 18),  Color(114, 57, 27), Color(0, 0, 0) },
        {Color(0, 0, 0),  Color(0, 0, 0),     Color(0, 0, 0),      Color(42, 22, 9),   Color(176, 89, 41),  Color(217, 110, 50), Color(141, 72, 32), Color(133, 66, 31), Color(155, 78, 36), Color(11, 6, 3),    Color(0, 0, 0) },
        {Color(0, 0, 0),  Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),     Color(6, 4, 2),      Color(150, 75, 34),  Color(105, 54, 24), Color(99, 51, 23),  Color(74, 36, 17),  Color(0, 0, 0),     Color(0, 0, 0) },
        {Color(0, 0, 0),  Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),     Color(0, 0, 0),      Color(3, 1, 1),      Color(68, 34, 16),  Color(50, 24, 12),  Color(0, 0, 0),     Color(0, 0, 0),     Color(0, 0, 0) },
        {Color(0, 0, 0),  Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),     Color(0, 0, 0),      Color(0, 0, 0),      Color(0, 0, 0),     Color(0, 0, 0),     Color(0, 0, 0),     Color(0, 0, 0),     Color(0, 0, 0) }
    };

    icons["Primogem"] =
    {
        { Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0) },
        { Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(15,17,20),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0) },
        { Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(15,15,17),Color(186,207,221),Color(12,16,19),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0) },
        { Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(138,129,137),Color(198,222,251),Color(90,122,141),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0) },
        { Color(0,0,0),Color(0,0,0),Color(39,34,37),Color(160,149,147),Color(248,228,236),Color(189,213,249),Color(153,218,251),Color(106,136,161),Color(26,34,40),Color(0,0,0),Color(0,0,0) },
        { Color(0,0,0),Color(68,61,66),Color(249,222,215),Color(252,222,219),Color(245,225,237),Color(207,219,251),Color(184,225,254),Color(168,216,253),Color(164,211,248),Color(46,60,68),Color(0,0,0) },
        { Color(0,0,0),Color(0,0,0),Color(38,34,38),Color(152,136,151),Color(207,214,248),Color(163,205,251),Color(106,201,249),Color(96,143,159),Color(25,33,39),Color(0,0,0),Color(0,0,0) },
        { Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(99,124,138),Color(144,210,251),Color(80,123,141),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0) },
        { Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(12,14,17),Color(125,187,221),Color(11,16,19),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0) },
        { Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(13,16,18),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0) },
        { Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0),Color(0,0,0) }
    };
}

void Genshin::drawIcon(const std::string& name, Point pos = Point(0, 0))
{
    std::vector<std::vector<Color>> icon = icons[name];

    for (int row = 0; row < icon.size(); row++)
    {
        for (int column = 0; column < icon[row].size(); column++)
        {
            Color pixel = icon[row][column];
            graphics.set_pen(pixel.r, pixel.g, pixel.b);
            graphics.pixel(pos + Point(row, column));
        }
    }
}

void Genshin::drawIcons()
{
    for (auto& element: elements)
    {
        Point& elementLocation = movingIcons[element.type];
        elementLocation.x -= SCROLL_SPEED;

        if (elementLocation.x <= -ICON_SIZE)
        {
            elementLocation = Point(iconTail, 0);
            iconTail += ICON_SIZE + 1;
        }

        drawIcon(element.type, elementLocation);

        sleep_ms(5);
    }

    iconTail -= SCROLL_SPEED;
}

void Genshin::drawElement(const Element& element)
{
    Point location(0,0);
    drawIcon(element.type, location);

    location += Point(ICON_SIZE + 1, 2);
    graphics.set_pen(element.color.r, element.color.g, element.color.b);
    graphics.text(element.type, location, -1, 1.0f);
}

void Genshin::startSequence()
{
    sequence = new Sequence(galacticUnicorn, graphics, GalacticUnicorn::SWITCH_A);

    sequence->addSequence([this]
    {
        this->drawIcon("Primogem");
        this->graphics.set_pen(255,255,255);
        this->graphics.text("Genshin", Point(ICON_SIZE + 1,2), -1, 1.0f);
    });

    for (auto& element: elements)
    {
        sequence->addSequence([this, element]
        {
            this->drawElement(element);
        });
    }

    sequence->addSequence([this]
    {
        this->drawIcons();
    });

    sequence->begin();
}

void Genshin::checkSequenceButton()
{
    this->sequence->checkButtonPress();
    this->sequence->draw();
}
