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

Individual::Individual() : Character(){
    _current_status = 'S';
    _previous_status = 'S';
}

Individual::Individual(Position pos) : Character(pos){
    _current_status = 'S';
    _previous_status = 'S';
}

Individual::Individual(Position pos, char status) : Character(pos){
    _current_status = status;
    _previous_status = status;
}


//-----------------------------------------------------------------

// Setter

void Individual::set_current_status(char status){
    _current_status = status;
}

void Individual::set_previous_status(char status){
    _previous_status = status;
}

// Getter

char Individual::get_current_status(){
    return _current_status;
}

char Individual::get_previous_status(){
    return _previous_status;
}

//-----------------------------------------------------------------

// Fonctions pour changer le statut

void Individual::Infect(){
    set_current_status('I');
}

void Individual::Recover(){
    set_current_status('R');
}

void Individual::actualise_status(){
    _previous_status = _current_status;
}


//-----------------------------------------------------------------

// Affichage

void Individual::Display_pos_indiv(){
    std::cout << "L'individu est situé en";
}


