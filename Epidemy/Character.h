//
//  Character.h
//  Epidemy
//
//  Created by Eliott Jouhaud on 08/12/2016.
//  Copyright © 2016 Eliott Jouhaud. All rights reserved.
//

#ifndef Character_h
#define Character_h

#include "Position.h"

class Character{

private:
    Position _position;
    
public:
    // Constructeur
    Character();
    Character(Position pos);
    
    // Getter
    Position get_Position();
    
    // Affichage
    void Display_pos_char();
    
    // Fonctions déplacement
    void Move_left();
    void Move_right();
    void Move_up();
    void Move_down();
    void Move();

    
};

#endif /* Character_h */
