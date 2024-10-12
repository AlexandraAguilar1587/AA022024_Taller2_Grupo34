#include "./lista_salarios.h"    
#include <iostream>

using namespace std;

void intercambiarValores(int* primerElemento, int* segundoElemento);
void heapificar(int* listaSalarios, int tamanio, int nodoActual);
void heapSort(int* listaSalarios, int tamanio);
void mostrarSalarios(int* listaSalarios, int tamanio);

int main() 
{
    try {
        // Limpiamos la consola
        system("cls");
        heapSort(listaSalarios, numSalarios);
        cout << "<-- Listado de salarios ordenados de forma descendente -->\n" << endl;
        mostrarSalarios(listaSalarios, numSalarios);
        cout << "\n<-- Lista de salarios ha sido mostrada por completo -->\n" << endl;
    } catch (const exception& e) {
        cout << "Ha ocurrido un error: " << e.what() << endl;
    }
    return 0;
}

// Ordenamos la lista de salarios en orden descendente
void heapSort(int* listaSalarios, int tamanio) {
    int i = tamanio / 2 - 1;
    while (i >= 0) {
        heapificar(listaSalarios, tamanio, i);
        i--;
    }
    int j = tamanio - 1;
    while (j > 0) {
        intercambiarValores(listaSalarios, listaSalarios + j);
        heapificar(listaSalarios, j, 0);
        j--;
    }
}

// Intercambiamos los valores utilizando punteros
void intercambiarValores(int* primerElemento, int* segundoElemento) {
    int temp = *primerElemento;
    *primerElemento = *segundoElemento;
    *segundoElemento = temp;
}

// Aseguramos que el subarbol con la raiz en el nodoActual cumpla Max-Heap.
void heapificar(int* listaSalarios, int tamanio, int nodoActual) {
    int* nodoMayor = listaSalarios + nodoActual;  
    int* hijoIzquierdo = listaSalarios + 2 * nodoActual + 1;  
    int* hijoDerecho = listaSalarios + 2 * nodoActual + 2;  

    if (2 * nodoActual + 1 < tamanio) {
        if (*hijoIzquierdo > *nodoMayor) {
            nodoMayor = hijoIzquierdo;
        }
    }

    if (2 * nodoActual + 2 < tamanio) {
        if (*hijoDerecho > *nodoMayor) {
            nodoMayor = hijoDerecho;
        }
    }

    if (nodoMayor != listaSalarios + nodoActual) {
        intercambiarValores(listaSalarios + nodoActual, nodoMayor);
        heapificar(listaSalarios, tamanio, nodoMayor - listaSalarios);
    }
}

// Mostramos la lista ordenada en la consola 
void mostrarSalarios(int* listaSalarios, int tamanio) {
    for (int i = tamanio - 1; i >= 0; i--) {
        cout << (tamanio - i) << " - " << *(listaSalarios + i) << endl;
    }
}
