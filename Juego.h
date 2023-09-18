#ifndef JUEGOS_H
#define JUEGOS_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class Juego {
private:
    std::string nombre;
    int fechaLanzamiento;
    int calificacion;
    int precio;
    bool descargado;

public:
    Juego(std::string nombre, int lanzamiento, int calificacion, int precio, bool descargado)
        : nombre(nombre), fechaLanzamiento(lanzamiento), calificacion(calificacion), precio(precio), descargado(descargado) {}

    std::string obtener_nombre() {
        return nombre;
    }

    int obtener_lanzamiento() {
        return fechaLanzamiento;
    }

    int obtener_calificacion() {
        return calificacion;
    }

    int obtener_precio() {
        return precio;
    }

    bool obtener_descargado() {
        return descargado;
    }
};

template <class T>
class Bubble {
public:

    // Swap
    void intercambiar(std::vector<T>& v, int i, int j) {
        T temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }

    std::vector<T> ordenarLanzamiento(std::vector<T>& origen) {
        std::vector<T> v(origen);

        for (int i = v.size() - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (v[j].obtener_lanzamiento() > v[j + 1].obtener_lanzamiento()) {
                    intercambiar(v, j, j + 1);
                }
            }
        }
        return v;
    }

    std::vector<T> ordenarCalificacion(std::vector<T>& origen) {
        std::vector<T> v(origen);

        for (int i = v.size() - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (v[j].obtener_calificacion() > v[j + 1].obtener_calificacion()) {
                    intercambiar(v, j, j + 1);
                }
            }
        }
        return v;
    }

    std::vector<T> ordenarPrecio(std::vector<T>& origen) {
        std::vector<T> v(origen);

        for (int i = v.size() - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (v[j].obtener_precio() > v[j + 1].obtener_precio()) {
                    intercambiar(v, j, j + 1);
                }
            }
        }
        return v;
    }

    std::vector<T> ordenarNombre(std::vector<T>& origen) {
        std::vector<T> v(origen);

        for (int i = v.size() - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (v[j].obtener_nombre() > v[j + 1].obtener_nombre()) {
                    intercambiar(v, j, j + 1);
                }
            }
        }
        return v;
    }
};


#endif
