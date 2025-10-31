#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NoeudFichier {
public:
    virtual string nom() const = 0;
    virtual int taille() const = 0;
    virtual ~NoeudFichier() {}
};

class Fichier : public NoeudFichier {
    string nom_a;
    int taille_b;
public:
    Fichier(const string& nom, int taille) : nom_a(nom), taille_b(taille) {}
    string nom() const override { return nom_a; }
    int taille() const override { return taille_b; }
};

class Dossier : public NoeudFichier {
    string nom_a;
    vector<NoeudFichier*> enfants;
public:
    Dossier(const string& nom) : nom_a(nom) {}
    string nom() const override { return nom_a; }

    int taille() const override {
        int total = 0;
        for (int i = 0; i < enfants.size(); i++) {
            total += enfants[i]->taille();
        }
        return total;
    }

    void ajouter(NoeudFichier* n) { enfants.push_back(n); }

    void afficherContenu() const {
         for (int i = 0; i < enfants.size(); i++) {
            cout << "- " << enfants[i]->nom() << " (" << enfants[i]->taille() << " Ko)" << endl;
        } 
    }
};

int main() {
    Dossier* racine = new Dossier("Racine");

    racine->ajouter(new Fichier("fichierA.txt", 20));
    racine->ajouter(new Fichier("fichierB.txt", 40));

    Dossier* sousDossier = new Dossier("SousDossier");
    sousDossier->ajouter(new Fichier("sousDossierA.txt", 15));
    sousDossier->ajouter(new Fichier("sousDossierB.txt", 5));

    racine->ajouter(sousDossier);

    racine->afficherContenu();

    cout << "Taille totale est: " << racine->taille() << " Ko" << endl;

    delete racine;

    return 0;
}

