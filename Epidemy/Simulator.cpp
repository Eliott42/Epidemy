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
#include <iostream>

#include "Simulator.h"
#include "Character.h"
#include "Individual.h"
#include "Position.h"

int nb_char = 10;

// Constructeur

Simulator::Simulator(int n){
    _nb_cycles = n;
    srand((int)time(NULL)); // Initialise la seed de la fonction rand()
    Character::bound_right = 100;
    Character::bound_up = 100;
    Position random_pos; // On définit une position, qui va ensuite changer aléatoirement pour initialiser les individus
    for (int i = 0; i < nb_char; i++){
        random_pos.set_coord_xy(rand()%Character::bound_right,rand()%Character::bound_up);
        _character_simules[i] = new Individual(random_pos);
    }
}

// Destructeur
Simulator::~Simulator(){
    for (int i = 0; i < nb_char; i++){
        delete _character_simules[i];
    }
}

//-----------------------------------------------------------------

// Méthodes

// Fonction qui lance un tour de la simulation : fait se déplacer (ou non) l'ensemble des individus, puis permet l'infection (ou non) des individus sur la même position

void Simulator::Tour_de_simulation(){
    double proba_stay = 0.2; // Probabilité de rester sur place
    double proba_infect = 0.4; // Probabilité d'être infecté quand on est en contact avec un infecté
    double proba_recover = 0.2; // Probabilité de guérir
    
    // On fait se déplacer l'ensemble des individus, avec une proba p de rester sur place
    for (int i = 0; i < nb_char; i++){
        std::cout << i << " ,";
        double p = ((double)rand())/RAND_MAX;
        std::cout << p << " ,";
        if (p >= proba_stay){
            _character_simules[i]->Move();
        }
        _character_simules[i]->Display_pos_char();
    }
    
    // On compare la position des individus : un individu à côte d'un autre a une probabilité d'être infecté si l'autre est infecté. Il faut donc 2 boucles pour comparer tous les individus avec tous les autres
    for (int i = 0; i < nb_char; i++){
        for (int j = 0; j < nb_char; j++){
            if ((i != j) && _character_simules[i]->Compare_pos_char(*_character_simules[j]) && _character_simules[j]->get_previous_status() == 'I') {
                // Probabilité d'être infecté si l'on est sain (et non rétabli)
                if (_character_simules[j]->get_previous_status() == 'S' && ((double)rand())/RAND_MAX <= proba_infect){
                    _character_simules[i] -> Infect();
                }
            }
        }
    }
    
    // À la fin du tour, chaque individu infecté à une chance de guérir
    for (int i = 0; i < nb_char; i++){
        if (_character_simules[i] -> get_current_status() == 'I'){
            if (((double)rand())/RAND_MAX <= proba_recover){
                _character_simules[i] -> Recover();
            }
        }
    }
    
    // À la fin du tour, on atualis les statuts des individus
    for (int i = 0; i < nb_char; i++){
        _character_simules[i] -> actualise_status();
    }
}

//-----------------------------------------------------------------

// Fonction permettant d'afficher la position de l'ensemble des characters simulés

void Simulator::Dislay_pos_simules(){
    for (int i = 0; i < nb_char; i++){
        _character_simules[i] -> Display_pos_char();
    }
}
