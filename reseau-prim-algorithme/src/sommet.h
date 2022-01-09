#if !defined(_SOMMET__H_)
#define _SOMMET__H_

#include "coordonnee.h"
#include "arrete.h"
#include <string>
#include <vector>

using namespace std;

class Sommet {
    public:
        Sommet(const Coordonnee& coor_);
        // coordonnées du sommet.
        Coordonnee coor;
        // arrêtes sortantes du sommet.
        vector<Arrete> voisins;
        // true si sommet est ou a été visité.
        bool visite;

        Sommet& operator=(const Sommet& s);
};

#endif
