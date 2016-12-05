//
//  Position.cpp
//  Epidemy
//
//  Created by Eliott Jouhaud on 24/11/2016.
//  Copyright © 2016 Eliott Jouhaud. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <iostream>

#include "Position.h"

int bound_right = 100;
int bound_up = 100;

//Constructeurs

//Constructeur par défaut : initialisation de la position à (0,0)
Position::Position(){
    _x = 0;
    _y = 0;
}

//Constructeur ou l'on spécifie en entrée les coordonnées (x,y)
Position::Position(double x, double y){
    _x = x;
    _y = y;
}

//-----------------------------------------------------------------

// Setters

void Position::set_Coord_x(double x){
    _x = x;
}

void Position::set_Coord_y(double y){
    _y = y;
}

// Getters

double Position::get_Coord_x(){
    return _x;
}

double Position::get_Coord_y(){
    return _y;
}

//-----------------------------------------------------------------

// Functions to move

void Position::Move_left(){
    if (_x != 0){
        _x = _x - 1;
    }
}

void Position::Move_right(){
    if (_x != bound_right){
        _x = _x + 1;
    }
}

void Position::Move_down(){
    if (_y != 0){
        _y = _y - 1;
    }
}

void Position::Move_up(){
    if (_y != bound_up){
        _y = _y + 1;
    }
}

void Position::Move(){
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

//-----------------------------------------------------------------

// Affichage

void Position::Display_pos(){
    std::cout << "(" << get_Coord_x() << "," << get_Coord_y() << ")\n";
}





