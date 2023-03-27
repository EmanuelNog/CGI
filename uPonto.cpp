//---------------------------------------------------------------------------

#pragma hdrstop
#include "uJanela.h"
#include <vcl.h>

#include "uPonto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
 Ponto::Ponto(){
	x = y = 0;
 }

int Ponto::Vpx(Janela mundo, Janela vp){
	return  (1+((x - mundo.xmax)/(mundo.xmax - mundo.xmin))) * (vp.xmax - vp.xmin);
}
int Ponto::Vpy(Janela mundo, Janela vp){
	return  (-((y - mundo.ymax)/(mundo.ymax - mundo.ymin))) * (vp.ymax - vp.ymin);
}


 Ponto::Ponto(double nx, double ny){
	x = nx;
	y = ny;
 }

 UnicodeString Ponto::toString(){
	return "{" + FloatToStr(x) + "," + FloatToStr(y) + "}";
 }

 void Ponto::Transladar(double dx, double dy){
   x += dx;
   y += dy;
 }

 void Ponto::Escalar(double sx, double sy){
	x *= sx;
	y *= sy;
 }

 void Ponto::Rotacionar(double GrauR){
	double radiano = GrauR * M_PI/180;
	double xAnterior=x;

	x = (x*cos(radiano)) - (y*sin(radiano));
	y = (xAnterior*sin(radiano)) + (y*cos(radiano));
}

void Ponto::Refletir(double sx, double sy){
	x *= sx;
	y *= sy;
}



