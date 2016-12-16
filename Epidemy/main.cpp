//
//  main.cpp
//  Epidemy
//
//  Created by Eliott Jouhaud on 24/11/2016.
//  Copyright © 2016 Eliott Jouhaud. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "Position.h"
#include "Individual.h"
#include "Character.h"

int main() {
    
    Individual Indiv1;
    
    Position pos(2,3);
    Individual Indiv2(pos, 'I');
    Character Pers1(pos);
    
    std::cout << Indiv2.Compare_pos_char(Pers1);
    
    Indiv1.Display_pos_indiv();
    //Indiv2.Display_pos_indiv();
    //std::cout << Indiv2.get_Status() << "\n";
    Pers1.Display_pos_char();
    Pers1.Move_down();
    Pers1.Display_pos_char();
    
    
    return 0;
}
