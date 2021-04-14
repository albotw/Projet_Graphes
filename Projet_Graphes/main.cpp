#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
#include <random>
#include <vector>

#include "globals.h"
#include "print.h"
#include "DSAT.h"

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
                adj[i][i + 1] = 1;
                adj[i + 1][i] = 1;
            }
            else //fermeture
            {
                adj[i][0] = 1;
                adj[0][i] = 1;
            }

            //liaison
            adj[i][i + n] = 1;
            adj[i + n][i] = 1;
        }
        

        //boucle polygone interne
        for (int i = n; i < 2*n; i++)
        {
            //application du modulo si dépassement de tableau
            int delta = i + k > 2 * n - 1? (i % n) + k : i + k;
            adj[i][delta] = 1;
            adj[delta][i] = 1;
        }
        
        if (k == 1)
        {
            //fermeture polygone interne
            adj[2 * n - 1][n] = 1;
            adj[n][2 * n - 1] = 1;
        }

    }
}





int main()
{
    generateGraphe(n, k);

    printGraphe(2*n);
    printGrapheRaw(2*n);

    //int k = DSATUR();
    //cout << "DSAT: coloration en " << k << endl;

    //printTab(couleur2, n);

    return 0;
}