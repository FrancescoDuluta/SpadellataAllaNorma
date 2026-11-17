#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>

struct Point2D {
    double x = 0.0;
    double y = 0.0;

    Point2D() = default;
    Point2D(double x_val, double y_val);

    // Operazioni vettoriali
    Point2D operator+(const Point2D& other) const;
    Point2D operator-(const Point2D& other) const;
    Point2D operator*(double scalar) const;

    // Norma euclidea ||v||
    double norm() const;
};

// Moltiplicazione commutativa: permette di scrivere (a * gradiente)
Point2D operator*(double scalar, const Point2D& p);

// Stampa formattata su terminale: es. (x, y)
std::ostream& operator<<(std::ostream& os, const Point2D& p);

#endif // Point2D_H