/**
 * @file GradientDescent.cpp
 * @brief Implementazione della classe GradientDescent e delle funzioni ausiliarie di stampa.
 * @author Francesco
 * @date 19-11-2026
 */

#include "../include/GradientDescent.h"
#include <iostream>
#include <cmath>

// Definizione del costruttore parametrico tramite member initializer list
GradientDescent::GradientDescent(double step_size, int max_iterations, double tolerance) :
    step_size(step_size), max_iterations(max_iterations), tolerance(tolerance) {}

// Aggiorna la lunghezza del passo costante 'a'
void GradientDescent::set_step_size(double step_size) {
    this->step_size = step_size;
}

// Stampa su terminale lo stato dell'iterazione corrente (k, p_k, f(p_k), e_k, ||grad(f(p_k))||)
void print_status(int k, const Point2D& current_point, double funcVal, double error, double norm) {
    std::cout << "k: " << k
              << "\tpunto p_k: " << current_point
              << "\tvalore f(p_k): " << funcVal
              << "\terrore e_k: " << error
              << "\t||grad||: " << norm << std::endl;
}

// Esegue l'algoritmo iterativo di discesa del gradiente p_{k+1} = p_k - a * grad(f(p_k))
DescentResult GradientDescent::solve(const Function& func, const Point2D& initial_point) const {
    Point2D current_point = initial_point; // Posizione corrente p_k inizializzata a p_0
    int k = 0;                             // Contatore delle iterazioni eseguite
    int last_printed = -1;                 // Traccia l'ultima iterazione stampata per evitare duplicati
    bool converged = false;                // Flag di avvenuta convergenza
    bool diverged = false;                 // Flag di divergenza numerica (NaN / Inf)

    Point2D gradient;
    double norm = 0.0;
    double funcVal = 0.0;
    double error = 0.0;

    // Valore analitico noto m = f(x_min, y_min) usato per il calcolo dell'errore e_k
    const double known_min_val = func.evaluate(func.known_minimum());

    /*
     * Ciclo iterativo con controlli di uscita interni: calcola gradiente, norma, valore
     * della funzione ed errore al passo k, verifica le condizioni di arresto prima di
     * aggiornare la posizione e stampa lo stato ogni 10 iterazioni.
     */
    while (true) {
        // Calcolo del gradiente e della sua norma euclidea nel punto corrente
        gradient = func.gradient(current_point);
        norm = gradient.norm();
        if (std::isnan(norm) || std::isinf(norm)) {
            std::cout << "Errore: divergenza numerica rilevata nel calcolo del gradiente!" << std::endl;
            diverged = true;
            break;
        }

        // Calcolo del valore scalare della funzione f(p_k)
        funcVal = func.evaluate(current_point);
        if (std::isnan(funcVal) || std::isinf(funcVal)) {
            std::cout << "Errore: divergenza numerica rilevata nel calcolo della funzione!" << std::endl;
            diverged = true;
            break;
        }

        // Calcolo dell'errore rispetto al minimo analitico noto: e_k = f(p_k) - m
        error = funcVal - known_min_val;

        // Stampa periodica ogni 10 iterazioni (k = 0, 10, 20, ...)
        if (k % 10 == 0) {
            print_status(k, current_point, funcVal, error, norm);
            last_printed = k;
        }

        // Criterio di arresto 1: norma del gradiente inferiore alla soglia T
        if (norm < tolerance) {
            converged = true;
            break;
        }

        // Criterio di arresto 2: raggiunto il numero massimo di iterazioni N
        if (k >= max_iterations) {
            break;
        }

        // Aggiornamento della posizione al passo successivo: p_{k+1} = p_k - a * grad(f(p_k))
        current_point = current_point - step_size * gradient;
        k++;
    }

    // Stampa dell'ultima iterazione se non è già stata stampata (ovvero se k non è multiplo di 10)
    if (!diverged && k != last_printed) {
        print_status(k, current_point, funcVal, error, norm);
    }

    return {current_point, funcVal, k, converged};
}