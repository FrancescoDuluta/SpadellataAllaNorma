/**
 * @file Point2D.cpp
 * @brief Implementazione della struct Point2D.
 * @author Francesco
 * @date 19-11-2026
 */

#include "../include/Point2D.h"
#include <cmath>

// Costruttore parametrico con member initializer list
Point2D::Point2D(double x_val, double y_val) : x(x_val), y(y_val) {}

// Definizione del costruttore di copia tramite delega
Point2D::Point2D(const Point2D& p) : Point2D(p.x, p.y) {}

// Somma vettoriale tra due punti/vettori
Point2D Point2D::operator+(const Point2D& other) const {
    return Point2D(x + other.x, y + other.y);
}

// Sottrazione vettoriale (usata nella formula p_{k+1} = p_k - a * grad(f(p_k)))
Point2D Point2D::operator-(const Point2D& other) const {
    return Point2D(x - other.x, y - other.y);
}

// Moltiplicazione punto * scalare
Point2D Point2D::operator*(double scalar) const {
    return Point2D(x * scalar, y * scalar);
}

// Operatore di assegnamento
Point2D& Point2D::operator=(const Point2D& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

// Operatore di confronto > basato sulla distanza euclidea dall'origine
bool Point2D::operator>(const Point2D& other) const {
    return this->norm() > other.norm();
}

// Operatore di confronto < basato sulla distanza euclidea dall'origine
bool Point2D::operator<(const Point2D& other) const {
    return this->norm() < other.norm();
}

// Operatore di confronto == basato sulla coincidenza delle coordinate
bool Point2D::operator==(const Point2D& other) const {
    return (x == other.x) && (y == other.y);
}

// Calcolo della norma euclidea: sqrt(x^2 + y^2)
double Point2D::norm() const {
    return std::hypot(x, y);
}

// Moltiplicazione commutativa scalare * punto (funzione libera)
Point2D operator*(double scalar, const Point2D& p) {
    return p * scalar;
}

// Formattazione per la stampa su terminale (funzione libera)
std::ostream& operator<<(std::ostream& os, const Point2D& p) {
    os << "( " << p.x << ", " << p.y << " )";
    return os;
}