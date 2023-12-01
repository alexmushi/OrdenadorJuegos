#include "Juego.h"

int main() {
    ListaJuegos juegos;
    int opcion;

    do {
        cout << "\n--- Menu de Opciones ---\n";
        cout << "1. Mostrar todos los juegos\n";
        cout << "2. Ordenar juegos\n";
        cout << "3. Agregar un nuevo juego\n";
        cout << "4. Buscar un juego\n";
        cout << "5. Guardar como archivo .csv\n";
        cout << "6. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << juegos.toString_juegos(1);
        } else if (opcion == 2) {
            int sortChoice;
            cout << "Selecciona una opcion de ordenamiento (1-4): ";
            cout << "\n1 - Nombre ";
            cout << "\n2 - Reviews ";
            cout << "\n3 - Precio ";
            cout << "\n4 - Fecha de lanzamiento \n";
            cin >> sortChoice;
            if (sortChoice == 1) {
                juegos.bubble_texto(sortChoice);
            } else if (sortChoice == 2 || sortChoice == 3 || sortChoice == 4) {
                juegos.bubble_num(sortChoice);
            }
            cout << "Juegos ordenados. Para verlos, elige la opcion 1";
        } else if (opcion == 3) {
            juegos.agrega_juego();
        } else if (opcion == 4) {
            int respuestaBusqueda;
            cout << "Selecciona una opcion de busqueda (1-4): ";
            cout << "\n1 - Nombre ";
            cout << "\n2 - Reviews ";
            cout << "\n3 - Precio ";
            cout << "\n4 - Fecha de lanzamiento \n";
            cin >> respuestaBusqueda;
            if (respuestaBusqueda == 1){
                cout << "Respetar las mayusculas. El primer caracter siempre es mayuscula.";
            };
            cout << "Ingresa el valor a buscar: ";
            string valor;
            cin >> valor;
            cout << juegos.menu_busqueda(respuestaBusqueda, valor);
        } else if (opcion == 5) {
            cout << "Generando .csv con los juegos agregados y ordenados hasta el momento...";
            juegos.generar_archivo();
            cout << "Archivo guardado como juegos.csv";
        } else if (opcion == 6) {
            cout << "Saliendo del programa. ¡Hasta luego!\n";
        } else {
            cout << "Opcion no valida. Intentalo de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}
