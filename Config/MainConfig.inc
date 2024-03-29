;----------------------------------------------------
; # # DO NOT REMOVE ANYTHING FROM THIS SECTION # # # 
;----------------------------------------------------

[Rainmeter]
Update=-1
OnRefreshAction=[!Delay 100][!UpdateMeter *][!Redraw]

[Variables]
CustomAppPosition=7

BoxHeight1=0
BoxHeight2=0
BoxHeight3=0
BoxHeight4=0
BoxHeight5=0

@IncludeCommunityAppMeters=#SKINSPATH#Droptop\@Resources\Meters\CommunityAppMeters.inc

OpenFolder=[!Hide "#CURRENTCONFIG#\Folder"][!ActivateConfig "#CURRENTCONFIG#\Folder" "Folder[#[#*CURRENTSECTION*]].ini"][!Move ([#CURRENTCONFIGX]-#DropdownSubMenuWidth#-#DropdownSubMenuXOffset#+[#*SysAppMenuXOffset*]+1) ([#CURRENTCONFIGY]+[1Icon:Y]-#DropdownItemYOffset#-(#DropdownStrokeWidth#-(#DropdownStrokeWidth#%1))-1) "#CURRENTCONFIG#\Folder"][!#Show# "#CURRENTCONFIG#\Folder"]

Action1=[!WriteKeyValue Variables FolderNumber [#[#*CURRENTSECTION*]] "#CURRENTPATH#Folder\Config\FolderConfig.inc"][!CommandMeasure MeasureActionTimer "Stop 1"][#*OpenFolder*]

;----------------------------------------------------
; # # BEGIN EDITING BELOW # # # # # # # # # # # # # #
;----------------------------------------------------

[InfoStyle]
FontColor=[#Karmy___Banner_Exists_Foreground_Color_[#Karmy___Banner_Exists]],#DropdownItemOpacity#
StringAlign=[#Karmy___Snoovatar_Exists_Align_[#Karmy___Snoovatar_Exists]]Center
Padding=((20*#DroptopSize#)-(20*#DroptopSize#)%1),#DropdownItemPaddingY#,((20*#DroptopSize#)-(20*#DroptopSize#)%1),(#DropdownItemPaddingY#*-1)
X=r
W=([#CURRENTCONFIGWIDTH]-((20*#DroptopSize#)-(20*#DroptopSize#)%1)*2)
MouseOverAction=
MouseLeaveAction=

[IconStyle]
ImageTint=255,255,255,255
W=(#IconW#+(12*#DroptopSize#)-(12*#DroptopSize#)%1)
H=(#IconW#+(12*#DroptopSize#)-(12*#DroptopSize#)%1)

[ArrowStyleB]
Hidden=1

[BoxStyle]
Hidden=1

[TextStyle]

;-----------------------------------------

[Group0Style]
PreserveAspectRatio=2
Container=Group0_Container
DynamicVariables=1
Group=Group0

[Group1Style]
PreserveAspectRatio=1
Container=Group1_Container
DynamicVariables=1

;-----------------------------------------

[Account_About_Prefixed_UnPrefixed]
Measure=String
String=#Karmy___Account_About_Prefixed#
Substitute="u/":""
DynamicVariables=1
Disabled=(#Karmy___Reddit_Connected#=0?1:(1-#Karmy___Reddit_Status#))

;-----------------------------------------

[1]
MeterStyle=#DefaultMeterStyle#

[2]
MeterStyle=#DefaultMeterStyle#

[3]
MeterStyle=#DefaultMeterStyle#

[4]
MeterStyle=#DefaultMeterStyle#

[5]
MeterStyle=#DefaultMeterStyle#

[6]
MeterStyle=#DefaultMeterStyle#

[7]
MeterStyle=#DefaultMeterStyle#

[8]
MeterStyle=#DefaultMeterStyle#

[9]
MeterStyle=#DefaultMeterStyle#

[10]
MeterStyle=#DefaultMeterStyle#

;-----------------------------------------

[1Icon]
MeterStyle=IconStyle

[2Icon]
MeterStyle=IconStyle

[3Icon]
MeterStyle=IconStyle

[4Icon]
MeterStyle=IconStyle

[5Icon]
MeterStyle=IconStyle

[6Icon]
MeterStyle=IconStyle

[7Icon]
MeterStyle=IconStyle

[8Icon]
MeterStyle=IconStyle

[9Icon]
MeterStyle=IconStyle

[10Icon]
MeterStyle=IconStyle

;-----------------------------------------

[1Arrow]
MeterStyle=ArrowStyleB

[2Arrow]
MeterStyle=ArrowStyleB

[3Arrow]
MeterStyle=ArrowStyleB

[4Arrow]
MeterStyle=ArrowStyleB

[5Arrow]
MeterStyle=ArrowStyleB

[6Arrow]
MeterStyle=ArrowStyleB

[7Arrow]
MeterStyle=ArrowStyleB

[8Arrow]
MeterStyle=ArrowStyleB

[9Arrow]
MeterStyle=ArrowStyleB

[10Arrow]
MeterStyle=ArrowStyleB

;----------------------------------------------------

[Box1]
MeterStyle=BoxStyle

[Box2]
MeterStyle=BoxStyle

[Box3]
MeterStyle=BoxStyle

[Box4]
MeterStyle=BoxStyle

[Box5]
MeterStyle=BoxStyle
