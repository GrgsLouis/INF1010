// Fait par Georges Louis: 1880098
// et	par	Guillaume Tousignant: 1743805
// Nom du fichier: main.cpp
// Contenu : execution du programme principal
// Date de modification : 27 septembre 2017
//

// Si plateforme windows
#ifdef _WIN32 
    #include <Windows.h>
    #define PAUSE system("PAUSE")
// S'il s'agit d'une plateforme UNIX
#else
    #include <unistd.h>
    #define PAUSE sleep(0)
#endif

#include <iostream>
#include <string>
#include "GroupeImage.h"

using namespace std;

int main() {
	// Chemin vers les images
    string cheminLoad = "./Ensemble d'images/Originale/";
	// Nom des 6 images dans un tableau de string
    string image[6] = {"Breaking-Bad.bmp", "Couleur.bmp", "Fall.bmp", "RM.bmp", "SolarEclipse.bmp", "WiC.bmp"};

	// Creer un groupe d'image
	cout << "**************************************************" << endl;
	cout << "Creation du groupe d'image" << endl;
	cout << "**************************************************" << endl << endl;
	
	/* Image** ImagesCouleurs;
	for (int i=0; i < 6; i++) {
		nomDuDossier = cheminLoad + image[i];
		ImagesCouleurs[i] = new Image(nomDuDossier, Couleurs);
		groupeDimages.ajouterImage(ImagesCouleurs[i]);
	} */

	/* Image ImagesCouleurs[6];							
	for (int i=0; i < 6; i++) {
		nomDuDossier = cheminLoad + image[i];
		ImagesCouleurs[i] =  Image(nomDuDossier, Couleurs);
		groupeDimages.ajouterImage(&ImagesCouleurs[i]);
	} */

	// Ajouter toutes les images au groupe en tant qu'image couleurs
	string nomDuDossier;	// chemin du fichier
	Image imageSSS[6];
	for (int i = 0; i < 6; i++) {
		imageSSS[i] = Image(cheminLoad + image[i],TypeImage::Couleurs);  //Image(cheminLoad + image[i], imageSSS[i].obtenirType());
	}
	
	GroupeImage groupeDimages;
	for (int i=0; i < 6; i++) {
		groupeDimages += &imageSSS[i];
	}

	
	
		


	// Afficher le contenu du groupe d'image
	cout << groupeDimages;

	// Convertir toutes les images en couleurs
	groupeDimages.toutMettreEnCouleur();
	// Enregistrer toutes les images convertie
	groupeDimages.toutEnregistrer();
	// Convertir toutes les images en Nuance de Gris
	groupeDimages.toutMettreEnGris();
	// Enregistrer toutes les images grises
	groupeDimages.toutEnregistrer();
	// Convertir toutes les images en Noir et Blanc
	groupeDimages.toutMettreEnNb();
	// Enretisgrer toutes les images
	groupeDimages.toutEnregistrer();

	// Permet d'afficher le contenu de la console
    PAUSE;

	// Fin du programme
    return 0;
}