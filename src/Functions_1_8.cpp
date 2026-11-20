/**
 * @file Functions_1_8.cpp
 * @brief Implementazione delle otto funzioni di test (f1 - f8) derivate dalla classe astratta Function.
 * @details Accorpa in un unico modulo le implementazioni di Lorenzo (f1 - f4) e Denis (f5 - f8),
 *          fornendo valutazione scalare, gradiente analitico, punto di minimo noto e nome identificativo.
 * @authors Francesco, Lorenzo, Denis
 * @date 20-11-2026
 */

#include "../include/Functions_1_8.h"
#include <cmath>

/// Costante pi greco ad alta precisione utilizzata nelle funzioni trigonometriche
constexpr double PI = 3.14159265358979323846;

// ============================================================================
// Function_1: f1(x, y) = (x^2 + y^2) / 2
// ============================================================================

// Calcola il valore scalare della funzione f1 nel punto p
double Function_1::evaluate(const Point2D& p) const {
    return ((std::pow(p.x, 2) + std::pow(p.y, 2))/ 2.0);
}

// Calcola il vettore gradiente analitico (x, y) nel punto p
Point2D Function_1::gradient (const Point2D& p) const {
    return Point2D(p.x, p.y);
}

// Restituisce il punto di minimo analitico noto (0, 0), dove m = 0
Point2D Function_1::known_minimum() const {
    return Point2D();
}

// Restituisce l'espressione analitica identificativa della funzione
std::string Function_1::name() const {
    return "f(x, y) = (x^2 + y^2) / 2";
}

// ============================================================================
// Function_2: f2(x, y) = (x^2 + 16y^2) / 2
// ============================================================================

// Calcola il valore scalare della funzione f2 nel punto p
double Function_2::evaluate(const Point2D& p) const {
    return ((std::pow(p.x, 2) + 16.0 * std::pow(p.y, 2))/ 2.0);
}

// Calcola il vettore gradiente analitico (x, 16y) nel punto p
Point2D Function_2::gradient (const Point2D& p) const {
    return Point2D(p.x, 16.0*p.y);
}

// Restituisce il punto di minimo analitico noto (0, 0), dove m = 0
Point2D Function_2::known_minimum() const {
    return Point2D();
}

// Restituisce l'espressione analitica identificativa della funzione
std::string Function_2::name() const {
    return "f(x, y) = (x^2 + 16*y^2) / 2";
}

// ============================================================================
// Function_3: f3(x, y) = (x^2 - 1)^2 + y^2
// ============================================================================

// Calcola il valore scalare della funzione f3 nel punto p
double Function_3::evaluate(const Point2D& p) const {
    return std::pow((std::pow(p.x, 2) - 1.0), 2) + std::pow(p.y, 2);
}

// Calcola il vettore gradiente analitico (4x(x^2 - 1), 2y) nel punto p
Point2D Function_3::gradient(const Point2D& p) const {
    return Point2D(4.0 * p.x * (std::pow(p.x, 2) - 1.0), 2.0 * p.y);
}

// Restituisce il punto di minimo analitico noto (m = 0)
Point2D Function_3::known_minimum() const {
    return Point2D();
}

// Restituisce l'espressione analitica identificativa della funzione
std::string Function_3::name() const {
    return "f(x, y) = (x^2 - 1)^2 + y^2";
}

// ============================================================================
// Function_4: f4(x, y) = (x^2 - 1)^2 + ((x - 1)^2) / 5 + y^2
// ============================================================================

// Calcola il valore scalare della funzione f4 nel punto p
double Function_4::evaluate(const Point2D& p) const {
    return std::pow((std::pow(p.x, 2) - 1.0), 2) + (std::pow((p.x - 1.0), 2) / 5) + std::pow(p.y, 2);
}

// Calcola il vettore gradiente analitico (4x(x^2 - 1) + 2(x - 1)/5, 2y) nel punto p
Point2D Function_4::gradient(const Point2D& p) const {
    return Point2D(4.0 * p.x * (std::pow(p.x, 2) - 1.0) + (2 * (p.x - 1.0)) / 5, 2.0 * p.y);
}

// Restituisce il punto di minimo analitico noto (m = 0)
Point2D Function_4::known_minimum() const {
    return Point2D();
}

// Restituisce l'espressione analitica identificativa della funzione
std::string Function_4::name() const {
    return "f(x, y) = (x^2 - 1)^2 + ((x - 1)^2)/5 + y^2";
}

// ============================================================================
// Function_5: f5(x, y) = 4 * sinh^2(x / 2) + y^2
// ============================================================================

// Calcola il valore scalare della funzione f5 tramite seno iperbolico std::sinh
double Function_5::evaluate(const Point2D& p) const {
    // Variabile di appoggio per evitare il doppio calcolo del seno iperbolico
    double s = std::sinh(p.x / 2.0);
    return 4.0 * s * s + p.y * p.y;
}

// Calcola il vettore gradiente analitico (4*sinh(x/2)*cosh(x/2), 2y) nel punto p
Point2D Function_5::gradient(const Point2D& p) const {
    double dx = 4.0 * std::sinh(p.x / 2.0) * std::cosh(p.x / 2.0);
    double dy = 2.0 * p.y;
    return Point2D(dx, dy);
}

// Restituisce il punto di minimo analitico noto (0, 0), dove m = 0
Point2D Function_5::known_minimum() const {
    return Point2D();
}

// Restituisce l'espressione analitica identificativa della funzione
std::string Function_5::name() const {
    return "f5(x, y) = 4*sinh^2(x/2) + y^2";
}

// ============================================================================
// Function_6: f6(x, y) = ln(1 + x^2 + y^2)
// ============================================================================

// Calcola il valore scalare della funzione f6 tramite logaritmo naturale std::log
double Function_6::evaluate(const Point2D& p) const {
    return std::log(1.0 + p.x * p.x + p.y * p.y);
}

// Calcola il vettore gradiente analitico (2x / (1 + x^2 + y^2), 2y / (1 + x^2 + y^2))
Point2D Function_6::gradient(const Point2D& p) const {
    double dx = 2.0 * p.x / (1.0 + p.x * p.x + p.y * p.y);
    double dy = 2.0 * p.y / (1.0 + p.x * p.x + p.y * p.y);
    return Point2D(dx, dy);
}

// Restituisce il punto di minimo analitico noto (0, 0), dove m = 0
Point2D Function_6::known_minimum() const {
    return Point2D();
}

// Restituisce l'espressione analitica identificativa della funzione
std::string Function_6::name() const {
    return "f6(x,y) = log(1 + y^2 + x^2)";
}

// ============================================================================
// Function_7: f7(x, y) = 1 - exp(-(x^2 + y^2))
// ============================================================================

// Calcola il valore scalare della funzione f7 tramite esponenziale std::exp
double Function_7::evaluate(const Point2D& p) const {
    return 1.0 - std::exp(-(p.x * p.x + p.y * p.y));
}

// Calcola il vettore gradiente analitico (2x * exp(-(x^2 + y^2)), 2y * exp(-(x^2 + y^2)))
Point2D Function_7::gradient(const Point2D& p) const {
    double dx = 2.0 * p.x * std::exp(-(p.x * p.x + p.y * p.y));
    double dy = 2.0 * p.y * std::exp(-(p.x * p.x + p.y * p.y));
    return Point2D(dx, dy);
}

// Restituisce il punto di minimo analitico noto (0, 0), dove m = 0
Point2D Function_7::known_minimum() const {
    return Point2D();
}

// Restituisce l'espressione analitica identificativa della funzione
std::string Function_7::name() const {
    return "f7(x,y) = 1 - exp(-(x^2 + y^2))";
}

// ============================================================================
// Function_8: f8(x, y) = 2 - cos(pi * x) - cos(pi * y)
// ============================================================================

// Calcola il valore scalare della funzione f8 tramite coseno std::cos
double Function_8::evaluate(const Point2D& p) const {
    return 2.0 - std::cos(PI * p.x) - std::cos(PI * p.y);
}

// Calcola il vettore gradiente analitico (pi * sin(pi * x), pi * sin(pi * y))
Point2D Function_8::gradient(const Point2D& p) const {
    double dx = PI * std::sin(PI * p.x);
    double dy = PI * std::sin(PI * p.y);
    return Point2D(dx, dy);
}

// Restituisce il punto di minimo analitico noto nell'origine (0, 0), dove m = 0
Point2D Function_8::known_minimum() const {
    return Point2D();
}

// Restituisce l'espressione analitica identificativa della funzione
std::string Function_8::name() const {
    return "f8(x,y) = 2 - cos(PI * x) - cos(PI * y)";
}