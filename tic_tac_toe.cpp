#include <bits/stdc++.h>
#include <conio.h>
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char name1[15], name2[15];
char turn = 'X';
bool draw = false;
int row, column;
void display_board();
void player_turn();
bool game_over();
using namespace std;
int main()
{
    cout << "                                             xoxoxoxoxoxoxoxo------THE TICK TAC TOE GAME------xoxoxoxoxoxoxoxo" << endl;
    cout << endl
         << endl
         << endl
         << endl;
    cout << "INSTRUCTIONS" << endl
         << "You probably already know how to play Tic-Tac-Toe. It's a really simple game, right? That's what most people think. But if you really wrap your brain around" << endl
         << "it, you'll discover that Tic-Tac-Toe isn't quite as simple as you think!" << endl
         << "Tic-Tac -Toe (along with a lot of other games) involves looking ahead and trying to figure out what the person playing against you might do next." << endl;
    cout << endl
         << endl
         << endl
         << endl;
    cout << "RULES FOT TIC TAC TOE" << endl
         << endl;
    cout << "1. The game is played on a grid that's 3 squares by 3 squares" << endl;
    cout << "2. You are X, your friend is O. Players take turns putting their marks in empty squares." << endl;
    cout << "3. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner." << endl;
    cout << "4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie." << endl;
    cout << endl
         << endl
         << endl;
    cout << "Enter your first name PLAYER 1" << endl;
    cin >> name1;
    cout << "Enter your first name PLAYER 2" << endl;
    cin >> name2;
    cout << endl;
    cout << "So make your brains ready because the game is about to start " << name1 << " and " << name2 << endl
         << endl
         << name1 << " you are assigned X as your sword for this game and " << name2
         << "you are assigned O as your sword "
         << endl
         << endl;
    while (game_over())
    {
        display_board();
        player_turn();
        game_over();
    }
    if (turn == 'X' && draw == false)
    {
        cout << "CONGRATULATIONS!!!" << name2 << " WINS!!!" << endl;
    }
    else if (turn == 'O' && draw == false)
    {
        cout << "CONGRATULATIONS!!!" << name1 << " WINS!!!" << endl;
    }
    else
    {
        cout << "GAME DRAW!!" << endl;
    }

    getch();
    return 0;
}
void display_board()
{
    cout << "\t\t\t\t\t"
         << "       |       |       " << endl;
    cout << "\t\t\t\t\t"
         << "   " << board[0][0] << "   |   " << board[0][1] << "   |   " << board[0][2] << "   " << endl;
    cout << "\t\t\t\t\t"
         << "_______|_______|_______" << endl;
    cout << "\t\t\t\t\t"
         << "       |       |       " << endl;
    cout << "\t\t\t\t\t"
         << "   " << board[1][0] << "   |   " << board[1][1] << "   |   " << board[1][2] << "   " << endl;
    cout << "\t\t\t\t\t"
         << "_______|_______|_______" << endl;
    cout << "\t\t\t\t\t"
         << "       |       |       " << endl;
    cout << "\t\t\t\t\t"
         << "   " << board[2][0] << "   |   " << board[2][1] << "   |   " << board[2][2] << "   " << endl;
    cout << "\t\t\t\t\t"
         << "       |       |       " << endl;
}
void player_turn()
{
    int n;
    if (turn == 'X')
    {
        cout << "So " << name1 << " out of the 9 numbers that you see on your screen enter the number at which you want to enter your X mark"
             << endl
             << "Remember not to overlap existing Xs and Os"
             << endl;
        cin >> n;
    }
    else
    {
        cout << "So " << name2 << " out of the 9 numbers that you see on your screen enter the number at which you want to enter your X mark"
             << endl
             << "Remember not to overlap existing Xs and Os"
             << endl;
        cin >> n;
    }
    switch (n)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;
    default:
        cout << "Please enter valid number" << endl;
        break;
    }
    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "BOX ALREADYY FILLED...!!\n PLEASE TRY AGAIN" << endl;
        player_turn();
    }
    //display_board();
}
bool game_over()
{
    // check win
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return false;
    }

    //game playing
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return true;
            }
    //game draw
    draw = true;
    return false;
}