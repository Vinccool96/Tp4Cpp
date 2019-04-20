/**
 * \file Bibliographie.cpp
 * \brief Implémentation de la classe Bibliographie
 * \author etudiant
 * \version 1.0
 * \date 2019-04-10
 */
#include "Bibliographie.h"
#include "ContratException.h"

#include <sstream>
#include <vector>

namespace biblio
{

	/**
	 * \brief crée un instance de biblio::Bibliographie
	 * \param[in] p_nom le nom de le bibliographie
	 * \pre p_nom n'est pas vide
	 * \post m_nom prend la valeur de p_nom
	 * \post m_vReferences est vide
	 */
	Bibliographie::Bibliographie(const std::string& p_nom) :
			m_nom(p_nom)
	{
		PRECONDITION(!(p_nom.empty()));

		POSTCONDITION(m_nom == p_nom);
		POSTCONDITION(m_vReferences.empty());
		INVARIANTS();
	}

	/**
	 * \brief destructeur
	 */
	Bibliographie::~Bibliographie()
	{
		m_vReferences.clear();
		std::vector<Reference*>(m_vReferences).swap(m_vReferences);
	}

	/**
	 * \brief ajoute une référence à la bibliographie
	 * \param[in] p_nouvelleReference
	 * \pre p_nouvelleReference n'est pas dans la bibliographie
	 * \post p_nouvelleReference est dans la bibliographie
	 */
	void Bibliographie::ajouterReference(const Reference& p_nouvelleReference)
	{
		Reference* ref = p_nouvelleReference.clone();
		PRECONDITION(!(referenceEstDejaPresente(ref->reqIdentifiant())));
		m_vReferences.push_back(ref);
		POSTCONDITION(referenceEstDejaPresente(ref->reqIdentifiant()));
		INVARIANTS();
	}

	/**
	 * La représentation textuelle de la bibliographie
	 * \return un string sous la forme:
	 * ```
	 * m_nom
	 * ===============================
	 * [1] ref1.reqReferenceFormate()
	 * [2] ref2.reqReferenceFormate()
	 * ...
	 * [n] refn.reqReferenceFormate()
	 * ```
	 */
	std::string Bibliographie::reqBibliographieFormate() const
	{
		std::ostringstream oss;
		oss << reqNom() << "\n" << "===============================";
		for (unsigned int i = 1; i <= m_vReferences.size(); i++)
		{
			oss << "\n[" << i << "] "
			        << m_vReferences[i - 1]->reqReferenceFormate() << "";
		}
		return oss.str();
	}

	/**
	 * \brief vérifie si la référence est présente dans la bibliographie en vérifiant si l'identifiant
	 * appartient déjà à une des références de la bibliographie.
	 * \param[in] p_identifiant le string de ll'identifiant de la référence à vérifier.
	 * @return
	 */
	bool Bibliographie::referenceEstDejaPresente(
	        const std::string& p_identifiant) const
	{
		bool resultat = false;
		for (Reference* ref : m_vReferences)
		{
			if (p_identifiant == ref->reqIdentifiant())
			{
				resultat = true;
				break;
			}
		}
		return resultat;
	}

	/**
	 * Retourne le nom de la bibliographie
	 * \return le string du nom
	 */
	const std::string& Bibliographie::reqNom() const
	{
		return m_nom;
	}

	/**
	 * \brief Vérifie les invariants de la classe
	 */
	void Bibliographie::verifieInvariant() const
	{
		INVARIANT(!(m_nom.empty()));
	}

}  // namespace biblio