#ifndef EleveH 
#define EleveH
//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include "activite.h"
using namespace std;

class Eleve 
{

private:

	string codeEleve;
	string nom;
	string prenom;
	Activite* activiteDeLEleve;

public:

	Eleve();
	Eleve(string aCodeEleve, string aNom, string aPrenom);

	string getCodeEleve() const;
	string getNom() const;
	string getPrenom() const;
	string getCodeActivite() const;

	void InscrireEleve(string aCodeEleve, string aNom, string aPrenom);
	void InscrireAUneActivite(Activite* aActivite);

};


#endif

