#include "DSAT.h"

bool convientDSAT(int point, int couleur)
{
    for (int i = 0; i < 2 * n; i++)
    {
        if (couleur2[i] != 0)
        {
            //si pt et i sont voisins
            if (at(adj, point, i))
            {
                if (abs(couleur - couleur2[i]) < 2)
                {
                    return false;
                }
            }

            if (at(voisins, point, i))
            {
                if (abs(couleur - couleur2[i]) < 1)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int dsatMax()
{
    int maxDeg = -1;
    int maxDSAT = -1;
    int sMax = 0;

    for (int i = 0; i < 2 * n; i++)
    {
        if (couleur2[i] == 0 && (DSAT[i] > maxDSAT || (DSAT[i] == maxDSAT && degre[i] > maxDeg)))
        {
            maxDSAT = DSAT[i];
            maxDeg = degre[i];
            sMax = i;
        }

    }
    return sMax;
}

int DSATUR()
{
    int cpt = 0;
    int couleur = 0;
    int max = 0;
    int couleurMax = 0;

    for (int i = 0; i < 2 * n; i++)
    {
        couleur2[i] = 0;
        DSAT[i] = 0;
        degre[i] = 0;
        for (int j = 0; j < 2 * n; j++)
        {
            if (at(adj, i, j))
            {
                degre[i]++;
            }
        }
        DSAT[i] = degre[i];
    }

    while (cpt < 2 * n)
    {
        couleur = 1;
        max = dsatMax();
        while (!convientDSAT(max, couleur))
        {
            couleur++;
        }
        for (int j = 0; j < 2 * n; j++)
        {
            if (at(adj, max, j) && convientDSAT(j, couleur))
            {
                DSAT[j]++;
            }
        }

        couleur2[max] = couleur;
        if (couleurMax < couleur)
        {
            couleurMax = couleur;
        }
        cpt++;
    }
    return couleurMax;
}