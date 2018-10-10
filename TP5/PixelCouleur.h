
#ifndef TP3_PIXEL_COULEUR_H
#define TP3_PIXEL_COULEUR_H

#include "Pixel.h"

enum Couleur { R, G, B };  // R = 0, G = 1, B = 2
const int LONGUEUR_TABLEAU = 3;  // donnee_[3]

class PixelCouleur :
	public Pixel
{
public:
	PixelCouleur();
	PixelCouleur(const bool& donnee);
	PixelCouleur(const unsigned int& donnee);
    PixelCouleur(const unchar& donnee);
    PixelCouleur(const unchar& R, const unchar& G, const unchar& B);
	~PixelCouleur();

	void modifierTeinteRouge(unchar d);
	void modifierTeinteVerte(unchar d);
	void modifierTeinteBleue(unchar d);

	bool convertirPixelBN();
	unchar convertirPixelGris();
    virtual void mettreEnNegatif();

    virtual Pixel* retournerUneCopieProfonde();

    virtual unchar retournerR() const;
    virtual unchar retournerG() const;
    virtual unchar retournerB() const;

	//TP5
	virtual bool estMajoriteRouge() const;
	virtual bool estMajoriteVert() const;
	virtual bool estMajoriteBleu() const;
	virtual double retournerIntensiteMoyenne() const;

private:
    void assignerValeurs(const unchar& donnee);
    void assignerValeur(const unsigned int& donnee);
	unsigned int somme() const;

	unchar donnee_[LONGUEUR_TABLEAU];
};

#endif // TP3_PIXEL_COULEUR_H