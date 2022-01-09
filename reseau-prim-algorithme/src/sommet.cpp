
#include "sommet.h"

Sommet::Sommet(const Coordonnee& coor_)
: coor(coor_), voisins(), visite(false) {

}

Sommet& Sommet::operator=(const Sommet& sommet) {
    if(this == &sommet) {
        return *this;
    }
    coor = sommet.coor;
    voisins = sommet.voisins;
    return *this;
}
