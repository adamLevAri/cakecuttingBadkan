//
//  LastDiminisher.hpp
//  badkanAutomation3
//
//  Created by Adam Lev-Ari on 08/03/2020.
//  Copyright © 2020 Adam Lev-Ari. All rights reserved.
//

#ifndef LastDiminisher_hpp
#define LastDiminisher_hpp

#include <stdio.h>

#include "Allocation.hpp"

namespace cake {
    
    void LastDiminisher(vector<Agent*>);
    void LastDiminisherRecursive (float, vector<Agent*>, vector<int>, Allocation);
    
}

#endif /* LastDiminisher_hpp */
