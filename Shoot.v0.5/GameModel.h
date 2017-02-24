// GameModel.h

#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include <vector>
#include <sstream>
#include <string>
#include "Element.h"
#include "Ship.h"
#include "Laser.h"
#include <sys/time.h>
#include "utils.h"

class GameModel {
	private:
		/// <summary>
		/// Largeur et hauteur du GameModel
		/// </summary>
		int _w, _h;
		
		/// <summary>
		/// Score de la partie courante
		/// </summary>
		int _score;
		
		/// <summary>
		/// Niveaux courant
		/// </summary>
		int _stage;
		
		/// <summary>
		/// Booléen permettant de savoir si le niveaux courant est passé ou pas.
		/// </summary>
		bool _level_passed;
		
		/// <summary>
		/// Permet de savoir si le joueur est en jeu ou pas
		/// </summary>
		bool _in_game;
		
		/// <summary>
		/// Objectif de la partie
		/// </summary>
		int _goal;
		
		/// <summary>
		/// Nombre d'ennemis tués dans le niveau courant
		/// </summary>
		int _kills;
		
		/// <summary>
		/// Vaisseau du joueur
		/// </summary>
		Ship* _player;
		
		/// <summary>
		/// Dernier moment ou un ennemi est apparut
		/// </summary>
		unsigned int _last_enemi_spawn;
		
		/// <summary>
		/// Prochain moment ou un ennemi apparaitra
		/// </summary>
		unsigned int _next_enemi_spawn;
		
		/// <summary>
		/// Description de la variable et de son rôle dans le programme/classe.
		/// </summary>
		int _last_kill;
		
		/// <summary>
		/// Vecteur de pointeurs sur des Ship contenant les vaisseaux enemis
		/// </summary>
		std::vector <Ship*> _enemies;
		
		/// <summary>
		/// Vecteur de pointeurs sur des Laser contenant les tirs du joueur
		/// </summary>
		std::vector <Laser*> _tirs_player;
		
		/// <summary>
		/// Vecteur de pointeurs sur des Laser contenant les tirs des enemis
		/// </summary>
		std::vector <Laser*> _tirs_enemies;
		
		/// <summary>
		/// Vecteur d'entier contenant les position des enemis à detruire dans le vecteur _enemies
		/// </summary>
		std::vector <int> _ships_to_destroy;
		
		/// <summary>
		/// Vecteur d'entier contenant les position des tirs du joueur à detruire dans le vecteur _tirs_player
		/// </summary>
		std::vector <int> _tirs_player_to_destroy;
		
		/// <summary>
		/// Vecteur d'entier contenant les position des tirs des ennemis a detruire dans le vecteur _tirs_enemies
		/// </summary>
		std::vector <int> _tirs_enemies_to_destroy;

	public:
        /*
         * Constructeurs et destructeur
        */
		GameModel();
		GameModel(int w, int h);
		~GameModel();


		/// <summary>
		/// Cette methode permet de mettre a jours jour le modèle en le faisant passer a l'étape suivante.
		/// Elle gère tout les autres nextStep.
		/// </summary>
		void nextStep();

		/// <summary>
		/// Cette methode permet de mettre a jours jour le vaisseau du joueur en gèrant son état, 
		/// ses déplacements, creer les tirs.
		/// </summary>
		void nextStepPlayer();

		/// <summary>
		/// Cette methode permet de mettre a jours jour les vaisseaux ennemis en gèrant leurs états, 
		/// leurs déplacements, creer les tirs.
		/// </summary>
		void nextStepShips();
		
		/// <summary>
		/// Cette methode permet de mettre a jours jour les tirs du joueur en gèrant leurs états, 
		/// leurs déplacements. Dans cette méthode sont aussi gèrés les collisions des tirs du joueur 
		/// avec les vaisseaux ennemis.
		/// </summary>		
		void nextStepPlayerLasers();
		
		/// <summary>
		/// Cette methode permet de mettre a jours jour les tirs des ennemis en gèrant leurs états, 
		/// leurs déplacements. Dans cette méthode sont aussi gèrés les collisions des tirs ennemis 
		/// avec le vaisseau du joueur.
		/// </summary>
		void nextStepEnemiesLasers();

		/// <summary>
		/// Cette méthode permet de modifier les attributs _is_moving_right, et _is_moving_left du vaisseaux du joueur.
		/// </summary>
		/// <param name=right>parametre qui sert à modifier _is_moving_right.</param>
		/// <param name=left>parametre qui sert à modifier _is_moving_left.</param>
		/// <returns>Valeur passée en argument non modifiée car la fonction ne fait rien .</returns>
		void setShipMovingX(bool right, bool left);
		
		/// <summary>
		/// Cette méthode permet de modifier les attributs _is_moving_up, et _is_moving_down du vaisseaux du joueur.
		/// </summary>
		/// <param name=right>parametre qui sert à modifier _is_moving_up.</param>
		/// <param name=left>parametre qui sert à modifier _is_moving_down.</param>
		void setShipMovingY(bool up, bool down);

		/// <summary>
		/// Cette méthode permet de récuperer les attributs _x (coordonnée en x), et _y (coordonnée en y)
		/// du vaisseaux du joueur.
		/// </summary>
		/// <param name=x> parametre qui sert à récuperer _x, il est donc passé par réference et sera modifier.</param>
		/// <param name=y> parametre qui sert à récuperer _y, il est donc passé par réference et sera modifier.</param>
		void getShipPlayerPosition(float & x, float & y);
		
		/// <summary>
		/// Cette méthode permet de récuperer les attributs _h (hauteur), et _w (largeur)
		/// du vaisseaux du joueur.
		/// </summary>
		/// <param name=h> parametre qui sert à récuperer _h, il est donc passé par réference et sera modifier.</param>
		/// <param name=w> parametre qui sert à récuperer _w, il est donc passé par réference et sera modifier.</param>
		void getShipPlayerSize(float & h, float & w);
		
		
		/// <summary>
		/// Cette méthode permet de récuperer les adresses des 3 vecteur _enemies, _tirs_enemies et _tirs_player.
		/// Cette méthode est utilisée dans le GameView pour synchroniser les maps.
		/// </summary>
		/// <param name=enemies_lasers>parametre qui sert à récuperer l'adresse de _tirs_enemies.</param>
		/// <param name=player_lasers>parametre qui sert à récuperer l'adresse de _tirs_player.</param>
		/// <param name=enemies_ships>parametre qui sert à récuperer l'adresse de _enemies.</param>
		void getVectors(std::vector<Laser*>* &enemies_lasers, std::vector<Laser*>* &player_lasers,
								std::vector<Ship*>* &enemies_ships); 
								
		/// <summary>
		/// Cette méthode permet de récuperer les diverse information sur le jeu (score, niveaux, santé du joueur...).
		/// Cette méthode transtype ces information en chaine de caractères puis les renvoie dans les 
		/// parametres qui sont passés par réference.
		/// </summary>
		/// <param name=score>parametre qui sert à récuperer le score de la partie courante.</param>
		/// <param name=health>parametre qui sert à récuperer la santé du joueur.</param>
		/// <param name=life>parametre qui sert à récuperer les vies restantes du joueur.</param>
		/// <param name=kills>parametre qui sert à récuperer le nombre d'ennemis tués.</param>
		/// <param name=goal>parametre qui sert à récuperer le nombre d'ennemis à tués (objectif pour finir le niveau).</param>
		/// <param name=stage>parametre qui sert à récuperer le niveau dans lequel on joue.</param>
		void getInfosString(std::string &score, std::string &health, std::string &life, 
							std::string &kills, std::string &goal, std::string &stage);
							
		/// <summary>
		/// Cette méthode renvoie la valeur du niveau courant
		/// </summary>
		/// <returns>Valeur de _stage en int .</returns>
		int getStage();
		
		/// <summary>
		/// Cette méthode renvoie la valeur du booléen _level_passed.
		/// </summary>
		/// <returns>Valeur de _level_passed.</returns>
		bool getLevelPassed();
		
		/// <summary>
		/// Cette méthode renvoie la valeur du booléen _in_game.
		/// </summary>
		/// <returns>Valeur de _in_game.</returns>
		bool getInGame();
		
		/// <summary>
		/// Cette méthode renvoie le nombres de vies restantes du joueur.
		/// </summary>
		/// <returns>Valeur de _player._life en int .</returns>
		int getPlayerLife();

		/// <summary>
		/// Cette méthode permet de changer la valeur de _player._firing avec la valeur donné en parametre.
		/// </summary>
		/// <param name=pf> parametre qui sert à changé la valeur de _player._firing .</param>
		void setPlayerFiring (bool pf);
		
		/// <summary>
		/// Cette méthode permet de changer la valeur de _player._firing avec la valeur donné en parametre.
		/// </summary>
		/// <param name=pf> parametre qui sert à changé la valeur de _player._firing .</param>
		void setLevelPassed(bool lp);
		
		/// <summary>
		/// Cette méthode permet de changer la valeur de _player._firing avec la valeur donné en parametre.
		/// </summary>
		/// <param name=pf> parametre qui sert à changé la valeur de _player._firing .</param>
		void setInGame(bool ig);

		/// <summary>
		/// Cette méthode fais tirer le joueur.
		/// </summary>
		void playerShoot();
		
		/// <summary>
		/// Cette méthode fais tirer le vaisseau passé en parametre.
		/// </summary>
		/// <param name=s> Vaisseau a faire tirer.</param>
		void enemiesShoot(Ship* s);
		
		/// <summary>
		/// Cette méthode renvoie le nombres de vies restantes du joueur.
		/// </summary>
		void spawnEnemiesShip();

		/// <summary>
		/// Cette méthode détruits touts les vaisseaux ennemis qui doivent etre detruits.
		/// </summary>
		void destroyShips();
		
		/// <summary>
		/// Cette méthode détruits touts les tirs du joueurs qui doivent etre detruits.
		/// </summary>
		void destroyPlayerLasers();
		
		/// <summary>
		/// Cette méthode détruits touts les tirs ennemis qui doivent etre detruits.
		/// </summary>
		void destroyEnemiesLasers();

		/// <summary>
		/// Cette méthode vide entierements les 3 vecteurs _enemies, _tirs_enemies et _tirs_player.
		/// Elle suprime donc tout ce qui apparait a l'écran, excepté le joueur.
		/// </summary>
		void reset();

};
#endif
