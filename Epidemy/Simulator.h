//
//  Simulator.h
//  Epidemy
//
//  Created by Eliott Jouhaud on 16/12/2016.
//  Copyright © 2016 Eliott Jouhaud. All rights reserved.
//

#ifndef Simulator_h
#define Simulator_h

#include "Position.h"
#include "Character.h"

class Simulator{
    
private:
    int _nb_cycles;
    Character* _character_simules[10];
    
public:
    // Constructeur
    Simulator(int n);
    // Destructeur
    ~Simulator();
    
    // Fonction pour lancer un tour de la simulation
    void Tour_de_simulation();
    
    // Fonction affichage de la position de tous les characters simulés.
    void Dislay_pos_simules();
    
};

#endif /* Simulator_h */
