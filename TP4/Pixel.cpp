//
// Created by Gabriel Bernard
//

#include "Pixel.h"

Pixel::Pixel() {}


Pixel::~Pixel() {}

// Pour s'assurer de rester dans les valeurs valables de couleur
unsigned int Pixel::testPixel(const unsigned int &valeur) const {
    if(valeur > VALEUR_MAX_PIXEL) {
        return VALEUR_MAX_PIXEL;
    } else {
        return valeur;
    }
}

// M�me chose mais avec un unchar
unchar Pixel::testPixel(const unchar &valeur) const {
    if(valeur > VALEUR_MAX_PIXEL) {
        return VALEUR_MAX_PIXEL;
    } else {
        return valeur;
    }
}


// V�rifier que deux pixels sont de la m�me couleur, devrait fonctionner across les diff�rent types de pixels
bool Pixel::operator==(const Pixel& pixel) const {
    return( retournerB() == pixel.retournerB() && retournerG() == pixel.retournerG() && retournerR() == pixel.retournerR());
}
