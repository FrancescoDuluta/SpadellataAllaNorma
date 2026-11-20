/**
 * @file GradientDescent.h
 * @brief Dichiarazione della classe e delle strutture di supporto per l'algoritmo
 *        di discesa del gradiente (Gradient Descent) a passo costante.
 * @author Francesco
 * @date 2026-11-18
 */

#ifndef GRADIENTDESCENT_H
#define GRADIENTDESCENT_H

#include "Point2D.h"
#include "Function.h"

/**
 * @struct DescentResult
 * @brief Memorizza gli esiti finali al termine dell'esecuzione dell'algoritmo.
 * @details Racchiude in un'unica struttura il punto di arresto \f$ p_E \f$, il relativo
 *          valore della funzione \f$ f(p_E) \f$, il numero totale di iterazioni eseguite
 *          e il flag booleano che indica il raggiungimento della convergenza.
 */
struct DescentResult {
    Point2D final_point; ///< Punto finale \f$ p_E \f$ su cui termina l'esecuzione.
    double final_value;  ///< Valore della funzione nel punto finale \f$ f(p_E) \f$.
    int iterations;      ///< Numero di iterazioni \f$ k \f$ effettuate fino all'arresto.
    bool converged;      ///< \c true se la norma del gradiente è scesa sotto la soglia, \c false altrimenti.
};

/**
 * @class GradientDescent
 * @brief Implementa il motore iterativo dell'algoritmo di discesa del gradiente.
 * @details Incapsula i parametri di configurazione (passo costante \f$ a \f$, numero massimo
 *          di iterazioni \f$ N \f$ e tolleranza \f$ \overline{T} \f$) ed espone il metodo
 *          polimorfico \c solve() per minimizzare una qualsiasi funzione derivata da \c Function.
 */
class GradientDescent {
public:
    /**
     * @brief Costruttore parametrico del risolutore.
     * @param step_size Lunghezza del passo costante \f$ a > 0 \f$.
     * @param max_iterations Numero massimo di iterazioni \f$ N \f$ consentite.
     * @param tolerance Soglia di arresto \f$ \overline{T} \f$ sulla norma euclidea del gradiente.
     */
    GradientDescent(double step_size, int max_iterations, double tolerance);

    /**
     * @brief Aggiorna la lunghezza del passo costante \f$ a \f$.
     * @param a Nuovo valore positivo da assegnare al passo costante.
     */
    void set_step_size(double a);

    /**
     * @brief Esegue l'algoritmo di discesa del gradiente sulla funzione data.
     * @param func Riferimento costante alla funzione obiettivo \f$ f \f$ da minimizzare.
     * @param initial_point Punto bidimensionale di partenza \f$ p_0 \f$.
     * @return DescentResult Struttura contenente il punto finale, il valore minimo trovato,
     *         le iterazioni svolte e l'esito della convergenza.
     */
    DescentResult solve(const Function& func, const Point2D& initial_point) const;

    /**
     * @brief Distruttore virtuale di default della classe.
     */
    virtual ~GradientDescent() = default;

private:
    double step_size;   ///< Passo costante \f$ a \f$ dell'algoritmo.
    int max_iterations; ///< Numero massimo di iterazioni \f$ N \f$.
    double tolerance;   ///< Soglia di arresto \f$ \overline{T} \f$ sulla norma del gradiente.
};

/**
 * @brief Stampa a terminale lo stato dell'algoritmo all'iterazione corrente.
 * @param k Indice dell'iterazione corrente.
 * @param norm Norma euclidea del gradiente \f$ \lVert \nabla f(p_k) \rVert \f$.
 * @param funcVal Valore della funzione nel punto corrente \f$ f(p_k) \f$.
 * @param error Errore rispetto al minimo analitico noto \f$ e_k = f(p_k) - m \f$.
 */
void print_status(int k, const Point2D& current_point, double funcVal, double error, double norm);

#endif // GRADIENTDESCENT_H