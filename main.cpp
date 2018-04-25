/*
    TP graphes

    G�n�rer un graphe � partir des �l�ments suivants :
    - N : nombre de noeuds
    - C : nombre de couleurs disponibles pour colorier chaque neud
    - D : densit� du graphe

    Le graphe prendra la forme d'une matrice.

    La g�n�ration sera faite en 2 temps :
    - une fonction pour cr�er le graphe
    - une fonction pour colorier le graphe
*/

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

short calc_nb_arretes (short N, double D);
void creer_graphe (vector<vector<bool>> &matrice_graphe, short N, double D) ;
void coloriser_graphe (vector<short> &matrice_couleurs, short N, short C) ;

int main()
{
    cout << "Creation d'un graphe en cours." << endl;

    short i, j ;
    short N = 8 ; // Nombre de noeuds
    short C = 3 ; // Nombre de couleurs disponibles
    double D = 0.5 ; // Densit� du graphe � cr�er

    srand(time(NULL));

    // Cr�ation matrice graphe
    vector<vector<bool>> matrice_graphe (N, vector<bool> (N,0));

    // Cr�ation arr�tes/connexions liant les noeuds
    creer_graphe(matrice_graphe, N, D);

    // Afficher matrice graphe
    for (i=0; i<N; i++)
    {
        for (j=0; j<i; j++)
            cout << " " << matrice_graphe[i][j] << " " ;

        cout << " \\ " << endl ;
    }

    // Colorisation du graphe
    vector<short> matrice_couleurs (N, 0);
    coloriser_graphe(matrice_couleurs, N, C) ;


    return 0;
}


short calc_nb_arretes (short N, double D)
{
    return D*N*(N-1)/2; // TODO : et si le r�sultat n'est pas entier ?
}

void creer_graphe (vector<vector<bool>> &matrice_graphe, short N, double D)
{
    short i ;
    short nb_arretes = calc_nb_arretes(N, D);

    cout << "Nb arretes = " << nb_arretes << endl ;

    short v1, v2, noeud_depart, noeud_arrivee;

    for (i=0; i<nb_arretes ; i++)
    {
        //cout << "Arrete n�" << i << " :" << endl;
        do
        {
            v1 = rand()%N;
            v2 = rand()%N;

            // On n'utilisera que la partie inf�rieure de la matrice
            if (v1 > v2)
            {
                noeud_depart = v1 ;
                noeud_arrivee = v2 ;
            }
            else
            {
                noeud_depart = v2 ;
                noeud_arrivee = v1 ;
            }
        } while (   noeud_depart == noeud_arrivee // Pour �viter les boucles
                 || matrice_graphe[noeud_depart][noeud_arrivee] != 0
                 );

        matrice_graphe[noeud_depart][noeud_arrivee] = 1 ;
    }
}

void coloriser_graphe (vector<short> &matrice_couleurs, short N, short C)
{
    short i ;
    cout << "Couleurs : " << endl ;
    for (i=0; i<N ; i++)
    {
        matrice_couleurs[i] = rand()%C ;
        cout << "Noeud n " << i << " : " << matrice_couleurs[i] << endl ;
    }
}
