class Vertice {
	private:
		int id; //Identificação do nó
		int grau; //Grau do nó
		int G_v; //Diferença entre o grau do nó e o valor ideal para o grau
		double D_v; //Somatório de todas as distâncias entre o vértice e seus vizinhos
		double M_v; //Valor que representa a mobilidade do nó
		double P_v; //Capacidade de processamento do vertice
		double W_v; //Valor ponderado que determina o quão bom este vértice é para ser cluster-head. Quanto menor, melhor.
	public:	
		// Construtor da clase
		Vertice(){}
		Vertice(int id, int grau_n, int diferenca, double distancia, double mobilidade, double processamento);
		// Calcula a média ponderada de acordo com os pesos passados por parametro
		void calcularW_v(double v1, double v2, double v3, double v4); 
		// Retorna o id do vértice
		int getId();		
		//Retorna o somatório das distâncias
		double getD_v();
		//Retorna o valor da mobilidade
		double getM_v();
		//Retorna o valor de processamento
		double getP_v();
		// Retorna a média ponderada do vértice
		double getW_v();
		//Muda o valor da média ponderada
		void setW_v(double v);
		//Muda o valor do samatório das distâncias		
		void setD_v(double v);
		//Muda o valor da mobilidade
		void setM_v(double v);
		//Muda o valor de processamento
		void setP_v(double v);
};


