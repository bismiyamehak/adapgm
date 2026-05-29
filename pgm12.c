
#include <stdio.h>
#define N 4

// Function to print the solution
void printSolution(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if it's safe to place queen
int isSafe(char board[N][N], int row, int col) {
    int i, j;

    // Check row on left side
    for (i = 0; i < col; i++)
        if (board[row][i] == 'Q')
            return 0;

    // Check upper diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return 0;

    // Check lower diagonal
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j] == 'Q')
            return 0;
    return 1;
}

// Recursive function to solve N-Queens
int solveNQUtil(char board[N][N], int col) {

    // Base case: If all queens are placed
    if (col >= N)
        return 1;

    // Try placing queen in all rows
    for (int i = 0; i < N; i++) {

        if (isSafe(board, i, col)) {

            board[i][col] = 'Q';

            // Recur for next column
            if (solveNQUtil(board, col + 1))
                return 1;

            // Backtrack
            board[i][col] = '-';
        }
    }
    return 0;
}

// Main function
int main() {

    char board[N][N];

    // Initialize board with '-'
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = '-';

    if (solveNQUtil(board, 0) == 0) {
        printf("Solution does not exist\n");
    } else {
        printf("Solution for %d Queens problem:\n", N);
        printSolution(board);
    }
    return 0;
}
