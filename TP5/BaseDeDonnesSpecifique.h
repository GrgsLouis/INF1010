#ifndef BASE_DE_DONNES_SPECIFIQUE
#define BASE_DE_DONNES_SPECIFIQUE

#include "BaseDeDonnesGenerique.h"
#include "GroupeImage.h"
#include "Image.h"

class BaseDeDonnesSpecifique: public BaseDeDonnesGenerique<Image,GroupeImage>
{
public:
	// Ajouter une image à un groupe
	bool AssocierImage(GroupeImage* groupe, Image* image) {
		bool add = groupe->ajouterImage( image); 
		if (add) {
			ajouter(image);
		}
		
		return add;

	}

	// Retirer une image d'un groupe
	bool EnleverImage(GroupeImage* groupe, const std::string& nomImage) {
		return groupe->retirerImage(nomImage);
		// Retirer image de la base de donnés? non, car elle pourrait être dans un autre groupe
		//supprimerImage(FoncteurImagesDeMemeNom(nomImage));
	}

	// Print les informations des groupes et des images 
	friend std::ostream& operator<<(std::ostream& os, const BaseDeDonnesSpecifique& dataBase) {
		os << "Nombre de groupes " << dataBase.listGroupeImage_.size() << endl;
		os << "Nombre d'images " << dataBase.listImage_.size() << endl;
		for (auto it = dataBase.listImage_.begin(); it != dataBase.listImage_.end(); it++)
		{
			os << "Nom de l'image " << (*it)->obtenirNomImage() << endl; // pas certain
		}
		/*
		iza ma tele3 aseme l images 3mol list jdide w 7et fiya obtenirlisteImage
		w ktob talama l begin != l end ya3mol l begin++ l begin houwe auto (it = list jdide.begin())
		*/

		// ^?
		return os;
	}
};
#endif
