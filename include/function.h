/**
 * @file Function.h
 * @brief Dichiarazione della classe astratta e dei metodi per la gestione di una funzione generica in 2 variabili.
 * @author Francesco
 * @date 2026-11-18
 */
#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include "Point2D.h"

/**
 * @class Function
 * @brief Implementa la gestione di una funzione astratta \f$ f(x,y)\f$.
 * 
 * Essendo una classe astratta impone dei "contratti" da far rispettare alle varie funzioni
 * figlie di Function. Abbiamo fatto questa scelta implementativa per fornire un codice più 
 * robusto essendo separato in più strutture (classi) indipendenti tra loro in modo da 
 * diminuire la propagazione di errori. Abbiamo scelto di raccogliere in function alcune
 * elaborazioni che altrimenti avremmo riscritto troppo volte nelle funzioni figlie, come 
 * il valore della funzione calcolata in un punto (Point2D) \f$ f(x,y)\f$, il gradiente della 
 * funzione \f$ \nabla f(x,y)\f$, il punto di minimo noto \f$ (x,y)\f$ e il nome della funzione.
 */
class Function {
    public:
        /**
         * @brief Calcolo del valore della funzione in un punto.
         * @param p Un generico punto descritto da una coordinata \f$ x\f$ e una coordinata \f$ y\f$.
         * @return double Il valore della funzione calcolata nel punto \f$ f(p) = f(p.x, p.y)\f$.
         */
        virtual double evaluate(const Point2D& p) const = 0;
        
        /**
         * @brief Calcolo del valore del gradiente della funzione in un punto.
         * @param p Un generico punto descritto da una coordinata \f$ x\f$ e una coordinata \f$ y\f$.
         * @return Point2D il valore del gradiente della funzione calcolato nel punto p: \f$ \nabla f(p)\f$. 
         */
        virtual Point2D gradient(const Point2D& p) const = 0;

        /**
         * @brief Punto di minimo (noto )della funzione.
         * @return Point2D Il punto dove si trova il punto di minimo finora noto della funzione. 
         */
        virtual Point2D known_minimum() const = 0;

        /**
         * @brief Nome della funzione.
         * @return std::string La stringa contenente il nome identificativo assegnato alla funzione.
         */
        virtual std::string name() const = 0;
        
        /**
         * @brief Distruttore della funzione (serve per l'allocazione dinamica della memoria).
         */
        virtual ~Function() = default;
};

#endif // FUNCTION_H