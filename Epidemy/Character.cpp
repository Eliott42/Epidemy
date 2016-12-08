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
#include "Character.h"

int bound_right = 100;
int bound_up = 100;

// Constructeurs


//-----------------------------------------------------------------

// Fonctions déplacement

void Character::Move_left(){
    if (_position.get_Coord_x() != 0){
        _position.set_Coord_x(_position.get_Coord_x() - 1);
    }
}

void Character::Move_right(){
    if (_position.get_Coord_x() != bound_right){
        _position.set_Coord_x(_position.get_Coord_x() + 1);
    }
}

void Character::Move_down(){
    if (_position.get_Coord_y() != 0){
        _position.set_Coord_y(_position.get_Coord_y() - 1);
    }
}

void Character::Move_up(){
    if (_position.get_Coord_y() != bound_up){
        _position.set_Coord_y(_position.get_Coord_y() + 1);
    }
}

void Character::Move(){
    int i;
    srand(time(NULL)); // Initialise la seed de la fonction rand()
    i = rand()%4; // Génère un nombre aléatoire entre 1 et 4
    
    switch (i){
        case 0:
            Move_left();
        case 1:
            Move_right();
        case 2:
            Move_down();
        case 3:
            Move_up();
    }
}
