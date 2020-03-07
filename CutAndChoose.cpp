//
//  CutAndChoose.cpp
//  CutChooseAlgorithm
//
//  Created by Adam Lev-Ari on 21/01/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#include "CutAndChoose.hpp"

namespace cake {

    Allocation asymmetric_protocol(vector<Agent*> agents) {
        
        if (agents.size() != 2)
            throw "Cut and choose works only for two agents";
        
        
        Allocation allocation(agents);
        
        float cut = agents[0]->mark(0, agents[0]->cakeValue() / 2);
        cout << "The cutter " << agents[0]->getName() << " cuts at "
        << cut << endl;
        
        if (agents[1]->eval(0, cut) > (agents[1]->cakeValue()/2)){
            
            cout << "The chooser " << agents[1]->getName()
            << " chooses the leftmost piece" << endl;
            allocation.setPiece(1, {0,cut});
            allocation.setPiece(0, {cut, agents[1]->cakeLength()});
        } else{
            
            cout << "The chooser" << agents[1]->getName()
            << "chooses the rightmost piece" << endl;
            allocation.setPiece(1, {cut, agents[1]->cakeLength()});
            allocation.setPiece(0, {0,cut});
        }
        
        return allocation;
    };

    Allocation symmetric_protocol(vector<Agent*> agents){
        
        if (agents.size() != 2)
            throw "Cut and choose works only for two agents";
        
        float marks[agents.size()];
        Allocation allocation(agents);
        
        for (int i=0; i<agents.size(); i++) {
            float agentCakeValue = agents[i]->cakeValue()/2;
            marks[i] = agents[i]->mark(0, agentCakeValue);
        }
        cout << "The agents mark at " << marks[0] << "," << marks[1]
        << endl;
        float cut = (marks[0] + marks[1])/2;
        cout << "The cake is cut at " << cut << endl;
        
        if (marks[0] < marks[1]){
            
            cout << agents[0]->getName() << "'s mark is to the left of "
            << agents[1]->getName() << "'s mark " << endl;
            allocation.setPiece(0, {0, cut});
            allocation.setPiece(1, {cut, agents[1]->cakeLength()});
        } else {
            cout << agents[1]->getName() << "'s mark is to the left of "
            << agents[0]->getName() << "'s mark " << endl;
            
            allocation.setPiece(1, {0, cut});
            allocation.setPiece(0, {cut, agents[0]->cakeLength()});
        }
        
        
        return allocation;
    };

}

