//--------------------------------------------------------------------------

#include "uDisplay.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


void DisplayFile::toString(TListBox *LBpoligonos){
	LBpoligonos->Clear();
	for (int i=0; i < poligonos.size(); i++) {
		LBpoligonos->Items->Add(poligonos[i].toString());
	}
}

void DisplayFile::desenha(TCanvas *canvas, Janela mundo, Janela vp, int tipoReta){
	canvas->Brush->Color = clWhite;
	canvas->FillRect(Rect(0,0,500,500));

	canvas->Pen->Width = 2;
	canvas->Pen->Color = clRed;

	for (int i=0; i < poligonos.size(); i++) {
		poligonos[i].desenha(canvas, mundo, vp, tipoReta);
	}
}

#pragma hdrstop
