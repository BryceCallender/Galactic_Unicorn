#include "Sequence.hpp"

Sequence::Sequence(GalacticUnicorn& galacticUnicorn, PicoGraphics_PenRGB888& graphics, uint8_t triggerButton)
: galacticUnicorn(galacticUnicorn), graphics(graphics), triggerButton(triggerButton)
{
}

Sequence::~Sequence()
{

}

void Sequence::progress()
{
    draw();
    currentSequence = ++currentSequence % sequences.size();
}

void Sequence::checkButtonPress()
{
    if(galacticUnicorn.is_pressed(triggerButton))
    {
        if(!pressedButton)
        {
            progress();
        }
        pressedButton = true;
    }
    else
    {
        pressedButton = false;
    }
}

void Sequence::addSequence(const std::function<void()>& drawFunction)
{
    sequences.push_back(drawFunction);
}

void Sequence::begin()
{
    draw();
}

void Sequence::draw()
{
    auto next = sequences.at(currentSequence);
    next();
    galacticUnicorn.update(&graphics);
}
