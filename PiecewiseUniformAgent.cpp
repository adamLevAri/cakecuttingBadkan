//
//  PiecewiseConstantAgent.cpp
//  CutChooseAlgorithm
//
//  Created by Adam Lev-Ari on 19/01/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#include "PiecewiseUniformAgent.hpp"

PiecewiseUniformAgent:: PiecewiseUniformAgent() {
    length = 0;
    totalValueCache = 0;
};

PiecewiseUniformAgent:: PiecewiseUniformAgent(vector<vector<float>> desiredRegions, string name) :
Agent(name) {
    
    this->desiredRegions = desiredRegions;
    sort(this->desiredRegions.begin(), this->desiredRegions.end());
    
    for (int i=0; i<desiredRegions.size()-1; i++) {
        length = max(desiredRegions[i][1], desiredRegions[i+1][i]);
    }
    
    for (int i=0; i<desiredRegions.size(); i++) {
        for (int j=0; j<desiredRegions[i].size()-1; j++) {
            totalValueCache += (desiredRegions[i][j+1] - desiredRegions[i][j]);
        }
    }
    
};

//TODO: piecewise-uniform agent details print
string PiecewiseUniformAgent:: print() {
    ostringstream os;
    os << this->getName() << " is a piecewise-uniform agent with desired regions"
    << toString(desiredRegions) << "and total value = " << this->totalValueCache;
    
    return os.str();
    
};

PiecewiseUniformAgent:: ~PiecewiseUniformAgent() {};

float PiecewiseUniformAgent:: cakeValue() { return this->totalValueCache; };

float PiecewiseUniformAgent:: cakeLength() { return this->length; };

float PiecewiseUniformAgent:: eval(float start, float end) {
    
    if (end <= start)
        return 0;
    
    float val = 0;
    
    for (int i=0; i<desiredRegions.size(); i++) {
        
        float beginNUM = *desiredRegions[i].begin();
        float endNUM = *(desiredRegions[i].end()-1);
        
        if(!(endNUM<start) && !(end<beginNUM)){
            
            float valueFromRegion = (min(end ,endNUM) -
                                     max(start, beginNUM));
            val += valueFromRegion;
        }
    }
    return val;
};

float PiecewiseUniformAgent:: mark(float start, float targetValue) {
    
    if (targetValue < 0)
        throw "sum out of range (should be positive): ";
    
    float effectiveStart = 0;
    float regionValue = 0;
    for (int i=0; i<desiredRegions.size(); i++) {
        
        float beginNUM = *desiredRegions[i].begin();
        float endNUM = *(desiredRegions[i].end()-1);
        
        
        if (!(endNUM < start)){
            effectiveStart = max(start, beginNUM);
            regionValue = endNUM - effectiveStart;
            
        }if ((regionValue < targetValue)){
            targetValue -= regionValue;
            
        }else
            return effectiveStart + targetValue;
    }
    return 0;
    
};

