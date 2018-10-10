#include "Pixel.h"

// Constructeur par defaut
Pixel::Pixel() : type_(TypePixel::Couleur){}

// Constructeur par parametre
Pixel::Pixel(TypePixel tp) : type_(tp) {}

// Destructeur
Pixel::~Pixel() {}

// Fonction de test sur un pixel avec un unsigned int
unsigned int Pixel::testPixel(const unsigned int &valeur) const {
    if(valeur > VALEUR_MAX_PIXEL) {
        return VALEUR_MAX_PIXEL;
    } else {
        return valeur;
    }
}

// Fonction de test sur un pixel avec un unchar
unchar Pixel::testPixel(const unchar &valeur) const {
    if(valeur > VALEUR_MAX_PIXEL) {
        return VALEUR_MAX_PIXEL;
    } else {
        return valeur;
    }
}

// Accesseur
TypePixel Pixel::getType() const { return type_; }

// Surcharge de l'operateur =
bool Pixel::operator==(const Pixel& pixel) const {
    return(type_ == pixel.type_);
}
