#include <iostream> 
#include "dijkstra.h"

/** 
 * @file 
 * @brief El programa completo de la clase Grafo y el algoritmo de Dijkstra.
 *
 * @details Las opciones son las siguientes:
 * - 1) Crear un grafo con un número determinado de vértices.
 * - 2) Agregar aristar ponderadas, dirigidas o no, entre dos vértices del grafo.
 * - 3) Calcular y visualzar la distancia mínima desde un vértice de origen a todos los demás.
 * - 4) Salir del programa.
 */

int menu();

using namespace std;

int main()
{
    int n; ///< Número de vértices del grafo.
    Grafo<int>* grafo = nullptr; ///< Grafo con n vertices y pesos enteros.

    while (true)
	{
		switch (menu())
		{
        case 1:
        {
            cout << "\n¿De cuántos vértices desea crear el grafo?: ";
            cin >> n;

            if (grafo != nullptr)
            {
                delete grafo; ///< Elimina el grafo anterior si fue creado previamente.
            }

            grafo = new Grafo<int>(n);
            cout << "\n¡El grafo se ha creado exitosamente con " << n << " vértices!";
            break;
        }
		case 2:
        {
            if (grafo == nullptr)
            {
                cout << "\nNo se ha creado un grafo aún.";
                break;
            }

            int in, dest, p; ///< Vértice de inicio, de destino, y peso de la arista, respectivamente.
            bool direccion; ///< Indica si el grafo es dirigido o no.

            cout << "\nIngrese el vértice de inicio: ";
            cin >> in;

            cout << "\nIngrese el vértice de destino: ";
            cin >> dest;

            cout << "\nIngrese el peso de la arista: ";
            cin >> p;

            cout << "\n¿Es un grafo dirigido? (1 para sí, 0 para no): ";
            cin >> direccion;

            grafo->agregarArista(in, dest, p, direccion);
            cout << "\n¡La arista se ha creado exitosamente!";
			break;
        }
		case 3:
        {
            if (grafo == nullptr)
            {
                cout << "\nNo se ha creado un grafo aún.";
                break;
            }

            int origen; ///< Vértice de inicio para el algoritmo de Dijkstra.

            cout << "\n¿Cuál es el vértice de inicio? (Implementación del algoritmo de Dijkstra): ";
            cin >> origen;

            grafo->dijkstra(origen);
            break;
        }
        case 4:
        {
			cout << "\nSaliendo del programa...";
			exit(0);
			break;
        }
        }
    }

    delete grafo; ///< Libera la memoria del grafo antes de salir del programa.
}

/***********************************************************************/

/** 
 * @brief Menú del programa que maneja el input (aportación) del usuario.
 *
 * @details Devuelve una opción a la función main().
 */

int menu()
{
    int opcion;
	do
	{
		cout << "\n\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ ¡ MENÚ ! -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_";
        cout << "\n\n1) Crear un grafo de n vértices.\n";
		cout << "2) Agregar aristar ponderadas.\n";
		cout << "3) Calcular y visualzar la distancia mínima desde un vértice de origen a todos los demás.\n";
        cout << "4) Salir del programa.\n";
		cout << "\n--> Seleccione una opción: ";
		cin >> opcion;
	} while (opcion < 1 || opcion > 4);
	return opcion;
}

/***********************************************************************/

/** 
 * @page Análisis
 * @brief Análisis técnico y Justificación teórica del programa
 * 
 * @section Cuestiones
 * 
 * En este apartado se responden las siguientes cuestiones...
 * 
 * 1) Análisis de la complejidad algorítmica de su implementación (O(V2) o O(E log V)).
 * 
 * 2) Justificación teórica: ¿Por qué una búsqueda en anchura (BFS) estándar no es capaz
 * de encontrar la ruta más corta en un grafo donde las aristas tienen diferentes pesos? 
 * Explique cómo Dijkstra soluciona este problema.
 * 
 * @section algoritmo_dijkstra Análisis técnico
 * 
 * 1) La complejidad algorítmica de la implementación del algoritmo de Dijkstra, al utilizarse
 * una matriz de adyacencia, es de O(V^2). Su complejidad se debe a que, primero, en la función para determinar
 * la distancia mínima (distanciaMin), se recorren todos los vértices hasta encontrar el vértice no visitado
 * con la distancia mínima, lo cual lo categoriza como O(V).
 * 
 * Posteriormente, en la función correspondiente al algoritmo de Dijkstra (dijkstra), se itera nuevamente sobre
 * los vértices del grafo para actualizar las distancias de sus vértices adyacences y encontrar el vértice no visitado
 * con la distancia mínima, lo cual también lo categoriza como O(V).
 * 
 * Por lo tanto, ambas funciones en conjunto dan como resultado una complejida O(V) * O(V) = O(V^2).
 * 
 * @section bfs_dijkstra Justificación teórica
 * 
 * 2) Una búsqueda en anchura (BFS) estándar es un algoritmo que puede recorrer grafos no ponderados (cuyas aristas no tienen
 * costo o peso), encontrando el camino mas corto en cuestión de aristas. Logra su cometido utilizando una cola para acceder a
 * los vertices adyacentes desde un vértice de inicio, es decir, recorre el grafo por niveles.
 * 
 * Debido a lo anterior, si se aplicara el algoritmo de BFS en un grafo ponderado, no tomaría en cuenta los pesos
 * asignados a las aristas entre los vértices, haciéndolo susceptible a encontrar caminos más cortos en cuestión de aristas que
 * de pesos. 
 * 
 * Ante esta situación, el algoritmo de Dijkstra es la mejor opción para encontrar el camino más corto en un grafo
 * ponderado, sea dirigido o no, ya que calcula la distancia mínima desde un vertice de inicio a los demás vértices utilizando
 * una matriz de adyacencia para registrar los pesos de las aristas entre los vértices y actualizar las distancias acumuladas a 
 * través de los vértices adyacentes.
 */

/***********************************************************************/

/** 
 * @page Pruebas
 * @brief Ejecución del programa
 * @section pruebas_dijkstra Resultados de Pruebas
 * 
 * Las siguientes imágenes muestran la ejecución exitosa del programa correspondiente
 * al algoritmo de Dijkstra, el cual tiene las funciones de...
 * 
 * - Inicialización de grafo con n vértices.
 * - Uso de una matriz de adyacencia.
 * - Inserción de aristas.
 * - Visualización del camino más corto desde un vértice de inicio a los demás vértices del grafo.
 * 
 * El primer grafo de ejemplo es un grafo no dirigido de 5 vértices, los cuales son del 0 al 4 debido
 * a la indexación de los vértices. A continuación, se muestra la ejecución del programa para este grafo.
 * 
 * \image latex grafo1part1.png "Ejecución del programa en el grafo no dirigido (Parte 1)"
 * \image html grafo1part1.png
 * 
 * \image latex grafo1part2.png "Ejecución del programa en el grafo no dirigido (Parte 2)"
 * \image html grafo1part2.png
 * 
 * \image latex grafo1part3.png "Ejecución del programa en el grafo no dirigido (Parte 3)"
 * \image html grafo1part3.png
 * 
 * El segundo grafo de ejemplo es un grafo dirigido de 8 vértices, los cuales son del 0 al 7 debido a la
 * indexación de los vértices. A continuación, se muestra la ejecución del programa para este grafo.
 * 
 * \image latex grafo2part1.png "Ejecución del programa en el grafo dirigido (Parte 1)"
 * \image html grafo2part1.png
 * 
 * \image latex grafo2part2.png "Ejecución del programa en el grafo dirigido (Parte 2)"
 * \image html grafo2part2.png
 * 
 * \image latex grafo2part3.png "Ejecución del programa en el grafo dirigido (Parte 3)"
 * \image html grafo2part3.png
 * 
 * \image latex grafo2part4.png "Ejecución del programa en el grafo dirigido (Parte 4)"
 * \image html grafo2part4.png
 * 
 * \image latex grafo2part5.png "Ejecución del programa en el grafo dirigido (Parte 5)"
 * \image html grafo2part5.png
 */

/***********************************************************************/

 /** 
 * @page Bibliografía 
 * @brief Fuentes consultadas
 * 
 * Las fuentes consultadas (en formato APA) para la realización de este programa fueron...
 * 
 * 1) Breadth first search or BFS for a graph. (2012, marzo 20). GeeksforGeeks. https://www.geeksforgeeks.org/dsa/breadth-first-search-or-bfs-for-a-graph/
 * 
 * 2) C++ vector library. (s/f). W3schools.com. Recuperado el 11 de mayo de 2026, de https://www.w3schools.com/cpp/cpp_ref_vector.asp
 * 
 * 3) Dijkstra’s algorithm. (2012, noviembre 25). GeeksforGeeks. https://www.geeksforgeeks.org/dsa/dijkstras-shortest-path-algorithm-greedy-algo-7/
 * 
 * 4) Introduction to graph data structure. (2020, julio 15). GeeksforGeeks. https://www.geeksforgeeks.org/dsa/introduction-to-graphs-data-structure-and-algorithm-tutorials/ 
 */