//
//  Character.cpp
//  Epidemy
//
//  Created by Eliott Jouhaud on 08/12/2016.
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
    _position = Position(); // par défaut le character est en (0,0)
    _destination = Position(); // Sa destination est (0,0)
    _arrived = 1;
}

Character::Character(Position pos, Position des){
    _position = pos;
    _destination = des;
    if (pos == des){
        _arrived = 1;
    }
    else _arrived = 0;
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

// Fonction permettant de se déplacer jusqu'à la destination initiale. Le principe est le suivant : Le character se déplace d'abord horizontalement sur la grille, jusqu'à atteindre la colonne de sa destination. Ensuite, il se déplace verticalement.

void Character::Move_to_destination(){
    // On teste d'abord si le character est arrivé à destination. Si ce n'est pas le cas, il se déplace.
    if (_arrived == 0){
        if (_position.get_coord_x() < _destination.get_coord_x()){
            Move_right();
        }
        else{
            if (_position.get_coord_x() > _destination.get_coord_x()){
                Move_left();
            }
            else {
                if (_position.get_coord_y() < _destination.get_coord_y()){
                    Move_up();
                }
                else{
                    if (_position.get_coord_y() > _destination.get_coord_y()){
                        Move_down();
                    }
                }
            }
        }
    }
}

//-----------------------------------------------------------------

// Comparaison de position entre characters

bool Character::Compare_pos_char(Character char2){
    return (_position == char2.get_Position());
}

//-----------------------------------------------------------------

// Affichage

void Character::Display_info(){
    std::cout << "(" << _position.get_coord_x() << "," << _position.get_coord_y() << ") " ;
}
