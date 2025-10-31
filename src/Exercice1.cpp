#include <iostream>
#include <cmath>
using namespace std;

class Forme {
public:
    virtual double aire() const = 0; 
    virtual ~Forme() {}
};

class Cercle : public Forme {
    double rayon;
public:
    Cercle(double r) {
	 rayon = r;
	  }
    double aire() const {
	 return 3.14 * rayon * rayon;
	 }
	
 };

class Rectangle : public Forme {
    double longueur, largeur;
public:
    Rectangle(double L, double l) {
	 longueur = L; 
	 largeur = l; 
	 }
    double aire() const { 
	return longueur * largeur; 
	}
};

int main() {
    int n;
    cout << "donner n: ";
    cin >> n;

    Forme** formes = new Forme*[n]; 

    for (int i = 0; i < n; i++) {
        int choix;
        cout << "\nForme " << i + 1 << " (1=Cercle, 2=Rectangle) : ";
        cin >> choix;

        if (choix == 1) {
            double r;
            cout << "Rayon : ";
            cin >> r;
            formes[i] = new Cercle(r);
        } else {
            double L, l;
            cout << "Longueur : ";
            cin >> L;
            cout << "Largeur : ";
            cin >> l;
            formes[i] = new Rectangle(L, l);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Aire de la forme " << i + 1 << " = " << formes[i]->aire() << endl;
    }

    for (int i = 0; i < n; i++)
        delete formes[i];
    delete[] formes;

    return 0;
}

