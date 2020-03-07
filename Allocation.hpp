//
//  Allocation.hpp
//  CutChooseAlgorithm
//
//  Created by Adam Lev-Ari on 06/02/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#ifndef Allocation_hpp
#define Allocation_hpp

#include <stdio.h>
#include "Agent.hpp"

using namespace std;

class Allocation {

private:
    
    vector<Agent*> agents;
    vector<vector<float>> pieces;
        
public:

    Allocation();
    Allocation(vector<Agent*>);
    ~Allocation();
    
    void setPiece(int, vector<float>);
    string toString(vector<float>);
    string print();
        
};


#endif /* Allocation_hpp */
