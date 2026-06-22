#include "QuadTree.h"



// construimos el quadtree con un limite y una capacidad
QuadTree::QuadTree(LimiteEspacial l, int capacidad) {


    limite = l;
    capacidad_maxima = capacidad;
    esta_dividido = false;      //al inicio no tiene hijos por eso lo ponemos en false
    
    noroeste = nullptr;
    noreste = nullptr;
    suroeste = nullptr;
    sureste = nullptr;
}


QuadTree::~QuadTree() {


    // si tiene hijos, los borra
    if (esta_dividido) {

        delete noroeste;
        delete noreste;
        delete suroeste;
        delete sureste;
    }
}


// metodo para subdividir el cuadrante del QuadTree
void QuadTree::subdividir() {


    double x = limite.centro_x;
    double y = limite.centro_y;
    double m_ancho = limite.mitad_ancho / 2.0;
    double m_alto = limite.mitad_alto / 2.0;

    // creamos los 4 cuadrantes hijos
    LimiteEspacial limite_no = {x - m_ancho, y - m_alto, m_ancho, m_alto};
    noroeste = new QuadTree(limite_no, capacidad_maxima);

    LimiteEspacial limite_ne = {x + m_ancho, y - m_alto, m_ancho, m_alto};
    noreste = new QuadTree(limite_ne, capacidad_maxima);

    LimiteEspacial limite_so = {x - m_ancho, y + m_alto, m_ancho, m_alto};
    suroeste = new QuadTree(limite_so, capacidad_maxima);

    LimiteEspacial limite_se = {x + m_ancho, y + m_alto, m_ancho, m_alto};
    sureste = new QuadTree(limite_se, capacidad_maxima);

    // prendemos la bandera, ya fue dividido el quadtree
    esta_dividido = true;
}



// metodo para insertar una particula por recursion en un quadtree hijo
bool QuadTree::insertar(Particle p) {


    // si no esta en los limites la ignoramos
    if (!limite.contienePunto(p.x, p.y)) {

        return false;
    }

    // si hay espacio y no se ha subdividido la guardamos aqui
    if (particulas.size() < capacidad_maxima && !esta_dividido) {

        particulas.push_back(p);
        return true;
    }

    // si llegamos a capacidad maxima y no esta subdividido, subdividimos
    if (!esta_dividido) {

        subdividir();
    }

    // si llegamos hasta aqui es porque ya subdividimos, entonces insertamos por recursion 
    // en ese orden

    if (noroeste->insertar(p)) return true;
    if (noreste->insertar(p)) return true;
    if (suroeste->insertar(p)) return true;
    if (sureste->insertar(p)) return true;

    return false; 
}