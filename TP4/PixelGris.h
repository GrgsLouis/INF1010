//
// Created by Gabriel Bernard
//

#ifndef TP3_PIXEL_GRIS_H
#define TP3_PIXEL_GRIS_H

#include "Pixel.h"

class PixelGris :
	public Pixel
{
public:
	PixelGris();
	PixelGris(unsigned int);
	~PixelGris();
	virtual void mettreEnNegatif();
	bool convertirPixelBN() const;
	unchar* convertirPixelCouleur() const;
	virtual unchar retournerR() const;
	virtual unchar retournerG() const;
	virtual unchar retournerB() const;
	unsigned int obtenirDonnee() const;
	virtual PixelGris* retournerCopieProfonde();
	virtual unchar convertirPixelGris() const;
	/*virtual PixelGris& operator=(const PixelGris& pixel);*/
private:
	unchar donnee_;
};

#endif // TP3_PIXEL_GRIS_H