//
// Created by Gabriel Bernard
//

#include "PixelGris.h"

// Constructeur par défaut
PixelGris::PixelGris() : Pixel() {
	donnee_ = VALEUR_MIN_PIXEL;
}

// Constructeur par paramètre
PixelGris::PixelGris(unsigned int donnee) : Pixel() {
    if(donnee < VALEUR_MAX_PIXEL) {
        donnee_ = donnee;
    } else {
        donnee_ = VALEUR_MAX_PIXEL;
    }
}

// Rien à faire ici
PixelGris::~PixelGris() {}

// Équivalent en couleur
unchar* PixelGris::convertirPixelCouleur() const {
	unchar *ret = new unchar[3];
	ret[0] = ret[1] = ret[2] = donnee_;
	return ret;
}

// Équivalent blanc ou noir
bool PixelGris::convertirPixelBN() const {
	return donnee_ > 127;
}

// Retourner valeur
unsigned int PixelGris::obtenirDonnee() const {
	return donnee_;
}

// Inverser
void PixelGris::mettreEnNegatif() {
	donnee_ = 255 - donnee_;
}

// Retourner équivalent rouge
unchar PixelGris::retournerR() const {
	return donnee_;
}

// Retourner équivalent vert
unchar PixelGris::retournerG() const {
	return donnee_;
}

// Retourner équivalent bleu
unchar PixelGris::retournerB() const {
	return donnee_;
}

// Donner l'équivalent gris, mais déjà en gris
unchar PixelGris::convertirPixelGris() const {
	return donnee_;
}

// Retourner nouveau pixel identique
PixelGris* PixelGris::retournerCopieProfonde(){
	PixelGris* pixelGris = new PixelGris(donnee_);	// à revoir
	return pixelGris;
}
