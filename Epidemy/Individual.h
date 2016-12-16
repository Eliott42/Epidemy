//
//  Individual.h
//  Epidemy
//
//  Created by Eliott Jouhaud on 05/12/2016.
//  Copyright © 2016 Eliott Jouhaud. All rights reserved.
//

#ifndef Individual_h
#define Individual_h

#include "Position.h"
#include "Character.h"

class Individual: public Character{
    
private:
    char _status;
    
public:
    // Constructeur
    Individual();
    Individual(Position pos, char status);
    
    // Setter
    void set_Status(char status);
    
    // Getter
    char get_Status();
    
    // Fonctions pour changer le statut
    void Infect();
    void Recover();
    
    // Affichage
    void Display_pos_indiv();
};

#endif /* Individual_h */
