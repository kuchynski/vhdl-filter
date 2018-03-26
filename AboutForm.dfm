object AboutBox: TAboutBox
  Left = 237
  Top = 552
  BorderStyle = bsDialog
  Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
  ClientHeight = 205
  ClientWidth = 298
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 281
    Height = 153
    BevelInner = bvRaised
    BevelOuter = bvLowered
    ParentColor = True
    TabOrder = 0
    object ProductName: TLabel
      Left = 48
      Top = 8
      Width = 225
      Height = 13
      Caption = #1055#1088#1086#1075#1088#1072#1084#1084#1072' '#1092#1080#1083#1100#1090#1088#1072#1094#1080#1080' '#1094#1080#1092#1088#1086#1074#1086#1075#1086' '#1089#1080#1075#1085#1072#1083#1072
      IsControl = True
    end
    object Version: TLabel
      Left = 48
      Top = 56
      Width = 159
      Height = 13
      Caption = #1042#1077#1088#1089#1080#1103' '#1084#1077#1078#1076#1091' '#1087#1077#1088#1074#1086#1081' '#1080' '#1074#1090#1086#1088#1086#1081
      IsControl = True
    end
    object Comments: TLabel
      Left = 112
      Top = 128
      Width = 60
      Height = 13
      Caption = #1052#1080#1085#1089#1082' 2006'
      WordWrap = True
      IsControl = True
    end
    object Label1: TLabel
      Left = 48
      Top = 80
      Width = 85
      Height = 13
      Caption = 'kuchynski@tut.by'
      WordWrap = True
      IsControl = True
    end
    object Label3: TLabel
      Left = 48
      Top = 24
      Width = 86
      Height = 13
      Caption = #1076#1083#1103' FPGA XILINX'
    end
  end
  object OKButton: TButton
    Left = 56
    Top = 172
    Width = 193
    Height = 25
    Caption = 'Ok'
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
end
