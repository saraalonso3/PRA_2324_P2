#include<iostream>
#include <limits>
#include<algorithm>
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
			 if ( i == 0 && v[i] > j){
				int infinito = std::numeric_limits<int>::max();
                                matrix[i][j] = infinito;
			 }
			 if ( i == 0){
				matrix[i][j] = 1 + matrix[1, j - v[i]];
			 }
			 if( v[i] > j){
				 matrix[i][j] = matrix[i -1, j];
			 }
			 else{
				 matrix[i][j] = std::min(matrix[i-1, j], 1 + matrix[i, j - v[i]] );
			 }
		 }
	
	}

	for(int i = 0; i < N; i++){
		for(int j = 0;j <= M; j++){
			std::cout<<matrix[i][j]<< " ";
		}
		std::cout<<std::endl;
	}

	return matrix[N-1][M];
}

	



int *vectorSolucion (int *v, int **matrix) {
	int *x;
	for(int i = 0; i < N; i++){
		x[i] = 0;
	}
	int i = N-1; int j = M;
	
	while(i > 0 && j > 0){
		if( matrix[i][j] = 1 + matrix[i][j - v[i]] ){
			x[i] = x[i] + 1;
			j = j - v[i];
		}
		else{
			i = i - 1;
		}
	}
	return x;
}




int main(){
	int N = 3; int M = 8; int v[3]={1,4,6};
	cambio(N, v, M);
	vectorSolucion(v, **matrix);
	return 0;
}

