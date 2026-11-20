/**
 * @file Point2D.h
 * @brief Dichiarazione della struttura e dei metodi per la gestione di un punto in \f$ \mathbb{R}^2 \f$.
 * @author Francesco
 * @date 2026-11-18
 */

#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>

/**
 * @struct Point2D
 * @brief Implementa la gestione di un punto o vettore in \f$ \mathbb{R}^2 \f$.
 * @details Questa struct consente di trattare una coppia di coordinate \f$ (x, y) \f$
 *          come un'unica entità anziché come scalari separati, definendo gli operatori
 *          vettoriali, gli operatori di confronto e il calcolo della norma euclidea.
 *          Si è scelta una struct per garantire accesso diretto e immediato ai campi,
 *          trattandosi di coordinate prive di vincoli di incapsulamento.
 */
struct Point2D {
    double x = 0.0; ///< Coordinata orizzontale x.
    double y = 0.0; ///< Coordinata verticale y.

    /**
     * @brief Costruttore di default che inizializza le coordinate a \f$ (0, 0) \f$.
     */
    Point2D() = default;

    /**
     * @brief Costruttore parametrico che inizializza le coordinate ai valori forniti.
     * @param x_val Valore iniziale per la coordinata x.
     * @param y_val Valore iniziale per la coordinata y.
     */
    Point2D(double x_val, double y_val);

    /**
     * @brief Costruttore di copia.
     * @param p Riferimento costante al punto da cui copiare le coordinate.
     */
    Point2D(const Point2D& p);

    /**
     * @brief Operatore di somma vettoriale.
     * @param other Secondo punto/vettore da sommare.
     * @return Point2D Risultato della somma componente per componente.
     */
    Point2D operator+(const Point2D& other) const;

    /**
     * @brief Operatore di sottrazione vettoriale.
     * @param other Secondo punto/vettore da sottrarre.
     * @return Point2D Risultato della differenza componente per componente.
     */
    Point2D operator-(const Point2D& other) const;

    /**
     * @brief Operatore di prodotto punto per scalare.
     * @param scalar Valore scalare per cui moltiplicare le coordinate.
     * @return Point2D Punto/vettore scalato.
     */
    Point2D operator*(double scalar) const;

    /**
     * @brief Operatore di assegnamento.
     * @param other Punto da cui copiare i valori.
     * @return Point2D& Riferimento all'istanza corrente aggiornata.
     */
    Point2D& operator=(const Point2D& other);

    /**
     * @brief Operatore di confronto maggiore (\p this > \p other).
     * @param other Punto da confrontare.
     * @return bool \c true se la condizione è soddisfatta, \c false altrimenti.
     */
    bool operator>(const Point2D& other) const;

    /**
     * @brief Operatore di confronto minore (\p this < \p other).
     * @param other Punto da confrontare.
     * @return bool \c true se la condizione è soddisfatta, \c false altrimenti.
     */
    bool operator<(const Point2D& other) const;

    /**
     * @brief Operatore di uguaglianza (\p this == \p other).
     * @param other Punto da confrontare.
     * @return bool \c true se le coordinate coincidono, \c false altrimenti.
     */
    bool operator==(const Point2D& other) const;

    /**
     * @brief Calcola la norma euclidea \f$ \lVert v \rVert = \sqrt{x^2 + y^2} \f$.
     * @return double Norma euclidea del punto/vettore.
     */
    double norm() const;
};

/**
 * @brief Moltiplicazione commutativa scalare per punto (\f$ a \cdot \nabla f \f$).
 * @param scalar Scalare moltiplicativo.
 * @param p Punto o vettore gradiente.
 * @return Point2D Prodotto dello scalare per il punto.
 */
Point2D operator*(double scalar, const Point2D& p);

/**
 * @brief Operatore di inserimento su stream per la stampa formattata \f$ (x, y) \f$.
 * @param os Riferimento allo stream di output.
 * @param p Punto da stampare.
 * @return std::ostream& Riferimento allo stream di output aggiornato.
 */
std::ostream& operator<<(std::ostream& os, const Point2D& p);

#endif // POINT2D_H