//
//  GraphicSimulator.cpp
//  Epidemy
//
//  Created by Eliott Jouhaud on 30/12/2016.
//

#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_gfxPrimitives.h>

#include "GraphicSimulator.h"
#include "Simulator.h"
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
    _renderer = SDL_CreateRenderer(_fenetre, -1, SDL_RENDERER_ACCELERATED);
    
    // Initialisation du booléen pour que le programme ne quitte pas immédiatement
    quit = false;
    
    // Initialisation des différents attributs temporels
    _delta = 0.0f;
    _current_time = 0.0f;
    _previous_time = 0.0f;
    
    //----------Attributs concernant la simulation--------------------------
    
    _count_cycle = 1; // On commence le compteur de cycles à 1
    _sim = new Simulator(n);
}

//-----------------------------------------------------------------


// Méthodes


// Boucle qui, à chaque cycle de la simulation, appelle les fonctions qui font se déplacer et intéragir les individus, puis les fonctions qui permettent le rendu graphique

int GraphicSimulator::loop()
{
    int n = _sim -> get_nb_cycles();
    
    while (!quit && (_count_cycle < n)) // While quit is false
    {
        // Nous mettons à jour les temps, en déterminant quel est l'intervalle entre deux rendus
        _current_time = (float)SDL_GetTicks();
        _delta = (_current_time - _previous_time) / 1000.0f;
        _previous_time = _current_time;
        
        handleEvents(); // Fonction gérant les événements liées à la souris ou clavier
        _sim -> simulate_one_cycle();
        render();
        
        // Affichage de la simulation
        SDL_RenderPresent(_renderer);
        SDL_Delay(500); // pause pour voir le rendu
        
        _count_cycle++ ;
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


// fonction permettant de faire le rendu graphique

void GraphicSimulator::render() //
{
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255); // choix de la couleur du rendu (blanc)
    // Nettoyage de l'écran avec la couleur choisie
    SDL_RenderClear(_renderer);
    // Définition du rayon du cercle qui va représenter l'individu
    Sint16 circleR = 10;
    
    // Nous traçons la grille
    for (int i = 0; i < 101; i++){
        vlineColor(_renderer, 7*i, 0, 7*100, 0xFFFFF0FF);
        hlineColor(_renderer, 0, 7*100, 7*i, 0xFFFFF0FF);
    }
    
    // Nous traçons un cercle pour chaque individu sur la grille
    for (int i = 0; i < nb_char2; i++)
    {
        Sint16 xc = _sim -> get_Character(i) -> get_Position().get_coord_x();
        Sint16 yc = _sim -> get_Character(i) -> get_Position().get_coord_y();
        Sint32 color=0xFF00FF00;
        
        if (_sim -> get_Character(i) -> get_current_status() == 'I'){
            color=0xFF0000FF;
        }
        //Débuggage
        //std::cout << "xc: " << xc << ", yc: " << yc << " et " << color << ", " << _sim -> get_Character(i) -> get_current_status() << "\n";
        filledCircleColor(_renderer, 7*xc,7*yc,circleR, color);
    }
}