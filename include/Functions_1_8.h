/**
 * @file Functions_1_8.h
 * @brief Dichiarazione delle classi derivate dalla classe astratta Function
 *        su cui verrà eseguito l'algoritmo di discesa del gradiente.
 *        Accorpa il lavoro di Lorenzo e Denis, precedentemente strutturato su file separati.
 * @authors Francesco, Lorenzo, Denis
 * @date 20-11-2026
 */

#ifndef FUNCTIONS_1_8_H
#define FUNCTIONS_1_8_H

#include <string>
#include "Point2D.h"
#include "Function.h"

/**
 * @class Function_1
 * @brief Prima funzione di test: \f$ f_1(x, y) = \frac{x^2 + y^2}{2} \f$.
 * @details
 * - Gradiente analitico: \f$ \nabla f_1(x, y) = (x,\; y) \f$
 * - Minimo noto: \f$ m = 0 \f$ nel punto \f$ (0, 0) \f$
 */
class Function_1 : public Function {
public:
    /**
     * @brief Valuta la funzione nel punto assegnato.
     * @param p Punto bidimensionale in cui calcolare \f$ f_1(p) \f$.
     * @return Valore scalare della funzione nel punto @p p.
     */
    double evaluate(const Point2D& p) const override;

    /**
     * @brief Calcola il vettore gradiente nel punto assegnato.
     * @param p Punto bidimensionale in cui calcolare \f$ \nabla f_1(p) \f$.
     * @return Vettore delle derivate parziali prime \f$ (\partial f_1/\partial x,\; \partial f_1/\partial y) \f$.
     */
    Point2D gradient(const Point2D& p) const override;

    /**
     * @brief Restituisce il punto di minimo analitico noto.
     * @return Coordinate del minimo teorico della funzione.
     */
    Point2D known_minimum() const override;

    /**
     * @brief Restituisce l'identificativo testuale della funzione.
     * @return Nome della funzione.
     */
    std::string name() const override;
};

/**
 * @class Function_2
 * @brief Seconda funzione di test: \f$ f_2(x, y) = \frac{x^2 + 16y^2}{2} \f$.
 * @details
 * - Gradiente analitico: \f$ \nabla f_2(x, y) = (x,\; 16y) \f$
 * - Minimo noto: \f$ m = 0 \f$ nel punto \f$ (0, 0) \f$
 */
class Function_2 : public Function {
public:
    /**
     * @brief Valuta la funzione nel punto assegnato.
     * @param p Punto bidimensionale in cui calcolare \f$ f_2(p) \f$.
     * @return Valore scalare della funzione nel punto @p p.
     */
    double evaluate(const Point2D& p) const override;

    /**
     * @brief Calcola il vettore gradiente nel punto assegnato.
     * @param p Punto bidimensionale in cui calcolare \f$ \nabla f_2(p) \f$.
     * @return Vettore delle derivate parziali prime \f$ (\partial f_2/\partial x,\; \partial f_2/\partial y) \f$.
     */
    Point2D gradient(const Point2D& p) const override;

    /**
     * @brief Restituisce il punto di minimo analitico noto.
     * @return Coordinate del minimo teorico della funzione.
     */
    Point2D known_minimum() const override;

    /**
     * @brief Restituisce l'identificativo testuale della funzione.
     * @return Nome della funzione.
     */
    std::string name() const override;
};

/**
 * @class Function_3
 * @brief Terza funzione di test: \f$ f_3(x, y) = (x^2 - 1)^2 + y^2 \f$.
 * @details
 * - Gradiente analitico: \f$ \nabla f_3(x, y) = (4x(x^2 - 1),\; 2y) \f$
 * - Minimo noto: \f$ m = 0 \f$ nei punti di minimo globale \f$ (-1, 0) \f$ e \f$ (1, 0) \f$
 */
class Function_3 : public Function {
public:
    /**
     * @brief Valuta la funzione nel punto assegnato.
     * @param p Punto bidimensionale in cui calcolare \f$ f_3(p) \f$.
     * @return Valore scalare della funzione nel punto @p p.
     */
    double evaluate(const Point2D& p) const override;

    /**
     * @brief Calcola il vettore gradiente nel punto assegnato.
     * @param p Punto bidimensionale in cui calcolare \f$ \nabla f_3(p) \f$.
     * @return Vettore delle derivate parziali prime \f$ (\partial f_3/\partial x,\; \partial f_3/\partial y) \f$.
     */
    Point2D gradient(const Point2D& p) const override;

    /**
     * @brief Restituisce il punto di minimo analitico noto.
     * @return Coordinate del minimo teorico della funzione.
     */
    Point2D known_minimum() const override;

    /**
     * @brief Restituisce l'identificativo testuale della funzione.
     * @return Nome della funzione.
     */
    std::string name() const override;
};

/**
 * @class Function_4
 * @brief Quarta funzione di test: \f$ f_4(x, y) = (x^2 - 1)^2 + \frac{(x - 1)^2}{5} + y^2 \f$.
 * @details
 * - Gradiente analitico: \f$ \nabla f_4(x, y) = \left(4x(x^2 - 1) + \frac{2}{5}(x - 1),\; 2y\right) \f$
 * - Minimo noto: \f$ m = 0 \f$ nel minimo globale \f$ (1, 0) \f$ (minimo locale non globale in \f$ \approx (-0.8873, 0) \f$)
 */
class Function_4 : public Function {
public:
    /**
     * @brief Valuta la funzione nel punto assegnato.
     * @param p Punto bidimensionale in cui calcolare \f$ f_4(p) \f$.
     * @return Valore scalare della funzione nel punto @p p.
     */
    double evaluate(const Point2D& p) const override;

    /**
     * @brief Calcola il vettore gradiente nel punto assegnato.
     * @param p Punto bidimensionale in cui calcolare \f$ \nabla f_4(p) \f$.
     * @return Vettore delle derivate parziali prime \f$ (\partial f_4/\partial x,\; \partial f_4/\partial y) \f$.
     */
    Point2D gradient(const Point2D& p) const override;

    /**
     * @brief Restituisce il punto di minimo analitico noto.
     * @return Coordinate del minimo teorico della funzione.
     */
    Point2D known_minimum() const override;

    /**
     * @brief Restituisce l'identificativo testuale della funzione.
     * @return Nome della funzione.
     */
    std::string name() const override;
};

/**
 * @class Function_5
 * @brief Quinta funzione di test: \f$ f_5(x, y) = 4\sinh^2\left(\frac{x}{2}\right) + y^2 \f$.
 * @details
 * - Gradiente analitico: \f$ \nabla f_5(x, y) = \left(4\sinh\left(\frac{x}{2}\right)\cosh\left(\frac{x}{2}\right),\; 2y\right) = (2\sinh(x),\; 2y) \f$
 * - Minimo noto: \f$ m = 0 \f$ nel punto \f$ (0, 0) \f$
 */
class Function_5 : public Function {
public:
    /**
     * @brief Valuta la funzione nel punto assegnato.
     * @param p Punto bidimensionale in cui calcolare \f$ f_5(p) \f$.
     * @return Valore scalare della funzione nel punto @p p.
     */
    double evaluate(const Point2D& p) const override;

    /**
     * @brief Calcola il vettore gradiente nel punto assegnato.
     * @param p Punto bidimensionale in cui calcolare \f$ \nabla f_5(p) \f$.
     * @return Vettore delle derivate parziali prime \f$ (\partial f_5/\partial x,\; \partial f_5/\partial y) \f$.
     */
    Point2D gradient(const Point2D& p) const override;

    /**
     * @brief Restituisce il punto di minimo analitico noto.
     * @return Coordinate del minimo teorico della funzione.
     */
    Point2D known_minimum() const override;

    /**
     * @brief Restituisce l'identificativo testuale della funzione.
     * @return Nome della funzione.
     */
    std::string name() const override;
};

/**
 * @class Function_6
 * @brief Sesta funzione di test: \f$ f_6(x, y) = \ln(1 + x^2 + y^2) \f$.
 * @details
 * - Gradiente analitico: \f$ \nabla f_6(x, y) = \left(\frac{2x}{1 + x^2 + y^2},\; \frac{2y}{1 + x^2 + y^2}\right) \f$
 * - Minimo noto: \f$ m = 0 \f$ nel punto \f$ (0, 0) \f$
 */
class Function_6 : public Function {
public:
    /**
     * @brief Valuta la funzione nel punto assegnato.
     * @param p Punto bidimensionale in cui calcolare \f$ f_6(p) \f$.
     * @return Valore scalare della funzione nel punto @p p.
     */
    double evaluate(const Point2D& p) const override;

    /**
     * @brief Calcola il vettore gradiente nel punto assegnato.
     * @param p Punto bidimensionale in cui calcolare \f$ \nabla f_6(p) \f$.
     * @return Vettore delle derivate parziali prime \f$ (\partial f_6/\partial x,\; \partial f_6/\partial y) \f$.
     */
    Point2D gradient(const Point2D& p) const override;

    /**
     * @brief Restituisce il punto di minimo analitico noto.
     * @return Coordinate del minimo teorico della funzione.
     */
    Point2D known_minimum() const override;

    /**
     * @brief Restituisce l'identificativo testuale della funzione.
     * @return Nome della funzione.
     */
    std::string name() const override;
};

/**
 * @class Function_7
 * @brief Settima funzione di test: \f$ f_7(x, y) = 1 - e^{-(x^2 + y^2)} \f$.
 * @details
 * - Gradiente analitico: \f$ \nabla f_7(x, y) = \left(2x e^{-(x^2 + y^2)},\; 2y e^{-(x^2 + y^2)}\right) \f$
 * - Minimo noto: \f$ m = 0 \f$ nel punto \f$ (0, 0) \f$
 */
class Function_7 : public Function {
public:
    /**
     * @brief Valuta la funzione nel punto assegnato.
     * @param p Punto bidimensionale in cui calcolare \f$ f_7(p) \f$.
     * @return Valore scalare della funzione nel punto @p p.
     */
    double evaluate(const Point2D& p) const override;

    /**
     * @brief Calcola il vettore gradiente nel punto assegnato.
     * @param p Punto bidimensionale in cui calcolare \f$ \nabla f_7(p) \f$.
     * @return Vettore delle derivate parziali prime \f$ (\partial f_7/\partial x,\; \partial f_7/\partial y) \f$.
     */
    Point2D gradient(const Point2D& p) const override;

    /**
     * @brief Restituisce il punto di minimo analitico noto.
     * @return Coordinate del minimo teorico della funzione.
     */
    Point2D known_minimum() const override;

    /**
     * @brief Restituisce l'identificativo testuale della funzione.
     * @return Nome della funzione.
     */
    std::string name() const override;
};

/**
 * @class Function_8
 * @brief Ottava funzione di test: \f$ f_8(x, y) = 2 - \cos(\pi x) - \cos(\pi y) \f$.
 * @details
 * - Gradiente analitico: \f$ \nabla f_8(x, y) = (\pi \sin(\pi x),\; \pi \sin(\pi y)) \f$
 * - Minimo noto: \f$ m = 0 \f$ nei punti periodici \f$ (2k_1, 2k_2) \f$ con \f$ k_1, k_2 \in \mathbb{Z} \f$ (in particolare nell'origine \f$ (0, 0) \f$)
 */
class Function_8 : public Function {
public:
    /**
     * @brief Valuta la funzione nel punto assegnato.
     * @param p Punto bidimensionale in cui calcolare \f$ f_8(p) \f$.
     * @return Valore scalare della funzione nel punto @p p.
     */
    double evaluate(const Point2D& p) const override;

    /**
     * @brief Calcola il vettore gradiente nel punto assegnato.
     * @param p Punto bidimensionale in cui calcolare \f$ \nabla f_8(p) \f$.
     * @return Vettore delle derivate parziali prime \f$ (\partial f_8/\partial x,\; \partial f_8/\partial y) \f$.
     */
    Point2D gradient(const Point2D& p) const override;

    /**
     * @brief Restituisce il punto di minimo analitico noto.
     * @return Coordinate del minimo teorico della funzione.
     */
    Point2D known_minimum() const override;

    /**
     * @brief Restituisce l'identificativo testuale della funzione.
     * @return Nome della funzione.
     */
    std::string name() const override;
};

#endif // FUNCTION_1_8_H