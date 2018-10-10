//
// Created by Gabriel Bernard
//

#include "PixelBN.h"

// Constructeur par d�faut
PixelBN::PixelBN() : Pixel() {
	donnee_ = false;
}

// Constructeur par param�tre
PixelBN::PixelBN(bool p) : Pixel() {
	donnee_ = p;
}

// Rien � faire ici
PixelBN::~PixelBN() {}

// Retourner la valeur �quivalente en couleur
unchar* PixelBN::convertirPixelCouleur() const {
    unchar valeur = (unchar)VALEUR_MIN_PIXEL;
    if(donnee_) {
        valeur = (unchar)VALEUR_MAX_PIXEL;
    }

	unchar* ret = new unchar[3];
	ret[0] = ret[1] = ret[2] = valeur;

	return ret;
}

// // M�me chose pour le gris
unchar PixelBN::convertirPixelGris() const {
	return donnee_ ? VALEUR_MAX_PIXEL : VALEUR_MIN_PIXEL;
}

// Retourner blanc ou noir
bool PixelBN::obtenirDonnee() const {
	return donnee_;
}

// Inverser la valeur du pixel
void PixelBN::mettreEnNegatif() {
	donnee_ = 1 - donnee_;
}

// Retourner la valeur rouge �quivalente du pixel
unchar PixelBN::retournerR() const {
	return (donnee_ * 255);
}

// Retourner la valeur verte �quivalente du pixel
unchar PixelBN::retournerG() const {
	return (donnee_ * 255);
}

// Retourner la valeur bleue �quivalente du pixel
unchar PixelBN::retournerB() const {
	return (donnee_ * 255);
}

// Retourner un nouveau pixel identique
PixelBN* PixelBN::retournerCopieProfonde() {
	PixelBN* pixelbn = new PixelBN(donnee_); // this->donnee_ ou donnee_ ?
	return pixelbn;
}

// Donner l'�quivalent en BN... donc retourner valeur
bool PixelBN::convertirPixelBN() const {
	return donnee_;
}

//PixelBN& PixelBN::operator=(const PixelBN& pixel) {
//	donnee_ = pixel.donnee_;
//}