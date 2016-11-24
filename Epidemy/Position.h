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
    
    //Setters
    void set_Coord_x(double x);
    void set_Coord_y(double y);
    
    //Getters
    double get_Coord_x();
    double get_Coord_y();
    
    //Functions to move
    void Move_left();
    void Move_right();
    void Move_up();
    void Move_down();
    void Move();
    
};

#endif /* Position_h */
