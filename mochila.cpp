#include<iostream>
#include<algorithm>
// M --> peso maximo
//
int *vectorSolucion (int *p, int *b, int **matrix, int N, int M){

	int *x = new int[N];
        for(int i = 0; i < N; i++){
                x[i] = 0;
        }
        int i = N; int j = M;

        while(i > 0 && j > 0){
                if( i == 1 && matrix[i][j] == b[i]){
			x[i] = 1;
		}

		else if( matrix[i][j] == b[i] + matrix[i-1][j - p[i]] ){
                        x[i] = 1;
                        j = j - p[i];
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

int mochila(int N, int *p ,int *b , int M){ // b es el vector beneficio y p contiene los pesos
	int** matrix = new int*[N];	

	for(int i=0; i<=N; i++){
		matrix[i] = new int[M + 1];
		for(int j = 0; j<=M; j++){
			matrix[i][j] = 0;
		}
	}

	for(int i=0; i<=N; i++){
                 for(int j = 0; j<=M; j++){
			if( i == 0){
				matrix[i][j] = 0;
			}
			else if(j == 0){
				matrix[i][j] = 0;
			}
			else if (i == 1 && p[i] < j){
				matrix[i][j] = b[i];
			}
					
			else if( p[i] > j){
			 	matrix[i][j] = matrix[i - 1][j];
			} 
		   
			else {
				matrix[i][j] = std::max(matrix[i - 1][j], matrix[i - 1][j - p[i]] + b[i]);
	
			} 
		}
	}


for(int i = 0; i <= N; i++){
                for(int j = 0;j <= M; j++){
                        std::cout<<matrix[i][j]<< " ";
                }
                std::cout<<std::endl;
        }

	int *x = vectorSolucion (b,p, matrix, N, M);

	return matrix[N-1][M];
}

int main(){
	int N = 3; int M = 15; int p[4]={0,9,6,5};
	int b[4]={0,38,40,24};
	int beneficio = mochila(N, p, b, M);
	std::cout<<"El beneficio de la mochila es de: "<<beneficio<<std::endl;
	return 0;
}
