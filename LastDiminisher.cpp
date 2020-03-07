//
//  LastDiminisher.cpp
//  badkanAutomation3
//
//  Created by Adam Lev-Ari on 08/03/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#include "LastDiminisher.hpp"

namespace cake {

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
