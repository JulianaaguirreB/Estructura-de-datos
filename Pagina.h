#ifndef PAGINA_H_
#define  PAGINA_H_

class Pagina
{ private:
    int numero;
    public:
        Pagina();
        Pagina(int numero);
        int getNumero() const;
        void setNumero(int numero);
};
#endif // PAGINA_H_
