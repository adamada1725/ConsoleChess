#include <iostream>
#include <conio.h>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
#include <uchar.h>
#include <windows.h>
using namespace std;

class test {
public:
    test(){};
    void horseprint(){
        cout<<"♞";
    }
/*    char K[5]={"A2E4"};
    K[0]-=17;
    K[2]-=17;*/
};

class Session {
private:
    //const char figures[13]{'▮', '♟', '♞', '♝', '♜', '♛', '♚', '♙', '♘', '♗', '♖', '♕', '♔'};
    short board[8][8]
    {
        //0 - пустая клетка, 1- черная пешка, 2- черный конь.... 7 - белая пешка, 8 - белый конь...
        {4, 2, 3, 5, 6, 3, 2, 4},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {7, 7, 7, 7, 7, 7, 7, 7},
        {10, 8, 9, 11, 12, 9, 8, 10}
    };
    char check=0; //черным шах 1 мат 2 белым +2 
    short counter=0;
    void pmove(char _turnp[4]){
            _turnp[0]-=17;
            _turnp[2]-=17;
            _turnp[1]--;
            _turnp[3]--;
            for(int i=0; i<5; i++){
                if(_turnp[i]-'0'>7||_turnp[i]-'0'==-1){
                    cout<<"Неверная позиция!\n";
                    turn();
                }
            }
            //cout<<endl<<_turnp;
            board[_turnp[3]-'0'][_turnp[2]-'0']=board[_turnp[1]-'0'][_turnp[0]-'0'];
            board[_turnp[1]-'0'][_turnp[0]-'0']=0;
            return;
    }
/*    char convert(char figure){
        return figure;
    };*/
public:
    Session() {

    }
    ~Session() {

    }
    
    void turn() {
        render();
        counter%2==0 ? cout << "Ход белых:\n" : cout << "Ход черных:\n";
        char turnp[4];
        cin>>turnp;
        pmove(turnp);
        counter++;
//        system("cls");
        turn();
        if (check % 2 == 0) {
        } else if (check == 2) {
            cout <<"Победа белых";
            return;
        } else {
            cout <<"Победа черных";
            return;
        }
    }
    void render() {
        cout<<" A B C D E F G H\n";
        for(int i=8; i>0; i--){
            cout<<i;
            for(int j=0; j<8; j++){
                switch(board[i-1][j]){
                    case 0:
                        (i+j)%2==1? cout<<"  " : cout<<"▉ ";
                    break;
                    case 1:
                        cout<<"♟ ";
                        break;
                    case 2: 
                        cout<<"♞ "; 
                        break;
                    case 3: 
                        cout<<"♝ "; 
                        break;
                    case 4: 
                        cout<<"♜ "; 
                        break;
                    case 5: 
                        cout<<"♛ "; 
                        break;
                    case 6: 
                        cout<<"♚ "; 
                        break;
                    case 7: 
                        cout<<"♙ "; 
                        break;
                    case 8: 
                        cout<<"♘ "; 
                        break;
                    case 9: 
                        cout<<"♗ "; 
                        break;
                    case 10:  
                        cout<<"♖ "; 
                        break;
                    case 11: 
                        cout<<"♕ "; 
                        break;
                    case 12: 
                        cout<<"♔ "; 
                        break;
                };
            }
            cout<<endl;
        }
    }
};

int main() {
    test Test;
    cout<<"Абакумов А.А.\t2ИС\tШахматы\nПример перемещения фигур: E2E4 (латиница, печетные буквы)\n";
    Session Game1;
    Game1.turn();
}