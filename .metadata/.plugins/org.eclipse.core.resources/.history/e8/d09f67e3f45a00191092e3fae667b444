/**
 * \file Ouvrage.h
 * \brief Interface de la classe Ouvrage
 * \author etudiant
 * \version 1.0
 * \date 2019-04-07
 */

#ifndef OUVRAGE_H_
#define OUVRAGE_H_

#include "Reference.h"

#include <string>

namespace biblio
{
	/**
	 * \class Ouvrage
	 * \brief Classe permettant d'implémenter le concept de référence bibliographique d'un ouvrage
	 *
	 * Attributs:
	 * 		string 	m_auteurs: 		Le ou les auteurs de la référence
	 * 		string 	m_titre:		Le titre de la référence
	 * 		int 	m_annee:		L'année de publication de la référence
	 * 		string 	m_identifiant	Le code d'identification de la référence, soit le code ISBN
	 * 		string 	m_etiteur: 		Le nom de l'éditeur de l'ouvrage
	 * 		string 	m_titre:		La ville d’édition de l’ouvrage
	 */
	class Ouvrage: public Reference
	{
		public:
			Ouvrage(const std::string& p_auteurs, const std::string& p_titre,
			        int& p_annee, const std::string& p_identifiant,
			        const std::string& p_editeur, const std::string& p_ville);
			const std::string& reqEditeur() const;
			const std::string& reqVille() const;
			virtual Reference* clone() const;
			virtual std::string reqReferenceFormate() const;
		private:
			std::string m_editeur;
			std::string m_ville;
			void verifieInvariant() const;
	};
} // namespace biblio

#endif /* OUVRAGE_H_ */
