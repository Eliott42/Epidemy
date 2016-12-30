//
//  GraphicSimulator.cpp
//  Epidemy
//
//  Created by Eliott Jouhaud on 30/12/2016.
//  Copyright © 2016 Eliott Jouhaud. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_gfxPrimitives.h>

#include "GraphicSimulator.h"
#include "Character.h"
#include "Individual.h"
#include "Position.h"

int nb_char2 = 10;

// Constructeur

GraphicSimulator::GraphicSimulator(unsigned short largeur, unsigned short hauteur, int n)
{
    //----------Attributs concernant les graphismes--------------------------
    // Initialisation de l'interface graphique (image et temps)
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    
    // Définition de la fenêtre
    _fenetre = SDL_CreateWindow("Simulation epidemie",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              largeur, hauteur, SDL_WINDOW_SHOWN);
    
    // Initialisation du rendu
    _renderer = SDL_CreateRenderer(_fenetre, -1, 0);
    
    // Initialisation du booléen pour que le programme ne quitte pas immédiatement
    quit = false;
    
    // Initialisation des différents attributs temporels
    _delta = 0.0f;
    _current_time = 0.0f;
    _previous_time = 0.0f;
    
    //----------Attributs concernant la simulation--------------------------
    _nb_cycles = n; // Initialisation du nb de cycles de la simulation
    srand((int)time(NULL)); // Initialise la seed de la fonction rand()
    
    Character::bound_right = 100; // Initialisation de la taille de la grille (ville)
    Character::bound_up = 100;
    
    Position random_pos; // On définit une position, qui va ensuite changer aléatoirement pour initialiser les individus
    double proba_infect_init = 0.4; // Probabilité que l'individu soit infecté dès le début
    
    for (int i = 0; i < nb_char2; i++){
        // Génération d'une position aléatoire
        random_pos.set_coord_xy(rand()%Character::bound_right,rand()%Character::bound_up);
        // Création de l'individu à cette position aléatoire
        _character_simules[i] = new Individual(random_pos);
        // L'individu a une probabilité d'être infecté dès le début
        if (((double)rand())/RAND_MAX <= proba_infect_init){
            _character_simules[i] -> Infect();
        }
    }
}

//-----------------------------------------------------------------


// Méthodes


// Boucle qui, à chaque cycle de la simulation, appelle les fonctions qui ont se déplacer et intéragir les individus, puis les fonctions qui permmettent le rendu graphique

int GraphicSimulator::loop()
{
    while (!quit) // While quit is false
    {
        // Nous mettons à jour les temps, en déterminant quel est l'intervalle entre deux rendus
        _current_time = (float)SDL_GetTicks();
        _delta = (_current_time - _previous_time) / 1000.0f;
        _previous_time = _current_time;
        
        handleEvents(); // Start calling each needed function, each is self explanatory
        simulate_one_cycle();
        render();
        
        // SDL_Flip(_fenetre); // Affichage de la simulation
        SDL_Delay(10); // pause pour voir le rendu
    }
    
    return 0; // Valeur renvoyée dans main() : 0 indique que l'on quitte le programme
}


// Gestion des événements liés au clavier ou à la souris

void GraphicSimulator::handleEvents()
{
    while (SDL_PollEvent(&_events)) // Tant qu'il ya des événements à gérer, faire:
    {
        // Si l'utilisateur a fermé la fenêtre d'animation, nous quittons le programme
        if (_events.type == SDL_QUIT)
        {
            quit = true; // le programme quitte
        }
    }
}



// Fonction qui lance un tour de la simulation : fait se déplacer (ou non) l'ensemble des individus, puis permet l'infection (ou non) des individus sur la même position

void GraphicSimulator::simulate_one_cycle()
{
    double proba_stay = 0.2; // Probabilité de rester sur place
    double proba_infect = 0.4; // Probabilité d'être infecté quand on est en contact avec un infecté
    double proba_recover = 0.2; // Probabilité de guérir
    
    // On fait se déplacer l'ensemble des individus, avec une proba p de rester sur place
    for (int i = 0; i < nb_char2; i++){
        double p = ((double)rand())/RAND_MAX;
        if (p >= proba_stay){
            _character_simules[i]->Move();
        }
        _character_simules[i]->Display_info();
    }
    
    // On compare la position des individus : un individu à côte d'un autre a une probabilité d'être infecté si l'autre est infecté. Il faut donc 2 boucles pour comparer tous les individus avec tous les autres
    for (int i = 0; i < nb_char2; i++){
        for (int j = 0; j < nb_char2; j++){
            if ((i != j) && _character_simules[i]->Compare_pos_char(*_character_simules[j]) && _character_simules[j]->get_previous_status() == 'I') {
                // Probabilité d'être infecté si l'on est sain (et non rétabli)
                if (_character_simules[j]->get_previous_status() == 'S' && ((double)rand())/RAND_MAX <= proba_infect){
                    _character_simules[i] -> Infect();
                }
            }
        }
    }
    
    // À la fin du tour, chaque individu infecté à une chance de guérir
    for (int i = 0; i < nb_char2; i++){
        if (_character_simules[i] -> get_current_status() == 'I'){
            if (((double)rand())/RAND_MAX <= proba_recover){
                _character_simules[i] -> Recover();
            }
        }
    }
    
    // À la fin du tour, on atualise les statuts des individus
    for (int i = 0; i < nb_char2; i++){
        _character_simules[i] -> actualise_status();
    }
}


// fonction permettant de faire le rendu graphique

void GraphicSimulator::render() //
{
    // Nettoyage de l'écran avec la couleur choisie
    SDL_RenderClear(_renderer);
    // Définition du rayon du cercle qui va représenter l'individu
    Sint16 circleR = 10;
    
    // Nous traçons un cercle pour chaque individu sur la grille
    for (int i = 0; i < nb_char2; i++)
    {
        filledCircleColor(_renderer, _character_simules[i] -> get_Position().get_coord_x(),
                          _character_simules[i] -> get_Position().get_coord_y(),
                          circleR, 0xFF0000FF);
    }
}