#ifndef TP3_PIXEL_GRIS_H
#define TP3_PIXEL_GRIS_H

#include "Pixel.h"

class PixelBN;
class PixelCouleur;

class PixelGris :
	public Pixel
{
public:
	PixelGris();
	PixelGris(unsigned int);
	PixelGris(unchar);
	~PixelGris();

	bool convertirPixelBN();
    unchar convertirPixelGris();
	virtual void mettreEnNegatif();

    virtual Pixel* retournerUneCopieProfonde();

    unchar obtenirDonnee() const;

    virtual unchar retournerR() const;
    virtual unchar retournerG() const;
    virtual unchar retournerB() const;

	// TP5
	virtual bool estMajoriteRouge() const;
	virtual bool estMajoriteVert() const;
	virtual bool estMajoriteBleu() const;
	virtual double retournerIntensiteMoyenne() const;


private:
	unchar donnee_;
};

#endif // TP3_PIXEL_GRIS_H