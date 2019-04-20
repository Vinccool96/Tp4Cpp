/**
 * \file Journal_Testeur.cpp
 * \brief Fichier test pour la classe Journal
 * \author etudiant
 * \version 1.0
 * \date 2019-04-10
 */

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "Journal.h"

using namespace biblio;

int annee = 2030;
int volume = 30;
int numero = 69;
int page = 420;

TEST(Journal, Constructeur)
{
	Journal journal("Albert Einstein", "Mein Kampf", annee, "ISSN 0395-2037",
	        "Philosophie moderne", volume, numero, page);
	ASSERT_EQ("Philosophie moderne", journal.reqNom());
	ASSERT_TRUE(30 == journal.reqVolume());
	ASSERT_TRUE(69 == journal.reqNumero());
	ASSERT_TRUE(420 == journal.reqPage());
}

TEST(Journal, ConstructeurInvalideISSN)
{
	ASSERT_THROW(
	        Journal journal("Albert Einstein", "Mein Kampf", annee, "ISBN 978-2-1234-5680-3", "Philosophie moderne", volume, numero, page),
	        ContratException);
}

TEST(Journal, ConstructeurInvalideNom)
{
	ASSERT_THROW(
	        Journal journal("Albert Einstein", "Mein Kampf", annee, "ISSN 0395-2037", "", volume, numero, page),
	        ContratException);
	ASSERT_THROW(
	        Journal journal("Albert Einstein", "Mein Kampf", annee, "ISSN 0395-2037", "Ph!losophie moderne", volume, numero, page),
	        ContratException);
}

TEST(Journal, ConstructeurInvalideVolume)
{
	int numInvalide = -1;
	ASSERT_THROW(
	        Journal journal("Albert Einstein", "Mein Kampf", annee, "ISSN 0395-2037", "Philosophie moderne", numInvalide, numero, page),
	        ContratException);
}

TEST(Journal, ConstructeurInvalideNumero)
{
	int numInvalide = -1;
	ASSERT_THROW(
	        Journal journal("Albert Einstein", "Mein Kampf", annee, "ISSN 0395-2037", "Philosophie moderne", volume, numInvalide, page),
	        ContratException);
}

TEST(Journal, ConstructeurInvalidePage)
{
	int numInvalide = -1;
	ASSERT_THROW(
	        Journal journal("Albert Einstein", "Mein Kampf", annee, "ISSN 0395-2037", "Philosophie moderne", volume, numero, numInvalide),
	        ContratException);
}

class journalTest: public ::testing::Test
{
	public:
		journalTest() :
				journal("Albert Einstein", "Mein Kampf", annee,
				        "ISSN 0395-2037", "Philosophie moderne", volume, numero,
				        page)
		{
		}
		Journal journal;
};

TEST_F(journalTest, reqNom)
{
	ASSERT_EQ("Philosophie moderne", journal.reqNom());
}

TEST_F(journalTest, reqVolume)
{
	ASSERT_TRUE(30==journal.reqVolume());
}

TEST_F(journalTest, reqNumero)
{
	ASSERT_TRUE(69==journal.reqNumero());
}

TEST_F(journalTest, reqPage)
{
	ASSERT_TRUE(420==journal.reqPage());
}

TEST_F(journalTest, reqReferenceFormate)
{
	ASSERT_EQ(
	        "Albert Einstein. Mein Kampf. Philosophie moderne, vol. 30, no. 69, pp. 420, 2030. ISSN 0395-2037.",
	        journal.reqReferenceFormate());
}
