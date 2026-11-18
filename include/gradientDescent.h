#ifndef GRADIENTDESCENT_H
#define GRADIENTDESCENT_H

#include "Function.h"

/*
Dovrà prevedere la memorizzazione dei parametri di esecuzione (passo $a$, massimo iterazioni $N$,
tolleranza $\overline{T}$) e un metodo pubblico di risoluzione che riceva una const Function& e 
il punto iniziale $p_0$.
*/

class GradientDescent {
    public:
        GradientDescent(double step_size, int max_iterations, double tolerance);
        void set_step_size(double a);
        DescentResult solve(const Function& func, const Point2D& initial_point) const;
    private:
        double step_size;      // il passo costante a
        int max_iterations;    // il numero massimo di iterazioni N
        double tolerance;      // la soglia T sulla norma del gradiente
};

struct DescentResult {
    Point2D final_point; 
    double final_value; 
    int iterations; 
    bool converged;
};

#endif