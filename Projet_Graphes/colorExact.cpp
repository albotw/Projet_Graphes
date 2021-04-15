#include "colorExact.h"

//test si la couleur c peut être donnée au point
//(pas utilisée par un de ses voisins).
bool convient(int pt, int couleur)
{

    for (int i = 0; i < 2 * n; i++)
    {
        //si pt et i sont voisins
        if (adj[pt][i])
        {
            if (abs(couleur - couleur1[i]) < 2)
            {
                return false;
            }
        }

        if (!voisins[pt][i].empty())
        {
            if (abs(couleur - couleur1[i]) < 1)
            {
                return false;
            }
        }
    }

    return true;
}

//test récursif de toutes les couleurs possibles pour un point.
void colorRR(int pt, int nCouleurs)
{
    if (pt == 2*n -1)
    {
        cout << "coloration en " << nCouleurs << endl;
        for (int i = 0; i < 2*n; i++)
        {
            cout << "couleur de " << i << " : " << couleur1[i] << endl;
        }
        trouve = true;
    }
    else
    {
        for (int couleur = 1; couleur <= nCouleurs; couleur++)
        {
            if (convient(pt, couleur))
            {
                couleur1[pt] = couleur;
                cout << "couleur de " << pt << " : " << couleur1[pt] << endl;
                colorRR(pt + 1, nCouleurs);
                if (trouve) return;
            }
        }
    }
}

//teste toutes les combinaisons pour n couleurs
void colorExact(int nCouleurs)
{
    for (int i = 0; i < 2*n; i++)
    {
        couleur1[i] = 0;
        colorRR(0, nCouleurs);
        if (!trouve) cout << "pas de coloration en " << nCouleurs << " couleurs" << endl;
    }
    
}