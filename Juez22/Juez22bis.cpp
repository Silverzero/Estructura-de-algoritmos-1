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



// funcio´n que resuelve el problema
// comentario sobre el coste, O(f(N))
int resolver(std::vector<int> const &v, int i)
{
	if (v[i] != v[i - 1] + 1) return v[i-1] + 1;
	else return resolver(v, ++i);
}

bool resolver(std::vector<int> const &v, int inicio, int final, int &resultado, int primervalor)
{
	int media = ((final + inicio) / 2);
	
	//if (media == 0) return false;
	if (v[media] != v[media - 1] + 1)
	{
		resultado = v[media - 1] + 1;
	}
	else if (v[media] > primervalor + media)
		resolver(v,media,final, resultado, inicio);
	else

		if (resolver(v, inicio, v[media - 1], resultado,primervalor))
			return true;
		else if (resolver(v, v[media + 1], final, resultado,primervalor))
			return true;;
}

int resolver(std::vector<int> const &v, int inicio, int final)
{

	int resultado , media = (((v.size()) + 0) / 2);

	if (v[media] != v[media - 1] + 1)
	{
		resultado = v[media - 1] + 1;
	}
	else if (v[media] > inicio + media)
		resolver(v, 0, media, resultado, inicio);
	else
		resolver(v, media+1, v.size() - 1, resultado, inicio);
	return resultado;
		
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int inicio, final;
	std::cin >> inicio;
	std::cin >> final;
	
	std::vector<int> v(final-inicio);
	for (int i = 0; i < v.size(); i++)
	{
		std::cin >> v[i];
	}

	int sol = resolver(v, inicio, final);
	std::cout << sol << std::endl;
	
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("22EntradaEjemplo.txt");
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