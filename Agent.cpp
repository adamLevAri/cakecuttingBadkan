//
//  agents.cpp
//  CutChooseAlgorithm
//
//  Created by Adam Lev-Ari on 19/01/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#include "Agent.hpp"

Agent::Agent(){
    name = "Anonymous";
};

Agent::Agent(string name){
    this->name = name;
};

Agent:: ~Agent() {}

string Agent:: getName(){ return name; }

//deque print
string Agent:: toString(vector<float> deq) {
    ostringstream os;
    os << "[";
    for (int i=0; i<deq.size(); i++) {
        os << deq[i] << ", ";
    }
    os << "]";
    return os.str();
}

string Agent:: toString(vector<vector<float>> deq) {
    ostringstream os;
    os << "[";
    for (int i=0; i<deq.size(); i++) {
        os << "(";
        for (int j=0; j<deq[i].size(); j++) {
            
        os << deq[i][j];
        if (j != deq[i].size()-1)
            os << " ,";
    }
        os << ")";
    }
    os << "]";
    return os.str();
}

//return: sum of all element's in a given list
float Agent:: pieceValue(vector<float> piece){
    float sum = 0;
    for (int i=0; i<piece.size()-1; i++) {
        sum += this->eval(piece[i], piece[i+1]);
    }
    
    return sum;
}

//return: all the pieces in the given partition
vector<float> Agent:: partitionValues(vector<float> partition){
    vector<float> values;
    
    values.push_back(this->eval(0, *values.begin()));
    
    for (int i=0; i<partition.size()-1; i++) {
        values.push_back(this->eval(values[i], values[i+1]));
    }
    values.push_back(this->eval(partition[-1], this->cakeLength()));
    
    return values;
}


