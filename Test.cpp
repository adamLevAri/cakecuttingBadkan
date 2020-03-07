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
    
    vector<vector<float>> vec;
    vec = {{0,1},{2,4},{6,9}};
    
    //Alice has two desired intervals, 0..1 and 3..6. Each interval has value 1.
    PiecewiseUniformAgent Alice(vec, "Alice");
    
    //George has four desired intervals: 0..1 with value 1, 1..2 with value 3, etc.
    PiecewiseConstantAgent George({11,22,33,44}, "George");

    CHECK(George.cakeValue() == string("110"));
    CHECK(George.cakeLength() == string("4"));
    CHECK(George.eval(1, 3) == string("55"));
    CHECK(George.mark(1, 77) == string("3.5"));
    
    CHECK(Alice.cakeValue() == string("6"));
    CHECK(Alice.cakeLength() == string("9"));
    CHECK(Alice.eval(3, 1) == string("0"));
    CHECK(Alice.mark(0, 2) == string("3"));
    
    
}

TEST_CASE("Test case 2") {
    
    vector<vector<float>> vec;
    vec = {{0,1},{2,4},{6,9}};
    
    //Alice has two desired intervals, 0..1 and 3..6. Each interval has value 1.
    PiecewiseUniformAgent Alice(vec, "Alice");
    
    //George has four desired intervals: 0..1 with value 1, 1..2 with value 3, etc.
    PiecewiseConstantAgent George({11,22,33,44}, "George");

    CHECK(George.cakeValue() == string("110"));
    CHECK(George.cakeLength() == string("4"));
    CHECK(George.eval(1, 3) == string("55"));
    CHECK(George.mark(1, 77) == string("3.5"));
    
    CHECK(Alice.cakeValue() == string("6"));
    CHECK(Alice.cakeLength() == string("9"));
    CHECK(Alice.eval(3, 1) == string("0"));
    CHECK(Alice.mark(0, 2) == string("3"));

}
