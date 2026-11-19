#include "Function_1_4.h"
#include <cmath>

// ============================================================================
// Function_1: f(x, y) = (x^2 + y^2) / 2
// ============================================================================

// Calcola il valore numerico della funzione nel punto
double Function_1::evaluate(const Point2D& p) const{

    return ((std::pow(p.x, 2) + std::pow(p.y, 2))/ 2.0);
}

// Calcola il gradiente della funzione nel punto
Point2D Function_1::gradient (const Point2D& p) const{

    return Point2D(p.x, p.y);
}

// Specifica il minimo teorico (riportato nel file di FAMP)
double Function_1::known_minimum() const{

    return 0.0;
}

// Ritorna l'espressione della funzione
std::string Function_1::name() const{

    return "f(x, y) = (x^2 + y^2) / 2";
}


// ============================================================================
// Function_2: f(x, y) = (x^2 + 16y^2) / 2
// ============================================================================

// Calcola il valore numerico della funzione nel punto
double Function_2::evaluate(const Point2D& p) const{

    return ((std::pow(p.x, 2) + 16.0 * std::pow(p.y, 2))/ 2.0);
}

// Calcola il gradiente della funzione
Point2D Function_2::gradient (const Point2D& p) const{

    return Point2D(p.x, 16.0*p.y);
}

// Specifica il minimo teorico (riportato nel file di FAMP)
double Function_2::known_minimum() const{

    return 0.0;
}

// Ritorna l'espressione della funzione
std::string Function_2::name() const{

    return "f(x, y) = (x^2 + 16*y^2) / 2";
}

// ============================================================================
// Function_3: f(x, y) = (x^2 - 1)^2 + y^2
// ============================================================================

// Calcola il valore numerico della funzione nel punto
double Function_3::evaluate(const Point2D& p) const{
    return std::pow((std::pow(p.x, 2) - 1.0), 2) + std::pow(p.y, 2);
}

// Calcola il gradiente della funzione
Point2D Function_3::gradient(const Point2D& p) const{

    return Point2D(4.0 * p.x * (std::pow(p.x, 2) - 1.0), 2.0 * p.y);
}

// Specifica il minimo teorico (riportato nel file di FAMP)
double Function_3::known_minimum() const{
    return 0.0;
}

// Ritorna l'espressione della funzione
std::string Function_3::name() const{
    return "f(x, y) = (x^2 - 1)^2 + y^2";
}

// ============================================================================
// Function_4: f(x, y) = (x^2 - 1)^2 + ((x - 1)^2)/5 + y^2
// ============================================================================

// Calcola il valore numerico della funzione nel punto
double Function_4::evaluate(const Point2D& p) const{
    return std::pow((std::pow(p.x, 2) - 1.0), 2) + (std::pow((p.x - 1.0), 2) / 5) + std::pow(p.y, 2);
}

// Calcola il gradiente della funzione
Point2D Function_4::gradient(const Point2D& p) const{
    return Point2D(4.0 * p.x * (std::pow(p.x, 2) - 1.0) + (2 * (p.x - 1.0)) / 5, 2.0 * p.y);
}

// Specifica il minimo teorico (riportato nel file di FAMP)
double Function_4::known_minimum() const{
    return 0.0;
}

// Ritorna l'espressione della funzione
std::string Function_4::name() const{
    return "f(x, y) = (x^2 - 1)^2 + ((x - 1)^2)/5 + y^2";
}