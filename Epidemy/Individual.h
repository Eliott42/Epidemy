//
//  Individual.h
//  Epidemy
//
//  Created by Eliott Jouhaud on 05/12/2016.
//

#ifndef Individual_h
#define Individual_h

#include "Position.h"
#include "Character.h"

class Individual: public Character{
    
private:
    char _current_status; // Statut actuel de l'individu : sain (S), infecté (I) ou rétabli (R).
    char _previous_status; // Statut précédent de l'individu, mis à jour à la fin d'un tour de simulation
    
public:
    // Constructeur
    Individual(); // Par défaut en (0,0) avec destination (0,0)
    Individual(Position pos, Position des);
    Individual(Position pos, Position des, char status);
    
    // Setter
    virtual void set_current_status(char status);
    virtual void set_previous_status(char status);
    
    // Getter
    virtual char get_current_status();
    virtual char get_previous_status();
    
    // Fonctions pour changer le statut
    virtual void Infect();
    virtual void Recover();
    virtual void actualise_status();
    
    // Affichage
    virtual void Display_info();
};

#endif /* Individual_h */
