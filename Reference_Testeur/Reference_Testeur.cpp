/**
 * \file Reference_Testeur.cpp
 * \brief Fichier test pour la classe Reference
 * \author etudiant
 * \version 1.0
 * \date 2019-04-09
 */

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "Reference.h"

using namespace biblio;

namespace biblio
{
	class ReferenceTest: public Reference
	{
		public:
			ReferenceTest(const std::string& p_auteurs,
			        const std::string& p_titre, int& p_annee,
			        const std::string& p_identifiant) :
					Reference(p_auteurs, p_titre, p_annee, p_identifiant)
			{
			}
			;
			virtual Reference* clone() const
			{
				return new ReferenceTest(*this);

			}
			;
			virtual std::string reqReferenceFormate() const
			{
				std::ostringstream oss;
				oss << Reference::reqReferenceFormate();
				return oss.str();
			}

			;
	};
}

int annee = 2030;

class refTest: public ::testing::Test
{
	public:
		refTest() :
				referenceTest("Albert Einstein", "Mein Kampf", annee,
				        "ISSN 0395-2037")
		{
		}
		ReferenceTest referenceTest;
};

TEST(Reference,ConstructeurDefaut)
{
	ReferenceTest uneRefISSN("Albert Einstein", "Mein Kampf", annee,
	        "ISSN 0395-2037");
	ASSERT_EQ("Albert Einstein", uneRefISSN.reqAuteurs());
	ASSERT_EQ("Mein Kampf", uneRefISSN.reqTitre());
	ASSERT_EQ(annee, uneRefISSN.reqAnnee());
	ASSERT_EQ("ISSN 0395-2037", uneRefISSN.reqIdentifiant());
	ReferenceTest uneRefISBN("Albert Einstein", "Mein Kampf", annee,
	        "ISBN 978-2-1234-5680-3");
	ASSERT_EQ("ISBN 978-2-1234-5680-3", uneRefISBN.reqIdentifiant());
	ReferenceTest uneRefISBN10("Albert Einstein", "Mein Kampf", annee,
	        "ISBN 0-201-89551-X");
	ASSERT_EQ("ISBN 0-201-89551-X", uneRefISBN10.reqIdentifiant());
}

TEST(Reference,ConstructeurInvalideNom)
{
	ASSERT_THROW(
	        ReferenceTest uneRef("", "Mein Kampf", annee, "ISSN 0395-2037"),
	        PreconditionException);
	ASSERT_THROW(
	        ReferenceTest uneRef("Albert Einstein1", "Mein Kampf", annee, "ISSN 0395-2037"),
	        PreconditionException);
}

TEST(Reference,ConstructeurInvalideAnnee)
{
	int anneeInvalide = -230;
	ASSERT_THROW(
	        ReferenceTest uneRef("Albert Einstein", "Mein Kampf", anneeInvalide, "ISSN 0395-2037"),
	        PreconditionException);
}

TEST(Reference,ConstructeurInvalideTitre)
{
	ASSERT_THROW(
	        ReferenceTest uneRef("Albert Einstein", "", annee, "ISSN 0395-2037"),
	        PreconditionException);
}

TEST(Reference,ConstructeurInvalideCode)
{
	ASSERT_THROW(
	        ReferenceTest uneRef("Albert Einstein", "Mein Kampf", annee, "ISSN 0395-2038"),
	        PreconditionException);
	ASSERT_THROW(
	        ReferenceTest uneRef("Albert Einstein", "Mein Kampf", annee, "ISBN 978-2-1234-5780-3"),
	        PreconditionException);
	ASSERT_THROW(
	        ReferenceTest uneRef("Albert Einstein", "Mein Kampf", annee, "ISBN 0-201-89591-X"),
	        PreconditionException);
}

TEST_F(refTest, reqAnnee)
{
	ASSERT_EQ(2030, referenceTest.reqAnnee());
}

TEST_F(refTest, reqAuteurs)
{
	ASSERT_EQ("Albert Einstein", referenceTest.reqAuteurs());
}

TEST_F(refTest, reqTitre)
{
	ASSERT_EQ("Mein Kampf", referenceTest.reqTitre());
}

TEST_F(refTest, reqIdentifiant)
{
	ASSERT_EQ("ISSN 0395-2037", referenceTest.reqIdentifiant());
}

TEST_F(refTest, asgAuteurs)
{
	referenceTest.asgAuteurs("Mark Callaway");
	ASSERT_EQ("Mark Callaway", referenceTest.reqAuteurs());
	ASSERT_THROW(referenceTest.asgAuteurs("DeadMou5e"), PreconditionException);
}

TEST_F(refTest, reqReferenceFormate)
{
	ASSERT_EQ("Albert Einstein. Mein Kampf.",
	        referenceTest.reqReferenceFormate());
}

