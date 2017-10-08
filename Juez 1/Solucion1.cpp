// Marco Desantes Grupo 2ºE Software
// Comentario general sobre la solucio´n,
// explicando co´mo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;



// funcion que resuelve el problema
// comentario sobre el coste, O(f(N))
void resolver(vector<int> const& datos) {


	if (datos.size() >= 1)
	{

		int max = datos[0];
		int cont = 1;
		for (vector<int>::size_type i = 1; i < datos.size(); i++)
		{
			if (datos[i] == max) cont += 1;
			else if (datos[i] > max)
			{
				max = datos[i];
				cont = 1;
			}
		}
		cout << max << " " << cont << "\n";
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada


	
	int tamano;
	cin >> tamano;
	vector<int> v(tamano);
	
	for (int& c : v)
	{
		cin >> c;
	}

	resolver(v);
		
}


int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("01EntradaEjemplo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos;i++)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}