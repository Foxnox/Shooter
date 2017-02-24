// Atelier 1
// GameView.cc

#include "GameView.h"
#include "GameModel.h"
#include "shoot_const.h"


using namespace std;
using namespace sf;

//=======================================
// Constructeur
//=======================================
GameView::GameView(int w, int h, int bpp): _w(w), _h(h)
{
  _window = new RenderWindow(sf::VideoMode(w, h, bpp), "Shoot", sf::Style::Close);

  if (!_background_image.loadFromFile(BACKGROUND_IMG) or !_player_ship_image.loadFromFile(SHIP_PLAYER_IMG)
      or !_backgroung_menu_image.loadFromFile(BACKGROUNG_MENU_IMG) or !_play_button_off_image.loadFromFile(PLAY_OFF_IMG) 
      or !_play_button_on_image.loadFromFile(PLAY_ON_IMG) or !_quit_button_off_image.loadFromFile(QUIT_OFF_IMG) 
      or !_quit_button_on_image.loadFromFile(QUIT_ON_IMG) or !_enemy_ship1_image.loadFromFile(ENEMY1_IMG)
      or !_enemy_ship2_image.loadFromFile(ENEMY2_IMG) or !_enemy_ship3_image.loadFromFile(ENEMY3_IMG)
      or !_laser1_image.loadFromFile(LASER_IMG) or !_tran_win_image.loadFromFile(TRAN_WIN) 
      or !_tran_loose_image.loadFromFile(TRAN_LOOSE) or !_tran_die_image.loadFromFile(TRAN_DIE)
      or !_opening_image.loadFromFile(OPEN_IMG)) // 
    {
      cerr << "Problem occurs when loading image files" << endl;
      _background_GE_sup = new GraphicElement();
      _background_GE_inf = new GraphicElement();
      _player_ship_GE = new GraphicElement();
      _background_menu_GE = new GraphicElement();
      _play_button_GE = new GraphicElement();
      _quit_button_GE = new GraphicElement();
      _transition_GE = new GraphicElement();
      _opening_GE = new GraphicElement();
    }
  else {

    _player_ship_image.createMaskFromColor(Color(255, 170, 255));
    _enemy_ship1_image.createMaskFromColor(Color(255, 170, 255));
    _enemy_ship2_image.createMaskFromColor(Color(255, 170, 255));
    _enemy_ship3_image.createMaskFromColor(Color(255, 170, 255));
    _laser1_image.createMaskFromColor(Color(255, 170, 255));
    _opening_image.createMaskFromColor(Color(255, 170, 255));
    _opening_image.createMaskFromColor(Color(254, 169, 254));
	
    _play_button_off_image.createMaskFromColor(Color(255, 255, 255));
    _play_button_on_image.createMaskFromColor(Color(255, 255, 255));
    _quit_button_off_image.createMaskFromColor(Color(255, 255, 255));
    _quit_button_on_image.createMaskFromColor(Color(255, 255, 255));

    _player_ship_texture.loadFromImage(_player_ship_image);
    _enemy_ship1_texture.loadFromImage(_enemy_ship1_image);
    _enemy_ship2_texture.loadFromImage(_enemy_ship2_image);
    _enemy_ship3_texture.loadFromImage(_enemy_ship3_image);
    _laser1_texture.loadFromImage(_laser1_image);
    _opening_texture.loadFromImage(_opening_image);

    _play_button_on_texture.loadFromImage(_play_button_on_image);
    _play_button_off_texture.loadFromImage(_play_button_off_image);
    _quit_button_on_texture.loadFromImage(_quit_button_on_image);
    _quit_button_off_texture.loadFromImage(_quit_button_off_image);
    
    _background_GE_sup = new GraphicElement(&_background_texture, 0, -VIEW_HEIGHT, _w, _h);
    _background_GE_inf = new GraphicElement(&_background_texture, 0, 0, _w, _h);
    _player_ship_GE = new GraphicElement(&_player_ship_texture, 0, 0, PLAYER_SHIP_HEIGHT, PLAYER_SHIP_WIDTH);
    _background_menu_GE = new GraphicElement(&_backgroung_menu_texture, 0, 0, _w, _h);
		
    _play_button_GE = new GraphicElement(&_play_button_off_texture, VIEW_WIDTH/2 - BUTTON_WIDTH/2, 0.33*VIEW_HEIGHT - BUTTON_HEIGHT/2, 
				       BUTTON_WIDTH, BUTTON_HEIGHT);
		
    _quit_button_GE = new GraphicElement(&_quit_button_off_texture, VIEW_WIDTH/2 - BUTTON_WIDTH/2, 0.66*VIEW_HEIGHT - BUTTON_HEIGHT/2, 
				       BUTTON_WIDTH, BUTTON_HEIGHT);
    _transition_GE = new GraphicElement(&_tran_loose_texture, 0, 0, _w, _h);
		
    _opening_GE = new GraphicElement(&_opening_texture, -400, VIEW_HEIGHT/2-200, 400, 400);
  } 
  _player_ship_image.createMaskFromColor(Color(255, 170, 255));
  _enemy_ship1_image.createMaskFromColor(Color(255, 170, 255));
  _enemy_ship2_image.createMaskFromColor(Color(255, 170, 255));
  _enemy_ship3_image.createMaskFromColor(Color(255, 170, 255));
  _laser1_image.createMaskFromColor(Color(255, 170, 255));
  _opening_image.createMaskFromColor(Color(255, 170, 255));
  _opening_image.createMaskFromColor(Color(254, 169, 254));
	
  _play_button_off_image.createMaskFromColor(Color(255, 255, 255));
  _play_button_on_image.createMaskFromColor(Color(255, 255, 255));
  _quit_button_off_image.createMaskFromColor(Color(255, 255, 255));
  _quit_button_on_image.createMaskFromColor(Color(255, 255, 255));
}

//=======================================
// Destructeur
//=======================================
GameView::~GameView(){
	
  if(_window!= NULL)
    delete _window;
    
  if(_background_GE_sup!= NULL)
    delete _background_GE_sup;
  if(_background_GE_inf!= NULL)
    delete _background_GE_inf;
  if(_player_ship_GE != NULL)
    delete _player_ship_GE;
    
}

    
//=======================================
// Accesseurs en écriture
//=======================================
void GameView::setModel(GameModel * model){
  _model = model;
}

//=======================================
void GameView::showInfos()
{
  sf::Font *  _font = new Font();                        // _font est un objet de sf::Font
  _font->loadFromFile("abberanc.ttf");     // utilisant la police "Antique Olive.ttf"
  //  fourni en fichier joint
  string score, health, life, kills, goal, stage;
  score = "Score : ";
  health = " HP : ";
  life = " Lifes : ";
  kills= " OBJ : ";
  stage = " Stage : ";
  _model->getInfosString(score, health, life, kills, goal, stage);
  kills += "/" + goal;
    
  sf::Text stext_score = Text(score, *_font, 30);    
  sf::Text stext_health = Text(health, *_font, 30);    
  sf::Text stext_life = Text(life, *_font, 30);    
  sf::Text stext_kills = Text(kills, *_font, 30);    
  sf::Text stext_stage = Text(stage, *_font, 30);

  stext_score.setPosition(425, VIEW_HEIGHT - 35); 
  _window->draw(stext_score); 
    
  stext_kills.setPosition(425, VIEW_HEIGHT - 70);  
  _window->draw(stext_kills); 
    
  stext_life.setPosition(5, VIEW_HEIGHT - 35);             
  _window->draw(stext_life);
     
  stext_health.setPosition(5, VIEW_HEIGHT - 70);              
  _window->draw(stext_health);
    
  stext_stage.setPosition(5, 5);           
  _window->draw(stext_stage); 
    
    
  delete _font;
}

//=======================================
// Fonction de dessin
//=======================================
void GameView::draw()
{
  _window->clear();
  _background_GE_sup->draw(_window);
  _background_GE_inf->draw(_window);
  _player_ship_GE->draw(_window);

  if (_map_enemies_ships.size () != 0)
    drawEnemiesShipsMap();
  if (_map_player_shoots.size() != 0)
    drawPlayerShootsMap();
  if (_map_enemies_shoots.size() != 0)	
    drawEnemiesShootsMap();

  showInfos();
  _window->display();
}

void GameView::synchronize()
{
  float x_player_ship, y_player_ship;
  float h_player_ship, w_player_ship;
	
  std::vector<Laser*>* enemies_lasers;
  std::vector<Laser*>* player_lasers;
  std::vector<Ship*>* enemies_ships;
	
  _model->getVectors(enemies_lasers, player_lasers, enemies_ships);
	
  synchronizeEnemiesShootsMap(*enemies_lasers);
  synchronizePlayerShootsMap(*player_lasers);
  synchronizeEnemiesShipsMap(*enemies_ships);
	
  _model->getShipPlayerPosition(x_player_ship, y_player_ship);
  _model->getShipPlayerSize(h_player_ship, w_player_ship);
	
  _player_ship_GE->resize(w_player_ship, h_player_ship);
  _player_ship_GE->setPosition(x_player_ship, y_player_ship);
	
  scrolling();
}

//=======================================
// Traitement des evenements
// Retourne false si un evenement de fin est reçu
//=======================================
bool GameView::treatEvents()
{
  _window->setFramerateLimit(FRL);
  bool result = false;
	
  if(_window->isOpen())
    {
      result = true;
      Event event;
		
      while (_window->pollEvent(event)) 
	{
	  //////////////////////////////////////
			
	  /////////////////////////////////////
			
	  if ((event.type == Event::Closed) ||
	      ((event.type == Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) 
	    {
	      _window->close();
	      result = false;
	    }
			
	  if (event.type == Event::KeyPressed)
	    {
	      switch (event.key.code)
		{
		case sf::Keyboard::Right : 
		  _model->setShipMovingX(true, false);
		  break;
		case sf::Keyboard::Left :
		  _model->setShipMovingX(false, true);
		  break;
		case sf::Keyboard::Space :
		  _model->setPlayerFiring(true);
		  break;
		case sf::Keyboard::Up :
		  _model->setShipMovingY(true, false);
		  break;
		case sf::Keyboard::Down :
		  _model->setShipMovingY(false, true);
		  break;
		default: break;
						
		}
	    }
	  if (event.type == Event::KeyReleased)
	    {
	      switch (event.key.code)
		{
		case sf::Keyboard::Right : 
		  _model->setShipMovingX(false, false);
		  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		    _model->setShipMovingX(false, true);
		  break;
		case sf::Keyboard::Left :
		  _model->setShipMovingX(false, false);
		  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		    _model->setShipMovingX(true, false);
		  break;
		case sf::Keyboard::Space :
		  _model->setPlayerFiring(false);
		  break;
		case sf::Keyboard::Up :
		  _model->setShipMovingY(false, false);
		  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		    _model->setShipMovingY(false, true);
		  break;
		case sf::Keyboard::Down :
		  _model->setShipMovingY(false, false);
		  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		    _model->setShipMovingY(true, false);
		  break;
		default: break;
		}
	    }
	}
    }  
  return result;
}

void GameView::scrolling()
{
  //_background_GE_inf->move(0, SCROLL_SPEED);
  _background_GE_inf->setPosition(_background_GE_inf->getPosition().x,
				  _background_GE_inf->getPosition().y +  SCROLL_SPEED);
  if (_background_GE_inf->getPosition().y >= VIEW_HEIGHT)
    _background_GE_inf->setPosition(0, -VIEW_HEIGHT);
	
  //_background_GE_sup->move(0, SCROLL_SPEED);
  _background_GE_sup->setPosition(_background_GE_sup->getPosition().x,
				  _background_GE_sup->getPosition().y + SCROLL_SPEED);
  if (_background_GE_sup->getPosition().y >= VIEW_HEIGHT)
    _background_GE_sup->setPosition(0, -VIEW_HEIGHT);	
}

///////////////////////MENU /////////////////////////////

int GameView::treatEventsMenu()
{
  bool on_play_button, on_quit_button;
  on_play_button = false;
  on_quit_button = false;
	
  int result = 0; // 0 pour QUIT		1 Pour rester dans le MENU		2 Pour PLAY
	
  if(_window->isOpen())
    {
      result = 1;
      Event event;

      sf::Vector2i mouse_pos = sf::Mouse::getPosition(*_window);
		
      unsigned int mouse_x = mouse_pos.x;
      unsigned int mouse_y = mouse_pos.y;
      _window->setFramerateLimit(FRL);
		
      while (_window->pollEvent(event)) 
	{
	  mouse_x = sf::Mouse::getPosition(*_window).x;
	  mouse_y = sf::Mouse::getPosition(*_window).y;
			
	  on_play_button = false;
	  on_quit_button = false;
			
	  if( _play_button_GE->contain(mouse_x, mouse_y))
	    {
	      _play_button_GE->setTexture(_play_button_on_texture);
	      on_play_button = true;
	    }
	  else 
	    {
	      _play_button_GE->setTexture(_play_button_off_texture);
	      //~ on_play_button = false;
	    }
			
	  if (_quit_button_GE->contain(mouse_x, mouse_y))
	    {
	      on_quit_button = true;
	      _quit_button_GE->setTexture(_quit_button_on_texture);
	    }
	  else 
	    {
	      _quit_button_GE->setTexture(_quit_button_off_texture);
	      //~ on_quit_button = false;
	    }
				
	  if (event.type == Event::MouseButtonPressed)
	    {
	      if (event.mouseButton.button == Mouse::Left)
		{
		  if (on_play_button)
		    {
		      _window->close();
		      result = 2; 
		    }
		  if (on_quit_button)
		    {
		      _window->close();
		      result = 0; 
		    }
						
		}
	    }
			
	  if ((event.type == Event::Closed) ||
	      ((event.type == Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) 
	    {
	      _window->close();
	      result = 0;
	    }
				
	}
    }
  return result;
}

bool GameView::treatEventsTransition()
{
  _window->setFramerateLimit(FRL);
  bool result = false;
  if(_window->isOpen())
    {
      result = true;
      Event event;
		
      while (_window->pollEvent(event) and result) 
	{
			
			
	  //////////////////////////////////////
			
	  /////////////////////////////////////
			
	  if ((event.type == Event::Closed) ||
	      ((event.type == Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) 
	    {
	      _window->close();
	      result = false;
	    }
	  if ((event.type == Event::KeyPressed) && (event.key.code == sf::Keyboard::Space)) 
	    {
	      result = false;
	    }
	}
    }  
  return result;
}

bool GameView::treatEventsOpening()
{
  _window->setFramerateLimit(FRL);
  bool result = false;
  if(_window->isOpen())
    {
      result = true;
      Event event;
      sf::Vector2f last_pos = _opening_GE->getPosition();
      _opening_GE->setPosition(last_pos.x + 5, last_pos.y);
		
      if (_opening_GE->getPosition().x >= VIEW_WIDTH) 
	{
	  result = false;
	}
		
      while (_window->pollEvent(event)) 
	{
			
	  if ((event.type == Event::Closed) ||
	      ((event.type == Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) 
	    {
	      _window->close();
	      result = false;
	    }
	  if ((event.type == Event::KeyPressed) && (event.key.code == sf::Keyboard::Space)) 
	    {
	      result = false;
	    }
			
	}
    }  
  return result;
}

void GameView::drawMenu()
{
  _window->clear();
  _background_menu_GE->draw(_window);
  _play_button_GE->draw(_window);
  _quit_button_GE->draw(_window);

  _window->display();
}

void GameView::drawTransition(bool win)
{
  _window->clear();
  if(win)
    _transition_GE->setTexture(_tran_win_texture);
  else 
    {
      if (_model->getPlayerLife() >= 0)
	_transition_GE->setTexture(_tran_die_texture);
      else
	_transition_GE->setTexture(_tran_loose_texture);
    }
  _transition_GE->draw(_window);
  _window->display();
}

void GameView::drawOpening()
{
  _window->clear();
  _background_menu_GE->draw(_window);
  _opening_GE->draw(_window);
  _window->display();
}

void GameView::synchronizeEnemiesShipsMap(std::vector <Ship*> Ships)
{
  int x, y, w, h;
  for ( map<GraphicElement*,Ship*>::iterator it=_map_enemies_ships.begin(); 
	it != _map_enemies_ships.end(); it++)
    {
      delete (*it).first;
    }
  _map_enemies_ships.clear();
	
  if (Ships.size() !=0)
    {	
      for(vector <Ship*>::iterator it2=Ships.begin() ; it2!=Ships.end() ; ++it2)
	{
	  if (*it2 != NULL)
	    {
	      x = (*it2)->getX();
	      y = (*it2)->getY();
	      w = (*it2)->getW();
	      h = (*it2)->getH();
	      switch ((*it2)->getLvl())
		{
		case 1: 
		  _map_enemies_ships.insert(make_pair(new GraphicElement(&_enemy_ship1_texture,
									 x, y, w, h),*it2)); 
		  break;
		case 2: 
		  _map_enemies_ships.insert(make_pair(new GraphicElement(&_enemy_ship2_texture,
									 x, y, w, h),*it2)); 
		  break;
		case 3: 
		  _map_enemies_ships.insert(make_pair(new GraphicElement(&_enemy_ship3_texture,
									 x, y, w, h),*it2)); 
		  break;
		}
	    } 
	}
    }
  /*for (int i=0; i<_map_enemies_ships.size();i++){
    cout <<_map_enemies_ships[i] << endl;
    }*/
}

void GameView::synchronizeEnemiesShootsMap(std::vector <Laser*> Lasers)
{
  int x, y, w, h;
  for ( map<GraphicElement*,Laser*>::iterator it=_map_enemies_shoots.begin(); 
	it != _map_enemies_shoots.end(); it++)
    {
      delete (*it).first;
    }
  _map_enemies_shoots.clear();
  if (Lasers.size() != 0)
    {
      for(vector <Laser*>::iterator it2=Lasers.begin() ; it2!=Lasers.end() ; ++it2)
	{
	  if (*it2 != NULL)
	    {
	      x = (*it2)->getX();
	      y = (*it2)->getY();
	      w = (*it2)->getW();
	      h = (*it2)->getH();
	      _map_enemies_shoots.insert(make_pair(new GraphicElement(&_laser1_texture, x, y, w, h),*it2)); 
	    } 
	}
    }
}
  
  
void GameView::synchronizePlayerShootsMap(std::vector <Laser*> Lasers)
{
  int x, y, w, h;
  for ( map<GraphicElement*,Laser*>::iterator it=_map_player_shoots.begin(); 
	it != _map_player_shoots.end(); it++)
    {
      delete (*it).first;
    }
  _map_player_shoots.clear();
  if (Lasers.size() != 0)
    {
      for(vector <Laser*>::iterator it2=Lasers.begin() ; it2!=Lasers.end() ; ++it2)
	{
	  if (*it2 != NULL)
	    {
	      x = (*it2)->getX();
	      y = (*it2)->getY();
	      w = (*it2)->getW();
	      h = (*it2)->getH();
	      _map_player_shoots.insert(make_pair(new GraphicElement(&_laser1_texture, x, y, w, h),*it2));  
	    }
	}
    }
}

void GameView::drawEnemiesShipsMap()
{
  for ( map<GraphicElement*,Ship*>::iterator it=_map_enemies_ships.begin(); 
	it != _map_enemies_ships.end(); it++)
    {
      it->first->draw(_window);
    }
}
void GameView::drawEnemiesShootsMap()
{
  for ( map<GraphicElement*,Laser*>::iterator it=_map_enemies_shoots.begin(); 
	it != _map_enemies_shoots.end(); it++)
    {
      it->first->draw(_window);
    }
}
void GameView::drawPlayerShootsMap()
{
  for ( map<GraphicElement*,Laser*>::iterator it=_map_player_shoots.begin(); 
	it != _map_player_shoots.end(); it++)
    {
      it->first->draw(_window);
    }
}
