#pragma once
#include <vector>

using namespace std;
inline const int n = 7;
inline const int k = 3;
inline int adj[2 * n][2 * n];
inline vector<int> voisins[2 * n][2 * n];
inline int couleur1[2 * n];
inline int couleur2[2 * n];
inline int DSAT[2 * n];
inline int degre[2 * n];
inline bool trouve = false;