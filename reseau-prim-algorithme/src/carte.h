#if !defined(_CARTE__H_)
#define _CARTE__H_
#include "coordonnee.h"
#include "sommet.h"
#include "arrete.h"
#include <cassert>
#include <istream>
#include <list>
#include <map>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class Carte{
    public:
        Carte();

        void ajouterSommet(const string& nom, const Coordonnee& coor);
        void ajouterRoute(const string& nom, const list<string>& sommets, const int poids);
        void findMst();
        void printMst();
        void enleverSommets(Arrete& arr);
        void enleverSommetsVoisins(Arrete& arr);


    private:
        // les sommets de la carte.
        map<int, Sommet> sommets;
        // map nom sommet - indice.
        map<string, int> indexes;
        // map indice - nom sommet.
        map<int, string> indexesInv;
        // MST.
        vector<Arrete> route;

    friend istream& operator >> (istream& is, Carte& carte);
};

// tri les arrêtes de la route.
// inspiration: https://stackoverflow.com/questions/1380463/sorting-a-vector-of-custom-objects
struct sortArretes {
    inline bool operator() (const Arrete& arreteA, const Arrete& arreteB) {
        int p1Debut = arreteA.fin < arreteA.debut ? arreteA.fin: arreteA.debut;
        int p1Fin = arreteA.fin < arreteA.debut ? arreteA.debut: arreteA.fin;
        int p2Debut = arreteB.fin < arreteB.debut ? arreteB.fin: arreteB.debut;
        int p2Fin = arreteB.fin < arreteB.debut ? arreteB.debut: arreteB.fin;

        if(p1Debut < p2Debut) {
            return true;
        } else if(p1Debut == p2Debut && p1Fin < p2Fin) {
            return true;
        }
        return false;
    }
};

#endif
