#include <iostream>
#include <string>
#ifndef Pelicula_h
#define Pelicula_h
#include "Video.h"
using namespace std;
class Pelicula: public Video{
    
    public:
        Pelicula();
        Pelicula(string, string, string, int, int, string);


        void mostrar();
};
// constructors
Pelicula::Pelicula(){
    
}
Pelicula::Pelicula(string idVideo, string titulo, string genero, int duracion, int puntaje, string tipo):Video(idVideo, titulo, genero, duracion, puntaje, tipo){}
//methods
void Pelicula::mostrar(){
    cout << "id: " << idVideo << " - titulo: " << titulo << " - genero: " << genero << " - duracion: " << duracion << " - Rating: " << puntaje << "\n";
}
#endif