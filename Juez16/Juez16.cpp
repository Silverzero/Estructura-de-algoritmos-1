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


	vector < int > v(matriz[0].size());


	for (int j = 0; j < matriz[0].size(); j++)
	{
		v[j] = matriz[0][j];
		for (int i = 1; i < matriz.size() && v[j] != -1; i++)
		{

			if (matriz[i][j] != v[j]) v[j] = -1;
		}

	}

	int contador = 0, contadoraux;
	if (v[0] == -1) contadoraux = 0;
	else contadoraux = 1;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] == v[i - 1] && v[i] != -1) contadoraux++;
		else if (v[i] != v[i - 1] && v[i] != -1)
		{
			contadoraux = 1;
		}
		if (contadoraux > contador)
		{
			contador = contadoraux;
		}
	}
	cout << contador << endl;
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int columna, fila;
	cin >> fila >> columna;
	if (!std::cin)
		return false;

	vector<vector <int>> matrix(fila, std::vector<int>(columna));
	if (fila > 0 && columna > 0)
	{
		for (int i = 0; i < fila; i++)
		{
			for (int j = 0; j < columna; j++)
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
	std::ifstream in("16EntradaEjemlo.txt");
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