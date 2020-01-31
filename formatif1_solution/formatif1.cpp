#include <string>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "..\screen\screen.h"
using namespace std;

#include "donnees.h"
#include "activite.h" 
#include "eleve.h" 

//const int maxActivites = 10;
//const int maxEleves = 25;

//Activite lesActivites[maxActivites];
//Eleve lesEleves[maxEleves];
Donnees lesDonneesDuProgramme;

int nombreActivitesReelles = 0;
int nombreElevesReels = 0;

char AfficherMenu();
//partie 1
void AjouterActivite();
void Afficher(Activite aActivite);
void Afficher(Eleve aEleve);
void AfficherLesActivites();

void ChoixActivite();

//partie 2
void AjouterLesEleves();
void AfficherLesEleves();
void InscrireUnEleve(string, string, string);

//partie 3
void InscrireEleveActivite();
int RechercherEleve(string eleveVoulu);
int RechercherActivite(string activiteVoulu);
void AfficherLesInscriptions();


int main()
{
	char choix = ' ';
	while (choix != '0')
	{
		choix = AfficherMenu();
		switch (choix)
		{
		case '1': AjouterActivite();
			break;
		case '2': ChoixActivite();
			break;
		case '3': AfficherLesActivites();
			break;
		case '4': AjouterLesEleves();
			break;
		case '5': AfficherLesEleves();
			break;
		case '6': InscrireEleveActivite();
			break;
		case '7': AfficherLesInscriptions();
			break;
		}
	}
}
//----------------------------------------------------------------------------------------
void ChoixActivite() {

	int lActiviteChoisie;

	ClrScr();

	cout << "Inscrire le numero de l'activite voulue: ";
	cin >> lActiviteChoisie;

	if ((lActiviteChoisie > nombreActivitesReelles) || lActiviteChoisie < 1) {

		ChoixActivite();

	}
	else {

		Afficher(lesDonneesDuProgramme.lesActivites[lActiviteChoisie - 1]);

	}

}

//----------------------------------------------------------------------------------------
char AfficherMenu()
{
	char choix;
	ClrScr();
	Gotoxy(15, 4);
	cout << "1- Ajouter une activite";
	Gotoxy(15, 6);
	cout << "2- Afficher les informations d'une activite";
	Gotoxy(15, 8);
	cout << "3- Afficher toutes les activites";
	Gotoxy(15, 10);
	cout << "4- Ajouter des eleves";
	Gotoxy(15, 12);
	cout << "5- Afficher les eleves";
	Gotoxy(15, 14);
	cout << "6- Inscrire un eleve a une activite";
	Gotoxy(15, 16);
	cout << "7- Afficher les inscriptions d'une activite";
	Gotoxy(15, 18);
	cout << "0- Arreter";
	Gotoxy(15, 20);
	cout << "Choix: ";
	cin >> choix;
	return choix;
}

//----------------------------------------------------------------------------------------
void AjouterActivite()
{
	string code; //test git
	string titre;
	string responsable;
	ClrScr();
	cout << "Code activite: ";
	cin >> code;
	cout << "Titre: ";
	cin >> titre;
	cout << "Responsable: ";
	cin >> responsable;
	//ajoutez les instructions permettant d'inscrire la nouvelle activité dans le tableau des activités
	//utilisez nombreActivitesReelles comme indice pour le tableau

	if (nombreActivitesReelles < 10) {

		lesDonneesDuProgramme.lesActivites[nombreActivitesReelles].InitialiserActivite(code, titre);
		lesDonneesDuProgramme.lesActivites[nombreActivitesReelles].AssignerResponsable(responsable);

		nombreActivitesReelles++;

	}
	else {

		cout << "Le nombre maximal d'activite a ete atteint" << endl;

	}

}

//----------------------------------------------------------------------------------------
void Afficher(Activite aActivite) {

	cout << "\n\n\tCode de l'activite: " << aActivite.getCodeActivite() << endl << "\tTitre de l'activite: " << aActivite.getTitre() << endl << "\tResponsable de l'activite: " << aActivite.getResponsable() << endl;
}

void Afficher(Eleve aEleve) {

	cout << "\n\n\tCode de l'eleve: " << aEleve.getCodeEleve() << endl << "\tNom de l'eleve: " << aEleve.getNom() << endl << "\tPrenom de l'eleve: " << aEleve.getPrenom() << endl;

}

//----------------------------------------------------------------------------------------
void AfficherLesActivites()
{
	ClrScr();

	for (unsigned int i = 0; i < nombreActivitesReelles; i++) {

		Afficher(lesDonneesDuProgramme.lesActivites[i]);

	}

	_getch();
}

//----------------------------------------------------------------------------------------
void AjouterLesEleves()
{
	InscrireUnEleve("111", "Laroche", "Arthur");
	InscrireUnEleve("222", "Cailloux", "Fred");
	InscrireUnEleve("333", "Cailloux", "Delima");
	InscrireUnEleve("444", "Laroche", "Bertha");
	InscrireUnEleve("555", "Cailloux", "Agathe");
	InscrireUnEleve("666", "Laroche", "Boumboum");
	InscrireUnEleve("777", "Mirock", "Pierre");
	InscrireUnEleve("888", "Roche", "Onezime");
	InscrireUnEleve("999", "Roche", "Alfreda");
	InscrireUnEleve("112", "Cailloux", "Dino");
}

//----------------------------------------------------------------------------------------
void AfficherLesEleves()
{
	ClrScr();

	for (unsigned int i = 0; i < nombreElevesReels; i++) {

		Afficher(lesDonneesDuProgramme.lesEleves[i]);

	}

	_getch();
}
//----------------------------------------------------------------------------------------
void InscrireUnEleve(string inCode, string inNom, string inPrenom)
{
	if (nombreElevesReels < maxEleves) {

		lesDonneesDuProgramme.lesEleves[nombreElevesReels].InscrireEleve(inCode, inNom, inPrenom);

	}

	nombreElevesReels++;
}

//----------------------------------------------------------------------------------------
void InscrireEleveActivite()
{
	string eleve;
	string activite;
	int cptEleve;
	int cptActivite;
	ClrScr();
	cout << "Code de l'eleve a inscrire: ";
	cin >> eleve;
	cptEleve = RechercherEleve(eleve);
	cout << "Activite desiree: ";
	cin >> activite;
	cptActivite = RechercherActivite(activite);

	Afficher(lesDonneesDuProgramme.lesEleves[cptEleve]);
	Afficher(lesDonneesDuProgramme.lesActivites[cptActivite]);

	lesDonneesDuProgramme.lesEleves[cptEleve].InscrireAUneActivite(&lesDonneesDuProgramme.lesActivites[cptActivite]);

	_getch();
}

//----------------------------------------------------------------------------------------
int RechercherEleve(string inCodeVoulu)
{
	int cptEleve = 0;
	int posEleve = 0;
	bool trouve = false;
	while (trouve == false && cptEleve < maxEleves)
	{

		if (lesDonneesDuProgramme.lesEleves[cptEleve].getCodeEleve() == inCodeVoulu) {

			posEleve = cptEleve;
			trouve = true;

		}
		cptEleve++;

	}
	return posEleve;
}

//----------------------------------------------------------------------------------------
int RechercherActivite(string inCodeActiviteVoulue)
{
	int cptActivite = 0;
	int posActivite = 0;
	bool trouve = false;
	while (trouve == false && cptActivite < maxActivites/*nombreActivites*/)
	{

		if (lesDonneesDuProgramme.lesActivites[cptActivite].getCodeActivite() == inCodeActiviteVoulue) {

			posActivite = cptActivite;
			trouve = true;

		}
		cptActivite++;

	}
	return posActivite;
}
//----------------------------------------------------------------------------------------
void AfficherLesInscriptions()
{
	int cptEleve = 0;

	string activite;
	ClrScr();
	cout << "Code de l'activite: ";
	cin >> activite;

	while (cptEleve < maxEleves) {

		if (lesDonneesDuProgramme.lesEleves[cptEleve].getCodeActivite() == activite) {

			Afficher(lesDonneesDuProgramme.lesEleves[cptEleve]);

		}
		cptEleve++;

	}

	_getch();
}







