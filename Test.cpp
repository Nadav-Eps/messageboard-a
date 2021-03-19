#include "doctest.h"
#include "Board.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
// using ariel::Direction;
// using ariel::Board;
using namespace std;
using namespace ariel;

 ariel :: Board board;

TEST_CASE("good post and read"){
CHECK(board.post(100,100,Direction::Horizontal,"hello")==0);
CHECK(board.read(100,100,Direction::Horizontal,5)==0);
CHECK(board.read(100,100,Direction::Vertical,5)==0);
//now well see what happens if a message runs over another
CHECK(board.post(100,102,Direction::Vertical,"nadav")==0);
CHECK(board.read(100,100,Direction::Horizontal,5)==0);//the 'n' took over 'l' spot
CHECK(board.read(101,102,Direction::Vertical,4)==0);
CHECK(board.post(100,97,Direction::Horizontal,"nnnnnnnn")==0);//should run over henlo
CHECK(board.read(100,100,Direction::Horizontal,5)==0);
CHECK(board.read(100,100,Direction::Horizontal,2)==0);
CHECK(board.read(100,101,Direction::Horizontal,4)==0);

}
TEST_CASE("negative cols and rows"){
    CHECK_THROWS(board.post(-100,-1,Direction::Horizontal,"hey"));//cannot use negative col and negative row together to post
    CHECK_THROWS(board.post(100,-1,Direction::Horizontal,"hey"));//cannot use negative col to post
    CHECK_THROWS(board.post(-100,1,Direction::Horizontal,"hey"));//cannot use negative row to post
    CHECK_THROWS(board.read(100,100,Direction::Horizontal,-5));//cannot read negative number of cells
    CHECK_THROWS(board.read(-100,-1,Direction::Horizontal,3));//cannot use negative col and negative rows together to read
    CHECK_THROWS(board.read(100,-1,Direction::Horizontal,3));//cannot use negative col to read
    CHECK_THROWS(board.read(-100,1,Direction::Horizontal,3));//cannot use negative row to read
    CHECK_THROWS(board.read(10,-5,Direction::Horizontal,4));
    CHECK_THROWS(board.read(-100,-1,Direction::Horizontal,-3));
    CHECK_THROWS(board.read(-100,100,Direction::Horizontal,-30));
    CHECK_THROWS(board.read(100,-1,Direction::Horizontal,-13));
    
}
