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
// comentario sobre el coste, O(n*m + n)
void resolver(vector<vector <int>> const & matriz, int media) {

	vector <int> w;
	// 0(f(n*n) porque es cuadrada.
	for (int i = 0; i < matriz.size(); i++)
	{
		int suma2 = 0;
		for (int j = 0; j + i < matriz.size(); j++)
		{
			suma2 += matriz[i + j][j];
		}
		suma2 = suma2 / (matriz.size() - i);
		w.push_back(suma2);
	}
	// en W tenemos un vector con las medias de las diagonales inferiores

	// 0(n)
	int contador = 0, contadoraux = 0, primeroaux = 0, primero = 0, max = 0, maxcontador = 0;
	bool salida = false;

	/*
	Falta calcular bien el primero y el ultimo valor a mostrar, muestra bien el tamaño de la franja maxima.
	y el maxcontador;
	
	*/
	for (int i = 0; i < w.size(); i++)
	{
		if (w[i] >= media)
		{
			if (w[i] > max)
			{
				maxcontador = 1;
				max = w[i];
			}
			else if(w[i] == max)
			{
				maxcontador++;
			}
			salida = true;
			contadoraux++;
			//este if esta mal.
			if (primeroaux < i)primeroaux = i;
			
		}
		else if (w[i] < media)
		{
			if (contadoraux > contador)
			{
				contador = contadoraux;
				primero = primeroaux;
			}
			contadoraux = 0;
			primeroaux = 0;
		}
		
	}
	
	if (!salida)
		cout << "NO" << endl;
	else
	{
		cout << contador << " " << primero << " " << maxcontador << endl;
		
	}


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio´n, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int size, media;
	cin >> size;
	cin >> media;
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
	resolver(matrix,media);

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