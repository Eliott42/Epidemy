//
//  Individual.cpp
//  Epidemy
//
//  Created by Eliott Jouhaud on 05/12/2016.
//  Copyright © 2016 Eliott Jouhaud. All rights reserved.
//

#include <stdio.h>
#include "Position.h"
#include "Individual.h"

// Constructeurs

Individual::Individual(){
    _position = Position();
    _status = 'S';
}

Individual::Individual(Position pos, char status){
    _position = pos;
    _status = status;
}

//-----------------------------------------------------------------

// Setter

void Individual::set_Status(char status){
    _status = status;
}

// Getter

char Individual::get_Status(){
    return _status;
}

//-----------------------------------------------------------------