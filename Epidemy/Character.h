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

protected:
    Position _position;
    
public:
    // Constructeur
    Character();
    Character(Position pos);
    
    // Getter
    virtual Position get_Position();
    
    // Affichage
    virtual void Display_pos_char();
    
    // Fonctions déplacement
    virtual void Move_left();
    virtual void Move_right();
    virtual void Move_up();
    virtual void Move_down();
    virtual void Move();

    virtual char get_Status() {return '0';}

    // Comparaison de position entre characters
    virtual bool Compare_pos_char(Character char2);

    
};

#endif /* Character_h */
