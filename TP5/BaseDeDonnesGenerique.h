#ifndef BASE_DE_DONNES_GENERIQUE
#define BASE_DE_DONNES_GENERIQUE

#include <list>
#include <algorithm>
#include <iterator>

// Implementer toutes les methodes dans ce fichier

using namespace  std;
template<typename T, typename S> //T = Image, S = GroupeImage
class BaseDeDonnesGenerique
{
public:
	// Rien ici
	BaseDeDonnesGenerique() {}

	// Destructeur
	~BaseDeDonnesGenerique() {
	/*	for (auto it = listImage_.begin(); it != listImage_.end(); it++) {
			delete *it;
		}
		for (auto itt = listGroupeImage_.begin(); itt != listGroupeImage_.end(); itt++) {
			delete *itt;
		}*/
		listImage_.clear();
		listGroupeImage_.clear();
	} // auto ?

	// Accesseurs
	list<T*> obtenirListImages() const {
		return listImage_;
	}
	list<S*> obtenirListGroupeImages() const {
		return listGroupeImage_;
	}

	// Ajouter images et groupes (T et S ici)
	void ajouter(T* t) {
		listImage_.push_back(t);
	}
	void ajouter(S* s) {
		listGroupeImage_.push_back(s);
	}

	// Supprimer T et S des listes internes
	bool supprimer(const T* t) {
		//auto it = find(listImage_.begin(), listImage_.end(), t);
		//if (it != listImage_.end()) {
		//	delete *it;		// a revoir
		//	*it = listImage_.back();
		//	listImage_.pop_back();
		//}
		if (!listImage_.empty()) {
			remove(listImage_.begin(), listImage_.end(), t);
		}
	}
	bool supprimer(const S* s) {
		//auto it = find(listGroupeImage_.begin(), listGroupeImage_.end(), s);
		//if (it != listGroupeImage_.end()) {
		//	delete *it;		// a revoir
		//	*it = listGroupeImage_.back();
		//	listGroupeImage_.pop_back();
		//}
		if (!listGroupeImage_.empty()) {
			remove(listGroupeImage_.begin(), listGroupeImage_.end(), s);
		}
	}

	// Supprimer un groupe image selon un prédicat
	template<typename Predicate>
	bool supprimerGroupeImage(const Predicate& predicate);
	
	// Supprimer une image selon un prédicat
	template<typename Predicate>
	bool supprimerImage(const Predicate& predicate);

	// Clearer les membres
	void vider() {
		/*for (auto it = listImage_.begin(); it != listImage_.end(); it++) {
			delete *it;
		}
		for (auto itt = listGroupeImage_.begin(); itt != listGroupeImage_.end(); itt++) {
			delete *itt;
		}*/
		listGroupeImage_.clear();
		listImage_.clear();
	}

	// Ajouter T avec opérateur 
	BaseDeDonnesGenerique& operator+=(T* t) {
		ajouter(t);
		return *this;
	}

	// Ajouter S avec opérateur
	BaseDeDonnesGenerique& operator+=(S* s) {
		ajouter(s);
		return *this;
	}

	// Retirer T avec opérateur
	BaseDeDonnesGenerique& operator-=(T* t) {
		supprimer(t);
		return *this;
	}

	// Retirer S avec opérateur
	BaseDeDonnesGenerique& operator-=(S* s) {
		supprimer(s);
		return *this;
	}

protected:
	list<T*> listImage_; //contient les images
	list<S*> listGroupeImage_; // contient des GroupeImage
};

#endif

// Fonctions pour retirer une image ou groupeImage
template<typename T, typename S>
template<typename Predicate>
bool BaseDeDonnesGenerique<T,S>:: supprimerImage(const Predicate& predicate) {
	return (remove_if(listImage_.begin(), listImage_.end(), predicate) != listImage_.end());
}

template<typename T, typename S>
template<typename Predicate>
bool BaseDeDonnesGenerique<T,S>:: supprimerGroupeImage(const Predicate& predicate) {
	return (remove_if(listGroupeImage_.begin(), listGroupeImage_.end(), predicate) != listImage.end() );
}

