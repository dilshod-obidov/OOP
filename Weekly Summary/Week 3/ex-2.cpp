#include <iostream>

using namespace std;

void MatInput(int*, int, int);
void MatAdd(int*, int*, int*, int, int);
void MatDisplay(int*, int, int);

int main() {
	int row, col;
	int* mat1, * mat2, * matAdd;

	cout << "Enter size of matrix (row, col): ";
	cin >> row >> col;

	// 1. allocate the memory buffers for the 3 matrices
	mat1 = new int[row*col];
	mat2 = new int[row*col];
	matAdd = new int[row*col];

	// 2. use the buffers
	cout << "Enter elements in 1st matrix of size " << row << "x" << col << ":\n";
	MatInput(mat1, row, col);
	cout << "Enter elements in 2nd matrix of size " << row << "x" << col << ":\n";
	MatInput(mat2, row, col);

	MatAdd(mat1, mat2, matAdd, row, col);

	cout << "Sum of two matrices: \n";
	MatDisplay(matAdd, row, col);

	// 3. free the allocated buffers
	delete[] mat1;
	delete[] mat2;
	delete[] matAdd;

	return 0;
}

void MatInput(int* mat, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> mat[i*col + j];
		}
	}
}
void MatAdd(int* mat1, int* mat2, int* matAdd, int row, int col) {
	for (int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++)
			matAdd[i*col + j] = mat1[i*col + j] + mat2[i*col + j];
	}
}
void MatDisplay(int* madAdd, int row, int col) {
	for (int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++)
			cout << madAdd[i*col + j] << " ";
		cout << endl;
	}
}