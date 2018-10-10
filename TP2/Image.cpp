
#include "Image.h"
#include <iostream>
#include "Const.h"

using namespace std;

Image::Image():nomImage_("Image Vide"),nombrePixelEnHauteur_(1),nombrePixelEnLargeur_(1)
{
	pixels_ = new Pixel*[1];
	pixels_[0] = new Pixel[1];
}

Image::Image(const Image& image):nomImage_(image.nomImage_), nombrePixelEnHauteur_(image.nombrePixelEnHauteur_),
nombrePixelEnLargeur_(image.nombrePixelEnLargeur_)
{
	pixels_ = new Pixel*[nombrePixelEnHauteur_];			//créer un nouveau tableau de pixels
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) 
	{
		pixels_[i] = new Pixel[nombrePixelEnLargeur_];

		for (int j = 0; j < nombrePixelEnLargeur_; j++)     //Remplir le nouveau tableau de pixels avec les valeurs
			pixels_[i][j] = image.pixels_[i][j];			//de l'objet précédent.(deep copy)
	}
}


Image::~Image()
{
	/*
	for(unsigned int i = 0; i < nombrePixelEnHauteur_; i++){
		delete[] pixels_[i];
	}
	delete[] pixels_;
	nombrePixelEnHauteur_ = 0;
	nombrePixelEnLargeur_ = 0;
	pixels_ = nullptr;
	*/
}

Image::Image(const string& nomImage,unsigned int nombrePixelHauteur, unsigned int nombrePixelLargeur) :nomImage_(nomImage),
	nombrePixelEnHauteur_(nombrePixelHauteur), nombrePixelEnLargeur_(nombrePixelLargeur)
{
	pixels_ = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0; i < nombrePixelEnHauteur_;i++) {
		pixels_[i] = new Pixel[nombrePixelEnLargeur_];
	}
}


void Image::modifierNomImage(const string & nomImage) {
	nomImage_ = nomImage;
}


unsigned int Image::obtenirNombrePixelHauteur() const {
	return nombrePixelEnHauteur_;
}


unsigned int Image::obtenirNombrePixelLargeur() const {
	return nombrePixelEnLargeur_;
}

string Image::obtenirNomImage() const{
	return nomImage_;
}

bool Image::ajouterPixel(Pixel & pixel, unsigned int positionLargeur, unsigned int positionHauteur) {
	if (positionLargeur >= nombrePixelEnLargeur_ || positionHauteur >= nombrePixelEnHauteur_) {
		return false;
	}
	else {
		pixels_[positionHauteur][positionLargeur] = pixel;
		return true;
	}
}




void Image::doublerTailleEnHauteur(){
	nombrePixelEnHauteur_ *= 2;

	Pixel** imageTemp = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0;i < nombrePixelEnHauteur_ / 2;i++) {
		imageTemp[i] = pixels_[i];
	}

	for (unsigned int i = nombrePixelEnHauteur_ / 2;i < nombrePixelEnHauteur_;i++) {
		imageTemp[i] = new Pixel[nombrePixelEnLargeur_];
	}	

	delete[] pixels_;
	pixels_ = imageTemp;
	imageTemp = nullptr;

}


void Image::doublerTailleEnLargeur() {
	nombrePixelEnLargeur_ *= 2;

	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		Pixel* colonneImage = new Pixel[nombrePixelEnLargeur_];
		for (unsigned int j = 0;j < nombrePixelEnLargeur_ / 2; j++) {
			colonneImage[j] = pixels_[i][j];
		}
		delete[] pixels_[i];
		pixels_[i] = colonneImage;

	}

	
}


ostream& operator<<(ostream& o, Image image)
{
	o << "Affichage de l'image :  " << image.nomImage_.c_str()<< endl;
	
	for (unsigned int i = 0; i < image.nombrePixelEnHauteur_; i++) {
		o << "    ";
			for (unsigned int j = 0; j < image.nombrePixelEnLargeur_;j++) {
				o << image.pixels_[i][j];
		    }
		o << endl;
	}
	return o;
}

Pixel Image::obtenirPixel(unsigned int positionLargeur,unsigned int positionHauteur) const {
 
	return pixels_[positionHauteur][positionLargeur];

}

void Image::augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur) {

	if (couleur == 'R') {
		pixels_[positionHauteur][positionLargeur].modifierTeinteRouge(increment);
	}
	if (couleur == 'G') {
		pixels_[positionHauteur][positionLargeur].modifierTeinteVert(increment);
	}
	if (couleur == 'B') {
		pixels_[positionHauteur][positionLargeur].modifierTeinteBleu(increment);
	}

}

Image& Image::operator=(const Image& image)
{
	if (this != &image) {										//si l'objet à écraser est différent de l'objet à copier
		for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) { //désallouer la mémoire de l'objet à écraser.
			delete[] pixels_[i];
		}
		delete[] pixels_;
	}

	pixels_ = new Pixel*[image.nombrePixelEnHauteur_];
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++)
	{
		pixels_[i] = new Pixel[nombrePixelEnLargeur_];

		for (unsigned j = 0; j < nombrePixelEnLargeur_; j++)	//remplir le nouveau tableau créé avec les valeurs de copie
			pixels_[i][j] = image.pixels_[i][j];
	}
	return *this;									//retourne une référence d'image pour un appel en cascade.
}

bool Image::operator==(const Image& image)const
{
	bool flag = true;
	for (unsigned i = 0; i < nombrePixelEnHauteur_; i++)
		for (unsigned j = 0; j < nombrePixelEnLargeur_ && flag; j++)
			flag = (image.pixels_[i][j] == pixels_[i][j]);

	return (flag && nomImage_ == image.nomImage_);
}

bool Image::operator==(const string& nom)const
{
	return (nomImage_ == nom);
}

bool operator==(const string& nom, const Image& image)
{
	return (image.nomImage_ == nom);
}

