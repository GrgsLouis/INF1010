//
// Created by Gabriel Bernard
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

#include <string>
#include <fstream>

typedef unsigned char unchar;

#define VALEUR_MAX_PIXEL 255
#define VALEUR_MIN_PIXEL 0

#include "TypeImage.h"
#include "Pixel.h"

class Image {
public:
    // Constructeur par defaut
    Image();
    // Constructeur par copie
    Image(const Image& i);
    // Constructeur par parametre
    Image(const std::string& cheminDuFichier, const TypeImage& type);

    // Destructeur
    ~Image();

    // Accesseurs
    std::string obtenirCheminDuFichier() const;
    std::string obtenirNomImage() const;
    unsigned int obtenirNombrePixelHauteur() const;
    unsigned int obtenirNombrePixelLargeur() const;
    unsigned int obtenirTaille() const;
    TypeImage obtenirType() const;
    std::string obtenirTypeEnString() const;

    // Mutateurs
    void changerNomImage(const std::string& nom);

    // Sauvegarde et lecture d'image sur disque
    void sauvegarderImage(const std::string &nomDuFichier = "./out.ppm") const;
    void lireImage(const std::string &nomDuFichier, const TypeImage& type);

    // overload d'operateurs
    Image& operator=(const Image& image);
    bool operator==(const Image& image);
    bool operator==(const std::string& nom);
    friend bool operator==(const std::string& nom,  Image& image);

    // fonction d'impression
    friend std::ostream& operator<<(std::ostream& os, const Image& image);

    // Fonction de conversion
    void convertirNB();
    void convertirGris();
    void convertirCouleurs();

	// methodes ajoutees
	void toutMettreEnNegatif();

private:
    void lirePixelsCouleur(std::ifstream &bmpIn);
    void lirePixelsGris(std::ifstream &bmpIn);
    void lirePixelsBN(std::ifstream &bmpIn);
    // Fonction privee qui permet de faire une copie profonde d'une image
    // passee en reference dans l'objet image actuel
    void copieProfonde(const Image& image);

    std::string cheminVersImageOriginale_;  // Chemin de lecture du fichier original
    std::string nomDuFichier_;     // Nom du fichier
    Pixel** pixels_;               // Tableau des pixels associes a l'image
    unsigned int hauteur_;         // Hauteur de l'image en pixel
    unsigned int largeur_;         // Largeur de l'image en pixel
    unsigned int taille_;          // Taile de l'image (hauteur_ * largeur_)
	TypeImage typeImage_;		   // Type de l'image cree
};

size_t bitmap_encode_rgb(const unchar *rgb, unsigned int width, unsigned int height, unsigned char** output);

#endif //TP3_IMAGE_H
