#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int const boardSize = 4;
int board[boardSize][boardSize] = {};
bool merged;
bool win=false;
bool exitGame=false;
int lastSum = 0;
bool evenMoved;
bool evenMerged;
void displayBoard();
void menu();
void intializeBoard();
void playGame();
void playerTurn();
void upMove();
void leftMove();
void rightMove();
void downMove();
void fillRandomIndex();
bool endGame();
bool checkEqualNeighbors(int i,int j);
void displayBoard()
{
    cout << "************************************" << endl;
    cout << endl;
    for (int i = 0; i < boardSize; ++i)
    {
        cout << "+------+------+------+------+" << endl;
        for (int j = 0; j < boardSize; ++j)
        {
            if (board[i][j] == 0)
                cout << "|      ";
            else{
                if(board[i][j] < 10)
                    cout << "|  " << board[i][j] << "   ";
                else if(board[i][j] < 100)
                    cout << "|  " << board[i][j] << "  ";
                else if(board[i][j] < 1000)
                    cout << "| " << board[i][j] << "  ";
                else
                    cout << "| " << board[i][j]<< " ";
            }
                
        }
        cout << "|" << endl;
    }
    cout << "+------+------+------+------+" << endl;
    cout << endl;
    cout << "************************************" << endl;
}
void intializeBoard()
{
    srand(static_cast<unsigned int>(time(0)));
    int i = rand() % 4;
    int j = rand() % 4;
    int k, z;
    while (true)
    {
        k = rand() % 4;
        z = rand() % 4;
        if (k == i && z == j)
        {
            continue;
        }
        else
            break;
    }
    board[i][j] = 2;
    board[k][z] = 2;
}
void playerTurn()
{
    system("cls");
    displayBoard();
    cout << "Enter a word [ w (Up) , s (Down) , a (Left) , d (Right) , e (Exit)]" << endl;
    cout << "Your Choice :";
    string input;
    do
    {

        cin >> input;
        if (input.length() != 1)
        {
            cout << "Invalid Input, please try again." << endl;
            return;
        }
        switch (input[0])
        {
        case 'w':
            upMove();
            return;
        case 's':
            downMove();
            return;
        case 'a':
            leftMove();
            return;
        case 'd':
            rightMove();
            return;
        case 'e':
            exitGame = true;
            return;
        default:
            cout << "Invalid Input, please try again." << endl;
            return;
        }

    } while (true);
}
void playGame()
{
    intializeBoard();
    while (!endGame())
    {
        playerTurn();
        if (evenMoved || evenMerged)
        {
            fillRandomIndex();
        }
    }
}
void upMove()
{
    evenMoved = false;
    evenMerged = false;
    for (int i = 1; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (board[i][j] != 0 && board[i - 1][j] == 0)
            {
                for (int k = i; k > 0; k--)
                {
                    if (board[k - 1][j] == 0)
                    {
                        board[k - 1][j] += board[k][j];
                        board[k][j] = 0;
                        evenMoved = true;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    for (int j = 0; j < boardSize; j++)
    {
        lastSum = 0;
        merged = false;
        for (int i = 0; i < boardSize - 1; i++)
        {
            if (board[i][j] == 0)
            {
                if (board[i + 1][j] != 0)
                {
                    board[i][j] += board[i + 1][j];
                    board[i + 1][j] = 0;
                    if (lastSum == board[i][j] && !merged)
                    {
                        board[i - 1][j] += board[i][j];
                        board[i][j] = 0;
                        merged = true;
                        lastSum = board[i - 1][j];
                    }
                    else
                    {
                        lastSum = board[i][j];
                        merged = false;
                    }
                }
            }
            else
            {
                if (board[i][j] == board[i + 1][j])
                {
                    board[i][j] += board[i + 1][j];
                    board[i + 1][j] = 0;
                    lastSum = board[i][j];
                    merged = true;
                }
            }
            if (merged)
            {
                evenMerged = true;
            }
        }
    }
}
void downMove()
{
    evenMoved = false;
    evenMerged = false;
    for (int i = boardSize - 2; i >= 0; i--)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (board[i][j] != 0 && board[i + 1][j] == 0)
            {
                for (int k = i; k < boardSize - 1; k++)
                {
                    if (board[k + 1][j] == 0)
                    {
                        board[k + 1][j] += board[k][j];
                        board[k][j] = 0;
                        evenMoved = true;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    for (int j = 0; j < boardSize; j++)
    {
        lastSum = 0;
        merged = false;
        for (int i = boardSize - 1; i > 0; i--)
        {
            if (board[i][j] == 0)
            {
                if (board[i - 1][j] != 0)
                {
                    board[i][j] += board[i - 1][j];
                    board[i - 1][j] = 0;
                    if (lastSum == board[i][j] && !merged)
                    {
                        board[i + 1][j] += board[i][j];
                        board[i][j] = 0;
                        merged = true;
                        lastSum = board[i + 1][j];
                    }
                    else
                    {
                        lastSum = board[i][j];
                        merged = false;
                    }
                }
            }
            else
            {
                if (board[i][j] == board[i - 1][j])
                {
                    board[i][j] += board[i - 1][j];
                    board[i - 1][j] = 0;
                    lastSum = board[i][j];
                    merged = true;
                }
            }
            if (merged)
            {
                evenMerged = true;
            }
        }
    }
}
void rightMove()
{
    evenMoved = false;
    evenMerged = false;
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = boardSize - 2; j >= 0; j--)
        {
            if (board[i][j] != 0 && board[i][j + 1] == 0)
            {
                for (int k = j; k < boardSize - 1; k++)
                {
                    if (board[i][k + 1] == 0)
                    {
                        board[i][k + 1] += board[i][k];
                        board[i][k] = 0;
                        evenMoved = true;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < boardSize; i++)
    {
        lastSum = 0;
        merged = false;
        for (int j = boardSize - 1; j > 0; j--)
        {
            if (board[i][j] == 0)
            {
                if (board[i][j - 1] != 0)
                {
                    board[i][j] += board[i][j - 1];
                    board[i][j - 1] = 0;
                    if (lastSum == board[i][j] && !merged)
                    {
                        board[i][j + 1] += board[i][j];
                        board[i][j] = 0;
                        merged = true;
                        lastSum = board[i][j + 1];
                    }
                    else
                    {
                        lastSum = board[i][j];
                        merged = false;
                    }
                }
            }
            else
            {
                if (board[i][j] == board[i][j - 1])
                {
                    board[i][j] += board[i][j - 1];
                    board[i][j - 1] = 0;
                    lastSum = board[i][j];
                    merged = true;
                }
            }
            if (merged)
            {
                evenMerged = true;
            }
        }
    }
}
void leftMove()
{
    evenMoved = false;
    evenMerged = false;
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 1; j < boardSize; j++)
        {
            if (board[i][j] != 0 && board[i][j - 1] == 0)
            {
                for (int k = j; k > 0; k--)
                {
                    if (board[i][k - 1] == 0)
                    {
                        board[i][k - 1] += board[i][k];
                        board[i][k] = 0;
                        evenMoved = true;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < boardSize; i++)
    {
        lastSum = 0;
        merged = false;
        for (int j = 0; j < boardSize - 1; j++)
        {
            if (board[i][j] == 0)
            {
                if (board[i][j + 1] != 0)
                {
                    board[i][j] += board[i][j + 1];
                    board[i][j + 1] = 0;
                    if (lastSum == board[i][j] && !merged)
                    {
                        board[i][j - 1] += board[i][j];
                        board[i][j] = 0;
                        merged = true;
                        lastSum = board[i][j - 1];
                    }
                    else
                    {
                        lastSum = board[i][j];
                        merged = false;
                    }
                }
            }
            else
            {
                if (board[i][j] == board[i][j + 1])
                {
                    board[i][j] += board[i][j + 1];
                    board[i][j + 1] = 0;
                    lastSum = board[i][j];
                    merged = true;
                }
            }
            if (merged)
            {
                evenMerged = true;
            }
        }
    }
}
void fillRandomIndex()
{
    srand(static_cast<unsigned int>(time(0)));
    while (true)
    {
        int i = rand() % 4;
        int j = rand() % 4;
        if (board[i][j] == 0)
        {
            board[i][j] = 2;
            break;
        }
    }
}
void menu()
{
    cout << "*****      ***      *   *     *****\n";
    cout << "    *     *   *     *   *     *   *\n";
    cout << "    *     *   *     *   *     *   *\n";  
    cout<<  "*****     *   *     *****     *****\n";
    cout<<  "*         *   *         *     *   *\n";
    cout<<  "*         *   *         *     *   *\n";
    cout<<  "*****      ***          *     ***** \n";
    cout << "*********** Welcom to 2048 Game ***********" << endl;
    cout << "1.Play Game" << endl
         << "2.Exit" << endl
         << "Enter your choice:";
    int choice;

    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            playGame();
            return;
        case 2:
            system("cls");
            exitGame = true;
            return;
        }
    } while (true);
}

int main()
{
    menu();
    if(win){
        cout << "Congratulations! You have reached 2048!" << endl;
    }
    else if(exitGame){
        cout << "You have exited the game." << endl;
    }
    else{
        cout << "Game Over! No more moves available." << endl;
    }
}

bool endGame(){
    if(exitGame){
        return true;
    }
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
            if(board[i][j] == 0){
                return false;
            }
            if(board[i][j]==2048){
                win=true;
                return true;
            }
        }
    }
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
            if(checkEqualNeighbors(i, j)){
                return false;
            }
        }
    }
    return true;
}

bool checkEqualNeighbors(int i, int j){
    if(i > 0 && board[i][j] == board[i-1][j]){
        return true;
    }
    if(i < boardSize - 1 && board[i][j] == board[i+1][j]){
        return true;
    }
    if(j > 0 && board[i][j] == board[i][j-1]){
        return true;
    }
    if(j < boardSize - 1 && board[i][j] == board[i][j+1]){
        return true;
    }
    return false;
}