#include <iostream>
#include <stdlib.h>
#include "../src/Vertice.cpp"
#include <vector>

#include <chrono>
#include <random>
#include "../src/main.cpp"

using namespace std;

/* Essa função constrói um grafo aleatório com vértices 0..V-1 e exatamente A arcos. A função supõe que A <= V*(V-1). Se A for próximo de V*(V-1), a função pode consumir muito tempo. (Código inspirado no Programa 17.7 de Sedgewick.) */

struct Graph{

	std::vector<std::vector<double>> matriz_adj;

};


//geração de grafos densos, no caso grafos completos;
void GRAPHrand2(Graph &G,int V, int A) { 

	std::vector <double> linha;
    

    double prob = (double) A / V / (V-1);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  	std::default_random_engine generator (seed);

  	std::uniform_real_distribution<double> distribution (0.0,100.0);


	   for (int i = 0 ; G.matriz_adj.size() < V; i++){ 	  	 
	      for ( int j=0; linha.size() < V; j++){
	        if (i != j){
	        	double w = 0;
	            if (rand() < prob*(10000000000000000000)){
	            	w = distribution(generator);
	               linha.push_back(w);
	            }else 
	            	linha.push_back(w);
	       	 }
	       }

	       G.matriz_adj.push_back(linha);

	       linha.clear();
	   }

	  for (int i = 0 ; i < V; i++){ 	  	 
	      for ( int j=0; j < V; j++){

	      	G.matriz_adj[i][j] = G.matriz_adj[j][i];

	      	if(i == j)
	      		G.matriz_adj[i][j] = 0;
	      		
	      }
	  }
}


//geração de grafo  aleatório, não necessariamente denso
void GRAPHrand1(Graph &G,int V, int A) { 

	std::vector <double> linha;
    double prob = (double) A / V / (V-1);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  	std::default_random_engine generator (seed);

  	std::uniform_real_distribution<double> distribution (0.0,100.0);

	

	   for (int i = 0 ; G.matriz_adj.size() < V; i++){ 	  	 
	      for ( int j=0; linha.size() < V; j++){
	        if (i != j){
	         	double w = 0;
	         	if (rand() % 5 + 0 < prob*(100)){
	         	   w = distribution(generator);
	               linha.push_back(w);
	            }else 
	            	linha.push_back(w);
	       	 }
	       }

	       G.matriz_adj.push_back(linha);

	       linha.clear();
	   }

    for (int i = 0 ; i < V; i++){ 	  	 
	      for ( int j=0; j < V; j++){

	      	G.matriz_adj[i][j] = G.matriz_adj[j][i];

	      	if(i == j)
	      		G.matriz_adj[i][j] = 0;
	      		
	      }
	  }
	  
}

void print(Graph G){

	for (int i = 0; i < G.matriz_adj.size(); i++){
		std::cout << i <<":";
		for (int j = 0; j < G.matriz_adj[i].size(); ++j)
		{
			cout << G.matriz_adj[i][j] << ",";
		}

		std::cout << endl;
	}

}

int main(){


	std::vector<std::vector<double>> matriz_adjn(4, std::vector<double>(4));
	std::vector<int> idVerticesConjuntoDominante ;

	Graph G;

	//GRAPHrand2(G,4,2);
	print(G);

	cout << "----------------------------------------"<< endl;

	GRAPHrand1(G,4,2);
	print(G);

	algo_wca(G.matriz_adj, matriz_adjn, idVerticesConjuntoDominante, 2, 50.0, 0.6, 0.3, 0.05, 0.05);


	std::cout << "\nVertices que pertencem ao conjunto dominante:\n";
	for (int i = 0; i < matriz_adjn.size(); i++) {
			std::cout << "Vertice " << idVerticesConjuntoDominante[i] << "\n";	
	}

}
