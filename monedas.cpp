#include<iostream>
#include <limits>
#include<algorithm>

int *vectorSolucion (int *v, int **matrix, int N, int M) {
        int *x = new int[N];
        for(int i = 0; i < N; i++){
                x[i] = 0;
        }
        int i = N-1; int j = M;

        while(i > 0 && j > 0){
                if( matrix[i][j] == 1 + matrix[i][j - v[i]] ){
                        x[i] = x[i] + 1;
                        j = j - v[i];
                }
                else{
                        i = i - 1;
                }
        }

	std::cout<<"El vector x es: x = ";

        for(int i = 0; i < N; i++){
                std::cout<<x[i]<<" ";
        }

	std::cout<<std::endl;
        return x;
}



int cambio (int N, int *v, int M) {
	int** matrix = new int*[N];
	for(int i=0; i<N; i++){
		matrix[i] = new int[M + 1];
		for(int j = 0; j<=M; j++){
			if( j == 0){
				matrix[i][j] = 0;
			}
			else{	
				matrix[i][j] = -1;
			}

		}
	}


        for(int i=0; i<N; i++){
                 for(int j = 0; j<=M; j++){
			 if( j == 0){
				matrix[i][j] = 0;
			 }
			 else if ( i == 0 && v[i] > j){
				//int infinito = std::numeric_limits<int>::max();
                                matrix[i][j] = 0;
			 }
			 else if ( i == 0){
				matrix[i][j] = 1 + matrix[i][j - v[i]];
			 }
			 else if( v[i] > j){
				 matrix[i][j] = matrix[i -1][j];
			 }
			 else{
				 matrix[i][j] = std::min(matrix[i-1][j], 1 + matrix[i][ j - v[i]] );
			 }
		 }
	
	} 

	for(int i = 0; i < N; i++){
		for(int j = 0;j <= M; j++){
	
			std::cout<<matrix[i][j]<< " ";
		}
		std::cout<<std::endl;
		}
	
	int *x = vectorSolucion (v, matrix, N, M);

	return matrix[N-1][M-1];
}





int main(){
	int N = 3; int M = 8; int v[N];
	v[0] = 1;
	v[1] = 4;
	v[2] = 6;

	int minMonedas = cambio(N, v, M);
	std::cout<< "Número mínimo de monedas necesarias: " << minMonedas << std::endl;

  

	return 0;
}

