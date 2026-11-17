#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include "Point2D.h" // La vostra struttura/classe per rappresentare (x, y)

class function {
public:
    // Contratto obbligatorio per ogni funzione matematica
    virtual double evaluate(const Point2D& p) const = 0;
    virtual Point2D gradient(const Point2D& p) const = 0;
    virtual double known_minimum() const = 0;
    virtual std::string name() const = 0;
    
    // Distruttore virtuale: indispensabile quando si usano puntatori alla classe base
    virtual ~function() = default;
};

#endif // FUNCTION_H