#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

int* leerSalarios(string& archivo, int& numSalarios);
void heapify(int* arreglo, int tamanio, int i);
void heapSort(int* arreglo, int tamanio);
void guardarSalariosOrdenados(int* salarios, int tamanio, string& archivo);

int main() {
    int numSalarios = 0;
    string ficheroEntrada = "lista_salarios.txt";
    string ficheroSalida = "salarios_ordenados.txt";

    try {
        int* salarios = leerSalarios(ficheroEntrada, numSalarios);
        if (salarios == nullptr) {
            throw runtime_error("Error al leer los salarios desde el archivo.");
        }

        heapSort(salarios, numSalarios);
        guardarSalariosOrdenados(salarios, numSalarios, ficheroSalida);

        delete[] salarios;
        cout << "Fichero con salarios ordenados generado!!!";

    } catch (const exception& e) {
        cerr << "Se ha producido un error: " << e.what() << endl;
    }

    return 0;
}

int* leerSalarios(string& archivo, int& numSalarios) {
    ifstream fichero(archivo);
    if (!fichero.is_open()) {
        throw runtime_error("No se pudo abrir el fichero: " + archivo);
    }

    numSalarios = 0;
    int salario;
    
    while (fichero >> salario) {
        numSalarios++;
    }

    fichero.clear();
    fichero.seekg(0);

    int* salarios = new int[numSalarios];
    for (int i = 0; i < numSalarios; i++) {
        fichero >> salarios[i];
    }

    fichero.close();
    return salarios;
}

void heapify(int* arreglo, int tamanio, int i) {
    int menor = i;
    int izquierdo = 2 * i + 1;
    int derecho = 2 * i + 2;

    if (izquierdo < tamanio && arreglo[izquierdo] < arreglo[menor])
        menor = izquierdo;

    if (derecho < tamanio && arreglo[derecho] < arreglo[menor])
        menor = derecho;

    if (menor != i) {
        swap(arreglo[i], arreglo[menor]);
        heapify(arreglo, tamanio, menor);
    }
}

void heapSort(int* arreglo, int tamanio) {
    for (int i = tamanio / 2 - 1; i >= 0; i--)
        heapify(arreglo, tamanio, i);

    for (int i = tamanio - 1; i > 0; i--) {
        swap(arreglo[0], arreglo[i]);
        heapify(arreglo, i, 0);
    }
}

void guardarSalariosOrdenados(int* salarios, int tamanio, string& archivo) {
    ofstream fichero(archivo);
    if (!fichero.is_open()) {
        throw runtime_error("Error al abrir el fichero -> " + archivo);
    }

    for (int i = 0; i < tamanio; i++) {
        fichero << salarios[i] << endl;
    }
    fichero.close();
}