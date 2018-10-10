#include "PixelBN.h"

// Constructeur par d�faut
PixelBN::PixelBN() {
	donnee_ = false;
}

// Constructeur par param�tre
PixelBN::PixelBN(bool p) {
	donnee_ = p;
}

// Rien � faire ici
PixelBN::~PixelBN() {}

// Retourner blanc ou noir en �quivalent gris
unchar PixelBN::convertirPixelGris() {
    if(donnee_) {
        return VALEUR_MAX_PIXEL;
    } else {
        return VALEUR_MIN_PIXEL;
    }
}

// D�j� noir et blanc, retourner valeur
bool PixelBN::convertirPixelBN() {
	return donnee_;
}

// Copie profonde, nouveau pixel
Pixel* PixelBN::retournerUneCopieProfonde() {
	PixelBN *copie = new PixelBN(donnee_);
	return copie;
}

// Retourner la donn�e
bool PixelBN::obtenirDonnee() {
	return donnee_;
}

// Retourner �quivalent rouge
unchar PixelBN::retournerR() const {
    if(donnee_) {
        return (unchar) VALEUR_MAX_PIXEL;
    } else {
        return (unchar) VALEUR_MIN_PIXEL;
    }
}

// Retourner l'�quivalent vert
unchar PixelBN::retournerG() const {
    if(donnee_) {
        return (unchar) VALEUR_MAX_PIXEL;
    } else {
        return (unchar) VALEUR_MIN_PIXEL;
    }
}

// Retourner l'�quivalent bleu
unchar PixelBN::retournerB() const {
    if(donnee_) {
        return (unchar) VALEUR_MAX_PIXEL;
    } else {
        return (unchar) VALEUR_MIN_PIXEL;
    }
}

// Inverser
void PixelBN::mettreEnNegatif() {
    donnee_ = !donnee_;
}

// Toujours false ici
bool PixelBN::estMajoriteRouge() const {
	return false;
};

// Toujours false ici
bool PixelBN::estMajoriteVert() const {
	return false;
};

// Toujours false ici
bool PixelBN::estMajoriteBleu() const {
	return false;
};

// Valeur est toujours 1 ou 0, donc la retourner telle quelle
double PixelBN::retournerIntensiteMoyenne() const {
	return ((double)donnee_);
};
