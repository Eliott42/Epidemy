//
//  Position.cpp
//  Epidemy
//
//  Created by Eliott Jouhaud on 24/11/2016.
//  Copyright © 2016 Eliott Jouhaud. All rights reserved.
//

#include <stdio.h>
#include "Position.h"


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

//Setters

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