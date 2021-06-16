#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkwin();
void board();
void multiPlayer();
void AI();
void GamePlay(char mark, int player, int choice);

int main()
{
    int mode;
    cout << "choce a mode:\n";
    cout << "single player mode(1)\n";
    cout << "two players mode(2)\n";
    cin >> mode;
    if (mode == 2)
    {
        multiPlayer();
    }
    else if (mode == 1)
    {
        AI();
    }
    else
    {
        cout << "Invalid optian";
    }
    return 0;
}

void AI()
{

    vector<int> vect{1, 2, 3, 4, 5, 6, 7, 8, 9};

    int player = 1, i, choice;

    char mark;

    do
    {
        board();
        if ((player % 2) == 1)
        {
            cout << "Player please enter a number:  ";
            cin >> choice;

            auto it = find(vect.begin(), vect.end(), choice);

            mark = 'X';
            vect.erase(it);
        }
        else
        {
            mark = 'O';
            int vectSize = vect.size();

            srand((unsigned)time(0));
            int randomNum = (rand() % vectSize);

            choice = vect[randomNum];
            vect.erase(vect.begin() + (randomNum));
        }
        GamePlay(mark, player, choice);

        i = checkwin();
        player++;

    } while (i == -1);

    board();
    if (i == 1)
    {
        if (((player - 1) % 2) == 1)
        {
            cout << "==>\aThe Player wins, congrats!! ";
        }
        else
        {
            cout << "==>\aIt's your lose ";
        }
    }
    else
        cout << "==>\aGame draw";

    cin.ignore();
    cin.get();
}

void multiPlayer()
{

    int player = 1, i, choice;

    char mark;

    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        GamePlay(mark, player, choice);

        i = checkwin();
        player++;
    } while (i == -1);

    board();
    if (i == 1)

        cout << "==>\aPlayer " << --player << " win ";
    else
        cout << "==>\aGame draw";

    cin.ignore();
    cin.get();
}

void GamePlay(char mark, int player, int choice)
{
    board();

    if (choice == 1 && square[1] == '1')

        square[1] = mark;
    else if (choice == 2 && square[2] == '2')

        square[2] = mark;
    else if (choice == 3 && square[3] == '3')

        square[3] = mark;
    else if (choice == 4 && square[4] == '4')

        square[4] = mark;
    else if (choice == 5 && square[5] == '5')

        square[5] = mark;
    else if (choice == 6 && square[6] == '6')

        square[6] = mark;
    else if (choice == 7 && square[7] == '7')

        square[7] = mark;
    else if (choice == 8 && square[8] == '8')

        square[8] = mark;
    else if (choice == 9 && square[9] == '9')

        square[9] = mark;
    else
    {
        cout << "Invalid move ";

        player--;
        cin.ignore();
        cin.get();
    }
}

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}

void board()
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl
         << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "__|_|__" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "__|_|__" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl
         << endl;
}