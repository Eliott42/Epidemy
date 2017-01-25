//
//  main.cpp
//  Epidemy
//
//  Created by Eliott Jouhaud on 24/11/2016.
//

#include <iostream>
#include <cstdlib>
#include <stdlib.h>

#include "Position.h"
#include "Individual.h"
#include "Character.h"
#include "Simulator.h"
#include "GraphicSimulator.h"


int main(int argc, char **argv) {
    
    /*
    Position pos(2,2);
    Individual char1(pos, pos);
    Individual char2(pos, pos);
    
    char2.Infect();
    
    char1.Display_info();
    char2.Display_info();
    
    char2.actualise_status();
    std::cout << (char2.get_previous_status() == 'I') << "\n";
    
    if (char1.Compare_pos_char(char2) && char2.get_previous_status() == 'I') {
        // Probabilité d'être infecté si l'on est sain (et non rétabli)
        if (char1.get_previous_status() == 'S' && ((double)rand())/RAND_MAX <= 1){
            char1.Infect();
        }
    }
    
    char1.Display_info();
    char2.Display_info();
    */
    
    /*
    Simulator sim(10);
    
    sim.Dislay_pos_simules();
    sim.simulate_all();
    sim.Dislay_pos_simules();
    */
    
    
    GraphicSimulator simgraph(1024, 768, 100, 3); // Creation de la simulation
    return simgraph.loop(); // Loop the simulation, exit when the loop is done
    
    
    return 0;
}

