//
// UndoRedo
// Classe permettant de garder en memoire
// les commandes effectuees. Chaque commande
// doit derivee de la classe abstraite
// InterfaceCommande qui assure la possession
// d'une fonction undo et redo.
//
// La stack undos_ permet de garder toutes les
// commandes effectuees au fur et a mesure qu'elles
// sont inseree grace a la fonciton insererDansUndosRedos
// pour q'on puisse appeler undo plus tard. Undo permet
// de retrouver la derniere commande utilisee, appelle
// la fonction annulerCommande, retire la commande de la stack
// undos_ et l'ajoute a la stack redos_. Ainsi, redo peut appeler
// executer sur les commandes qui la remplisse le cas echeant.
//

#ifndef UNDOREDO_H
#define UNDOREDO_H

#include <stack>
#include <memory>
#include "interfacecommande.h"

class UndoRedo
{
public:
    UndoRedo();
    void insererDansUndosRedos(std::shared_ptr<InterfaceCommande> commande);
    void undo();
    void redo();
    void clear();
private:
    std::stack<std::shared_ptr<InterfaceCommande>> undos;
    std::stack<std::shared_ptr<InterfaceCommande>> redos;
};

#endif // UNDOREDO_H
