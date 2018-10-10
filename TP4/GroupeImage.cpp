//
// Created by Gabriel Bernard
//

#include <iostream>
#include "GroupeImage.h"


using namespace std;
// Constructeur par défaut
GroupeImage::GroupeImage() {};

// constructeur par copie
GroupeImage::GroupeImage(const GroupeImage& grpImage) {

	for (unsigned int i = 0; i < images_.size(); i++) {
		//Image* temp = new Image(*grpImage.images_[i]);
		images_.push_back(new Image(*grpImage.images_[i]));
	}
}

// Opérateur d'assignation
GroupeImage& GroupeImage::operator=(const GroupeImage& groupeimage) {
	if (this != &groupeimage) {
		images_ = groupeimage.images_;
	}
	return *this;
}

// Inverser images
void GroupeImage::toutMettreEnNegatif() {
	for (int i = 0; i < images_.size(); i++) {	//8alat
		images_[i]->toutMettreEnNegatif();
		}
}

// rien à faire ici
GroupeImage::~GroupeImage() {};

// Ajouter image au groupe
bool GroupeImage::ajouterImage(Image* image) {
    for (unsigned int i = 0; i <  images_.size(); i++)
    {
        if (image->obtenirNomImage() == *(images_[i]))
        {
            cout << image->obtenirNomImage() << " n'a pas ete ajoute" << std::endl;
            return false;
        }
    }
    images_.push_back(image);
    std::cout << image->obtenirNomImage() << " a bien ete ajoute" << std::endl;
    return true;
}

// Enlever image du groupe selon son nom
bool GroupeImage::retirerImage(const std::string& nom) {
    for (unsigned int i = 0; i < images_.size(); i++)
    {
        if (*(images_[i]) == nom)
        {
            images_[i] = images_.back();
            images_.pop_back();
            cout << nom << " a bien ete retire" << endl;
            return true;
        }
    }
    return false;
}

// Afficher les infos des images
void GroupeImage::afficherImages(ostream& os ) const {

    os << endl;
    os << "**************************************************" << endl;
    os << "Affichage des images du groupe :  " << endl;
    os << "**************************************************" << endl << endl;

    for  (unsigned int j= 0; j < images_.size(); j++) {
        os << *images_[j] << "--------------------------------------------------" << endl;
    }
    os << endl;
}

// Retourner une image selon son indice
Image* GroupeImage::obtenirImage(unsigned int indiceImage) const {
    return images_[indiceImage];
}

// Ajouter image avec un opérateur plus cool, possible en cascade
GroupeImage& GroupeImage::operator+=(Image* image)
{
    ajouterImage(image);
    return *this;
}

// Retier image selon son nom, utilisable en cascade
GroupeImage& GroupeImage::operator-=(Image* image)
{
    retirerImage(image->obtenirNomImage());
    return *this;
}

// Pour pouvoir afficher les images
std::ostream& operator<<(std::ostream& os, const GroupeImage& groupeImage)
{
    os << endl;
    os << "**************************************************" << endl;
    os << "Affichage des images du groupe :  " << endl;
    os << "**************************************************" << endl << endl;

    for  (unsigned int j= 0; j < groupeImage.images_.size(); j++) {
        os << *groupeImage.images_[j] << "--------------------------------------------------" << endl;
    }
    os << endl;

    return os;
}

// Pour accéder à une image
Image* GroupeImage::operator[](const unsigned int& indice) const {
    if(indice >= images_.size()) {
        cerr << "L'indice est plus grand que la quantite d'image present dans ce groupe." << endl;
        return nullptr;
    }
    return images_[indice];
}

// Obtenir le nombre d'images
unsigned int GroupeImage::obtenirNombreImages() const {
    return images_.size();
}

// Convertir images en noir et blanc
void GroupeImage::toutMettreEnNB(){
    unsigned int i;
    for(i = 0; i < images_.size(); i++) {
        images_[i]->convertirNB();
    }
    cout << endl;
}

// Convertir en gris
void GroupeImage::toutMettreEnGris() {
    unsigned int i;
    for(i = 0; i < images_.size(); i++) {
        images_[i]->convertirGris();
    }
    cout << endl;
}

// Convertir en couleur
void GroupeImage::toutMettreEnCouleur() {
   
    for(unsigned int i = 0; i < images_.size(); i++) {
        images_[i]->convertirCouleurs();
    }
    cout << endl;
}

// Enregistrer images
void GroupeImage::toutEnregistrer() {
    
    for(unsigned int i = 0; i < images_.size(); i++) {
        Image* image = images_[i];
        string nom = "../TP4/Ensemble d'images/" + image->obtenirTypeEnString()
                     + "/im" + to_string(i) + image->obtenirNomImage();
        cout << "Sauvegarde de " << nom << endl;
        images_[i]->sauvegarderImage(nom);
    }
    cout << endl;
}