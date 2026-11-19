/**
 * @file GradientDescent.cpp
 * @brief Implementaione della classe GradientDescent
 * @author Francesco
 * @date 19-11-2026
*/
#include "../include/GradientDescent.h"
#include <iostream>

/*
    Definizione del costruttore di GradientDescent: inizializzare gli attributi privati 
    (passo a, iterazioni massime N, soglia T) tramite member initializer list
*/

GradientDescent::GradientDescent(double step_size, int max_iterations, double tolerance) :
    step_size(step_size), max_iterations(max_iterations), tolerance(tolerance)  {}

// Definizione del metodo set_step_size necessario per cambiare la dimensione del passo a
void GradientDescent::set_step_size(double step_size) {
    this->step_size = step_size;
}

/*
*/
void print_status(int k, double norm, double funcVal, double error) {
    std::cout << "k: " << k << "\tpunto p_k: " << norm << "\tvalore f(p_k)" << funcVal <<
                "\terrore e_k: " << error << std::endl;
}

/*
*/
DescentResult GradientDescent::solve(const Function& func, const Point2D& initial_point) const {
    Point2D current_point = initial_point;
    int k = 0;
    bool converged = false;
    Point2D gradient = Point2D();
    double norm = 0.0; double funcVal = 0.0; double error = 0.0;
    while(true) {
        gradient = func.gradient(current_point);
        norm = gradient.norm();
            if(std::isnan(norm) || std::isinf(norm)) {
                std::cout << "Errore: divergenza trovata nel calcolo della norma! " << std::endl;
                break;
            }
        funcVal = func.evaluate(current_point);
            if(std::isnan(funcVal) || std::isinf(funcVal)) {
                std::cout << "Errore: divergenza trovata nel calcolo del valore della funzione in p_k! " << std::endl;
                break;
            } 
        error = funcVal - func.evaluate(func.known_minimum());
        
        // Controllo criterio di arresto 1: ||grad(f(p_k))|| < soglia T
        if(norm < tolerance) converged = true;

        // Controllo criterio di arresto 2: k ha raggiunto il numero massimo di iterazioni N
        if(norm < tolerance || k >= max_iterations) break;

        /*  
            Stampa dello stato al punto corrente (ogni 10 iterazioni): 
            (punto finale p_E, valore f(p_E), iterazioni effettuate k, esito della convergenza)
        */
        if(k % 10 == 0) print_status(k, norm, funcVal, error);

        current_point = gradient - step_size * gradient;    // Aggiornamento al nuovo punto (p_k+1)        
        k++;    // Incremento k
    }
    return {gradient, funcVal, k, converged};   //Restituisco il valore finale trovato come tipo DescentResult
}