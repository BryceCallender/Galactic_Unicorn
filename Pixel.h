//
// Created by Bryce Callender on 12/16/22.
//

#ifndef GALACTIC_PIXEL_H
#define GALACTIC_PIXEL_H

struct Pixel
{
    int r;
    int g;
    int b;

    Pixel(int r, int g, int b)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }
};

#endif //GALACTIC_PIXEL_H
