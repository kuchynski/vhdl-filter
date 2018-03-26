object MainForm: TMainForm
  Left = 224
  Top = 114
  Width = 718
  Height = 594
  Caption = #1060#1080#1083#1100#1090#1088#1072#1094#1080#1103
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 80
    Top = 64
    Width = 65
    Height = 13
    Caption = #1088#1072#1079#1088#1103#1076#1085#1086#1089#1090#1100
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 33
    Width = 710
    Height = 507
    ActivePage = TabSheet1
    Align = alClient
    TabIndex = 0
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
      object Label2: TLabel
        Left = 8
        Top = 120
        Width = 87
        Height = 13
        Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090#1099' b'
      end
      object Label5: TLabel
        Left = 8
        Top = 168
        Width = 87
        Height = 13
        Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090#1099' a'
      end
      object Label6: TLabel
        Left = 8
        Top = 187
        Width = 6
        Height = 13
        Caption = '1'
      end
      object Label14: TLabel
        Left = 8
        Top = 92
        Width = 39
        Height = 13
        Caption = #1056#1072#1079#1084#1077#1088
      end
      object GroupBox1: TGroupBox
        Left = 0
        Top = 0
        Width = 129
        Height = 81
        Caption = #1056#1072#1079#1088#1103#1076#1085#1086#1089#1090#1100
        TabOrder = 0
        object Label3: TLabel
          Left = 8
          Top = 24
          Width = 43
          Height = 13
          Caption = #1084#1072#1085#1090#1080#1089#1072
        end
        object Label4: TLabel
          Left = 72
          Top = 24
          Width = 42
          Height = 13
          Caption = #1087#1086#1088#1103#1076#1086#1082
        end
        object CSpinEditMantisa: TCSpinEdit
          Left = 8
          Top = 40
          Width = 49
          Height = 22
          MaxValue = 32
          MinValue = 8
          TabOrder = 0
          Value = 8
          OnChange = CSpinEditMantisaChange
        end
        object CSpinEditPor: TCSpinEdit
          Left = 72
          Top = 40
          Width = 49
          Height = 22
          MaxValue = 30
          MinValue = 6
          TabOrder = 1
          Value = 8
          OnChange = CSpinEditMantisaChange
        end
      end
      object EditB: TEdit
        Left = 8
        Top = 136
        Width = 689
        Height = 21
        TabOrder = 1
        OnChange = CSpinEditMantisaChange
      end
      object EditA: TEdit
        Left = 8
        Top = 184
        Width = 689
        Height = 21
        TabOrder = 2
        OnChange = CSpinEditMantisaChange
      end
      object GroupBox2: TGroupBox
        Left = 0
        Top = 216
        Width = 553
        Height = 137
        Caption = #1043#1088#1072#1092#1080#1082
        TabOrder = 3
        object Label7: TLabel
          Left = 8
          Top = 24
          Width = 122
          Height = 13
          Caption = #1063#1072#1089#1090#1086#1090#1072' '#1076#1080#1089#1082#1088#1077#1090#1080#1079#1072#1094#1080#1080
        end
        object Label8: TLabel
          Left = 232
          Top = 24
          Width = 65
          Height = 13
          Caption = #1043#1072#1088#1084#1086#1085#1080#1082#1072' 1'
        end
        object Label9: TLabel
          Left = 304
          Top = 24
          Width = 65
          Height = 13
          Caption = #1043#1072#1088#1084#1086#1085#1080#1082#1072' 2'
        end
        object Label10: TLabel
          Left = 376
          Top = 24
          Width = 65
          Height = 13
          Caption = #1043#1072#1088#1084#1086#1085#1080#1082#1072' 3'
        end
        object Label11: TLabel
          Left = 168
          Top = 50
          Width = 42
          Height = 13
          Caption = #1063#1072#1089#1090#1086#1090#1072
        end
        object Label12: TLabel
          Left = 168
          Top = 74
          Width = 55
          Height = 13
          Caption = #1040#1084#1087#1083#1080#1090#1091#1076#1072
        end
        object Label13: TLabel
          Left = 168
          Top = 100
          Width = 54
          Height = 13
          Caption = #1057#1084#1077#1097#1077#1085#1080#1077
        end
        object EditFd: TEdit
          Left = 8
          Top = 40
          Width = 65
          Height = 21
          TabOrder = 0
          OnChange = CSpinEditMantisaChange
        end
        object EditFr1: TEdit
          Left = 232
          Top = 48
          Width = 57
          Height = 21
          TabOrder = 1
          OnChange = CSpinEditMantisaChange
        end
        object EditFr2: TEdit
          Left = 304
          Top = 48
          Width = 57
          Height = 21
          TabOrder = 2
          OnChange = CSpinEditMantisaChange
        end
        object EditFr3: TEdit
          Left = 376
          Top = 48
          Width = 57
          Height = 21
          TabOrder = 3
          OnChange = CSpinEditMantisaChange
        end
        object EditA3: TEdit
          Left = 376
          Top = 72
          Width = 57
          Height = 21
          TabOrder = 4
          OnChange = CSpinEditMantisaChange
        end
        object EditA2: TEdit
          Left = 304
          Top = 72
          Width = 57
          Height = 21
          TabOrder = 5
          OnChange = CSpinEditMantisaChange
        end
        object EditA1: TEdit
          Left = 232
          Top = 72
          Width = 57
          Height = 21
          TabOrder = 6
          OnChange = CSpinEditMantisaChange
        end
        object EditSm: TEdit
          Left = 232
          Top = 100
          Width = 201
          Height = 21
          TabOrder = 7
          OnChange = CSpinEditMantisaChange
        end
      end
      object CSpinEditKol: TCSpinEdit
        Left = 56
        Top = 88
        Width = 49
        Height = 22
        MaxValue = 32
        MinValue = 2
        TabOrder = 4
        Value = 8
        OnChange = CSpinEditMantisaChange
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1043#1088#1072#1092#1080#1082
      ImageIndex = 1
      object Panel1: TPanel
        Left = 0
        Top = 409
        Width = 702
        Height = 70
        Align = alClient
        BevelInner = bvRaised
        TabOrder = 0
        object ButIn: TButton
          Left = 424
          Top = 32
          Width = 57
          Height = 25
          Caption = #1042#1093#1086#1076
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clTeal
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = ButInClick
        end
        object ButOut: TButton
          Left = 552
          Top = 32
          Width = 57
          Height = 25
          Caption = #1042#1099#1093#1086#1076
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clYellow
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = ButOutClick
        end
        object ScrollBar1: TScrollBar
          Left = 0
          Top = 9
          Width = 689
          Height = 15
          LargeChange = 500
          Max = 9300
          Min = 1
          PageSize = 0
          Position = 1
          SmallChange = 100
          TabOrder = 2
          OnChange = ScrollBar1Change
        end
        object ButMidle: TButton
          Left = 488
          Top = 32
          Width = 57
          Height = 25
          Caption = #1056#1057
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          OnClick = ButMidleClick
        end
      end
      object PageControl2: TPageControl
        Left = 0
        Top = 0
        Width = 702
        Height = 409
        ActivePage = TabSheet5
        Align = alTop
        TabIndex = 0
        TabOrder = 1
        object TabSheet5: TTabSheet
          Caption = #1060#1091#1085#1082#1094#1080#1103
          object image: TImage
            Left = 0
            Top = -8
            Width = 512
            Height = 337
          end
          object Label15: TLabel
            Left = 8
            Top = 352
            Width = 38
            Height = 13
            Caption = #1057#1078#1072#1090#1080#1077
          end
          object Label16: TLabel
            Left = 379
            Top = 352
            Width = 3
            Height = 13
          end
          object TrackBar1: TTrackBar
            Left = 48
            Top = 344
            Width = 313
            Height = 25
            Max = 100
            Min = 1
            Orientation = trHorizontal
            Frequency = 1
            Position = 1
            SelEnd = 0
            SelStart = 0
            TabOrder = 0
            TickMarks = tmTopLeft
            TickStyle = tsAuto
            OnChange = TrackBar1Change
          end
        end
        object TabSheet6: TTabSheet
          Caption = #1057#1087#1077#1082#1090#1088
          ImageIndex = 1
          object imagefft: TImage
            Left = 0
            Top = 8
            Width = 512
            Height = 337
          end
          object Label17: TLabel
            Left = 8
            Top = 360
            Width = 38
            Height = 13
            Caption = #1057#1078#1072#1090#1080#1077
          end
          object Label20: TLabel
            Left = 387
            Top = 352
            Width = 3
            Height = 13
          end
          object TrackBar2: TTrackBar
            Left = 48
            Top = 352
            Width = 313
            Height = 25
            Max = 50
            Min = -50
            Orientation = trHorizontal
            Frequency = 1
            Position = 1
            SelEnd = 0
            SelStart = 0
            TabOrder = 0
            TickMarks = tmTopLeft
            TickStyle = tsAuto
            OnChange = TrackBar2Change
          end
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'VHDL'
      ImageIndex = 2
      object MemoVhdl: TMemo
        Left = 0
        Top = 0
        Width = 702
        Height = 479
        Align = alClient
        Lines.Strings = (
          '')
        ReadOnly = True
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 710
    Height = 33
    Align = alTop
    TabOrder = 1
    object ButNew: TBitBtn
      Left = 8
      Top = 4
      Width = 25
      Height = 25
      Hint = #1057#1086#1079#1076#1072#1090#1100
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnClick = M_newClick
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF0033333333B333
        333B33FF33337F3333F73BB3777BB7777BB3377FFFF77FFFF77333B000000000
        0B3333777777777777333330FFFFFFFF07333337F33333337F333330FFFFFFFF
        07333337F33333337F333330FFFFFFFF07333337F33333337F333330FFFFFFFF
        07333FF7F33333337FFFBBB0FFFFFFFF0BB37777F3333333777F3BB0FFFFFFFF
        0BBB3777F3333FFF77773330FFFF000003333337F333777773333330FFFF0FF0
        33333337F3337F37F3333330FFFF0F0B33333337F3337F77FF333330FFFF003B
        B3333337FFFF77377FF333B000000333BB33337777777F3377FF3BB3333BB333
        3BB33773333773333773B333333B3333333B7333333733333337}
      NumGlyphs = 2
    end
    object ButLoad: TBitBtn
      Left = 32
      Top = 4
      Width = 25
      Height = 25
      Hint = #1054#1090#1082#1088#1099#1090#1100
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      OnClick = M_openClick
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF0033333333B333
        333B33FF33337F3333F73BB3777BB7777BB3377FFFF77FFFF77333B000000000
        0B3333777777777777333330FFFFFFFF07333337F33333337F333330FFFFFFFF
        07333337F3FF3FFF7F333330F00F000F07333337F77377737F333330FFFFFFFF
        07333FF7F3FFFF3F7FFFBBB0F0000F0F0BB37777F7777373777F3BB0FFFFFFFF
        0BBB3777F3FF3FFF77773330F00F000003333337F773777773333330FFFF0FF0
        33333337F3FF7F37F3333330F08F0F0B33333337F7737F77FF333330FFFF003B
        B3333337FFFF77377FF333B000000333BB33337777777F3377FF3BB3333BB333
        3BB33773333773333773B333333B3333333B7333333733333337}
      NumGlyphs = 2
    end
    object ButSave: TBitBtn
      Left = 56
      Top = 4
      Width = 25
      Height = 25
      Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      Enabled = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      OnClick = M_saveClick
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333330070
        7700333333337777777733333333008088003333333377F73377333333330088
        88003333333377FFFF7733333333000000003FFFFFFF77777777000000000000
        000077777777777777770FFFFFFF0FFFFFF07F3333337F3333370FFFFFFF0FFF
        FFF07F3FF3FF7FFFFFF70F00F0080CCC9CC07F773773777777770FFFFFFFF039
        99337F3FFFF3F7F777F30F0000F0F09999937F7777373777777F0FFFFFFFF999
        99997F3FF3FFF77777770F00F000003999337F773777773777F30FFFF0FF0339
        99337F3FF7F3733777F30F08F0F0337999337F7737F73F7777330FFFF0039999
        93337FFFF7737777733300000033333333337777773333333333}
      NumGlyphs = 2
    end
    object ButRun: TBitBtn
      Left = 120
      Top = 4
      Width = 25
      Height = 25
      Hint = #1050#1086#1084#1087#1080#1083#1103#1094#1080#1103' / '#1083#1080#1085#1082#1086#1074#1082#1072' (F9)'
      ParentShowHint = False
      ShowHint = True
      TabOrder = 3
      OnClick = ButRunClick
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        33333FF3333333333333448333333333333388FFF33333333333844483333333
        333338883FF3333333333444448333333333383F883FF3333333334444448333
        33333383F3883FF3333333844444448333333338F333883FF333333444444444
        833333383F3333883FF3333344444444448333333FFFFFFF88FF33333CCCCCCC
        CCCC88888888888833883333CCCCCCCCCC3333338333333F8833333CCCCCCCCC
        33333338F3333F883333333CCCCCCC3333333338333F8833333333CCCCCC3333
        333333833F88333333333CCCCC333333333338FF8833333333333CCC33333333
        33333888333333333333CC333333333333338833333333333333}
      NumGlyphs = 2
    end
  end
  object MainMenu1: TMainMenu
    BiDiMode = bdLeftToRight
    ParentBiDiMode = False
    Left = 312
    object M_file: TMenuItem
      Caption = #1060#1072#1081#1083
      object M_new: TMenuItem
        Caption = #1053#1086#1074#1099#1081
        ShortCut = 16462
        OnClick = M_newClick
      end
      object M_open: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100
        ShortCut = 16463
        OnClick = M_openClick
      end
      object M_save: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        ShortCut = 16467
        OnClick = M_saveClick
      end
      object M_save_as: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082
        OnClick = M_save_asClick
      end
      object M_exit: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = M_exitClick
      end
    end
    object M_help: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
      object M_Abuot: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = M_AbuotClick
      end
    end
  end
  object OpenDialog: TOpenDialog
    Filter = '*.fil|*.fil'
    Left = 184
    Top = 8
  end
  object SaveDialog: TSaveDialog
    Filter = '*.fil|*.fil'
    Left = 224
    Top = 8
  end
end
