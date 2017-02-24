#ifndef SHIP_H
#define SHIP_H

#include "MovableElement.h"

class Ship : public MovableElement
{
	private : 
		/// <summary>
		/// Santé du vaisseau
		/// </summary>
		int _health;
		
		/// <summary>
		/// Permet de savoir si il s'agit du joueur ou d'un enemi
		/// </summary>
		bool _is_player;
		
		/// <summary>
		/// Vies restante au vaisseau
		/// </summary>
		int  _life;
		
		/// <summary>
		/// Permet de savoir si le vaisseau est en vie (true) ou pas (false)
		/// </summary>
		bool _alive;
		
		/// <summary>
		/// Permet de savoir si le vaisseau tire (true) ou pas (false)
		/// </summary>
		bool _firing;
		
		/// <summary>
		/// Niveau du vaisseau (determina sa puissance
		/// </summary>
		int _level; 
		
		/// <summary>
		/// Dernier moment ou le vaisseau a tiré
		/// </summary>
		int _last_fire;
		
	public : 
		Ship(bool player, int lvl);
		
		/////////////////////////
		// ACSESSEURS LECTURE  //
		/////////////////////////
		/// <summary>
		/// Cette méthode renvoie la valeur du niveau du vaisseau
		/// </summary>
		/// <returns>Valeur de _level.</returns>
		int getLvl();
		
		/// <summary>
		/// Cette méthode renvoie si le vaisseau est en vie ou pas
		/// </summary>
		/// <returns>Valeur de _alive.</returns>
		bool getAlive();
		
		/// <summary>
		/// Cette méthode renvoie si le vaisseau tire ou pas
		/// </summary>
		/// <returns>Valeur de _firing.</returns>
		bool getFiring();
		
		/// <summary>
		/// Cette méthode renvoie le dernier moment ou le vaisseau a tiré
		/// </summary>
		/// <returns>Valeur de _last_fire.</returns>
		int getLastFire();
		
		/// <summary>
		/// Cette méthode renvoie la valeur du niveau courant
		/// </summary>
		/// <returns>Valeur de _stage en int .</returns>
		int getHealth();
		
		/// <summary>
		/// Cette méthode renvoie le nombre de vie restante du vaisseau
		/// </summary>
		/// <returns>Valeur de _life.</returns>
		int getLife();
		
		/////////////////////////
		// ACSESSEURS ECRITURE //
		/////////////////////////
		
		/// <summary>
		/// Cette méthode permet de changer la valeur de _alive avec la valeur de a.
		/// </summary>
		void setAlive(bool a);
		
		/// <summary>
		/// Cette méthode permet de changer la valeur de _firing avec la valeur de f.
		/// </summary>
		void setFiring(bool f);
		
		/// <summary>
		/// Cette méthode permet de changer la valeur de _last_fire avec la valeur de lf.
		/// </summary>
		void setLastFire(int lf);
		
		/// <summary>
		/// Cette méthode permet de changer la valeur de _health avec la valeur de health.
		/// </summary>
		void setHealth(int health);
		
		/// <summary>
		/// Cette méthode permet de changer la valeur de _life avec la valeur de life.
		/// </summary>
		void setLife(int life);
		
		

};

#endif
