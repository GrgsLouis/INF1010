#ifndef TP3_PIXEL_GRIS_H
#define TP3_PIXEL_GRIS_H

#include "Pixel.h"

class PixelGris :
	public Pixel
{
public:
    // Constructeur par defaut
	PixelGris();
    // Constructeur par parametre
	PixelGris(unsigned int);
    // Destructeur
	~PixelGris();

    // Fonctions de conversion
	bool convertirPixelBN() const;
	unchar* convertirPixelCouleur() const;

    // Accesseur
	unsigned int obtenirDonnee() const;

    // Surcharge de l'operateur ==
	bool operator==(const PixelGris& pixel) const;
    
private:
	unchar donnee_;
};

#endif // TP3_PIXEL_GRIS_H