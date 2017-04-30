/*#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include "game.hpp"
#include "playSpace.hpp"
#include <cstring>
#include <string>

using namespace std;
int x=0;
int n_choice;
string choice;

int take_HowBigArray()
{
    int n;
    cout<<"Input how big the Table is (just width, up to 100): ";
    cin>> n;
    return n;
}

void randToTable(int* table,int arrSize){
    int i=arrSize;
    while(i--)
    {
        *(table+i)=rand()%2;
    }
}

int main(){
    srand(time(0));
    do{
        //menu
        cout<<"------Picross------\n";
        cout<<"Please Select\n";
        cout<<"1.Play\n2.How to Play\n3.Exit\n";
        cout<<"-------------------\n";

        cin>>choice;
        n_choice=atoi(choice.c_str());
        switch(n_choice)
        {
            case 1:
                x=take_HowBigArray();
                break;

            case 2:
                //do something
                break;
            case 3:
                cout<<"Thanks for playing, Goodbye!\n";
                break;
            default:
                cout<<"Wrong input. Please select again.\n";
        }
        if(x)
        {
            int tableSize[x*x];
            randToTable(tableSize,x*x);
            playSpace(tableSize);
        }
        x=0;

    }while(n_choice!=3);
    return 0;
}

//play howtoPlay exit*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include "game.hpp"
#include "playSpace.hpp"
#include <cstring>
#include <string>
#include <conio.h>
#include "leaderboard.hpp"

using namespace std;
extern int how_to_play();
int x=0;
int n_choice;
string choice;

int take_HowBigArray()
{
    int n;
    cout<<"Input how big the Table is (just width, up to 100): ";
    cin>> n;
    return n;
}

void randToTable(int* table,int arrSize){
    int i=arrSize;
    while(i--)
    {
        *(table+i)=rand()%2;
    }
}

void playGame(){
    x=take_HowBigArray();
    int tableSize[x*x];
    randToTable(tableSize,x*x);
    playSpace(tableSize);
}

int main(){
    srand(time(0));
    do{
        cout<<"Please select\n";
        cout<<"(1)Play (2)How to play (3)High Score (4)Exit : ";

        cin>>choice;
        cin.ignore();

        n_choice=atoi(choice.c_str());

        switch(n_choice)
        {
            case 1:
                cout<<"-------------------------------------------\n\n";
                playGame();
                break;
            case 2:
                cout<<"-------------------------------------------\n\n";
                how_to_play();
                break;
            case 3:
                cout<<"-------------------------------------------\n\n";
                cout << "Which size? : ";
                int s;
                cin >> s;
                showScore(s);
                break;
            case 4:
                cout<<"-------------------------------------------\n\n";
                cout<<"Good bye\n";
                cout<<"Press any key to continue..\n";
                getch();
                return 0;
                break;

            default:
                cout<<"-------------------------------------------\n";
                cout<<"wrong in put.\nPlease enter 1-3\n";
                cout<<"-------------------------------------------\n\n";
                cout<<"Press any key to continue..\n";
                getch();
        }
        cout<<"Press any key to continue..\n";
        getch();
        system("cls");
    }while(n_choice!=4);
    return 0;
}
