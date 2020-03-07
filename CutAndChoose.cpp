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

    void LastDiminisher(vector<Agent*> agents){
        
        if (agents.size() == 0)
            throw "There must be at least one agent";
        
        Allocation allocation(agents);
        
        float start = 0;
        vector<int> activeAgents;
        activeAgents.resize(agents.size());
        
        LastDiminisherRecursive(start, agents, activeAgents, allocation);
    };

    void LastDiminisherRecursive (float start, vector<Agent*> agents,
                                  vector<int> activeAgents, Allocation allocation){
        
        if (activeAgents.size() == 1){
            
            int remainingAgentIndex = activeAgents[0];
            Agent* remainingAgent = agents[remainingAgentIndex];
            cout << "One agent remains " << remainingAgent->getName()
            << ", and recieves the entire remaining cake starting at " << endl;
            allocation.setPiece(remainingAgentIndex, {start, remainingAgent->cakeLength()});
            return;
        }
        
        cout << activeAgents.size() << " agents remain, and recursively allocate the cake starting at "
        << start << " among them." << endl;
        
        int firstAgentIndex = activeAgents[0];
        Agent* firstAgent = agents[firstAgentIndex];
        float firstAgentMark = firstAgent->mark(start, firstAgent->cakeValue()/2);
        cout << firstAgent->getName() << " marks at " << firstAgentMark << endl;
        
        float currentMark = firstAgentMark;
        int currentMarkIndex = firstAgentIndex;
        
        for (int nextAgentIndex=1; nextAgentIndex<activeAgents.size(); nextAgentIndex++) {
            Agent* nextAgent = agents[nextAgentIndex];
            float nextAgentMark = nextAgent->mark(start, nextAgent->cakeValue()/agents.size());
            
            if (nextAgentMark < currentMark){
                cout << nextAgent->getName() << " diminishes the current mark to "
                << nextAgentMark << endl;
                currentMark = nextAgentMark;
                currentMarkIndex = nextAgentIndex;
            } else {
                cout << nextAgent->getName() << " does not diminish the current mark."
                << endl;
            }
        }
        
        Agent* currentMarker = agents[currentMarkIndex];
        allocation.setPiece(currentMarkIndex, {start, currentMark});
        cout << currentMarker->getName() << " is the last diminisher, and gets the piece ["
        << start << "," << currentMark << "]." << endl;
        
        activeAgents.erase(activeAgents.begin() + currentMarkIndex);
        float newStart = currentMark;
        
        LastDiminisherRecursive(newStart, agents, activeAgents, allocation);
        
    };

}

