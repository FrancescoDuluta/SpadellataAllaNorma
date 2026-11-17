
### Definizione e Ruolo dei Moduli

*   `include/funzioni_1_4.h` e `src/funzioni_1_4.cpp`: Contengono l'implementazione matematica, le derivate parziali prime rispetto a $x$ e $y$ e i minimi analitici noti per il primo gruppo di funzioni ($f_1, f_2, f_3, f_4$).
*   `include/funzioni_5_8.h` e `src/funzioni_5_8.cpp`: Contengono l'implementazione matematica, le derivate parziali prime rispetto a $x$ e $y$ e i minimi analitici noti per il secondo gruppo di funzioni ($f_5, f_6, f_7, f_8$).
*   `include/gradient_descent.h` e `src/gradient_descent.cpp`: Definiscono la struttura dati per il calcolo iterativo del gradiente a passo costante, la gestione dell'arresto dell'algoritmo e le routine di visualizzazione e formattazione dei dati di output.
*   `src/main.cpp`: Costituisce il punto di ingresso dell'applicazione e raccoglie la suite completa di test, richiamando l'esecuzione dell'algoritmo su tutti i casi d'uso previsti dalle specifiche.
*   `README.txt`: Documento informativo strutturato collocato nella radice del progetto per la reportistica delle attività svolte dal gruppo.

# 3. Divisione dei Compiti per Membro del Gruppo

## Ruolo A: Francesco (Project Lead, Motore Algoritmo & Integrazione GitHub)

### Gestione dell'Ambiente di Sviluppo e Controllo Versione
*   Inizializzazione del repository GitHub dell'organizzazione/gruppo e impostazione delle regole di protezione sul ramo principale (`main`).
*   Configurazione del file `.gitignore` per ignorare file temporanei, file oggetto e binari generati dai compilatori in ambiente Linux/Windows.
*   Revisione, approvazione e fusione (merge) delle Pull Request presentate dagli altri componenti del team.

### Progettazione dell'Interfaccia Comune
*   Definizione concordata preliminarmente delle strutture dati di base per la rappresentazione dei vettori nello spazio bidimensionale (coordinate $x, y$), dei valori scalari della funzione, del gradiente bidimensionale e delle informazioni sul minimo noto.
*   Definizione dei tipi di puntatori a funzione o costrutti equivalenti per uniformare l'invocazione delle funzioni matematiche e dei rispettivi gradienti da parte del motore di discesa.

### Sviluppo del Modulo Algoritmico (`gradient_descent.h` / `gradient_descent.cpp`)
*   Implementazione della formula iterativa di aggiornamento a passo costante:
    *
    dove $a$ rappresenta il passo scelto, $p_k = (x_k, y_k)$ il punto corrente e $\nabla f(p_k)$ il gradiente calcolato nel punto.
*   Gestione integrata dei due criteri di arresto condizionale:
    1.  Raggiungimento del numero massimo di iterazioni consentite $N$.

    2.  Norma euclidea del gradiente inferiore alla tolleranza fissata $T$: $||\nabla f(p_k)|| < T$.
|---|---|---|
    *   Stampa dettagliata delle informazioni ogni 10 iterazioni (iterazione 0, 10, 20, ...) e obbligatoriamente al termine dell'ultima iterazione, anche qualora l'indice non sia un multiplo di 10.
    *   Dati da visualizzare per ogni passo di stampa: indice iterazione $k$, coordinate attuali del punto $p_k$, valore della funzione $f(p_k)$, errore assoluto rispetto al minimo analitico $e_k = f(p_k) - m$, e norma euclidea del gradiente $||\nabla f(p_k)||$.
    *   Stampa conclusiva del riepilogo dell'elaborazione con indicazione del punto di arresto finale $p_E$ e del valore di funzione $f(p_E)$.

### Integrazione Finale e Consegna
*   Scrittura della logica di controllo nel file `src/main.cpp` per l'esecuzione automatica della sequenza di test.
*   Esecuzione delle verifiche di validazione sulla macchina virtuale VLab/Taliercio.2020.
*   Generazione e verifica del pacchetto compresso finale pulito per la consegna su portale Moodle.

## Ruolo B: Lorenzo (Modulo Funzioni Matematiche Gruppo 1: f1 - f4)

### Analisi Matematica Preliminare
*   Calcolo analitico formale delle derivate parziali prime rispetto alle variabili $x$ e $y$ per ciascuna delle seguenti funzioni: $f_1, f_2, f_3, f_4$.
*   Determinazione esatta del valore di minimo $m$ (globale o locale a seconda del dominio) per le medesime quattro funzioni, fondamentale per garantire il corretto calcolo del valore di errore $e_k$.

### Sviluppo del Modulo C++ (`funzioni_1_4.h` / `funzioni_1_4.cpp`)
*   Implementazione della logica di calcolo delle quattro funzioni matematiche attraverso l'utilizzo delle funzioni offerte dalla libreria standard `<cmath>`.
*   Implementazione delle routine per la valutazione del vettore gradiente $(\frac{\partial f}{\partial x}, \frac{\partial f}{\partial y})$ in un generico punto del dominio.
*   Fornitura delle funzioni accessorie per il recupero del valore minimo noto $m$ relativo a ciascuna funzione.

### Attività di Testing e Documentazione
*   Definizione dei casi di test per le funzioni $f_1 - f_4$ basati sui parametri ufficiali (passo $a$ e dominio prescritti).
*   Predisposizione di test aggiuntivi con punti di partenza esterni al dominio base e valori del passo alternativi per valutare la stabilità dell'algoritmo e la divergenza del metodo.
*   Inserimento di documentazione analitica sotto forma di commenti standardizzati nei file di competenza.

## Ruolo C: Compagno 3 (Modulo Funzioni Matematiche Gruppo 2: f5 - f8)

### Analisi Matematica Preliminare
*   Calcolo analitico formale delle derivate parziali prime rispetto alle variabili $x$ e $y$ per le funzioni: $f_5, f_6, f_7, f_8$. L'analisi deve gestire correttamente la derivazione di operatori complessi quali seno iperbolico ($\sinh$), logaritmo naturale ($\ln$), funzioni esponenziali ed espressioni trigonometriche ($\sin$, $\cos$).
*   Calcolo analitico del valore minimo $m$ per ogni funzione, ponendo particolare attenzione alla funzione $f_8$ a causa della sua natura periodica, al fine di individuare il minimo locale corretto all'interno del dominio di interesse.

### Sviluppo del Modulo C++ (`funzioni_5_8.h` / `funzioni_5_8.cpp`)
*   Implementazione dei metodi di calcolo per le funzioni $f_5 - f_8$ mediante le funzioni della libreria `<cmath>` e l'impiego di una costante ad alta precisione per il valore di $\pi$.
*   Implementazione delle componenti del vettore gradiente per il secondo gruppo di funzioni e predisposizione delle funzioni per restituire il valore di minimo teorico $m$.

### Attività di Testing e Stesura Reportistica
*   Definizione dei casi di test per le funzioni $f_5 - f_8$ con l'uso dei parametri prescritti e con configurazioni di test al contorno.
*   Redazione finale e mantenimento del file `README.txt`, raccogliendo le descrizioni del lavoro svolto da tutti i componenti del gruppo, la ripartizione dei compiti e la documentazione relativa alle eventuali problematiche riscontrate.

# 4. Tabella di Riferimento per i Test (Parametri Obbligatori)

La tabella seguente riporta la configurazione dei parametri di test per ciascuna funzione. Tutti i test devono essere condotti a partire dai domini e dai passi specificati, integrando le verifiche con coordinate iniziali prescelte sia interne che esterne all'intervallo indicato.

| Identificatore Funzione | Passo Prescritto ($a$) | Dominio di Partenza Standard | Note di Configurazione Analitica |
| :--- | :--- | :--- | :--- |
| **f1** | $1/5 = 0.20$ | $[-4.0, 4.0]^2$ | Funzione quadratica/polinomiale base |
| **f2** | $2/25 = 0.08$ | $[-1.5, 1.5]^2$ | Polinomiale a convergenza rapida |
| **f3** | $1/20 = 0.05$ | $[-2.0, 2.0]^2$ | Presenza di termini ad accoppiamento incrociato |
| **f4** | $1/20 = 0.05$ | $[-2.0, 2.0]^2$ | Dominio quadratico con forte pendenza |
| **f5** | $3/20 = 0.15$ | $[-2.0, 2.0]^2$ | Trattamento espressivo con termini esponenziali/logaritmici |
| **f6** | $3/10 = 0.30$ | $[-2.0, 2.0]^2$ | Presenza di funzioni iperboliche ($\sinh$) |
| **f7** | $1/5 = 0.20$ | $[-2.0, 2.0]^2$ | Combinazione di termini trigonometrici e algebrici |
| **f8** | $1/10 = 0.10$ | $[-4.0, 4.0]^2$ | Modello trigonometrico periodico (minimi multipli) |

*Nota: Durante le sessioni di test in `main.cpp`, oltre ai punti interni al dominio di partenza prescritti, devono essere esplicitamente valutati punti di innesco situati esternamente ai limiti del dominio ed eseguiti test di sensibilità variando il parametro $a$.*

# 5. Fasi Operative e Flusso GitHub (Roadmap)

```text
[Fase 1: Setup & Contratti] ──> [Fase 2: Sviluppo Parallelo] ──> [Fase 3: PR & Integrazione] ──> [Fase 4: Validazione & Consegna]
