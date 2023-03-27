//---------------------------------------------------------------------------

#ifndef uPontoH
#define uPontoH

#include "uJanela.h"
#include <vcl.h>
//---------------------------------------------------------------------------
class Ponto {
	public:
	double x;
	double y;

	Ponto();
	int Vpx(Janela mundo, Janela vp);
	int Vpy(Janela mundo, Janela vp);
	Ponto(double nx, double ny);
	UnicodeString toString();

	void Transladar(double dx, double dy);
	void Escalar(double sx, double sy);
	void Rotacionar(double GrauR);
	void Refletir(double sx, double sy);
};
#endif
