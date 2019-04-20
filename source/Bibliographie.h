/**
 * \file Bibliographie.h
 * \brief Interface de la classe Bibliographie
 * \author etudiant
 * \version 1.0
 * \date 2019-04-10
 */

#ifndef BIBLIOGRAPHIE_H_
#define BIBLIOGRAPHIE_H_

#include "Reference.h"

#include <string>
#include <vector>

namespace biblio
{

	/**
	 * \class biblio::Bibliographie
	 * \brief classe permettant d'implémenter le concept de bibliographie
	 * Attributs:
	 * 		string	m_nom:	Le nom de la bibliographie s'affichant en haut
	 */
	class Bibliographie
	{
		public:
			Bibliographie(const std::string& p_nom);
			~Bibliographie();
			void ajouterReference(const Reference& p_nouvelleReference);
			std::string reqBibliographieFormate() const;
			const std::string& reqNom() const;
		private:
			std::string m_nom;
			std::vector<Reference*> m_vReferences;
			bool referenceEstDejaPresente(const std::string& p_identifiant) const;
			void verifieInvariant() const;
	};

}  // namespace biblio

#endif /* BIBLIOGRAPHIE_H_ */

