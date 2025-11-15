#include <iostream>
#include <fstream>

using namespace std;

int contarNumeros(const char* nombre) {
    ifstream f(nombre);
    if (!f.is_open()) return 0;
    int x, contador = 0;
    while (f >> x) contador++;
    f.close();
    return contador;
}

int* leerArchivo(const char* nombre, int &n) {
    n = contarNumeros(nombre);
    if (n == 0) return nullptr;
    ifstream f(nombre);
    if (!f.is_open()) { n = 0; return nullptr; }

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        f >> arr[i];
    }
    f.close();
    return arr;
}

void escribirArchivo(const char* nombre, int* arr, int n) {
    ofstream f(nombre);
    for (int i = 0; i < n; i++) {
        f << arr[i];
        if (i < n) f << endl;
    }
    f.close();
}


void mostrarArchivo(const char* nombre) {
    ifstream f(nombre);
    if (!f.is_open()) {
        cout << nombre << " (archivo no encontrado o vacio)" << endl;
        return;
    }
    int x;
    cout << "Contenido de " << nombre << ":" << endl;
    bool any = false;
    while (f >> x) {
        cout << x << " ";
        any = true;
    }
    if (!any) cout << "(vacio)";
    cout << endl << endl;
    f.close();
}

void ordenarArchivo(int* arr, int n) {
    if (arr == nullptr || n <= 1) return;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void clasificarNumeros(const char* origen, const char* paresFile, const char* imparesFile) {
    ifstream f(origen);
    if (!f.is_open()) {
        cout << "No se pudo abrir " << origen << ". Asegurarse de que el archivo exista y que tenga numeros." << endl;
        return;
    }
    ofstream pares(paresFile), impares(imparesFile);
    int x;
    while (f >> x) {
        if (x % 2 == 0) pares << x << endl;
        else impares << x << endl;
    }
    f.close();
    pares.close();
    impares.close();
}

int main() {
    const char* origen = "datos.txt";
    const char* paresFile = "pares.txt";
    const char* imparesFile = "impares.txt";

    if (contarNumeros(origen) == 0) {
        cout << "No se encontró datos.txt o está vacío. Creando un ejemplo datos.txt con numeros de prueba." << endl;
        ofstream ejemplo(origen);
        ejemplo << 10 << endl << 3 << endl << 7 << endl << 4 << endl << 18 << endl << 5 << endl;
        ejemplo.close();
    }

    clasificarNumeros(origen, paresFile, imparesFile);

    cout << "--- Antes del ordenamiento ---" << endl;
    mostrarArchivo(paresFile);
    mostrarArchivo(imparesFile);

    int nPares = 0;
    int* arrPares = leerArchivo(paresFile, nPares);
    if (arrPares != nullptr && nPares > 0) {
        ordenarArchivo(arrPares, nPares);
        escribirArchivo(paresFile, arrPares, nPares);
        delete[] arrPares;
    }

    int nImpares = 0;
    int* arrImpares = leerArchivo(imparesFile, nImpares);
    if (arrImpares != nullptr && nImpares > 0) {
        ordenarArchivo(arrImpares, nImpares);
        escribirArchivo(imparesFile, arrImpares, nImpares);
        delete[] arrImpares;
    }

    cout << "--- Despues del ordenamiento ---" << endl;
    mostrarArchivo(paresFile);
    mostrarArchivo(imparesFile);

    cout << "Proceso completado." << endl;
    return 0;
}
