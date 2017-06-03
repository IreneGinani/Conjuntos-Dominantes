#include "Vertice.h"

Vertice::Vertice (int grau_n, int diferenca, double distancia, double mobilidade, double processamento) {
	grau = grau_n;
	G_v = diferenca;
	D_v = distancia;
	M_v = mobilidade;
	P_v = processamento;
	W_v = 0;
}

void Vertice::calcularW_v (double v1, double v2, double v3, double v4) {
	W_v = (G_v * v1) + (D_v * v2) + (M_v * v3) + (P_v * v4);
}

double Vertice::getW_v () {
	return W_v;
}
