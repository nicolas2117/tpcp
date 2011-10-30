#ifndef SYMBOLE
#define SYMBOLE

/**
 * @file Symbole.hpp
 * @brief Fichier qui contient la définition de la classe symbole.
 * @author Nicolas CHARREL
 */

/**
 * @brief Liste des catégories.
 */
typedef enum {
    CATEGORIE_CONSTANTE = 0,
    CATEGORIE_ETIQUETTE,
    CATEGORIE_FONCTION,
    CATEGORIE_PARAMETRE,
    CATEGORIE_PROCEDURE,
    CATEGORIE_PROGRAMME,
    CATEGORIE_TEMPORAIRE,
    CATEGORIE_TYPE,
    CATEGORIE_VARIABLE
} Categorie;

/**
 * @brief Classe Symbole.
 */
class Symbole
{
	private:
        int id; /**< id du symbole. */
        Categorie categorie;  /**< categorie du symbole */

	public:
        /**
         * @brief Constructeur.
         * @param id id du symbole.
         * @param categorie Categorie du symbole.
         */
        Symbole(int id, Categorie categorie);

        /**
         * @brief Retourne l'id du symbole.
         * @return L'id du symbole.
         */
        int getId();

        /**
         * @brief Retourne la categorie du symbole.
         * @return La categorie du symbole.
         */
        Categorie getCategorie();
};

#endif
