/**
 * @file main.cpp
 * @brief Punto di ingresso del programma: gestisce un menu interattivo da terminale
 *        per configurare i parametri e testare la discesa del gradiente sulle funzioni f1 - f8.
 * @author Francesco
 * @date 20-11-2026
 */

#include "../include/GradientDescent.h"
#include "../include/Functions_1_8.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

/**
 * @brief Esegue l'algoritmo di discesa del gradiente su una specifica funzione
 *        e stampa a schermo il riepilogo dei risultati ottenuti.
 * @param solver Istanza configurata del risolutore GradientDescent.
 * @param func Riferimento costante alla funzione matematica da minimizzare.
 * @param p0 Punto bidimensionale di partenza per le iterazioni.
 */
void run(const GradientDescent& solver, const Function& func, const Point2D& p0) {
    cout << "\n--- Esecuzione su: " << func.name() << " ---" << endl;
    cout << "p0: " << p0 << endl;

    // Avvio dell'algoritmo iterativo e raccolta dell'esito
    DescentResult res = solver.solve(func, p0);

    // Verifica del criterio di arresto che ha terminato l'esecuzione
    if (res.converged)
        cout << "Convergenza raggiunta." << endl;
    else
        cout << "Divergenza o numero massimo di iterazioni N raggiunto." << endl;

    // Stampa del punto finale p_E, del valore f(p_E) e del numero di iterazioni
    cout << "Iterazioni effettuate: " << res.iterations
         << "\tPunto finale p_E: " << res.final_point
         << "\tValore f(p_E): " << res.final_value << endl;

    // Calcolo dell'errore scalare e_E = f(p_E) - m e della distanza euclidea dal minimo noto
    Point2D known_min = func.known_minimum();
    double final_error = res.final_value - func.evaluate(known_min);
    double distance_from_min = (res.final_point - known_min).norm();

    cout << "Punto di minimo noto: " << known_min
         << "\tErrore e_E: " << final_error
         << "\tDistanza dal minimo: " << distance_from_min << endl;
}

/**
 * @brief Funzione principale: inizializza i parametri di default, istanzia le 8 funzioni
 *        di test e gestisce il ciclo interattivo di selezione da terminale.
 * @return int Codice di uscita del programma (0 in caso di terminazione regolare).
 */
int main() {
    // Parametri di configurazione iniziali dell'algoritmo e punto di partenza p0
    double step_size = 0.01;
    int max_iterations = 1000;
    double tolerance = 1e-6;
    Point2D initial_point(2.0, 2.0);

    // Istanziazione del risolutore e delle 8 funzioni concrete derivate da Function
    GradientDescent solver(step_size, max_iterations, tolerance);
    Function_1 f_1;
    Function_2 f_2;
    Function_3 f_3;
    Function_4 f_4;
    Function_5 f_5;
    Function_6 f_6;
    Function_7 f_7;
    Function_8 f_8;

    // Ciclo principale del menu interattivo da terminale
    int choose = 0;
    do {
        // Visualizzazione dei parametri correnti e delle opzioni disponibili
        cout << "\n============================================================" << endl;
        cout << "Parametri attuali:\n"
             << "Passo a: " << step_size
             << "\tIterazioni max N: " << max_iterations
             << "\tSoglia T: " << tolerance
             << "\tPunto iniziale p0: " << initial_point << endl;

        cout << "\nOperazioni a disposizione:\n"
             << "1-8 -> Esegui discesa del gradiente su Funzione 1-8\n"
             << "9   -> Modifica il passo (step_size) e il punto iniziale p0\n"
             << "0   -> Esci dal programma\n"
             << "Inserisci l'operazione scelta: ";
        cin >> choose;

        // Gestione di eventuali input non numerici nel flusso standard
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input non valido: inserisci un numero intero." << endl;
            choose = -1; // Evita l'uscita accidentale se choose valeva 0
            continue;
        }

        // Smistamento dell'operazione selezionata dall'utente
        switch (choose) {
            case 1:
                run(solver, f_1, initial_point);
                break;
            case 2:
                run(solver, f_2, initial_point);
                break;
            case 3:
                run(solver, f_3, initial_point);
                break;
            case 4:
                run(solver, f_4, initial_point);
                break;
            case 5:
                run(solver, f_5, initial_point);
                break;
            case 6:
                run(solver, f_6, initial_point);
                break;
            case 7:
                run(solver, f_7, initial_point);
                break;
            case 8:
                run(solver, f_8, initial_point);
                break;
            case 9: {
                // Aggiornamento del passo costante 'a' con validazione del valore inserito
                double new_step = 0.0;
                cout << "\nInserisci il nuovo passo a (> 0): ";
                cin >> new_step;

                if (cin.fail() || new_step <= 0.0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Valore non valido per il passo. Mantengo a = " << step_size << endl;
                } else {
                    step_size = new_step;
                    solver.set_step_size(step_size);
                }

                // Aggiornamento delle coordinate del punto iniziale p0 = (x0, y0)
                double new_x = 0.0;
                double new_y = 0.0;
                cout << "Inserisci le nuove coordinate di p0 (x0 y0): ";
                cin >> new_x >> new_y;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Coordinate non valide. Mantengo p0 = " << initial_point << endl;
                } else {
                    initial_point = Point2D(new_x, new_y);
                }
                break;
            }
            case 0:
                cout << "Programma terminato correttamente." << endl;
                break;
            default:
                cout << "L'opzione inserita non e' valida!" << endl;
                break;
        }
    } while (choose != 0);

    return 0;
}