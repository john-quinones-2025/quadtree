#ifndef QUADTREE_H
#define QUADTREE_H

#include <vector>
#include "Estructuras.h"

using namespace std;


class QuadTree {


private:


    LimiteEspacial limite;       // el area limite
    int capacidad_maxima;        // cantidad de particulas maxima
    vector<Particle> particulas; // guarda las particulas almacenadas
    bool esta_dividido;          // bandera para saber si ya alacenamos los 4 hijos


    // punteros hijos
    QuadTree* noroeste;
    QuadTree* noreste;
    QuadTree* suroeste;
    QuadTree* sureste;


public:
    
    QuadTree(LimiteEspacial l, int capacidad);
    
    ~QuadTree();

    // metodos
    bool insertar(Particle p);
    void subdividir();
};

#endif 