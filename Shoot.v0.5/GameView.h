// Atelier 1
// GameView.h

#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GraphicElement.h"

class GameModel;
class Laser;
class Ship;

class GameView {
	private:
		/// <summary>
		/// Largeur (_w) et hauteur (_h) du GameView
		/// </summary>
		int _w, _h;
		
		/// <summary>
		/// Permet de savoir si l'on est dans une transition
		/// </summary>
		bool _in_transition;
		
		/// <summary>
		/// Contien les vaisseaux enemis et leurs graphicElements correspondant
		/// </summary>
		std::map<GraphicElement*,Ship *> _map_enemies_ships;
		
		/// <summary>
		/// Contien les tirs enemis et leurs graphicElements correspondant
		/// </summary>
		std::map<GraphicElement*,Laser *> _map_enemies_shoots;
		
		/// <summary>
		/// Contien les tirs du joueur et leurs graphicElements correspondant
		/// </summary>
		std::map<GraphicElement*,Laser *> _map_player_shoots;

		sf::RenderWindow * _window;

		/////////////////////////////////////
		//      DECLARATION DES IMAGES     //
		/////////////////////////////////////


		sf::Image _background_image; // image de fond d'ecran
		sf::Image _player_ship_image; // image du vaisseau du joueur

		sf::Image _backgroung_menu_image;  // image de fond d'ecran du menu

		sf::Image _play_button_off_image; // image du boutton PLAY quand la souris n'est pas dessus
		sf::Image _play_button_on_image; // image du boutton PLAY quand la souris est dessus
		sf::Image _quit_button_off_image; // image du boutton QUIT quand la souris n'est pas dessus
		sf::Image _quit_button_on_image; // image du boutton QUIT quand la souris est dessus

		sf::Image _enemy_ship1_image; // image des enemis de niveau 1
		sf::Image _enemy_ship2_image; // image des enemis de niveau 2
		sf::Image _enemy_ship3_image; // image des enemis de niveau 3

		sf::Image _laser1_image; // image des lasers

		sf::Image _tran_win_image; // ecran de transition de monté de niveau
		sf::Image _tran_loose_image; // ecran de fin de jeu
		sf::Image _tran_die_image; // ecran de mort

		sf::Image _opening_image; // image de l'introduction

				
		sf::Texture _background_texture; // image de fond d'ecran
		sf::Texture _player_ship_texture; // image du vaisseau du joueur

		sf::Texture _backgroung_menu_texture;  // image de fond d'ecran du menu

		sf::Texture _play_button_off_texture; // image du boutton PLAY quand la souris n'est pas dessus
		sf::Texture _play_button_on_texture; // image du boutton PLAY quand la souris est dessus
		sf::Texture _quit_button_off_texture; // image du boutton QUIT quand la souris n'est pas dessus
		sf::Texture _quit_button_on_texture; // image du boutton QUIT quand la souris est dessus

		sf::Texture _enemy_ship1_texture; // image des enemis de niveau 1
		sf::Texture _enemy_ship2_texture; // image des enemis de niveau 2
		sf::Texture _enemy_ship3_texture; // image des enemis de niveau 3

		sf::Texture _laser1_texture; // image des lasers

		sf::Texture _tran_win_texture; // ecran de transition de monté de niveau
		sf::Texture _tran_loose_texture; // ecran de fin de jeu
		sf::Texture _tran_die_texture; // ecran de mort

		sf::Texture _opening_texture; // image de l'introduction
		
		/////////////////////////////////////
		// DECLARATION DES GRAPHICELEMENT  //
		/////////////////////////////////////
		
		GraphicElement * _background_GE_sup;
		GraphicElement * _background_GE_inf;
		
		GraphicElement * _player_ship_GE; // Joueur
 
		GraphicElement * _laser1_GE; // Laser

		GraphicElement * _background_menu_GE; // Fond d'ecran du menu
		GraphicElement * _play_button_GE; // Boutton PLAY
		GraphicElement * _quit_button_GE; // Boutton QUIT

		GraphicElement * _transition_GE; // ecran de transition
		GraphicElement * _opening_GE; // Element de l'introduction


		GameModel * _model; 
		
		/// <summary>
		/// Gère le défilement de l'ecran dans le jeu
		/// </summary>
		void scrolling();
		
	public:
		GameView(int w, int h, int bpp);
		~GameView();

		/// <summary>
		/// Modifie _model avec model
		/// </summary>
		void setModel(GameModel * model);
		
		/// <summary>
		/// Gère l'affichage du jeu 
		/// </summary>
		void draw();
		
		/// <summary>
		/// synchronize les GraphicElement avec attribut du model correspondant
		/// </summary>
		void synchronize();
		
		/// <summary>
		/// Gère tout les evenement qui surviennent lors du jeu
		/// </summary>
		bool treatEvents();
		
		/// <summary>
		/// Gère tout les evenement qui surviennent dans le menu
		/// </summary>
		int treatEventsMenu();
		
		/// <summary>
		/// Gère tout les evenement qui surviennent dans les transitions
		/// </summary>
		bool treatEventsTransition();
		
		/// <summary>
		/// Gère tout les evenement qui surviennent dans l'introduction
		/// </summary>
		bool treatEventsOpening();

		/// <summary>
		/// Gère l'affichage du menu 
		/// </summary>
		void drawMenu();
		
		/// <summary>
		/// Gère l'affichage des transition 
		/// </summary>
		/// <param name=win> Permet d'afficher le bon ecran de transition</param>
		void drawTransition(bool win);
		
		/// <summary>
		/// Gère l'affichage de l'introduction
		/// </summary>
		void drawOpening();

		/// <summary>
		/// Remplie la map _map_enemies_ships avec :
		/// first : un GraphicElement*
		/// second : un Ship* contenu dans le vecteur passé en paramettre
		/// </summary>
		void synchronizeEnemiesShipsMap(std::vector <Ship*>);
		
		/// <summary>
		/// Remplie la map _map_enemies_shoots avec :
		/// first : un GraphicElement*
		/// second : un Laser* contenu dans le vecteur passé en paramettre
		/// </summary>
		void synchronizeEnemiesShootsMap(std::vector <Laser*>);
		
		/// <summary>
		/// Remplie la map _map_player_shoots avec :
		/// first : un GraphicElement*
		/// second : un Laser* contenu dans le vecteur passé en paramettre
		/// </summary>
		void synchronizePlayerShootsMap(std::vector <Laser*>);
		
		/// <summary>
		/// Affiche tout les GraphicElement contenu dans _map_enemies_ships
		/// </summary>
		void drawEnemiesShipsMap();
		
		/// <summary>
		/// Affiche tout les GraphicElement contenu dans _map_enemies_shoots
		/// </summary>
		void drawEnemiesShootsMap();
		
		/// <summary>
		/// Affiche tout les GraphicElement contenu dans _map_player_shoots
		/// </summary>
		void drawPlayerShootsMap();
		
		/// <summary>
		/// Affiche les information (score, niveau, vies restantes ...) de la partie en cours
		/// </summary>
		void showInfos ();

};
#endif
