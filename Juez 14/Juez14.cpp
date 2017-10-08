// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solucio´n,
/*	recorremos el vector una sola vez y vamos almacenando el maximo y 
el numero de apariciones de este y despues de recorrerlo se le resta el max,
tantas veces como apariciones;
*/

// explicando co´mo se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;



// funcio´n que resuelve el problema
// comentario sobre el coste, O(f(N))
int resolver(vector<int> const& v) {


	int MAX = v[0];
	int suma = v[0];
	int contador = 1;
	//un recorrido  lineal,
	// N-1 acceso por cada elemento del vector
	for (int i = 1; i < v.size(); i++)
	{
		suma += v[i];//suma del vector;
		if (v[i] == MAX) contador++;
		else if (v[i] > MAX)
		{
			MAX = v[i];
			contador = 1;
		}	
	}
	suma = suma - (MAX*contador);// resta de contador veces el MAX;

	return suma;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	int size;
	cin >> size;
	vector<int> v(size);
	//PRECONDICION
	if (size > 0)
	{
		
		for (int &c : v)
			cin >> c;
	}
	int  sol = resolver(v);
	// escribir sol
	cout << sol << "\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("14EntradaEjemplo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}