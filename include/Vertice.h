class Vertice {
	private:
		int grau; //Grau do nó
		int G_v; //Diferença entre o grau do nó e o valor ideal para o grau
		double D_v; //Somatório de todas as distâncias entre o vértice e seus vizinhos
		double M_v; //Valor que representa a mobilidade do nó
		double P_v; //Capacidade de processamento do vertice
		double W_v; //Valor ponderado que determina o quão bom este vértice é para ser cluster-head. Quanto menor, melhor.
	public:	
		// Construtor da clase
		Vertice(int grau_n, int diferenca, double distancia, double mobilidade, double processamento);
		// Calcula a média ponderada de acordo com os pesos passados por parametro
		void calcularW_v(double v1, double v2, double v3, double v4);
		// Retorna a média ponderada do vértice
		double getW_v();
};