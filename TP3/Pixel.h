#ifndef TP3_PIXEL_H
#define TP3_PIXEL_H

typedef unsigned char unchar;

#define VALEUR_MAX_PIXEL 255
#define VALEUR_MIN_PIXEL 0

#include <iostream>
#include "TypePixel.h"

class Pixel
{
public:
    // Constructeur par defaut
    Pixel();
    // Constructeur par parametres
	Pixel(TypePixel tp);
    // Destructeur
	~Pixel();

    // Accesseur
	TypePixel getType() const;

    // Test valeur Pixel
    unsigned int testPixel(const unsigned int& valeur) const;
    unchar testPixel(const unchar& valeur) const;

    // Surcharge d'operateur
	bool operator==(const Pixel& pixel) const;

protected:
	TypePixel type_;

};

#endif // PIXEL_H