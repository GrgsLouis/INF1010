#include "PixelCouleur.h"

// Constructeur par defaut
PixelCouleur::PixelCouleur() :Pixel(TypePixel::Couleur) { donnee_[Couleur::R] = 0; donnee_[Couleur::G] = 0; donnee_[Couleur::B] = 0; }

// Constructeur par parametre
PixelCouleur::PixelCouleur(const unchar& r, const unchar& g, const unchar& b) :Pixel(TypePixel::Couleur) {
	
	donnee_[Couleur::R] = r;
	donnee_[Couleur::G] = g;
	donnee_[Couleur::B] = b;
}

// Accesseurs
unchar PixelCouleur::retournerR() const {
    
	return donnee_[Couleur::R];
}

unchar PixelCouleur::retournerG() const {
 
    return donnee_[Couleur::G];
}

unchar PixelCouleur::retournerB() const {
    
    return donnee_[Couleur::B];
}

PixelCouleur::~PixelCouleur() {
	
}

void PixelCouleur::modifierTeinteRouge(unchar d) {
	donnee_[Couleur::R] = d;
}

void PixelCouleur::modifierTeinteVert(unchar d) {
	donnee_[Couleur::G] = d;
}

void PixelCouleur::modifierTeinteBleue(unchar d) {
	donnee_[Couleur::B] = d;
}

bool PixelCouleur::convertirPixelBN() const {
	unsigned int  moyenne = ((unsigned int(donnee_[Couleur::R] + donnee_[Couleur::G]) + donnee_[Couleur::B]) / 3); // on a ajouter double (...) tout sauf les ...

	
	return(moyenne > 127);
		
}

unchar PixelCouleur::convertirPixelGris() const {
	unsigned int moyenne = (unsigned int(donnee_[Couleur::R] + donnee_[Couleur::G]) + donnee_[Couleur::B]) / 3;
	unchar moyenne1 = moyenne;
	return (moyenne1);  
}

bool PixelCouleur::operator==(const PixelCouleur& pixel) const {
	return (pixel.type_ == type_ && pixel.donnee_[Couleur::R] == donnee_[Couleur::R] &&
		pixel.donnee_[Couleur::G] == donnee_[Couleur::G] && pixel.donnee_[Couleur::B] == donnee_[Couleur::B]);
}

