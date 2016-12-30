//
//  GraphicSimulator.h
//  Epidemy
//
//  Created by Eliott Jouhaud on 30/12/2016.
//  Copyright © 2016 Eliott Jouhaud. All rights reserved.
//

#ifndef GraphicSimulator_h
#define GraphicSimulator_h

#include "Position.h"
#include "Character.h"
#include <SDL2/SDL.h>
#include <SDL2_gfxPrimitives.h>

class GraphicSimulator{
    
private:
    //----------Attributs concernant les graphismes--------------------------
    SDL_Window* _fenetre = nullptr; // fenêtre pour le rendu
    SDL_Renderer* _renderer = nullptr; // rendu
    
    SDL_Event _events; // file d'attente pour les événement graphiques
    bool quit; // le programme quitte quand le booléen est égal à TRUE
    // Les 3 attributs suivants sont utilisés pour le timing, et notamment les intervalles de temps qu'il va y avoir entre deux images de l'animation finale
    float _delta;
    float _current_time; // temps actuel
    float _previous_time; // temps précédent
    
    //----------Attributs concernant la simulation--------------------------
    int _nb_cycles;
    Character* _character_simules[10]; // nombre de characters simulés
    
    
public:
    GraphicSimulator(unsigned short largeur, unsigned short hauteur, int n); //largeur de la fenêtre, hauteur de la fenêtre, nb de cycles dans la simulation
    ~GraphicSimulator(){}; // Destructeur par défaut
    
    int  loop(); // Boucle principale, qui va appeler les autres fonctions
    void handleEvents(); // gère les événements liés au clavier ou à la souris (fermeture de la fenêtre d'animation par exempe)
    void simulate_one_cycle(); // fait faire les actions aux individus
    void render(); // Fait le rendu graphique des characters à l'écran
    
};

#endif /* GraphicSimulator_h */
