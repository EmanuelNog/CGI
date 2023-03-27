//---------------------------------------------------------------------------

#ifndef uPrincipalH
#define uPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>

#include "uJanela.h"
//---------------------------------------------------------------------------
class TFprincipal : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TButton *CriaPoligono;
	TImage *Image1;
	TLabel *Label3;
	TListBox *LBpoligonos;
	TListBox *LBpontos;
	TLabel *Label4;
	TLabel *Label5;
	TButton *CriaCirculo;
	TRadioGroup *RgTipoReta;
	TEdit *FieldX;
	TEdit *FieldY;
	TButton *BFromFieldXY;
	TEdit *EdXMin;
	TEdit *EdXMax;
	TEdit *EdYMin;
	TEdit *EdYMax;
	TButton *BtnEdXY;
	TLabel *Label6;
	TLabel *Mundo;
	TEdit *EdEscalaX;
	TEdit *EdEscalaY;
	TButton *BtnEscalonarXY;
	TLabel *Escalonar;
	TButton *BtnRotacionar;
	TLabel *Label7;
	TButton *RefletirX;
	TLabel *Rotacao;
	TEdit *EdRotacao;
	TButton *RefletirY;
	TButton *RefletirXeY;
	TLabel *Label8;
	TEdit *EdRotacaoHomogenea;
	TButton *BtnRotacionarHomogeneo;
	TButton *BtnUp;
	TButton *BtnDown;
	TButton *BtnLeft;
	TButton *BtnRight;
	TButton *BtnZoomIn;
	TButton *BtnZoomOut;
	TButton *BtnCurva;
	TRadioGroup *RgTipoCurva;
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall LBpoligonosClick(TObject *Sender);
	void __fastcall CriaPoligonoClick(TObject *Sender);
	void __fastcall CriaCirculoClick(TObject *Sender);
	void __fastcall RgTipoRetaClick(TObject *Sender);
	void __fastcall BFromFieldXYClick(TObject *Sender);
	void __fastcall BtnEdXYClick(TObject *Sender);
	void __fastcall BtnEscalonarXYClick(TObject *Sender);
	void __fastcall BtnRotacionarClick(TObject *Sender);
	void __fastcall RefletirXClick(TObject *Sender);
	void __fastcall RefletirYClick(TObject *Sender);
	void __fastcall RefletirXeYClick(TObject *Sender);
	void __fastcall BtnRotacionarHomogeneoClick(TObject *Sender);
	void __fastcall BtnUpClick(TObject *Sender);
	void __fastcall BtnLeftClick(TObject *Sender);
	void __fastcall BtnDownClick(TObject *Sender);
	void __fastcall BtnRightClick(TObject *Sender);
	void __fastcall BtnZoomInClick(TObject *Sender);
	void __fastcall BtnZoomOutClick(TObject *Sender);
	void __fastcall RgTipoCurvaClick(TObject *Sender);
	void __fastcall BtnCurvaClick(TObject *Sender);



private:	// User declarations
	void DesenhaCircunferencia(int xc, int yc, int r);
	void atualizaDisplay();

public:		// User declarations
	__fastcall TFprincipal(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TFprincipal *Fprincipal;
//---------------------------------------------------------------------------
#endif
