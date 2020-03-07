//
//  agents.hpp
//  CutChooseAlgorithm
//
//  Created by Adam Lev-Ari on 19/01/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#ifndef Agent_hpp
#define Agent_hpp

#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;

class Agent {
private:
    string name;
    
public:
    
    Agent();
    Agent(string);
     ~Agent();
    
    // abstract methods - pure virtual
    virtual float cakeValue() = 0;
    virtual float cakeLength() = 0;
    virtual float eval(float, float) = 0;
    virtual float mark(float, float) = 0;
    virtual string print() = 0;
    
    // non-abstract methods
    string getName();
    string toString(vector<float>);
    string toString(vector<vector<float>>);
    float pieceValue(vector<float>);
    vector<float> partitionValues(vector<float>);
    
    
};

#endif /* Agent_hpp */
