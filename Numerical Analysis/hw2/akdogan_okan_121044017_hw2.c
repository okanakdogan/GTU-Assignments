/*	Okan Akdogan 121044017
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
// default values
#define MATRIX_SIZE 5
#define VALUE_MIN 1
#define VALUE_MAX 5
// functions
double compute_determinant(int matrix[MATRIX_SIZE][MATRIX_SIZE]);
void matrix_create(int matrix[MATRIX_SIZE][MATRIX_SIZE], int min_val, int max_val);
void matrix_print(int matrix[MATRIX_SIZE][MATRIX_SIZE]);

double determinant(int* matrix,int size);
int * reduceMatrix(int * matrix,int*reduced, int row, int col, int dim);

// main function
int main(int argc, char *argv[])
{
	// variables
	int matrix[MATRIX_SIZE][MATRIX_SIZE];
	int row, column;
	// generate different numbers
	srand(time(NULL));
	// create a matrix with random numbers
	matrix_create(matrix, VALUE_MIN, VALUE_MAX);
	// print matrix
	matrix_print(matrix);
	// calculate determinant of matrix
	printf("Determinant of NxN Matrix:\t%f\n", compute_determinant(matrix));
	return 0;
}
// compute determinent of matrix
double compute_determinant(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
	// ...
	// describe your algorithm as a pseudocode in here
	// ...
	/*
		Make matrix dynamic matrix
		
		send matrix "determinent" func

		**determinent func**

		if matrix size < 4
			calculate determinent
		else
			send matrix "reduce" func
			send reduced matrix to "determinent" func

		return determinent

		**reduce func**
			create matrix dynamic orj. size-1
			reduce given row and column copy rest of matrix.
			return reducedMatrix   

	*/
	
	// write your real algorithms code in here!
	
	int i,j,mSize=MATRIX_SIZE;
	int * matrixDyn=malloc(sizeof(int)*(mSize)*(mSize));
	double det=0.0;
	/*Make dynamic array */
	if(matrixDyn!=NULL){
		/*copy values*/
		for(i=0;i<mSize;++i)
			for(j=0;j<mSize;++j)
				matrixDyn[i*mSize+j]=matrix[i][j];
		/*find Determinent*/
		det=determinant(matrixDyn,mSize);

		/*relase memory*/
		free(matrixDyn);

		return det;
	}
	else
		return 0;

	// Your are allowed to change necessary parts of this function
	// based on your algorithm
	
	// DO NOT forget to write comments

	return 0.0;
}
// print matrix
void matrix_print(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
	int row, column;

	for(row = 0; row < MATRIX_SIZE; row++) {
		for(column = 0; column < MATRIX_SIZE; column++) {
			printf("%d\t", matrix[row][column]);
		}
		printf("\n");
	}
}
// create matrix
void matrix_create(int matrix[MATRIX_SIZE][MATRIX_SIZE], int min_val, int max_val) {
	int row, column;
	srand(time(NULL));

	for(row = 0; row < MATRIX_SIZE; row++) {
		for(column = 0; column < MATRIX_SIZE; column++) {
			matrix[row][column] = (rand() % (max_val-min_val+1)) + min_val;
		}
	}
}

double determinant(int* matrix,int mSize){
    int *reducedM=NULL;
	double result=0;
	int p1=1,p2=1;
	int i,j,h;
	/*if matrix little enough find det classic way
		else reduce matrix*/
	if(mSize<4){
        for(i=0;i<mSize;++i){
            p1=1; p2=1;

            for(j=0;j<mSize;++j){

                p1 *= matrix[((j + i + 1) % mSize)*mSize+j];
                p2 *= matrix[((j + i + 1) % mSize)*mSize+mSize - j - 1];

            }
             result+=p1-p2;
        }
        return result;

	}
	else{
		/*create an array smaller than first matrix*/
        reducedM=malloc(sizeof(int)*(mSize-1)*(mSize-1));

		
        if (reducedM!=NULL){

            for ( h = 0; h < mSize; h++)
            {

                if (matrix[h*mSize+0] == 0)
                    continue;
                /*reduce matrix*/
                reduceMatrix(matrix,reducedM , h, 0, mSize);
                

				/*find determinent*/
                if (h % 2 == 0) result -= determinant(reducedM,mSize-1 ) * matrix[h*mSize+0];
                if (h  %2 == 1) result += determinant(reducedM,mSize-1 ) * matrix[h*mSize+0];
                
            } //end loop


         free(reducedM);
         return result;
        }
        return 0;
    }

}


int * reduceMatrix(int * matrix,int*reduced, int row, int col, int dim){

    int r=0,c=0,j=0,k=0;
	/*check dynamic array location*/
    if(reduced==NULL){

        return NULL;
    }
    else{

        for(r=0,j=0;r<dim;++r){
			/*if given row don't copy*/
            if (r==row)
                continue;
            for(c=0,k=0;c<dim;++c){
			/*if given column don't copy*/
                if(c==col)
                    continue;
                reduced[j*(dim-1)+k]=matrix[r*dim+c];
                ++k;
            }
            ++j;
        }
        return reduced;
    }

}
