#include <iostream>
#include <vector>
#include "Juego.h"

using namespace std;

int main() {
    // Crear algunos objetos de Juego
    Juego<int> juego1("TBOI", 2016, 8, 50, true);
    Juego<int> juego2("Minecraft", 2010, 7, 40, false);
    Juego<int> juego3("BG3", 2023, 9, 60, true);

    // Almacenarlos en un vector
    std::vector<Juego<int>> juegos = {juego1, juego2, juego3};

    // Crear una instancia de la clase Bubble
    Bubble<Juego<int>> ordenador;

    // Pedir al usuario el metodo de ordenamiento
    std::cout << "Elija por que variable ordenar (1: Fecha de Lanzamiento, 2: Calificacion, 3: Precio, 4: Nombre): ";
    int eleccion;
    std::cin >> eleccion;

    switch (eleccion) {
        case 1:
            // Ordenar por fecha de lanzamiento (de menor a mayor)
            juegos = ordenador.ordenarLanzamiento(juegos);
            break;
        case 2:
            // Ordenar por calificacion (de menor a mayor)
            juegos = ordenador.ordenarCalificacion(juegos);
            break;
        case 3:
            // Ordenar por precio (de menor a mayor)
            juegos = ordenador.ordenarPrecio(juegos);
            break;
        case 4:
            // Ordenar por nombre (en orden alfabetico)
            juegos = ordenador.ordenarNombre(juegos);
            break;
        default:
            std::cout << "Eleccion no valida. Se ordenara por fecha de lanzamiento por defecto utilizando el metodo de burbuja." << std::endl;
            juegos = ordenador.ordenarLanzamiento(juegos);
    }

    // Imprimir los juegos ordenados
    for (Juego<int>& juego : juegos) {
        std::cout << "Nombre: " << juego.obtener_nombre();
        std::cout << ", Fecha de Lanzamiento: " << juego.obtener_lanzamiento();
        std::cout << ", Calificacion: " << juego.obtener_calificacion();
        std::cout << ", Precio: " << juego.obtener_precio() << std::endl;
    }

    return 0;
}
