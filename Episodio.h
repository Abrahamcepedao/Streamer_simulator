#include <iostream>
#include <string>
#ifndef Episodio_h
#define Episodio_h
#include "Video.h"
using namespace std;
class Episodio: public Video{
    private:
        string idSerie;
        int numTemporada;
    public:
        Episodio();
        Episodio(string, string, string, string, int, int, int, string);

        int getNumTemporada() { return numTemporada; };
        string getIdSerie(){ return idSerie; };

        void setNumTemporada(int numTemporada) { this->numTemporada = numTemporada; };

        void mostrar();
};
//constructors
Episodio::Episodio(){
    idSerie = "";
    numTemporada = 1;
}
Episodio::Episodio(string idSerie, string idVideo, string titulo, string genero, int duracion, int puntaje, int numTemporada, string tipo):Video(idVideo, titulo, genero, duracion, puntaje, tipo){
    this->idSerie = idSerie;
    this->numTemporada = numTemporada;
}

//methods
void Episodio::mostrar(){
    cout << "<-----Episodio----->\n";
    cout << "Temporada: " << numTemporada << "\n";
    cout << "id: " << idVideo << " - titulo: " << titulo << " - duracion: " << duracion << " - Rating: " << puntaje << "\n";
}
#endif