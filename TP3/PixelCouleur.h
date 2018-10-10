#ifndef TP3_PIXEL_COULEUR_H
#define TP3_PIXEL_COULEUR_H

#include "Pixel.h"

enum Couleur { R=0, G=1, B=2 };  // R = 0, G = 1, B = 2
const int LONGUEUR_TABLEAU = 3;  // donnee_[3]

class PixelCouleur :
	public Pixel
{
public:
    // Constructeur par defaut
	PixelCouleur();
    // Constructeur par parametres
	PixelCouleur(const unchar& r, const unchar& g, const unchar& b);
    // Destructeur
	~PixelCouleur();

    // Mutateurs
	void modifierTeinteRouge(unchar d);
	void modifierTeinteVert(unchar d);
	void modifierTeinteBleue(unchar d);

    // Accesseur
    unchar retournerR() const;
    unchar retournerG() const;
    unchar retournerB() const;

    // Fonctions de conversion
	bool convertirPixelBN() const;
	unchar convertirPixelGris() const;

    // Surcharge de l'operateur ==
	bool operator==(const PixelCouleur& pixel) const;

private:
	unchar donnee_[3];
};

#endif // TP3_PIXEL_COULEUR_H