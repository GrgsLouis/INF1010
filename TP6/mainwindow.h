#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QString>
#include <QScrollArea>
#include <QLabel>
#include <QScrollBar>
#include <QScreen>
#include <QRect>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDir>
#include <QImageReader>
#include <QImageWriter>
#include <QMessageBox>
#include <QPointer>
#include <QTableWidget>
#include <QGroupBox>
#include <QPushButton>

#include "image.h"
#include "undoredo.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Constructeur (le mot cle explicit empeche
    // l'utilisation de ce constructeur pour la
    // conversion implicite d'un QWidget en MainWindow
    explicit MainWindow(QWidget *parent = 0);
    // Destructeur
    ~MainWindow();

private slots:
    // Slots Qt permettant la reception de signaux
    void ouvrirImage();
    void enregistrerImage();
    void updateImage(QImage image);
    void updateTableViewWidget(QImage image);
    void afficherMessage(QString msg);
    void about();

    void on_Button_nb_clicked();

    void on_pushButton_clicked();

private:
    // Fonction qui cree les actions de la barre de menu
    void creeActions();
    // Fonction d'initialisation de l'interface utilisateur
    void initUI();
    // Fonction initialisant les connections entre les
    // signaux et leur foncitons
    void initConnections();
    // Fonction permettant de configurer une fenetre de dialogue explorateur de fichier
    static void fileExplorer(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode);
    // Fonction qui active les boutons de l'interface
    void activateButtons();

    // Interface utilisateur
    Ui::MainWindow *ui;
    // Attribut Image permettant de traiter une image
    Image image_;
    // Vue sur l'image
    QPointer<QLabel> imageLabel_;
    QMenu* FileMenu; // c ajouter
    QMenu* EditMenu; //
    QMenu* AideMenu; //
    // Action d'ouverture (correspond a un click Ficher + Ouvrir)
    QAction *actionOuvrir_;
    // Action a propos (correspond a un click Aide + A Propos)
    QAction *actionAPropos_;
    // Action d'enregistrement (correspond a un click Ficher + Enregistrer sous)
    QAction *actionEnregistrerSous_;
    QAction *undo_;
    QAction *redo_;

    // GroupBox contenant les boutons
    QGroupBox *groupBox_;
    // Bouton Noir et Blanc
    QPushButton *boutonNB_;
    // Bouton Nuance de Gris
    QPushButton *boutonGris_;
    // Bouton Negatif
    QPushButton *boutonNegatif_;

    // Table widget qui affiche des informations sur l'image
    QTableWidget * tableWidget_;

    // Environement avec barre de deplacement
    QScrollArea *imageScrollArea_;
};

#endif // MAINWINDOW_H
