//
// Created by Gabriel Bernard
//

#ifndef TP3_PIXEL_COULEUR_H
#define TP3_PIXEL_COULEUR_H

#include "Pixel.h"

enum Couleur { R=0, G=1, B=2 };  // R = 0, G = 1, B = 2
const int LONGUEUR_TABLEAU = 3;  // donnee_[3]

class PixelCouleur :
	public Pixel
{
public:
	PixelCouleur();
	PixelCouleur(const unchar& r, const unchar& g, const unchar& b);
	~PixelCouleur();

	void modifierTeinteRouge(unchar d);
	void modifierTeinteVert(unchar d);
	void modifierTeinteBleue(unchar d);

    // Accesseur
    unchar retournerR() const;
    unchar retournerG() const;
    unchar retournerB() const;
	PixelCouleur* retournerCopieProfonde();
	virtual void mettreEnNegatif();
	bool convertirPixelBN() const;
	unchar convertirPixelGris() const;
	virtual unchar* convertirPixelCouleur() const; //pas sure si on l'ajoute
	/*virtual PixelCouleur& operator=(const PixelCouleur* pixel);*/

private:
	unsigned int somme() const;

	unchar donnee_[LONGUEUR_TABLEAU];
};

#endif // TP3_PIXEL_COULEUR_H