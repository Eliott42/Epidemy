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

// Constructeur

Simulator::Simulator(int n){
    _nb_cycles = n;
    for (int i = 0; i < 10; i++){
        _character_simules[i] = Individual();
    }
}

// Méthodes

// Fonction qui lance un tour de la simulation : fait se déplacer (ou non) l'ensemble des individus, puis permet l'infection (ou non) des individus sur la même position
void Simulator::Tour_de_simulation(){
    double proba_stay = 0.3; // Probabilité de rester sur place
    for (int i = 0; i < 10; i++){
        srand((int)time(NULL));
        if ((rand()/RAND_MAX) >= proba_stay){
            _character_simules[i].Move();
        }
    }
}

//