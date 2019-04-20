/**
 * \file Bibliographie_Testeur.cpp
 * \brief Fichier test pour la classe Bibliographie
 * \author etudiant
 * \version 1.0
 * \date 2019-04-10
 */

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "Bibliographie.h"
#include "Ouvrage.h"
#include "Journal.h"

using namespace biblio;

int annee = 2030;
int volume = 30;
int numero = 69;
int page = 420;

//On vérifie si le vecteur est bel et bien vide
TEST(Bibliographie, Constructeur)
{
	try
	{
		Bibliographie bibli("Biblio");
	} catch (ContratException e)
	{
		ASSERT_TRUE(false);
	}
	ASSERT_TRUE(true);
}

class bibliographieTest: public ::testing::Test
{
	public:
		bibliographieTest() :
				bibli("Biblio"), ouvrage1("Albert Einstein", "Mein Kampf",
				        annee, "ISBN 978-2-1234-5680-3", "Illuminatis Inc",
				        "Berlin"), ouvrage2("Albert Einstein", "Mein Kampf",
				        annee, "ISBN 0-201-89551-X", "Illuminatis Inc",
				        "Berlin"), journal1("Albert Einstein", "Mein Kampf",
				        annee, "ISSN 0395-2037", "Philosophie moderne", volume,
				        numero, page), journal2("Albert Einstein", "Mein Kampf",
				        annee, "ISSN 0395-2037", "Philosophie moderne", volume,
				        numero, page)
		{
		}
		Bibliographie bibli;
		Ouvrage ouvrage1;
		Ouvrage ouvrage2;
		Journal journal1;
		Journal journal2;
};

TEST_F(bibliographieTest, reqNom)
{
	ASSERT_TRUE("Biblio" == bibli.reqNom());
}

TEST_F(bibliographieTest, ajouterReference)
{
	ASSERT_EQ("Biblio\n===============================",
	        bibli.reqBibliographieFormate());
	bibli.ajouterReference(ouvrage1);
	bibli.ajouterReference(ouvrage2);
	bibli.ajouterReference(journal1);
	std::ostringstream oss;
	oss << "Biblio\n===============================\n" << "[1] "
	        << ouvrage1.reqReferenceFormate() << "\n" << "[2] "
	        << ouvrage2.reqReferenceFormate() << "\n" << "[3] "
	        << journal1.reqReferenceFormate();
	ASSERT_EQ(oss.str(), bibli.reqBibliographieFormate());
	ASSERT_THROW(bibli.ajouterReference(journal2), ContratException);
}

TEST_F(bibliographieTest, reqBibliographieFormate)
{
	ASSERT_EQ("Biblio\n===============================",
	        bibli.reqBibliographieFormate());
	bibli.ajouterReference(ouvrage1);
	bibli.ajouterReference(ouvrage2);
	bibli.ajouterReference(journal1);
	std::ostringstream oss;
	oss << "Biblio\n===============================\n" << "[1] "
	        << ouvrage1.reqReferenceFormate() << "\n" << "[2] "
	        << ouvrage2.reqReferenceFormate() << "\n" << "[3] "
	        << journal1.reqReferenceFormate();
	ASSERT_EQ(oss.str(), bibli.reqBibliographieFormate());
}
