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
bool resolver(std::vector<int> const &v, int numero, int inicio, int final)
{
	int media = (inicio + final) / 2;
	if (v[media] == numero + media)
	{
		std::cout << v[media] << std::endl;
		return true;
	}
	else if (media == v.size() - 1 || media == 0){
		std::cout << "NO" << std::endl;
		return false;
	}
	else if (v[media] < numero + media)//derecha
	{
		return resolver(v, numero, media + 1, v.size());
	}
	else //izquierda
		return resolver(v, numero, 0, media - 1);

}


bool resolver(std::vector<int> const &v, int numero)
{
	int media =(v.size() + 0) / 2;
	if (v[media] == numero + media)
	{
		std::cout << v[media] << std::endl;
		return true;
	}
	else if (v[media] < numero + media )//derecha
	{
		return resolver(v, numero, media + 1, v.size());
	}
	else //izquierda
		return resolver(v, numero, 0, media -1);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso()
{
	// leer los datos de la entrada
	int size, numero;
	std::cin >> size >> numero;
	std::vector<int> v(size);
	for (int i = 0; i < v.size(); i++)
	{
		std::cin >> v[i];
	}
	resolver(v,numero);
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("23EntradaEjemplo.txt");
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