//
// Created by Gabriel Bernard
//

#ifndef TP3_PIXELBN_H
#define TP3_PIXELBN_H

#include "Pixel.h"
#include "TypePixel.h"

class PixelBN: public Pixel
{
public:
	PixelBN();
	PixelBN(bool p);
	~PixelBN();

	unchar* convertirPixelCouleur() const;
	unchar convertirPixelGris() const;
	virtual void mettreEnNegatif();
	bool obtenirDonnee() const;
	virtual unchar retournerR() const;
	virtual unchar retournerG() const;
	virtual unchar retournerB() const;
	virtual PixelBN* retournerCopieProfonde();
	virtual bool convertirPixelBN() const;
	/*virtual PixelBN& operator=(const PixelBN& pixel);*/
private:
	bool donnee_;
};

#endif // TP3_PIXELBN_H