#include "PixelCouleur.h"

// Constructeur par défaut
PixelCouleur::PixelCouleur() {
	assignerValeur(VALEUR_MIN_PIXEL);
}

// Constructeur avec bool
PixelCouleur::PixelCouleur(const bool& donnee) {
	if(donnee) {
        assignerValeur(VALEUR_MAX_PIXEL);
	}
	else {
        assignerValeur(VALEUR_MIN_PIXEL);
	}
}

// Constructeur par paramètres unchar
PixelCouleur::PixelCouleur(const unchar& R, const unchar& G, const unchar& B) {
    donnee_[Couleur::R] = testPixel(R);
    donnee_[Couleur::G] = testPixel(G);
    donnee_[Couleur::B] = testPixel(B);
}

// Constructeur avec int
PixelCouleur::PixelCouleur(const unsigned int& donnee) {
    assignerValeur(donnee);
}

// Constructeur avec unchar
PixelCouleur::PixelCouleur(const unchar& donnee) {
	assignerValeurs(donnee);
}

// Rien à faire ici
PixelCouleur::~PixelCouleur() {}

// Somme des pixels (luminance absolue)
unsigned int PixelCouleur::somme() const {
	unsigned int somme = donnee_[Couleur::R] + donnee_[Couleur::G] + donnee_[Couleur::B];
	return somme;
}

// Retourner blanc ou noir
bool PixelCouleur::convertirPixelBN() {
	unsigned int moyenne = somme() / 3;
	if (moyenne > 127) {
		return true;
	}
	else {
		return false;
	}
}

// Retourner équivalent gris (luminance)
unchar PixelCouleur::convertirPixelGris() {
	return (somme() / 3);
}

// Retourner nouveau pixel identique
Pixel* PixelCouleur::retournerUneCopieProfonde() {
    PixelCouleur *copie = new PixelCouleur(donnee_[Couleur::R], donnee_[Couleur::G], donnee_[Couleur::B]);
    return copie;
}

// Donner une valeur aux 3 couleurs (int)
void PixelCouleur::assignerValeur(const unsigned int& valeur) {
    donnee_[Couleur::R] = donnee_[Couleur::G] = donnee_[Couleur::B] = valeur;
}

// Donner une valeur aux 3 couleurs (unchar) (also le nom est différent... why?)
void PixelCouleur::assignerValeurs(const unchar& valeur) {
    donnee_[Couleur::R] = donnee_[Couleur::G] = donnee_[Couleur::B] = valeur;
}

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

// Modifier les valeurs de couleur
void PixelCouleur::modifierTeinteRouge(unchar d) {
	donnee_[Couleur::R] = testPixel((unsigned int) d);
}
void PixelCouleur::modifierTeinteVerte(unchar d) {
	donnee_[Couleur::G] = testPixel((unsigned int) d);
}
void PixelCouleur::modifierTeinteBleue(unchar d) {
	donnee_[Couleur::B] = testPixel((unsigned int) d);
}

// Inverser pixel
void PixelCouleur::mettreEnNegatif() {
	donnee_[Couleur::R] = 255 - donnee_[Couleur::R];
	donnee_[Couleur::G] = 255 - donnee_[Couleur::G];
	donnee_[Couleur::B] = 255 - donnee_[Couleur::B];
}

// TP 5
// Voir si majoritairement d'une couleur
bool PixelCouleur::estMajoriteRouge() const {
	return ((donnee_[Couleur::R] > donnee_[Couleur::G]) && (donnee_[Couleur::R] > donnee_[Couleur::B]));
	//return (donnee_[Couleur::R] > (donnee_[Couleur::G] + donnee_[Couleur::B]));
}
bool PixelCouleur::estMajoriteVert() const {
	//return (donnee_[Couleur::G] > (donnee_[Couleur::R] + donnee_[Couleur::B]));
	return ((donnee_[Couleur::G] > donnee_[Couleur::B]) && (donnee_[Couleur::G] > donnee_[Couleur::R]));
}
bool PixelCouleur::estMajoriteBleu() const {
	//return (donnee_[Couleur::B] > (donnee_[Couleur::G] + donnee_[Couleur::R]));
	//return ((donnee_[Couleur::B] > donnee_[Couleur::G]) && (donnee_[Couleur::B] ­­> donnee_[Couleur::R]));
	return ((donnee_[Couleur::B] > donnee_[Couleur::G]) && (donnee_[Couleur::B] > donnee_[Couleur::R]));
}

// Retourner intensité (luminance relative)
double PixelCouleur::retournerIntensiteMoyenne() const {
	return (((double)donnee_[Couleur::R] + (double)donnee_[Couleur::G] + (double)donnee_[Couleur::B])/765.0);
}
