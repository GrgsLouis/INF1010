//
// Created by Gabriel Bernard on 17-09-12.
//

#include "GroupeImage.h"
#include "Foncteur.h"
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

// Constructeur par défaut (rien à faire ici)
GroupeImage::GroupeImage() {};

// Constructeur par copie
GroupeImage::GroupeImage(const GroupeImage& groupe) : images_(groupe.images_) {}

// Destructeur 
GroupeImage::~GroupeImage() {
};

// Opérateur d'assignation
GroupeImage& GroupeImage::operator=(const GroupeImage &groupe) {
	images_.clear();
	/*for (auto it = images_.begin(); it != images_.end(); it++) {
		images_.push_back(*it);
	}*/
	images_.insert(images_.begin(), groupe.images_.begin(), groupe.images_.end()); 
	return *this;
}

// Ajouter une image au groupe, utilisation du fancy foncteur de mm nom
bool GroupeImage::ajouterImage(Image* image) {
	/*for (auto it= images_.begin(); it != images_.end() ; it++)
	{
		if (image->obtenirNomImage() == **it)
		{
			cout << image->obtenirNomImage() << " n'a pas ete ajoute" << std::endl;
			return false;
		}
	}*/
	FoncteurImagesDeMemeNom fonc(image->obtenirNomImage());
	auto it = find_if(images_.begin(),images_.end(), fonc);
	if (it != images_.end()) {
		cout << image->obtenirNomImage() << " n'a pas ete ajoute" << std::endl;
		return false;
	}

	images_.push_back(image);
	std::cout << image->obtenirNomImage() << " a bien ete ajoute" << std::endl;
	return true;
}

// Retirer une image si son nom est trouvé avec le foncteur
bool GroupeImage::retirerImage(const std::string& nom) {
	auto it = remove_if(images_.begin(), images_.end(), FoncteurImagesDeMemeNom(nom));
	if (it == images_.end()) {
		cout << nom << " n'a pas ete retire" << std::endl;
		return false;
	}
	else {
		//delete *it; // a revoir
		//*it = images_.back();	
		//images_.pop_back();
		//cout << nom << " a bien ete retire" << endl;
		//return true;
		remove_if(images_.begin(), images_.end(), FoncteurImagesDeMemeNom(nom));
		return true;
	}
}

// Fonction qui print les images
void GroupeImage::afficherImages(ostream& os) const {

	os << "**************************************************" << endl;
	os << "Affichage des images du groupe :  " << endl;
	os << "**************************************************" << endl << endl;
	copy(images_.begin(),images_.end(),ostream_iterator<Image*>(cout, "\n"));
	/*for (auto it = images_.begin(); it != images_.end(); it++) {
		os << *it << "--------------------------------------------------" << endl;
	}*/
	os << endl;
}

// Fonction qui retourne un pointeur vers une image d'un certain nom
Image* GroupeImage::obtenirImage(const std::string& nom) const { //a revoir
	/*auto it = images_.begin();
	for (unsigned int i = 1; i < indiceImage; i++) {
		it++;
	}
	return *it;*/
	FoncteurImagesDeMemeNom temp(nom);
	auto it= find_if(images_.begin(), images_.end(), temp);
	return *it;
	//if (it == images_.end()) {
	//	cout << nom << " n'a pas ete trouver, dernier image retouner" << std::endl;
	//	it--;						// a revoir
	//	return *it;
	//}
	//return *it;
}

// Moyenne des intensitées des images du groupe
double GroupeImage::obtenirIntensiteMoyenne() {
	double intensite = 0.0;
	for (auto it = images_.begin(); it != images_.end(); it++) {
		intensite += (*it)->obtenirIntensiteMoyenne();
	}
	return (intensite / images_.size());
}

// Moyenne des tailles des images du groupe
double GroupeImage::obtenirTailleMoyenne() {
	double taille = 0.0;
	for (auto it = images_.begin(); it != images_.end(); it++) {
		taille += (*it)->obtenirTaille();
	}
	return (taille / images_.size());
}

// Ajouter une image au groupe avec un opérateur au lieu d'une fonction (bcp plus cool)
GroupeImage& GroupeImage::operator+=(Image* image)
{
	ajouterImage(image);
	return *this;
}

// Même chose pour retirer une image
GroupeImage& GroupeImage::operator-=(Image* image)
{
	retirerImage(image->obtenirNomImage());
	return *this;
}

// Pour print les infos des images du groupe
std::ostream& operator<<(std::ostream& os, const GroupeImage& groupeImage)
{
	os << "**************************************************" << endl;
	os << "Affichage des images du groupe :  " << endl;
	os << "**************************************************" << endl << endl;
	
	/*for (auto it = groupeImage.images_.begin(); it != groupeImage.images_.end(); it++) {
		os << *it << "--------------------------------------------------" << endl;
	}
	os << endl;*/
	copy(groupeImage.images_.begin(),groupeImage.images_.end(),ostream_iterator<Image*>(cout, "\n"));
	return os;
}

// Nombre d'images dans le groupe
unsigned int GroupeImage::obtenirNombreImages() const {
	return images_.size();
}

// Enregistrer sur le disque
void GroupeImage::toutEnregistrer() {
	cout << endl;
	unsigned int i=0;
	for (auto it = images_.begin(); it != images_.end(); it++) {
		Image* image = *it;
		string nom = "./Ensemble d'images/" + image->obtenirTypeEnString()
			+ "/im" + to_string(i) + image->obtenirNomImage();
		cout << "Sauvegarde de " << nom << endl;
		(*it)->sauvegarderImage(nom); // a revoir
		i++;
	}
}

// Obtenir une image par son index.
Image* GroupeImage::obtenirImageParIndex(int index)
{
	auto it = images_.begin();
	advance(it, index);
	return  *it;
}