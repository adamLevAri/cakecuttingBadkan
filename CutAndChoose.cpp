//
//  CutAndChoose.cpp
//  CutChooseAlgorithm
//
//  Created by Adam Lev-Ari on 21/01/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#include "CutAndChoose.hpp"
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
Allocation:: Allocation() {};
    
Allocation:: Allocation(vector<Agent*> agents) {
        
        this->agents = agents;
        (this->pieces).resize(agents.size());
};
    
Allocation:: ~Allocation() {};
    
//TODO: sets the piece of the given index
void Allocation:: setPiece(int agentIndex, vector<float> piece){

        this->pieces[agentIndex] = piece;
        
};
    
string Allocation:: toString(vector<float> vec){
        ostringstream os;
        os << "[" << vec[0] << ", " << vec[1] << "]" << endl;
        return os.str();
        
};
    
string Allocation:: print(){

        ostringstream os;
        for (int i=0; i<pieces.size(); i++) {
            os << agents[i]->getName() << " gets " << toString(pieces[i])
            << " with value " << agents[i]->pieceValue(pieces[i]) << endl;
    }
        
    return os.str();
        
};
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

