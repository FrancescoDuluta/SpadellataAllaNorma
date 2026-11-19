# Guida all'uso di Doxygen nel Progetto (C++ & Matematica)

Questa guida serve a uniformare i commenti nel nostro codice C++ in modo da generare automaticamente la documentazione HTML del progetto tramite **Doxygen**, includendo le formule matematiche per la discesa del gradiente.

---

## 1. Installazione e Setup Iniziale

### Installazione
* **Linux (Ubuntu/Debian):** `sudo apt install doxygen graphviz`
* **macOS (Homebrew):** `brew install doxygen graphviz`
* **Windows:** Scaricare l'installer dal sito ufficiale di Doxygen (e opzionalmente Graphviz per i diagrammi delle classi).

### Configurazione (da fare una sola volta nel repo)
1. Nella cartella principale del progetto, genera il file di configurazione base:
   ```bash
   doxygen -g Doxyfile
   ```
2. Apri il file `Doxyfile` appena creato e modifica/verifica queste righe fondamentali:
   * `PROJECT_NAME = "Nome Del Nostro Progetto"`
   * `OUTPUT_DIRECTORY = docs` *(salva l'output in una cartella dedicata; ricorda di aggiungere `docs/` al `.gitignore`!)*
   * `INPUT = src include` *(le cartelle dove mettiamo i file `.cpp` e `.hpp`/`.h`)*
   * `RECURSIVE = YES` *(cerca anche nelle sottocartelle)*
   * `EXTRACT_ALL = YES` *(documenta anche elementi non ancora commentati)*
   * `USE_MATHJAX = YES` *(**Fondamentale**: permette di renderizzare le formule LaTeX nell'HTML senza dover installare LaTeX localmente)*

### Generare la documentazione
Ogni volta che volete vedere la documentazione aggiornata:
```bash
doxygen Doxyfile
```
Poi aprite il file `docs/html/index.html` con un qualsiasi browser.

---

## 2. Dove e Come Scrivere i Commenti

**Regola d'oro:** Documentate soprattutto nei file **Header (`.hpp` / `.h`)** sopra le dichiarazioni di classi, struct e funzioni. Nei file `.cpp` mettete solo commenti normali (`//`) per spiegare passaggi interni complessi.

Doxygen riconosce i commenti che iniziano con `/**` (stile Javadoc) oppure `///`. Useremo lo stile **`/** ... */`** per i blocchi e **`///<`** per i commenti inline.

---

## 3. Sintassi e Tag Principali

### A. Intestazione dei File
All'inizio di ogni file `.hpp` e `.cpp`:
```cpp
/**
 * @file gradient_descent.hpp
 * @brief Dichiarazione della classe e dei metodi per la discesa del gradiente.
 * @author Nome Cognome
 * @date 2026-11-18
 */
```

### B. Classi e Struct
Subito prima della dichiarazione della classe:
```cpp
/**
 * @class GradientDescent
 * @brief Implementa l'algoritmo di ottimizzazione della discesa del gradiente.
 * 
 * Questa classe gestisce l'aggiornamento iterativo dei parametri fino al 
 * raggiungimento della tolleranza desiderata o del numero massimo di iterazioni.
 */
class GradientDescent {
    // ...
};
```

### C. Funzioni e Metodi (Il più importante!)
Usa `@brief`, `@param`, `@return` e, se necessario, `@throws` o `@note`.
```cpp
/**
 * @brief Esegue un singolo passo di aggiornamento dei pesi.
 * 
 * Calcola il nuovo vettore dei parametri sottraendo il gradiente scalato 
 * per il learning rate.
 * 
 * @param weights Vettore corrente dei parametri (viene modificato in-place).
 * @param gradient Vettore del gradiente calcolato nel punto corrente.
 * @param learning_rate Passo di apprendimento ($\alpha > 0$).
 * @return double La norma euclidea del gradiente al passo corrente.
 * @throws std::invalid_argument Se weights e gradient hanno dimensioni diverse.
 */
double step(std::vector<double>& weights, const std::vector<double>& gradient, double learning_rate);
```

### D. Variabili e Attributi di Classe
Per commentare i membri privati/pubblici o i valori di un `enum`:
```cpp
private:
    double tolerance_;      ///< Soglia di arresto per la norma del gradiente.
    size_t max_iterations_; ///< Numero massimo di iterazioni consentite.
```

---

## 4. Scrivere Formule Matematiche ($\LaTeX$)

Grazie a `USE_MATHJAX = YES` nel `Doxyfile`, possiamo inserire formule matematiche direttamente nei commenti usando i delimitatori specifici di Doxygen:

* **Formula inline (nel testo):** racchiusa tra `\f$` e `\f$`
* **Formula centrata (su riga propria):** racchiusa tra `\f[` e `\f]`

### Esempio pratico per il nostro codice:
```cpp
/**
 * @brief Calcola l'aggiornamento dei parametri secondo la regola standard.
 * 
 * Ad ogni iterazione \f$ k \f$, il vettore dei parametri \f$ \mathbf{x}_k \f$ 
 * viene aggiornato secondo la formula:
 * \f[
 *   \mathbf{x}_{k+1} = \mathbf{x}_k - \alpha_k \nabla f(\mathbf{x}_k)
 * \f]
 * dove \f$ \alpha_k \f$ è il learning rate e \f$ \nabla f(\mathbf{x}_k) \f$ 
 * è il gradiente della funzione obiettivo.
 * 
 * @param x Vettore dei parametri al passo \f$ k \f$.
 * @param alpha Step size (learning rate).
 */
void update(Vector& x, double alpha);
```

---

## 5. Checklist Prima di Fare `git push`

1. Ogni nuova funzione pubblica nel `.hpp` ha almeno `@brief`, `@param` (per ogni parametro) e `@return` (se non è `void`).
2. Se hai implementato una formula matematica non banale (es. Armijo line search, gradiente coniugato, norme), hai scritto l'equazione in LaTeX nel commento.
3. Hai lanciato `doxygen Doxyfile` da terminale per verificare che **non ci siano warning** (es. parametri documentati con nome diverso da quello nel codice).