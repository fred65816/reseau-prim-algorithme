#if !defined(_ARRETE__H_)
#define _ARRETE__H_

#include <string>

using namespace std;

class Arrete {
    public:
        Arrete();
        Arrete(const Arrete& a);
        Arrete(const int s1_, const int s2_, const string& rue_,
               const int poids_, const double distance_);

        bool isEqualS1S2(const Arrete& arrete);
        bool isEqualS2S1(const Arrete& arrete);
        bool isEqualS1S1(const Arrete& arrete);
        bool isEqualS2S2(const Arrete& arrete);
        Arrete& operator=(const Arrete& arrete);
        bool operator<(const Arrete& arrete);

        // le sommet de départ.
        int debut;
        // le sommet de fin.
        int fin;
        // le poids de l'arrête.
        int poids;
        // true si on a pas besoin de vérifier cette arrête,
        // par exemple quand ses deux sommet font parti de la route
        // sans que cette arrête en fasse partie.
        bool membre;
        // le noom de la rue par laquelle passe l'arrête.
        string rue;

    private:
        // la distance entre le sommet de départ et de fin.
        double distance;
};

#endif
