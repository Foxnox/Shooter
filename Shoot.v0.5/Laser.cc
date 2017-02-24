#include "Laser.h"

using namespace std;

Laser::Laser()
: MovableElement(), _dmg(0)
{}

Laser::Laser(float x, float y, float h, float w,int vitx, int vity,int lvl)
: MovableElement(x, y, h, w,vitx,vity), _active(true)
{
	_moving_right = false;
	_moving_left = false;
	_moving_up = true;
	_moving_down = false;
	switch (lvl)
	{
		case 1 : 
			_dmg = 50;
			break;
		case 2 : 
			_dmg = 100;
			_h*=1.1;
			_w*=1.1;
			break;
		case 3 : 
			_dmg = 150;
			_h*=1.3;
			_w*=1.3;
			break;
	}
}

Laser::Laser(float x, float y, float h, float w,int vitx, int vity, bool stop, bool right, bool left, bool up, bool down,int dmg)
: MovableElement(x, y, h, w,vitx,vity,right,left,up,down), _dmg(dmg), _active(true)
{
}

Laser::~Laser()
{}

int Laser::getDmg()
{ return _dmg; }

bool Laser::getActive() const
{ return _active; }

void Laser::setActive( bool act)
{ _active = act; }



