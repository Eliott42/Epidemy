//
//  Character.h
//  Epidemy
//
//  Created by Eliott Jouhaud on 08/12/2016.
//

#ifndef Character_h
#define Character_h

#include "Position.h"

class Character{

protected:
    Position _position; // la position actuelle du character
    Position _destination; // la position que souhaite atteindre le character
    bool _arrived; // booléen qui indique si l'individu est arrivé, oui ou non, à destination
    
public:
    // Constructeur
    Character();
    Character(Position pos, Position des);
    
    // Getter
    virtual Position get_Position();
    
    // Fonctions déplacement
    virtual void Move_left();
    virtual void Move_right();
    virtual void Move_up();
    virtual void Move_down();
    virtual void Move();

    // Fonctions implémentées seulement dans les classes filles
    virtual char get_current_status() {return '0';}
    virtual char get_previous_status() {return '0';}
    virtual void Infect(){}
    virtual void Recover(){}
    virtual void actualise_status(){}
    
    // Comparaison de position entre characters
    virtual bool Compare_pos_char(Character char2);
    
    // Affichage
    virtual void Display_info();

    static int bound_right;
    static int bound_up;

    
};

#endif /* Character_h */
