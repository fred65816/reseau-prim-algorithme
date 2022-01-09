#include "arrete.h"

Arrete::Arrete():
debut(-1), fin(-1), poids(-1), membre(false), rue(), distance(99999) {

}

Arrete::Arrete(const Arrete& a):
debut(a.debut), fin(a.fin), poids(a.poids), membre(a.membre),
rue(a.rue), distance(a.distance) {

}

Arrete::Arrete(const int debut_, const int fin_, const string& rue_,
    const int poids_, const double distance_):
debut(debut_), fin(fin_), poids(poids_), membre(false),
rue(rue_), distance(distance_) {

}

// Compare le sommet de depart à celui de fin de l'arrête
// passée en paramètre.
bool Arrete::isEqualS1S2(const Arrete& arrete) {
    return debut == arrete.fin;
}

// Compare le sommet de fin à celui de départ de l'arrête
// passée en paramètre.
bool Arrete::isEqualS2S1(const Arrete& arrete) {
    return fin == arrete.debut;
}

// Compare le sommet de depart à celui de départ de l'arrête
// passée en paramètre.
bool Arrete::isEqualS1S1(const Arrete& arrete) {
    return debut == arrete.debut;
}

// Compare le sommet de fin à celui de fin de l'arrête
// passée en paramètre.
bool Arrete::isEqualS2S2(const Arrete& arrete) {
    return fin == arrete.fin;
}

// Copie une arrête passée en paramètre.
Arrete& Arrete::operator=(const Arrete& arrete) {
    if(this == &arrete) {
        return *this;
    }
    debut = arrete.debut;
    fin = arrete.fin;
    rue = arrete.rue;
    poids = arrete.poids;
    distance = arrete.distance;
    membre = arrete.membre;
    return *this;
}

// Compare une arrête passée en paramètre selon le poids.
// Si les deux poids sont égaux, on compare la distance.
bool Arrete::operator<(const Arrete& arrete) {
    if(poids < arrete.poids) {
        return true;
    } else if(poids == arrete.poids && distance > arrete.distance) {
        return true;
    }
    return false;
}
