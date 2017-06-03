#include "../include/Vertice.h"
#include <iostream>

using namespace std;

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

double Vertice::getD_v () {
	return D_v;
}

double Vertice::getP_v () {
	return P_v;
}

double Vertice::getM_v () {
	return W_v;
}

void Vertice::setW_v (double v) {
	
	W_v = v;
}

void Vertice::setP_v (double v) {
	
	P_v = v;
}

void Vertice::setM_v (double v) {
	
	M_v = v;
}

void Vertice::setD_v (double v) {
	
	D_v = v;
}
