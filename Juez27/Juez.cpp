// Grupo E11, Marco Desantes
// Comentario general sobre la solucio´n,
// explicando co´mo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>



// funcio´n que resuelve el problema
// comentario sobre el coste, O(f(N))
// El coste si se hace recursivo iterativo es O(n),
// al reducir el problema a subproblemas mas sencillo el algoritmo pasa a ser O(log n)
/*
	funcion recursiva auxiliar
*/
int resolver(std::vector<int> const &v, int inicio, int fin)
{
	int media = (fin + inicio) / 2;
	//caso base

	if (media == fin - 1 && v[media] < v[media-1])
		return v[media];
	else if (media == 0 && v[media] < v[media + 1])
		return v[media];
	else if(v[media] < v[media + 1] && v[media] < v[media - 1])
		return v[media];
	else
	{
		//si v[media-1] < v[media]
		if (v[media - 1] < v[media])
			return resolver(v, inicio, media - 1);
		//si v[media+1] < v[media]
		else 
			return resolver(v, media,fin);	
	}

}
/*
	 dividimos el vector a la mitad, comparamos los valores colindantes de cada lado,
	 si ambos son mayores ese es el minimo,por el contrario,
	 si i-1 es menor repetimos el proceso con la mitad de la izquierda  del vector,
	 si por el contrario es el de la derecha, operamos con el otro subvector.
	 
*/
int resolver(std::vector<int>const & v) {
	//partimos el vector a la mitad
	//caso base 1
	int media = v.size() / 2;
	if (v.size() == 1)
		return v[0];
	else if (v.size() == 2)
		if (v[0] < v[1]) return v[0];
		else return v[1];
	else if (media == v.size() - 1 && v[media] < v[media - 1])
		return v[media];
	else if (media == 0 && v[media] < v[media + 1])
		return v[media];
	// si v[media] es el minimo, caso base 2
	else if (v[media] < v[media + 1] && v[media] < v[media - 1])
		return v[media];
	else
	{
	//si v[media-1] < v[media]
		if (v[media - 1] < v[media])
			return resolver(v,0, media-1);
	//si v[media+1] < v[media]
		else
			return resolver(v, media, v.size());
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int numero;
	std::cin >> numero;
	if (!std::cin)
		return false;

	std::vector<int> v(numero);
	for (int i = 0; i < v.size(); i++)
		std::cin >> v[i];

	int sol = resolver(v);

	std::cout << sol << std::endl;
	// escribir sol


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Entrada.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}