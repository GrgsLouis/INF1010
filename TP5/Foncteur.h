#ifndef  FONCTEUR
#define  FONCTEUR

#include "GroupeImage.h"
#include <stdlib.h>
#include <time.h>
#include "image.h"
#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 3

// Foncteur de comparison d'images
class FoncteurEgalImages
{
public:
	FoncteurEgalImages(Image* image) {
		image_ = image;
	}
	~FoncteurEgalImages() {}

	bool FoncteurEgalImages::operator() (Image* imageAComparer) const {
		return ((*image_) == (*imageAComparer));
	}

private:
	Image* image_;
};

// Foncteur de comparaison de nom
class FoncteurImagesDeMemeNom
{
public:
	FoncteurImagesDeMemeNom(const std::string& nom): nom_(nom) {
	
	}
	~FoncteurImagesDeMemeNom() {};

	bool operator() ( Image* image) const {
		return ((*image) == nom_); //*image == nom_
	}

private:
	std::string nom_;
};

// Foncteur qui retourne la taille d'une image
class FoncteurObtenirTailleImage
{
public:
	FoncteurObtenirTailleImage() {}
	~FoncteurObtenirTailleImage() {}

	unsigned int operator() (const Image* image) const {
		return image->obtenirTaille();
	}
};

// Foncteur de conversion en gris
class FoncteurMettreEnGris
{
public:
	FoncteurMettreEnGris() {}
	~FoncteurMettreEnGris() {}

	void operator() (Image* image) {
		image->convertirGris();
	}
};

// Foncteur de conversion en couleur
class FoncteurMettreEnCouleur
{
public:
	FoncteurMettreEnCouleur() {}
	~FoncteurMettreEnCouleur() {}

	void operator() (Image* image) {
		image->convertirCouleur();
	}
};

// Foncteur de conversion en blanc et noir
class FoncteurMettreEnBN
{
public:
	FoncteurMettreEnBN() {}
	~FoncteurMettreEnBN() {}

	void operator() (Image* image) {
		image->convertirBN();
	}
};

// Foncteur d'inversion d'image
class FoncteurMettreEnNegatif
{
public:
	FoncteurMettreEnNegatif() {}
	~FoncteurMettreEnNegatif() {}

	void operator() (Image* image) {
		image->mettreEnNegatif();
	}
};

// Foncteur qui donne des nombre aléatoires
class FoncteurGenerateurNombresAlea
{
public:
	FoncteurGenerateurNombresAlea() {
		
		min_ = 0;
		max_ = 9;
		
	}
	// a revoir
	FoncteurGenerateurNombresAlea(unsigned int min, unsigned int max) {
		
		min_ = min;
		max_ = max;
		
	}

	~FoncteurGenerateurNombresAlea() {}

	unsigned int operator() () const { // quoi faire?
		srand((unsigned int)time(NULL));
		return ((rand() % (max_ - min_)) + min_);
	}

private:
	unsigned int min_;
	unsigned int max_;
};


#endif;