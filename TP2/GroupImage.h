#ifndef GROUPIMAGE_H
#define GROUPIMAGE_H
#include "Image.h"
#include <vector>

using namespace std;


class GroupImage
{
public:
	GroupImage(); // A modifier l'implementation         FAIT!!!
	~GroupImage(); // A modifier l'implementation		 FAIT!!!

	void modifierType(const string &type);
	string obtenirType() const;

	// Modifier cette méthode par Image* obtenirImage(unsigned int indiceImage) const;       FAIT!!!!
	Image* obtenirImage(unsigned int indiceImage) const;


	// Méthode à modifier avec void ajouterImage(Image* &image)       FAIT!!!!
	void ajouterImage(Image* image);

	//  ajouter la methode pour retirer une image en donnant		  FAIT!!!!	
	//son nom en paramètre
	void retirerImage(const string& nom);

	// Méthode à modifier avec void afficherImages(ostream& os)
	//void afficherImages(ostream& os);
	

	void doublerTailleImageEnLargeur(unsigned int indiceImage);

	void doublerTailleImageEnHauteur(unsigned int indiceImage);
	
     
    // Ajouter les opérateurs 
	GroupImage& operator+=(Image& image);
	GroupImage& operator-=(const Image& image);
	friend ostream& operator<<(ostream& o, const GroupImage images);


private:

	string type_;

	// Attributs à mdifier 
	vector< Image* > images_;

};

#endif