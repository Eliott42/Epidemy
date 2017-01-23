//
//  main.cpp
//  Epidemy
//
//  Created by Eliott Jouhaud on 24/11/2016.
//  Copyright © 2016 Eliott Jouhaud. All rights reserved.
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
    Character char1(pos);
    //Character* char1 = new Character(pos);
    
    char1.Display_pos_char();
    char1.Move();
    char1.Display_pos_char();
    char1.Move();
    char1.Display_pos_char();
    char1.Move();
    */
    
    /*
    Simulator sim(10);
    
    sim.Dislay_pos_simules();
    sim.simulate_all();
    sim.Dislay_pos_simules();
    */
    
    GraphicSimulator simgraph(1024, 768, 1000); // Creation de la simulation
    return simgraph.loop(); // Loop the simulation, exit when the loop is done

    
    return 0;
}

