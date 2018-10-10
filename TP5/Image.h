//
// Created by Gabriel Bernard on 17-09-08.
//

#ifndef TP3_IMAGE_H
#define TP3_IMAGE_H

#ifndef PAUSE
    #ifdef _WIN32
        #include <Windows.h>
        #define PAUSE system("PAUSE")
    #else
        #include <unistd.h>
        #define PAUSE sleep(0)
    #endif
#endif /* PAUSE */

typedef unsigned char unchar;

#define VALEUR_MAX_PIXEL 255
#define VALEUR_MIN_PIXEL 0

#include <string>
#include <fstream>
#include <iostream>
#include "Pixel.h"

enum TypeImage {
    NB, Gris, Couleurs
};

class Image {
public:
    // Constructeur par defaut
    Image();
    // Constructeur par copie
    Image(const Image& i);
    // Constructeur par parametre
    Image(const std::string& cheminDuFichier, const TypeImage& type = TypeImage::Couleurs);
    // Destructeur
    ~Image();

    // Accesseurs
    std::string obtenirCheminDuFichier() const;
    std::string obtenirNomImage() const;
    unsigned int obtenirNombrePixelHauteur() const;
    unsigned int obtenirNombrePixelLargeur() const;
    unsigned int obtenirTaille() const;
    std::string obtenirTypeEnString() const;

    // Sauvegarde et lecture d'image sur disque
    void sauvegarderImage(const std::string &nomDuFichier) const;
    void lireImage();

    // overload d'operateurs
    Image& operator=(const Image& image);
    bool operator==(const Image& image);
    bool operator==(const std::string& nom);
    friend bool operator==(const std::string& nom,  Image& image);

    // Operateur de flux de sortit
    friend std::ostream& operator<<(std::ostream& os, const Image& image);

	// Fonction de conversion
    void convertirBN();
	void convertirGris();
	void convertirCouleur();

	void mettreEnNegatif();

	// TP5
	bool estMajoriteRouge() const;
	bool estMajoriteVert() const;
	bool estMajoriteBleu() const;
	double obtenirIntensiteMoyenne() const;

private:
    void lirePixelsCouleur(std::ifstream &bmpIn);
    void lirePixelsGris(std::ifstream &bmpIn);
    void lirePixelsBN(std::ifstream &bmpIn);

    std::string cheminVersImageOriginale_;  // Chemin de lecture du fichier original
    std::string nomDuFichier_;     // Nom du fichier
    Pixel** pixels_;               // Tableau des pixels associes a l'image
    unsigned int hauteur_;         // Hauteur de l'image en pixel
    unsigned int largeur_;         // Largeur de l'image en pixel
    unsigned int taille_;          // Taile de l'image (hauteur_ * largeur_)
    TypeImage typeImage_;
};

size_t bitmap_encode_rgb(const unchar *rgb, unsigned int width, unsigned int height, unsigned char** output);

#endif //TP3_IMAGE_H
