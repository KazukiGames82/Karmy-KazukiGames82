[Rainmeter]

[Variables]

;----------------------------------------------------
; # # ADD BACKGROUND PROCESSES BELOW # # # # # # # #
; # # Measures that run even when the app isn't open
;----------------------------------------------------
;----------------------------------------------------------------------
; Auxiliar Variables for apps state
HideAppWifi=0
;----------------------------------------------------------------------
Karmy___Settings_Loaded=0

Karmy___ConnectError_1_0=[!SetVariable Karmy___Reddit_Connected 0 "Droptop\DropdownBar"][!WriteKeyValue Variables Karmy___Reddit_Connected 0 "#KarmyWriteConfigPath#"]#Karmy___Update_Meters_TopBar_1#
Karmy___ConnectError_1_1=[!SetVariable Karmy___Reddit_Connected 0 "Droptop\DropdownBar"][!WriteKeyValue Variables Karmy___Reddit_Connected 0 "#KarmyWriteConfigPath#"][!SetVariable Karmy___Reddit_Connected 0 "#KarmyUpdateSettingsLoc#"][!UpdateMeter * "#KarmyUpdateSettingsLoc#"][!Redraw "#KarmyUpdateSettingsLoc#"]#Karmy___Update_Meters_TopBar_1#
Karmy___RegExpError_1_0=[!SetVariable Karmy___Reddit_Status 0 "Droptop\DropdownBar"][!WriteKeyValue Variables Karmy___Reddit_Status 0 "#KarmyWriteConfigPath#"]#Karmy___Update_Meters_TopBar_1#
Karmy___RegExpError_1_1=[!SetVariable Karmy___Reddit_Status 0 "Droptop\DropdownBar"][!WriteKeyValue Variables Karmy___Reddit_Status 0 "#KarmyWriteConfigPath#"][!SetVariable Karmy___Reddit_Status 0 "#KarmyUpdateSettingsLoc#"][!UpdateMeter * "#KarmyUpdateSettingsLoc#"][!Redraw "#KarmyUpdateSettingsLoc#"]#Karmy___Update_Meters_TopBar_1#
Karmy___Finish_1_0=[!SetVariable Karmy___Reddit_Connected 1 "Droptop\DropdownBar"][!WriteKeyValue Variables Karmy___Reddit_Connected 1 "#KarmyWriteConfigPath#"][!SetVariable Karmy___Reddit_Status 1 "Droptop\DropdownBar"][!WriteKeyValue Variables Karmy___Reddit_Status 1 "#KarmyWriteConfigPath#"][#Karmy___Update_Meters_TopBar_[#*Karmy_Setting_Show_Text*]]
Karmy___Finish_1_1=[!SetVariable Karmy___Reddit_Connected 1 "Droptop\DropdownBar"][!WriteKeyValue Variables Karmy___Reddit_Connected 1 "#KarmyWriteConfigPath#"][!SetVariable Karmy___Reddit_Status 1 "Droptop\DropdownBar"][!WriteKeyValue Variables Karmy___Reddit_Status 1 "#KarmyWriteConfigPath#"][!SetVariable Karmy___Reddit_Connected 1 "#KarmyUpdateSettingsLoc#"][!SetVariable Karmy___Reddit_Status 1 "#KarmyUpdateSettingsLoc#"][!UpdateMeter * "#KarmyUpdateSettingsLoc#"][!Redraw "#KarmyUpdateSettingsLoc#"][#Karmy___Update_Meters_TopBar_[#*Karmy_Setting_Show_Text*]]
Karmy___Update_0=
Karmy___Update_1=[!SetOption 8 Text "#*WeatherBox1A*# [Karmy___Measure_Updated_Time]" "#KarmyUpdateSettingsLoc#"][!UpdateMeter * "#KarmyUpdateSettingsLoc#"][!Redraw "#KarmyUpdateSettingsLoc#"]

;----------------------------------------------------------------------
; Example # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
; Updates the top bar when CPU temperature changes
; 
; UpdateDivider=10 rechecks the temperature every 10 seconds
; Recommended this number be no lower than 10 to prevent high CPU usage
;----------------------------------------------------------------------

[Karmy___Measure_Updated_Time]
Measure=Time
Format="#SettingsTimeFormat7B# #SettingsTimeFormat1B#"

[Karmy___Measure_Parent]
Measure=WebParser
Url=https://www.reddit.com/user/#Karmy___Username#/about.json
RegExp="(?siU).*"is_employee":(.*),(?(?=.*"banner_img").*"banner_img":(.*)",)(?(?=.*"title").*"title":(.*),)(?(?=.*"over_18").*"over_18":(.*),)(?(?=.*"icon_img").*"icon_img":(.*)",)(?(?=.*"display_name_prefixed").*"display_name_prefixed":(.*),)(?(?=.*"public_description").*"public_description":(.*),)(?(?=.*"awardee_karma").*"awardee_karma":(.*),)(?(?=.*"is_gold").*"is_gold":(.*),)(?(?=.*"is_mod").*"is_mod":(.*),)(?(?=.*"awarder_karma").*"awarder_karma":(.*),)(?(?=.*"link_karma").*"link_karma":(.*),)(?(?=.*"total_karma").*"total_karma":(.*),)(?(?=.*"snoovatar_img").*"snoovatar_img":(.*)",)(?(?=.*"comment_karma").*"comment_karma":(.*),)"
UpdateRate=600
UpdateDivider=1
OnConnectErrorAction=[#Karmy___ConnectError_1_[#Karmy___Settings_Loaded]]
OnRegExpErrorAction=[#Karmy___RegExpError_1_[#Karmy___Settings_Loaded]]
FinishAction=[#Karmy___Finish_1_[#Karmy___Settings_Loaded]][!EnableMeasureGroup Karmy___Measures][!UpdateMeasureGroup Karmy___Measures][!WriteKeyValue Variables Karmy___Update_Time "[Karmy___Measure_Updated_Time]" "#KarmyWriteConfigPath#"][#Karmy___Update_[#Karmy___Settings_Loaded]]
Substitute="":""
LogSubstringErrors=0
DynamicVariables=1

[Karmy___Measure_Parent_2]
Measure=WebParser
Url=https://www.reddit.com/user/#Karmy___Username#
RegExp="(?siU).*data-testid="cake-day".*>(.*)<"
UpdateRate=600
UpdateDivider=1
FinishAction=[!EnableMeasure Karmy___Measure_Account_Cake_Day][!UpdateMeasure Karmy___Measure_Account_Cake_Day]
Substitute="":""
LogSubstringErrors=0
DynamicVariables=1

[Karmy___Connection_Status]
Measure=Calc
Formula=[MeasureConnection]
OnUpdateAction=[#Karmy___Update_Meters_TopBar_[#Karmy_Setting_Show_Text]][!SetOption #CURRENTSECTION# OnUpdateAction ""]
OnChangeAction=[#Karmy___Update_Meters_TopBar_[#Karmy_Setting_Show_Text]]
IfCondition=(Karmy___Connection_Status=1)
IfTrueAction=[!UpdateMeasure Karmy___Measure_Parent][!UpdateMeasure Karmy___Measure_Parent_2]
DynamicVariables=1
UpdateDivider=1

;------------------------------

[Karmy___Measure_Account_Cake_Day]
Measure=WebParser
Url=[Karmy___Measure_Parent_2]
StringIndex=1
RegExpSubstitute=1
Substitute="^\s":"","\s+$":"","\x{0022}":"","":"KARMY___CAKED_DAY_NOT_FOUND"
OnUpdateAction=[!WriteKeyValue Variables Karmy___Account_Cake_Day "[Karmy___Measure_Account_Cake_Day]" "#KarmyWriteConfigPath#"]
DynamicVariables=1
UpdateDivider=-1
Disabled=1

;------------------------------

[Karmy___Measure_Account_Is_Over_18]
Group=Karmy___Measures
Measure=WebParser
Url=[Karmy___Measure_Parent]
StringIndex=4
DecodeCharacterReference=1
DecodeCodePoints=1
RegExpSubstitute=1
Substitute="^\s":"","\s+$":"","\x{0022}":"","true":"1","false":"0","":"0"
OnUpdateAction=[!WriteKeyValue Variables Karmy___Account_Is_Over_18 "[Karmy___Measure_Account_Is_Over_18]" "#KarmyWriteConfigPath#"]
DynamicVariables=1
UpdateDivider=-1
Disabled=1

[Karmy___Measure_Account_Is_Gold]
Group=Karmy___Measures
Measure=WebParser
Url=[Karmy___Measure_Parent]
StringIndex=9
DecodeCharacterReference=1
DecodeCodePoints=1
RegExpSubstitute=1
Substitute="^\s":"","\s+$":"","\x{0022}":"","true":"1","false":"0","":"0"
OnUpdateAction=[!WriteKeyValue Variables Karmy___Account_Is_Gold "[Karmy___Measure_Account_Is_Gold]" "#KarmyWriteConfigPath#"]
DynamicVariables=1
UpdateDivider=-1
Disabled=1

[Karmy___Measure_Account_Is_Mod]
Group=Karmy___Measures
Measure=WebParser
Url=[Karmy___Measure_Parent]
StringIndex=10
DecodeCharacterReference=1
DecodeCodePoints=1
RegExpSubstitute=1
Substitute="^\s":"","\s+$":"","\x{0022}":"","true":"1","false":"0","":"0"
OnUpdateAction=[!WriteKeyValue Variables Karmy___Account_Is_Mod "[Karmy___Measure_Account_Is_Mod]" "#KarmyWriteConfigPath#"]
DynamicVariables=1
UpdateDivider=-1
Disabled=1

;------------------------------

[Karmy___Measure_Account_Image_Banner]
Group=Karmy___Measures
Measure=WebParser
Url=[Karmy___Measure_Parent]
StringIndex=2
DecodeCharacterReference=1
RegExpSubstitute=1
Substitute="^\s":"","\x{0022}":"","\?width.*":"","":"KARMY___BANNER_NOT_FOUND"
OnUpdateAction=[!WriteKeyValue Variables Karmy___Account_Image_Banner "[Karmy___Measure_Account_Image_Banner]" "#KarmyWriteConfigPath#"]
DynamicVariables=1
UpdateDivider=-1
Disabled=1

[Karmy___Measure_Account_Image_Icon]
Group=Karmy___Measures
Measure=WebParser
Url=[Karmy___Measure_Parent]
StringIndex=5
DecodeCharacterReference=1
RegExpSubstitute=1
Substitute="^\s":"","\x{0022}":"","":"KARMY___ICON_NOT_FOUND"
OnUpdateAction=[!WriteKeyValue Variables Karmy___Account_Image_Icon "[Karmy___Measure_Account_Image_Icon]" "#KarmyWriteConfigPath#"]
DynamicVariables=1
UpdateDivider=-1
Disabled=1

[Karmy___Measure_Account_Image_Snoovatar]
Group=Karmy___Measures
Measure=WebParser
Url=[Karmy___Measure_Parent]
StringIndex=14
DecodeCharacterReference=1
RegExpSubstitute=1
Substitute="^\s":"","\x{0022}":"","":"KARMY___SNOOVATAR_NOT_FOUND"
OnUpdateAction=[!WriteKeyValue Variables Karmy___Account_Image_Snoovatar "[Karmy___Measure_Account_Image_Snoovatar]" "#KarmyWriteConfigPath#"]
DynamicVariables=1
UpdateDivider=-1
Disabled=1

;------------------------------

[Karmy___Measure_Account_About_Name]
Group=Karmy___Measures
Measure=WebParser
Url=[Karmy___Measure_Parent]
StringIndex=3
DecodeCharacterReference=1
DecodeCodePoints=1
RegExpSubstitute=1
Substitute="^\s":"","\x{0022}":"","":"KARMY___NAME_NOT_FOUND"
OnUpdateAction=[!WriteKeyValue Variables Karmy___Account_About_Name "[Karmy___Measure_Account_About_Name]" "#KarmyWriteConfigPath#"]
DynamicVariables=1
UpdateDivider=-1
Disabled=1

[Karmy___Measure_Account_About_Name_Prefixed]
Group=Karmy___Measures
Measure=WebParser
Url=[Karmy___Measure_Parent]
StringIndex=6
DecodeCharacterReference=1
DecodeCodePoints=1
RegExpSubstitute=1
Substitute="^\s":"","\x{0022}":"","":"KARMY___PREFIXEDNAME_NOT_FOUND"
OnUpdateAction=[!WriteKeyValue Variables Karmy___Account_About_Prefixed "[Karmy___Measure_Account_About_Name_Prefixed]" "#KarmyWriteConfigPath#"]
DynamicVariables=1
UpdateDivider=-1
Disabled=1

[Karmy___Measure_Account_About_Description]
Group=Karmy___Measures
Measure=WebParser
Url=[Karmy___Measure_Parent]
StringIndex=7
DecodeCharacterReference=1
DecodeCodePoints=1
RegExpSubstitute=1
Substitute="^\s":"","\x{0022}":"","":"KARMY___DESCRIPTION_NOT_FOUND","\\n":"#*CRLF*#"
OnUpdateAction=[!WriteKeyValue Variables Karmy___Account_About_Description "[Karmy___Measure_Account_About_Description]" "#KarmyWriteConfigPath#"]
DynamicVariables=1
UpdateDivider=-1
Disabled=1

;------------------------------

[Karmy___Measure_Account_Karma_Total]
Group=Karmy___Measures
Measure=WebParser
Url=[Karmy___Measure_Parent]
StringIndex=13
DecodeCharacterReference=1
RegExpSubstitute=1
Substitute="^\s":"","\x{0022}":"","(\d)(?=(\d{3})+(?!\d))":"\1,","":"0"
OnUpdateAction=[!WriteKeyValue Variables Karmy___Account_Karma_Total "[Karmy___Measure_Account_Karma_Total]" "#KarmyWriteConfigPath#"][!SetVariable Karmy___Account_Karma_Total "[Karmy___Measure_Account_Karma_Total]" "Droptop\DropdownBar"][#Karmy___Update_Meters_TopBar_[#Karmy_Setting_Show_Text]]
DynamicVariables=1
UpdateDivider=-1
Disabled=1

[Karmy___Measure_Account_Karma_Awardee]
Group=Karmy___Measures
Measure=WebParser
Url=[Karmy___Measure_Parent]
StringIndex=8
DecodeCharacterReference=1
RegExpSubstitute=1
Substitute="^\s":"","\x{0022}":"","(\d)(?=(\d{3})+(?!\d))":"\1,","":"0"
OnUpdateAction=[!WriteKeyValue Variables Karmy___Account_Karma_Awardee "[Karmy___Measure_Account_Karma_Awardee]" "#KarmyWriteConfigPath#"]
DynamicVariables=1
UpdateDivider=-1
Disabled=1

[Karmy___Measure_Account_Karma_Awarder]
Group=Karmy___Measures
Measure=WebParser
Url=[Karmy___Measure_Parent]
StringIndex=11
DecodeCharacterReference=1
RegExpSubstitute=1
Substitute="^\s":"","\x{0022}":"","(\d)(?=(\d{3})+(?!\d))":"\1,","":"0"
OnUpdateAction=[!WriteKeyValue Variables Karmy___Account_Karma_Awarder "[Karmy___Measure_Account_Karma_Awarder]" "#KarmyWriteConfigPath#"]
DynamicVariables=1
UpdateDivider=-1
Disabled=1

[Karmy___Measure_Account_Karma_Link]
Group=Karmy___Measures
Measure=WebParser
Url=[Karmy___Measure_Parent]
StringIndex=12
DecodeCharacterReference=1
RegExpSubstitute=1
Substitute="^\s":"","\x{0022}":"","(\d)(?=(\d{3})+(?!\d))":"\1,","":"0"
OnUpdateAction=[!WriteKeyValue Variables Karmy___Account_Karma_Link "[Karmy___Measure_Account_Karma_Link]" "#KarmyWriteConfigPath#"]
DynamicVariables=1
UpdateDivider=-1
Disabled=1

[Karmy___Measure_Account_Karma_Comment]
Group=Karmy___Measures
Measure=WebParser
Url=[Karmy___Measure_Parent]
StringIndex=15
DecodeCharacterReference=1
RegExpSubstitute=1
Substitute="^\s":"","\x{0022}":"","(\d)(?=(\d{3})+(?!\d))":"\1,","":"0"
OnUpdateAction=[!WriteKeyValue Variables Karmy___Account_Karma_Comment "[Karmy___Measure_Account_Karma_Comment]" "#KarmyWriteConfigPath#"]
DynamicVariables=1
UpdateDivider=-1
Disabled=1