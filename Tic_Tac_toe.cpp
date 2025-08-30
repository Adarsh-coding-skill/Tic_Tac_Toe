#include <iostream>
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
        for (int i = 1; i < 3; i++)
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
            for(int j =0; j< 3; j++0){
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

        
    }


};


int main(){


    return 0;
}