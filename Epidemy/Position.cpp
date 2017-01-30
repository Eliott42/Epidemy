//
//  Position.cpp
//  Epidemy
//
//  Created by Eliott Jouhaud & Johan Guyot on 24/11/2016.
//

#include <stdio.h>
#include <iostream>

#include "Position.h"

//Constructeurs

//Constructeur par défaut : initialisation de la position à (0,0)
Position::Position(){
    _x = 0;
    _y = 0;
}

//Constructeur ou l'on spécifie en entrée les coordonnées (x,y)
Position::Position(int x, int y){
    _x = x;
    _y = y;
}

//-----------------------------------------------------------------

// Setters

void Position::set_coord_x(int x){
    _x = x;
}

void Position::set_coord_y(int y){
    _y = y;
}

void Position::set_coord_xy(int x, int y){
    _x = x;
    _y = y;
}

// Getters

int Position::get_coord_x(){
    return _x;
}

int Position::get_coord_y(){
    return _y;
}


//-----------------------------------------------------------------

// Affichage

void Position::Display_pos(){
    std::cout << "(" << get_coord_x() << "," << get_coord_y() << ")\n";
}

//-----------------------------------------------------------------

// Opérateur comparaison de 2 positions

bool Position::operator==(Position pos2){
    return ((_x == pos2.get_coord_x()) && (_y == pos2.get_coord_y()));
}
