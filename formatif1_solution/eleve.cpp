#include "eleve.h"
#include <conio.h>

Eleve::Eleve() {

	codeEleve = "";
	nom = "";
	prenom = "";
	activiteDeLEleve = NULL;

}

Eleve::Eleve(string aCodeEleve, string aNom, string aPrenom) {

	codeEleve = aCodeEleve;
	nom = aNom;
	prenom = aPrenom;
	activiteDeLEleve = NULL;

}

string Eleve::getCodeEleve() const {
	 
	return codeEleve;

}

string Eleve::getNom() const {

	return nom;

}

string Eleve::getPrenom() const {

	return prenom;

}

string Eleve::getCodeActivite() const {
	
	string titreActivite = "";

	if (activiteDeLEleve != NULL) {

		titreActivite = activiteDeLEleve->getCodeActivite();

	}
	return titreActivite;
}

void Eleve::InscrireEleve(string aCodeEleve, string aNom, string aPrenom) {

	codeEleve = aCodeEleve;
	nom = aNom;
	prenom = aPrenom;

}

void Eleve::InscrireAUneActivite(Activite* aActivite) {

	activiteDeLEleve = aActivite;

}
