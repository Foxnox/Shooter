#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <cstdlib>
#include "shoot_const.h"

///////////////							////////////////
// Classe Element : 								  //
// Objet fixes possedants une position est une taille //
///////////////							////////////////

class Element
{
	protected : 
		float _x; // coordonée en abcsisse
		float _y; // coordonée en ordonné
		float _h; // taille : largeur
		float _w; // taille : hauteur
	
	public : 
		/////////////////////////////////
		// CONSTRUCTEURS DESTRUCTEUR   //
		/////////////////////////////////
		Element();
		Element(float x, float y, float h, float w);
		~Element();
		
		/////////////////////////////////
		// ACSESSEURS ECRITURE/LECTURE //
		/////////////////////////////////
		float getX() const;
		float getY() const;
		float getH() const;
		float getW() const;
		
		void setPos(float x, float y); // permet de definir la position de l'element
		void resize(float h, float w); // definie la taille de l'element
		
		/////////////////////////////////
		// METHODES DIVERSES		   //
		/////////////////////////////////		
		
		/// <summary>
		/// Permet de savoir si un element est sorti de l'ecran
		/// </summary>
		/// <returns>renvoie vrais si l'Element est hors de l'ecran et faux sinon</returns>
		bool isOutOfScreen();
		
};


#endif
