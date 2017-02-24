#ifndef LASER
#define LASER
#include "MovableElement.h"

class Laser : public MovableElement
{
	private : 
	
		/// <summary>
		/// Dommage qu'inflige le laser
		/// </summary>
		int _dmg;
		
		/// <summary>
		/// Permet de savoir si il est actif.
		/// CàD, s'il doit etre ou non supprimer
		/// </summary>
		bool _active;
		
	public : 
		Laser();
		Laser(float x, float y, float h, float w,int vitx, int vity,int lvl);
		Laser(float x, float y, float h, float w,int vitx,
						int vity, bool stop, bool right, bool left, bool up, bool down,int lvl);
		~Laser();
		
		/// <summary>
		/// Cette méthode renvoie la valeur des dommages qu'inflige la laser
		/// </summary>
		/// <returns>Valeur de _dmg.</returns>
		int getDmg();
		
		/// <summary>
		/// Cette méthode renvoie si le laser est actif (true) ou pas (false)
		/// </summary>
		/// <returns>Valeur de _active.</returns>
		bool getActive() const;
		
		/// <summary>
		/// Permet de modifier _active avec act
		/// </summary>
		void setActive(bool act);
};


#endif
