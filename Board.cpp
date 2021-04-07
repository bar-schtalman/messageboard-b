#include "Board.hpp"
#include <iostream>
#include <cstddef>
#include <exception>
#include <map>
using namespace std;


namespace ariel{

    void Board::post(unsigned int row ,unsigned int col ,Direction d,const string &msg){
        if ( d == Direction::Vertical){
            max_row = max( row + unsigned(msg.length()),max_row);
            for(unsigned int i = 0; i < msg.length(); i ++){
                this->board[row][col] = msg.at(i);
                row++;
            }
        }
        else {
             max_col = max( col + unsigned(msg.length()),max_col);
             for(unsigned int i = 0; i < msg.length(); i ++){
                this->board[row][col] = msg.at(i);
                col++;
            }
        }
    }
    

  string Board::read(unsigned int row, unsigned int col, Direction d, unsigned int char_num){
        string ans;
        for(unsigned int i = 0 ; i < char_num; i++){
            if(board.find(row) == board.end()){
                ans += "_";
            }
            else if(board[row].find(col) == board[row].end()){
                ans += "_";
            }
            else{
                ans += this->board[row][col];
            }

            if(d == Direction::Vertical){
                row ++;
            }
            else{
                col++;
            }

        }

        return ans;
    }

    void Board::show(){
        for (unsigned int i = min_row; i < max_row; i ++){
            for(unsigned int j = min_col; j < max_col; j ++){
                cout << this->board[i][j];
            }
            cout << "\n"; 
        }
    }

}
    





