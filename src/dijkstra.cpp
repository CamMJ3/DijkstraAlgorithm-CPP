#include <iostream>
#include "dijkstra.h"

/** 
 * @file 
 * @brief Implementación de de los constructores y métodos de la plantilla Grafo.
 */

using namespace std;

/***********************************************************************/

/** 
 * @brief Inicializa un grafo de n vértices con una matriz de adyacencia, por lo tanto, vacía.
 * @details A partir del número de vértices, se re-dimensiona un grafo del mismo tamaño cuya matriz de adyacencia
 * (matriz_adj) empieza en ceros, lo cual indica que no hay aristas existentes entre los vertices.
 * @param v Número de vértices del grafo.
 */

template <typename T>
Grafo<T>::Grafo(int v)
{
    vertices = v;
    matriz_adj.resize(vertices, vector<T>(vertices, 0));
}

/***********************************************************************/

/** 
 * @brief Encuentra el vértice, no visitado, con la distancia mínima desde el vértice de inicio.
 * @details Haciendo uso del vector "dist" (distancias) y el vector "visitado" (vértices visitados),
 * se recorre el vector de distancias para encontrar el vértices con la distancia mínima, siempre y
 * cuando no haya sido visitado anteriormente.
 * @param dist Vector de la distancia obtenida desde el vértice de inicio.  
 * @param visitado Vector de vertices ya visitados.
 */

template <typename T>
int Grafo<T>::distanciaMin(vector<T>& dist, vector<bool>& visitado)
{
    T min = numeric_limits<T>::max();
    int indice_min = -1;

    for (int i = 0; i < vertices; i++)
    {
        if (!visitado[i] && dist[i] < min)
        {
            min = dist[i];
            indice_min = i;
        }
    }

    return indice_min;
}

/***********************************************************************/

/** 
 * @brief Inserta una arista ponderada que conecta a dos vértices del grafo.
 * @details Se le asigna el peso de la arista a su posición respectiva en la matriz de 
 * adyacencia. Dado el caso que el grafo sea no dirigido, se asigna el mismo peso a la posición simétrica de la matriz de adyacencia.
 * @param inicio Vértice de inicio.
 * @param destino Vértice de destino.
 * @param peso Peso de la arista.
 * @param dirigido Indica si es un grafo dirigido o no.
 */

template <typename T>
void Grafo<T>::agregarArista(int inicio, int destino, T peso, bool dirigido)
{
    matriz_adj[inicio][destino] = peso;
    if (!dirigido)
    {
        matriz_adj[destino][inicio] = peso;
    }
}


/***********************************************************************/

/** 
 * @brief Implementa el algoritmo de Dijkstra para calcular la distancia mínima desde un vértice de origen a todos los demás vértices del grafo.
 * @details Primero, se inicializa un vector de distancias con el valor máximo para el tipo de dato T, además de un vector de visitados en "false"
 * para indicar que no han sido visitados. La distancia del vértice de inicio consigo mismo es de 0.
 * 
 * Se itera sobre los vértices del grafo, encontrado el vértice no visitado con la distancia mínima acumulada, marcándolo como visitado y
 * actualizando las distancias de sus vértices adyacentes. Si se encuentra un camino más corto a través del vértice actual, se actualiza la
 * distancia en el vector de distancias.
 * @param inicio Vértice de origen.
 */

template <typename T>
void Grafo<T>::dijkstra(int inicio)
{
    vector<T> dist(vertices, numeric_limits<T>::max());
    vector<bool> visitado(vertices, false);

    dist[inicio] = 0;

    for (int i = 0; i < vertices - 1; i++)
    {
        int u = distanciaMin(dist, visitado);
        
        if (u == -1)
        {
            break; ///< No hay vértices alcanzables.
        }

        visitado[u] = true;

        for (int v = 0; v < vertices; v++)
        {
            if (!visitado[v] && matriz_adj[u][v] != 0 && dist[u] != numeric_limits<T>::max() && dist[u] + matriz_adj[u][v] < dist[v])
            {
                dist[v] = dist[u] + matriz_adj[u][v];
            }
        }
    }

    cout << "-_-_-_-_- Distancias desde el vértice " << inicio << " -_-_-_-_-\n\n"; 
    for (int i = 0; i < vertices; i++)
    {
        cout << "--> Para llegar al vertice " << i << " : " << dist[i] << endl;
    }
}