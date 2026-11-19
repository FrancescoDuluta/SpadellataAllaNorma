# Guida Architetturale OOP e Progettazione del `main`
**Progetto:** Ricerca del Minimo Locale tramite Discesa del Gradiente ($\mathbb{R}^2 \rightarrow \mathbb{R}$)

---

## 1. Scelte Stilistiche e Best Practice per l'Ereditarietà in C++

Adottare una gerarchia orientata agli oggetti rende il motore di discesa completamente indipendente dalle singole equazioni matematiche: l'algoritmo dialogherà esclusivamente con un'interfaccia astratta, ignorando quale delle 8 funzioni stia effettivamente calcolando.

Per evitare errori tipici di compilazione o gestione memoria sull'ambiente di verifica (**VLab/Taliercio.2020**), conviene adottare fin da subito queste regole stilistiche:

### A. La Classe Base Astratta (`Funzione`)
Questa classe definisce il "contratto" che tutte le 8 funzioni ($f_1 \dots f_8$) devono rispettare.
* **Metodi virtuali puri:** Dichiarare come virtuali puri i quattro comportamenti fondamentali che ogni funzione deve esporre:
  1. Valutazione scalare $f(x, y)$ dato un punto 2D.
  2. Valutazione del vettore gradiente $(\frac{\partial f}{\partial x}, \frac{\partial f}{\partial y})$ dato un punto 2D.
  3. Restituzione del valore analitico del minimo noto $m$.
  4. Restituzione di un identificativo testuale (es. `"f1"`, `"f2"`) utile per formattare i log di test.
* **Distruttore virtuale obbligatorio:** Nella classe base va sempre dichiarato un distruttore virtuale (`virtual ~Funzione()`). Senza di esso, la distruzione polimorfica degli oggetti derivati genera *undefined behavior* e warning severi nei compilatori GCC/Clang su Linux.
* **`const`-correctness rigorosa:** Valutare una funzione matematica o il suo gradiente non modifica lo stato interno dell'oggetto. Tutti i metodi di valutazione e lettura devono essere marcati come `const`. Questo permette al motore di discesa di ricevere la funzione come riferimento costante (`const Funzione&`), garantendo sicurezza e pulizia.

### B. Le Classi Derivate (`Funzione1` ... `Funzione8`)
* **Uso esplicito di `override`:** Nelle classi implementate da Lorenzo e dal terzo compagno, ogni metodo ridefinito deve riportare la parola chiave `override`. In questo modo, se qualcuno sbaglia un tipo di parametro o dimentica un `const` nella firma, il compilatore segnala subito l'errore invece di creare silenziosamente un nuovo metodo scollegato.
* **Incapsulamento delle costanti:** Eventuali parametri o costanti matematiche specifiche (come $\pi$ per $f_8$) vanno tenuti privati all'interno del file `.cpp` della rispettiva classe, senza inquinare gli header globali.

### C. Classi di Supporto ("Value Objects" senza ereditarietà)
Non tutto deve usare l'ereditarietà. Per i dati puri conviene usare classi concrete leggere o `struct`:
* **`Punto2D` (o `Vettore2D`):** Rappresenta contemporaneamente sia le coordinate $p_k = (x_k, y_k)$ sia il vettore gradiente $\nabla f(p_k)$. Dotarlo di operazioni vettoriali di base (somma/sottrazione tra punti, prodotto per scalare $a$, calcolo della norma euclidea) permette di scrivere l'equazione di aggiornamento $p_{k+1} = p_k - a\nabla f(p_k)$ in modo pulito e leggibile.
* **`ParametriDiscesa` e `EsitoDiscesa`:** Due contenitori dati per raggruppare rispettivamente gli input dell'algoritmo (passo $a$, punto iniziale $p_0$, iterazioni massime $N$, tolleranza $\overline{T}$) e i risultati finali (punto di arresto $p_E$, valore $f(p_E)$, iterazioni effettive, causa di terminazione).

### D. Gestione Sicura del Polimorfismo (Zero Memory Leak)
Per gestire in modo uniforme le 8 classi derivate evitando `new` e `delete` manuali:
* **Strategia consigliata (`std::unique_ptr`):** Conservare le 8 istanze in un contenitore standard di puntatori intelligenti (`std::vector<std::unique_ptr<Funzione>>`). Alla chiusura del programma la memoria viene liberata automaticamente (principio RAII).
* **Alternativa su Stack:** Istanziare le 8 funzioni come normali variabili locali nel `main` e raccogliere i loro indirizzi in un vettore di puntatori non proprietari (`std::vector<const Funzione*>`), passando poi ciascun elemento dereferenziato (`const Funzione&`) al risolutore. È la soluzione più semplice e a zero rischio di errori di memoria.

### E. Regole d'Oro per i File Header (`.h`)
* **Divieto di `using namespace std;` negli header:** Va usato eventualmente solo dentro i `.cpp` per evitare collisioni di nomi tra i file dei tre membri del gruppo.
* **Passaggio per riferimento costante:** Oggetti come `Punto2D` o `Funzione` vanno passati alle funzioni come `const Tipo&` per evitare copie inutili.
* **Include Guards:** Ogni `.h` deve avere le direttive di protezione contro l'inclusione multipla.

---

## 2. Struttura e Funzioni Base nel `main.cpp`

Il file `src/main.cpp` non deve contenere formule matematiche né logica di calcolo del gradiente: il suo unico compito è **orchestrare la suite di test** in modo ordinato, leggibile e facilmente estendibile.

Ecco le **4 funzioni di orchestrazione** consigliate da strutturare all'interno di `main.cpp`:

### 1. `creaSuiteFunzioni()` (Factory / Inizializzazione)
* **Scopo:** Istanzia tutte e 8 le classi derivate ($f_1 \dots f_8$) e le inserisce in un'unica collezione polimorfica, associando a ciascuna i suoi parametri di riferimento previsti dalle specifiche (passo $a$ prescritto ed estremi del dominio standard).
* **Vantaggio:** Centralizza in un solo punto la creazione degli oggetti. Se durante lo sviluppo volete testare temporaneamente solo una funzione, vi basta commentare una riga qui.

### 2. `eseguiSingoloEsperimento(...)` (Runner atomico)
* **Scopo:** Riceve una singola `const Funzione&`, un punto di partenza $p_0$, il passo $a$ e i criteri di arresto ($N, \overline{T}$).
* **Flusso operativo:**
  1. Stampa un'intestazione chiara a schermo con il nome della funzione, il punto di partenza $p_0$ e il passo $a$ utilizzato.
  2. Invoca il motore `DiscesaGradiente`, che si occupa di eseguire il ciclo e stampare lo stato ogni 10 iterazioni (più l'ultima se non multipla di 10) con $k$, $p_k$, $f(p_k)$, $e_k$ e $||\nabla f(p_k)||$.
  3. Riceve l'`EsitoDiscesa` e stampa il riepilogo finale con il punto di arresto $p_E$, il valore $f(p_E)$ e l'indicazione se l'algoritmo è arrivato a convergenza sotto soglia $\overline{T}$ oppure se ha raggiunto il limite massimo di iterazioni $N$.

### 3. `eseguiTestObbligatori(...)` (Batteria Standard)
* **Scopo:** Cicla sull'intera collezione delle 8 funzioni ed esegue per ciascuna i test con i **passi $a$ prescritti dalla tabella** e una selezione di punti di partenza $p_0$ **interni ai domini standard** (es. punti vicino ai bordi, punti asimmetrici, quadranti positivi e negativi).
* **Obiettivo:** Dimostrare in un'unica esecuzione che tutte le 8 funzioni convergono correttamente secondo i parametri ufficiali.

### 4. `eseguiTestEsplorativi(...)` (Fuori Dominio e Sensibilità al Passo)
* **Scopo:** Soddisfa la richiesta delle specifiche di verificare il comportamento anche al di fuori dei valori in tabella. Si divide in due sotto-scenari mirati:
  * **Punti di partenza esterni al dominio:** Utile per osservare l'attrazione verso minimi locali diversi (es. in $f_3$ e $f_4$ che hanno due pozzi, o in $f_8$ che è periodica) oppure il rallentamento su zone quasi piatte (es. lontano dall'origine in $f_7$).
  * **Variazione del passo $a$:** Test con un passo troppo piccolo (verifica che l'algoritmo si arresti pulitamente al raggiungimento di $N$ iterazioni) e con un passo troppo grande (verifica il comportamento oscillatorio o divergente).

### Flusso del `main()`
Con questa suddivisione, la funzione `main()` vera e propria diventa pulitissima e si riduce a quattro passaggi sequenziali:
1. Richiamo di `creaSuiteFunzioni()`.
2. Stampa titolo e avvio di `eseguiTestObbligatori()`.
3. Stampa separatore e avvio di `eseguiTestEsplorativi()`.
4. Chiusura pulita con `return 0;`.

---

## 3. Ordine di Congelamento dei File Header (`.h`)

Per permettere a tutti di lavorare in parallelo senza conflitti su GitHub, **Francesco** deve caricare su `main` i contratti base prima che gli altri inizino a scrivere i `.cpp`:

| File Header | Responsabile | Contenuto da congelare subito |
| :--- | :--- | :--- |
| `include/punto_2d.h` | Francesco | Struttura `Punto2D` e firma delle operazioni vettoriali |
| `include/funzione.h` | Francesco | Classe base astratta `Funzione` con i 4 metodi virtuali puri |
| `include/gradient_descent.h` | Francesco | Strutture di configurazione/esito e interfaccia del risolutore |
| `include/funzioni_1_4.h` | Lorenzo | Dichiarazione delle classi `Funzione1` ... `Funzione4` (ereditano da `Funzione`) |
| `include/funzioni_5_8.h` | Compagno 3 | Dichiarazione delle classi `Funzione5` ... `Funzione8` (ereditano da `Funzione`) |