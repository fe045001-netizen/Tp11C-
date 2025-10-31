#include <iostream>
#include <vector>
using namespace std;

class Animal {
public:
    virtual void crier() const = 0; 
    void info() const {             
        cout << "Je suis un animal." << endl;
    }
    virtual ~Animal() {}            
};

class Chien : public Animal {
public:
    void crier() const {
        cout << "Wouf !" << endl;
    }
};

class Chat : public Animal {
public:
    void crier() const {
        cout << "Miaou !" << endl;
    }
};

class Vache : public Animal {
public:
    void crier() const {
        cout << "Meuh !" << endl;
    }
};

int main() {
    int n;
    cout << "Saisir n :  ";
    cin >> n;

    Animal* animaux[n]; 

    for (int i = 0; i < n; i++) {
        int choix;
        cout << "Type de l'animal " << i+1 << " (1=Chien, 2=Chat, 3=Vache) : ";
        cin >> choix;
        if (choix == 1) animaux[i] = new Chien();
        else if (choix == 2) animaux[i] = new Chat();
        else animaux[i] = new Vache();
    }

    for (int i = 0; i < n; i++) {
        animaux[i]->info();
        animaux[i]->crier();
        cout << endl;
    }

    for (int i = 0; i < n; i++)
        delete animaux[i];

    return 0;
}
