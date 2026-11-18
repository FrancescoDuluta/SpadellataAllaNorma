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
    double x = 0.0;
    double y = 0.0;

    Point2D() = default;
    Point2D(double x_val, double y_val);

    // Operazioni vettoriali
    Point2D operator+(const Point2D& other) const;
    Point2D operator-(const Point2D& other) const;
    Point2D operator*(double scalar) const;
    Point2D operator=(const Point2D& other) const;

    // Norma euclidea ||v||
    double norm() const;
};

// Moltiplicazione commutativa: permette di scrivere (a * gradiente)
Point2D operator*(double scalar, const Point2D& p);

// Stampa formattata su terminale: es. (x, y)
std::ostream& operator<<(std::ostream& os, const Point2D& p);

#endif // Point2D_H