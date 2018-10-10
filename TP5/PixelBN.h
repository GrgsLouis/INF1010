#ifndef TP3_PIXELBN_H
#define TP3_PIXELBN_H

#include "Pixel.h"

class PixelBN: public Pixel
{
public:
	PixelBN();
	PixelBN(bool p);
	~PixelBN();

	virtual bool convertirPixelBN();
	virtual unchar convertirPixelGris();
	virtual void mettreEnNegatif();

	virtual Pixel* retournerUneCopieProfonde();
	bool obtenirDonnee();

	virtual unchar retournerR() const;
	virtual unchar retournerG() const;
	virtual unchar retournerB() const;

	//TP5
	virtual bool estMajoriteRouge() const;
	virtual bool estMajoriteVert() const;
	virtual bool estMajoriteBleu() const;
	virtual double retournerIntensiteMoyenne() const;

private:
	bool donnee_;
};

#endif // TP3_PIXELBN_H