// GameModel.cc

#include "GameModel.h"
#include "shoot_const.h"
#include <iostream>
#include <fstream>

using namespace std;

//=======================================
// Constructeurs
//=======================================
GameModel::GameModel() 
  : _w(MODEL_WIDTH), _h(MODEL_HEIGHT), _score(0), _stage(1), _level_passed(false), _in_game(true),
   _goal(GOAL),  _kills(0), _last_enemi_spawn(0), _next_enemi_spawn(0), _last_kill(0)
{
	_player = new Ship(true, 1);
}
//=======================================
GameModel::GameModel(int w, int h)
  :  _w(w), _h(h), _score(0), _stage(1), _level_passed(false),_in_game(true), _goal(GOAL),
    _kills(0), _last_enemi_spawn(0), _next_enemi_spawn(0), _last_kill(0) 
{
	_player = new Ship(true, 1);
}

//=======================================
// Destructeurs
//=======================================
GameModel::~GameModel()
{
	if (_player != NULL)
		delete _player;
}

//=======================================
// Accesseurs en lecture
//=======================================

void GameModel::getShipPlayerPosition(float & x, float & y)
{
	x = _player->getX();
	y = _player->getY();
}

void GameModel::getShipPlayerSize(float & h, float & w)
{
	h = _player->getH();
	w = _player->getW();
}

void GameModel::getVectors( std::vector<Laser*>* &enemies_lasers, std::vector<Laser*>* &player_lasers,
							 std::vector<Ship*>* &enemies_ships)
{
	enemies_lasers = &_tirs_enemies;
	player_lasers = &_tirs_player;
	enemies_ships = &_enemies;
}


void GameModel::getInfosString(string &score, string &health, string &life, string &kills, string &goal, string &stage)
{
	ostringstream str_score;
	ostringstream str_health;
	ostringstream str_life;
	ostringstream str_kills;
	ostringstream str_goal;
	ostringstream str_stage;
	
	
	str_score << _score;
	score += str_score.str();
	
	str_health << _player->getHealth();
	health += str_health.str();
	
	str_life << _player->getLife();
	life += str_life.str();
	
	str_kills << _kills;
	kills += str_kills.str();
	
	str_goal << _goal;
	goal += str_goal.str();
	
	str_stage << _stage;
	stage += str_stage.str();
}

int GameModel::getStage()
{ return _stage;}

bool GameModel::getLevelPassed()
{ return _level_passed; }

bool GameModel::getInGame()
{ return _in_game; }

int GameModel::getPlayerLife()
{ return _player->getLife(); }
//=======================================
// Accesseurs en ecriture
//=======================================


void GameModel::setShipMovingX(bool right, bool left)
{
	_player->setIsMovingRight(right);
	_player->setIsMovingLeft(left);
}

void GameModel::setShipMovingY( bool up, bool down)
{
	_player->setIsMovingUp(up);
	_player->setIsMovingDown(down);
}

//=======================================
// Calcul la prochaine étape
//=======================================
void GameModel::nextStep()
{ 
	nextStepPlayer();
	
	nextStepShips();
	destroyShips();
	
	
	nextStepPlayerLasers();
	nextStepEnemiesLasers();
	
	
	destroyPlayerLasers();
	destroyEnemiesLasers();
	
	
	spawnEnemiesShip();
	
	if (_kills >= _goal)
	{
		reset();
		_kills = 0;
		_level_passed = true;
		_in_game = false;
		++_stage;
		_goal += GOAL;
	}
	

}

void GameModel::nextStepPlayer()
{
	_player->move(0,0);
	playerShoot();
	
	if (_player->getY() <= 0)
			_player->setPos(_player->getX(),0);
	if ( _player->getY() + _player->getH() > MODEL_HEIGHT)
		_player->setPos(_player->getX(),MODEL_HEIGHT - _player->getH());
	
	int health, life;
	health = _player->getHealth();
	life = _player->getLife();
	if (health <= 0)
	{	
		if (life == 0)
		{
			_in_game = false;
			_player->setLife(life - 1);
		}
		else
		{
			_player->setLife(life - 1);
			_player->setHealth(300);
			reset();
			_in_game = false;
		}
	}
	
}

void GameModel::nextStepShips()
{
	// Gère la prochaine étape des vaisseaux enemis
	for(unsigned int i = 0; i < _enemies.size(); ++i)
	{
		if ( _enemies[i]->isOutOfScreen()) // gère la sortie de l'ecran
		{
			_enemies[i]->setAlive(false);	
		}
		
		int health = _enemies[i]->getHealth();
		if (health <= 0)
		{
			_enemies[i]->setAlive(false);
			_score += 10*_enemies[i]->getLvl();
			++_kills;
		}
		
		_enemies[i]->move(0, 0);
		enemiesShoot(_enemies[i]);
		
		if (!_enemies[i]->getAlive())
			_ships_to_destroy.push_back(i);
		
		
		}
}


void GameModel::nextStepPlayerLasers()
{
	
	// Gère la prochaine étape des tirs
	// Alliés
	for(unsigned int i = 0; i < _tirs_player.size(); ++i)
	{
		if ( _tirs_player[i]->isOutOfScreen()) // gère la sortie de l'ecran
		{
			_tirs_player[i]->setActive(false);
		}
		_tirs_player[i]->move(0, 0);
		for (unsigned int j = 0; j < _enemies.size(); ++j)
		{
			if (_tirs_player[i]->enContact(*_enemies[j])and !_enemies[j]->isOutOfScreen())
			{
				_enemies[j]->setHealth(_enemies[j]->getHealth() - _tirs_player[i]->getDmg());
				_tirs_player[i]->setActive(false);
			}
		}
		if (!_tirs_player[i]->getActive())
			_tirs_player_to_destroy.push_back(i);
	}
}


void GameModel::nextStepEnemiesLasers()
{
	// Enemis
	for(unsigned int i = 0; i < _tirs_enemies.size(); ++i)
	{
		if ( _tirs_enemies[i]->isOutOfScreen()) // gère la sortie de l'ecran
		{
			_tirs_enemies[i]->setActive(false);

		}
		
		if  ( _tirs_enemies[i]->enContact(*_player))
		{
			_player->setHealth(_player->getHealth() - _tirs_enemies[i]->getDmg());
			_tirs_enemies[i]->setActive(false);
		}
		if (!_tirs_enemies[i]->getActive())
			_tirs_enemies_to_destroy.push_back(i);
			
		_tirs_enemies[i]->move(0, -ENEMIES_SPEED/2);	
	}
}

void nextStepMenu()
{
	
}

void GameModel::playerShoot()
{
	if (_player->getAlive() and _player->getFiring() and (getTime() - _player->getLastFire() > TIME_BETWEEN_ATK))
	{
		_tirs_player.push_back( new Laser(_player->getX()+(_player->getW()/2)-(LASER_WIDTH/2), _player->getY(), 
								LASER_HEIGHT, LASER_WIDTH,0, LASER_SPEED, _player->getLvl()));
		_player->setLastFire(getTime());
	}
}

void GameModel::enemiesShoot(Ship* s)
{
	if (s->getFiring() and (getTime() - s->getLastFire() > TIME_BETWEEN_ATK))
	{
		_tirs_enemies.push_back( new Laser(s->getX()+(s->getW()/2)-(LASER_WIDTH/2), (s->getY()+s->getH()/2), 
								LASER_HEIGHT, LASER_WIDTH,0, -LASER_SPEED, s->getLvl())); // On met -LASER_SPEED pour que les tirs aillent dans la bonne direction
		s->setLastFire(getTime());
	}
}


void GameModel::setPlayerFiring (bool pf)
{
	_player->setFiring(pf);
}

void GameModel::setLevelPassed(bool lp)
{
	_level_passed = lp;
}

void GameModel::setInGame(bool ig)
{
	_in_game = ig;
}

void GameModel::spawnEnemiesShip()
{
	if (getTime() - _last_enemi_spawn > _next_enemi_spawn )
	{
		_enemies.push_back( new Ship(false, Random(1,4)));
		_last_enemi_spawn = getTime();
		_next_enemi_spawn = Random(1000, 3000);
	}
}

void GameModel::destroyShips()
{
	if (_enemies.size() > 0)
	{
		for (unsigned int i= 0; i< _ships_to_destroy.size(); ++i)
		{
			delete _enemies[_ships_to_destroy[i] -i];
			_enemies.erase(_enemies.begin() + _ships_to_destroy[i] -i);
		}
		_ships_to_destroy.erase(_ships_to_destroy.begin(), _ships_to_destroy.end());
	}
}

void GameModel::destroyPlayerLasers()
{
	if ( _tirs_player_to_destroy.size() > 0)
	{
		for (unsigned int i= 0; i< _tirs_player_to_destroy.size(); ++i)
		{
			delete _tirs_player[_tirs_player_to_destroy[i] -i];
			_tirs_player.erase(_tirs_player.begin() + _tirs_player_to_destroy[i] - i);
		}
		_tirs_player_to_destroy.erase(_tirs_player_to_destroy.begin(), _tirs_player_to_destroy.end());
	}
}

void GameModel::destroyEnemiesLasers()
{
	if (_tirs_enemies_to_destroy.size() > 0)
	{
		for (unsigned int i= 0; i< _tirs_enemies_to_destroy.size(); ++i)
		{
			delete _tirs_enemies[_tirs_enemies_to_destroy[i] -i];
			_tirs_enemies.erase(_tirs_enemies.begin() + _tirs_enemies_to_destroy[i] - i);
		}
		_tirs_enemies_to_destroy.erase(_tirs_enemies_to_destroy.begin(), _tirs_enemies_to_destroy.end());
	}
}

void GameModel::reset()
{
	for(unsigned int i = 0; i < _enemies.size(); ++i)
	{
		delete _enemies[i];
	}
	_enemies.erase(_enemies.begin(), _enemies.end());
	
	for(unsigned int i = 0; i < _tirs_enemies.size(); ++i)
	{
		delete _tirs_enemies[i];
	}
	_tirs_enemies.erase(_tirs_enemies.begin(), _tirs_enemies.end());
	
	for(unsigned int i = 0; i < _tirs_player.size(); ++i)
	{
		delete _tirs_player[i];
	}
	_tirs_player.erase(_tirs_player.begin(), _tirs_player.end());

}
