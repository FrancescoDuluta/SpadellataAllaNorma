#ifndef FUNZIONI_5_8_H
#define FUNZIONI_5_8_H

#include "Function.h"
#include "Point2D.h"
#include <string>

class Function_5 : public function {
public:
    double evaluate(const Point2D& p) const override;
    Point2D gradient(const Point2D& p) const override;
    double known_minimum() const override;
    std::string name() const override;
};

class Function_6 : public function {
public:
    double evaluate(const Point2D& p) const override;
    Point2D gradient(const Point2D& p) const override;
    double known_minimum() const override;
    std::string name() const override;
};

class Function_7 : public function {
public:
    double evaluate(const Point2D& p) const override;
    Point2D gradient(const Point2D& p) const override;
    double known_minimum() const override;
    std::string name() const override;
};

class Function_8 : public function {
public:
    double evaluate(const Point2D& p) const override;
    Point2D gradient(const Point2D& p) const override;
    double known_minimum() const override;
    std::string name() const override;
};

#endif