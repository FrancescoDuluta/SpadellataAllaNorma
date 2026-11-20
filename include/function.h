/**
 * @file Function.h
 * @brief Dichiarazione della classe base astratta per la rappresentazione di una funzione
 *        scalare in due variabili \f$ f: \mathbb{R}^2 \to \mathbb{R} \f$.
 * @author Francesco
 * @date 2026-11-18
 */

#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include "Point2D.h"

/**
 * @class Function
 * @brief Interfaccia astratta che definisce il contratto per una funzione \f$ f(x, y) \f$.
 * @details Ogni funzione concreta di test eredita da questa classe e implementa i metodi
 *          virtuali puri per la valutazione scalare \f$ f(p) \f$, il calcolo del gradiente
 *          analitico \f$ \nabla f(p) \f$, il punto di minimo noto e il nome identificativo.
 *          Questa architettura disaccoppia il motore di ottimizzazione (GradientDescent)
 *          dalle singole funzioni tramite polimorfismo.
 */
class Function {
public:
    /**
     * @brief Calcola il valore scalare della funzione nel punto dato.
     * @param p Punto bidimensionale \f$ (x, y) \f$ in cui valutare la funzione.
     * @return double Valore della funzione calcolata in \p p, ovvero \f$ f(p.x, p.y) \f$.
     */
    virtual double evaluate(const Point2D& p) const = 0;

    /**
     * @brief Calcola il vettore gradiente della funzione nel punto dato.
     * @param p Punto bidimensionale \f$ (x, y) \f$ in cui valutare le derivate parziali.
     * @return Point2D Vettore gradiente \f$ \nabla f(p) = \left(\frac{\partial f}{\partial x}, \frac{\partial f}{\partial y}\right) \f$.
     */
    virtual Point2D gradient(const Point2D& p) const = 0;

    /**
     * @brief Restituisce il punto di minimo analitico noto della funzione.
     * @return Point2D Coordinate del punto in cui la funzione raggiunge il minimo noto.
     */
    virtual Point2D known_minimum() const = 0;

    /**
     * @brief Restituisce il nome o l'espressione identificativa della funzione.
     * @return std::string Stringa identificativa assegnata alla funzione.
     */
    virtual std::string name() const = 0;

    /**
     * @brief Distruttore virtuale di default per garantire la corretta deallocazione
     *        polimorfica delle classi derivate.
     */
    virtual ~Function() = default;
};

#endif // FUNCTION_H