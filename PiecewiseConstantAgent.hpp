//
//  PiecewiseConstantAgent.hpp
//  CutChooseAlgorithm
//
//  Created by Adam Lev-Ari on 06/02/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#ifndef PiecewiseConstantAgent_hpp
#define PiecewiseConstantAgent_hpp

#include <stdio.h>
#include <algorithm>
#include <math.h>
#include "Agent.hpp"

using namespace std;

class PiecewiseConstantAgent : public Agent {
    
private:
    vector<float> values;
    float length, totalValueCache;
    
public:
    
    PiecewiseConstantAgent();
    PiecewiseConstantAgent(vector<float>, string);
    ~PiecewiseConstantAgent();
    
    virtual string print();
    virtual float cakeValue();
    virtual float cakeLength();
    virtual float eval(float, float);
    virtual float mark(float, float);
    
};


#endif /* PiecewiseConstantAgent_hpp */
