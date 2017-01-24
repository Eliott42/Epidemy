//
//  Simulator.h
//  Epidemy
//
//  Created by Eliott Jouhaud on 16/12/2016.
//

#ifndef Simulator_h
#define Simulator_h

#include <vector>

#include "Position.h"
#include "Character.h"

class Simulator{
    
private:
    int _nb_cycles; // nombre de tours de la simulation
    int _nb_char; // nombre de characters simulés
    std::vector<Character*> _character_simules; // tableaux des characters simulés
    
public:
    // Constructeur
    Simulator(int n, int m);
    // Destructeur
    ~Simulator();
    
    // Getters
    Character* get_Character(int i);
    int get_nb_cycles();
    int get_nb_char();
    
    // Fonction pour lancer un tour de la simulation
    void simulate_one_cycle();
    // Fonction pour lancer la simulation complète
    void simulate_all();
    
    // Fonction affichage de la position de tous les characters simulés.
    void Dislay_pos_simules();
    // Fonction d'affichage de statistiques au i-ème tour sur la progression de l'épidémie.
    void Dislay_statistics(int i);
    
};

#endif /* Simulator_h */
