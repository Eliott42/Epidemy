//
//  Individual.cpp
//  Epidemy
//
//  Created by Eliott Jouhaud on 05/12/2016.
//

#include <stdio.h>
#include <iostream>
#include "Position.h"
#include "Individual.h"

// Constructeurs

// Appel du constructeur par défaut de character, et statut "sain"
Individual::Individual() : Character(){
    _current_status = 'S';
    _previous_status = 'S';
}

// On spécifie la position initiale et la destination, mais le statut est sain par défaut.
Individual::Individual(Position pos, Position des) : Character(pos, des){
    _current_status = 'S';
    _previous_status = 'S';
}

Individual::Individual(Position pos, Position des, char status) : Character(pos, des){
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

// L'individu est infecté, son statut passe à I
void Individual::Infect(){
    set_current_status('I');
}

// Il guérit, le statut pas à R
void Individual::Recover(){
    set_current_status('R');
}

void Individual::actualise_status(){
    _previous_status = _current_status;
}


//-----------------------------------------------------------------

// Affichage

void Individual::Display_info(){
    Character::Display_info();
    std::cout << "status " << get_current_status() << "\n";
}
