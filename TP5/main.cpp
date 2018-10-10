
#ifndef PAUSE
    #ifdef _WIN32
        #include <Windows.h>
        #define PAUSE system("PAUSE")
    #else
        #include <unistd.h>
        #define PAUSE sleep(0)
    #endif
#endif /* PAUSE */

#include <iostream>
#include <string>

#include "GroupeImage.h"
#include <queue>
#include "BaseDeDonnesSpecifique.h"
#include "Foncteur.h"
#include <functional>
#include "Image.h"

using namespace  std;
using namespace std::placeholders;

/*
TODO : Veuillez répondre aux question ici
1)  La suppression et l'ajout d'un élément dans une liste à tout point a un temps d'exécution constant,
	contrairement aux vecteurs, où il est très coûteux d'ajouter ou retirer un élément au milieu, ou pire,
	au début. Si on veut accéder à des éléments de façon aléatoire, le vecteur est un meilleur choix car
	il n'a pas besoin de parcourir ses éléments jusqu'au point donné, comme une liste, pour y accéder.
2)	L'implémentation des classes génériques doivent être dans le .h car le compilateur doit savoir 
	quelles méthodes les objets génériques doivent supporter (donc les méthodes appelées par la classe) 
	pour être utilisées dans cette classe.
*/

int main() {
	
	// Chemin vers les images
	string cheminLoad = "./Ensemble d'images/Originale/";
    // Nom des 6 images dans un tableau de string
	string image[9] = {"Breaking-Bad.bmp", "Couleur.bmp", "Fall.bmp", "RM.bmp", "SolarEclipse.bmp", "Monkey.bmp","WiC.bmp","Sloth.bmp","Green.bmp"};

    // Creer un conteneur de type QUEUE et ajouter les images dans la queue
	cout << "**************************************************" << endl;
	cout << "Creation de la file de travail" << std::endl;
	cout << "**************************************************" << endl << endl;
	Image* images[9];

	queue <Image*> QUEUE;
	for (int i = 0; i < 9; i++) {
		images[i] = new Image(cheminLoad + image[i], TypeImage::Couleurs);
		QUEUE.push(images[i]);
	}
	//Creez 3 GroupeImage
	GroupeImage* groupe1= new GroupeImage;
	GroupeImage* groupe2= new GroupeImage;	//pointeur?
	GroupeImage* groupe3= new GroupeImage;

	// Creez un objet de type BaseDeDonnesSpecifique et ajoutez les 3 groupes a la base de donnes
	BaseDeDonnesSpecifique BaseDeDonne;
	BaseDeDonne.ajouter(groupe1);
	BaseDeDonne.ajouter(groupe2);
	BaseDeDonne.ajouter(groupe3);

	/*Faites repartir les elements de la queue de maniere uniforme et sequentielle dans les groupe
	 Vous devez avoir la composition suivante :
		groupe 1 a les images 0,3,6
		groupe 2 a les images 1,4,7
		groupe 3 a les images 2,5,8
	 ATTENTION : la repartition doit se faire dans une seule boucle ET vous devez utiliser les fonctions de l'objet de base de donnes
	 NB: La methode pop() de queue<> ne retourne pas l'element de la structure
	*/
	
	cout << "**************************************************" << endl;
	cout << "CHARGEMENT DES IMAGES\n\n";
	// TODO : Votre implementation ici

	// Mettre 3 normalement, 9 avec la loop pas legit
	for (int i = 0; i < 3; i++) {
		BaseDeDonne.AssocierImage(groupe1, QUEUE.front());
		QUEUE.pop();
		BaseDeDonne.AssocierImage(groupe2, QUEUE.front());
		QUEUE.pop();
		BaseDeDonne.AssocierImage(groupe3, QUEUE.front());
		QUEUE.pop();

		/*if (i == 0 || i == 3 || i == 6) {
			BaseDeDonne.AssocierImage(groupe1, images[i]);
		}
		else if (i == 1 || i == 4 || i == 7) {
			BaseDeDonne.AssocierImage(groupe2, images[i]);
		}
		else  { 
		//(i == 2 || i == 5 || i == 8)		
		BaseDeDonne.AssocierImage(groupe3, images[i]);
		}*/
	}

	cout << "**************************************************" << endl << endl;
	cout <<"AFFICHAGE DE LA BASE DE DONNESES\n";
	// TODO : Afficher la base de donnes au complet
	
	cout << BaseDeDonne;	// il y a une autre methode dans l'operator << 

	// Pour chaque groupe, generez un nombre aleatoire. Le nombre aleatoire doit toujours donner un index valide
	// ET appliquez les modifications suivantes aux images obtenues avec le nombre aleatoire
	
	FoncteurGenerateurNombresAlea NbAlea(0,3);
	FoncteurMettreEnNegatif MetNeg;
	//GROUPE 1 - Mettre en negatif
	unsigned int x = NbAlea();
	
	MetNeg(groupe1->obtenirImageParIndex(x));
	//groupe1->appliquerFoncteurUnaire(FoncteurMettreEnNegatif(groupe1->obtenirImageParIndex(x)));
	
	//GROUPE 2 - Mettre en gris
	unsigned int y = NbAlea();
	MetNeg((groupe2->obtenirImageParIndex(y)));

	//GROUPE 3 - Mettre en noir et blanc
	unsigned int z = NbAlea();
	MetNeg((groupe3->obtenirImageParIndex(z)));



	/*
	 *TRAITEMENT DE GROUPE 1
	 *Calculer l'intensite moyenne des images du groupe 1 et l'afficher
	 */

	cout << "**************************************************" << endl;
	cout << "CALCUL DE LA MOYENNE \n\n";
	// TODO : Votre implementation ici

	cout << "MOYENNES DES IMAGES DANS LA BASE DE DONNES: \n";
	
	double IntensiteMoyen = groupe1->obtenirIntensiteMoyenne();
	cout << IntensiteMoyen << endl;
	// Trouver toutes les images avec une intensite moyenne plus petite que la valeur trouve et
	// afficher leur nom et leur moyenne
	// ATTENTION : Faire ceci avec une boucle for intelligente de type 
	//																for (Type variable : conteneur)

	for (Image* i:BaseDeDonne.obtenirListImages()) {
		if (i->obtenirIntensiteMoyenne() < IntensiteMoyen) {
			cout << i->obtenirNomImage() << " " << i->obtenirIntensiteMoyenne() << endl;
		}
	}

	cout << "**************************************************" << endl << endl;



	cout << "**************************************************" << endl;
	cout << "CALCUL DE LA TAILLE \n\n";
	// TODO : Votre implementation ici

	/*
	 *TRAITEMENT DE GROUPE 2
	 * Calculer la taille moyenne des images dans le groupe 2 et afficher l'afficher
	 */
	double TailMoy = groupe2->obtenirTailleMoyenne();
	cout << TailMoy << endl;

	// Afficher le nombre d'images dans la base de donnes
	//cout << "Nombre d'images totales dans la base de donnes " << dataBase.obtenirListImages().size() << endl;

	cout << "Nombre d'images totales dans la base de donnes " << BaseDeDonne.obtenirListImages().size() << endl;

	// Trouver at afficher le nombre d'images qui ont une taille plus grande que la moyenne calculee
	// Utiliser les fonctions std::bind et std::placeholders pour effectuer le travail
	
	FoncteurObtenirTailleImage A;

	list<Image*>list = BaseDeDonne.obtenirListImages();
	int nb =count_if(list.begin(),list.end(),bind(greater<double>(), bind(A,_1) , TailMoy));

	// Decommenter et Remplacer les variables X,Y, Z par les bons elements 
	/*
	 MonFoncteur foncteurTaille;
	 groupeImage2->supprimerElements(
		std::bind(
			X, //A COMPLETER générer un opérateur > pour les entiers
			//Le bind ci-dessous permet d'appeler la méthode obtenirTaile de la
			//Image* passée en argument du foncteur lors des appels de ce dernier dans supprimerElements
			std::bind(
				foncteurTaille,
				Y //A COMPLETER utiliser le premier placeholder (attention aux namespace) (reçoit une Image*)
				),
			Z //A COMPLETER comparer à taille Moyenne
			)
		);
	 */

	// Calculer le nombre d'images avec une taille superieure a la taille moyenne
	// ASTUCE: utilisez la STL et les fonctions de decompte conditionel

	// Afficher le nombre d'images dans la base de donnes avec une taille plus grande que la moyenne
	cout << "Nombre d'images dont la taille est plus grande que la moyenne " << nb << endl;
	
	cout << "**************************************************" << endl << endl;


	/*
	 *TRAITEMENT DU GROUPE 3
	 *
	 *Mettre tout les images du groupe 3 en noir et blanc et sauvegarder
	 *ATTENTION : Vous devez utiliser la fonction generique "appliquerFoncteurUnaire"  demandee dans au TP5 et non une boucle sur les elements
	 */

	cout << "**************************************************" << endl;
	cout << "CONVERSION EN NOIR ET BLANC \n";
	// TODO : Votre implementation ici
	
	groupe3->appliquerFoncteurUnaire(FoncteurMettreEnBN());
	/*groupe1->toutEnregistrer();
	groupe2->toutEnregistrer(); pas demander*/
	groupe3->toutEnregistrer();
	cout << "**************************************************" << endl << endl;


    // Permet d'afficher le contenu de la console
    PAUSE;

    // Fin du programme
    return 0;
}