/**************************************************
 * Titre: Travail pratique #1 - Main.cpp
 * Date: 22 Septembre 2017
 * Auteurs: Georges Louis et Guillaume Tousignant.
**************************************************/

#include "Pixel.h"
#include "Image.h"
#include "GroupImage.h"


#include <string>
#include <iostream>

using namespace std;

int main()
{

	//1- Creez 9 pixels rouge  (255,0,0)	
	Pixel rouge(255, 0, 0);
	Pixel rouges[9];
	for (int i = 0; i < 9; i++) {
		rouges[i] = rouge;
	}


	//2-Creez 9 pixels verts (0,255,0)
	Pixel vert(0, 255, 0);
	Pixel verts[9];
	for (int i = 0; i < 9; i++) {
		verts[i] = vert;
	}



	//3- Creez une image de taille 3*3 
	Image imageRouge("Image Rouge", 3, 3);
	


	//4- Ajouter à l'image créée à l'étape 3 les pixels rouges
	int counter = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			imageRouge.ajouterPixel(rouges[counter], i, j);
			counter++;
		}
	}
	
	//5- Creez une deuxième image de taille 3*3 
	Image imageVerte("Image Verte", 3, 3);
	
	//6- Ajouter à l'image créées à l'étape 3 les pixels verts
	counter = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			imageVerte.ajouterPixel(verts[counter], i, j);
			counter++;
		}
	}
	//7- Creez un groupe d'image avec une capacite de 3
	GroupImage groupe("Couleurs", 3);
	
	//8- Ajoutez les deux images crées precédament au groupe
	groupe.ajouterImage(imageRouge);
	groupe.ajouterImage(imageVerte);
	

	//9- Augmentez la teinte bleu du Pixel (1,1) de l'image 0 de 50 unités
	groupe.obtenirImage(0).augmenterTeintePixel(1, 1, 50, 'B');



	//10- Diminuer la teinte rouge du Pixel (1, 1) de l'image 0 de 255 unités
	groupe.obtenirImage(0).augmenterTeintePixel(1, 1, -255, 'R');
	

	//11- Augmentez la teinte bleu du Pixel (2, 1) de l'image 1 de 100 unités  
	groupe.obtenirImage(1).augmenterTeintePixel(2, 1, 100, 'B');
	

	//12- Affichez les images de ce groupe
	groupe.afficherImages();
	

	//13- Doublez la taille de la premiere image du groupe en largeur
	groupe.doublerTailleImageEnLargeur(0);


	//14- Doublez la taille de la deuxieme image du groupe en hauteur
	groupe.doublerTailleImageEnHauteur(1);


	//15- Afficher cette image 
	groupe.obtenirImage(1).afficherImage();

	
	system("pause");
	return 0;
}

/* Question #1:
La relation entre GroupImage et Image est une relation d'agrégation parce que si on détruit 
l'un des deux le deusiéme continue a existé sans l'autre. L'attribut Image dans groupImage est un pointeur !
alors si on detruit groupImage l'addresse pointer par le pointeur Image sera detruit et non pas la classe Image.


Question #2:
La methode avec la mention const aura comme effet que la valeur qu'elle retourne ou qu'elle cherche ne peut plus etre modifie.
*/