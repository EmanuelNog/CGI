#include <stdio.h>
#include <iostream>
#include <vector>
#include "matriz.h"

using namespace std;

int main(){
    
    double x=1;
    double y = 2;
    int l,c;
    int m=1,n=3,k=3,j=3;

    vector<vector<double>> M_atual(1, vector<double>(3));

    M_atual[0][0] = {x};
    M_atual[0][1] = {y};
    M_atual[0][2] = {1};

    double M_deOperacao[j][k] = { {-1,0,0},
                                  {0,-1,0},
                                  {0,0,1}  };
    vector<vector<double>> M_novo(m, vector<double>(n));

    vector<vector<double>> M_auxiliar = multiplicarMatriz(M_atual,M_deOperacao);

    cout << "atual:" << endl;
    // for(int p=0; p<m; p++)
    //     for(int q=0; q<n; q++)
    //         cout << M_atual[p][q]<<endl;

    // for (l=0; l < m; l++)
    //     for (c=0; c < k; c++){
    //         M_novo[l][c] = 0;
    //         for (int w=0; w < k; w++)
	//             M_novo[l][c] = M_novo[l][c] + M_atual[l][w] * M_deOperacao[w][c];
    //     }

    cout << "novo:" << endl;
    for(int p=0; p<m; p++)
        for(int q=0; q<n; q++)
            cout << M_auxiliar[p][q]<<endl;

    M_novo = M_atual;

    cout << "novo do novo:" << endl;
    for(int p=0; p<m; p++)
        for(int q=0; q<n; q++)
            cout << M_novo[p][q]<<endl;

    return 0;
}
