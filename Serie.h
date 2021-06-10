#include <iostream>
#include <string>
#ifndef Serie_h
#define Serie_h
using namespace std;
class Serie{
    protected:
        string idSerie;
        string titulo;
        string genero;
        int cantTemporadas;
        int cantEpisodios;
    public:
        Serie();
        Serie(string, string, string, int, int);

        string getIdSerie(){ return idSerie; };
        string getTitulo(){ return titulo; };
        int getCantTemporadas(){return cantTemporadas;};
        int getCantEpisodios() { return cantEpisodios; };

        void setCantEpisodios(int cantEpisodios) { this->cantEpisodios = cantEpisodios; };
        void setCantTemporadas(int cantTemporadas) { this->cantTemporadas = cantTemporadas; };

        void mostrar();
};
//constructors
Serie::Serie(){
    idSerie = "";
    titulo = "";
    genero = "";
    cantTemporadas = 0;
    cantEpisodios = 0;
}
Serie::Serie(string idSerie, string titulo, string genero, int cantTemporadas, int cantEpisodios){
    this->idSerie = idSerie;
    this->titulo = titulo;
    this->genero = genero;
    this->cantTemporadas = cantTemporadas;
    this->cantEpisodios = cantEpisodios;
}

#endif