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

#include "undoredo.h"

using namespace std;
// Constructeur
UndoRedo::UndoRedo() {}

// Inseretion de commandes dans les attributs de l'objet
void UndoRedo::insererDansUndosRedos(shared_ptr<InterfaceCommande> commande) {
    // Si redos_ n'est pas vide, il faut le vider
    while(!redos.empty()){
        redos.pop();
    }
    // Ajout de la commande a undos_
    undos.push(commande);
}

// Appelle AnnulerCommande sur la derniere commande ajoutee
void UndoRedo::undo() {
    // Si la stack undos est vide, ne fait rien
    if(undos.empty())
        return;
    // Appelle annulerCommande et retire la commande de la stack
    // apres l'avoir ajoutee a la stack redos
    shared_ptr<InterfaceCommande> c = undos.top();
    redos.push(c);
    c->AnnulerCommande();
    undos.pop();
}

// Appelle executer sur la derniere commande ajoute a redo
void UndoRedo::redo() {
    // Si redos est vide, ne fait rien
    if(redos.empty())
        return;
    // Appelle executer sur la comande, la rajoute a undos
    // et retire la commande de redos
    shared_ptr<InterfaceCommande> c = redos.top();
    undos.push(c);
    c->Executer();
    redos.pop();
}

void UndoRedo::clear() {
    // Si redos_ n'est pas vide, il faut le vider
    while(!redos.empty()){
        redos.pop();
    }
    // Si undos_ n'est pas vide, il faut le vider
    while(!undos.empty()){
        undos.pop();
    }
}
