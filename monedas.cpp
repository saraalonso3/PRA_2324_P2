#include<iostream>
#include <limits>

int cambio (int N, int *v, int M){
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
				return 0;
			 }
			 if ( i == 0 && v[i] > j){
				int infinito = std::numeric_limits<int>::max();
                                return infinito;
			 }
			 if









	for(int i=0; i<N; i++){
		 for(int j = 0; j<=M; j++){
			 std::cout<<matrix[i][j]<<" ";
		 }
		 std::cout<<std::endl;
	}
}	



int main(){
	int N = 3; int M = 8; int *v;
	cambio(N, v, M);
	return 0;
}

