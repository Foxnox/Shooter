#include <iostream>
#include <cstdlib>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Element.h"

using namespace std;

/////////////////////////////////
// CONSTRUCTEURS DESTRUCTEUR   //
/////////////////////////////////
Element::Element()
: _x(0), _y(0), _h(0), _w(0)
{}

Element::Element(float x, float y, float h, float w)
: _x(x), _y(y), _h(h), _w(w)
{}

Element::~Element()
{}

/////////////////////////////////
// ACSESSEURS ECRITURE/LECTURE //
/////////////////////////////////
float Element::getX() const
{ return _x; }

float Element::getY() const
{ return _y; }

float Element::getH() const
{ return _h; }

float Element::getW() const
{ return _w; }

void Element::setPos(float x, float y)
{ _x = x; _y = y; } 

void Element::resize(float h, float w)
{ _h = h; _w= w; }

/////////////////////////////////
// METHODES DIVERSES		   //
/////////////////////////////////		


bool Element::isOutOfScreen()
{
	return ((_x < -_w) or (_x  > MODEL_WIDTH) or (_y < -_h) or (_y > MODEL_HEIGHT));
}
