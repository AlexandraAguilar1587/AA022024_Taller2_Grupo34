#include "./lista_salarios.h"    
#include <iostream>

using namespace std;

void intercambiar(int* primerElemento, int* segundoElemento);         
void restaurarHeap(int* listaSalarios, int tamanio, int nodoActual);  
void ordenarHeap(int* listaSalarios, int tamanio);                   
void mostrarSalarios(int* listaSalarios, int tamanio);                

int main()                                                                                  
{
    try {                                                                                   
        system("cls");                                                                      
        ordenarHeap(listaSalarios, numSalarios);                                            
        cout << "<-- Listado de salarios ordenados de forma descendente -->\n" << endl;    
        mostrarSalarios(listaSalarios, numSalarios);                                        
        cout << "\n<-- Lista de salarios ha sido mostrada por completo -->\n" << endl;      
    } catch (const exception& e) {                                                          
        cout << "Ha ocurrido un error: " << e.what() << endl;                               
    }
    return 0;                                                                               
}

// Ordenamos la lista de salarios en orden descendente
void ordenarHeap(int* listaSalarios, int tamanio) {
    int i = tamanio / 2 - 1;
    while (i >= 0) {
        restaurarHeap(listaSalarios, tamanio, i);
        i--;
    }
    int j = tamanio - 1;
    while (j > 0) {
        intercambiar(listaSalarios, listaSalarios + j);
        restaurarHeap(listaSalarios, j, 0);
        j--;
    }
}

// Intercambiamos los valores utilizando punteros
void intercambiar(int* primerElemento, int* segundoElemento) {
    int aux = *primerElemento;
    *primerElemento = *segundoElemento;
    *segundoElemento = aux;
}

// Aseguramos que el subarbol con la raiz en el nodoActual cumpla las propiedades de heap.
void restaurarHeap(int* listaSalarios, int tamanio, int nodoActual) {
    int aux = listaSalarios[nodoActual];
    int hijoIzquierdo = 2 * nodoActual + 1;

    while (hijoIzquierdo < tamanio) {
        int hijoDerecho = hijoIzquierdo + 1;
        int hijoMayor = hijoIzquierdo;

        if (hijoDerecho < tamanio) {
            if (listaSalarios[hijoDerecho] > listaSalarios[hijoIzquierdo])
            {
                hijoMayor = hijoDerecho;
            }
        }

        if (listaSalarios[hijoMayor] > aux) {
            listaSalarios[nodoActual] = listaSalarios[hijoMayor];
            nodoActual = hijoMayor;
            hijoIzquierdo = 2 * nodoActual + 1;
        } else {
            break;
        }
    }
    
    listaSalarios[nodoActual] = aux;
}


// Mostramos la lista ordenada en la consola 
void mostrarSalarios(int* listaSalarios, int tamanio) {
    for (int i = tamanio - 1; i >= 0; i--) {
        cout << (tamanio - i) << " - " << *(listaSalarios + i) << endl;
    }
}
