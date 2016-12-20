//
//  Simulator.h
//  Epidemy
//
//  Created by Eliott Jouhaud on 16/12/2016.
//  Copyright © 2016 Eliott Jouhaud. All rights reserved.
//

#ifndef Simulator_h
#define Simulator_h

#include "Position.h"
#include "Character.h"

class Simulator{
    
private:
    int _nb_cycles;
    Character* _character_simules[10];
    
public:
    Simulator(int n);
    void Tour_de_simulation();
    
};

#endif /* Simulator_h */
