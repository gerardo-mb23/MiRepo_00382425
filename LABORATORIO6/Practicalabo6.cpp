#include <iostream>
#include <string>
using namespace std;


struct Direccion {
    string calle;
    int numero;
    string ciudad;
};


struct Estudiante {
    string nombre;
    int edad;
    float calificaciones[5];
    Direccion direccion;
};


void ingresarEstudiantes(Estudiante* estudiantes, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "\n ***Ingrese los datos del estudiante " << i + 1 << "***\n";
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, estudiantes[i].nombre);

        cout << "Edad: ";
        cin >> estudiantes[i].edad;

        cout << "Ingrese las 5 calificaciones:\n";
        for (int j = 0; j < 5; j++) {
            cout << "Calificacion " << j + 1 << ": ";
            cin >> estudiantes[i].calificaciones[j];
        }

        cout << "Direccion:\n";
        cout << "  Calle: ";
        cin.ignore();
        getline(cin, estudiantes[i].direccion.calle);
        cout << "  Numero de casa: ";
        cin >> estudiantes[i].direccion.numero;
        cout << "  Ciudad: ";
        cin.ignore();
        getline(cin, estudiantes[i].direccion.ciudad);
    }
}


void mostrarEstudiantes(Estudiante* estudiantes, int cantidad) {
    cout << "\n*** Lista de estudiantes ***\n";
    for (int i = 0; i < cantidad; i++) {
        cout << "\nEstudiante " << i + 1 << ":\n";
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        cout << "Edad: " << estudiantes[i].edad << endl;
        cout << "Calificaciones: ";
        for (int j = 0; j < 5; j++) {
            cout << estudiantes[i].calificaciones[j] << " ";
        }
        cout << "\nDireccion: " << estudiantes[i].direccion.calle << " "
             << estudiantes[i].direccion.numero << ", "
             << estudiantes[i].direccion.ciudad << endl;
    }
}


void buscarEstudiante(Estudiante* estudiantes, int cantidad) {
    string nombreBuscado;
    bool encontrado = false;
    cout << "\nIngrese el nombre del estudiante a buscar: ";
    cin.ignore();
    getline(cin, nombreBuscado);

    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].nombre == nombreBuscado) {
            cout << "\nEstudiante encontrado:\n";
            cout << "Nombre: " << estudiantes[i].nombre << endl;
            cout << "Edad: " << estudiantes[i].edad << endl;
            cout << "Calificaciones: ";
            for (int j = 0; j < 5; j++) {
                cout << estudiantes[i].calificaciones[j] << " ";
            }
            cout << "\nDireccion: " << estudiantes[i].direccion.calle << " "
                 << estudiantes[i].direccion.numero << ", "
                 << estudiantes[i].direccion.ciudad << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro ningun estudiante con ese nombre.\n";
    }
}


void modificarEstudiante(Estudiante* estudiantes, int cantidad) {
    string nombreBuscado;
    bool encontrado = false;
    cout << "\nIngrese el nombre del estudiante a modificar: ";
    cin.ignore();
    getline(cin, nombreBuscado);

    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].nombre == nombreBuscado) {
            cout << "\nModificando los datos de " << estudiantes[i].nombre << endl;
            cout << "Nueva edad: ";
            cin >> estudiantes[i].edad;

            cout << "Nuevas calificaciones:\n";
            for (int j = 0; j < 5; j++) {
                cout << "Calificacion " << j + 1 << ": ";
                cin >> estudiantes[i].calificaciones[j];
            }

            cout << "Nueva direccion:\n";
            cout << "  Calle: ";
            cin.ignore();
            getline(cin, estudiantes[i].direccion.calle);
            cout << "  Numero de casa: ";
            cin >> estudiantes[i].direccion.numero;
            cout << "  Ciudad: ";
            cin.ignore();
            getline(cin, estudiantes[i].direccion.ciudad);

            encontrado = true;
            cout << "Datos actualizados correctamente.\n";
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro ningun estudiante con ese nombre.\n";
    }
}

int main() {
    int opcion;
    int cantidad = 0;
    Estudiante* estudiantes = nullptr; 

    do {
        cout << "\n*** MENU ***\n";
        cout << "1. Ingresar estudiantes\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Buscar estudiante\n";
        cout << "4. Modificar estudiante\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese la cantidad de estudiantes: ";
            cin >> cantidad;
            estudiantes = new Estudiante[cantidad];
            ingresarEstudiantes(estudiantes, cantidad);
            break;
        case 2:
            if (estudiantes != nullptr)
                mostrarEstudiantes(estudiantes, cantidad);
            else
                cout << "No hay estudiantes registrados.\n";
            break;
        case 3:
            if (estudiantes != nullptr)
                buscarEstudiante(estudiantes, cantidad);
            else
                cout << "No hay estudiantes registrados.\n";
            break;
        case 4:
            if (estudiantes != nullptr)
                modificarEstudiante(estudiantes, cantidad);
            else
                cout << "No hay estudiantes registrados.\n";
            break;
        case 5:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion no valida.\n";
        }

    } while (opcion != 5);

    delete[] estudiantes;
    return 0;
}
