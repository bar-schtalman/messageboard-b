#include <map>
#include <string>
#include "Direction.hpp"
using namespace std;
namespace ariel{
    class Board{
        private:
            unsigned int min_row=0;
            unsigned int min_col=0;
            unsigned int max_row=0;
            unsigned int max_col=0;
            map<unsigned int, map<unsigned int, string>> board ;
        public:
            Board(){}
            
            void post(unsigned int row ,unsigned int col ,Direction d,const string &msg);
            string read(unsigned int row ,unsigned int col ,Direction d,unsigned int char_num);
            void show();
           
    };
}