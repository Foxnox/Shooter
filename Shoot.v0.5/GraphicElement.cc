#include "GraphicElement.h"
#include <iostream>


using namespace std;
using namespace sf;

GraphicElement::GraphicElement():  Sprite(), _w(0), _h(0)
{}

GraphicElement::GraphicElement(Texture * image, int x, int y, int w, int h)
  :  Sprite(*image), _w(w), _h(h)
{
  resize(_w, _h);  
  Sprite::setPosition(x,y);
}

GraphicElement::~GraphicElement()
{}

void GraphicElement::setPosition(int x, int y){
  Sprite::setPosition(x, y);
}

void GraphicElement::setPosition(const Vector2f & pos){
  Sprite::setPosition(pos.x, pos.y);
}

void GraphicElement::resize(int w, int h){
  _w = w;
  _h = h;
  
  FloatRect sprite_rect = getLocalBounds();
  
  float x_scale_factor = _w / sprite_rect.width;
  float y_scale_factor = _h / sprite_rect.height;

  setScale(x_scale_factor, y_scale_factor);
}

void GraphicElement::draw(RenderWindow * window){
  window->draw(*this);
}

bool GraphicElement::contain(int x, int y)
{
  return (x > getPosition().x && x < getPosition().x + getGlobalBounds().width && 
	  y > getPosition().y && y < getPosition().y + getGlobalBounds().height);
}

