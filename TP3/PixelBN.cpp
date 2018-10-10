#include "PixelBN.h"
enum Couleur { R = 0, G = 1, B = 2 };
// Constructeur par defaut
PixelBN::PixelBN():Pixel(TypePixel::NoireBlanc) {
	donnee_ = false;
}

// Constructeur par parametres
PixelBN::PixelBN(bool p):Pixel(TypePixel::NoireBlanc) {
	
	donnee_ = p;
}

PixelBN::~PixelBN() {

}
// Accesseur
bool PixelBN::obtenirDonnee() const {
    return donnee_;
}

unchar PixelBN::convertirPixelGris() const {
	return unchar(donnee_*255);
}
unchar* PixelBN::convertirPixelCouleur() const {
	unchar tableau[3] = { 0,0,0 };
	if (donnee_) {
		tableau[Couleur::R] =  255;
		tableau[Couleur::G] =  255;
		tableau[Couleur::B] = 255;
	}
	return tableau;
}

bool PixelBN::operator==(const PixelBN& pixel) const {
	return (pixel.type_ == type_ && pixel.donnee_ == donnee_);
}