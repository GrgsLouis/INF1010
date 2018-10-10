#ifndef PIXEL_H
#define PIXEL_H
#include <iostream>



class Pixel
{
public:
	Pixel();
	~Pixel();

	Pixel(unsigned int tauxRouge,unsigned int tauxVert, unsigned int tauxBleu);

	void modifierTeinteRouge( int incrementRouge);
	void modifierTeinteVert( int incrementVert);
	void modifierTeinteBleu(int incrementBleu);

	unsigned int obtenirTauxRouge() const;
	unsigned int obtenirTauxVert() const;
	unsigned int obtenirTauxBleu() const;
		
	
     //  Remplacer cette méthode par char retournerCouleur() const;
	char retournerCouleur() const;
	
	// Ajouter les opérateurs
	friend std::ostream& operator<<(std::ostream& o, const Pixel& pixel);
	bool operator==(const Pixel& pixel)const;
	bool operator==(const char& pixel)const;
	friend bool operator==(const char& couleur, const Pixel& pixel);
private:
	unsigned int tauxRouge_ ;
	unsigned int tauxVert_;
	unsigned int tauxBleu_;
};

#endif