//	Code written by Aditya ;)   ||  C++ Snippet
#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> board = vector<vector<char>>(3,vector<char>(3,' '));

char playerMarker = '.';
int i,j;

void showBoard(){
    cout<<' '<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"-----------"<<endl;
    cout<<' '<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"-----------"<<endl;
    cout<<' '<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
    cout<<endl<<endl;
}

bool makeMove(){
    cout<<(playerMarker=='X' ? "Player 1's turn:\n" : "Player 2's turn:\n");
    cout<<"Choose your input: \n";
    showBoard();
    int input;
    cin>>input;
         if(input == 1) {if(board[0][0]!='X' && board[0][0]!='O'){board[0][0]=playerMarker;return true;};}
    else if(input == 2) {if(board[0][1]!='X' && board[0][1]!='O'){board[0][1]=playerMarker;return true;};}
    else if(input == 3) {if(board[0][2]!='X' && board[0][2]!='O'){board[0][2]=playerMarker;return true;};}
    else if(input == 4) {if(board[1][0]!='X' && board[1][0]!='O'){board[1][0]=playerMarker;return true;};}
    else if(input == 5) {if(board[1][1]!='X' && board[1][1]!='O'){board[1][1]=playerMarker;return true;};}
    else if(input == 6) {if(board[1][2]!='X' && board[1][2]!='O'){board[1][2]=playerMarker;return true;};}
    else if(input == 7) {if(board[2][0]!='X' && board[2][0]!='O'){board[2][0]=playerMarker;return true;};}
    else if(input == 8) {if(board[2][1]!='X' && board[2][1]!='O'){board[2][1]=playerMarker;return true;};}
                   else {if(board[2][2]!='X' && board[2][2]!='O'){board[2][2]=playerMarker;return true;};}

    return false;
}
bool isXorO(int i,int j){
    return board[i][j]=='X' || board[i][j]=='O';
}
char whoWon(){
    for(i=0;i<3;i++){
        if(isXorO(i,0) && (board[i][0]==board[i][1] && board[i][1]==board[i][2]))
            return board[i][0];
    }
    for(j=0;j<3;j++){
        if(isXorO(0,j) && (board[0][j]==board[1][j] && board[1][j]==board[2][j]))
            return board[0][j];
    }
    
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && isXorO(1,1)) return board[1][1];
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && isXorO(1,1)) return board[1][1];

    return ' ';
}
void swapMarker(){
    playerMarker = playerMarker=='X' ? 'O' : 'X';
}
void chooseMarker(){
    cin>>playerMarker;
    while(playerMarker!='X' && playerMarker!='O'){
        cout<<"Wrong Marker choosen! Choose out of (X/O) (in upper case)! \n";
        cout<<"Choose the first player's marker (X/O):  ";
        cin>>playerMarker;
    }
}
void playGame(){
    cout<<"-------WELCOME TO TIC-TAC-TOE-------\n";
    cout<<"Choose the first player's marker (X/O):  ";
    chooseMarker();
    int times=9;
    char ch;
    while(times--){
        while(makeMove() == false){
            cout<<"That Place is already choosen! Try Again!\n";
        }
        swapMarker();
        ch = whoWon();
        if(ch != ' ') break;
    }
    showBoard();
    if(ch=='X') cout<<"Player 1 won!";
    else if(ch=='O') cout<<"Player 2 won!";
    else cout<<"The Match resulted in a Draw!";
}

void fillBoard(){
    char ch = '1';
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j] = ch++;
        }
    }
}

int main(){
    fillBoard();
    playGame();
    cout<<"\n\nPress any key to terminate the program!";
    char ch;
    cin>>ch;
    return 0;
}
