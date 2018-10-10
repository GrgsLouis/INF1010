#ifndef IMAGE_H
#define IMAGE_H

#include <QObject>
#include <QString>
#include <QImage>
#include <QPointer>
#include <QFileInfo>

#include <string>
#include <memory>

#include "interfacecommande.h"
#include "undoredo.h"

class Image : public QObject
{
    Q_OBJECT
public:
    // Constructeur par defaut
    Image();
    // Constructeur par parametre string
    Image(const std::string& cheminVersLeFichier);
    // Constructeur par parametre QString
    Image(const QString& cheminVersLeFichier);

    // Accesseur
    QFileInfo obtenirNomDuFichier() const {return nomDuFichier_;}

    // Fonction permettant d'ouvrir une image
    bool ouverturDeImage(const QString &cheminVersLeFichier);
    // Fonction permettant d'enregistrer une image
    bool enregistrerImage(const QString &cheminVersEnregistrement);

signals:
    void signal_changementImage (QImage image);

public slots:
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * * * * * * * * * * * * * * * *  TODO * * * * * * * * * * * * * * * * * * 
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    // "Slot" Qt permettant de recevoir des signaux
    void convertirEnNuanceDeGris(); // exemple
    // Creer une slot convertirEnNoirEtBlanc
    void convertirEnNoirEtBlanc();
    // Creer une slot mettreEnNegatif
    void mettreEnNegatif();
    // Creer une slot undo
    void undo();
    // Creer une slot redo
    void redo();
private:
    QImage image_;
    QFileInfo nomDuFichier_;
    UndoRedo undoRedo_;
};

#endif // IMAGE_H
