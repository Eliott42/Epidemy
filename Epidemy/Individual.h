//
//  Individual.h
//  Epidemy
//
//  Created by Eliott Jouhaud on 05/12/2016.
//  Copyright © 2016 Eliott Jouhaud. All rights reserved.
//

#ifndef Individual_h
#define Individual_h

#include "Position.h"

class Individual{
    
private:
    Position _position;
    char _status;
    
public:
    // Constructeur
    Individual();
    Individual(Position pos, char status);
    
    // Setter
    void set_Status(char status);
    
    // Getter
    char get_Status();
    
};

#endif /* Individual_h */
