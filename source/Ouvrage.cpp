/**
 * \file Ouvrage.cpp
 * \brief Implémentation de la classe Ouvrage
 * \author etudiant
 * \version 1.0
 * \date 2019-04-07
 */

#include "Ouvrage.h"
#include "validationFormat.h"
#include <sstream>

namespace biblio
{

	/**
	 * \brief crée un instance de biblio::Ouvrage
	 * \param[in] p_auteurs un string listant les auteurs
	 * \param[in] p_titre le titre de la référence sous forme de string
	 * \param[in] p_annee un int représantant l'année
	 * \param[in] p_identifiant le string de l'identifiant
	 * \param[in] p_editeur le string de l'éditeur
	 * \param[in] p_ville le string de la ville
	 * \pre p_auteurs n'est pas nul et respecte le format donné par util::validerFormatNom()
	 * \pre p_titre n'est pas nul
	 * \pre p_annee est plus grand que 0
	 * \pre n'est pas nul et est un code ISBN valide
	 * \pre p_editeur n'est pas nul et respecte le format donné par util::validerFormatNom()
	 * \pre p_ville n'est pas nul et respecte le format donné par util::validerFormatNom()
	 * \post m_auteurs prend la valeur de p_auteurs
	 * \post m_titre prend la valeur de p_titre
	 * \post m_annee prend la valeur de p_annee
	 * \post m_identifiant prend la valeur de p_identifiant
	 * \post m_editeur prend la valeur de p_editeur
	 * \post m_ville prend la valeur de p_ville
	 */
	Ouvrage::Ouvrage(const std::string& p_auteurs, const std::string& p_titre,
	        int& p_annee, const std::string& p_identifiant,
	        const std::string& p_editeur, const std::string& p_ville) :
			Reference(p_auteurs, p_titre, p_annee, p_identifiant), m_editeur(
			        p_editeur), m_ville(p_ville)
	{
		PRECONDITION(util::validerCodeIsbn(p_identifiant));
		PRECONDITION(!(p_editeur.empty()) && util::validerFormatNom(p_editeur));
		PRECONDITION(!(p_ville.empty()) && util::validerFormatNom(p_ville));

		POSTCONDITION(m_editeur == p_editeur);
		POSTCONDITION(m_ville == p_ville);

		INVARIANTS();
	}

	/**
	 * Retourne l'éditeur de la référence
	 * \return le string de l'éditeur
	 */
	const std::string& Ouvrage::reqEditeur() const
	{
		return m_editeur;
	}

	/**
	 * Retourne la ville de la référence
	 * \return le string de la ville
	 */
	const std::string& Ouvrage::reqVille() const
	{
		return m_ville;
	}

	/**
	 * \brief crée un clone de l'objet
	 * \return un objet de type biblio::Ouvrage qui possède les mêmes propriétés que l'objet initial.
	 */
	Reference* Ouvrage::clone() const
	{
		return new Ouvrage(*this);
	}

	/**
	 * La représentation textuelle de la référence
	 * \return un string sous la forme "m_auteur. m_titre. m_ville : m_editeur, m_annee. m_iditenfiant."
	 */
	std::string Ouvrage::reqReferenceFormate() const
	{
		std::ostringstream oss;
		oss << Reference::reqReferenceFormate() << " " << reqVille() << " : "
		        << reqEditeur() << ", " << reqAnnee() << ". "
		        << reqIdentifiant() << ".";
		return oss.str();
	}

	/**
	 * \brief Vérifie les invariants de la classe
	 */
	void Ouvrage::verifieInvariant() const
	{
		INVARIANT(!(m_editeur.empty()));
		INVARIANT(!(m_ville.empty()));
	}

} // namespace biblio