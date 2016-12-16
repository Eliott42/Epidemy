//
//  Position.h
//  Epidemy
//
//  Created by Eliott Jouhaud on 24/11/2016.
//  Copyright © 2016 Eliott Jouhaud. All rights reserved.
//

#ifndef Position_h
#define Position_h

class Position{
    
private:
    double _x;
    double _y;
    
public:
    // Constructeurs
    Position();
    Position(double x, double y);
    
    // Setters
    void set_Coord_x(double x);
    void set_Coord_y(double y);
    
    // Getters
    double get_Coord_x();
    double get_Coord_y();
    
    // Affichage
    void Display_pos();
    
    // Opérateur comparaison de 2 positions
    bool operator==(Position pos2);
    
};

#endif /* Position_h */
