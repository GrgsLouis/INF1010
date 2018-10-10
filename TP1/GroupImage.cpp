#include "GroupImage.h"
#include <iostream>
#include <string>
#include <iomanip>

// Un constructeur par défaut qui initialise les attributs aux valeurs par défaut.
GroupImage::GroupImage() {
	type_ = "";
	capaciteImages_ = 0;
	nombreImages_ = 0;
}
// Un constructeur par paramètres qui initialise les attributs aux valeurs correspondantes.
GroupImage::GroupImage(const string &type, unsigned int capaciteImages) {
	type_ = type;
	capaciteImages_ = capaciteImages;
	images_ = new Image[capaciteImages_];
	nombreImages_ = 0;
}

// destructeur de l'image qui desalloue la memoire prise par images_.
GroupImage::~GroupImage(){
	delete [] images_;
	images_ = nullptr;
}
// cette fonction modifie le type de string par celui qui est mis dans le parametre.
void GroupImage::modifierType(const string &type) {
	type_ = type;
}
// cette fonction nous permet d'avoir le type_.
string GroupImage::obtenirType() const {
	return type_;
}
// cette fonction nous permet d'avoir l'image qui se trouve à (indiceImage).
Image GroupImage::obtenirImage(unsigned int indiceImage) const {
	return images_[indiceImage];
}
// cette fonction nous permet d'avoir le nombre d'images.
unsigned int GroupImage::obtenirNombreImages() const {
	return nombreImages_;
}
// cette fonction nous permet d'ajouter une image à la fin du groupe images.
void GroupImage::ajouterImage(const Image &image) {
	images_[nombreImages_] = image;
	nombreImages_++;
}
// cette fonction nous permet d'afficher toutes les images suivit par les pixels correspondants.
void GroupImage::afficherImages() const {
	for (unsigned int i = 0; i < nombreImages_; i++) {
		images_[i].afficherImage();
		cout << setfill('-') << setw(40) << "\n";
	}
	cout << endl;
}
// cette fonction nous permet de doubler la taille de l'image en largeur.
void GroupImage::doublerTailleImageEnLargeur(unsigned int indiceImage) {
	images_[indiceImage].doublerTailleEnLargeur();
}
// cette fonction nous permet de doubler la taille de l'image en hauteur.
void GroupImage::doublerTailleImageEnHauteur(unsigned int indiceImage) {
	images_[indiceImage].doublerTailleEnHauteur();
}
	
	