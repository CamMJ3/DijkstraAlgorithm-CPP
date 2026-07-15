#pragma once
#include <vector>
#include <limits>

using namespace std;

/** 
 * @file 
 * @brief Se define la estructura de un grafo pesado para la implementación del algoritmo de Dijkstra.
 * @author Camila Andrea Jaimes Martínez.
 * 
 * @details Utilizando una matriz de adyacencia para representar el grafo, la plantilla de clase Grafo
 * permite trabajar con diferentes tipos de peso, sean enteros o decimales. A partir de los vertices, el
 * algoritmo de Dijkstra se especializa en calcular la distancia mínima desde un vértice "inicio a los
 * demás vértices del grafo.
 */


template <typename T>
class Grafo 
{
    private:
        int vertices; ///< Número de vértices en el grafo.
        vector<vector<T>> matriz_adj; ///< Matriz de adyacencia que permite registrar los pesos de las aristas entre los vértices.

        int distanciaMin(vector<T>& dist, vector<bool>& visitado); ///< Encuentra el vértice, no visitado, con la distancia mínima desde el vértice de inicio.
    public:
        Grafo(int v); ///< Inicializa un grafo de n vértices con una matriz de adyacencia, por lo tanto, vacía.

        void agregarArista(int inicio, int destino, T peso, bool dirigido); ///< Inserta una arista ponderada que conecta a dos vértices del grafo.
        void dijkstra(int inicio); ///< Implementa el algoritmo de Dijkstra para calcular la distancia mínima desde un vértice de origen a todos los demás vértices del grafo.
};

#include "../src/dijkstra.cpp"