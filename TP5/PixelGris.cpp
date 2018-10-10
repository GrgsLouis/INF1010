#include "PixelGris.h"


// Constructeur par défaut
PixelGris::PixelGris() {
	donnee_ = 0;
}

// Constructeur par paramètre avec int
PixelGris::PixelGris(unsigned int donnee) {
	donnee_ = testPixel(donnee);
}

// Constructeur par paramètre
PixelGris::PixelGris(unchar donnee): donnee_(donnee) {}

// Rien à faire ici
PixelGris::~PixelGris() {}

// Retourner noir ou blanc (le plus près)
bool PixelGris::convertirPixelBN() {
    if (donnee_ > 127) {
        return true;
    } else {
        return false;
    }
}

// Déjà gris, juste retourner valeur ici
unchar PixelGris::convertirPixelGris() {
    return donnee_;
}

// Retourner nouveau pixel identique
Pixel* PixelGris::retournerUneCopieProfonde() {
    PixelGris* copie = new PixelGris(donnee_);
    return copie;
}

// Retourner équivalent rouge
unchar PixelGris::retournerR() const {
    return (unchar) donnee_;
}

// Retourner équivalent vert
unchar PixelGris::retournerG() const {
    return (unchar) donnee_;
}

// Retourner équivalent bleu
unchar PixelGris::retournerB() const {
    return (unchar) donnee_;
}

// Inverser pixel
void PixelGris::mettreEnNegatif() {
    donnee_ = 255-donnee_;
}

// Retourner valeur
unchar PixelGris::obtenirDonnee() const {
    return donnee_;
}

// Toujours false
bool PixelGris::estMajoriteRouge() const {
	return false;
};

// Toujours false
bool PixelGris::estMajoriteVert() const {
	return false;
};

// Toujours false
bool PixelGris::estMajoriteBleu() const {
	return false;
};

// Retourner valeur entre 0 et 1 (luminance)
double PixelGris::retournerIntensiteMoyenne() const {
	return ((double)donnee_ / 255.0);
};

