#include <stdio.h>

void createMatrix(int matrix[100][100], int row, int col){
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[100][100],int row,int col){
    for (int i = 0; i < row; i++) {
        for (int j=0;j<col;j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    scanf("%d %d", &row,&col);
    int matrix[100][100];
    createMatrix(matrix,row,col);
    printMatrix(matrix,row,col);
    return 0;
}
