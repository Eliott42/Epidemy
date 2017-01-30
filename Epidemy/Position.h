//
//  Position.h
//  Epidemy
//
//  Created by Eliott Jouhaud & Johan Guyot on 24/11/2016.
//

#ifndef Position_h
#define Position_h

class Position{
    
private:
    // La classe position possède deux attributs ; des entiers indiquant la coordonnée x (abscisse) et la coordonnée y (ordonnée) sur la grille
    int _x;
    int _y;
    
    
public:
    // Constructeurs
    Position(); // Par défaut crée une position en (0,0)
    Position(int x, int y); // Crée une position en (x,y)
    
    // Setters
    void set_coord_x(int x);
    void set_coord_y(int y);
    void set_coord_xy(int x, int y);
    
    // Getters
    int get_coord_x();
    int get_coord_y();
    
    // Affichage
    void Display_pos();
    
    // Opérateur comparaison de 2 positions
    bool operator==(Position pos2);
    
};

#endif /* Position_h */
