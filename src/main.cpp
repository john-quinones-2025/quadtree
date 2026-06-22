#include <iostream>
#include "Estructuras.h"
#include "QuadTree.h" 

int main() {
    
    LimiteEspacial pantalla = {400.0, 300.0, 400.0, 300.0};
    
    
    QuadTree arbol(pantalla, 4);

    
    Particle p1 = {1, 50.0, 50.0, 1.5, -1.0, 5.0};
    

    if (arbol.insertar(p1)) {
        
        cout << "particula insertada correctamente" << endl;

    } else {

        cout << "error: particula fuera de limites" << endl;
    }
    
    return 0;
}