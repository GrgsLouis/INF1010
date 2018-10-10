//
// Commandes
// Definition et implementation des commandes
// de modification sur les images utilisees
// dans le tp.
//

#ifndef COMMANDES_H
#define COMMANDES_H

#include <QImage>
#include "interfacecommande.h"

// MettreEnNegatif, commande qui met l'image en negatif
class MettreEnNegatif : public InterfaceCommande {
public:
    explicit MettreEnNegatif(QImage *image) : image_(image) {}
    virtual ~MettreEnNegatif() {}
    // Executer appelle la fonction invertPixels de QImage
    virtual void Executer() {image_->invertPixels();}
    // AnnulerCommande rappelle invertPixels de QImage (-(-1) = 1)
    virtual void AnnulerCommande() {image_->invertPixels();}
private:
    QImage *image_;
};

// ConvertirEnGris, commande qui met l'image en gris
class ConvertirEnGris : public InterfaceCommande {
public:
    // Cree une copie de l'image originale et une copie de l'image en gris
    explicit ConvertirEnGris(QImage *image) : image_(image), originalImage_(*image) {
        grayImage_ = originalImage_.convertToFormat(QImage::Format_Grayscale8);
    }
    virtual ~ConvertirEnGris() {}
    // Executer remplace l'image pointee par l'image en gris
    virtual void Executer() {
        *image_ = grayImage_;
    }
    // AnnulerCommande remplace l'image pointee par l'image originale
    virtual void AnnulerCommande() {
        *image_ = originalImage_;
    }
private:
    QImage *image_;
    QImage grayImage_;
    QImage originalImage_;
};

// ConvertirEnGris, commande qui met l'image en noir et blanc
class ConvertirEnNoirEtBlanc : public InterfaceCommande {
public:
    // Cree une copie de l'image originale et une copie de l'image en noir et blanc
    explicit ConvertirEnNoirEtBlanc(QImage *image) : image_(image), originalImage_(*image) {
        nbImage_ = originalImage_.convertToFormat(QImage::Format_Mono);
    }
    virtual ~ConvertirEnNoirEtBlanc() {}
    // Executer remplace l'image pointee par l'image en gris
    virtual void Executer() {
        *image_ = nbImage_;
    }
    // AnnulerCommande remplace l'image pointee par l'image originale
    virtual void AnnulerCommande() {
        *image_ = originalImage_;
    }
private:
    QImage *image_;
    QImage nbImage_;
    QImage originalImage_;
};

#endif // COMMANDES_H
