object Fprincipal: TFprincipal
  Left = 0
  Top = 0
  Caption = 'Formulario Principal'
  ClientHeight = 648
  ClientWidth = 1074
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  PixelsPerInch = 106
  TextHeight = 14
  object Label1: TLabel
    Left = 553
    Top = 552
    Width = 35
    Height = 14
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 88
    Top = 552
    Width = 35
    Height = 14
    Caption = 'Label2'
  end
  object Label3: TLabel
    Left = 552
    Top = 584
    Width = 35
    Height = 14
    Caption = 'Label3'
  end
  object Label4: TLabel
    Left = 776
    Top = 44
    Width = 51
    Height = 14
    Caption = 'Poligonos'
  end
  object Label5: TLabel
    Left = 903
    Top = 44
    Width = 38
    Height = 14
    Caption = 'Pontos'
  end
  object Label6: TLabel
    Left = 613
    Top = 278
    Width = 57
    Height = 14
    Caption = 'Translacao'
  end
  object Mundo: TLabel
    Left = 613
    Top = 409
    Width = 37
    Height = 14
    Caption = 'Mundo'
  end
  object Escalonar: TLabel
    Left = 776
    Top = 276
    Width = 50
    Height = 14
    Caption = 'Escalonar'
  end
  object Label7: TLabel
    Left = 920
    Top = 276
    Width = 46
    Height = 14
    Caption = 'Reflexao'
  end
  object Rotacao: TLabel
    Left = 776
    Top = 409
    Width = 44
    Height = 14
    Caption = 'Rotacao'
  end
  object Label8: TLabel
    Left = 912
    Top = 409
    Width = 114
    Height = 14
    Caption = 'Rotacao Homogenea'
  end
  object Panel1: TPanel
    Left = 88
    Top = 24
    Width = 508
    Height = 508
    Margins.Left = 1
    Margins.Top = 1
    Margins.Right = 1
    Margins.Bottom = 1
    TabOrder = 0
    object Image1: TImage
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 500
      Height = 500
      Align = alClient
      IncrementalDisplay = True
      OnMouseDown = Image1MouseDown
      OnMouseMove = Image1MouseMove
      ExplicitLeft = 1
      ExplicitWidth = 497
      ExplicitHeight = 497
    end
  end
  object CriaPoligono: TButton
    Left = 624
    Top = 176
    Width = 75
    Height = 25
    Caption = 'Cria Poligono'
    TabOrder = 1
    OnClick = CriaPoligonoClick
  end
  object LBpoligonos: TListBox
    Left = 776
    Top = 64
    Width = 121
    Height = 97
    ItemHeight = 14
    TabOrder = 2
    OnClick = LBpoligonosClick
  end
  object LBpontos: TListBox
    Left = 903
    Top = 64
    Width = 121
    Height = 97
    ItemHeight = 14
    TabOrder = 3
  end
  object CriaCirculo: TButton
    Left = 624
    Top = 216
    Width = 75
    Height = 25
    Caption = 'Cria Circulo'
    TabOrder = 4
    OnClick = CriaCirculoClick
  end
  object RgTipoReta: TRadioGroup
    Left = 613
    Top = 56
    Width = 157
    Height = 105
    Caption = 'Tipo da Reta'
    TabOrder = 5
    OnClick = RgTipoRetaClick
  end
  object FieldX: TEdit
    Left = 613
    Top = 298
    Width = 121
    Height = 22
    TabOrder = 6
    Text = '0'
  end
  object FieldY: TEdit
    Left = 613
    Top = 326
    Width = 121
    Height = 22
    TabOrder = 7
    Text = '0'
  end
  object BFromFieldXY: TButton
    Left = 637
    Top = 354
    Width = 75
    Height = 25
    Caption = 'BAM!!!'
    TabOrder = 8
    OnClick = BFromFieldXYClick
  end
  object EdXMin: TEdit
    Left = 610
    Top = 429
    Width = 71
    Height = 22
    TabOrder = 9
    Text = '-250'
  end
  object EdXMax: TEdit
    Left = 687
    Top = 429
    Width = 67
    Height = 22
    TabOrder = 10
    Text = '250'
  end
  object EdYMin: TEdit
    Left = 610
    Top = 457
    Width = 71
    Height = 22
    TabOrder = 11
    Text = '-250'
  end
  object EdYMax: TEdit
    Left = 687
    Top = 457
    Width = 67
    Height = 22
    TabOrder = 12
    Text = '250'
  end
  object BtnEdXY: TButton
    Left = 637
    Top = 485
    Width = 75
    Height = 25
    Caption = 'BUM !!'
    TabOrder = 13
    OnClick = BtnEdXYClick
  end
  object EdEscalaX: TEdit
    Left = 776
    Top = 296
    Width = 97
    Height = 22
    TabOrder = 14
    Text = '1'
  end
  object EdEscalaY: TEdit
    Left = 776
    Top = 326
    Width = 97
    Height = 22
    TabOrder = 15
    Text = '1'
  end
  object BtnEscalonarXY: TButton
    Left = 776
    Top = 354
    Width = 75
    Height = 25
    Caption = 'Bleu !!'
    TabOrder = 16
    OnClick = BtnEscalonarXYClick
  end
  object BtnRotacionar: TButton
    Left = 776
    Top = 457
    Width = 75
    Height = 25
    Caption = 'Rotate'
    TabOrder = 17
    OnClick = BtnRotacionarClick
  end
  object RefletirX: TButton
    Left = 920
    Top = 294
    Width = 89
    Height = 25
    Caption = 'Refletir X'
    TabOrder = 18
    OnClick = RefletirXClick
  end
  object EdRotacao: TEdit
    Left = 776
    Top = 429
    Width = 97
    Height = 22
    TabOrder = 19
  end
  object RefletirY: TButton
    Left = 920
    Top = 325
    Width = 89
    Height = 25
    Caption = 'Refletir Y'
    TabOrder = 20
    OnClick = RefletirYClick
  end
  object RefletirXeY: TButton
    Left = 920
    Top = 356
    Width = 89
    Height = 25
    Caption = 'Refletir X e Y'
    TabOrder = 21
    OnClick = RefletirXeYClick
  end
  object EdRotacaoHomogenea: TEdit
    Left = 912
    Top = 429
    Width = 121
    Height = 22
    TabOrder = 22
  end
  object BtnRotacionarHomogeneo: TButton
    Left = 912
    Top = 457
    Width = 75
    Height = 25
    Caption = 'Rotacionar'
    TabOrder = 23
    OnClick = BtnRotacionarHomogeneoClick
  end
  object BtnUp: TButton
    Left = 660
    Top = 529
    Width = 52
    Height = 33
    Caption = 'Up'
    TabOrder = 24
    OnClick = BtnUpClick
  end
  object BtnDown: TButton
    Left = 660
    Top = 607
    Width = 52
    Height = 33
    Caption = 'Down'
    TabOrder = 25
    OnClick = BtnDownClick
  end
  object BtnLeft: TButton
    Left = 613
    Top = 568
    Width = 52
    Height = 33
    Caption = 'Left'
    TabOrder = 26
    OnClick = BtnLeftClick
  end
  object BtnRight: TButton
    Left = 702
    Top = 568
    Width = 52
    Height = 33
    Caption = 'Right'
    TabOrder = 27
    OnClick = BtnRightClick
  end
  object BtnZoomIn: TButton
    Left = 768
    Top = 553
    Width = 52
    Height = 33
    Caption = 'Zoom +'
    TabOrder = 28
    OnClick = BtnZoomInClick
  end
  object BtnZoomOut: TButton
    Left = 768
    Top = 592
    Width = 52
    Height = 33
    Caption = 'Zoom -'
    TabOrder = 29
    OnClick = BtnZoomOutClick
  end
  object BtnCurva: TButton
    Left = 754
    Top = 176
    Width = 73
    Height = 25
    Caption = 'Criar Curva'
    TabOrder = 30
    OnClick = BtnCurvaClick
  end
  object RgTipoCurva: TRadioGroup
    Left = 847
    Top = 167
    Width = 185
    Height = 105
    Caption = 'Tipo Curva'
    TabOrder = 31
    OnClick = RgTipoCurvaClick
  end
end
