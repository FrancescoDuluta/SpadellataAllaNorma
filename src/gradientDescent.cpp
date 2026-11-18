#include "../include/gradientDescent.h"
#include <iostream>
#include <cmath>

GradientDescent::GradientDescent(double step_size, int max_iterations, double tolerance) :
    step_size(step_size), max_iterations(max_iterations), tolerance(tolerance)  {}
    
void GradientDescent::set_step_size(double step_size) {
    this->step_size = step_size;
}

DescentResult solve(const Function& func, const Point2D& initial_point) {
    Point2D current_point = initial_point;
    double norm = func.gradient(current_point).norm();
    double FuncVal = func.evaluate(current_point);
}

void DescentResult::run(Point2D final_point, double final_value, int iterations, bool converged) {
    std::cout << final_point << "\t" << final_value << "\t" << iterations << "\t" << converged << std::endl; 
}

// ============================================================================
// METODO AUSILIARIO PRIVATO PER LA STAMPA DELLO STATO (CONSIGLIATO)
// ============================================================================
// Funzione helper per stampare su una singola riga formattata le 5 informazioni
// richieste per l'iterazione corrente:
// indice k, punto p_k, valore f(p_k), errore e_k = f(p_k) - m, norma del gradiente


// ============================================================================
// METODO PRINCIPALE DI RISOLUZIONE (SOLVE)
// ============================================================================
// Firma del metodo solve che riceve un riferimento costante a Function
// e il punto di partenza p_0, restituendo la struct con l'esito finale

    // ------------------------------------------------------------------------
    // 1. Inizializzazione delle variabili di stato dell'algoritmo
    // ------------------------------------------------------------------------
    // Dichiarare il punto corrente inizializzato a p_0, il contatore k = 0,
    // un booleano per tracciare l'avvenuta convergenza e una variabile per
    // memorizzare l'indice dell'ultima iterazione stampata (es. last_printed = -1)


    // ------------------------------------------------------------------------
    // 2. Ciclo iterativo della discesa del gradiente
    // ------------------------------------------------------------------------
    // Avviare il ciclo di iterazione fino al raggiungimento dei criteri di arresto

        // Calcolare il valore scalare della funzione f(p_k) nel punto corrente


        // Calcolare il vettore gradiente nel punto corrente


        // Calcolare la norma euclidea del gradiente ||grad(f(p_k))||


        // Calcolare l'errore rispetto al minimo analitico noto: e_k = f(p_k) - m


        // Controllo di sicurezza contro la divergenza: verificare con std::isnan
        // o std::isinf se la norma o il valore della funzione non sono più finiti;
        // in tal caso stampare un avviso e interrompere il ciclo


        // Stampa periodica: se k è un multiplo di 10 (0, 10, 20, ...),
        // richiamare la stampa dello stato corrente e aggiornare last_printed = k


        // Primo criterio di arresto: verificare se ||grad(f(p_k))|| < soglia T;
        // se vero, impostare il flag di convergenza a true e uscire dal ciclo


        // Secondo criterio di arresto: verificare se k ha raggiunto il numero
        // massimo di iterazioni N; se vero, uscire dal ciclo


        // Aggiornamento della posizione per il passo successivo:
        // p_{k+1} = p_k - a * grad(f(p_k))


        // Incrementare il contatore delle iterazioni k


    // ------------------------------------------------------------------------
    // 3. Stampe conclusive e restituzione del risultato
    // ------------------------------------------------------------------------
    // Verificare se l'ultima iterazione k non è già stata stampata (ovvero se
    // k != last_printed, quindi non multipla di 10); in tal caso stamparla ora


    // Stampare il riepilogo finale obbligatorio a schermo con la posizione
    // di arresto finale p_E e il corrispondente valore della funzione f(p_E)


    // Costruire e restituire la struct di risultato (punto finale p_E,
    // valore f(p_E), iterazioni effettuate k, esito della convergenza)