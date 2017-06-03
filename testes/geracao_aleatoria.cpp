#include <iostream>
#include <stdlib.h>
#include "../src/Vertice.cpp"
#include <vector>

#include <chrono>
#include <random>

/* Essa função constrói um grafo aleatório com vértices 0..V-1 e exatamente A arcos. A função supõe que A <= V*(V-1). Se A for próximo de V*(V-1), a função pode consumir muito tempo. (Código inspirado no Programa 17.7 de Sedgewick.) */

struct Graph{

	std::vector<std::vector<Vertice>> matriz_adj;

};


//geração de grafos densos, no caso grafos completos;
void GRAPHrand2(Graph &G,int V, int A) { 

	std::vector <Vertice> linha;
    double prob = (double) A / V / (V-1);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  	std::default_random_engine generator (seed);

  	std::uniform_real_distribution<double> distribution (0.0,100.0);

  	std::uniform_real_distribution<double> mobilidade (0.0,1.0);

  	std::uniform_real_distribution<double> potencia (0.0,1.0);


	   for (int i = 0 ; G.matriz_adj.size() < V; i++){ 	  	 
	      for ( int j=0; linha.size() < V; j++){
	        if (i != j){
	        	Vertice w(0,0,0.0,0.0,0.0);
	            if (rand() < prob*(10000000000000000000)){
	            	w.setM_v(mobilidade(generator));
	         		w.setP_v(potencia(generator));
	            	w.setD_v(distribution(generator));
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

	      	G.matriz_adj[i][j].setD_v(G.matriz_adj[j][i].getD_v());

	      	if(i == j)
	      		G.matriz_adj[i][j].setD_v(0);
	      		
	      }
	  }
}


//geração de grafo  aleatório, não necessariamente denso
void GRAPHrand1(Graph &G,int V, int A) { 

	std::vector <Vertice> linha;
    double prob = (double) A / V / (V-1);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  	std::default_random_engine generator (seed);

  	std::uniform_real_distribution<double> distribution (0.0,100.0);

  	std::uniform_real_distribution<double> mobilidade (0.0,1.0);

  	std::uniform_real_distribution<double> potencia (0.0,1.0);

	

	   for (int i = 0 ; G.matriz_adj.size() < V; i++){ 	  	 
	      for ( int j=0; linha.size() < V; j++){
	        if (i != j){
	         	Vertice w(0,0,0.0,0.0,0.0);
	         	if (rand() % 5 + 0 < prob*(100)){
	         		w.setM_v(mobilidade(generator));
	         		w.setP_v(potencia(generator));
	            	w.setD_v(distribution(generator));
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

	      	G.matriz_adj[i][j].setD_v(G.matriz_adj[j][i].getD_v());

	      	if(i == j)
	      		G.matriz_adj[i][j].setD_v(0);
	      		
	      }
	  }
	  
}

void print(Graph G){

	for (int i = 0; i < G.matriz_adj.size(); i++){
		std::cout << i <<":";
		for (int j = 0; j < G.matriz_adj[i].size(); ++j)
		{
			cout << G.matriz_adj[i][j].getP_v() << ",";
		}

		std::cout << endl;
	}

}

int main(){

	Graph G;

	GRAPHrand2(G,4,2);
	print(G);

	cout << "----------------------------------------"<< endl;

	GRAPHrand1(G,4,2);
	print(G);

}
