#include "Pixel.h"
#include "Const.h"
#include <iostream>
#include <string>
using namespace std;
// Un constructeur par défaut qui initialise les attributs aux valeurs par défaut.
Pixel::Pixel() {
	tauxRouge_ = 0;
	tauxVert_ = 0;
	tauxBleu_ = 0;
}
// Un constructeur par paramètres qui initialise les attributs aux valeurs correspondantes.
Pixel::Pixel(unsigned int tauxRouge, unsigned int tauxVert, unsigned int tauxBleu) {
	tauxRouge_ = tauxRouge;
	tauxVert_ = tauxVert;
	tauxBleu_ = tauxBleu;
}
// destructeur du pixel qui desalloue la memoire prise par pixel.
Pixel::~Pixel() {
}
// cette fonction nous permet d'avoir le taux de la couleur rouge du pixel.
unsigned int Pixel::getTauxRouge() {
	return tauxRouge_;
}
// cette fonction nous permet d'avoir le taux de la couleur vert du pixel.
unsigned int Pixel::getTauxVert() {
	return tauxVert_;
}
// cette fonction nous permet d'avoir le taux de la couleur bleu du pixel.
unsigned int Pixel::getTauxBleu() {
	return tauxBleu_;
}
// cette fonction modifie le taux rouge en faisant attention à ne pas passer la valeur maximal et minimal que le pixel peut avoir.
void Pixel::modifierTeinteRouge(int incrementRouge) {
	int ResultatRouge = 0;
	ResultatRouge = tauxRouge_ + incrementRouge;
		if (ResultatRouge < MIN_CONCENTRATION_COULEUR) {
			tauxRouge_ = MIN_CONCENTRATION_COULEUR;
		}
		else if (ResultatRouge > MAX_CONCENTRATION_COULEUR) {
			tauxRouge_ = MAX_CONCENTRATION_COULEUR;
		}
		else {
			tauxRouge_ = ResultatRouge;
		}
}
// cette fonction modifie le taux vert en faisant attention à ne pas passer la valeur maximal et minimal que le pixel peut avoir.
void Pixel::modifierTeinteVert(int incrementVert) {
	int ResultatVert = 0;
	ResultatVert = tauxVert_ + incrementVert;
	if (ResultatVert < MIN_CONCENTRATION_COULEUR) {
		tauxVert_ = MIN_CONCENTRATION_COULEUR;
	}
	else if (ResultatVert > MAX_CONCENTRATION_COULEUR) {
		tauxVert_ = MAX_CONCENTRATION_COULEUR;
	}
	else {
		tauxVert_ = ResultatVert;
	}
}
// cette fonction modifie le taux bleu en faisant attention à ne pas passer la valeur maximal et minimal que le pixel peut avoir.
void Pixel::modifierTeinteBleu(int incrementBleu) {
	int ResultatBleu = 0;
	ResultatBleu = tauxBleu_ + incrementBleu;
	if (ResultatBleu < MIN_CONCENTRATION_COULEUR) {
		tauxBleu_ = MIN_CONCENTRATION_COULEUR;
	}
	else if (ResultatBleu > MAX_CONCENTRATION_COULEUR) {
		tauxBleu_ = MAX_CONCENTRATION_COULEUR;
	}
	else {
		tauxBleu_ = ResultatBleu;
	}
}
// cette fonction affiche les pixels sur l'ecran selon leur taux de couleur (taux de bleu,vert et rouge)
void Pixel::afficherPixel() const {
	if ((tauxBleu_ == 0) && (tauxRouge_ == 0) && (tauxVert_ > 0)) {
		cout << "G";
	}
	else if ((tauxBleu_ == 0) && (tauxRouge_ > 0) && (tauxVert_ == 0)) {
		cout << "R";
	}
	else if ((tauxBleu_ > 0) && (tauxRouge_ == 0) && (tauxVert_ == 0)) {
		cout << "B";
	}
	else {
		cout << "Q";
	}
}

