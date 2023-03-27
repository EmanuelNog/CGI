#include <stdio.h>
#include <iostream>
#include <vector>
#include "matriz.h"

vector multiplicarMatriz(vector<vector<double>> matriz1,vector<vector<double>> matriz1)  {

	vector<vector<double>> M_auxiliar;
	M_auxiliar = matriz1;

	for (int l=0; l < M_auxiliar.size(); l++)
		for (int c=0; c < M_auxiliar[l].size(); c++){
			M_auxiliar[l][c] = 0;
			for (int w=0; w < k; w++)
				M_auxiliar[l][c] = M_auxiliar[l][c] + matriz1[l][w] * matriz2[w][c];
		}

	return M_auxiliar;
}
