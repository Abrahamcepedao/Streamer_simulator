#include <iostream>
#include <string>
#ifndef Video_h
#define Video_h
using namespace std;
class Video{
    protected:
        string idVideo;
        string genero;
        string titulo;
        int duracion; 
        int puntaje;
        string tipo;
    public:
        Video();
        Video(string, string, string, int, int, string);

        string getTitulo(){ return titulo; };
        string getGenero(){return genero;};
        float getPuntaje() { return puntaje; };
        string getTipo(){ return tipo; };


        void setPuntaje(int puntaje) { this->puntaje = puntaje; };

        virtual void mostrar() = 0;
};
// constructors
Video::Video(){
    idVideo = "";
    genero = "-";
    titulo = "-";
    duracion = 0;
    puntaje = 1;
    tipo = "";
}
Video::Video(string idVideo, string titulo, string genero, int duracion, int puntaje, string tipo){
    this->idVideo = idVideo;
    this->genero = genero;
    this->titulo = titulo;
    this->duracion = duracion;
    this->puntaje = puntaje;
    this->tipo = tipo;
}
#endif