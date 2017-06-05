#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string.h>
#include <sstream>
#include "../src/Vertice.cpp"

#include <chrono>
#include <random>

#include "../src/wca.cpp"


using namespace std;

struct Graph{

	std::vector<std::vector<double>> matriz_adj;

};

void lerArquivo(std::string arq, Graph &G){
	
	std::string line, token,posi, posj, peso;
	int pi,pj;
	double pes;
	std::ifstream info(arq);
	int counter = 0;
	std::vector<double> linhas;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  	std::default_random_engine generator (seed);
	
	for (int i =0; i < 6; i++){
		for (int j = 0; j <	 6; j++)
		{
			double w = 0;
			linhas.push_back(w);

		}

		G.matriz_adj.push_back(linhas);
		linhas.clear();


	}

	int aux = 0;
	while(!info.eof()){

		getline(info,line);
        std::istringstream ss(line);
        int counter = 1;
        double w;
        while(getline(ss, token,' ')) {

        	counter++;
        	
        	if(counter == 3)
        		posi = token;
        	else if (counter == 4)
        		posj = token;
			else if (counter == 5)
				peso = token;
			else if(counter == 2)
				continue;
			else
				break;	

			
		}
		
		pi = atoi(posi.c_str());
		pj = atoi(posj.c_str());
		pes = atoi(peso.c_str());
		
		
		G.matriz_adj[pi][pj] = pes;
		G.matriz_adj[pj][pi] = pes;

		//std::cout <<G.matriz_adj[pi][pj]<<std::endl;

	}
}

void print(Graph G){

	for (int i = 0; i < 6; i++){
		std::cout << i <<":";
		for (int j = 0; j < 6; ++j)
		{
			cout << G.matriz_adj[i][j] << ",";
		}

		std::cout << endl;
	}

}

int main(int argc, char const *argv[])
{
	if (argc < 2) {
        std::cerr << "Arquivo nao fornecido." << std::endl;
        exit (1);
    }
    Graph G;
    std::string arquivo = argv[1];
    lerArquivo(arquivo, G);
    //print(G);

    std::vector<std::vector<double>> matriz_adjn (6, std::vector<double>(6) );
	std::vector<int> idVerticesConjuntoDominante;

	
	algo_wca(G.matriz_adj, matriz_adjn, idVerticesConjuntoDominante, 5, 5000.0, 0.6, 0.3, 0.05, 0.05);

	//std::cout << idVerticesConjuntoDominante.size();
	std::cout << "\nVertices que pertencem ao conjunto dominante:\n";
	for (int i = 0; i < idVerticesConjuntoDominante.size(); i++) {
				std::cout << "Vertice " << idVerticesConjuntoDominante[i] << "\n";	
	}
    
	return 0;
}