//
//  PiecewiseConstantAgent.cpp
//  CutChooseAlgorithm
//
//  Created by Adam Lev-Ari on 19/01/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#include "PiecewiseConstantAgent.hpp"


PiecewiseConstantAgent:: PiecewiseConstantAgent() {
    length = 0;
    totalValueCache = 0;
};

PiecewiseConstantAgent:: PiecewiseConstantAgent(vector<float> values, string name) : Agent(name) {
    
    this->values = values;
    this->length = values.size();
    
    for (int i=0; i<values.size(); i++) {
        this->totalValueCache += values[i];
    }
};

PiecewiseConstantAgent:: ~PiecewiseConstantAgent() {};

//TODO: piecewise-constant agent details print
string PiecewiseConstantAgent:: print() {
    
    ostringstream os;
    
    os << this->getName() << " is a piecewise-constant agent with desired regions"
    << toString(values) << "and total value = " << this->totalValueCache;
    
    return os.str();
};

float PiecewiseConstantAgent:: cakeValue() { return this->totalValueCache; };

float PiecewiseConstantAgent:: cakeLength() { return this->length; };

float PiecewiseConstantAgent:: eval(float start, float end) {
    
    float val = 0;
    //TODO: the cake to the left of 0 and to the right of length is considered worthless
    start = max((float) 0, min(start, this->length));
    end = max((float) 0, min(end, this->length));
    
    if (end <= start)
        return 0;
    
    int fromFloor = floor(start);
    float fromFraction = fromFloor + 1 - start;
    int toCeiling = ceil(end);
    float toCeilingRemoveFraction = toCeiling - end;
    
    
    val += (this->values[fromFloor] * fromFraction);
    for (int i=fromFloor+1; i < toCeiling; i++) {
        val += values[i];
    }
    val -= (this->values[toCeiling-1] * toCeilingRemoveFraction);
    
    
    return val;
};

float PiecewiseConstantAgent:: mark(float start, float targetValue) {
    
    //TODO: the cake to the left of 0 and to the right of length is considered worthless.
    //start = max((float) 0, min(start, this->length));
    start = max((float)0, start);
    
    if (start >= this->length)
        return 0; //value is too high
    
    if (targetValue < 0)
        throw "sum out of range (should be positive)";
    
    int startFloor = floor(start);
    if (startFloor >= this->values.size())
        throw "startFloor >= length of values";
    
    float startFraction = startFloor + 1 - start;
    
    float value = this->values[startFloor];
    if ((value * startFraction) >= targetValue)
        return start + (targetValue/value);
    
    targetValue -= (value * startFraction);
    for (int i=startFloor+1; i<this->length; i++) {
        value = this->values[i];
        if (targetValue <= value)
            return i+(targetValue / value);
        targetValue -= value;
    }
    
    
    //value is too high: return 0
    return 0;
};

