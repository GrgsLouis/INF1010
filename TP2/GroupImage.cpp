
#include "GroupImage.h"
#include <iostream>

using namespace std;

GroupImage::GroupImage(): type_("")
{}

GroupImage::~GroupImage() {
	/*
	for (unsigned i = 0; i < images_.capacity(); i++)
	{
		if (images_[i] != nullptr)
		{
			delete images_[i];
			images_[i] = nullptr;
		}
	}
	*/
}

void GroupImage::modifierType(const string & type) {
	type_ = type;
}

string GroupImage::obtenirType() const{
	return type_;
}



void GroupImage::ajouterImage(Image* image) {
	bool estPareil = false;
	for (unsigned i = 0; i < images_.capacity() && !estPareil; i++)
		estPareil = (*(images_[i]) == image->obtenirNomImage());
	if (!estPareil)
	{
		images_.push_back(image);
		cout << "L'image a ete bien ajoutee" << endl;
	}
	else
		cout << "Une image du même nom existe déjà!" << endl;
}

ostream& operator<<(ostream& o, const GroupImage images) {

	o << "*********************************************" << endl;
	o << "Affichage des images du groupe :  ";
	o << images.obtenirType().c_str() << endl;
	o << "*********************************************"<< endl;
	
	for (unsigned int i = 0; i < images.images_.size(); i++) {

		o << *images.images_[i];
		o << "---------------------------------------------" << endl;

	}
	o << endl;
	return o;
}

Image* GroupImage::obtenirImage(unsigned int indiceImage) const {
	return images_[indiceImage];
}

void GroupImage::doublerTailleImageEnLargeur(unsigned int indiceImage) {
	images_[indiceImage]->doublerTailleEnLargeur();
}

void GroupImage::doublerTailleImageEnHauteur(unsigned int indiceImage) {
	images_[indiceImage]->doublerTailleEnHauteur();
}
 
void GroupImage::retirerImage(const string& nom)
{
	bool estTrouve = false;
	for (unsigned i = 0; i < images_.capacity() && !estTrouve; i++)
	{
		estTrouve = (*(images_[i]) == nom);
		if (estTrouve)
		{
			images_.erase(images_.begin() + i); //Fonction qui supprime la case i en partant du début 
			cout << "L'image a bien ete retiree" << endl;	//et décale automatiquement les éléments
		}
	}
	if (!estTrouve)
		cout << "L'image n'existe pas!" << endl;
}

GroupImage& GroupImage::operator+=(Image& image)
{
	ajouterImage(&image);	//on ajoute l'image au groupe d'images avec l'adresse de l'image en paramètre.
	return *this;			//on retourne la référence sur le même groupe image.
}

GroupImage& GroupImage::operator-=(const Image& image)
{
	retirerImage(image.obtenirNomImage());	//on retire l'image du groupe d'images en utilisant le nom de l'image.
	return *this;
}