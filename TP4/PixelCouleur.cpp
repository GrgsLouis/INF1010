//
// Created by Gabriel Bernard
//

#include "PixelCouleur.h"

// Constructeur par défaut
PixelCouleur::PixelCouleur() : Pixel() {
	donnee_[Couleur::R] = donnee_[Couleur::G] = donnee_[Couleur::B] = VALEUR_MIN_PIXEL;
}

// Constructeur par paramètres
PixelCouleur::PixelCouleur(const unchar& r, const unchar& g, const unchar& b) : Pixel() {
    donnee_[Couleur::R] = testPixel(r);
    donnee_[Couleur::G] = testPixel(g);
    donnee_[Couleur::B] = testPixel(b);
}

// Rien à faire ici
PixelCouleur::~PixelCouleur() {}

// Retourner rouge
unchar PixelCouleur::retournerR() const {
	return donnee_[Couleur::R];
}

// Retourner vert
unchar PixelCouleur::retournerG() const {
    return donnee_[Couleur::G];
}

// Retourner bleu
unchar PixelCouleur::retournerB() const {
    return donnee_[Couleur::B];
}

// Sommer les veleurs (aka luminance)
unsigned int PixelCouleur::somme() const {
	unsigned int somme = donnee_[Couleur::R] + donnee_[Couleur::G] + donnee_[Couleur::B];
	return somme;
}

// Donner l'équivalent blanc ou noir
bool PixelCouleur::convertirPixelBN() const {
	unsigned int moyenne = somme() / 3;
	return moyenne > 127;
}

// Donner l'équivalent gris
unchar PixelCouleur::convertirPixelGris() const {
	return somme() / 3;
}

// Modifier valeurs
void PixelCouleur::modifierTeinteRouge(unchar d) {
	donnee_[Couleur::R] = d;
}
void PixelCouleur::modifierTeinteVert(unchar d) {
	donnee_[Couleur::G] = d;
}
void PixelCouleur::modifierTeinteBleue(unchar d) {
	donnee_[Couleur::B] = d;
}

// Inverser pixel
void PixelCouleur::mettreEnNegatif() {
		donnee_[0] = 255 - donnee_[0];
		donnee_[1] = 255 - donnee_[1];
		donnee_[2] = 255 - donnee_[2];
}

// Retourner nouveau pixel identique
PixelCouleur* PixelCouleur::retournerCopieProfonde() { // a revoir
	PixelCouleur* pixelcouleur = new PixelCouleur(retournerR(), retournerG(), retournerB());
	return pixelcouleur;
}

// Retourner équivelent couleur, déjà en couleur
unchar* PixelCouleur::convertirPixelCouleur() const {
	//unchar* nouveau = new unchar[3];	// a revoirr
	unchar nouveau[3];
	nouveau[0] = donnee_[0];
	nouveau[1] = donnee_[1];
	nouveau[2] = donnee_[2];
	return nouveau;
	// Pourquoi pas juste retourner donnee_?
}
//
//PixelCouleur& PixelCouleur::operator=(const PixelCouleur* pixel) {
//	donnee_[0] = pixel->donnee_[0];
//	donnee_[1] = pixel->donnee_[1];
//	donnee_[2] = pixel->donnee_[2];
//	return *this;
//}