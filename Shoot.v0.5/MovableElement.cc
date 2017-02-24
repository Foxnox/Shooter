#include "MovableElement.h"

using namespace std;

MovableElement::MovableElement()
: Element(), _vit_x(0), _vit_y(0), _moving_right(false), _moving_left(false), _moving_up(false), _moving_down(false)
{}

MovableElement::MovableElement(float x, float y, float h, float w,int vitx, int vity)
: Element(x, y, h, w), _vit_x(vitx), _vit_y(vity), _moving_right(false), _moving_left(false), _moving_up(false), _moving_down(false)
{}

MovableElement::MovableElement(float x, float y, float h, float w,int vitx, int vity, bool right, bool left, bool up, bool down)
: Element(x, y, h, w), _vit_x(vitx), _vit_y(vity), _moving_right(right), _moving_left(left), _moving_up(up), _moving_down(down)
{}

MovableElement::~MovableElement()
{}

void MovableElement::move(int dx, int dy)
{
	//~ if (!_is_stoped)
	//~ {
		if (_moving_right)
			setPos(getX()+_vit_x + dx, getY());
		if (_moving_left)
			setPos(getX()-_vit_x + dx , getY());
			
		if (_moving_up)
			setPos(getX(), getY()-_vit_y-dy);
		if (_moving_down)
			setPos(getX(), getY()+_vit_y+dx);
			
		if ( _x < 0 )
			_x = 0;
		if ( _x + _w > MODEL_WIDTH)
			_x = MODEL_WIDTH - _w;
			
		
	//~ }
}

void MovableElement::setIsMovingRight(bool moving)
{
	_moving_right = moving;
}

void MovableElement::setIsMovingLeft(bool moving)
{
	_moving_left = moving;
}

void MovableElement::setIsMovingUp(bool moving)
{
	_moving_up = moving;
}

void MovableElement::setIsMovingDown(bool moving)
{
	_moving_down = moving;
}


bool MovableElement::enContact(const MovableElement & m)
{	
	return ((_y > m._y) and (_y < m._y + m._h) and (_x > m._x) and (_x < m._x + m._w));
}
