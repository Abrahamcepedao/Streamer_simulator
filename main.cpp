#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <limits>
#include "Serie.h"
#include "Episodio.h"
#include "Pelicula.h"

using namespace std;

int cantVideos = 1075;
int cantMovies = 100;
int cantSeries = 50;
Video *videos[1075];
Serie *series[50];

int validarNum(int min, int max){
    int num;
    cin >> num;
    while(1){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Ingrese un número!\n";
            cin >> num;
        }
        if(!cin.fail()){
            if(num < min || num > max){
                cout << "Ingrese un número válido!\n";
                cin >> num;
            } else{
                break;
            }
        }
    }
    return num;
}

/* Cargar datos */
int calcEpiTemp(int cantEpi, int cantTemp, int n){
    int num = cantEpi / cantTemp;
    int rem = cantEpi % cantTemp;
    if(n < (cantTemp-1)){
        return num;
    } else{
        return num + rem;
    }
}

void cargarDatos(){
    // declare variables
    int count = 0;
    string id, titulo, genero;
    int duracion, puntaje;
    
    // add movie objects
    ifstream archivoPeliculas;
    archivoPeliculas.open("peliculas.txt");
    srand(time(0));
    while (archivoPeliculas >> id >> titulo >> genero >> duracion){
        puntaje = rand() % 5 + 1;
        videos[count] = new Pelicula(id, titulo, genero, duracion, puntaje, "pelicula");
        count++;
    }
    archivoPeliculas.close();

    // add series objects
    ifstream archivoSeries;
    archivoSeries.open("series.txt");
    int cantTemporadas, cantEpisodios, videosCount = count, countSeries = 0,  cantEpiTemp, countEpisodio = 1;
    srand(time(0));
    while(archivoSeries >> id >> titulo >>  cantEpisodios >> genero >> cantTemporadas >> duracion){
        series[countSeries] = new Serie(id, titulo, genero, cantTemporadas, cantEpisodios);
        for(int i = 0; i < cantTemporadas; i++){
            cantEpiTemp = calcEpiTemp(cantEpisodios, cantTemporadas, i);
            for(int j = 0; j < cantEpiTemp; j++){
                videos[videosCount] = new Episodio(id, id + "_episode" + to_string(countEpisodio), id + "_Episode_" + to_string(countEpisodio), genero, duracion, rand() % 5 + 1, i + 1, "episodio");
                videosCount++;
                countEpisodio++;
            }
        }
        countEpisodio = 1;
        countSeries++;
    }
}

/* buscar videos por genero */
void buscarGenero(){
    string genero;
    int count = 0;
    cout << "Ingrese genero: ";
    cin >> genero;
    for(int i = 0; i < cantVideos; i++){
        if(videos[i]->getGenero() == genero){
            videos[i]->mostrar();
            count++;
        }
    }
    if(count == 0){
        cout << "No se encontraro videos con ese género\n";
    }

}

/* buscar videos por calificacion */
void buscarPuntaje(){
    int puntaje;
    int count = 0;
    cout << "Ingrese puntaje mínimo (1-5): ";
    puntaje = validarNum(1,5);
    for(int i = 0; i < cantVideos; i++){
        if(videos[i]->getPuntaje() == puntaje){
            videos[i]->mostrar();
            count++;
        }
    }
    if(count == 0){
        cout << "No se encontraro videos con ese puntaje\n";
    }
}


/* videos con calificacion y genero */
void mostrarVideos(){
    int ans;
    cout << "Ingrese 1 para buscar por genero y 2 para  buscar por calificacion: ";
    ans = validarNum(1,2);
    switch (ans){
    case 1:
        buscarGenero();
        break;
    case 2:
        buscarPuntaje();
    default:
        break;
    }
}


/* Episodios con calificacion */
Serie *seriePorTitutlo(string titulo){
    for(int i = 0; i < cantSeries; i++){
        if(series[i]->getTitulo() == titulo){
            Serie *serie = series[i];
            return serie;
        }
    }
    string nuevoTitulo;
    cout << "No se encontró la serie. Ingrese otro título: ";
    cin >> nuevoTitulo;
    Serie *series = seriePorTitutlo(nuevoTitulo);
    return series;
}

void mostrarEpisodios(){
    string tituloSerie;
    int puntaje;
    cout << "Ingresa el titulo de la serie: ";
    cin >> tituloSerie;

    Serie *serie = seriePorTitutlo(tituloSerie);

    cout << "Ingresa el puntaje mínimo de los episodios (1-5): ";
    puntaje = validarNum(1,5);
    int count = 0;
    for(int i = cantMovies; i < cantVideos; i++){
        if(videos[i]->getTipo() == "episodio"){
            Episodio *episodio = (Episodio *)(videos[i]);
            if(episodio->getIdSerie() == serie->getIdSerie()){
                if(episodio->getPuntaje() == puntaje){
                    episodio->mostrar();
                    count++;
                }
            }
            
        }
    }
    if(count == 0){
        cout << "No se encontraro videos con ese puntaje\n";
    }
}

/* peliculas con calificacion */
void mostrarPeliculas(){
    int puntaje;
    cout << "Ingresa el puntaje mínimo de las peliculas (1-5): ";
    puntaje = validarNum(1,5);
    for(int i = 0; i < cantMovies; i++){
        if(videos[i]->getPuntaje() == puntaje){
            videos[i]->mostrar();
        }
    }

}

Video *videoPorTitulo(string titulo){
    for(int i = 0; i < cantVideos; i++){
        if(videos[i]->getTitulo() == titulo){
            Video *video = videos[i];
            return video;
        }
    }
    string nuevoTitulo;
    cout << "No se encontró el video. Ingrese otro título: ";
    cin >> nuevoTitulo;
    Video *video = videoPorTitulo(nuevoTitulo);
    return video;
}

/* calificar videos */
void calificarVideo(){
    string titulo;
    cout << "Ingresa el titulo a calificar: ";
    cin >> titulo;
    Video *video = videoPorTitulo(titulo);

    int puntaje;
    cout << "Ingresa el puntaje de este video: ";
    video->setPuntaje(validarNum(1,5));

    cout << "Así quedó el video: \n";
    video->mostrar();
}


int menu(){
    cout << "Menu principal\n";
    cout << " Ingrese la opción deseada\n";
    cout << " 1. Cargar archivo de datos\n";
    cout << " 2. Mostrar los videos en general con una cierta calificación o de un cierto género\n";
    cout << " 3. Mostrar los episodios de una determinada serie con una calificación determinada\n";
    cout << " 4. Mostrar las películas con cierta calificación\n";
    cout << " 5. Calificar un video\n";
    cout << " 0. Salir\n";
    int answer = validarNum(0,5);
    return answer;
}

int main(){
    int answer = menu();
    bool isLoaded = false;
    while (answer != 0){
        switch (answer){
            case 1:
                //Cargar archivo de datos
                isLoaded = true;
                cargarDatos();
                break;
            case 2:
                ///videos con cierta calificacion o generp
                if(isLoaded){
                    mostrarVideos();
                } else{
                    cout << "Debe cargar los datos primero. Presione 1.\n";
                }
                break;
            case 3:
                //episodios de serie con calificacion determinada
                if(isLoaded){
                    mostrarEpisodios();
                } else{
                    cout << "Debe cargar los datos primero. Presione 1.\n";
                }
                break;
            case 4:
                //peliculas con calificacion determinada
                if(isLoaded){
                    mostrarPeliculas();
                } else{
                    cout << "Debe cargar los datos primero. Presione 1.\n";
                }
                break;
            case 5:
                //Calificar video
                if(isLoaded){
                    calificarVideo();
                } else{
                    cout << "Debe cargar los datos primero. Presione 1.\n";
                }
                break;
            case 0:
                break;
            default:
                cout << "Ingrese un número válido!\n";
                break;
        }
        answer = menu();
    }
    return 0;
}
