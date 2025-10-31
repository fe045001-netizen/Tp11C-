#include <iostream>
using namespace std;

class Paiement {
public:
    virtual void effectuerPaiement(double montant) = 0;
    virtual ~Paiement() {}
};

class PaiementCarte : public Paiement {
public:
    void effectuerPaiement(double montant) {
        cout << "Paiement de " << montant << " DH par carte bancaire." << endl;
    }
};

class PaiementEspece : public Paiement {
public:
    void effectuerPaiement(double montant) {
        cout << "Paiement de " << montant << " DH en especes." << endl;
    }
};

int main() {
    int n;
    cout << "n: ";
    cin >> n;

    Paiement** paiements = new Paiement*[n]; 
    
    for (int i = 0; i < n; i++) {
        int choix;
        cout << "\nPaiement " << i + 1 << " (1=Carte, 2=Especes) : ";
        cin >> choix;

        if (choix == 1) {
            paiements[i] = new PaiementCarte();
        } else {
            paiements[i] = new PaiementEspece();
        }
    }

    for (int i = 0; i < n; i++) {
        double montant;
        cout << "Montant pour le paiement " << i + 1 << " : ";
        cin >> montant;
        paiements[i]->effectuerPaiement(montant); 
    }

    for (int i = 0; i < n; i++)
        delete paiements[i];
    delete[] paiements;

    return 0;
}

