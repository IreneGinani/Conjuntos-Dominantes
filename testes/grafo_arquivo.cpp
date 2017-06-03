#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string.h>
#include <sstream>


using namespace std;

struct Graph{

	std::vector<std::vector<int>> matriz_adj;

};

void lerArquivo(std::string arq, Graph &G){

	std::string line, token,posi, posj, peso;
	int pi,pj,pes;
	std::ifstream info(arq);
	int counter = 0;
	std::vector<int> linhas;

	for (int i =0; i < 124; i++){
		for (int j = 0; j < 124; j++)
		{
			linhas.push_back(0);
		}

		G.matriz_adj.push_back(linhas);
		linhas.clear();


	}

	int aux = 0;
	while(!info.eof()){

		getline(info,line);
        std::istringstream ss(line);
        int counter = 1;
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

	}
}

void print(Graph G){

	for (int i = 1; i <= 20; i++){
		std::cout << i <<":";
		for (int j = 1; j <= 20; ++j)
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
    print(G);
    
	return 0;
}