#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int const boardSize=4;
int board[boardSize][boardSize]={};
enum{w=1,s,a,d};
void displayBoard();
void menu();
void intializeBoard();
void playGame();
void playerTurn();
void displayBoard(){
    cout<<" ------------------"<<endl;
    
    for (int i = 0; i < boardSize; i++)
    {
        cout<<"| ";
        for (int j = 0; j < boardSize; j++)
        {
            if(j!=3)
                cout<<board[i][j]<<setw(5);
            else
                  cout<<board[i][j]<<" ";  
        }
        cout<<"|"<<endl;
    }
    cout<<" ------------------"<<endl;
    
}
void intializeBoard(){
    srand(static_cast<unsigned int>(time(0)));
    int i=rand()%4;
    int j=rand()%4;
    int k,z;
    while (true)
    {
        k=rand()%4;
        z=rand()%4;
        if(k==i && z==j){
            continue;
        }
        else
            break;
    }
    board[i][j]=2;
    board[k][z]=2;
}
void playerTurn(){
    displayBoard();
    cout<<"Enter a word [ w (up) , s (down) , a (left) , d (right)]";
    char word;
    do{
        cin>>word;
        switch (word)
        {
        case w:
            
            return;
        case s:
            
            return;
        case a:
            
            return;
        case d:

            return;
        }

    }while (true);
    
    


}
void playGame(){
    intializeBoard();
    while (true)
    {
        playerTurn();
        system("pause");
    }
    



}
void upMove(){

}

void menu(){
    cout << "*********** Welcom to 2048 Game ***********"<<endl;
    cout<<"1.Play Game"<<endl
    <<"2.Exit"<<endl
    << "Enter your choice:";
    int choice;
    
    do{
        cin>>choice;
        switch (choice)
        {
        case 1:
            playGame();
            return;
        case 2:
            return;
        }


    }while (true);
}

int main()
{
    menu();
    cout<<"\nGame over....";
}