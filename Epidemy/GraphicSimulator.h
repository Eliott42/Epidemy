//
//  GraphicSimulator.h
//  Epidemy
//
//  Created by Eliott Jouhaud on 30/12/2016.
//

#ifndef GraphicSimulator_h
#define GraphicSimulator_h

#include "Position.h"
#include "Simulator.h"
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
    
    Simulator* _sim; // Simulateur qui va contenir tous les characters et les méthodes de simulation
    int _count_cycle; // Compteur de cycles, que l'on incrémente à chaque tour et que l'on compare avec le nb max de cycles, pour savoir quand arreter la simulation
    
public:
    GraphicSimulator(unsigned short largeur, unsigned short hauteur, int n, int m);
    // largeur de la fenêtre, hauteur de la fenêtre, nb de cycles dans la simulation, nb de char
    GraphicSimulator(unsigned short largeur, unsigned short hauteur, int n, int m, Position epicentre, int radius);
    //largeur de la fenêtre, hauteur de la fenêtre, nb de cycles dans la simulation, nb de char, foyer de l'épidémie, rayon
    ~GraphicSimulator(){}; // Destructeur par défaut
    
    int  loop(); // Boucle principale, qui va appeler les autres fonctions
    void handleEvents(); // gère les événements liés au clavier ou à la souris (fermeture de la fenêtre d'animation par exempe)
    void render(); // Fait le rendu graphique des characters à l'écran
    
};

#endif /* GraphicSimulator_h */
