/**
 * @file Point2D.cpp
 * @brief Implementazione della struct Point2D
 * @author Francesco
 * @date 19-11-2026
*/
#include "../include/Point2D.h"
#include <cmath>

// Costruttore parametrico con member initializer list
Point2D::Point2D(double x_val, double y_val) : x(x_val), y(y_val) {}


// Definizione del costruttore di copia 
Point2D::Point2D(const Point2D& p) : Point2D(p.x, p.y) {}

// Somma vettoriale tra due punti/vettori
Point2D Point2D::operator+(const Point2D& other) const {
    return Point2D(x + other.x, y + other.y);
}

// Sottrazione vettoriale (usata nella formula \f$ p_{k+1} = p_k - a * \nabla f(p_k)\f$)
Point2D Point2D::operator-(const Point2D& other) const {
    return Point2D(x - other.x, y - other.y);
}

// Moltiplicazione punto * scalare
Point2D Point2D::operator*(double scalar) const {
    return Point2D(x * scalar, y * scalar);
}

// Assegnamento 
Point2D& Point2D::operator=(const Point2D& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

// Operatore di confronto >
bool Point2D::operator>(const Point2D& other) {
    return std::abs(this->norm()) > std::abs(other.norm());
}

// Operatore di confronto <
bool Point2D::operator<(const Point2D& other) {
    return std::abs(this->norm()) < std::abs(other.norm());
}

// Operatore di confronto ==
bool Point2D::operator==(const Point2D& other) {
    return std::abs(this->norm()) == std::abs(other.norm());
}

// Calcolo della norma euclidea: \f$ \sqrt{x^2 + y^2}\f$
double Point2D::norm() const {
    return std::hypot(x,y);
}

// Moltiplicazione commutativa scalare * punto (funzione libera: senza Point2D::)
Point2D operator*(double scalar, const Point2D& p) {
    return p * scalar;    
}

// Formattazione per la stampa su terminale (funzione libera: senza Point2D::)
std::ostream& operator<<(std::ostream& os, const Point2D& p) {
    os << "( " << p.x << ", " << p.y << " )";
    return os;
}