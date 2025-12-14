Para la entraga del advent of code se ha decidido entregar los siguientes problemas para su evaluación:
 -Problema DIA 4(lo encontraras como:códigodia4.cpp).
 -Problema DIA 8




--------------------------------Memoria Dia 4 (códigodia4.cpp):--------------------------------------------------------

En este problema del Advent of Code hemos trabajado con un mapa formado por rollos de papel representados con el carácter '@'. Cada uno de estos rollos puede interpretarse como un nodo, y dos rollos están conectados si están en alguna de las ocho posiciones adyacentes (horizontal, vertical o diagonal). Por tanto, el mapa puede modelarse como un grafo no ponderado donde cada vértice conoce a los rollos que tiene cerca. Este enfoque encaja muy bien con los contenidos vistos en clase y permite resolver el problema de forma estructurada.

Para la implementación hemos reutilizado parte del código de prácticas: la clase Node, la estructura ListLinked y la clase Graph construida sobre listas de adyacencia. Gracias a estas estructuras hemos podido representar el mapa como un grafo sin utilizar estructuras de la STL, cumpliendo así con las restricciones de la asignatura y aprovechando el trabajo desarrollado previamente.

El programa comienza leyendo el archivo puzzle.txt, que contiene el mapa original del reto. Cada línea representa una fila y cada posición con '@' se convierte en un vértice del grafo. A cada rollo se le asigna un índice y después se recorren sus ocho posiciones vecinas; si alguna de ellas contiene otro '@', se añade una arista entre los dos nodos usando Graph::addEdge. De esta forma, cada vértice queda asociado a la lista de todos sus vecinos directos.

Una vez construido el grafo, la solución se divide en dos partes: Part 1 y Part 2.

Part 1:
En la primera parte se trata de determinar cuántos rollos son accesibles por un montacargas. El enunciado indica que un rollo es accesible si tiene menos de cuatro vecinos adyacentes. Gracias al grafo construido, comprobar esto es tan simple como consultar el tamaño de la lista neighbors(v) de cada nodo. El programa recorre todos los vértices y cuenta cuántos tienen un grado estrictamente menor que cuatro. Este recuento es el resultado de la Part 1.

Part 2:
En la segunda parte hay que simular un proceso de eliminación de rollos. Si un rollo es accesible (tiene menos de cuatro vecinos), puede eliminarse. Al eliminarlo, sus vecinos pierden un adyacente y puede que pasen a ser accesibles a su vez. Por tanto, el proceso debe repetirse hasta que ya no quede ningún rollo con menos de cuatro vecinos.

Para simular este comportamiento se utiliza una cola implementada también con ListLinked. Primero se añaden a la cola todos los nodos cuyo grado inicial es menor que cuatro. Después se extrae un nodo, se marca como eliminado y se reduce en uno el grado de todos sus vecinos. Si alguno de ellos pasa a tener un grado menor que cuatro, se vuelve accesible y se añade a la cola. El proceso continúa hasta que la cola queda vacía. La cantidad total de nodos eliminados durante la simulación es el resultado de la Part 2.

Este enfoque funciona bien porque el problema se reduce a gestionar los grados de los nodos del grafo y actualizar sus valores a medida que se van eliminando vértices. No es necesario ejecutar BFS tradicional ni calcular rutas, ya que el reto no trata sobre encontrar caminos sino sobre determinar accesibilidad local y cómo esta cambia dinámicamente al modificar el grafo.

En cuanto a alternativas, podrían haberse utilizado otras estructuras o representaciones, como vectores dinámicos o colas de la STL, pero el objetivo principal era aplicar las estructuras construidas en las prácticas. Tampoco era necesario emplear algoritmos de caminos mínimos, programación dinámica o estructuras basadas en árboles, ya que el problema se resolvía de forma directa gestionando las listas de adyacencia.

En conclusión, este problema es una buena oportunidad para aplicar de manera práctica la representación de grafos mediante listas enlazadas, entender el concepto de grado de un nodo y ver cómo un pequeño cambio en la estructura (eliminación de vértices) puede modificar completamente el comportamiento del sistema. Separar la solución en Part 1 y Part 2 también ayuda a comprender cómo diferentes condiciones sobre el mismo grafo pueden abordarse de forma modular cambiando únicamente la lógica que actúa sobre él.






--------------------------------Memoria Día 8 (carpeta dia8 fichros Nodo.h Arbol.h main.cpp)-------------------------------------------------------
En este problema del Advent of Code hemos trabajado con un conjunto trimidensional de coordenadas, representados mediante las tripletas(x, y, z). Cada coordenada puede interpretarse como un nodo, y el objetivo principal consiste en identificar los grupos de nodos que se encuentran más cercanos entre sí, tomando como referencia la distancia euclidiana entre cada par de coordenadas.

Para la implementación hemos utilizado la clase nodo localizada en el fichero Nodo.h, que representa un nodo con sus coordenas y punteros a hijos en un árbol binario.Asimismo, también hemos empleado la clase Arbol, localizada en el fichero Arbol.h que combina un árbol binario de búsqueda con métodos para recorrer los nodos de forma ordenada y calcular distancia entre coordenada.Gracias a estas clases, hemos podido organizar de manera estructurada los nodos  y calcular las distancias de cada nodo respectivamente, evitando así recorrer todos los elementos de manera desordenada.

El programa inicialmente extrae del fichero input.txt las coordenadas de cada nodo en formato  int((x,y,z)) respectivamente. Cada linea del fichero se convierte en nodos que se insertan en el árbol binario, lo que nos facilitará el recorrido de forma ordenada.
Una se hayan obtenido todos los nodos, el programa calcula la distancia de cada coordenada siguiendo la siguiente expresión sqrt((x2-x1)^2 + (y2-y1)^2 +(z2-z1)^2 ).Dicho calculo se almacena en un vector de aristas, donde se almacenan la distancia y los índices de los nodos que conecta. Posteriormente las aristas se ordenan por distancias para priorizar las conexiones más cortas.
Inicialmente, cada nodo pertenece a su propio conjunto y luego se van uniendo nodos de menor distancia hasta un límite de aristas. De esta manera, se identifican grupos de nodos conectados según proximidad.Y finalmente, se calcula el tamaño de cada grupo y se selecciona los 3 más grandes multiplicando su tamaño para obtener la solución del reto del Advent of Code.

Esta estrategia es eficaz porque permite gestionar de manera clara todo el conjunto de nodos y sus relaciones de cercaía, sin necesidad de realizar una implementación de algun algoritmo de búsqueda. Además, el uso del árbol binario de busqueda optimiza la inserción de nuevos datos, evitando operaciones de ordenación explícitas sobre todos los datos.
Aunque esta solución resulta funcional y eficiente, existen alternaticas que podrían haberse implementado. Por ejemplo, el uso de un vector de memoria dinámica, o aplicar un algoritmo siguiendo una estrategia voraz para construir los grupos sin necesidad de recorrer todas las aristas.

En conlcusión, este reto ofrece la oportunidad de aplicar claramente una estrategia de árbol binario de busqueda, lo que permite simplificar el procesamiento y la organización de los datos.Gracias a esta estructura es posible recorrer y ordenar los nodos de forma eficiente facilitando cálculos posteriores.
