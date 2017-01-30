//
//  Simulator.h
//  Epidemy
//
//  Created by Eliott Jouhaud on 16/12/2016.
//

#ifndef Simulator_h
#define Simulator_h

#include <vector>
#include <fstream>

#include "Position.h"
#include "Character.h"

class Simulator{
    
private:
    int _nb_cycles; // nombre de tours de la simulation
    int _nb_char; // nombre de characters simulés
    std::vector<Character*> _character_simules; // tableaux des characters simulés
    
public:
    // Constructeur
    Simulator(int n, int m); // Constructeur avec n cycle et m individus. Les infectés sont tirés aléatoirement au départ
    Simulator(int n, int m, Position epicentre, int radius); // Constructeur avec n cycle et m individus. Les infectés sont ceux situé dans une zone de départ avec un rayon : le foyer de l'épidémie
    // Destructeur
    ~Simulator();
    
    // Getters
    Character* get_Character(int i);
    int get_nb_cycles();
    int get_nb_char();
    
    // Les méthodes suivantes appellelent un fichier en référence pour l'écriture des résultats
    // Fonction pour lancer un tour de la simulation
    void simulate_one_cycle(int k, std::ofstream& file);
    // Fonction pour lancer la simulation complète
    void simulate_all(std::ofstream& file);
    
    // Fonction affichage de la position de tous les characters simulés.
    void Dislay_pos_simules();
    // Fonction d'affichage et d'écriture dans le fichier "file", des statistiques au i-ème tour sur la progression de l'épidémie.
    void Dislay_statistics(int i, std::ofstream& file);
    
};

#endif /* Simulator_h */
