#include <iostream>
#include <string>
using namespace std;

// Classe base
class Persona {
protected:
    string nome;
    int eta;

public:
    void inserisciDati() {
        cout << "Inserisci il nome: ";
        getline(cin, nome);  // legge anche spazi nel nome
        cout << "Inserisci l'età: ";
        cin >> eta;
        cin.ignore(); // pulisce il buffer dopo cin
    }

    void mostraDati() const {
        cout << "Nome: " << nome << endl;
        cout << "Età: " << eta << endl;
    }
};

// Classe derivata
class Lavoratore : public Persona {
private:
    double stipendio;

public:
    void inserisciDatiLavoratore() {
        inserisciDati(); // chiama la funzione della classe base
        cout << "Inserisci lo stipendio: ";
        cin >> stipendio;
    }

    void mostraDatiLavoratore() const {
        mostraDati();
        cout << "Stipendio: " << stipendio << " €" << endl;
    }
};

int main() {
    Lavoratore l;
    l.inserisciDatiLavoratore();
    cout << "\n--- DATI DEL LAVORATORE ---" << endl;
    l.mostraDatiLavoratore();

    return 0;
}

