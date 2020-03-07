//
//  PiecewiseUniformAgent.hpp
//  CutChooseAlgorithm
//
//  Created by Adam Lev-Ari on 06/02/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#ifndef PiecewiseUniformAgent_hpp
#define PiecewiseUniformAgent_hpp

#include "Agent.hpp"
#include <stdio.h>
#include <algorithm>

using namespace std;

/*
 A PiecewiseConstantAgent is an Agent whose value function
 has a constant density on a finite number of intervals.
 */

class PiecewiseUniformAgent : public Agent {
    
private:
    vector<vector<float>> desiredRegions;
    float length, totalValueCache ;
    
public:
    PiecewiseUniformAgent();
    PiecewiseUniformAgent(vector<vector<float>>, string);
    ~PiecewiseUniformAgent();
    
    virtual string print();
    virtual float cakeValue();
    virtual float cakeLength();
    virtual float eval(float, float);
    virtual float mark(float, float);
    
};

#endif /* PiecewiseUniformAgent_hpp */
