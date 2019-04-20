/**
 * \file OuvrageTesteur.cpp
 * \brief Fichier test pour la classe Ouvrage
 * \author etudiant
 * \version 1.0
 * \date 2019-04-09
 */

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "Ouvrage.h"

using namespace biblio;

int annee = 2030;

TEST(Ouvrage, Constructeur)
{
	Ouvrage ouvrage13("Albert Einstein", "Mein Kampf", annee,
	        "ISBN 978-2-1234-5680-3", "Illuminatis Inc", "Berlin");
	ASSERT_EQ("ISBN 978-2-1234-5680-3", ouvrage13.reqIdentifiant());
	std::cout << std::endl << ouvrage13.reqReferenceFormate() << std::endl;
	ASSERT_EQ("Illuminatis Inc", ouvrage13.reqEditeur());
	ASSERT_EQ("Berlin", ouvrage13.reqVille());
	Ouvrage ouvrage10("Albert Einstein", "Mein Kampf", annee,
	        "ISBN 0-201-89551-X", "Illuminatis Inc", "Berlin");
	std::cout << std::endl << ouvrage10.reqReferenceFormate() << std::endl;
	ASSERT_EQ("ISBN 0-201-89551-X", ouvrage10.reqIdentifiant());
}

TEST(Ouvrage, ConstructeurInvalideIdentifiant)
{
	ASSERT_THROW(
	        Ouvrage ouvrage("Albert Einstein", "Mein Kampf", annee,"ISSN 0395-2037", "Illuminatis Inc", "Berlin"),
	        ContratException);
}

TEST(Ouvrage, ConstructeurInvalideEditeur)
{
	ASSERT_THROW(
	        Ouvrage ouvrage("Albert Einstein", "Mein Kampf", annee,"ISBN 978-2-1234-5680-3", "", "Berlin"),
	        ContratException);
	ASSERT_THROW(
	        Ouvrage ouvrage("Albert Einstein", "Mein Kampf", annee,"ISBN 978-2-1234-5680-3", "Illum!natis Inc", "Berlin"),
	        ContratException);
}

TEST(Ouvrage, ConstructeurInvalideVille)
{
	ASSERT_THROW(
	        Ouvrage ouvrage("Albert Einstein", "Mein Kampf", annee,"ISBN 978-2-1234-5680-3", "Illuminatis Inc", ""),
	        ContratException);
	ASSERT_THROW(
	        Ouvrage ouvrage("Albert Einstein", "Mein Kampf", annee,"ISBN 978-2-1234-5680-3", "Illuminatis Inc", "Berl!n"),
	        ContratException);
}

class ouvrageTest: public ::testing::Test
{
	public:
		ouvrageTest() :
				ouvrage("Albert Einstein", "Mein Kampf", annee,
				        "ISBN 978-2-1234-5680-3", "Illuminatis Inc", "Berlin")
		{
		}
		Ouvrage ouvrage;
};

TEST_F(ouvrageTest, reqEditeur)
{
	ASSERT_EQ("Illuminatis Inc", ouvrage.reqEditeur());
}

TEST_F(ouvrageTest, reqVille)
{
	ASSERT_EQ("Berlin", ouvrage.reqVille());
}

TEST_F(ouvrageTest, reqReferenceFormate)
{
	ASSERT_EQ(
	        "Albert Einstein. Mein Kampf. Berlin : Illuminatis Inc, 2030. ISBN 978-2-1234-5680-3.",
	        ouvrage.reqReferenceFormate());
}