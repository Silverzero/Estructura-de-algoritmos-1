// Grupo XYZ, Fulano y Mengano
// Comentario general sobre la solucio´n,
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
void resolver(vector<vector <int>> const & matriz) {

	int contador = 0;
	for (int i = 0; i < matriz.size(); i++)
	{
		for (int j = 0; j < matriz[i].size(); j++)
		{
			if (matriz[i][j] == i) contador++;
		}
	
	}
	cout << contador << endl;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int columna, fila;
	cin >> columna >> fila;
	if (!std::cin)
		return false;

	vector<vector <int>> matrix(columna, std::vector<int>(fila));
	if (fila > 0 && columna > 0)
	{
		for (int i = 0; i < columna; i++)
		{
			for (int j = 0; j < fila; j++)
			{
				cin >> matrix[i][j];
			}
		}
	}
	resolver(matrix);

	// escribir sol


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("15EntradaEjemplo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}