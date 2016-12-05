//
//  Individual.cpp
//  Epidemy
//
//  Created by Eliott Jouhaud on 05/12/2016.
//  Copyright © 2016 Eliott Jouhaud. All rights reserved.
//

#include <stdio.h>
#include <iostream>
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

Position Individual::get_Position(){
    return _position;
}

//-----------------------------------------------------------------

// Fonctions pour changer le statut

void Individual::Infect(){
    set_Status('I');
}

void Individual::Recover(){
    set_Status('R');
}

//-----------------------------------------------------------------

// Affichage

void Individual::Display_pos_indiv(){
    std::cout << "L'individu est situé en (" << _position.get_Coord_x() << "," << _position.get_Coord_y() << ").\n" ;
}


