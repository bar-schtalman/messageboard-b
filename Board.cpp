#include "Board.hpp"
#include <iostream>
#include <cstddef>
#include <exception>
#include <map>
using namespace std;

namespace ariel{

    void Board::post(unsigned int row ,unsigned int col ,Direction d,const string &msg){
        if ( d == Direction::Vertical){
            max_row = max(max_row , row + unsigned(msg.length()));
        }
        else {
          max_col = max(max_col, col + unsigned(msg.length()));
        }
  
    
        for (unsigned int i = 0; i < msg.length(); i ++){
            board[row][col] = msg.at(i);
            if (d == Direction::Vertical){
                row++;
            }
            else{
                col ++; 
            }
        }
        }
    

  string Board::read(unsigned int row, unsigned int col, Direction d, unsigned int char_num){
        string ans;
        for (int i = 0; i < char_num; i++){
            if( board[row].find(col)== board[row].end() || board.find(row) == board.end()){
                ans += "_";
            }
            else{
                ans += board[row][col];
            }
            if (d == Direction::Horizontal){
               col++;
            }
            else{
                row++;
            } 
        }
        
        return ans;
    }

    void Board::show(){
    for (unsigned int i = min_row; i < max_row; i++){
        for(unsigned int j = min_col; j < max_col; j++){
            cout << board[i][j];
        }
        cout << "\n"; 
    }
}

}





