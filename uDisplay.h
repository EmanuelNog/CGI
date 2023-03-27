//---------------------------------------------------------------------------

#ifndef uDisplayH
#define uDisplayH
#include <vector>
#include "uPoligono.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class DisplayFile{
	public:
		std::vector<Poligono> poligonos;

		void toString(TListBox *LBpoligonos);
		void desenha(TCanvas *canvas,Janela mundo, Janela vp, int tipoReta);
};
#endif
