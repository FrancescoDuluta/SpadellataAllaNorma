#ifndef FUNCTION_1_4_H
#define FUNCTION_1_4_H

#include <string>
#include "Point2D.h"
#include "function.h"

class Function_1 : public function {
/*
 * Funzione 1: f(x, y)=(x^2 + y^2)/2
 * Gradiente: (x, y)
 * Minimo noto: m = 0 in (0, 0)
 */

public:
    double evaluate(const Point2D& p) const override;
    Point2D gradient(const Point2D& p) const override;
    double known_minimum() const override;
    std::string name() const override;

};

class Function_2 : public function {
/*
 * Funzione 2: f(x, y)=(x^2 + 16*y^2)/2
 * Gradiente: (x, 16*y)
 * Minimo noto: m = 0 in (0, 0)
 */

public:
    double evaluate(const Point2D& p) const override;
    Point2D gradient(const Point2D& p) const override;
    double known_minimum() const override;
    std::string name() const override;

};  

class Function_3 : public function {
/* 
 * Funzione 3: f(x, y)=(x^2 - 1)^2 + y^2
 * Gradiente: (4*x*(x^2 - 1), 2*y)
 * Minimo noto: m = 0 in (-1, 0) e (1, 0)
*/
public:
    double evaluate(const Point2D& p) const override;
    Point2D gradient(const Point2D& p) const override;
    double known_minimum() const override;
    std::string name() const override;
};

class Function_4 : public function {
/*
 * Funzione 4: f(x, y)=((x^2 - 1)^2 + ((x - 1)^2)/5 + y^2)
 * Gradiente: (4*x*(x^2 - 1) + 2/5*(x - 1), 2*y)
 * Minimo noto: m = 0 in (1, 0) [minimo locale non assoluto in ~(-0.8873, 0)]
*/
public:
    double evaluate(const Point2D& p) const override;
    Point2D gradient(const Point2D& p) const override;
    double known_minimum() const override;
    std::string name() const override;
};



#endif //FUNCTION_1_4_H