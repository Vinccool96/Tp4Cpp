/**
 * \file Reference.h
 * \brief Interface de la classe Reference
 * \author etudiant
 * \version 2.0
 * \date 2019-02-26
 */

#ifndef REFERENCE_H_
#define REFERENCE_H_

#include "ContratException.h"

#include <string>

namespace biblio
{

	/**
	 * \class Reference
	 * \brief Classe implémentant le concept de référence bibliographique
	 *
	 * La classe Reference permet d'implanter le concept de référence bibliographique utilisée dans un ouvrage
	 *
	 * Attributs:
	 * 		string 	m_auteurs: 		Le ou les auteurs de la référence
	 * 		string 	m_titre:		Le titre de la référence
	 * 		int 	m_annee:		L'année de publication de la référence
	 * 		string 	m_identifiant	Le code d'identification de la référence, soit un code ISSN, soit le code ISBN
	 */
	class Reference
	{
		public:
			Reference(const std::string& p_auteurs, const std::string& p_titre,
			        int& p_annee, const std::string& p_identifiant);
			virtual ~Reference(){};
			const int reqAnnee() const;
			const std::string& reqAuteurs() const;
			void asgAuteurs(const std::string& p_auteurs);
			const std::string& reqIdentifiant() const;
			const std::string& reqTitre() const;
			virtual Reference* clone() const=0;
			virtual std::string reqReferenceFormate() const=0;
		private:
			std::string m_auteurs;
			std::string m_titre;
			int m_annee;
			std::string m_identifiant;
			void verifieInvariant() const;
	};
} // namespace biblio

#endif /* REFERENCE_H_ */