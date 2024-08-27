#include <iostream>
#include<fstream>

using namespace std;

int x=0, y=0;
char board [3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
int choice;
int row, column;
char turn = 'X';
bool draw = false;



void displayboard () {



    cout<<"\t\t\player - 1 [X] \t PLAYER - 2 [O]\n\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t “<<board [0][0] << “| "<<board [0][1]<<"   | "<<board [0][2] <<" \n";
    cout<<"\t\t_||\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t “<<board [1][0] << “| "<<board [1][1]<<"   |  "<<board[1][2]<<" \n";
    cout<<"\t\t_||\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  | "<<board[2][1]<<"   |  "<<board[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";
}



void player_turn(){
    if(turn == 'X'){
        cout<<"\n\tPlayer - 1 [X] turn : ";
    }
    else if(turn == 'O'){
        cout<<"\n\tPlayer - 2 [O] turn : ";
    }

    cin>> choice;


    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move"<<endl;
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){

        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){

        board[row][column] = 'O';
        turn = 'X';
    }else {

        cout<<"Box already filled!n Please choose another!!"<<endl;
        player_turn();
    }


}


void newgame(){
char newboard[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
        {
            board[i][j]=newboard[i][j];

        }
}
}
bool gameover(){
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;


    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;


    draw = true;
    return false;
}

void savef()
{
    ofstream file,file2;
    file.open("t1.dat");
    file2.open("t2.dat");
    file<<x;
    file2<<y;
    file.close();
}

void Display()
{
    ifstream file,file2;
    file.open("t1.dat");
    file2.open("t2.dat");
    file>>x;
    file2>>y;
    cout<<"\nX Won "<<x<<" times\nY Won "<<y<<" times\n";
    file.close();
}


int main()
{
int ch ;
do {
    system("pause");
    system("cls");
    cout<<"-------------------------TIC TAC TOE-------------------------\n"<<endl;
    cout<<"\n\t\tenter 1 to play "<<endl;
    cout<<"\t\tenter 2 to quit"<<endl;
    cout<<"\t\tenter 3 to view winners"<<endl;
    cout<<"\nEnter your choice: ";
    cin>>ch;

    if(ch==1)
    {
        cout<<"\t\t\tT I C K -- T A C -- T O E -- G A M E"<<endl;
        cout<<"\n\t\t\t\tFOR 2 PLAYERS\n"<<endl;
        while(gameover()){
            display_board();
            player_turn();
            gameover();
        }


        if(turn == 'X' && draw == false){
                display_board();
                cout<<"\n\nCongratulations!Player with 'O' has won the game"<<endl;
                y++;
        }
        else if(turn == 'O' && draw == false){
                display_board();
            cout<<"\n\nCongratulations!Player with 'X' has won the game"<<endl;
            x++;
        }
        else
        {
            display_board();
            cout<<"\n\nGAME DRAW!!!\n\n"<<endl;
        }
        savef();
    }

    else if(ch==2)
        exit(0);

    else if(ch==3)
        Display();

    else
        cout<<"Wrong choice entered\n";

    newgame();

}while(1);

return 0;
}
