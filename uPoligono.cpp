//---------------------------------------------------------------------------

#pragma hdrstop

#include<iostream>
#include "uPoligono.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

#define SIGN(x) ((x) < 0 ? (-1):(1))
#define ABS(x)	((x) < 0 ? (-x):(x))
#define FLOOR(x) ((x) < 0 ? ((x) - (int)(x) != 0 ? ((int)(x) -1) : ((int)(x))) : (int)(x))

UnicodeString Poligono::toString(){
	return IntToStr(id) + " - " + tipo + " - " + IntToStr((int)pontos.size())
			+ " pontos";
}

void Poligono::mostra(TListBox *LBpontos){
	LBpontos->Clear();
	for (int i=0; i < pontos.size(); i++) {
		LBpontos->Items->Add(pontos[i].toString());
	}
}

void Poligono::desenha(TCanvas *canvas,Janela mundo, Janela vp, int tipoDesenho){
	canvas->Pen->Color = clRed;

	if  (pontos.size()>1){
		switch (tipoDesenho) {
		   case 0:
				retaDDA(canvas, mundo, vp);
		   break;

		   case 1:
				retaBresenham(canvas,mundo, vp);
		   break;

		   case 2:
				desenhaCirculo(canvas,mundo, vp);
		   break;

		   default:
				retaMoveToLineTo(canvas, mundo, vp);
			break;
		}
	}
}

void Poligono::retaMoveToLineTo(TCanvas *canvas,Janela mundo, Janela vp){
		   canvas->MoveTo(pontos[0].Vpx(mundo,vp), pontos[0].Vpy(mundo,vp));

			for (int i = 1; i < pontos.size(); i++) {
				canvas->LineTo(pontos[i].Vpx(mundo,vp), pontos[i].Vpy(mundo,vp));
			}
}

void Poligono::retaDDA(TCanvas *canvas,Janela mundo, Janela vp){


	for (int i = 1; i < pontos.size(); i++) {
		float x1,x2,y1,y2;
		float length;
		float deltax,deltay,deltaDivx,deltaDivy;
		float x,y;

		x1 = (float)pontos[i-1].Vpx(mundo,vp);
		y1 = (float)pontos[i-1].Vpy(mundo,vp);
		x2 = (float)pontos[i].Vpx(mundo,vp);
		y2 = (float)pontos[i].Vpy(mundo,vp);

		deltax = x2-x1;
		deltay = y2-y1;

		if(ABS(deltax) >= ABS(deltay))
			length = ABS(deltax);
		else
			length = ABS(deltay);

		deltaDivx =  deltax / length;
		deltaDivy =  deltay / length;
		x = x1 + 0.5 * SIGN(deltaDivx);
		y = y1 + 0.5 * SIGN(deltaDivy);

		for (int i = 0; i < length; i++) {
			canvas->Pixels[FLOOR(x)][FLOOR(y)]= clBlack;
			x += deltaDivx;
			y += deltaDivy;
		}

		Ponto novo = centro();

		canvas->Pixels[novo.Vpx(mundo,vp)][novo.Vpy(mundo,vp)]= clBlack;

	}
}

void Poligono::retaBresenham(TCanvas *canvas,Janela mundo, Janela vp){
		   for (int i = 1; i < pontos.size(); i++) {
			   float x1,x2,y1,y2;
			   float deltax,deltay;
			   float x,y;
			   x1 = (float)pontos[i-1].Vpx(mundo,vp);
			   y1 = (float)pontos[i-1].Vpy(mundo,vp);
			   x2 = (float)pontos[i].Vpx(mundo,vp);
			   y2 = (float)pontos[i].Vpy(mundo,vp);

			   x = x1;
			   y = y1;
			   deltax = ABS((x2-x1));
			   deltay = ABS((y2-y1));
			   float signalx = SIGN((x2-x1));
			   float signaly = SIGN((y2-y1));

			   if (signalx < 0) {
					x -=1;
			   }
			   if (signaly < 0) {
					y -= 1;
			   }

			   bool interchange = false;

			   if(deltay > deltax){
				float tmp = deltax;
				deltax = deltay;
				deltay = tmp;
				interchange = true;
			   }

			   float e = 2*deltay - deltax;

			   for (int j = 0; j < deltax; j++) {
					canvas->Pixels[x][y]= clGreen;
					while (e >=0){
						if (interchange)
							x += signalx;
							else
							y += signaly;
						e = e - 2*deltax;
				   }
					if(interchange)
						y += signaly;
					else
						x += signalx;
					e = e + 2*deltay;
			   }
		   }
}

void Poligono::desenhaCirculo(TCanvas *canvas,Janela mundo, Janela vp){
	for (int i = 0; i < pontos.size(); i++) {
		canvas->Pixels[pontos[i].Vpx(mundo,vp)][pontos[i].Vpy(mundo,vp)]= clGray;
	}
}

void Poligono::Translada(double dx, double dy){
	for (int i = 0; i < pontos.size(); i++) {
		pontos[i].Transladar(dx,dy);
	}
}

void Poligono::Escala(double sx, double sy){
	for (int i = 0; i < pontos.size(); i++) {
		pontos[i].Escalar(sx,sy);
	}
}

void Poligono::Rotaciona(double GrauR){
	for (int i = 0; i < pontos.size(); i++) {
		pontos[i].Rotacionar(GrauR);
	}
}

void Poligono::Reflete(double rx, double ry){

	for (int i = 0; i < pontos.size(); i++) {
		pontos[i].Refletir(rx,ry);
	}
}

void Poligono::RotacionaHomogeneo(double GrauR){
	double radiano = GrauR * M_PI/180;
	double dx,dy;
	double xAnterior;
	double M_rotacao[3][3]={{cos(radiano),sin(radiano),0},
							{-sin(radiano),cos(radiano),0},
							{0,0,1}};
	Ponto centroPol = centro();
	dx = centroPol.x;
	dy = centroPol.y;

	double M_translacao[3][3]={{1,0,0},
							   {0,1,0},
							   {dx,dy,1}};

	double M_translacaoNegativa[3][3]={{1,0,0},
									   {0,1,0},
									   {-dx,-dy,1}};
	double M_xy[1][3]= {0,0,1};
	double M_auxiliar[1][3]={0,0,1};

	MultMatriz1x3x3(M_auxiliar,M_xy,M_translacaoNegativa);

	MultMatriz1x3x3(M_auxiliar,M_xy,M_rotacao);

	MultMatriz1x3x3(M_auxiliar,M_xy,M_translacao);

}

void Poligono::MultMatriz1x3x3(double M_auxiliar[1][3], double matriz1[1][3], double matriz2[3][3]){

	for(int i = 0; i<pontos.size(); i++){
		matriz1[0][0] = pontos[i].x;
		matriz1[0][1] = pontos[i].y;

		for (int l=0; l < 1; l++){
			for (int c=0; c < 3; c++){
			M_auxiliar[l][c] = 0;
				for (int w=0; w < 3; w++){
					M_auxiliar[l][c] = M_auxiliar[l][c] + matriz1[l][w]
									   * matriz2[w][c];
				}
			}
		}
		pontos[i].x = M_auxiliar[0][0];
		pontos[i].y = M_auxiliar[0][1];
	}
}

Ponto Poligono::centro(){
	double somax=0;
	double somay=0;

	for(int i = 0; i<pontos.size(); i++){
		somax += pontos[i].x;
		somay += pontos[i].y;
	}

	somax = somax / pontos.size();
	somay = somay / pontos.size();

	return Ponto(somax,somay);
}

Poligono Poligono::DesenhaCurva(int index){
Poligono empty;
	switch(index){
		case 0:
			return desenhaCasteljau();
			break;
		case 1:
			return desenhaHermite();
			break;
		case 2:
			return curvaBezier();
			break;
		case 3:
			return desenhaBSpline();
			break;
		default:
		return empty;
	}
}

Poligono Poligono::desenhaCasteljau(){
	Poligono curva;
	Poligono pontosReta;
	pontosReta.pontos.push_back(pontos[0]);
	pontosReta.pontos.push_back(pontos[1]);
	pontosReta.pontos.push_back(pontos[2]);
	curva.pontos.push_back(pontos[0]);
	desenhaCasteljauRec(&curva,pontosReta);
	return curva;
}

void Poligono::desenhaCasteljauRec(Poligono *curva,Poligono pontosReta){//talvez curva deva ser ponteiro
	Poligono curvaEsquerda;
	Poligono curvaDireita;

	if (distEntrePontos(pontosReta.pontos[0],pontosReta.pontos[2])<1) {
		curva->pontos.push_back(pontosReta.pontos[0]);
	}else{
		SubdividirCurva(pontosReta,&curvaEsquerda,&curvaDireita);
		desenhaCasteljauRec(curva, curvaEsquerda);
		desenhaCasteljauRec(curva, curvaDireita);
	}
}

void Poligono::SubdividirCurva(Poligono pontosReta, Poligono *curvaEsquerda, Poligono *curvaDireita){
	Ponto pMedio1 = pontoMedio(pontosReta.pontos[0],pontosReta.pontos[1]);
	Ponto pMedio2 = pontoMedio(pontosReta.pontos[1],pontosReta.pontos[2]);
	Ponto pMedio3 = pontoMedio(pMedio1,pMedio2);

	curvaEsquerda->pontos.push_back(pontosReta.pontos[0]);
	curvaEsquerda->pontos.push_back(pMedio1);
	curvaEsquerda->pontos.push_back(pMedio3);

	curvaDireita->pontos.push_back(pMedio3);
	curvaDireita->pontos.push_back(pMedio2);
	curvaDireita->pontos.push_back(pontosReta.pontos[2]);
}

Ponto Poligono::pontoMedio(Ponto p1 , Ponto p2){
	Ponto medio;
	medio.x = (p1.x + p2.x)/2;
	medio.y = (p1.y + p2.y)/2;
	return medio;
}

double Poligono::distEntrePontos(Ponto p1, Ponto p2){
	return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

Poligono Poligono::desenhaHermite(){
	Ponto R1,R4;
    Poligono curva;
	Ponto pCurva;
	double aux[1][1];
	double Cx[4][1],Cy[4][1];
	double T[1][4];

	R1.x = pontos[1].x - pontos[0].x;
	R1.x = pontos[1].x - pontos[0].x;
	R4.x = pontos[3].x - pontos[2].x;
	R4.x = pontos[3].x - pontos[2].x;

	double M_Hermite[4][4] = {{2,-2,1,1},
							  {-3,3,-2,-1},
							  {0,0,1,0},
							  {1,0,0,0}};

	double M_x[4][1] = {{pontos[0].x},
						{pontos[3].x},
						{R1.x},
						{R4.x}};

	double M_y[4][1] = {{pontos[0].y},
						{pontos[3].y},
						{R1.y},
						{R4.y}};

	multMatriz(M_Hermite,M_x,Cx,4);
	multMatriz(M_Hermite,M_y,Cy,4);

	for	(double t=0; t<=1; t+=0.01){
		T[0][0] = {t*t*t};
		T[0][1] = {t*t};
		T[0][2] = {t};
		T[0][3] = 1;

		multMatriz(T,Cx,aux,1);
		pCurva.x = aux[0][0];
		multMatriz(T,Cy,aux,1);
		pCurva.y = aux[0][0];

		curva.pontos.push_back(pCurva);
	}
	return curva;
}

void Poligono::multMatriz(double m1[][4], double m2[4][1], double aux[][1], int m1Linha){
	int i, k;
	int j = 0;

	for(i = 0; i < m1Linha; ++i){
		aux[i][j] = 0;

		for(k=0; k<4; ++k){
		   aux[i][j] += m1[i][k] * m2[k][j];
		}
	}

}

Poligono Poligono::curvaBezier(){

	Poligono curva;
	Ponto pCurva;
	double aux[1][1];
	double Cx[4][1], Cy[4][1];
	double T[1][4];

	double M_Bezier[4][4] = {{-1, 3, -3, 1},
							 {3, -6, 3, 0},
							 {-3, 3, 0, 0},
							 {1, 0, 0, 0}};

	double M_x[4][1] = {{pontos[0].x},
						{pontos[1].x},
						{pontos[2].x},
						{pontos[3].x}};

	double M_y[4][1] = {{pontos[0].y},
						{pontos[1].y},
						{pontos[2].y},
						{pontos[3].y}};

	multMatriz(M_Bezier, M_x, Cx, 4);
	multMatriz(M_Bezier, M_y, Cy, 4);

	for (double t = 0; t <= 1; t+=0.01){
		T[0][0] = {t*t*t};
		T[0][1] = {t*t};
		T[0][2] = {t};
		T[0][3] = 1;

		multMatriz(T, Cx, aux, 1);
		pCurva.x = aux[0][0];
		multMatriz(T, Cy, aux, 1);
		pCurva.y = aux[0][0];

		curva.pontos.push_back(pCurva);
	}
	return curva;
}

Poligono Poligono::desenhaBSpline(){

	Poligono curva;
	Ponto pCurva;
	double aux[1][1];
	double Cx[4][1], Cy[4][1];
	double T[1][4];

	double M_BSpline[4][4] = {{-1.0/6.0, 3.0/6.0, -3.0/6.0, 1.0/6.0},
							  {3.0/6.0, -6.0/6.0, 3.0/6.0, 0},
							  {-3.0/6.0, 0, 3.0/6.0, 0},
							  {1.0/6.0, 4.0/6.0, 1.0/6.0, 0}};

	for (int i = 3; i < pontos.size(); i++){

		double M_x[4][1] = {{pontos[i-3].x},
							 {pontos[i-2].x},
							 {pontos[i-1].x},
							 {pontos[i].x}};

		double M_y[4][1] = {{pontos[i-3].y},
							 {pontos[i-2].y},
							 {pontos[i-1].y},
							 {pontos[i].y}};

		multMatriz(M_BSpline, M_x, Cx, 4);
		multMatriz(M_BSpline, M_y, Cy, 4);

		for (double t = 0; t <= 1; t+=0.01){
			T[0][0] = {t*t*t};
			T[0][1] = {t*t};
			T[0][2] = {t};
			T[0][3] = 1;

			multMatriz(T, Cx, aux, 1);
			pCurva.x = aux[0][0];
			multMatriz(T, Cy, aux, 1);
			pCurva.y = aux[0][0];

			curva.pontos.push_back(pCurva);
		}
	}
	return curva;

}

/* Nao funciona
Poligono Poligono::desenhaForwardDifference(){

	Ponto R0, R3;
	double s = 0.01;
	Poligono curva;
	Ponto pCurva;
	double x0, dx0, d2x0, d3x0;
	double y0, dy0, d2y0, d3y0;
	double Coefx[4][1], Coefy[4][1];

	R0.x = pontos[1].x - pontos[0].x;
	R0.y = pontos[1].y - pontos[0].y;
	R3.x = pontos[3].x - pontos[2].x;
	R3.y = pontos[3].y - pontos[2].y;

	double M_HermInv[4][4] = {{0,  0, 0, 1},
							  {1, 1, 1, 1},
							  {0, 0, 1, 0},
							  {3, 2, 1, 0}};

	double M_x[4][1] = {{pontos[0].x},
						{pontos[3].x},
						{R0.x},
						{R3.x}};

	double M_y[4][1] = {{pontos[0].y},
						{pontos[3].y},
						{R0.y},
						{R3.y}};

	multMatriz(M_HermInv, M_x, Coefx, 4);
	multMatriz(M_HermInv, M_y, Coefy, 4);

	x0 = Coefx[0][0];
	y0 = Coefy[0][0];
	dx0 = Coefx[1][0];
	dy0 = Coefy[1][0];
	d2x0 = Coefx[2][0];
	d2y0 = Coefy[2][0];
    d3x0 = Coefx[3][0];
	d3y0 = Coefy[3][0];

	for (double t = 0; t <= 1; t+=s){
		pCurva.x = Coefx[0][0];
		pCurva.y = Coefy[0][0];

		Coefx[0][0] += Coefx[1][0];
		Coefx[1][0] += Coefx[2][0];
		Coefx[2][0] += Coefx[3][0];
		Coefy[0][0] += Coefy[1][0];
		Coefy[1][0] += Coefy[2][0];
		Coefy[2][0] += Coefy[3][0];

		curva.pontos.push_back(pCurva);
    }

	return curva;
};*/
