//
//  Character.cpp
//  Epidemy
//
//  Created by Eliott Jouhaud on 08/12/2016.
//  Copyright © 2016 Eliott Jouhaud. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include "Character.h"

int Character::bound_right = 100;
int Character::bound_up = 100;

// Constructeurs

Character::Character(){
    _position = Position();
}

Character::Character(Position pos){
    _position = pos;
}

// Getter

Position Character::get_Position(){
    return _position;
}

//-----------------------------------------------------------------

// Fonctions déplacement

void Character::Move_left(){
    if (_position.get_coord_x() > 0){
        _position.set_coord_x(_position.get_coord_x() - 1);
    }
}

void Character::Move_right(){
    if (_position.get_coord_x() < bound_right){
        _position.set_coord_x(_position.get_coord_x() + 1);
    }
}

void Character::Move_down(){
    if (_position.get_coord_y() > 0){
        _position.set_coord_y(_position.get_coord_y() - 1);
    }
}

void Character::Move_up(){
    if (_position.get_coord_y() < bound_up){
        _position.set_coord_y(_position.get_coord_y() + 1);
    }
}

void Character::Move(){
    int i;
    i = rand()%4; // Génère un nombre aléatoire entre 0 et 3
    std::cout << i << ", " ;
    
    switch (i){
        case 0:
            Move_left();
            break;
        case 1:
            Move_right();
            break;
        case 2:
            Move_down();
            break;
        case 3:
            Move_up();
            break;
    }
}

//-----------------------------------------------------------------

// Comparaison de position entre characters

bool Character::Compare_pos_char(Character char2){
    return (_position == char2.get_Position());
}

//-----------------------------------------------------------------

// Affichage

void Character::Display_pos_char(){
    std::cout << "(" << _position.get_coord_x() << "," << _position.get_coord_y() << ").\n" ;
}
