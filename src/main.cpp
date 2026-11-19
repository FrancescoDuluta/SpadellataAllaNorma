/**
 * @file main.cpp
 * @brief Punto di ingresso del programma: gestisce un menu interattivo da terminale
 *        per configurare i parametri e testare la discesa del gradiente su diverse funzioni.
 * @author Francesco
 * @date 19-11-2026
 */

#include "../include/GradientDescent.h"
#include "../include/Functions_1-8.h"
#include <iostream>
#include <iomanip>
using namespace std;

// FUNZIONE AUSILIARIA PER EVITARE CODICE DUPLICATO NELLO SWITCH
void run(const GradientDescent& solver, const Function& func, const Point2D& p0) {
    cout << "p0: " << p0 << endl;
    DescentResult res = solver.solve(func, p0);
    if(res.converged)
        cout << "Convergenza raggiunta" << endl;
    else
        cout << "Divergenza o numero max di iterazioni raggiunto" << endl;
    cout << "Iterazioni effettuate: " << res.iterations << "\tPunto finale: " << res.final_point <<
        "\tvalore f(p_E)" << res.final_value << endl;
    if(res.final_point < func.known_minimum()) 
        cout << "Il punto finale e' minore del punto di minimo noto." << endl;
    else if(res.final_point > func.known_minimum())
        cout << "Il punto finale e' maggiore del punto di minimo noto." << endl;
    else
        cout << "Il punto finale e' esattamente identico al punto di minimo noto." << endl;
}

int main() {
    // 3. INIZIALIZZAZIONE DEI PARAMETRI DI DEFAULT E DEL PUNTO INIZIALE
    // - Imposta valori sensati di partenza (es. step_size = 0.01, max_iterations = 1000, tolerance = 1e-6)
    // - Crea il punto iniziale di default (es. Point2D initial_point(2.0, 2.0);)
    double step_size = 0.01; 
    int max_iterations = 1000;
    int n_actual_iterations = 0;
    double tolerance = 1e-6;
    Point2D initial_point = Point2D(2.0, 2.0);

    // 4. ISTANZIAZIONE DEL SOLVER E DELLE FUNZIONI TEST (SULLO STACK)
    // - Crea l'oggetto GradientDescent solver(step_size, max_iterations, tolerance);
    // - Istanzia una variabile per ogni funzione concreta derivata da Function
    //   (es. Paraboloide f_parab; Rosenbrock f_rosen; ecc.)
    GradientDescent solver(step_size, max_iterations, tolerance);
    Function_1 f_1 = Function_1();
    Function_2 f_2 = Function_2();
    Function_3 f_3 = Function_3();
    Function_4 f_4 = Function_4();
    Function_5 f_5 = Function_5();
    Function_6 f_6 = Function_6();
    Function_7 f_7 = Function_7();
    Function_8 f_8 = Function_8();

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
        //          Chiama esegui_e_stampa(solver, f_parab, initial_point);
        //          break;
        //     case 2:
        //          Chiama esegui_e_stampa(solver, f_rosen, initial_point);
        //          break;
        //     case 3:
        //          Chiama esegui_e_stampa(solver, f_terza, initial_point);
        //          break;
        //     case 4:
        //          Chiedi all'utente il nuovo passo (verifica che sia > 0) e aggiorna con solver.set_step_size(...)
        //          Chiedi le nuove coordinate (x0, y0) e aggiorna initial_point
        //          break;
        //     case 0:
        //          Stampa un messaggio di uscita dal programma
        //          break;
        //     default:
        //          Avvisa che l'opzione inserita non è valida
        //          break;
        //   }

    int choose = 0;
    do {
        cout << "Parametri attuali: \nPasso a: " << step_size <<  "\tIterazioni N: " << n_actual_iterations
            << "\tSoglia T: " << tolerance << "\tPunto iniziale: " << initial_point << endl;
        cout << "\nOperazioni a disposizione:\n" 
            << "1-8 -> Esegui discesa del gradiente su Funzione 1-8\n"
            << "9 -> Modifica il passo (step_size) o il punto iniziale p0\n"
            << "0 -> Esci dal programma\n" 
            << "Inserisci l'operazione scelta: " << endl;
        cin >> choose;
        if(cin.fail()) {
           cin.clear(); 
           cin.ignore(choose);
           continue; 
        }

        switch(choose) {
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
            case 9: 
                double tmp = step_size;
                cout << "\nInserisci il nuovo passo: " << endl;
                cin >> step_size;
                if(cin.fail()) {
                    cin.clear(); 
                    cin.ignore(step_size);
                    step_size = tmp;
                    continue; 
                }
                if(step_size > 0) {
                    solver.set_step_size(step_size);
                }
                else {
                    cout << "Valore inserito non valido. Tengo il valore vecchio per il passo" << endl;
                    step_size = tmp;
                }
                free(&tmp);
                break;
            case 0: 
                cout << "Programma terminato correttamente." << endl;
                break;
            default: 
                cout << "L'opzione inserita non e' valida! " << endl;
        }
    } while(choose != 0);
    
    return 0;
}