/**************************************************
 * Titre: Travail pratique #1 - Main.cpp
 * Date: Septembre 2017
 * Auteur: 
**************************************************/

#include "Pixel.h"
#include "Image.h"
#include "GroupImage.h"


#include <string>
#include <iostream>

using namespace std;

/*
TODO : Veuillez répondre aux question ici
1)
2)
3)
*/

int main()
{


	//1- Creez 9 pixels rouge  (255,0,0)
	Pixel pixelsRouges[9];
	for (int i = 0; i < 9; i++)
	{
		pixelsRouges[i] = Pixel(255, 0, 0);
	}

	//2-Creez 9 pixels verts (0,255,0)
	Pixel pixelsVerts[9];
	for (int i = 0; i < 9; i++)
	{
		pixelsVerts[i] = Pixel(0, 255, 0);
	}

	//3- Creez une image de taille 3*3 
	Image image1("Image Rouge", 3, 3);

	//4- Ajouter à l'image créées à l'étape 3 les pixels rouges
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			image1.ajouterPixel(pixelsRouges[i + j], j, i);
		}
	}

	//5- Creez une deuxième image de taille 3*3 
	Image image2("Image Verte", 3, 3);

	//6- Ajouter à l'image créées à l'étape 3 les pixels verts
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			image2.ajouterPixel(pixelsVerts[i + j], j, i);
		}
	}

	//7- Creez un groupe d'image avec une capacite de 3
	GroupImage groupe;

	//8- Ajoutez les deux images crées precédament au groupe
	groupe.ajouterImage(&image1);
	groupe.ajouterImage(&image2);

	//9- Augmentez la teinte bleu du Pixel (1,1) de l'image 0 de 50 unités
	image1.augmenterTeintePixel(1, 1, 50, 'B');

	//10- Diminuer la teinte rouge du Pixel (1, 1) de l'image 0 de 255 unités
	image1.augmenterTeintePixel(1, 1, -255, 'R');

	//11- Augmentez la teinte bleu du Pixel (2, 1) de l'image 1 de 100 unités  
	image2.augmenterTeintePixel(2, 1, 100, 'B');

	//12- Afficher le groupe d'image
	cout << groupe;
	
	//13- Supprimer la premiere image du groupe d'image
	groupe -= image1;

	//14- Afficher le groupe d'image
	cout << groupe;
	
	return 0;
	
}