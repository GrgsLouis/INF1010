#include "PixelGris.h"
enum Couleur { R = 0, G = 1, B = 2 };
PixelGris::PixelGris() :Pixel(TypePixel::NuanceDeGris) {
	donnee_ = 0;
}
// Constructeur par parametre
PixelGris::PixelGris(unsigned int donnee) : Pixel(TypePixel::NuanceDeGris) {
	
	if (donnee > 255) {
		donnee_ = 255;
	}
	else {
		donnee_ = donnee;
	}
}

PixelGris::~PixelGris() {

}

// Accesseur
unsigned int PixelGris::obtenirDonnee() const {
	return donnee_;
}

bool PixelGris::convertirPixelBN() const {
	if (donnee_ > 127) {
		return true;
	}
	else {
		return false;
	}
}

unchar* PixelGris::convertirPixelCouleur() const {
	unchar tableau[3];
	tableau[Couleur::R] = donnee_;
	tableau[Couleur::G] = donnee_;
	tableau[Couleur::B] = donnee_;
	return tableau;
}

bool PixelGris::operator==(const PixelGris& pixel) const {
	return (pixel.type_ == type_ && pixel.donnee_ == donnee_);
}
