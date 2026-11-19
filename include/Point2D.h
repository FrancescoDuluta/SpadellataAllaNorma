/**
 * @file Point2D.h
 * @brief Dichiarazione della classe e dei metodi per la gestione di un punto in \mathbb{R}^2.
 * @author Francesco
 * @date 2026-11-18
 */
#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>

/**
 * @struct Point2D
 * @brief Implementa la gestione di un punto in $\mathbb{R}^2$.
 * 
 * Questa struct gestisce la facilitazione implementativa per poter trattare un punto
 * del piano $x,y$ come unica istanza e non come coordinate separate. Questo ovviamente
 * implica la definizione di alcuni operatori e di un metodo che calcola la norma.
 * Abbiamo scelto una struct per questione di facilità di accesso alle variabili dato che 
 * non contiene nulla di così pericoloso da perdere.
 */
struct Point2D {
    double x = 0.0;     ///< Coordinata orizzontale x.
    double y = 0.0;     ///< Coordinata verticale y.

    /**
     * @brief Costruttore vuoto.
     * Costruttore vuoto che inizializza i valori a 0.
     */
    Point2D() = default;

    /**
     * @brief Costruttore completo.
     * Costruttore completo che inizializza i valori a quelli scelti.
     * @param x_val Valore per la coordinata x.
     * @param y_val Valore per la coordinata y.
     */
    Point2D(double x_val, double y_val);

            
    /**
     * @brief Costruttore di copia
     * @param p Riferimento del punto di cui copiare gli attributi
     */
    Point2D(const Point2D& p);

    /**
     * @brief Operatore di somma.
     * @param other Un secondo Point2D su cui fare la somma.
     * @return Point2D Il punto costituito dalla somma delle coordinate.
     */
    Point2D operator+(const Point2D& other) const;
    
    /**
     * @brief Operatore di sottrazione.
     * @param other Un secondo Point2D su cui fare la sottrazione.
     * @return Point2D Il punto costituito dalla differenza tra le coordinate.
     */
    Point2D operator-(const Point2D& other) const;
    
    /**
     * @brief Operatore di prodotto con scalare.
     * @param scalar Uno scalare con cui moltiplicare le coordinate.
     * @return Point2D Il punto costituito dal prodotto delle coordinate per lo scalare.
     */
    Point2D operator*(double scalar) const;
    
    /**
     * @brief Operatore di assegnamento.
     * @param other Un secondo Point2D da cui copiare i valori.
     * @return Point2D Il punto costituito dalla copia del secondo punto Point2D.
     */
    Point2D& operator=(const Point2D& other);

    /**
     * @brief Confronto maggiore tra punti (se this > other) 
     * @param other Punto Point2D da confrontare se è minore del punto this
     * @return bool Il risultato dell'operazione di confronto
     */
    bool operator>(const Point2D& other);

    /**
     * @brief Confronto minore tra punti (se this < other) 
     * @param other Punto Point2D da confrontare se è maggiore del punto this
     * @return bool Il risultato dell'operazione di confronto
     */
    bool operator<(const Point2D& other);

    /**
     * @brief Confronto == tra punti (se this == other) 
     * @param other Punto Point2D da confrontare se è uguale al punto this
     * @return bool Il risultato dell'operazione di confronto
     */
    bool operator==(const Point2D& other);

    // Norma euclidea ||v||
    /**
     * @brief Norma euclidea $\lVert\lVert v \rVert\rVert$.
     * @return double La distanza delle coordinate dall'origine mediante il Teorema di Pitagora.
     */
    double norm() const;
};

/**
 * @brief Moltiplicazione commutativa: permette di scrivere (a * gradiente).
 * @param scalar Scalare a.
 * @param p Punto Point2D che in questo caso sarà il gradiente.
 * @return Point2D Il prodotto dello scalare per il gradiente.
 */
Point2D operator*(double scalar, const Point2D& p);

/**
 * @brief Stampa formattata su terminale: es. (x, y).
 * @param os Il riferimento all'oggetto dell'output stream della classe std.
 * @param p Il punto Point2D di cui voglio stampare le coordinate (x,y).
 * return std::ostream& Il riferimento all'oggetto output stream della classe standard.
 */
std::ostream& operator<<(std::ostream& os, const Point2D& p);

#endif // Point2D_H