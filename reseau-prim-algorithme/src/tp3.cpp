#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <math.h>
#include "carte.h"
#include "coordonnee.h"

using namespace std;

void tp3(Carte& carte){
    carte.findMst();
    carte.printMst();
}

int main(int argc, const char** argv)
{

    if(argc!=2){
        cout << "Syntaxe: ./tp3 carteVisites.txt" << endl;
        return 1;
    }

    Carte carte;
    {
        ifstream fichiercarte(argv[1]);
        if(fichiercarte.fail()){
            cout << "Erreur ouverture du fichier : " << argv[1] << endl;
            return 1;
        }
        fichiercarte >> carte;
    }

    tp3(carte);
    return 0;
}
