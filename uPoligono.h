//---------------------------------------------------------------------------

#ifndef uPoligonoH
#define uPoligonoH
#include <vector>
#include "uPonto.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Poligono {
	public:
		int id;
		char tipo;
		std::vector<Ponto> pontos;

		void mostra(TListBox *LBpontos);
		void desenha(TCanvas *canvas,Janela mundo, Janela vp, int tipoReta);
		UnicodeString toString();
		void desenhaCirculo(TCanvas *canvas,Janela mundo, Janela vp);
		void Translada(double dx, double dy);
		void Escala(double sx, double sy);
		void Rotaciona(double GrauR);
		void Reflete(double rx, double ry);
		void RotacionaHomogeneo(double GrauR);
		Poligono DesenhaCurva(int index);



	private:
		void retaDDA(TCanvas *canvas,Janela mundo, Janela vp);
		void retaBresenham(TCanvas *canvas,Janela mundo, Janela vp);
		void retaMoveToLineTo(TCanvas *canvas,Janela mundo, Janela vp);
		Ponto centro();
		void MultMatriz1x3x3(double M_auxiliar[1][3], double matriz1[1][3],
				double matriz2[3][3]);
		double distEntrePontos(Ponto p1, Ponto p2);
		//bool straight(Poligono curve);
		Ponto pontoMedio(Ponto p1 , Ponto p2);
		void SubdividirCurva(Poligono pontosReta,
				Poligono *curvaEsquerda, Poligono *curvaDireita);
		Poligono desenhaCasteljau();
		void desenhaCasteljauRec(Poligono *curva,Poligono pontosReta);
		Poligono desenhaHermite();
		void multMatriz(double m1[][4], double m2[4][1], double aux[][1], int m1Linha);
		Poligono curvaBezier();
		Poligono desenhaBSpline();
};

#endif

