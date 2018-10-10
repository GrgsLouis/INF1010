//
// Created by Gabriel Bernard on 17-10-06.
//

#include "Pixel.h"

// Méthode de comparaison de la classe pixel
bool Pixel::operator==(const Pixel &p) const {
	// This pour utiliser les fonctions des sous-classes.
    return (this->retournerR() == p.retournerR() &&
            this->retournerG() == p.retournerG() &&
            this->retournerB() == p.retournerB());
}