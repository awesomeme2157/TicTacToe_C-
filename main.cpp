#include <iostream>
#include <ctime>
using namespace std;

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

void drawBoard(char *spaces)
{
    cout << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    cout << "     |     |     " << '\n';
    cout << '\n';
}

void playerMove(char *spaces, char player)
{
    int number;
    while (true)
    {
        cout << "Enter a spot to place a marker (1-9): ";
        cin >> number;
        if (cin.fail() || number < 1 || number > 9 || spaces[number - 1] != ' ')
        {
            cin.clear();             // Clear the error flag
            cin.ignore(10000, '\n'); // Ignore invalid input
            cout << "Invalid input. Try again.\n";
        }
        else
        {
            spaces[number - 1] = player;
            break;
        }
    }
}

void computerMove(char *spaces, char computer)
{
    int number;
    while (true)
    {
        number = rand() % 9;
        if (spaces[number] == ' ')
        {
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer)
{
    int winningCombos[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

    for (int i = 0; i < 8; i++)
    {
        if (spaces[winningCombos[i][0]] != ' ' &&
            spaces[winningCombos[i][0]] == spaces[winningCombos[i][1]] &&
            spaces[winningCombos[i][1]] == spaces[winningCombos[i][2]])
        {
            if (spaces[winningCombos[i][0]] == player)
                cout << "YOU WIN!\n";
            else
                cout << "YOU LOSE!\n";
            return true;
        }
    }
    return false;
}

bool checkTie(char *spaces)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }
    cout << "IT'S A TIE!\n";
    return true;
}

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    srand(time(0)); // Seed random number generator

    cout << "Welcome to Tic-Tac-Toe!\n";
    drawBoard(spaces);

    while (running)
    {
        playerMove(spaces, player);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        if (checkTie(spaces))
        {
            running = false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        if (checkTie(spaces))
        {
            running = false;
            break;
        }
    }

    cout << "Thanks for playing!\n";

    return 0;
}
