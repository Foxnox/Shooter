#include "Ship.h"
#include "utils.h"

using namespace std;

Ship::Ship(bool player, int lvl)
: MovableElement(0,0,0,0, SHIP_SPEED, SHIP_SPEED), _is_player(player), _alive(true), _firing(true), _level(lvl), _last_fire(0) 
{
	if (_is_player)
	{
		_firing = false;
		setPos(MODEL_WIDTH/2, MODEL_HEIGHT-20-PLAYER_SHIP_HEIGHT);
		resize(PLAYER_SHIP_HEIGHT, PLAYER_SHIP_WIDTH);
		_life = 3;
		_health = 300;
	}
	else 
	{
		switch (lvl)
		{
			case 1 : 
				setPos(Random(0, MODEL_WIDTH-ENNEMI1_SHIP_WIDTH), 0-ENNEMI1_SHIP_HEIGHT);
				resize(ENNEMI1_SHIP_HEIGHT, ENNEMI1_SHIP_WIDTH);
				_life = 0;
				_health = 50;
				_moving_right = false;
				_moving_left = false;
				_moving_up = false;
				_moving_down = true;
				break;
			case 2 : 
				setPos(Random(0, MODEL_WIDTH-ENNEMI2_SHIP_WIDTH), 0-ENNEMI1_SHIP_HEIGHT);
				resize(ENNEMI2_SHIP_HEIGHT, ENNEMI2_SHIP_WIDTH);
				_life = 0;
				_health = 100;
				_moving_right = false;
				_moving_left = false;
				_moving_up = false;
				_moving_down = true;
				break;
			case 3 : 
				setPos(Random(0, MODEL_WIDTH-ENNEMI3_SHIP_WIDTH), 0-ENNEMI1_SHIP_HEIGHT);
				resize(ENNEMI3_SHIP_HEIGHT, ENNEMI3_SHIP_WIDTH);
				_life = 0;
				_health = 150;
				_moving_right = false;
				_moving_left = false;
				_moving_up = false;
				_moving_down = true;
				break;
		}
	}
}

int Ship::getLvl()
{
	return _level;
}

//~ int Ship::getState()
//~ {
	//~ return _state;
//~ }
//~ 
//~ void Ship::setState(int s)
//~ {
	//~ _state = s;
//~ }


bool Ship::getAlive()
{ return _alive; }

bool Ship::getFiring()
{ return _firing; }

int Ship::getLastFire()
{ return _last_fire; }

int Ship::getHealth()
{ return _health; }

int Ship::getLife()
{ return _life; }
		
void Ship::setAlive(bool a)
{ _alive = a; }

void Ship::setFiring(bool f)
{ _firing = f; }

void Ship::setLastFire(int lf)
{ _last_fire = lf; }

void Ship::setHealth(int health)
{ _health = health; }

void Ship::setLife(int life)
{ _life = life; }



