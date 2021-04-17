#include "colorExact.h"

//test si la couleur c peut être donnée au point
//(pas utilisée par un de ses voisins).
bool convient(int pt, int couleur)
{
    for (int i = 0; i < 2 * n; i++)
    {
        
        if (couleur1[i] != 0)
        {
            
            //si pt et i sont voisins
            if (at(adj, pt, i) == 1)
            {
                if (abs(couleur - couleur1[i]) < 2)
                {
                    return false;
                }
            }

            if (at(voisins, pt, i) == 1)
            {
                if (abs(couleur - couleur1[i]) < 1)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

void copy(int* tab1, int* tab2)
{
    for (int i = 0 ; i < 2 * n ; i++)
    {
        tab1[i] = tab2[i];
    }
}

//test récursif de toutes les couleurs possibles pour un point.
void colorRR(int pt, int nCouleurs)
{
    int* temp = new int[2 * n]();
    copy(temp, couleur1);

    if (pt == 2*n)
    {
        
        cout << "resultat exact: " << nCouleurs << endl;
        /*for (int i = 0; i < 2*n; i++)
        {
            cout << "couleur de " << i << " : " << couleur1[i] << endl;
        }*/
        printTab(couleur1, 2 * n);
        trouve = true;
        delete[] temp;
    }
    else
    {
        for (int couleur = 1; couleur <= nCouleurs; couleur++)
        {
            if (convient(pt, couleur))
            {
                couleur1[pt] = couleur;
                //cout << "couleur de " << pt << " : " << couleur1[pt] << endl;
                colorRR(pt + 1, nCouleurs);
                if (trouve) return;
            }
        }
        copy(couleur1, temp);
        delete[] temp;
    }
}


//teste toutes les combinaisons pour n couleurs
void colorExact(int nCouleurs)
{
    
    for (int i = 0; i < 2 * n; i++)
    {
        couleur1[i] = 0;
    }
    colorRR(0, nCouleurs);
    if (!trouve) cout << "pas de coloration en " << nCouleurs << " couleurs" << endl;   
}