#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int mode;
int player1 = 0, player2 = 0;
int computer = 0;

int checkwin();
void board(int score1, int score2);
void multiPlayer();
void AI();
void GamePlay(char mark, int player, int choice);

int main()
{
    cout << "choce a mode:\n";
    cout << "single player mode(1)\n";
    cout << "two players mode(2)\n";
    cin >> mode;
    if (mode == 2)
    {
        string i = "Y";
        while (i == "Y")
        {
            multiPlayer();
            cout << "Do you want to continue playing ?(Y/N) \n";
            cin >> i;
            square[0] = '0';
            square[1] = '1';
            square[2] = '2';
            square[3] = '3';
            square[4] = '4';
            square[5] = '5';
            square[6] = '6';
            square[7] = '7';
            square[8] = '8';
            square[9] = '9';
        }
    }
    else if (mode == 1)
    {
        string i = "Y";
        while (i == "Y")
        {
            AI();
            cout << "Do you want to continue playing ?(Y/N) \n";
            cin >> i;
            square[0] = '0';
            square[1] = '1';
            square[2] = '2';
            square[3] = '3';
            square[4] = '4';
            square[5] = '5';
            square[6] = '6';
            square[7] = '7';
            square[8] = '8';
            square[9] = '9';
        }
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
        board(player1, computer);
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
    if (--player % 2 == 0)
    {
        ++computer;
    }
    else
    {
        ++player1;
    }
    board(player1, computer);
    if (i == 1)
    {
        if ((player % 2) == 1)
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

        board(player1, player2);
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        GamePlay(mark, player, choice);

        i = checkwin();
        player++;
    } while (i == -1);

    if (--player % 2 == 0)
    {
        ++player2;
    }
    else
    {
        ++player1;
    }

    board(player1, player2);
    if (i == 1)

        cout << "==>\aPlayer " << player << " win ";
    else
        cout << "==>\aGame draw";

    cin.ignore();
    cin.get();
}

void GamePlay(char mark, int player, int choice)
{

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
    int i = checkwin();
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

void board(int score1, int score2)
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl
         << endl;
    cout << endl;
    if (mode == 2)
    {
        cout << "      scores:\n\n";
        cout << "player 1:  " << score1 << "  player 2:  " << score2 << "\n\n\n";
    }
    else
    {
        cout << "      scores:\n\n";
        cout << "player 1:  " << score1 << "  computer:  " << score2 << "\n\n\n";
    }

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << " __  |  _  |  __ " << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << " __  |  _  |  __ " << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl
         << endl;
}
