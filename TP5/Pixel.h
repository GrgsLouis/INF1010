//
// Created by Gabriel Bernard on 17-09-12.
//

#ifndef TP3_PIXEL_H
#define TP3_PIXEL_H

typedef unsigned char unchar;

#define VALEUR_MAX_PIXEL 255
#define VALEUR_MIN_PIXEL 0

class Pixel
{
public:
	virtual ~Pixel() {};

    virtual unchar retournerR() const = 0;
    virtual unchar retournerG() const = 0;
    virtual unchar retournerB() const = 0;

    virtual bool convertirPixelBN() = 0;
    virtual unchar convertirPixelGris() = 0;


	virtual void mettreEnNegatif() = 0;
    virtual Pixel* retournerUneCopieProfonde() = 0;

    bool operator==(const Pixel& p) const;

    unchar testPixel(const unsigned int& valeur) const {
        return (unchar) (valeur > VALEUR_MAX_PIXEL ? VALEUR_MAX_PIXEL : valeur);
    }
    unchar testPixel(const unchar& valeur) const {
        return valeur > VALEUR_MAX_PIXEL ? (unchar)VALEUR_MAX_PIXEL : valeur;
    }


	//TP5
	virtual bool estMajoriteRouge() const = 0;
	virtual bool estMajoriteVert() const = 0;
	virtual bool estMajoriteBleu() const = 0;
	virtual double retournerIntensiteMoyenne() const = 0;

};

#endif // PIXEL_H