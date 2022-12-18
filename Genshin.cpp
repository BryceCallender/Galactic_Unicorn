#include <filesystem>
#include <fstream>
#include "Genshin.h"

Genshin::Genshin()
{
    loadIcons();
}

Genshin::~Genshin()
{

}

void Genshin::loadIcons()
{
    icons["Anemo"] =
    {
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(9,15,14),Pixel(7,11,10),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(14,23,20),Pixel(42,71,62),Pixel(42,73,62),Pixel(104,174,152),Pixel(33,56,49),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(5,10,9),Pixel(47,78,67),Pixel(53,89,75),Pixel(95,161,139),Pixel(59,98,84),Pixel(66,111,96),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(1,2,2),Pixel(63,105,92),Pixel(70,118,102),Pixel(92,155,134),Pixel(66,111,96),Pixel(63,104,90),Pixel(42,71,62),Pixel(2,4,4),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(40,68,58),Pixel(47,78,68),Pixel(31,53,45),Pixel(55,92,80),Pixel(59,98,86),Pixel(1,2,1),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(6,13,12),Pixel(50,84,73),Pixel(71,117,102),Pixel(55,92,80),Pixel(60,99,86),Pixel(1,2,1) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(41,68,59),Pixel(47,78,68),Pixel(31,52,46),Pixel(55,93,80),Pixel(59,98,84),Pixel(1,2,1),Pixel(0,0,0) },
            { Pixel(1,2,2),Pixel(64,107,92),Pixel(72,121,104),Pixel(94,156,136),Pixel(65,109,94),Pixel(63,104,90),Pixel(43,71,61),Pixel(2,4,4),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(6,9,9),Pixel(45,76,66),Pixel(53,89,75),Pixel(95,161,139),Pixel(59,97,86),Pixel(66,111,96),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(14,23,20),Pixel(42,71,62),Pixel(42,71,62),Pixel(104,174,152),Pixel(32,56,48),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(9,14,13),Pixel(7,11,10),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) }
    };

    icons["Cryo"] =
    {
        { Pixel(0,0,0),Pixel(0,0,0),Pixel(1,1,1),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(1,1,1),Pixel(0,0,0),Pixel(0,0,0) },
        { Pixel(0,0,0),Pixel(0,0,0),Pixel(14,20,21),Pixel(66,89,95),Pixel(17,23,24),Pixel(0,0,0),Pixel(18,24,25),Pixel(67,90,96),Pixel(14,19,20),Pixel(0,0,0),Pixel(0,0,0) },
        { Pixel(0,0,0),Pixel(0,0,0),Pixel(17,23,24),Pixel(110,149,158),Pixel(85,114,121),Pixel(26,35,37),Pixel(86,115,122),Pixel(110,148,157),Pixel(16,22,24),Pixel(0,0,0),Pixel(0,0,0) },
        { Pixel(0,0,0),Pixel(0,0,0),Pixel(9,12,13),Pixel(72,98,104),Pixel(80,108,114),Pixel(29,40,42),Pixel(80,108,114),Pixel(71,96,102),Pixel(8,11,12),Pixel(0,0,0),Pixel(0,0,0) },
        { Pixel(1,2,2),Pixel(26,35,37),Pixel(61,82,87),Pixel(27,36,39),Pixel(64,86,91),Pixel(85,114,121),Pixel(66,89,95),Pixel(28,37,40),Pixel(61,83,88),Pixel(26,36,38),Pixel(2,3,3) },
        { Pixel(29,40,42),Pixel(112,151,160),Pixel(94,126,134),Pixel(79,106,113),Pixel(81,109,116),Pixel(108,146,154),Pixel(87,118,125),Pixel(80,108,114),Pixel(93,125,133),Pixel(112,151,160),Pixel(29,40,42) },
        { Pixel(2,3,3),Pixel(26,36,38),Pixel(61,83,88),Pixel(27,36,39),Pixel(64,86,91),Pixel(86,115,122),Pixel(67,91,97),Pixel(28,37,40),Pixel(61,82,87),Pixel(26,35,37),Pixel(1,2,2) },
        { Pixel(0,0,0),Pixel(0,0,0),Pixel(8,11,12),Pixel(71,96,102),Pixel(80,108,114),Pixel(29,40,42),Pixel(80,108,114),Pixel(72,98,104),Pixel(9,12,13),Pixel(0,0,0),Pixel(0,0,0) },
        { Pixel(0,0,0),Pixel(0,0,0),Pixel(16,22,24),Pixel(110,148,157),Pixel(86,115,122),Pixel(26,35,37),Pixel(85,114,121),Pixel(110,149,158),Pixel(17,23,24),Pixel(0,0,0),Pixel(0,0,0) },
        { Pixel(0,0,0),Pixel(0,0,0),Pixel(14,19,20),Pixel(67,90,96),Pixel(18,24,25),Pixel(0,0,0),Pixel(17,23,24),Pixel(66,89,95),Pixel(14,20,21),Pixel(0,0,0),Pixel(0,0,0) },
        { Pixel(0,0,0),Pixel(0,0,0),Pixel(1,1,1),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(1,1,1),Pixel(0,0,0),Pixel(0,0,0) }
    };

    icons["Dendro"] =
    {
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(4,4,2),Pixel(1,1,0),Pixel(0,0,0),Pixel(6,8,2),Pixel(23,27,8),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(37,45,12),Pixel(104,127,37),Pixel(33,40,12),Pixel(73,89,26),Pixel(62,74,21),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(75,90,26),Pixel(50,59,16),Pixel(22,28,8),Pixel(73,90,26),Pixel(93,112,32),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(2,2,1),Pixel(82,99,30),Pixel(102,123,35),Pixel(119,144,43),Pixel(57,70,20),Pixel(71,87,26),Pixel(49,60,18),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(6,9,3),Pixel(19,24,7),Pixel(91,109,31),Pixel(34,40,12),Pixel(0,0,0),Pixel(24,31,9),Pixel(7,8,2),Pixel(122,149,43),Pixel(8,8,3),Pixel(0,0,0) },
            { Pixel(4,4,2),Pixel(128,156,46),Pixel(158,192,56),Pixel(53,63,17),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(46,56,16),Pixel(104,124,37),Pixel(2,2,1) },
            { Pixel(0,0,0),Pixel(6,9,3),Pixel(19,24,7),Pixel(91,109,31),Pixel(34,41,12),Pixel(0,0,0),Pixel(27,34,9),Pixel(8,10,2),Pixel(124,149,44),Pixel(8,8,3),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(2,2,1),Pixel(82,99,30),Pixel(102,123,37),Pixel(119,145,42),Pixel(58,71,21),Pixel(72,87,25),Pixel(50,60,18),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(74,91,27),Pixel(51,60,18),Pixel(23,28,7),Pixel(75,90,26),Pixel(93,112,32),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(37,45,12),Pixel(104,127,37),Pixel(31,39,11),Pixel(73,89,26),Pixel(61,74,21),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(4,4,2),Pixel(1,1,0),Pixel(0,0,0),Pixel(6,8,2),Pixel(23,27,7),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) }
    };

    icons["Electro"] =
    {
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(2,2,2),Pixel(70,57,77),Pixel(135,109,148),Pixel(135,110,149),Pixel(87,70,96),Pixel(24,18,25),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(37,30,41),Pixel(115,94,127),Pixel(120,98,133),Pixel(4,4,5),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(21,17,23),Pixel(174,141,192),Pixel(49,40,54),Pixel(0,0,0),Pixel(25,21,29),Pixel(63,52,70),Pixel(3,3,4),Pixel(2,2,2),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(31,25,34),Pixel(166,135,183),Pixel(89,72,99),Pixel(1,1,1),Pixel(32,26,35),Pixel(175,142,193),Pixel(126,101,139),Pixel(37,30,41),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(8,7,8),Pixel(1,1,2),Pixel(36,28,38),Pixel(15,12,16),Pixel(118,96,131),Pixel(55,45,60),Pixel(62,51,68),Pixel(162,131,179),Pixel(118,96,131),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(74,61,82),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(60,48,65),Pixel(0,0,0),Pixel(0,0,0),Pixel(85,69,93),Pixel(137,111,151),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(76,61,84),Pixel(105,85,116),Pixel(40,32,44),Pixel(85,70,94),Pixel(148,119,162),Pixel(45,37,50),Pixel(0,0,0),Pixel(80,66,88),Pixel(73,60,80),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(3,3,4),Pixel(127,104,140),Pixel(148,120,162),Pixel(144,118,159),Pixel(102,81,112),Pixel(8,7,8),Pixel(2,2,2),Pixel(100,81,111),Pixel(2,2,2),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(2,2,2),Pixel(58,47,64),Pixel(14,10,14),Pixel(0,0,0),Pixel(0,0,0),Pixel(12,9,12),Pixel(4,4,4),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) }
    };

    icons["Geo"] =
    {
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(19,14,4),Pixel(117,84,22),Pixel(11,7,1),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(33,24,7),Pixel(83,61,15),Pixel(190,137,38),Pixel(208,152,41),Pixel(39,29,8),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(58,42,12),Pixel(219,159,43),Pixel(228,166,45),Pixel(77,55,14),Pixel(75,55,14),Pixel(202,147,41),Pixel(54,39,10),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(42,31,8),Pixel(146,105,29),Pixel(95,68,19),Pixel(144,104,28),Pixel(159,115,31),Pixel(176,129,34),Pixel(56,40,10),Pixel(157,114,32),Pixel(42,31,8),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(128,94,25),Pixel(7,4,0),Pixel(212,154,43),Pixel(59,43,11),Pixel(59,44,11),Pixel(61,44,11),Pixel(213,155,42),Pixel(7,4,0),Pixel(127,92,26),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(42,31,8),Pixel(158,116,31),Pixel(57,40,10),Pixel(176,129,34),Pixel(159,115,31),Pixel(147,107,28),Pixel(96,69,18),Pixel(146,105,29),Pixel(41,31,7),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(56,40,10),Pixel(203,147,40),Pixel(77,56,14),Pixel(77,55,14),Pixel(228,166,45),Pixel(219,159,43),Pixel(56,40,10),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(39,29,8),Pixel(208,152,41),Pixel(191,139,38),Pixel(83,61,15),Pixel(31,23,5),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(11,7,1),Pixel(116,84,23),Pixel(18,12,4),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) }
    };

    icons["Hydro"] =
    {
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(17,46,59),Pixel(3,6,9),Pixel(50,130,162),Pixel(3,9,11),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(40,103,128),Pixel(72,184,229),Pixel(11,26,34),Pixel(17,45,57),Pixel(0,1,1),Pixel(36,95,118),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(21,51,64),Pixel(75,192,239),Pixel(19,48,60),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(2,5,6),Pixel(4,8,11),Pixel(11,29,37),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(48,123,153),Pixel(57,148,183),Pixel(16,39,50),Pixel(60,153,190),Pixel(0,0,0),Pixel(40,105,130),Pixel(48,124,154),Pixel(34,89,111),Pixel(25,67,85),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(57,148,183),Pixel(46,120,150),Pixel(28,74,92),Pixel(65,166,206),Pixel(0,0,0),Pixel(70,179,223),Pixel(13,34,43),Pixel(14,34,42),Pixel(30,76,94),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(49,124,154),Pixel(61,155,193),Pixel(15,39,48),Pixel(75,191,238),Pixel(12,31,39),Pixel(39,100,123),Pixel(59,150,188),Pixel(5,13,17),Pixel(33,84,104),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(19,48,59),Pixel(76,194,241),Pixel(25,63,78),Pixel(43,108,135),Pixel(67,171,213),Pixel(29,74,93),Pixel(24,61,76),Pixel(47,120,148),Pixel(19,50,63),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(38,95,119),Pixel(73,188,234),Pixel(38,96,120),Pixel(30,79,98),Pixel(44,111,137),Pixel(55,142,176),Pixel(35,89,111),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(18,46,56),Pixel(46,118,147),Pixel(57,148,183),Pixel(48,124,154),Pixel(19,49,62),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) }
    };

    icons["Pyro"] =
    {
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(6,3,1),Pixel(74,36,17),Pixel(59,30,14),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(29,14,7),Pixel(152,76,35),Pixel(132,66,30),Pixel(117,58,26),Pixel(59,30,14),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(41,21,10),Pixel(219,111,51),Pixel(230,117,54),Pixel(133,66,31),Pixel(126,65,29),Pixel(117,58,26),Pixel(6,4,2),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(98,49,22),Pixel(192,97,45),Pixel(145,74,34),Pixel(124,63,28),Pixel(52,27,12),Pixel(152,76,35),Pixel(93,46,22),Pixel(104,53,23),Pixel(0,0,0) },
            { Pixel(13,7,3),Pixel(178,90,41),Pixel(230,117,54),Pixel(152,76,35),Pixel(175,88,41),Pixel(80,41,18),Pixel(121,61,28),Pixel(0,0,0),Pixel(42,21,10),Pixel(111,55,25),Pixel(37,18,9) },
            { Pixel(0,0,0),Pixel(13,7,3),Pixel(34,16,8),Pixel(104,53,25),Pixel(151,76,36),Pixel(114,57,27),Pixel(172,86,40),Pixel(112,56,27),Pixel(79,39,18),Pixel(114,57,27),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(42,22,9),Pixel(176,89,41),Pixel(217,110,50),Pixel(141,72,32),Pixel(133,66,31),Pixel(155,78,36),Pixel(11,6,3),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(6,4,2),Pixel(150,75,34),Pixel(105,54,24),Pixel(99,51,23),Pixel(74,36,17),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(3,1,1),Pixel(68,34,16),Pixel(50,24,12),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) },
            { Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0),Pixel(0,0,0) }
    };
}

void Genshin::drawIcon(const std::string& name, Point pos, PicoGraphics_PenRGB888& graphics)
{
    std::vector<std::vector<Pixel>> icon = icons[name];

    for (int row = 0; row < icon.size(); row++)
    {
        for (int column = 0; column < icon[row].size(); column++)
        {
            Pixel pixel = icon[row][column];
            graphics.set_pen(pixel.r, pixel.g, pixel.b);
            graphics.pixel(pos + Point(row, column));
        }
    }
}

void Genshin::drawIcons(Point pos, PicoGraphics_PenRGB888& graphics)
{
    Point location = pos;
    for (auto& value: icons)
    {
        drawIcon(value.first, location, graphics);
        location.x += 11;
    }
}
