/*
Dovrà prevedere la memorizzazione dei parametri di esecuzione (passo $a$, massimo iterazioni $N$,
tolleranza $\overline{T}$) e un metodo pubblico di risoluzione che riceva una const Function& e 
il punto iniziale $p_0$.
*/

class gradientDescent {
    public:

    private:
        double step_size;       // il passo costante a
        int max_interations;    // il numero massimo di iterazioni N
        double tolerance;       // la soglia T sulla norma del gradiente
};