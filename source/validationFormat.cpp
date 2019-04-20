/**
 * \file validationFormat.cpp
 * \brief Implémentation des fonctions de validation de format
 * \author etudiant
 * \date 2019-02-13
 */

#include "validationFormat.h"
using namespace std;

namespace util
{

	/**
	 * \brief Valide qu'un nom a le bon format.
	 * Valide que le nom est composé de lettres et d'espaces.
	 *
	 * \param[in] p_nom le nom à confirmer
	 *
	 * \return `bool` si le nom est valide ou non
	 *
	 */
	bool validerFormatNom(const std::string& p_nom)
	{
		bool result = true;
		for (char c : p_nom)
		{
			if (!(isalpha(c) || isspace(c)))
			{
				result = false;
				break;
			}
		}

		return result;
	}

	/**
	 * \brief S'assure que le code ISSN est valide.
	 *
	 * Il doit commencer par `"ISSN "`
	 *
	 * \param[in] p_issn un `string`, le code ISSN à valider
	 *
	 * \return `bool` si le code est valide ou non
	 */
	bool validerCodeIssn(const std::string& p_issn)
	{
		bool valide = false;
		if (p_issn.length() == 14 && p_issn.substr(0, 5) == "ISSN "
		        && p_issn[9] == '-')
		{
			bool bonCode = true;
			string strNum = p_issn.substr(5, 4) + p_issn.substr(10, 3);
			for (char c : strNum)
			{
				if (!isdigit(c))
				{
					bonCode = false;
					break;
				}
			}
			if (bonCode)
			{
				char clee = p_issn[13];
				int i = 8, num = 0;
				for (char c : strNum)
				{
					num += (c - 48) * i;
					i--;
				}
				int numMod = num % 11;
				int numClee = 11 - numMod;
				switch (clee)
				{
					case '0':
						if (numClee == 0)
						{
							valide = true;
						}
						break;
					case '1':
						if (numClee == 1)
						{
							valide = true;
						}
						break;
					case '2':
						if (numClee == 2)
						{
							valide = true;
						}
						break;
					case '3':
						if (numClee == 3)
						{
							valide = true;
						}
						break;
					case '4':
						if (numClee == 4)
						{
							valide = true;
						}
						break;
					case '5':
						if (numClee == 5)
						{
							valide = true;
						}
						break;
					case '6':
						if (numClee == 6)
						{
							valide = true;
						}
						break;
					case '7':
						if (numClee == 7)
						{
							valide = true;
						}
						break;
					case '8':
						if (numClee == 8)
						{
							valide = true;
						}
						break;
					case '9':
						if (numClee == 9)
						{
							valide = true;
						}
						break;
					case 'X':
						if (numClee == 10)
						{
							valide = true;
						}
						break;
					default:
						//valide est déjà faux
						break;
				}
			}
		}
		return valide;
	}

	/**
	 *
	 * \brief Valide que le code ISBN est le bon
	 *
	 * \param p_isbn le code ISBN à valider
	 * \return `bool`, si le code est valide ou non
	 */
	bool validerCodeIsbn(const std::string& p_isbn)
	{
		bool valide = false;
		if (p_isbn.substr(0, 5) == "ISBN ")
		{
			if (p_isbn.length() == 18)
			{
				int bonNbr = 0;
				for (char c : p_isbn.substr(5, 13))
				{
					if (c == '-')
						bonNbr++;
				}
				if (bonNbr == 3)
				{
					string strNum = "";
					for (char c : p_isbn.substr(5, 12))
					{
						if (c != '-')
							strNum += c;
					}
					int i = 10, num = 0;
					for (char c : strNum)
					{
						num += (c - 48) * i;
						i--;
					}
					char clee = p_isbn[17];
					int numMod = num % 11;
					int numClee = 11 - numMod;
					switch (clee)
					{
						case '0':
							if (numClee == 0)
							{
								valide = true;
							}
							break;
						case '1':
							if (numClee == 1)
							{
								valide = true;
							}
							break;
						case '2':
							if (numClee == 2)
							{
								valide = true;
							}
							break;
						case '3':
							if (numClee == 3)
							{
								valide = true;
							}
							break;
						case '4':
							if (numClee == 4)
							{
								valide = true;
							}
							break;
						case '5':
							if (numClee == 5)
							{
								valide = true;
							}
							break;
						case '6':
							if (numClee == 6)
							{
								valide = true;
							}
							break;
						case '7':
							if (numClee == 7)
							{
								valide = true;
							}
							break;
						case '8':
							if (numClee == 8)
							{
								valide = true;
							}
							break;
						case '9':
							if (numClee == 9)
							{
								valide = true;
							}
							break;
						case 'X':
							if (numClee == 10)
							{
								valide = true;
							}
							break;
						default:
							//valide est déjà faux
							break;
					}
				}
			}
			else if (p_isbn.length() == 22)
			{
				if (p_isbn[8] == '-' && p_isbn[10] == '-' && p_isbn[15] == '-'
				        && p_isbn[20] == '-')
				{
					string strNum = p_isbn.substr(5, 3) + p_isbn[9]
					        + p_isbn.substr(11, 4) + p_isbn.substr(16, 4);
					int i = 10, num = 0;
					for (char c : strNum)
					{
						num += (c - 48) * (i % 2 == 0 ? 1 : 3);
						i--;
					}
					char clee = p_isbn[21];
					int numMod = num % 10;
					int numClee = numMod == 0 ? 0 : 10 - numMod;
					switch (clee)
					{
						case '0':
							if (numClee == 0)
							{
								valide = true;
							}
							break;
						case '1':
							if (numClee == 1)
							{
								valide = true;
							}
							break;
						case '2':
							if (numClee == 2)
							{
								valide = true;
							}
							break;
						case '3':
							if (numClee == 3)
							{
								valide = true;
							}
							break;
						case '4':
							if (numClee == 4)
							{
								valide = true;
							}
							break;
						case '5':
							if (numClee == 5)
							{
								valide = true;
							}
							break;
						case '6':
							if (numClee == 6)
							{
								valide = true;
							}
							break;
						case '7':
							if (numClee == 7)
							{
								valide = true;
							}
							break;
						case '8':
							if (numClee == 8)
							{
								valide = true;
							}
							break;
						case '9':
							if (numClee == 9)
							{
								valide = true;
							}
							break;
						default:
							//valide est déjà faux
							break;
					}
				}
			}
		}
		return valide;
	}
}  // namespace util
