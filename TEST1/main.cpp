#include <iostream>
#include <string>

// Test1 du TEKBOT
// CLASSE DE GESTION DE ROBOT

class Robot {
protected:
    std::string nom;
    std::string couleur;
    double taille;     // taille en mètres
    double vitesse;    // vitesse en m/s
    double precision;  // précision en %

public:
    Robot(std::string n, std::string c, double t, double v, double p)
        : nom(n), couleur(c), taille(t), vitesse(v), precision(p) {}

    // Getters
    std::string getNom() const { return nom; }
    std::string getCouleur() const { return couleur; }
    double getTaille() const { return taille; }
    double getVitesse() const { return vitesse; }
    double getPrecision() const { return precision; }

    // Setters
    void setNom(const std::string& n) { nom = n; }
    void setCouleur(const std::string& c) { couleur = c; }
    void setTaille(double t) { taille = t; }
    void setVitesse(double v) { vitesse = v; }
    void setPrecision(double p) { precision = p; }

    // Méthode virtuelle
    virtual void move() const {
        std::cout << nom << " se déplace de façon générique." << std::endl;
    }

    virtual ~Robot() {}
};

// Classe RobotBasketteur

class RobotBasketteur : public Robot {
public:
    RobotBasketteur(std::string n, std::string c, double t, double v, double p)
        : Robot(n, c, t, v, p) {}

    void move() const override {
        std::cout << nom << " court vers le panier et tire avec " << precision << "% de précision." << std::endl;
    }
};

// Classe RobotSuiveurDeLigne

class RobotSuiveurDeLigne : public Robot {
public:
    RobotSuiveurDeLigne(std::string n, std::string c, double t, double v, double p)
        : Robot(n, c, t, v, p) {}

    void move() const override {
        std::cout << nom << " suit la ligne noire avec une vitesse de :  " << vitesse << " m/s." << std::endl;
    }
};

// Classe RobotSniper
class RobotSniper : public Robot {
public:
    RobotSniper(std::string n, std::string c, double t, double v, double p)
        : Robot(n, c, t, v, p) {}

    void move() const override {
        std::cout << nom << " se positionne stratégiquement et tire avec " << precision << "% de précision." << std::endl;
    }
};

int main() {
    Robot* r1 = new RobotBasketteur("Dunk", "Rouge", 1.2, 5.0, 95.0);
    Robot* r2 = new RobotSniper("Sharp", "Noir", 1.0, 4.0, 98.0);
    Robot* r3 = new RobotSuiveurDeLigne("LineChaser", "Blanc", 0.8, 2.5, 90.0);

    r1->move();
    r2->move();
    r3->move();

    delete r1;
    delete r2;
    delete r3;

    return 0;
}
