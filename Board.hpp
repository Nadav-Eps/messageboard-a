#include <iostream>
#include <string.h>
#include "Direction.hpp"
using ariel::Direction;
using namespace std;

namespace ariel {
   class Board{
       public :
int read(int col,int row,Direction d,int len);
int post(int col, int row, Direction d,string s);
void show();
   };
}