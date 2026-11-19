/**
 * @file GradientDescent.h
 * @brief Dichiarazione della classe e dei suoi metodi per l'implementazione dell'algoritmo di discesa del gradiente.
 * @author Francesco
 * @date 2026-11-18
 */
#ifndef GRADIENTDESCENT_H
#define GRADIENTDESCENT_H

#include "Function.h"

/**
 * @struct DescentResult
 * @brief Memorizza i risultati al termine dell'esecuzione dell'algoritmo.
 * Dovrà prevedere la memorizzazione dei parametri di esecuzione (passo \f $a\f$, massimo iterazioni \f$ N\f$,
 * tolleranza \f$ \overline{T}\f$) e un metodo pubblico di risoluzione che riceva una const Function& e 
 * il punto iniziale \f$ p_0\$.
 */
struct DescentResult {
    Point2D final_point;    ///< Punto finale su cui termina l'esecuzione dell'algoritmo.
    double final_value;     ///< Valore finale su cui termina l'algoritmo \f$ f(final_point)\f$.
    int iterations;         ///< Numero di iterazioni \f$ k\f$ al termine dell'algoritmo.
    bool converged;         ///< Se il risultato converge o diverge (a \f$ 0\f$ o \f$ +\infty\f$).
};

/**
 * @class GradientDescent
 * @brief Dichiara la classe e i metodi che mettono in atto l'algoritmo di discesa del gradiente.
 * Si tratta del vero e proprio "motore" del programma, dove vengono definiti i comandi implementativi 
 * attraverso alcuni metodi pubblici e dove prende vita l'algoritmo matematico al centro del progetto.
 */
class GradientDescent {
    public:
        /**
         * @brief Costruttore completo
         * @param step_size Lunghezza massima del passo costante \f$ a\f$.
         * @param max_iterazione Numero massimo di iterazioni \f$ N\f$ consentite.
         * 
         */
        GradientDescent(double step_size, int max_iterations, double tolerance);
        
        /**
         * @brief Modifica la lunghezza del passo costante \f$ a\f$
         * @param a La nuova lunghezza da dare al passo costante.
         */
        void set_step_size(double a);
        
        /**
         * @brief Risolve il problema computazionale applicando l'algoritmo richiesto
         * @param func La funzione \f$ f\f$ su cui viene applicato l'algoritmo.
         * @param initial_point Il punto iniziale fornito come punto di inizio da cui inizializzare l'algoritmo. 
         * @return DescentResult Il risultato dell'esecuzione dell'algoritmo, nel formato della struct descritta prima.
         */
        DescentResult solve(const Function& func, const Point2D& initial_point) const;

        /**
         * @brief Distruttore della classe
         */
        virtual ~GradientDescent() = default;

    private:
        double step_size;      ///< Il passo costante \f$ a\f$.
        int max_iterations;    ///< Il numero massimo di iterazioni \f$ N\f$.
        double tolerance;      ///< La soglia \f$ T\f$ sulla norma del gradiente.
};

/**
 * @brief Stampa a video il valore attuale di alcune variabili
 * @param k Numero attuale di iterazioni eseguite.
 * @param norm La norma del punto, appena calcolata.
 * @param funcVal Il valore della funzione nel determinato punto corrente \f$ P\f$.
 * @param error L'errore calcolato nella misura.
 */
void print_status(int k, double norm, double funcVal, double error);

#endif