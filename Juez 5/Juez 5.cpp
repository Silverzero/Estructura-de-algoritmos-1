// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

// función que resuelve el problema
// comentario sobre el coste, O(f(N))
void resolver(std::vector<int>const &v)
{
	int tamano = v.size();
	std::vector<int> w(tamano);
	w[0] = v[0];
	for (int i = 1; i < w.size(); i++)
	{
		w[i] = w[i - 1] + v[i];
	}

	for (int c : w)
	{
		std::cout << c;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::vector<int> v;

	int aux;
	std::cin >> aux;
	if (aux < 0)
		return false;
	while (aux != 0)
	{
		v.push_back(aux);
		std::cin >> aux;
		if (aux < 0)
			return false;
	}
	resolver(v);

	// escribir sol

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/isabel/Dropbox/XcodePrograms/Prueba/datos1.txt");
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