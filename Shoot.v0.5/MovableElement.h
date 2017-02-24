#ifndef MOVABLE_ELEMENT
#define MOVABLE_ELEMENT

#include "Element.h"

class MovableElement : public Element
{
	protected : 
		/// <summary>
		/// Vitesse en x de l'element
		/// </summary>
		float _vit_x;
		
		/// <summary>
		/// Vitesse en y de l'element
		/// </summary>
		float _vit_y;
		
		/// <summary>
		/// Permet de savoir si l'element bouge vers la droite (true) ou pas (false)
		/// </summary>
		bool _moving_right;
		
		/// <summary>
		/// Permet de savoir si l'element bouge vers la gauche (true) ou pas (false)
		/// </summary>
		bool _moving_left;
		
		/// <summary>
		/// Permet de savoir si l'element bouge vers le haut (true) ou pas (false)
		/// </summary>
		bool _moving_up;
		
		/// <summary>
		/// Permet de savoir si l'element bouge vers le bas (true) ou pas (false)
		/// </summary>
		bool _moving_down;
		
	public : 
		MovableElement();
		MovableElement(float x, float y, float h, float w,int vitx, int vity);
		MovableElement(float x, float y, float h, float w,int vitx,
						int vity, bool right, bool left, bool up, bool down);
		~MovableElement();
		
		/// <summary>
		/// Cette méthode permet de faire bouger l'element courant avec sa vitesse en x et en y selon l'etat des booléen.
		/// </summary>
		/// <param name=dx> Permet d'augmenter la vitesse en x de dx</param>
		/// <param name=dy> Permet d'augmenter la vitesse en y de dy</param>
		void move(int dx, int dy);
		
		/// <summary>
		/// Permet de modifier _moving_right avec moving
		/// </summary>>
		void setIsMovingRight(bool moving);
		
		/// <summary>
		/// Permet de modifier _moving_left avec moving
		/// </summary>
		void setIsMovingLeft(bool moving);
		
		/// <summary>
		/// Permet de modifier _moving_up avec moving
		/// </summary>
		void setIsMovingUp(bool moving);
		
		/// <summary>
		/// Permet de modifier _moving_down avec moving
		/// </summary>
		void setIsMovingDown(bool moving);
		
		/// <summary>
		/// Permet de savoir si 2 elements sont en contact.
		/// </summary>
		/// <param name=m> second element</param>
		bool enContact(const MovableElement & m);
};


#endif
