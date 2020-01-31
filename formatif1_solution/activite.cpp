#include "activite.h"

Activite::Activite() {

	codeActivite = "";
	titre = "";
	responsable = "";

}

Activite::Activite(string aCodeActivite, string aTitreActivite, string aResponsable) {

	codeActivite = aCodeActivite;
	titre = aTitreActivite;
	responsable = aResponsable;

}

void Activite::InitialiserActivite(string aCodeActivite, string aTitreActivite) {

	if (aCodeActivite != "") {

		codeActivite = aCodeActivite;

	}

	if (aTitreActivite != "") {

		titre = aTitreActivite;

	}

}

//----------------------------------------------------------------------------------------
void Activite::AssignerResponsable(string aResponsable) {

	if (aResponsable != "") {

		responsable = aResponsable;

	}

}

//----------------------------------------------------------------------------------------
string Activite::getCodeActivite() const {

	return codeActivite;

}

//----------------------------------------------------------------------------------------
string Activite::getTitre() const {

	return titre;

}

//----------------------------------------------------------------------------------------
string Activite::getResponsable() const {

	return responsable;

}

