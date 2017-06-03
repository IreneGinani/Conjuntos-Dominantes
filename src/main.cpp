#include <iostream>
#include <vector> // std::vector(), std::vector<>::iterator 
#include <stdlib.h> // std::abs()
#include <algorithm> // sort()
#include "Vertice.h"

//Função que compara vertices pela sua média ponderada
bool comp (Vertice i, Vertice j) { return (i.getW_v() < j.getW_v()); }

void algo_wca (std::vector<std::vector<double>> matrizAdjacencia, std::vector<std::vector<double>> &novaMatrizAdjacencia, std::vector<int> &idVerticesConjuntoDominante,int num_ideal_de_vizinhos, double faixa_transmissao, double v1, double v2, double v3, double v4) {
	std::vector<Vertice> vertices; //Vetor com todos os vértices do grafo
	srand(time(NULL));
	
	for (int i = 0; i < matrizAdjacencia[0].size(); i++) {
		int grau = 0;
		double distancia = 0;
		
		for (int j = 0; j < matrizAdjacencia[0].size(); j++) {
			//COUT PARA AJUDAR NA VISUALIZAÇÃO
			std::cout << "matrizAdjacencia[" << i << "][" << j << "] = " << matrizAdjacencia[i][j] << "\n";
			//Verifica quantos nós são vizinhos
			//Um nó só é vizinho de outro se a distanci entre eles estiver entre 0 e a faixa de transmissão 
			if ( (matrizAdjacencia[i][j] > 0) && (matrizAdjacencia[i][j] <= faixa_transmissao) ) {
				grau++;
				distancia += matrizAdjacencia[i][j];
			}
		}

		//Gerar um valor de mobilidade m
		double m = 1.0*((double)(rand())/RAND_MAX);;
		//Gerar um valor de potencia p
		double p = 1.0*((double)(rand())/RAND_MAX);;
		//COUT PARA AJUDAR NA VISUALIZAÇÃO
		std::cout << "id: " << i << " " << "grau: " << grau << " " << "|grau - phi| = " << abs(num_ideal_de_vizinhos - grau) << " " << "distancia: " << distancia << " " << "mobilidade: " << m << " " << "potencia: " << p << "\n";
		std::cout << "\n";
		Vertice v(i, grau, abs(num_ideal_de_vizinhos - grau), distancia, m, p);
		v.calcularW_v(v1, v2, v3, v4);
		vertices.push_back(v);
	}

	//Ordena o vetor em ordem não decrescente em relação ao valor de W_v de cada vértice
	std::sort (vertices.begin(), vertices.end(), comp); 

	for (int i = 0; i < vertices.size(); i++) {
		//COUT PARA AJUDAR NA VISUALIZAÇÃO
		std::cout << "Vertice " << vertices[i].getId() << " tem valor ponderado igual a: " << vertices[i].getW_v() << "\n";	
	}

	//Enquanto a lista de vertices não estiver vazia
	while (!vertices.empty()) {
		//Identifica o vertice pelo id
		int id = vertices[0].getId();

		//Seleciona os vertices vizinhos
		for (int j = 0; j < novaMatrizAdjacencia[0].size(); j++) {
			if ((matrizAdjacencia[id][j] > 0) && (matrizAdjacencia[id][j] <= faixa_transmissao)) {
				
				//Verifica se esse vertice vizinho ainda pertence ao vetor de vertices
				std::vector<Vertice>::iterator it1 = vertices.begin();
				std::vector<Vertice>::iterator it2 = vertices.end();
				bool r = false;
				while ( (it1!=it2) && !r ) {
					if ( (*it1).getId() == j) {
						r = true;
					} else {
						it1++;
					}
				}

				//Se o vertice ainda pertence ao vetor
				if (r) {
					std::cout << "Nó " << (*it1).getId() << " é vizinho de " << id << "\n";
					//Adiciona o valor da aresta da matriz antiga na nova
					novaMatrizAdjacencia[id][(*it1).getId()] = matrizAdjacencia[id][(*it1).getId()];
					novaMatrizAdjacencia[(*it1).getId()][id] = novaMatrizAdjacencia[id][(*it1).getId()];
					//Apaga o vertice vizinho no vetor
					vertices.erase(it1);
				} 
			}
		}

		//Adiciona o id no vetor dos elementos do conjunto dominante
		idVerticesConjuntoDominante.push_back(id);
		//Apaga vertice do vetor de vertices
		vertices.erase(vertices.begin()+0);

		std::cout << "\n";
		for (int i = 0; i < vertices.size(); i++) {
			//COUT PARA AJUDAR NA VISUALIZAÇÃO
			std::cout << "Vertice " << vertices[i].getId() << " tem valor ponderado igual a: " << vertices[i].getW_v() << "\n";	
		}
	}


}

int main () {
	//Ex: MATRIZ DE ADJACENCIA
	std::vector<std::vector<double>> matrizAdjacencia (5, std::vector<double>(5) );
	std::vector<std::vector<double>> novaMatrizAdjacencia (5, std::vector<double>(5) );
	
	std::vector<int> idVerticesConjuntoDominante;
	
	//Adicionando valores aleátorios na matriz de adjacencia
	srand(time(NULL));
	for (int i = 0, inicio = 0; i < matrizAdjacencia[0].size(); i++, inicio++) {
		for (int j = inicio; j < matrizAdjacencia[0].size(); j++) {
			if (i == j) {
				matrizAdjacencia[i][j] = 0;
			} else {
				matrizAdjacencia[i][j] = 100.0*((double)(rand())/RAND_MAX);
				matrizAdjacencia[j][i] = matrizAdjacencia[i][j];
			}
		}
	}

	algo_wca(matrizAdjacencia, novaMatrizAdjacencia, idVerticesConjuntoDominante, 2, 50.0, 0.6, 0.3, 0.05, 0.05);

	// Nova representação do grafo em novaMatrizAdjacencia
	
	//COUT PARA AJUDAR NA VISUALIZAÇÃO
	std::cout << "\nVertices que pertencem ao conjunto dominante:\n";
	for (int i = 0; i < idVerticesConjuntoDominante.size(); i++) {
			std::cout << "Vertice " << idVerticesConjuntoDominante[i] << "\n";	
	}

 	return 0;
}
