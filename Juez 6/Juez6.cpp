// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solucion,
// explicando como se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;



// funcio´n que resuelve el problema
// comentario sobre el coste, O(f(N))
void resolver(string const & buffer) {

	int MAX=1;
	int contador = 1;
	for (int i = 1; i < buffer.length(); i++)
	{
		if (buffer[i-1] >= buffer[i]) contador=1;
		else contador++;

		if (contador > MAX)MAX = contador;
	}


	cout << buffer.length() << " " << MAX << "\n";
	

	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	
	string buffer;
	cin >> buffer;
	
	while (buffer != "XXX")
	{
		
		resolver(buffer);

		cin >> buffer;
	}
	if (buffer == "XXX")
		return false;

	// escribir sol

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("06EntradaEjemplo.txt");
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