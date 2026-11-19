#include "../include/funzioni_5_8.h"
#include <cmath>

constexpr double PI = 3.14159265358979323846;



// ----------------------------------------------
// Function 5: f5(x, y) = 4 * sinh^2(x / 2) + y^2
// ----------------------------------------------

// calcolo il risultato della funzione 5
double Function_5::evaluate(const Point2D& p) const {

    // aggiungo la variabile 's' per semplificare la scrittura del return
    double s = std::sinh(p.x / 2.0);
    return 4.0 * s * s + p.y * p.y;
}

// calcolo del gradiente per la funzione 5
Point2D Function_5::gradient(const Point2D& p) const {
    double dx = 4.0 * std::sinh(p.x / 2.0) * std::cosh(p.x / 2.0);
    double dy = 2.0 * p.y;
    return Point2D(dx, dy);
}

// minimo teorico specificato nel file della Caravenna, sempre zero
double Function_5::known_minimum() const {
    return 0.0;
}

std::string Function_5::name() const {
    return "f5(x, y) = 4*sinh^2(x/2) + y^2";
}



// ----------------------------------------------
// Function 6: ln(1 + x^2 + y^2)
// ----------------------------------------------

// calcolo il risultato della funzione 6
double Function_6::evaluate(const Point2D& p) const {
    return std::log(1.0 + p.x * p.x + p.y * p.y);
}

// Calcolo del gradiente per la funzione 6
Point2D Function_6::gradient(const Point2D& p) const {
    double dx = 2.0 * p.x / (1.0 + p.x * p.x + p.y * p.y);
    double dy = 2.0 * p.y / (1.0 + p.x * p.x + p.y * p.y);
    return Point2D(dx, dy);
}

// minimo teorico specificato nel file della Caravenna, sempre zero
double Function_6::known_minimum() const {
    return 0.0;
}

std::string Function_6::name() const {
    return "f6(x,y) = log(1 + y^2 + x^2)";
}



// ----------------------------------------------
// Function 7: f7(x, y) = 1 - exp(-(x^2 + y^2))
// ----------------------------------------------

// calcolo il risultato della funzione 7
double Function_7::evaluate(const Point2D& p) const {
    return 1.0 - std::exp(-(p.x * p.x + p.y * p.y));
}

// calcolo del gradiente per la funzione 7
Point2D Function_7::gradient(const Point2D& p) const {
    double dx = 2.0 * p.x * std::exp(-(p.x * p.x + p.y * p.y));
    double dy = 2.0 * p.y * std::exp(-(p.x * p.x + p.y * p.y));
    return Point2D(dx, dy);
}

// minimo teorico specificato nel file della Caravenna, sempre zero
double Function_7::known_minimum() const {
    return 0.0;
}

std::string Function_7::name() const {
    return "f7(x,y) = 1 - exp(-(x^2 + y^2))";
}



// ----------------------------------------------
// Function 8: f8(x,y) = 2 - cos(PI * x) - cos(PI * y)
// ----------------------------------------------

// calcolo il risultato della funzione 8
double Function_8::evaluate(const Point2D& p) const {
    return 2.0 - std::cos(PI * p.x) - std::cos(PI * p.y);
}

// calcolo del gradiente per la funzione 8
Point2D Function_8::gradient(const Point2D& p) const {
    double dx = PI * std::sin(PI * p.x);
    double dy = PI * std::sin(PI * p.y);
    return Point2D(dx, dy);
}

// minimo teorico specificato nel file di FAMP, sempre zero
double Function_8::known_minimum() const {
    return 0.0;
}

std::string Function_8::name() const {
    return "f8(x,y) = 2 - cos(PI * x) - cos(PI * y)";
}