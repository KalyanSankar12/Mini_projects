#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';
char lastPlayer;
int scoreX = 0, scoreO = 0;

void resetBoard() {
    char ch = '1';
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j] = ch++;
        }
    }
}

void drawBoard() {
    system("cls");
    cout << "SCORE  X: " << scoreX << "   O: " << scoreO << "\n";
    cout << "\n TIC TAC TOE \n\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << " " << board[i][j] << " ";
            if(j<2) cout << "|";
        }
        cout << endl;
        if(i<2) cout << "---+---+---\n";
    }
}

bool checkWin() {
    for(int i=0;i<3;i++){
        if(board[i][0]==lastPlayer && board[i][1]==lastPlayer && board[i][2]==lastPlayer) return true;
        if(board[0][i]==lastPlayer && board[1][i]==lastPlayer && board[2][i]==lastPlayer) return true;
    }
    if(board[0][0]==lastPlayer && board[1][1]==lastPlayer && board[2][2]==lastPlayer) return true;
    if(board[0][2]==lastPlayer && board[1][1]==lastPlayer && board[2][0]==lastPlayer) return true;
    return false;
}

void makeMove() {
    int choice;
    cout << "\nPlayer " << currentPlayer << ", enter position (1-9): ";
    cin >> choice;

    if(choice < 1 || choice > 9){
        cout << "Invalid input! Try again.\n";
        makeMove();
        return;
    }

    int row = (choice-1)/3;
    int col = (choice-1)%3;

    if(board[row][col]=='X' || board[row][col]=='O'){
        cout << "Cell already used! Try again.\n";
        makeMove();
        return;
    }

    board[row][col] = currentPlayer;
    lastPlayer = currentPlayer;
    currentPlayer = (currentPlayer=='X') ? 'O' : 'X';
}

int main() {
    char playAgain = 'y';

    while(playAgain=='y' || playAgain=='Y'){
        resetBoard();
        currentPlayer = 'X';
        int moves = 0;
        bool gameWon=false;
        
        while(moves < 9){
            drawBoard();
            makeMove();
            moves++;

            if(checkWin()){
                drawBoard();
                cout << "\nPlayer " << lastPlayer << " wins!\n";

                if(lastPlayer=='X') scoreX++;
                else scoreO++;

                gameWon=true;
                break;
            }
        }

        if(!gameWon){
            drawBoard();
            cout << "\nGame Draw!\n";
        }

        cout << "\nPlay Again? (y/n): ";
        cin >> playAgain;
    }

    cout << "\nFinal Score ? X: " << scoreX << "  O: " << scoreO << endl;
    cout << "Thanks for playing!\n";
}

