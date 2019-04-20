/**
 * \file gestionBibliographie.cpp
 * \brief Programme principal
 * \author etudiant
 * \date 2019-02-27
 */

#include <iostream>
#include "Reference.h"
#include "validationFormat.h"
#include "Ouvrage.h"
#include "Journal.h"
#include "Bibliographie.h"

using namespace std;
using namespace biblio;
using namespace util;

/**
 * \brief Crée une instance de la classe biblio::Ouvrage
 * \return l'instance de la classe biblio::Ouvrage
 */
Ouvrage creerOuvrage()
{
	string auteurs;
	string titre;
	int annee;
	string identifiant;
	string editeur;
	string ville;
	cout << "Crée un ouvrage" << endl;
	do
	{
		cout << "Entre le nom des auteurs:" << endl;
		std::getline(std::cin, auteurs);
	} while (!auteurs.empty() && !validerFormatNom(auteurs));
	do
	{
		cout << "Entre le titre:" << endl;
		std::getline(std::cin, titre);
	} while (!titre.empty());
	do
	{
		string anneeStr;
		cout << "Entre l'année:" << endl;
		std::getline(std::cin, anneeStr);
		annee = std::stoi(anneeStr);
	} while (annee <= 0);
	do
	{
		cout << "Entre le code d'identification:" << endl;
		std::getline(std::cin, identifiant);
	} while (!(validerCodeIsbn(identifiant)));
	do
	{
		cout << "Entre l'éditeur:" << endl;
		std::getline(std::cin, editeur);
	} while (!editeur.empty() && !validerFormatNom(editeur));
	do
	{
		cout << "Entre la ville:" << endl;
		std::getline(std::cin, ville);
	} while (!ville.empty() && !validerFormatNom(ville));
	Ouvrage ouvrage(auteurs, titre, annee, identifiant, editeur, ville);
	return ouvrage;
}

/**
 * \brief Crée une instance de la classe biblio::Journal
 * \return l'instance de la classe biblio::Journal
 */
Journal creerJournal()
{
	string auteurs;
	string titre;
	int annee;
	string identifiant;
	string nom;
	int volume;
	int numero;
	int page;
	cout << "Crée un journal" << endl;
	do
	{
		cout << "Entre le nom des auteurs:" << endl;
		std::getline(std::cin, auteurs);
	} while (!auteurs.empty() && !validerFormatNom(auteurs));
	do
	{
		cout << "Entre le titre:" << endl;
		std::getline(std::cin, titre);
	} while (!titre.empty());
	do
	{
		string anneeStr;
		cout << "Entre l'année:" << endl;
		std::getline(std::cin, anneeStr);
		annee = std::stoi(anneeStr);
	} while (annee <= 0);
	do
	{
		cout << "Entre le code d'identification:" << endl;
		std::getline(std::cin, identifiant);
	} while (!(validerCodeIssn(identifiant)));
	do
	{
		cout << "Entre le nom:" << endl;
		std::getline(std::cin, nom);
	} while (!nom.empty() && !validerFormatNom(nom));
	do
	{
		string volumeStr;
		cout << "Entre le volume:" << endl;
		std::getline(std::cin, volumeStr);
		volume = std::stoi(volumeStr);
	} while (volume <= 0);
	do
	{
		string numeroStr;
		cout << "Entre le numéro:" << endl;
		std::getline(std::cin, numeroStr);
		numero = std::stoi(numeroStr);
	} while (numero <= 0);
	do
	{
		string pageStr;
		cout << "Entre la page:" << endl;
		std::getline(std::cin, pageStr);
		page = std::stoi(pageStr);
	} while (volume <= 0);
	Journal journal(auteurs, titre, annee, identifiant, nom, volume, numero,
	        page);
	return journal;
}

/**
 * \brief lance le programme
 * \return un int de valeur 0
 */
int main()
{
	string nomBibli;
	cout << "Crée un bibliographie!" << endl;
	do
	{
		cout << "Nomme ta bibliographie:" << endl;
		std::getline(std::cin, nomBibli);
	} while (!nomBibli.empty());
	Bibliographie bibli(nomBibli);
	bibli.ajouterReference(creerOuvrage());
	bool recommencerOuvrage = false;
	do
	{
		try
		{
			recommencerOuvrage = false;
			bibli.ajouterReference(creerOuvrage());
		} catch (ContratException e)
		{
			cout << "Tu dois recommencer" << endl;
			recommencerOuvrage = true;
		}
	} while (recommencerOuvrage);
	bibli.ajouterReference(creerJournal());
	bool recommencerJournal = false;
	do
	{
		try
		{
			recommencerJournal = false;
			bibli.ajouterReference(creerJournal());
		} catch (ContratException e)
		{
			cout << "Tu dois recommencer" << endl;
			recommencerJournal = true;
		}
	} while (recommencerJournal);
	cout << "Ta bibliographie:\n" << bibli.reqBibliographieFormate() << endl;

	cout << "Bye";
	return 0;
}