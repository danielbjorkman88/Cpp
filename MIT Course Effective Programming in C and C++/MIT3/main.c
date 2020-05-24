#include <stdio.h>
#include <stdlib.h>

#define MAXN 300

typedef struct Matrix {
  size_t R, C;
  int *index;
} Matrix;

Matrix* allocate_matrix( size_t R, size_t C ) {
  Matrix *matrix = malloc( sizeof( Matrix ) );
  matrix->R = R;
  matrix->C = C;
  matrix->index = malloc( R * C * sizeof( int ) );
  return matrix;

}



void destroy_matrix( Matrix *matrix ) {
  free( matrix->index );
  free( matrix );
}

Matrix* readMatrix( FILE *input ){
size_t R,C;

fscanf( input, "%zu %zu", &R, &C );

Matrix *matrix = NULL;

matrix = allocate_matrix( R, C );
  for( int r = 0; r < matrix->R; ++r ) {
    for( int c = 0; c < matrix->C; ++c ) {
      fscanf( input, "%d", &matrix->index[c + r * C] );
    }
  }
  return matrix;
}


Matrix* matrixMultiplication(Matrix *matrixA, Matrix *matrixB){

    Matrix *outMatrix = NULL;
    outMatrix = allocate_matrix( matrixA->R, matrixA->R );
    size_t nCols = outMatrix->R;
    size_t nInner = matrixA->C;

    for (int row = 0; row < matrixA->R ; ++row){
        for (int col = 0; col < matrixA->R ; ++col){
            outMatrix->index[col + row * nCols] = 0;
            for( size_t i = 0; i < matrixA->C; ++i ) {
            outMatrix->index[col + row * nCols] += matrixA->index[i + row*nInner] * matrixB->index[col + i*nCols];
            ///OutMatrix->index[row][col] +=  matrixA->index[row][i] * matrixB->index[i][col];
            ///prod->index[c + r * nCols] += a->index[i + r * nInner] * b->index[i + c * nInner]

            }
        }
    }
    return outMatrix;
}


/*

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

*/

void dispMatrix( Matrix *matrix){
printf("R = %d C = %d", matrix->R , matrix->C);
printf("\n");

for (int r = 0 ; r < matrix->R  ; ++r){
for (int c = 0 ; c < matrix->C  ; ++c){
 printf("%d ", matrix->index[c + r*matrix->C]);
}
printf("\n");
}
printf("\n");
}



int main()
{

  FILE *input  = fopen( "matrix2.1.in",  "r" ),

       *output = fopen( "matrix2.1my.out", "w" );



Matrix *matrixA = readMatrix(input);
Matrix *matrixB = readMatrix(input);


Matrix *outMatrix = matrixMultiplication( matrixA , matrixB );

dispMatrix(matrixA);
dispMatrix(matrixB);
dispMatrix(outMatrix);

/*
if (matrixA.R == matrixB.C){
    matrixMultiplication(&matrixA, &matrixB, &OutMatrix);
    ///printf( "%d ", OutMatrix.index[0][0] );
    writeMatrix(output, &OutMatrix);
}
else{
    fprintf( output, "%d", 0 );
}
*/
fclose( input );
  fclose( output );


    return 0;
}
