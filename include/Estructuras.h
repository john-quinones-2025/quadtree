#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H




// estructura de la particula
struct Particle {


    int id;
    double x, y;
    double vx, vy;
    double radius;
};



// estructura de la caja limitadora
struct LimiteEspacial {



    double centro_x;
    double centro_y;
    double mitad_ancho;
    double mitad_alto;

    // verficador si una particula se encuentra en los limites de la caja
    bool contienePunto(double punto_x, double punto_y)  {

        return (punto_x >= centro_x - mitad_ancho &&
                punto_x <= centro_x + mitad_ancho &&
                punto_y >= centro_y - mitad_alto &&
                punto_y <= centro_y + mitad_alto);
    }
};

#endif 