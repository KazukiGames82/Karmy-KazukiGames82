;----------------------------------------------------
; Styles
;----------------------------------------------------

[Karmy-KazukiGames82.Style]
ImageAlpha=0
W=((((#TopHeight#+#TopBarIconHOffset#)*1.5)-((#TopHeight#+#TopBarIconHOffset#)*1.5)%1)*([#NetworkStatusVar]<>1?1:[#Karmy_Setting_Show_Icon])+([Karmy_KazukiGames82_String:W]+((((#TopHeight#+#TopBarIconHOffset#)*1.5)/3.5)-(((#TopHeight#+#TopBarIconHOffset#)*1.5)/3.5)%1)*[#Karmy_Setting_Show_Icon])*[#Karmy_Setting_Show_Text]*([#NetworkStatusVar]<>1?0:1))

[Karmy_KazukiGames82_Style]
X=[#SideAppSlotXPos[#SideAppPosCustomApp[#Karmy-KazukiGames82]]]
MouseOverAction=
MouseLeaveAction=
LeftMouseDownAction=
RightMouseDownAction=
LeftMouseUpAction=
Container=SystemTrayContainer
Group=CustomApp[#Karmy-KazukiGames82]Sys | SysTray | Buttons00 | AppButton[#CustomApp[#Karmy-KazukiGames82]] | CustomAppButton | Karmy-KazukiGames82
DynamicVariables=1

; ;----------------------------------------------------
; ; Meters
; ;----------------------------------------------------

[Karmy_KazukiGames82_String]
Meter=String
MeterStyle=InfoStyle | Karmy_KazukiGames82_Style
StringAlign=LeftCenter
FontColor=#TopBarFontColor1#,#TopBarTitleOpacity#
Padding=(((#TopBarSysTextWPadding#*1.5)-(#TopBarSysTextWPadding#*1.5)%1)*(1-[#Karmy_Setting_Show_Icon])),#TopBarSysTextYPadding#,(((#TopBarSysTextWPadding#*1.5)-(#TopBarSysTextWPadding#*1.5)%1)*(1-[#Karmy_Setting_Show_Icon])),0
X=([#SideAppSlotXPos[#SideAppPosCustomApp[#Karmy-KazukiGames82]]]+(((#TopHeight#+#TopBarIconHOffset#)*1.5)-((#TopHeight#+#TopBarIconHOffset#)*1.5)%1)*[#Karmy_Setting_Show_Icon])
Y=((#TopBarTextYOffset#+#TopHeight#/2)-((#TopBarTextYOffset#+#TopHeight#/2)%1))
Text="[#Karmy___TopBar_Count_[#Karmy___Reddit_Connected]_[#Karmy___Reddit_Status]]"
Hidden=([#Karmy_Setting_Show_Text]=0?1:([#NetworkStatusVar]<>1?1:0))

[Karmy_KazukiGames82_Icon]
Meter=Image
MeterStyle=InfoStyle | Karmy_KazukiGames82_Style
ImageName="#SKINSPATH#Droptop Community Apps\Apps\Karmy-KazukiGames82\Button\Medium\Button[#TopIconShadows[#TopBarFontShadow][#ChamLum1][#LockTopBarShadow[#LockTopBarShadowNum]]].png"
ImageTint=#TopBarFontColor1#,#TopBarTitleOpacity#
ImageAlpha=(#TopBarTitleOpacity#*([#NetworkStatusVar]<>1?0.5:[#Karmy_Setting_Show_Icon]))
Padding=#SysIconPadding#
Y=0
W=(((#TopHeight#+#TopBarIconHOffset#)*1.5)-((#TopHeight#+#TopBarIconHOffset#)*1.5)%1)
H=(#TopHeight#+#TopBarIconHOffset#)
