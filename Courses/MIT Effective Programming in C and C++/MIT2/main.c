#include <stdio.h>
#include <stdlib.h>

#define MAXN 300

typedef struct Matrix {
  size_t R, C;
  int index[MAXN][MAXN];
} Matrix;


void readMatrix( FILE *input, Matrix *matrix ){
fscanf( input, "%d %d", &matrix->R, &matrix->C );
///printf("%d %d\n", matrix->R, matrix->C);
  for( int r = 0; r < matrix->R; ++r ) {
    for( int c = 0; c < matrix->C; ++c ) {
      fscanf( input, "%d", &matrix->index[r][c] );
    }
  }

}

void matrixMultiplication(Matrix *matrixA, Matrix *matrixB, Matrix *OutMatrix){

    OutMatrix->R = matrixA->R;
    OutMatrix->C = matrixA->R;

    for (int row = 0; row < matrixA->R ; ++row){
        for (int col = 0; col < matrixA->R ; ++col){

            for( size_t i = 0; i < matrixA->C; ++i ) {
            OutMatrix->index[row][col] +=  matrixA->index[row][i] * matrixB->index[i][col];

            }
        }
    }
}

void writeMatrix(FILE *output, Matrix *OutMatrix){
    fprintf( output, "%zu %zu\n", OutMatrix->R, OutMatrix->C );
    ///printf( "%zu %zu", OutMatrix->R, OutMatrix->C );
    for (int row = 0 ; row < OutMatrix->R ; ++row){
        for (int col = 0; col < OutMatrix->R ; ++col){
            ///printf( "%d ", OutMatrix->index[row][col] );
            fprintf( output, "%d ", OutMatrix->index[row][col] );
        }
        fprintf( output, "\n" );
    }
}

int main()
{

  FILE *input  = fopen( "matrix.1.in",  "r" ),

       *output = fopen( "matrix.1my.out", "w" );

Matrix matrixA;
Matrix matrixB;
Matrix OutMatrix;

readMatrix(input, &matrixA);
readMatrix(input, &matrixB);
fclose( input );

if (matrixA.R == matrixB.C){
    matrixMultiplication(&matrixA, &matrixB, &OutMatrix);
    ///printf( "%d ", OutMatrix.index[0][0] );
    writeMatrix(output, &OutMatrix);
}
else{
    fprintf( output, "%d", 0 );
}

/*

  for( int r = 0; r < OutMatrix.R; ++r ) {
    for( int c = 0; c < OutMatrix.C; ++c ) {
        printf( "%d ", OutMatrix.index[r][c] );
    }
  }




fscanf( input, "%d %d", &matrixA.R, &matrixA.C );



int a,b;
fscanf( input, "%d", &matrixA.index[0][0] );
printf("%d\n", matrixA.index[0][0]);
fscanf( input, "%d", &matrixA.index[0][1] );
printf("%d\n", matrixA.index[0][1]);
fscanf( input, "%d", &matrixA.index[1][0] );
printf("%d\n", matrixA.index[1][0]);
fscanf( input, "%d", &matrixA.index[1][1] );
printf("%d\n", matrixA.index[1][1]);


double a;


  for( int r = 0; r < matrixA.R; ++r ) {
    for( int c = 0; c < matrixA.C; ++c ) {
        fscanf( input, "%d", &matrixA.index[r][c] );
    }
  }
printf("%d %d\n", matrixA.R, matrixA.C);
printf("%d\n", matrixA.index[0][0]);

*/


  fclose( output );


    return 0;
}
