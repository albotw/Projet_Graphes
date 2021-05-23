#include <stdlib.h>
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

using namespace std;
using namespace std::chrono;

void generateGraphe(int n, int k)
{
    if (n >= 3 && 1 <= k && k <= n / 2)
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
        for (int i = n; i < 2 * n; i++)
        {
            //application du modulo si d�passement de tableau
            int delta = i + k > 2 * n - 1 ? (i % n) + k : i + k;
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
        if (at(adj, p1, i) == 1 && at(adj, p2, i) == 1)
        {
            set(voisins, p1, p2, 1);
        }
    }
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

void reset()
{
    if (adj != NULL)
        delete[] adj;
    if (voisins != NULL)
        delete[] voisins;
    if (couleur1 != NULL)
        delete[] couleur1;
    if (couleur2 != NULL)
        delete[] couleur2;
    if (DSAT != NULL)
        delete[] DSAT;
    if (degre != NULL)
        delete[] degre;

    adj = new int[2 * n * 2 * n]();
    voisins = new int[2 * n * 2 * n]();
    couleur1 = new int[2 * n]();
    couleur2 = new int[2 * n]();
    DSAT = new int[2 * n]();
    degre = new int[2 * n]();
    trouve = false;

    generateGraphe(n, k);
    generateVoisins();
}

void loop()
{
    cout << endl;
    cout << "n: " << n << " k: " << k << endl;
    reset();

    auto startDSAT = high_resolution_clock::now();

    int nCouleurs = DSATUR();

    auto endDSAT = high_resolution_clock::now();

    cout << "resultat DSAT: " << nCouleurs << " | " << duration_cast<milliseconds>(endDSAT - startDSAT).count() << " ms" << endl;
    printTab(couleur2, 2 * n);

    auto startExact = high_resolution_clock::now();
    int i = 0;
    do
    {
        trouve = false;
        colorExact(i);
        i++;
    } while (!trouve);
    auto endExact = high_resolution_clock::now();

    cout << "obtenu en " << duration_cast<milliseconds>(endExact - startExact).count() << " ms" << endl;
}

int main()
{
    cout << "entrez n" << endl;
    cin >> n;

    cout << "entrez k" << endl;
    cin >> k;

    char tmp = '\0';
    cout << "simple/multiple ? (s|m)" << endl;
    cin >> tmp;
    tmp == 's' ? single = true : single = false;

    if (!single)
    {
        for (; k <= n / 2; k++)
        {
            loop();
        }
    }
    else
    {
        loop();
    }
    return 0;
}