//
//  main.cpp
//  Epidemy
//
//  Created by Eliott Jouhaud & Johan Guyot on 24/11/2016.
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
    
    // Test si le bon nombre d'argument est entré
    if (argc != 3){
        std::cout << "Pas le bon nombre d'arguments !!!";
        return 0;
    }
    if (atoi(argv[1]) <= 0){
        std::cout << "Impossible de rentrer une population négative !!!";
        return 0;
    }
    
    // Cas de la simulation avec tirage initial uniforme
    if (atoi(argv[2]) == 1){
        GraphicSimulator simgraph(1024, 768, 400, atoi(argv[1])); // Creation de la simulation
        return simgraph.loop(); // Fait tourner la simulation, quitte quand la boucle est finie.
    }
    else{
        // Cas de la simulation avec foyer initial
        if (atoi(argv[2]) == 2){
            Position foyer(50,50);
            GraphicSimulator simgraph(1024, 768, 400, atoi(argv[1]), foyer, 15); // Creation de la simulation
            return simgraph.loop(); // Fait tourner la simulation, quitte quand la boucle est finie.
        }
        else{
            std::cout << "Numéro de simulation inexistant !!!";
        }
    }
    
    
    return 0;
}

