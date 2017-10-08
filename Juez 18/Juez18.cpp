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

	vector <int> v;
	vector <int> w;

	for (int i = 0; i < matriz.size(); i++)
	{
		int suma = 0;
		int suma2 = 0;
		for (int j = 0; j+i < matriz.size(); j++)
		{
			suma += matriz[j][i + j];
			suma2 += matriz[i + j][j];
		}
		v.push_back(suma);
		w.push_back(suma2);
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
		if (i == v.size() - 1) cout << endl;
		else cout << " ";
	}
	for (int i = 0; i < w.size(); i++)
	{
		cout << w[i];
		if (i == w.size() - 1) cout << endl;
		else cout << " ";
	}



}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int size;
	cin >> size;
	if (!std::cin)
		return false;

	vector<vector <int>> matrix(size, std::vector<int>(size));
	if (size > 0 && size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
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
	std::ifstream in("18EntradaEjemplo.txt");
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