#include "Image.h"
#include "Pixel.h"
#include <iostream>
#include <string>
#include <iomanip>
// Un constructeur par défaut qui initialise les attributs aux valeurs par défaut.
Image::Image() {
	nomImage_ = "";
	nombrePixelEnHauteur_ = 0;
	nombrePixelEnLargeur_ = 0;
}
// Un constructeur par paramètres qui initialise les attributs aux valeurs correspondantes. Et puis on cré un tableau de taille correspondant aux parametres entrés
Image::Image(const string& nomImage, unsigned int nombrePixelHauteur, unsigned int nombrePixelLargeur) {
	nomImage_ = nomImage;
	nombrePixelEnHauteur_ = nombrePixelHauteur;
	nombrePixelEnLargeur_ = nombrePixelLargeur;
	pixels_ = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		pixels_[i] = new Pixel[nombrePixelEnLargeur_];
	}
}
// destructeur de l'image qui desalloue la memoire prise par pixels.
Image::~Image() {
	/*
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		delete pixels_[i];
		pixels_[i] = nullptr;
	}
	//delete[] pixels_;
	pixels_ = nullptr;
	*/
}
// cette fonction nous permet d'avoir le nombre du pixel en hauteur.
unsigned int Image::obtenirNombrePixelHauteur() const {
	return nombrePixelEnHauteur_;
}

// cette fonction nous permet d'avoir le nombre du pixel en largeur.
unsigned int Image::obtenirNombrePixelLargeur() const {
	return nombrePixelEnLargeur_;
}
// cette fonction nous permet d'avoir le nom de l'image.
string Image::obtenirNomImage() const {
	return nomImage_;
}
// cette fonction nous permet d'avoir le pixel qui se situe dans la position specifié dans les parametres.
Pixel Image::obtenirPixel(unsigned int positionHauteur, unsigned int positionLargeur) const {
	return pixels_[positionHauteur-1][positionLargeur-1];
}
// cette fonction nous permet de modifier le nom de l'image.
void Image::modifierNomImage(const string & nomImage) {
	nomImage_ = nomImage;
}

void Image::doublerTailleEnLargeur() {
	// ici on double la taille du tableau en largeur.
	Pixel** pixels2_ = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		pixels2_[i] = new Pixel[nombrePixelEnLargeur_*2];
	}
	// apres avoir doubler la taille du tableau en largeur on a perdu les anciens informations que l'ancien tableau contener, alors cette boucle nous permet de recuperer les anciens informations et de les placer de nouveau dans le nouveau tableau.
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		for (unsigned int j = 0; j < nombrePixelEnLargeur_; j++) {
			pixels2_[i][j] = pixels_[i][j];
		}
	}

	delete[] pixels_;
	pixels_ = pixels2_;
	nombrePixelEnLargeur_ *= 2;
	pixels2_ = nullptr;
}

void Image::doublerTailleEnHauteur() {
	// ici on double la taille du tableau en hauteur.
	Pixel** pixels2_ = new Pixel*[nombrePixelEnHauteur_*2];
	for (unsigned int i = 0; i < nombrePixelEnHauteur_*2; i++) {
		pixels2_[i] = new Pixel[nombrePixelEnLargeur_];
	}
	// apres avoir doubler la taille du tableau en hauteur on a perdu les anciens informations que l'ancien tableau contener, alors cette boucle nous permet de recuperer les anciens informations et de les placer de nouveau dans le nouveau tableau.
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		for (unsigned int j = 0; j < nombrePixelEnLargeur_; j++) {
			pixels2_[i][j] = pixels_[i][j];
		}
	}

	delete[] pixels_;
	pixels_ = pixels2_;
	pixels2_ = nullptr;
	nombrePixelEnHauteur_ *= 2;
}
// cette fonction nous permet d'ajouter un pixel à une position specifié dans les parametres, en tenant compte que cette position se trouve dans le tableau qu'on a créer.
bool Image::ajouterPixel(Pixel & pixel, unsigned int positionLargeur, unsigned int positionHauteur) {
	if ((positionHauteur > nombrePixelEnHauteur_) & (positionLargeur > nombrePixelEnLargeur_)) {
		return 0;
	}
	else{
		pixels_[positionHauteur][positionLargeur] = pixel;
		return 1;
	}
}
// cette fonction nous permet de modifier la teinte (rouge ou vert ou bleu selon le char couleur) d'un pixel (qui se situe à la position indique dans les parametres) par la valeur indique en parametre ( increment).
void Image::augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur) {

	switch (couleur) {
	case 'R':
		pixels_[positionHauteur][positionLargeur].modifierTeinteRouge(increment);
		break;

	case 'G':
		pixels_[positionHauteur][positionLargeur].modifierTeinteVert(increment);
		break;

	case 'B':
		pixels_[positionHauteur][positionLargeur].modifierTeinteBleu(increment);
		break;
	}

}
// cette fonction nous permet d'afficher l'image suivit par les pixels correspondants.
void Image::afficherImage() const{
	cout << "Affichage de l'image: " << nomImage_ << endl;
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		cout << setfill(' ') << setw(5);
		for (unsigned int j = 0; j < nombrePixelEnLargeur_; j++) {
			pixels_[i][j].afficherPixel();
		}
		cout << endl;
	}
}