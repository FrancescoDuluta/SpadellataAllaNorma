/**
 * @file GradientDescent.cpp
 * @brief Implementaione della classe GradientDescent
 * @author Francesco
 * @date 19-11-2026
*/
#include "../include/GradientDescent.h"
#include <iostream>
#include <cmath>

/*
    Definizione del costruttore completo di GradientDescent: inizializzare gli attributi 
    privati (passo a, iterazioni massime N, soglia T) tramite member initializer list
*/

GradientDescent::GradientDescent(double step_size, int max_iterations, double tolerance) :
    step_size(step_size), max_iterations(max_iterations), tolerance(tolerance)  {}

/* 
    Definizione del metodo set_step_size necessario per cambiare la dimensione del passo a
*/
void GradientDescent::set_step_size(double step_size) {
    this->step_size = step_size;
}

/*
    Definizione della funzione che stampa le informazioni (iterazioni, norma, valore calcolato, 
    errore) del punto corrente in analisi nell'algoritmo 
*/
void print_status(int k, double norm, double funcVal, double error) {
    std::cout << "k: " << k << "\tpunto p_k: " << norm << "\tvalore f(p_k)" << funcVal <<
                "\terrore e_k: " << error << std::endl;
}

/*
    Definizione dell'algoritmo protagonista del progetto, che si occupa di calcolare il minimo 
    di una funzione generica. Esso considera un punto che, partendo da una posizione iniziale
    \f$(p_0, f(p_0))\f$, percorre la superficie di una funzione matematica utilizzando un certo n
    umero di iterazioni che spostano il punto in posizioni successive \f$(p_k, f(p_k))\f$, 
    con spostamenti che dipendono dal gradiente in cui il punto si trova al passo corrente, andando 
    nella direzione in cui il gradiente decresce. Questo permette al punto di spostarsi idealmente verso 
    un minimo locale. Lo spostamento verso il passo successivo è descritto dall’equazione: 
    \f[p_{k+1} = p_k - a\nabla f(p_k))\f]
    dove \f$ a\f$ è un parametro che identifica il passo, per semplicità considerato costante per tutte le 
    iterazioni in questo progetto (molti algoritmi più sofisticati si basano su passi non costanti).
    L’algoritmo ha quindi bisogno di conoscere:
        ● la funzione da percorrere;
        ● il gradiente della funzione;
        ● la posizione di partenza \f$ p_0 = (x_0, y_0)\f$;
        ● il passo .𝑎
    A partire da questi dati è possibile applicare la formula vista sopra e ricavare le posizioni successive 
    \f$ p_k\f$. Poiché il numero di posizioni calcolabili è potenzialmente infinito, è importante stabilire 
    il criterio di terminazione, cioè un insieme di condizioni che stabiliscono quando terminare le iterazioni; 
    in questo progetto i criteri sono due:
        ● è stato raggiunto un numero massimo di iterazioni \f$ N\f$;
        ● la norma del gradiente è inferiore a una certa soglia: \f$ ||\nabla f(p_k)|| < T\f$
    dove rappresenta la norma del gradiente \f$ ||\nabla f(p_k)|| \f$, definita come: 
    \f$ ||\nabla f(p_k)|| = \sqrt{f_x(p_k)^2 + f_y(p_k)^2}\f$
    
*/
DescentResult GradientDescent::solve(const Function& func, const Point2D& initial_point) const {
    // Definisco una variabile che tratta il punto corrente
    Point2D current_point = Point2D(initial_point.x, initial_point.y);     
    int k = 0;                                 // Definisco una variabile che conta le iterazioni
    bool converged = false;                    // Definisco un booleano che indica se converge o diverge
    Point2D gradient = Point2D();              // Definisco una variabile punto vuoto che conterrà il gradiente
    double norm = 0.0; double funcVal = 0.0; double error = 0.0;    // Inizializzo a dei valori di base
    /*
        Ciclo infinito controllato tramite break interni: questa struttura evita di duplicare
        il calcolo del gradiente e della norma prima dell'ingresso nel ciclo e al termine di ogni
        iterazione. Le condizioni di terminazione (convergenza, limite iterazioni o divergenza numerica)
        vengono infatti valutate subito dopo aver calcolato i valori al passo k, interrompendo
        l'esecuzione prima di effettuare l'aggiornamento al punto successivo p_{k+1}.
    */
    while(true) {
        // Calcolo del gradiente nel punto corrente
        gradient = func.gradient(current_point);
        // Calcolo della norma del gradiente
        norm = gradient.norm();
            if(std::isnan(norm) || std::isinf(norm)) {
                std::cout << "Errore: divergenza trovata nel calcolo della norma! " << std::endl;
                break;
            }
        // Calcolo valore della funzione
        funcVal = func.evaluate(current_point);
            if(std::isnan(funcVal) || std::isinf(funcVal)) {
                std::cout << "Errore: divergenza trovata nel calcolo del valore della funzione in p_k! " << std::endl;
                break;
            } 
        // Calcolo dell'errore
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

        current_point = current_point - step_size * gradient * funcVal;    // Aggiornamento al nuovo punto (p_k+1)        
        k++;    // Incremento k
    }
    return {gradient, funcVal, k, converged};   // Restituisco il valore finale trovato come tipo DescentResult
}