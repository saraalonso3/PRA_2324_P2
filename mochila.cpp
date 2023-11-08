#include<iostream>
#include<algorithm>
// M --> peso maximo
int mochila(int N, int *p ,int *b , int M){ // b es el vector beneficio y p contiene los pesos
	int** matrix = new int*[N];	

	for(int i=0; i<N; i++){
		matrix[i] = new int[M + 1];
		for(int j = 0; j<=M; j++){
			matrix[i][j] = 0;
		}
	}

	for(int i=0; i<N; i++){
                 for(int j = 0; j<=M; j++){
			if( i == 1){
				 if( p[i] <  ){
					 matrix[i][j] = b[1];
				 }
				 else{
					 matrix[i][j] = 0;
				 }
			}

			else if( p[i] > M){
			 	matrix[i][j] = matrix[i - 1][j];
			} 
		   
			else {
				matrix[i][j] = std::max(matrix[i - 1][j], b[i] + matrix[i - 1][j - p[i]]);
	
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

int main(){
	int N = 3; int M = 15; int p[N]={9,6,5};
	int b[N]={38,40,24};
	int beneficio = mochila(N, p, b, M);
	std::cout<<"El beneficio de la mochila es de: "<<beneficio<<std::endl;
	return 0;
}
