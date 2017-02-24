#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H

#include <SFML/Graphics.hpp>

class GraphicElement : public sf::Sprite {
	public:
		GraphicElement();
		GraphicElement(sf::Texture * image, int x, int y, int w, int h);

		virtual ~GraphicElement();

		/// <summary>
		/// Permet d'afficher le GrpahicElement dans la Window donnée en parametre.
		/// </summary>
		/// <param name=_window> second element</param>
		virtual void draw(  sf::RenderWindow * _window);

		/// <summary>
		/// Permet de changer la position du GraphicElement
		/// </summary>
		/// <param name=pos> Vecteur de 2 float</param>
		/// <param name=x> Nouvelle coordonné en x</param>
		/// <param name=y> Nouvelle coordonné en y</param>
		void setPosition(const sf::Vector2f & pos);
		void setPosition(int x, int y);

		/// <summary>
		/// Permet de changer la taille du GraphicElement
		/// </summary>
		/// <param name=w> Nouvelle largeur</param>
		/// <param name=h> Nouvelle hauteur</param>
		void resize(int w, int h);
		
		/// <summary>
		/// Renvoie true si le point (x;y) est dans le GraphicElement et false sinon
		/// </summary>
		bool contain(int x, int y);
	private:
	
		/// <summary>
		/// Largeur (_w) et hauteur (_h) du GraphicElement
		/// </summary>
		int _w, _h;
};
#endif
