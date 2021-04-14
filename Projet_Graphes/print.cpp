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