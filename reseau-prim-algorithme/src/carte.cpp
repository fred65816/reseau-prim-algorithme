#include <cstdio>
#include <math.h>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include "carte.h"

Carte::Carte():
sommets(), indexes(), indexesInv(), route() {

}

// Ajoute les sommets à une map lors de la lecture de la carte.
void Carte::ajouterSommet(const string& nom, const Coordonnee& coor) {
    // validation.
    map<int, Sommet>::const_iterator it = sommets.find(sommets.size());
    assert(it == sommets.end());
    // insertions.
    int index = sommets.size();
    sommets.insert(map<int, Sommet>::value_type(index, Sommet(coor)));
    indexes.insert(map<string, int>::value_type(nom, index));
    indexesInv.insert(map<int, string>::value_type(index, nom));
}

// Ajoute les routes aux vectors voisins des sommets correspondants.
void Carte::ajouterRoute(const string& nom, const list<string>& sommets, const int poids) {
    // validation.
    for(list<string>::const_iterator itl = sommets.begin(); itl != sommets.end(); ++itl) {
        map<string, int>::const_iterator itm = indexes.find(*itl);
        assert(itm != indexes.end());
    }
    // ajout des deux cotés donc itération fin - 1.
    list<string>::const_iterator itle = sommets.end();
    --itle;
    // insertions.
    for(list<string>::const_iterator itl1 = sommets.begin(); itl1 != itle;){
        list<string>::const_iterator itl2 = itl1;
        list<string>::const_iterator itl3 = ++itl1;
        const int ind1 = indexes.at(*itl2);
        const int ind2 = indexes.at(*itl3);
        Sommet& s2 = this->sommets.at(ind1);
        Sommet& s3 = this->sommets.at(ind2);
        const double distance = s2.coor.distance(s3.coor);
        s2.voisins.push_back(Arrete(ind1, ind2, nom, poids, distance));
        s3.voisins.push_back(Arrete(ind2, ind1, nom, poids, distance));
    }
}

// Résouds le MST
void Carte::findMst() {
    // la file contenant les sommets non-visités.
    set<int> queue;
    // arrête maximum (plus gros poids).
    Arrete arreteMax;
    // le sommet courant où la route se positionne.
    // sommet fin de l'arrête maximum précédente.
    int sommetCourant = 0;

    // remplissage de la file
    for(map<int, Sommet>::const_iterator it = sommets.begin(); it != sommets.end(); ++it) {
        queue.insert(it->first);
    }

    while (!queue.empty()) {
        // contient les arrêtes maximum de chaque sommets visités
        vector<Arrete> arretes;

        // on enlève le sommet courant de la file
        // et on le met comme étant visité.
        set<int>::iterator iter = queue.find(sommetCourant);
        if (iter != queue.end()) {
            queue.erase(iter);
        }
        sommets.at(sommetCourant).visite = true;

        // trouve l'arrête maximum pour chaque sommet visité.
        for(map<int, Sommet>::const_iterator itm = sommets.begin(); itm != sommets.end(); ++itm) {
            if(itm->second.visite) {
                arreteMax = Arrete();
                for(vector<Arrete>::const_iterator itv = itm->second.voisins.begin(); itv != itm->second.voisins.end(); ++itv) {
                    if(!(*itv).membre) {
                        if(arreteMax < *itv) {
                            arreteMax = *itv;
                        }
                    }
                }
                if(arreteMax.debut != -1) {
                    arretes.push_back(arreteMax);
                }
            }
        }

        if(arretes.size() > 0) {
            // trouve l'arrête maximum de tous les arrêtes maximum.
            vector<Arrete>::const_iterator its = arretes.begin();
            arreteMax = *its;
            ++its;
            for( ;its != arretes.end(); ++its) {
                if(arreteMax < *its) {
                    arreteMax = *its;
                }
            }

            // ajout de l'arrête à la route
            route.push_back(arreteMax);
            // on enlève l'arrête maximum et celles qu'on
            // n'a plus besoin de vérifier des candidats.
            enleverSommets(arreteMax);
            enleverSommetsVoisins(arreteMax);
            // mise-à-jour du sommet courant
            sommetCourant = arreteMax.fin;
        }
    }
}

// enlève le sommet maximum et son contraire des candidats.
void Carte::enleverSommets(Arrete& arr) {
    Sommet& s1 = sommets.at(arr.debut);
    for(vector<Arrete>::iterator it1 = s1.voisins.begin(); it1 != s1.voisins.end(); ++it1) {
        if((*it1).isEqualS1S1(arr) && (*it1).isEqualS2S2(arr)){
            (*it1).membre = true;
        }
    }
    Sommet& s2 = sommets.at(arr.fin);
    for(vector<Arrete>::iterator it2 = s2.voisins.begin(); it2 != s2.voisins.end(); ++it2) {
        if((*it2).isEqualS1S1(arr) && (*it2).isEqualS2S2(arr)){
            (*it2).membre = true;
        }
    }
}

// enlèves les sommets des candidats qu'on a plus besoin
// de vérifier ainsi que leur opposés.
void Carte::enleverSommetsVoisins(Arrete& arr) {
    Sommet& s = sommets.at(arr.fin);
    for(vector<Arrete>::iterator itv = s.voisins.begin(); itv != s.voisins.end(); ++itv) {
        for(vector<Arrete>::iterator itc = route.begin(); itc != route.end(); ++itc) {
            if((*itv).isEqualS2S1(*itc) && !((*itv).membre)) {
                (*itv).membre = true;
                Sommet& s1 = sommets.at((*itc).debut);
                for(vector<Arrete>::iterator its1 = s1.voisins.begin(); its1 != s1.voisins.end(); ++its1) {
                    if((*its1).isEqualS2S1(*itv) && (*its1).isEqualS1S2(*itv)) {
                        (*its1).membre = true;
                    }
                }
            }
            if((*itv).isEqualS2S2(*itc) && !((*itv).membre)) {
                (*itv).membre = true;
                Sommet& s2 = sommets.at((*itv).fin);
                for(vector<Arrete>::iterator its2 = s2.voisins.begin(); its2 != s2.voisins.end(); ++its2) {
                    if((*its2).isEqualS1S2(*itv) && (*its2).isEqualS2S1(*itv))  {
                        (*its2).membre = true;
                    }
                }
            }
        }
    }
}

// imprime le MST et le poids total sur stdout.
void Carte::printMst() {
    int poidsTotal = 0;

    sort(route.begin(), route.end(), sortArretes());

    for(vector<Arrete>::const_iterator it = route.begin(); it != route.end(); ++it) {
        if((*it).debut < (*it).fin) {
            cout << indexesInv[(*it).debut] << " " << indexesInv[(*it).fin] << endl;
        } else {
            cout << indexesInv[(*it).fin] << " " << indexesInv[(*it).debut] << endl;
        }
        cout << (*it).rue << endl;
        cout << (*it).poids << endl;
        poidsTotal += (*it).poids;
    }
    cout << "---" << endl;
    cout << poidsTotal << endl;
}

// lecture de la carte (prise dans le labo 12).
// validation minimale puisque rien de plus poussé
// n'a été demandé.
istream& operator >> (istream& is, Carte& carte)
{
    int nbNoeuds = 0, nbRoutes = 0, nbRefs = 0;
    while(is){
        string nom;
        is >> nom;
        if(nom == "---") break;
        assert(nom[0] =='n');
        Coordonnee coor;
        is >> coor;
        carte.ajouterSommet(nom, coor);
        nbNoeuds++;
    }
    while(is){
        string nom;
        int poids = 0;
        is >> nom;
        if(nom == "---") break;
        char dp;
        is >> dp;
        assert(dp == ':');
        std::list<string> lieux;
        while(is){
            string nomlieu;
            is >> nomlieu;
            if(nomlieu==";") break;
            assert(nomlieu!=":");
            assert(nomlieu.find(";")==string::npos);
            if(nomlieu[0] != 'n') {
                poids = stoi(nomlieu);
            } else {
                lieux.push_back(nomlieu);
                nbRefs++;
            }
        }
        carte.ajouterRoute(nom, lieux, poids);
        nbRoutes++;
    }
    return is;
}
