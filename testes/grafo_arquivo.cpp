#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string.h>
#include <sstream>
#include "../src/Vertice.cpp"
#include "../src/wca.cpp"
#include <chrono>
#include <random>


using namespace std;

struct Graph{

	std::vector<std::vector<Vertice>> matriz_adj;

};

void lerArquivo(std::string arq, Graph &G){

	std::string line, token,posi, posj, peso;
	int pi,pj;
	double pes;
	std::ifstream info(arq);
	int counter = 0;
	std::vector<Vertice> linhas;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  	std::default_random_engine generator (seed);

  	std::uniform_real_distribution<double> mobilidade (0.0,1.0);

  	std::uniform_real_distribution<double> potencia (0.0,1.0);

	for (int i =0; i < 124; i++){
		for (int j = 0; j < 124; j++)
		{
			Vertice w(0,0,0.0,0.0,0.0);
			w.setM_v(mobilidade(generator));
	    	w.setP_v(potencia(generator));
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
        Vertice w(0,0,0.0,0.0,0.0);
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

		
		G.matriz_adj[pi][pj].setD_v(pes);

	}
}

void print(Graph G){

	for (int i = 1; i <= 20; i++){
		std::cout << i <<":";
		for (int j = 1; j <= 20; ++j)
		{
			cout << G.matriz_adj[i][j].getD_v() << ",";
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
    print(G);
    
	return 0;
}