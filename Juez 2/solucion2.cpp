// Grupo E11, Marco Desantes
// Comentario general sobre la solucion,
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
bool resolver(std::vector<int> const &v,int const &p) {

	if (v.size() >= 10000 || v.size() < 0 || p < 0 || p >= v.size())
		return false;
	else if (p + 1 == v.size())
		return true;
	else
	{
				int w = v[p+1];
		for (int i = p + 2; i < v.size(); i++)
		{
			if (w > v[i]) w = v[i];
		}
		int u = v[0];
		for (int j = 1; j <= p; j++)
		{
			if (u < v[j]) u = v[j];
		}
		
		return u < w;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n, p;

	std::cin >> n;
	std::cin >> p;
	std::vector<int> v(n);
	for (int& i : v) std::cin >> i;

	bool sol = resolver(v,p);
	// escribir sol
	if (sol) std::cout << "SI\n";
	else std::cout << "NO\n";
	


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("02EntradaEjemplo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}