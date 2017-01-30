//
//  main.cpp
//  Epidemy
//
//  Created by Eliott Jouhaud on 24/11/2016.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>

#include "Position.h"
#include "Individual.h"
#include "Character.h"
#include "Simulator.h"
#include "GraphicSimulator.h"


int main(int argc, char **argv) {
    
    
    /*
    Simulator sim(10);
    
    sim.Dislay_pos_simules();
    sim.simulate_all();
    sim.Dislay_pos_simules();
    */
    
    
    Position foyer(50,50);
    GraphicSimulator simgraph(1024, 768, 300, 1000); // Creation de la simulation
    
    // GraphicSimulator simgraph(1024, 768, 1000, 1000, foyer, 15); // Creation de la simulation
    return simgraph.loop(); // Loop the simulation, exit when the loop is done
    
    
    return 0;
}

