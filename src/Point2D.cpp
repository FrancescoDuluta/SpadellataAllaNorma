/**
 * @file Point2D.cpp
 * @brief Implementaione della struct Point2D
 * @author Francesco
 * @date 19-11-2026
*/
#include "../include/Point2D.h"
#include <cmath>

// Costruttore parametrico con member initializer list
Point2D::Point2D(double x_val, double y_val) : x(x_val), y(y_val) {}

// Somma vettoriale tra due punti/vettori
Point2D Point2D::operator+(const Point2D& other) const {
    return Point2D(x + other.x, y + other.y);
}

// Sottrazione vettoriale (usata nella formula p_{k+1} = p_k - a * gradiente)
Point2D Point2D::operator-(const Point2D& other) const {
    return Point2D(x - other.x, y - other.y);
}

// Moltiplicazione punto * scalare
Point2D Point2D::operator*(double scalar) const {
    return Point2D(x * scalar, y * scalar);
}

// Assegnamento 
Point2D Point2D::operator=(const Point2D& other) const {
    return Point2D(other.x, other.y);
}

// Calcolo della norma euclidea: sqrt(x^2 + y^2)[cite: 2]
double Point2D::norm() const {
    return std::hypot(x,y);
}

// Moltiplicazione commutativa scalare * punto (funzione libera: senza Point2D::)
Point2D operator*(double scalar, const Point2D& p) {
    return p * scalar;    
}

// Formattazione per la stampa su terminale (funzione libera: senza Point2D::)
std::ostream& operator<<(std::ostream& os, Point2D& p) {
    os << "( " << p.x << ", " << p.y << " )";
    return os;
}