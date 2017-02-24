#ifndef PONG_CONST_H
#define PONG_CONST_H
#include <string>

const std::string BACKGROUND_IMG = "background.png";
const std::string SHIP_PLAYER_IMG = "ship.png";
const std::string BACKGROUNG_MENU_IMG = "background.png";
const std::string PLAY_OFF_IMG = "PlayButtonGray.png";
const std::string QUIT_OFF_IMG = "QuitButtonGray.png";
const std::string PLAY_ON_IMG = "PlayButtonRed.png";
const std::string QUIT_ON_IMG = "QuitButtonRed.png";
const std::string TRAN_WIN = "YouWin.png";
const std::string TRAN_LOOSE = "YouLoose.png";
const std::string TRAN_DIE = "YouDie.png";
const std::string OPEN_IMG = "Intro.png";


const int MODEL_WIDTH = 600;
const int MODEL_HEIGHT = 650;

const int VIEW_WIDTH = 600;
const int VIEW_HEIGHT = 650;
const int VIEW_BPP = 32;

const int FRL = 30; // FRAMERATE LIMIT (limitation du rafraichissement de l'image en ips)


// TAILLE DU VAISSEAU DU JOUEUR //
const int PLAYER_SHIP_WIDTH = 60;
const int PLAYER_SHIP_HEIGHT = 70;

const std::string ENEMY1_IMG = "enemy1.png";
const int ENNEMI1_SHIP_WIDTH = 40;
const int ENNEMI1_SHIP_HEIGHT= 56;

const std::string ENEMY2_IMG = "enemy2.png";
const int ENNEMI2_SHIP_WIDTH = 95;
const int ENNEMI2_SHIP_HEIGHT =57;

const std::string ENEMY3_IMG = "enemy3.png";
const int ENNEMI3_SHIP_WIDTH = 90;
const int ENNEMI3_SHIP_HEIGHT = 100;

const std::string LASER_IMG = "laser.png";
const int LASER_WIDTH =16;
const int LASER_HEIGHT =30;

const int SCROLL_SPEED = 5;
const int SHIP_SPEED = 7;
const int ENEMIES_SPEED = 4;
const int LASER_SPEED = 8;

const int BUTTON_HEIGHT = 120;
const int BUTTON_WIDTH = 200;

const int GOAL = 10;

const unsigned int TIME_BETWEEN_ATK = 500; // en ms
const unsigned int TIME_BETWEEN_KILL = 100; // en ms

#endif

