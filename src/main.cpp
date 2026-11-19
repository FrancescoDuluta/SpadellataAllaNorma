/**
 * @file main.cpp
 * @brief Punto di ingresso del programma: gestisce un menu interattivo da terminale
 *        per configurare i parametri e testare la discesa del gradiente su diverse funzioni.
 * @author Francesco
 * @date 19-11-2026
 */

// 1. INCLUSIONE DELLE LIBRERIE E DEGLI HEADER DEL PROGETTO
// - Includi <iostream>, <iomanip> (per formattare i decimali) e <limits> (per pulire il buffer di std::cin)
// - Includi gli header delle tue classi: Point2D.h, Function.h (e sottoclassi), GradientDescent.h
#include "../include/GradientDescent.h"
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// 2. FUNZIONE AUSILIARIA PER EVITARE CODICE DUPLICATO NELLO SWITCH (CONSIGLIATA)
// - Scrivi una funzione void esegui_e_stampa(const GradientDescent& solver, const Function& func, const Point2D& p0):
//   * Stampa il punto di partenza p0
//   * Chiama DescentResult res = solver.solve(func, p0);
//   * Controlla res.converged e stampa l'esito (convergenza raggiunta o stop per max iterazioni / divergenza)
//   * Stampa le iterazioni effettuate (res.iterations), il punto finale (res.final_point) e il valore f(p_E)
//   * Confronta il risultato trovato con il minimo teorico noto (func.known_minimum())

void run(const GradientDescent& solver, const Function& func, const Point2D& p0) {
    cout << "p0: " << p0 << endl;
    DescentResult res = solver.solve(func, p0);
    if(res.converged)
        cout << "Convergenza raggiunta" << endl;
    else
        cout << "Divergenza o numero max di iterazioni raggiunto" << endl;
    cout << ""
}

int main() {
    // 3. INIZIALIZZAZIONE DEI PARAMETRI DI DEFAULT E DEL PUNTO INIZIALE
    // - Imposta valori sensati di partenza (es. step_size = 0.01, max_iterations = 1000, tolerance = 1e-6)
    // - Crea il punto iniziale di default (es. Point2D initial_point(2.0, 2.0);)

    // 4. ISTANZIAZIONE DEL SOLVER E DELLE FUNZIONI TEST (SULLO STACK)
    // - Crea l'oggetto GradientDescent solver(step_size, max_iterations, tolerance);
    // - Istanzia una variabile per ogni funzione concreta derivata da Function
    //   (es. Paraboloide f_parab; Rosenbrock f_rosen; ecc.)

    // 5. CICLO DO-WHILE PER IL MENU INTERATTIVO
    // - Dichiara int scelta = 0;
    // - Apri un ciclo do { ... } while (scelta != 0);
    
        // 5a. STAMPA DELLE OPZIONI DEL MENU
        // - Mostra i parametri attuali (passo a, iterazioni N, soglia T, punto p0)
        // - Stampa le voci selezionabili:
        //   1 -> Esegui discesa del gradiente su Funzione 1 (es. Paraboloide)
        //   2 -> Esegui discesa del gradiente su Funzione 2 (es. Rosenbrock)
        //   3 -> Esegui discesa del gradiente su Funzione 3 (...)
        //   4 -> Modifica il passo (step_size) o il punto iniziale p0
        //   0 -> Esci dal programma

        // 5b. LETTURA E CONTROLLO DELL'INPUT UTENTE
        // - Leggi std::cin >> scelta;
        // - Se std::cin.fail() è vero (es. l'utente ha digitato una lettera invece di un numero):
        //   pulisci lo stato di errore con std::cin.clear(), svuota il buffer con std::cin.ignore(...)
        //   e usa 'continue;' per ripetere il ciclo

        // 5c. COSTRUTTO SWITCH SULLA SCELTA
        // - switch (scelta) {
        //     case 1:
        //         // Chiama esegui_e_stampa(solver, f_parab, initial_point);
        //         // break;
        //     case 2:
        //         // Chiama esegui_e_stampa(solver, f_rosen, initial_point);
        //         // break;
        //     case 3:
        //         // Chiama esegui_e_stampa(solver, f_terza, initial_point);
        //         // break;
        //     case 4:
        //         // Chiedi all'utente il nuovo passo (verifica che sia > 0) e aggiorna con solver.set_step_size(...)
        //         // Chiedi le nuove coordinate (x0, y0) e aggiorna initial_point
        //         // break;
        //     case 0:
        //         // Stampa un messaggio di uscita dal programma
        //         // break;
        //     default:
        //         // Avvisa che l'opzione inserita non è valida
        //         // break;
        //   }

    // 6. TERMINAZIONE DEL PROGRAMMA
    return 0;
}