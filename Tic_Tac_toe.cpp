#include <iostream>
using namespace std;

class TicTacToe
{
private:
    char board[3][3];
    char current_marker;
    int current_player;

public:
    TicTacToe()
    {
        char count = '1';
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = count++;
            }
        }

        current_marker = 1;
        current_player = 'X';
    }

    void drawBoard(){
         cout<<"\n";
        for(int i = 0; i< 3; i++){
            for(int j =0; j<3; j++){
                cout<<" "<<board[i][j];
                if(j<2) cout <<"|";
            }
cout<<"\n";
if(i<2) cout<<"--------\n";

        }
        cout<<"\n";
    }


    bool placeMarker(int slot){
        int row = (slot-1)/3;
        int col = (slot-1)%3;

        if(slot < 1 || slot > 9) return false;

        if(board[row][col] != 'X' && board[row][col] != 'O'){
board[row][col]= current_marker;
return true;
        }

        return false;
    }


int checkWinner(){
    for(int i =0; i < 3; i++){
        if(board[i][0]==board[i][1] && board[i][1] == board[i][2]) return current_player;
        if(board[0][i] == board[1][i] && board[1][i]== board[2][i]) return current_player;
    }
    if(board[0][0]==board[1][1] && board[1][1] == board[2][2]) return current_player;
        if(board[0][2] == board[1][1] && board[1][1]== board[2][0]) return current_player;

        return 0;
}

void swapPlayerAndMarker(){

    if(current_marker =='X')current_marker ='O';
    else current_marker ='X';

    if(current_player == 1) current_player=2;
    else current_player = 1;
}

void playGame(){
    cout<<"Player 1, Choose your marker (X or O): ";
    char marker_p1;
    cin>>marker_p1;

    current_player =1;
    current_marker = marker_p1;

    drawBoard();
    int player_won;

    for(int i =0;i<9; i++){
        cout<<"Player "<< current_player<< ", enter your slot (1-9): ";
        int slot;
        cin>>slot;
        if(!placeMarker(slot)){

            cout<<"Invaild move! Try again.\n";
            i--;
            continue;
        }

        drawBoard();

        player_won = checkWinner();
        if(player_won==1){
            cout<<"Player 1 wins!"<<endl;
            return;
        }
        if(player_won==2){
            cout<<"Player 2 wins!"<<endl;
            return;
        }
        swapPlayerAndMarker();
    }
 cout << "It's a draw!"<<endl;

}

};


int main(){
TicTacToe game;
game.playGame();
return 0;

   
}