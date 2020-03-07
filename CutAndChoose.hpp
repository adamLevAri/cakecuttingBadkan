//
//  CutAndChoose.hpp
//  CutChooseAlgorithm
//
//  Created by Adam Lev-Ari on 06/02/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#ifndef CutAndChoose_hpp
#define CutAndChoose_hpp


#include "Allocation.hpp"

namespace cake {

    Allocation asymmetric_protocol(vector<Agent*>);
    Allocation symmetric_protocol(vector<Agent*>);
    
    void LastDiminisher(vector<Agent*>);
    void LastDiminisherRecursive (float, vector<Agent*>, vector<int>, Allocation);
    
}

#endif /* CutAndChoose_hpp */
