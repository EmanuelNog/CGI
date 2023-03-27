// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uPrincipal.h"
#include "uPonto.h"
#include "uJanela.h"
#include "uPoligono.h"
#include "uDisplay.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFprincipal *Fprincipal;
Ponto aux;
Janela mundo(-250,-250,250,250);
Janela vp(0,0,500,500);  //isso nao define o tamanho da tela, só representa
						 //o tamanho e coordenadas sao feitas pelas dimensoes do Image1
Poligono pol;
DisplayFile display;

int contaId=0;
bool insere = false;
int tipoReta = -1;
bool criar_circulo = false;
int tipoCurva = -1;

double xVp2Mundo(int x, Janela mundo, Janela vp){
	return (x / vp.xmax) * (mundo.xmax - mundo.xmin)
	+ mundo.xmin;
}
double yVp2Mundo(int y, Janela mundo, Janela vp){
	return (1-(y / vp.ymax)) * (mundo.ymax - mundo.ymin)
	+ mundo.ymin;
}


// ---------------------------------------------------------------------------
__fastcall TFprincipal::TFprincipal(TComponent* Owner) : TForm(Owner)
{
	pol.pontos.push_back(Ponto(-250, 0));
	pol.pontos.push_back(Ponto(250, 0));
	pol.id = contaId++;
    display.poligonos.push_back(pol);
	pol.pontos.clear();
	pol.pontos.push_back(Ponto(0, -250));
	pol.pontos.push_back(Ponto(0, 250));
	pol.id = contaId++;
	display.poligonos.push_back(pol);
	pol.pontos.clear();

	pol.pontos.push_back(Ponto(-50, -50));
	pol.pontos.push_back(Ponto(50, 50));
	pol.id = contaId++;
	pol.tipo = 'N';

	display.poligonos.push_back(pol);
	pol.pontos.clear();

	display.toString(LBpoligonos);

	pol.mostra(LBpontos);
	display.desenha(Image1->Canvas, mundo, vp, tipoReta);

	RgTipoReta->Items->Add("DDA");
	RgTipoReta->Items->Add("Bresenham");

	RgTipoCurva->Items->Add("Casteljau");
	RgTipoCurva->Items->Add("Hermite");
	RgTipoCurva->Items->Add("Bezier");
    RgTipoCurva->Items->Add("BSpline");
}
// ---------------------------------------------------------------------------

void __fastcall TFprincipal::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	double xw,yw,auxVpx,auxVpy;
	xw = xVp2Mundo(X,mundo,vp);
	yw = yVp2Mundo(Y,mundo,vp);
    aux.x = xw;
	aux.y = yw;
	auxVpx = aux.Vpx(mundo,vp);
	auxVpy = aux.Vpy(mundo,vp);
	Label1->Caption = "{" + IntToStr(X) + "," + IntToStr(Y) + "}";
	Label2->Caption = "{" + FloatToStr(xw) + "," + FloatToStr(yw) + "}";
	Label3->Caption = "{" + FloatToStr(auxVpx) + "," + FloatToStr(auxVpy) + "}";


}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::Image1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	double xw,yw;
	xw = xVp2Mundo(X,mundo,vp);
	yw = yVp2Mundo(Y,mundo,vp);

	if(insere){
		if(Button == mbLeft){
			pol.pontos.push_back(Ponto(xw,yw));
			pol.desenha(Image1->Canvas, mundo, vp, tipoReta);
		} else{
			insere = false;
			pol.id = contaId++;
			pol.tipo = 'N';
			display.poligonos.push_back(pol); //push_back passa como valor e nao referencia
			pol.pontos.clear();
			display.toString(LBpoligonos);
		}
	}
	else
	ShowMessage("Clique no botao para inserir um novo poligono");


}
//---------------------------------------------------------------------------
void __fastcall TFprincipal::LBpoligonosClick(TObject *Sender)
{
	display.poligonos[LBpoligonos->ItemIndex].mostra(LBpontos);

}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::CriaPoligonoClick(TObject *Sender)
{
	insere = true;
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::CriaCirculoClick(TObject *Sender)
{

	int r = 150;
	DesenhaCircunferencia(250, 250, r);   // mando como VP
	pol.desenha(Image1->Canvas, mundo, vp, 2);

	pol.id = contaId++;
	pol.tipo = 'C';
	display.poligonos.push_back(pol);
	pol.pontos.clear();
	display.toString(LBpoligonos);
	//display.desenha(Image1->Canvas, mundo, vp, tipoReta);


}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::RgTipoRetaClick(TObject *Sender)
{
	tipoReta = RgTipoReta->ItemIndex;
}
//---------------------------------------------------------------------------

void TFprincipal::DesenhaCircunferencia(int xc, int yc, int r){

	double xw,yw;
	xw = xVp2Mundo(xc,mundo,vp);
	yw = yVp2Mundo(yc,mundo,vp);

	int x,y,p;
	x = xw;
	y = yw + r;

	pol.pontos.push_back(Ponto(xw,yw));
	pol.pontos.push_back(Ponto(x,y));

	p = 1-r;

	while(x<y){
		x++;
		if(p>0)
			y--;

		if (p<0)
			p += 2 * x + 1;
		else
			p += 2 * (x-y) + 1;

		pol.pontos.push_back(Ponto(x,y));
		pol.pontos.push_back(Ponto(-x,y));
		pol.pontos.push_back(Ponto(x,-y));
		pol.pontos.push_back(Ponto(-x,-y));

		pol.pontos.push_back(Ponto(y,x));
		pol.pontos.push_back(Ponto(y,-x));
		pol.pontos.push_back(Ponto(-y,x));
		pol.pontos.push_back(Ponto(-y,-x));
	}
}
//-------
void __fastcall TFprincipal::BFromFieldXYClick(TObject *Sender)
{
	display.poligonos[LBpoligonos->ItemIndex].Translada(StrToFloat(FieldX->Text),StrToFloat(FieldY->Text));
	display.desenha(Image1->Canvas, mundo, vp, tipoReta);
}
//---------------------------------------------------------------------------
void __fastcall TFprincipal::BtnEdXYClick(TObject *Sender)
{
	mundo.xmin = StrToFloat(EdXMin->Text);
	mundo.ymin = StrToFloat(EdYMin->Text);
	mundo.xmax = StrToFloat(EdXMax->Text);
	mundo.ymax = StrToFloat(EdYMax->Text);
	atualizaDisplay();
}
//---------------------------------------------------------------------------
void __fastcall TFprincipal::BtnEscalonarXYClick(TObject *Sender)
{
	display.poligonos[LBpoligonos->ItemIndex].Escala(StrToFloat(EdEscalaX->Text),
	StrToFloat(EdEscalaY->Text));
	display.desenha(Image1->Canvas, mundo, vp, tipoReta);
}
//---------------------------------------------------------------------------
void __fastcall TFprincipal::BtnRotacionarClick(TObject *Sender)
{
	display.poligonos[LBpoligonos->ItemIndex].Rotaciona(StrToFloat(EdRotacao->Text));
	display.desenha(Image1->Canvas, mundo, vp, tipoReta);
}
//---------------------------------------------------------------------------
void __fastcall TFprincipal::RefletirXClick(TObject *Sender)
{
	display.poligonos[LBpoligonos->ItemIndex].Reflete(-1,1);
	display.desenha(Image1->Canvas, mundo, vp, tipoReta);
}
//---------------------------------------------------------------------------
void __fastcall TFprincipal::RefletirYClick(TObject *Sender)
{
	display.poligonos[LBpoligonos->ItemIndex].Reflete(1,-1);
	display.desenha(Image1->Canvas, mundo, vp, tipoReta);
}
//---------------------------------------------------------------------------
void __fastcall TFprincipal::RefletirXeYClick(TObject *Sender)
{
	display.poligonos[LBpoligonos->ItemIndex].Reflete(-1,-1);
	display.desenha(Image1->Canvas, mundo, vp, tipoReta);
}
//---------------------------------------------------------------------------
void __fastcall TFprincipal::BtnRotacionarHomogeneoClick(TObject *Sender)
{
   display.poligonos[LBpoligonos->ItemIndex].RotacionaHomogeneo(StrToFloat(EdRotacaoHomogenea->Text));
   display.desenha(Image1->Canvas, mundo, vp, tipoReta);
}
//---------------------------------------------------------------------------
void TFprincipal::atualizaDisplay(){

    display.poligonos[0].pontos[0].x = mundo.xmin;
	display.poligonos[0].pontos[1].x = mundo.xmax;
	display.poligonos[1].pontos[0].y = mundo.ymin;
	display.poligonos[1].pontos[1].y = mundo.ymax;
	display.desenha(Image1->Canvas, mundo, vp, tipoReta);
}
//------
void __fastcall TFprincipal::BtnUpClick(TObject *Sender)
{
	mundo.ymin += 10;
	mundo.ymax += 10;
	atualizaDisplay();
}
//---------------------------------------------------------------------------
void __fastcall TFprincipal::BtnLeftClick(TObject *Sender)
{
	mundo.xmin -= 10;
	mundo.xmax -= 10;
	atualizaDisplay();
}
//---------------------------------------------------------------------------
void __fastcall TFprincipal::BtnDownClick(TObject *Sender)
{
	mundo.ymin -= 10;
	mundo.ymax -= 10;
	atualizaDisplay();
}
//---------------------------------------------------------------------------
void __fastcall TFprincipal::BtnRightClick(TObject *Sender)
{
	mundo.xmin += 10;
	mundo.xmax += 10;
	atualizaDisplay();
}
//---------------------------------------------------------------------------
void __fastcall TFprincipal::BtnZoomInClick(TObject *Sender)
{
	mundo.xmin += 10;
	mundo.ymin += 10;
	mundo.xmax -= 10;
	mundo.ymax -= 10;
	atualizaDisplay();
}
//---------------------------------------------------------------------------
void __fastcall TFprincipal::BtnZoomOutClick(TObject *Sender)
{
	mundo.xmin -= 10;
	mundo.ymin -= 10;
	mundo.xmax += 10;
	mundo.ymax += 10;
	atualizaDisplay();
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::RgTipoCurvaClick(TObject *Sender)
{
	tipoCurva = RgTipoCurva->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TFprincipal::BtnCurvaClick(TObject *Sender)
{
	pol = display.poligonos[LBpoligonos->ItemIndex].DesenhaCurva(tipoCurva);
	pol.id = contaId++;
	pol.tipo = 'N';
	display.poligonos.push_back(pol);
	pol.pontos.clear();
	display.toString(LBpoligonos);
	atualizaDisplay();
}
//---------------------------------------------------------------------------

