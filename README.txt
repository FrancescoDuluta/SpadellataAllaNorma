================================================================================
CORSO DI LABORATORIO DI PROGRAMMAZIONE - PROVA INTERMEDIA DI PROGRAMMAZIONE
Implementazione dell'algoritmo di Discesa del Gradiente (Gradient Descent)
Gruppo: SpadellataAllaNorma
================================================================================

1. MEMBRI DEL GRUPPO E SUDDIVISIONE DELLE ATTIVITA'
--------------------------------------------------------------------------------
- Francesco:
  * Progettazione dell'architettura del software e delle strutture dati
    (struct Point2D per i punti/vettori in R^2, classe base astratta Function
    per il polimorfismo delle funzioni matematiche).
  * Implementazione della classe GradientDescent (motore iterativo, formula di
    aggiornamento, criteri di arresto su iterazioni N e tolleranza T, stampa
    periodica ogni 10 iterazioni e sull'iterazione finale).
  * Sviluppo dell'interfaccia interattiva da terminale per l'esecuzione dei
    test in src/main.cpp.
  * Integrazione finale delle otto funzioni in Functions_1_8.h/.cpp,
    documentazione nel codice e verifica della compilazione sull'ambiente
    virtuale VLab (Taliercio.2020).

- Lorenzo:
  * Calcolo analitico delle derivate parziali prime e dei punti di minimo
    noti per le funzioni f1, f2, f3 e f4.
  * Implementazione dei metodi evaluate, gradient, known_minimum e name per
    le funzioni f1 - f4.
  * Esecuzione dei test di convergenza con i passi e i domini indicati in
    consegna e con parametri esplorativi esterni ai domini.

- Denis:
  * Calcolo analitico delle derivate parziali prime e dei punti di minimo
    noti per le funzioni f5, f6, f7 e f8.
  * Implementazione dei metodi evaluate, gradient, known_minimum e name per
    le funzioni f5 - f8.
  * Esecuzione dei test di convergenza per f5 - f8 e redazione delle note
    tecniche di consegna.


2. STRUTTURA DEL PROGETTO E ISTRUZIONI DI COMPILAZIONE
--------------------------------------------------------------------------------
Il codice sorgente e' organizzato nelle seguenti directory:

  include/
    - Point2D.h          : dichiarazione struct Point2D e operatori vettoriali
    - Function.h         : dichiarazione classe base astratta Function
    - Functions_1_8.h    : dichiarazione classi derivate Function_1 ... Function_8
    - gradientDescent.h  : dichiarazione classe GradientDescent e DescentResult

  src/
    - Point2D.cpp        : implementazione operazioni algebriche e norma euclidea
    - Functions_1_8.cpp  : implementazione funzioni f1 - f8 e relativi gradienti
    - gradientDescent.cpp: implementazione algoritmo di discesa del gradiente
    - main.cpp           : programma principale con menu interattivo di test

  README.txt             : presente file informativo per la correzione

Comando di compilazione (verificato senza warning su VLab / Taliercio.2020):
  g++ -Wall -Wextra -Iinclude src/*.cpp -o gradient_descent

Esecuzione:
  ./gradient_descent


3. NOTE AGGIUNTIVE E PROBLEMI RISCONTRATI
--------------------------------------------------------------------------------
A) Problemi riscontrati e risolti durante lo sviluppo:
- Minimi noti delle funzioni f3 e f4: inizialmente il metodo known_minimum()
  restituiva l'origine (0, 0) per tutte le funzioni. Tuttavia, mentre per f1,
  f2, f5, f6, f7 e f8 l'origine e' un punto di minimo globale con m = 0, per
  f3(0, 0) = 1 (punto di sella) e per f4(0, 0) = 1.2. Il valore di ritorno di
  known_minimum() e' stato quindi corretto in (1, 0) per entrambe, allineando
  il valore teorico m = 0 nel calcolo dell'errore e_k = f(p_k) - m.
- Gestione delle stampe intermedie e finali: per rispettare la specifica di
  stampare lo stato ogni 10 iterazioni (k = 0, 10, 20, ...) e anche all'ultima
  iterazione qualora non sia multipla di 10, e' stato introdotto il tracciamento
  dell'ultima iterazione stampata evitando duplicazioni in uscita.
- Input da terminale: nel menu interattivo del main e' stata gestita la
  pulizia dello stream std::cin in caso di inserimento di caratteri non
  numerici, prevenendo cicli infiniti in fase di test.

B) Comportamenti numerici rilevati nei test (note per la correzione):
- Punti di sella su f3: partendo con ascissa nulla (es. p0 = (0, 2)), la
  componente df3/dx risulta identicamente zero e l'algoritmo converge al
  punto di sella (0, 0) anziche' ai minimi globali (-1, 0) o (1, 0).
- Minimo locale non assoluto su f4: per punti iniziali con ascissa negativa
  sufficientemente lontana dall'origine, l'algoritmo converge al minimo locale
  in circa (-0.8873, 0) (dove f4 vale circa 0.713) anziche' al minimo globale
  (1, 0).
- Periodicita' su f8: essendo f8 periodicamente ripetuta sul piano, punti di
  partenza lontani dall'origine convergono al minimo locale del bacino di
  attrazione piu' vicino (2h, 2k) con h, k interi.
- Plateau su f7: per punti iniziali molto distanti dall'origine, il gradiente
  di f7 tende rapidamente a zero (superficie quasi piatta); se ||grad(f(p0))||
  e' gia' inferiore alla soglia T, l'algoritmo si arresta immediatamente.
- Sensibilita' al passo su f2: a causa della forte curvatura lungo l'asse y
  (termine 16*y^2), valori del passo a >= 1/8 provocano oscillazioni divergenti
  (gestite tramite controllo std::isnan / std::isinf).
================================================================================