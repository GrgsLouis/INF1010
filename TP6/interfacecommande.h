//
// InterfaceCommande
// Classe abstraite permettant d'identifier
// les commandes possedant des fonctions
// Executer et AnnulerCommande.
//

#ifndef INTERFACECOMMANDE_H
#define INTERFACECOMMANDE_H

class InterfaceCommande
{
public:
    InterfaceCommande() {};
    virtual ~InterfaceCommande() {};
    virtual void Executer() = 0;
    virtual void AnnulerCommande() = 0;
};

#endif // INTERFACECOMMANDE_H
