#ifndef _H_GLOBALS_
#define _H_GLOBALS_
#include <iostream>
using namespace std;

inline int n;
inline int k;
inline int *adj = NULL;
inline int *voisins = NULL;
inline int *couleur1 = NULL;
inline int *couleur2 = NULL;
inline int *DSAT = NULL;
inline int *degre = NULL;
inline bool trouve = false;
inline bool single = true;

inline int at(int *tab, int i, int j) { return tab[i * 2 * n + j]; }
inline void set(int *tab, int i, int j, int value) { tab[i * 2 * n + j] = value; }

#endif