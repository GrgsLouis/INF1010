#ifndef TP3_PIXELBN_H
#define TP3_PIXELBN_H

#include "Pixel.h"
#include "TypePixel.h"

class PixelBN: public Pixel
{
public:
    // Constructeur par defaut
	PixelBN();
    // Constructeur par parametre
	PixelBN(bool p);
    // Destructeur
	~PixelBN();

    // Fonctions de conversion
	unchar* convertirPixelCouleur() const;
	unchar convertirPixelGris() const;

    // Accesseur
	bool obtenirDonnee() const;

    // Surcharge de l'operateur ==
	bool operator==(const PixelBN& pixel) const;

private:
	bool donnee_;
};

#endif // TP3_PIXELBN_H