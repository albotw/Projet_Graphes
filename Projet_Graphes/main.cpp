#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
#include <random>
#include <vector>
#include <chrono>

#include "globals.h"
#include "print.h"
#include "DSAT.h"
#include "colorExact.h"

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

using namespace std;

void generateGraphe(int n, int k)
{
    if (n >= 3 && 1 <= k <= n / 2)
    {
        //boucle polygone externe
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1) //cas general
            {
                set(adj, i, i + 1, 1);
                set(adj, i + 1, i, 1);
            }
            else //fermeture
            {
                set(adj, i, 0, 1);
                set(adj, 0, i, 1);
            }

            //liaison
            set(adj, i, i + n, 1);
            set(adj, i + n, i, 1);
        }
        

        //boucle polygone interne
        for (int i = n; i < 2*n; i++)
        {
            //application du modulo si dépassement de tableau
            int delta = i + k > 2 * n - 1? (i % n) + k : i + k;
            set(adj, i, delta, 1);
            set(adj, delta, i, 1);
        }
        
        if (k == 1)
        {
            //fermeture polygone interne
            set(adj, 2 * n - 1, n, 1);
            set(adj, n, 2 * n - 1, 1);
        }

    }
}

void voisinCommun(int p1, int p2)
{
    for (int i = 0; i < 2 * n; i++)
    {
        if(at(adj, p1, i) == 1 && at(adj, p2, i) == 1)
        {
            set(voisins, p1, p2, 1);
        }
    }
}



void reset()
{
    if (adj != NULL) delete[] adj;
    if (voisins != NULL) delete[] voisins;
    if (couleur1 != NULL) delete[] couleur1;
    if (couleur2 != NULL) delete[] couleur2;
    if (DSAT != NULL) delete[] DSAT;
    if (degre != NULL) delete[] degre;
    
    adj = new int[2 * n * 2 * n]();
    voisins = new int[2 * n * 2 * n]();
    couleur1 = new int[2 * n]();
    couleur2 = new int[2 * n]();
    DSAT = new int[2 * n]();
    degre = new int[2 * n]();
    trouve = false;
}

void generateVoisins()
{
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            if (i != j)
            {
                voisinCommun(i, j);
            }
        }
    }
}

void loop()
{
    for (k; k <= n / 2; k++)
    {
        cout << endl;
        cout << "n: " << n << " k: " << k << endl;
        reset();
        generateGraphe(n, k);
        generateVoisins();
        auto start = high_resolution_clock::now();
        int nCouleurs = DSATUR();
        auto end = high_resolution_clock::now();
        auto delta = duration_cast<milliseconds>(end - start);
        cout << "resultat DSAT: " << nCouleurs;
        cout << " | " << delta.count() << " ms" << endl;
        printTab(couleur2, 2 * n);

        start = high_resolution_clock::now();
        int i = 0;
        do
        {
            trouve = false;
            colorExact(i);
            i++;
        } while (!trouve);
        end = high_resolution_clock::now();
        delta = duration_cast<milliseconds>(end - start);
        cout << "obtenu en " << delta.count() << " ms" << endl;
    }
}

int main()
{
    cout << "entrez n" << endl;
    cin >> n;
    cout << "entrez k" << endl;
    cin >> k;
    loop();
    /*
    reset();

    generateGraphe(n, k);

    cout << "arcs: " << endl;
    printGraphe(2*n);
    cout << "matrice d'adjacence: " << endl;
    printGrapheRaw(2*n);

    for (int i = 0; i < 2*n; i++)
    {
        for (int j = 0; j < 2*n; j++)
        {
            if (i != j)
            {
                voisinCommun(i, j);
            }
        }
    }

    cout << "affichage colorExact" << endl;
    colorExact(6);
    
    cout << "affichage DSATUR" << endl;
    cout << DSATUR() << endl;

    cout << "résultats colorExact: " << endl;
    printTab(couleur1, 2 * n);
    cout << "résultats DSATUR: " << endl; 
    printTab(couleur2, 2 * n);

    //int k = DSATUR();
    //cout << "DSAT: coloration en " << k << endl;

    //printTab(couleur2, n);
    */
    return 0;
}