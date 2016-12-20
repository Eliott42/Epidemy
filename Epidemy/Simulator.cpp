//
//  Simulator.cpp
//  Epidemy
//
//  Created by Eliott Jouhaud on 16/12/2016.
//  Copyright © 2016 Eliott Jouhaud. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <cstdlib>

#include "Simulator.h"
#include "Character.h"
#include "Individual.h"
#include "Position.h"

int nb_char = 10;

// Constructeur

Simulator::Simulator(int n){
    _nb_cycles = n;
    for (int i = 0; i < nb_char; i++){
        _character_simules[i] = new Individual();
    }
}

// Méthodes

// Fonction qui lance un tour de la simulation : fait se déplacer (ou non) l'ensemble des individus, puis permet l'infection (ou non) des individus sur la même position

void Simulator::Tour_de_simulation(){
    double proba_stay = 0.3; // Probabilité de rester sur place
    
    // On fait se déplacer l'ensemble des individus, avec une proba p de rester sur place
    for (int i = 0; i < nb_char; i++){
        srand((int)time(NULL));
        if ((rand()/RAND_MAX) >= proba_stay){
            _character_simules[i]->Move();
        }
    }
    
    // On compare la position des individus : un individu à côte d'un autre a une probabilité d'être infecté si l'autre est infecté
    for (int i = 0; i < nb_char; i++){
        for (int j = 0; j < nb_char; j++){
            //  && _character_simules[j].get_Status() == 'I'
            if ((i != j) && _character_simules[i] -> Compare_pos_char(*_character_simules[j])) {
                if (_character_simules[j]->get_Status() == 'I'){
                    
                }
            }
        }
    }
}
