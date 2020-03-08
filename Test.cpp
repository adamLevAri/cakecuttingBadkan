//
//  badkan.cpp
//  CutAndChoose
//
//  Created by Adam Lev-Ari on 21/01/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#include "doctest.h"
#include "CutAndChoose.hpp"
#include "PiecewiseUniformAgent.hpp"
#include "PiecewiseConstantAgent.hpp"

using namespace std;
using namespace cake;

TEST_CASE("Test case 1") {
    
    vector<vector<float>> vec2;
    vec2 = {{0,1},{2,4},{6,9}};
    
    //Alice has two desired intervals, 0..1 and 3..6. Each interval has value 1.
    PiecewiseUniformAgent Alice2(vec2, "Alice");
    
    //George has four desired intervals: 0..1 with value 1, 1..2 with value 3, etc.
    PiecewiseConstantAgent George2({11,22,33,44}, "George");

    CHECK(George2.cakeValue() == (110.0));
     CHECK(George2.cakeValue() == (110.0));
    CHECK(George2.cakeLength() == (4.0));
    CHECK(George2.eval(1, 3) == (55.0));
    CHECK(George2.mark(1, 77) == (3.5));
    
    CHECK(Alice2.cakeValue() == (6.0));
    CHECK(Alice2.cakeValue() == (6.0));
    CHECK(Alice2.cakeLength() == (9.0));
    CHECK(Alice2.eval(3, 1) == (0.0));
    CHECK(Alice2.mark(0, 2) == (3.0));
    
    
}

TEST_CASE("Test case 2") {
    
    vector<vector<float>> vec;
    vec = {{0,1},{2,4},{6,9}};
    
    //Alice has two desired intervals, 0..1 and 3..6. Each interval has value 1.
    PiecewiseUniformAgent Alice(vec, "Alice");
    
    //George has four desired intervals: 0..1 with value 1, 1..2 with value 3, etc.
    PiecewiseConstantAgent George({11,22,33,44}, "George");
    
    CHECK(George.cakeValue() == (110.0));
     CHECK(George.cakeValue() == (110.0));
    CHECK(George.cakeLength() == (4.0));
    CHECK(George.eval(1, 3) == (55.0));
    CHECK(George.mark(1, 77) == (3.5));
    
    CHECK(Alice.cakeValue() == (6.0));
    CHECK(Alice.cakeValue() == (6.0));
    CHECK(Alice.cakeLength() == (9.0));
    CHECK(Alice.eval(3, 1) == (0.0));
    CHECK(Alice.mark(0, 2) == (3.0));
    
    /*
    CHECK(George2.cakeValue() == 110);
    CHECK(George2.cakeLength() == 4);
    CHECK(George2.eval(1, 3) == 55);
    CHECK(George2.mark(1, 77) == 3.5);
    
    CHECK(Alice2.cakeValue() == 6);
    CHECK(Alice2.cakeLength() == 9);
    CHECK(Alice2.eval(3, 1) == 0);
    CHECK(Alice2.mark(0, 2) == 3);
    */
}
