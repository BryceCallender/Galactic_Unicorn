#include <filesystem>
#include <fstream>
#include "Genshin.h"

Genshin::Genshin()
{

}

Genshin::~Genshin()
{

}

void Genshin::loadIcons()
{
    const std::filesystem::path genshinImages {"images" };

    for (auto const& dir_entry : std::filesystem::directory_iterator{genshinImages })
    {
        std::vector<std::vector<Pixel>> icon;

        std::ifstream file;
        file.open(dir_entry.path());

        std::vector<std::string> numbers;
        std::string line, number;

        for (int row = 0; row < ICON_SIZE; row++)
        {
            std::vector<Pixel> pixels;
            for (int column = 0; column < ICON_SIZE; column++)
            {
                getline(file, line);
                std::stringstream stringStream(line);
                numbers.clear();

                while (getline(stringStream, number, ','))
                {
                    // add all the column data
                    // of a row to a vector
                    numbers.push_back(number);
                }

                Pixel pixel =
                {
                    .r = std::stoi(numbers[0]),
                    .g = std::stoi(numbers[1]),
                    .b = std::stoi(numbers[2])
                };

                pixels.push_back(pixel);
            }

            icon.push_back(pixels);
        }

        icons[dir_entry.path().stem().string()] = icon;

        file.close();
    }
}

void Genshin::drawIcon(const std::string& name, PicoGraphics_PenRGB888* graphics)
{
    std::vector<std::vector<Pixel>> icon = icons[name];

    for (int row = 0; row < icon.size(); row++)
    {
        for (int column = 0; column < icon[row].size(); column++)
        {
            Pixel pixel = icon[row][column];
            graphics->set_pen(pixel.r, pixel.g, pixel.b);
            graphics->pixel(Point(row, column));
        }
    }
}

void Genshin::drawIcons(PicoGraphics_PenRGB888* graphics)
{
    for (auto& value: icons)
    {
        drawIcon(value.first, graphics);
    }
}
