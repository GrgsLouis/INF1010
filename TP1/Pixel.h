#ifndef PIXEL_H
#define PIXEL_H




class Pixel
{
public:
	Pixel();
	~Pixel();

	Pixel(unsigned int tauxRouge,unsigned int tauxVert, unsigned int tauxBleu);

	void modifierTeinteRouge( int incrementRouge); 
	void modifierTeinteVert( int incrementVert); 
	void modifierTeinteBleu(int incrementBleu); 
		 
	void afficherPixel() const; 
	unsigned int getTauxRouge(); 
	unsigned int getTauxVert(); 
	unsigned int getTauxBleu(); 

private:
	unsigned int tauxRouge_ ;
	unsigned int tauxVert_;
	unsigned int tauxBleu_;
};

#endif
