#ifndef JUEGO_H
#define JUEGO_H

#include <list>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Clase con el juego y sus atributos
class Juego {
private:
    string nombre;
    int calif;
    int precio;
    int fecha;

public:
    Juego() : nombre(""), calif(0), precio(0), fecha(0){};
    Juego(string nom, int calif, int prec, int fech) : nombre(nom), calif(calif), precio(prec), fecha(fech){};
    string getNombre() { return nombre; }
    int getCalif() { return calif; }
    int getPrecio() { return precio; }
    int getFecha() { return fecha; }
};

// Clase que gestiona una lista de juegos
class ListaJuegos {
private:
    list<Juego> juegos;

    void swap(list<Juego>::iterator i, list<Juego>::iterator j);
    void leer_archivo(string filename);
    string formato_juego(list<Juego>::iterator &p, int i);

public:
    ListaJuegos(); // Constructor
    void agrega_juego();
    void generar_archivo();
    int letra_numero(list<Juego>::iterator &apuntador, int tipo_variable, int letra);
    void bubble_texto(int tipo_variable);
    void bubble_num(int tipo_variable);
    string toString_juegos(int asc_desc);
    string toString_elemento(list<Juego>::iterator &apuntador, int count);
    string menu_busqueda(int busq_respuesta, string value);
    bool busqueda(list<Juego>::iterator &apuntador, int busq_respuesta, string value);
    string busqueda(string value, int busq_respuesta, list<Juego>::iterator &apuntador);
    string toString_atributo(int atributo_num);
};

// Se inicializa leyendo el csv
ListaJuegos::ListaJuegos() {
    leer_archivo("ListaJuegos.csv");
}

// El usuario agrega un nuevo juego a la lista
void ListaJuegos::agrega_juego() {
    string nom;
    int calif, prec, fech;

    cout << "\nPor favor escribe el nombre del juego (si contiene espacios, no ponerlos): ";
    getline(cin.ignore(60, '\n'), nom);
    // La primera letra se hace mayúscula para facilitar el sort alfabetico
    if (!nom.empty()) {
        nom[0] = toupper(nom[0]);
    }

    cout << "\nPor favor escribe la calificación sobre 100 (sin decimales): ";
    cin >> calif;

    cout << "\nPor favor escribe el precio en pesos (sin decimales): ";
    cin >> prec;

    cout << "\nPor favor escribe el ano de lanzamiento: ";
    cin >> fech;

    juegos.push_back(Juego(nom, calif, prec, fech));
}

// Metodo para intercambiar dos elementoos en la lista
void ListaJuegos::swap(list<Juego>::iterator elem_1, list<Juego>::iterator elem_2) {
    Juego aux = *elem_1;
    *elem_1 = *elem_2;
    *elem_2 = aux;
}

// Método que devuelve el valor de un carácter o número en una posición específica
int ListaJuegos::letra_numero(list<Juego>::iterator &apuntador, int tipo_variable, int letra) {
    if (tipo_variable == 1) {
        return apuntador->getNombre()[letra];
    } else if (tipo_variable == 2) {
        return apuntador->getCalif();
    } else if (tipo_variable == 3) {
        return apuntador->getPrecio();
    } else if (tipo_variable == 4) {
        return apuntador->getFecha();
    }

    return 0;
}

// Algoritmo Bubble Sort para variables de tipo texto
void ListaJuegos::bubble_texto(int tipo_variable) {
    int n = juegos.size();
    list<Juego>::iterator i, j;

    for (i = juegos.begin(); i != juegos.end(); ++i) {
        for (j = juegos.begin(); j != juegos.end(); ++j) {
            int count_letra = 0;
            while (letra_numero(i, tipo_variable, count_letra) == letra_numero(j, tipo_variable, count_letra) && i != j) {
                count_letra++;
            }

            if (letra_numero(i, tipo_variable, count_letra) < letra_numero(j, tipo_variable, count_letra)) {
                swap(i, j);
            }
        }
    }
}

// Algoritmo Bubble Sort para variables numericas
void ListaJuegos::bubble_num(int tipo_variable) {
    int n = juegos.size();
    list<Juego>::iterator i, j;

    for (i = juegos.begin(); i != juegos.end(); ++i) {
        for (j = juegos.begin(); j != juegos.end(); ++j) {
            if (letra_numero(i, tipo_variable, 3) < letra_numero(j, tipo_variable, 3)) {
                swap(i, j);
            }
        }
    }
}

// Método para convertir la lista de juegos a una cadena de texto
string ListaJuegos::toString_juegos(int asc_desc) {
    stringstream aux;

    if (asc_desc == 1) {
        list<Juego>::iterator p = juegos.begin();
        int i = 1;

        while (p != juegos.end()) {
            aux << formato_juego(p, i);
            p++;
            i++;
        }
    } else if (asc_desc == 2) {
        list<Juego>::iterator p = juegos.end();
        p--;

        int i = 1;
        while (i <= juegos.size()) {
            aux << formato_juego(p, i);
            p++;
            i++;
        }
    }

    return aux.str();
}

// Método para convertir un elementoo de la lista a una cadena de texto
string ListaJuegos::toString_elemento(list<Juego>::iterator &apuntador, int count) {
    return formato_juego(apuntador, count);
}

// Método para formatear un juego a una cadena de texto
string ListaJuegos::formato_juego(list<Juego>::iterator &p, int i) {
    stringstream aux;

    aux << "\nJuego #" << i << endl;
    aux << "Nombre: " << p->getNombre() << endl;
    aux << p->getCalif() << " % de los usuarios dejaron un review positivo" << endl;
    aux << "Precio: " << p->getPrecio() << endl;
    aux << "Lanzamiento: " << p->getFecha() << endl;

    return aux.str();
}

// Método para convertir un atributo específico de la lista a una cadena de texto
string ListaJuegos::toString_atributo(int atributo_num) {
    stringstream aux;

    list<Juego>::iterator p = juegos.begin();
    list<Juego>::iterator end = juegos.end();
    end--;

    aux << "[";

    while (p != juegos.end()) {
        if (atributo_num == 1)
            aux << p->getNombre();
        else
            aux << letra_numero(p, atributo_num, 0);
        if (p != end) {
            aux << ", ";
        }
        p++;
    }

    aux << "]";

    return aux.str();
}

// Método para buscar un elemento en la lista según la opción seleccionada
string ListaJuegos::menu_busqueda(int busq_respuesta, string value) {
    stringstream aux;

    list<Juego>::iterator first = juegos.begin();
    list<Juego>::iterator last = juegos.end();
    last--;

    if (busq_respuesta == 1) {
        char first_char = 'A';
        char last_char = 'Z';
        int size = (first_char + last_char) / 2;

        if (value[0] <= size) {
            aux << busqueda(value, busq_respuesta, first);
        } else if (value[0] > size) {
            aux << busqueda(value, busq_respuesta, last);
        }
    } else if (busq_respuesta == 2 || busq_respuesta == 3 || busq_respuesta == 4) {
        int value_num;

        int first_num = letra_numero(first, busq_respuesta, 0);
        int last_num = letra_numero(last, busq_respuesta, 0);

        int size = (first_num + last_num) / 2;

        if (value_num <= size) {
            aux << busqueda(value, busq_respuesta, first);
        } else if (value_num > size) {
            aux << busqueda(value, busq_respuesta, last);
        }
    }

    return aux.str();
}

// Método para buscar un elementoo en la lista
bool ListaJuegos::busqueda(list<Juego>::iterator &apuntador, int busq_respuesta, string value) {
    if (busq_respuesta == 1) {
        if (apuntador->getNombre() == value)
            return true;
    } else if (busq_respuesta == 2) {
        int value_num = stoi(value);
        if (apuntador->getCalif() == value_num)
            return true;
    } else if (busq_respuesta == 3) {
        int value_num = stoi(value);
        if (apuntador->getPrecio() == value_num)
            return true;
    } else if (busq_respuesta == 4) {
        int value_num = stoi(value);
        if (apuntador->getFecha() == value_num)
            return true;
    }
    return false;
}

// Método para buscar un elementoo en la lista y convertir a cadena
string ListaJuegos::busqueda(string value, int busq_respuesta, list<Juego>::iterator &p) {
    stringstream aux;

    bool found = false;

    if (p == juegos.begin()) {
        int count = 1;
        while (p != juegos.end()) {
            if (busqueda(p, busq_respuesta, value) == true) {
                aux << "¡elementoo encontrado!" << endl;
                aux << formato_juego(p, count);
                found = true;
            }
            p++;
            count++;
        }
    } else {
        int count = juegos.size();
        while (count != 0) {
            if (busqueda(p, busq_respuesta, value) == true) {
                aux << formato_juego(p, count);
                found = true;
            }
            p--;
            count--;
        }
    }

    if (found == false) {
        aux << endl << "No existe el elementoo" << endl;
    }
    return aux.str();
}

// Método para leer juegos desde un archivo
void ListaJuegos::leer_archivo(string filename) {
    ifstream archivo;
    archivo.open(filename);

    string line;

    while (getline(archivo, line)) {
        int count = 0;
        string nom;
        int calif, prec, fech;

        stringstream ss(line);

        while (ss.good()) {
            string elemento;
            getline(ss, elemento, ',');

            if (count == 0)
                nom = elemento;
            else if (count == 1)
                calif = stoi(elemento);
            else if (count == 2)
                prec = stoi(elemento);
            else if (count == 3)
                fech = stoi(elemento);

            count++;
        }

        juegos.push_back(Juego(nom, calif, prec, fech));
    }

    archivo.close();
}

// Método para guardar la lista de juegos en un archivo CSV
void ListaJuegos::generar_archivo() {
    ofstream archivo("juegos.csv");
    list<Juego>::iterator p = juegos.begin();

    archivo << "Nombre, Calif, Precio, Fecha" << endl;
    while (p != juegos.end()) {
        archivo << p->getNombre() << ", ";
        archivo << p->getCalif() << ", ";
        archivo << p->getPrecio() << ", ";
        archivo << p->getFecha() << endl;
        p++;
    }

    archivo.close();
}

#endif
