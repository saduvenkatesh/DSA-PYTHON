#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

// Function to add two matrices
Matrix add(Matrix A, Matrix B, int n) {
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Function to subtract two matrices
Matrix subtract(Matrix A, Matrix B, int n) {
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Strassen's Algorithm
Matrix strassen(Matrix A, Matrix B, int n) {
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = n / 2;
    Matrix A11(newSize, vector<int>(newSize)), A12(newSize, vector<int>(newSize));
    Matrix A21(newSize, vector<int>(newSize)), A22(newSize, vector<int>(newSize));
    Matrix B11(newSize, vector<int>(newSize)), B12(newSize, vector<int>(newSize));
    Matrix B21(newSize, vector<int>(newSize)), B22(newSize, vector<int>(newSize));

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j]; 
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    Matrix P1 = strassen(A11, subtract(B12, B22, newSize), newSize);
    Matrix P2 = strassen(add(A11, A12, newSize), B22, newSize);
    Matrix P3 = strassen(add(A21, A22, newSize), B11, newSize);
    Matrix P4 = strassen(A22, subtract(B21, B11, newSize), newSize);
    Matrix P5 = strassen(add(A11, A22, newSize), add(B11, B22, newSize), newSize);
    Matrix P6 = strassen(subtract(A12, A22, newSize), add(B21, B22, newSize), newSize);
    Matrix P7 = strassen(subtract(A11, A21, newSize), add(B11, B12, newSize), newSize);

    Matrix C(n, vector<int>(n, 0));

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
            C[i][j + newSize] = P1[i][j] + P2[i][j];
            C[i + newSize][j] = P3[i][j] + P4[i][j];
            C[i + newSize][j + newSize] = P5[i][j] + P1[i][j] - P3[i][j] - P7[i][j];
        }
    }

    return C;
}

// Function to print matrix
void printMatrix(Matrix A, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

// Main function
int main() {
    int n = 2; // Matrix size (should be a power of 2)
    Matrix A = {{1, 2}, {3, 4}};
    Matrix B = {{5, 6}, {7, 8}};

    Matrix C = strassen(A, B, n);
    
    cout << "Resultant Matrix:\n";
    printMatrix(C, n);

    return 0;
}


// Algorithm

/*
      1)Divide the matrices into 4 equal-sized submatrices.

      2)Compute 7 intermediate matrices using Strassen’s formulas.

      3)Compute the final result using these intermediate matrices.

      4)Recursively apply the method if the submatrices are large.
      
      5)Combine the submatrices to form the resulting matrix.
*/