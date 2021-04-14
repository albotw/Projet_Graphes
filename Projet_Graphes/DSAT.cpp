#include "DSAT.h"

bool convientDSAT(int point, int couleur)
{
    for (int i = 0; i < n; i++)
    {
        if (adj[point][i] && couleur2[i] == couleur)
            return false;
    }
    return true;
}

int dsatMax()
{
    int maxDeg = -1;
    int maxDSAT = -1;
    int sMax = 0;

    for (int i = 0; i < n; i++)
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

    for (int i = 0; i < n; i++)
    {
        couleur2[i] = 0;
        DSAT[i] = 0;
        degre[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j])
            {
                degre[i]++;
            }
        }
        DSAT[i] = degre[i];
    }

    while (cpt < n)
    {
        couleur = 1;
        max = dsatMax();
        while (!convientDSAT(max, couleur))
        {
            couleur++;
        }
        for (int j = 0; j < n; j++)
        {
            if (adj[max][j] && convientDSAT(j, couleur))
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