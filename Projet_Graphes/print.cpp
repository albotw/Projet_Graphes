#include "print.h"


void printGraphe(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Sommet " << i << " -> ";
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 1)
            {
                cout << " " << j;
            }
        }

        cout << endl;
    }
}

void printGrapheRaw(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }
}

void printTab(int tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << " - ";
    }
    cout << endl;
}

void printVoisins()
{
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            cout << "voisin[" << i << "][" << j << "] -> ";
            for (int k = 0; k < voisins[i][j].size(); k++)
            {
                cout << voisins[i][j][k] << ", ";
            }
            cout << endl;
        }
    }
}