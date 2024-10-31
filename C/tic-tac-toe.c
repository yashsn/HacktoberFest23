#include <stdio.h>

char board[3][3]; // 3x3 Tic-Tac-Toe board
char currentPlayer; // 'X' or 'O'

// Function prototypes
void initializeBoard();
void printBoard();
int isWinner();
int isBoardFull();
void switchPlayer();

int main() {
    initializeBoard();
    currentPlayer = 'X'; // Start with player X

    while (1) {
        printBoard();
        int row, col;

        // Get player input
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check for valid input
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Place the mark on the board
        board[row][col] = currentPlayer;

        // Check for a winner
        if (isWinner()) {
            printBoard();
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        // Check if the board is full
        if (isBoardFull()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        // Switch players
        switchPlayer();
    }

    return 0;
}

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' '; // Empty space
}

// Function to print the board
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

// Function to check if there's a winner
int isWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
            return 1;
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
        return 1;

    return 0;
}

// Function to check if the board is full
int isBoardFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ') return 0; // Found an empty space
    return 1; // No empty spaces
}

// Function to switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Toggle player
}