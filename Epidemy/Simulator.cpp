//
//  Simulator.cpp
//  Epidemy
//
//  Created by Eliott Jouhaud on 16/12/2016.
//

#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

#include "Simulator.h"
#include "Character.h"
#include "Individual.h"
#include "Position.h"


// Constructeurs

// Première version où les infectés sont répartis aléatoirement dans la population au début

Simulator::Simulator(int n, int m){
    _nb_cycles = n; // Initialisation du nb de cycles de la simulation
    _nb_char = m; // Initialisation du nb de characters simulés
    
    srand((int)time(NULL)); // Initialise la seed de la fonction rand()
    Character::bound_right = 100; // Initialisation de la taille de la grille (ville)
    Character::bound_up = 100;
    Position random_pos; // On définit une position, qui va ensuite changer aléatoirement pour initialiser les individus
    Position random_des; // De même on définit une destination aléatoire pour cahque individu
    double proba_infect_init = 0.6; // Probabilité que l'individu soit infecté dès le début
    
    for (int i = 0; i < _nb_char; i++){
        // Génération d'une position et d'une destination aléatoire
        random_pos.set_coord_xy(rand()%Character::bound_right,rand()%Character::bound_up);
        random_des.set_coord_xy(rand()%Character::bound_right,rand()%Character::bound_up);
        
        // Création de l'individu à cette position aléatoire
        _character_simules.push_back(new Individual(random_pos, random_des));
        
        // L'individu a une probabilité d'être infecté dès le début
        if (((double)rand())/RAND_MAX <= proba_infect_init){
            _character_simules[i] -> Infect();
            _character_simules[i] -> actualise_status();
        }
    }
}

// Seconde version où les infectés apparaissent dans une zone particulière, autour d'un foyer, jusque dans un certain rayon.

Simulator::Simulator(int n, int m, Position epicentre, int radius){
    _nb_cycles = n; // Initialisation du nb de cycles de la simulation
    _nb_char = m; // Initialisation du nb de characters simulés
    
    srand((int)time(NULL)); // Initialise la seed de la fonction rand()
    Character::bound_right = 100; // Initialisation de la taille de la grille (ville)
    Character::bound_up = 100;
    Position random_pos; // On définit une position, qui va ensuite changer aléatoirement pour initialiser les individus
    Position random_des; // De même on définit une destination aléatoire pour cahque individu
    
    for (int i = 0; i < _nb_char; i++){
        // Génération d'une position et d'une destination aléatoire
        random_pos.set_coord_xy(rand()%Character::bound_right,rand()%Character::bound_up);
        random_des.set_coord_xy(rand()%Character::bound_right,rand()%Character::bound_up);
        
        // Si la position est dans le foyer d'infection (carré de centre "epicentre" et de largeur/longueur 2 x "radius" alors l'individu né infecté.
        // Création de l'individu à cette position aléatoire
        if (std::abs(random_pos.get_coord_x() - epicentre.get_coord_x()) <= radius && std::abs(random_pos.get_coord_y() - epicentre.get_coord_y()) <= radius) {
            _character_simules.push_back(new Individual(random_pos, random_des, 'I'));
        }
        else{
            _character_simules.push_back(new Individual(random_pos, random_des));
        }
    }
}

// Destructeur

Simulator::~Simulator(){
    for (int i = 0; i < _nb_char; i++){
        delete _character_simules[i];
    }
}

//-----------------------------------------------------------------

// Getters

// Pour les characters
Character* Simulator::get_Character(int i){
    return _character_simules[i];
}

// Pour le nombre de cycles
int Simulator::get_nb_cycles(){
    return _nb_cycles;
}

// Pour le nombre de characters
int Simulator::get_nb_char(){
    return _nb_char;
}


//-----------------------------------------------------------------

// Autres Méthodes

// Fonction qui lance un tour de la simulation : fait se déplacer (ou non) l'ensemble des individus, puis permet l'infection (ou non) des individus sur la même position

void Simulator::simulate_one_cycle(int k, std::ofstream& file){
    double proba_stay = 0.5; // Probabilité de rester sur place
    double proba_infect = 1; // Probabilité d'être infecté quand on est en contact avec un infecté
    double proba_recover = 0.03; // Probabilité de guérir
    
    // On fait se déplacer l'ensemble des individus, avec une proba p de rester sur place.
    for (int i = 0; i < _nb_char; i++){
        _character_simules[i]->Move_to_destination2();
        //_character_simules[i]->Display_info();
    }
    
    // Pour les individus arrivés à destination, il ya une probabilité de rester sur place. Sinon, on tire une nouvelle destination aléatoire.
    for (int i = 0; i < _nb_char; i++){
        if (_character_simules[i]->is_Arrived()) {
            double p = ((double)rand())/RAND_MAX;
            if (p >= proba_stay){
                _character_simules[i]->set_Destination(rand()%Character::bound_right, rand()%Character::bound_up);
            }
        }
    }
    
    // On compare la position des individus : un individu à côte d'un autre a une probabilité d'être infecté si l'autre est infecté. Il faut donc 2 boucles pour comparer tous les individus avec tous les autres.
    for (int i = 0; i < _nb_char; i++){
        for (int j = 0; j < _nb_char; j++){
            if ((i != j) && _character_simules[i]->Compare_pos_char(*_character_simules[j]) && _character_simules[j]->get_previous_status() == 'I') {
                // Probabilité d'être infecté si l'on est sain (et non rétabli)
                if (_character_simules[i]->get_previous_status() == 'S' && ((double)rand())/RAND_MAX <= proba_infect){
                    _character_simules[i] -> Infect();
                }
            }
        }
    }
    
    // À la fin du tour, chaque individu anciennement infecté à une chance de guérir
    for (int i = 0; i < _nb_char; i++){
        if (_character_simules[i] -> get_previous_status() == 'I'){
            if (((double)rand())/RAND_MAX <= proba_recover){
                _character_simules[i] -> Recover();
            }
        }
    }
    
    // Affichage des statistiques
    Dislay_statistics(k, file);
    
    // À la fin du tour, on atualise les statuts des individus
    for (int i = 0; i < _nb_char; i++){
        _character_simules[i] -> actualise_status();
    }
}

// Fonction lançant la simulation totale : n cycles

void Simulator::simulate_all(std::ofstream& file){
    for (int i = 0; i < _nb_cycles; i++){
        simulate_one_cycle(i, file);
    }
}

//-----------------------------------------------------------------

// Fonction permettant d'afficher la position de l'ensemble des characters simulés

void Simulator::Dislay_pos_simules(){
    for (int i = 0; i < _nb_char; i++){
        _character_simules[i] -> Display_info();
    }
}

// Fonction permettant d'afficher des statistiques au i-ème tour sur la progression de l'épidémie

void Simulator::Dislay_statistics(int i, std::ofstream& file){
    int count_infect = 0; // Compteur d'invidus infectés au total
    int count_recover = 0; // Compteur d'individus guéris au total
    int count_infect_previously = 0; // Compteur d'invidus qui étaient infectés au tour d'avant
    int count_recover_previously = 0; // Compteur d'individus étaient guéris au tour d'avant
    
    // On comptabilise le nombre total d'individus infectés/guéris/sains
    for (int i = 0; i < _nb_char; i++){
        if (_character_simules[i] -> get_current_status() == 'I'){
            count_infect ++;
        }
        else if (_character_simules[i] -> get_current_status() == 'R'){
            count_recover ++;
        }
    }
    // On comptabilise ceux qui ont été infecté ce tour-ci ou qui ont guéri
    for (int i = 0; i < _nb_char; i++){
        if (_character_simules[i] -> get_previous_status() == 'I'){
            count_infect_previously ++;
        }
        else if (_character_simules[i] -> get_previous_status() == 'R'){
            count_recover_previously ++;
        }
    }
    
    double prop_sane = 100*(double)(_nb_char - count_infect - count_recover)/_nb_char;
    double prop_infected = 100*(double)count_infect/_nb_char;
    double prop_recover = 100*(double)count_recover/_nb_char;
    int nb_infected = count_infect - count_infect_previously;
    int nb_recover = count_recover - count_recover_previously;
    
    // Affichage
    std::cout << "Au tour " << i << ":\n";
    std::cout << "nouveaux infectés :" << nb_infected << "\n";
    std::cout << "nombre de guérisons :" << nb_recover << "\n";
    std::cout << "Proportions :" << prop_sane << "% sains, " << prop_infected << "% infectés, " << prop_recover << "% guéris \n";
    
    // Écriture dans le fichier file
    file << prop_sane << " ; " << prop_infected << " ; " << prop_recover << " ; " << nb_infected << " ; " << nb_recover << "\n";
}