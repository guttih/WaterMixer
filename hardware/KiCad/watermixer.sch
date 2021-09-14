EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L watermixer-symbols:MCP4728 U1
U 1 1 613FB3CB
P 8700 5200
F 0 "U1" H 8700 5681 50  0000 C CNN
F 1 "MCP4728" H 8700 5590 50  0000 C CNN
F 2 "watermixer-footprints:MCP4728_module" H 8700 4600 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22187E.pdf" H 8700 5450 50  0001 C CNN
	1    8700 5200
	1    0    0    -1  
$EndComp
$Comp
L watermixer-symbols:CR2013-MI2120-touch U?
U 1 1 613FCFDC
P 2200 2950
F 0 "U?" H 2200 3731 50  0000 C CNN
F 1 "CR2013-MI2120-touch" H 2200 3640 50  0000 C CNN
F 2 "Display:CR2013-MI2120" H 2200 2250 50  0001 C CNN
F 3 "http://pan.baidu.com/s/11Y990" H 1550 3450 50  0001 C CNN
	1    2200 2950
	1    0    0    -1  
$EndComp
$Comp
L Espressif:ESP32-DevKitC U?
U 1 1 61402480
P 5550 2050
F 0 "U?" H 5625 3215 50  0000 C CNN
F 1 "ESP32-DevKitC" H 5625 3124 50  0000 C CNN
F 2 "Espressif:ESP32-DevKitC" H 5550 800 50  0000 C CNN
F 3 "https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/hw-reference/esp32/get-started-devkitc.html" H 5700 800 50  0001 C CNN
	1    5550 2050
	1    0    0    -1  
$EndComp
$Comp
L watermixer-symbols:LLC_4CH U?
U 1 1 6140B974
P 7250 5050
F 0 "U?" H 7250 5931 50  0000 C CNN
F 1 "LLC_4CH" H 7250 5840 50  0000 C CNN
F 2 "watermixer-footprints:LLC_4CH" H 7250 4300 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/txb0104.pdf" H 7360 5145 50  0001 C CNN
	1    7250 5050
	1    0    0    -1  
$EndComp
$Comp
L watermixer-symbols:Barrel_Jack J_12V
U 1 1 6141485A
P 1050 1150
F 0 "J_12V" H 1257 1567 50  0000 C CNN
F 1 "Barrel_Jack" H 1257 1476 50  0000 C CNN
F 2 "watermixer-footprints:Barrel_Jack" H 1200 900 50  0001 C CNN
F 3 "~" H 1150 1110 50  0001 C CNN
	1    1050 1150
	1    0    0    -1  
$EndComp
$Comp
L watermixer-symbols:Screw_Terminal_01x03 JPressure
U 1 1 6140DCC9
P 1950 6850
F 0 "JPressure" H 2280 7000 50  0000 L CNN
F 1 "Pressure sensor" H 2280 6909 50  0000 L CNN
F 2 "watermixer-footprints:Screw_Termianl_01x03" H 1950 6650 50  0001 C CNN
F 3 "~" H 1950 6850 50  0001 C CNN
	1    1950 6850
	0    1    1    0   
$EndComp
$Comp
L watermixer-symbols:Screw_Terminal_01x03 JD_VALVE
U 1 1 61418706
P 10400 5700
F 0 "JD_VALVE" H 10730 5850 50  0000 L CNN
F 1 "ST01x03" H 10730 5759 50  0000 L CNN
F 2 "watermixer-footprints:Screw_Termianl_01x03" H 10600 5600 50  0001 C CNN
F 3 "~" H 10400 5700 50  0001 C CNN
	1    10400 5700
	-1   0    0    1   
$EndComp
$Comp
L watermixer-symbols:Screw_Terminal_01x06 JHC_VALVES
U 1 1 6141617A
P 10400 5400
F 0 "JHC_VALVES" H 10730 5400 50  0000 L CNN
F 1 "01x06" H 10730 5309 50  0000 L CNN
F 2 "watermixer-footprints:Screw_Termianl_01x06" H 10400 5400 50  0001 C CNN
F 3 "~" H 10400 5400 50  0001 C CNN
	1    10400 5400
	-1   0    0    1   
$EndComp
Text Label 10600 5200 0    39   ~ 0
HotValve_GND
Text Label 10600 5300 0    39   ~ 0
HotValve_SIG
Text Label 10600 5400 0    39   ~ 0
ColdValve_VCC
Text Label 10600 5500 0    39   ~ 0
ColdValve_GND
Text Label 10600 5600 0    39   ~ 0
ColdValve_SIG
Text Label 10600 5700 0    39   ~ 0
DrainValve_VCC
Text Label 10600 5800 0    39   ~ 0
DrainValve_GND
Text Label 10600 5900 0    39   ~ 0
DrainValve_SIG
Text Label 10600 5100 0    39   ~ 0
HotValve_VCC
$Comp
L watermixer-symbols:R R1
U 1 1 61439517
P 2600 6350
F 0 "R1" H 2530 6304 50  0000 R CNN
F 1 "4.7k" H 2530 6395 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2530 6350 50  0001 C CNN
F 3 "~" H 2600 6350 50  0001 C CNN
	1    2600 6350
	-1   0    0    1   
$EndComp
$Comp
L watermixer-symbols:R R2
U 1 1 6143A5C1
P 1950 5450
F 0 "R2" H 1880 5404 50  0000 R CNN
F 1 "4.7k" H 1880 5495 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1880 5450 50  0001 C CNN
F 3 "~" H 1950 5450 50  0001 C CNN
	1    1950 5450
	-1   0    0    1   
$EndComp
$Comp
L watermixer-symbols:R R3
U 1 1 6143B052
P 1950 5950
F 0 "R3" H 1880 5904 50  0000 R CNN
F 1 "3.3k" H 1880 5995 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1880 5950 50  0001 C CNN
F 3 "~" H 1950 5950 50  0001 C CNN
	1    1950 5950
	-1   0    0    1   
$EndComp
$Comp
L watermixer-symbols:Screw_Terminal_01x03 JTemp
U 1 1 6143D1E5
P 2600 6850
F 0 "JTemp" H 2930 7000 50  0000 L CNN
F 1 "Temperature sensor" H 2930 6909 50  0000 L CNN
F 2 "watermixer-footprints:Screw_Termianl_01x03" H 2600 6650 50  0001 C CNN
F 3 "~" H 2600 6850 50  0001 C CNN
	1    2600 6850
	0    1    1    0   
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 61448603
P 1700 800
F 0 "#PWR?" H 1700 650 50  0001 C CNN
F 1 "+12V" H 1715 973 50  0000 C CNN
F 2 "" H 1700 800 50  0001 C CNN
F 3 "" H 1700 800 50  0001 C CNN
	1    1700 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 800  1700 1000
Wire Wire Line
	1700 1000 1600 1000
$Comp
L power:GND #PWR?
U 1 1 6144B091
P 1700 1400
F 0 "#PWR?" H 1700 1150 50  0001 C CNN
F 1 "GND" H 1705 1227 50  0000 C CNN
F 2 "" H 1700 1400 50  0001 C CNN
F 3 "" H 1700 1400 50  0001 C CNN
	1    1700 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 1400 1700 1250
Wire Wire Line
	1700 1250 1600 1250
Wire Wire Line
	1700 1250 1700 1150
Wire Wire Line
	1700 1150 1600 1150
Connection ~ 1700 1250
$Comp
L watermixer-symbols:SD_BUCK3A U_5V
U 1 1 61416868
P 4350 4500
F 0 "U_5V" H 4287 5117 50  0000 C CNN
F 1 "SD_BUCK3A" H 4287 5026 50  0000 C CNN
F 2 "watermixer-footprints:SD_BUCK3A" H 4450 4250 50  0001 C CNN
F 3 "" H 4350 4500 50  0001 C CNN
	1    4350 4500
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 6144D59F
P 5250 5950
F 0 "#PWR?" H 5250 5700 50  0001 C CNN
F 1 "GND" H 5255 5777 50  0000 C CNN
F 2 "" H 5250 5950 50  0001 C CNN
F 3 "" H 5250 5950 50  0001 C CNN
	1    5250 5950
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 614522A9
P 5250 4400
F 0 "#PWR?" H 5250 4250 50  0001 C CNN
F 1 "+12V" H 5265 4573 50  0000 C CNN
F 2 "" H 5250 4400 50  0001 C CNN
F 3 "" H 5250 4400 50  0001 C CNN
	1    5250 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 4400 5250 4400
Wire Wire Line
	4600 4500 5250 4500
Wire Wire Line
	5250 4500 5250 4400
Connection ~ 5250 4400
$Comp
L power:GND #PWR?
U 1 1 61453729
P 5250 4900
F 0 "#PWR?" H 5250 4650 50  0001 C CNN
F 1 "GND" H 5255 4727 50  0000 C CNN
F 2 "" H 5250 4900 50  0001 C CNN
F 3 "" H 5250 4900 50  0001 C CNN
	1    5250 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 4750 5250 4750
Wire Wire Line
	5250 4750 5250 4850
Wire Wire Line
	4600 4850 5250 4850
Wire Wire Line
	5250 4850 5250 4900
Connection ~ 5250 4850
Wire Wire Line
	4600 5750 5250 5750
Wire Wire Line
	5250 5750 5250 5850
Wire Wire Line
	4600 5850 5250 5850
Connection ~ 5250 5850
Wire Wire Line
	5250 5850 5250 5950
$Comp
L power:+12V #PWR?
U 1 1 61459696
P 5250 5350
F 0 "#PWR?" H 5250 5200 50  0001 C CNN
F 1 "+12V" H 5265 5523 50  0000 C CNN
F 2 "" H 5250 5350 50  0001 C CNN
F 3 "" H 5250 5350 50  0001 C CNN
	1    5250 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 5400 5250 5400
Wire Wire Line
	5250 5400 5250 5350
Wire Wire Line
	5250 5500 5250 5400
Connection ~ 5250 5400
Wire Wire Line
	3800 5400 3800 5500
Wire Wire Line
	3800 4400 3650 4400
Wire Wire Line
	3650 4400 3650 4500
Wire Wire Line
	3650 4500 3800 4500
Wire Wire Line
	3800 5400 3600 5400
Wire Wire Line
	3600 5400 3600 5500
Wire Wire Line
	3600 5500 3800 5500
Wire Wire Line
	3800 5750 3600 5750
Wire Wire Line
	3600 5750 3600 5850
Wire Wire Line
	3600 5850 3800 5850
Wire Wire Line
	3800 4750 3650 4750
Wire Wire Line
	3650 4750 3650 4850
Wire Wire Line
	3650 4850 3800 4850
Wire Wire Line
	9300 5400 9300 5900
Wire Wire Line
	9300 5900 10550 5900
Wire Wire Line
	9300 5100 10550 5100
Wire Wire Line
	9300 5200 10550 5200
$Comp
L watermixer-symbols:SD_BUCK3A U_3.3V
U 1 1 61417027
P 4350 5500
F 0 "U_3.3V" H 4287 6117 50  0000 C CNN
F 1 "SD_BUCK3A" H 4287 6026 50  0000 C CNN
F 2 "watermixer-footprints:SD_BUCK3A" H 4450 5250 50  0001 C CNN
F 3 "" H 4350 5500 50  0001 C CNN
	1    4350 5500
	-1   0    0    1   
$EndComp
Wire Wire Line
	4600 5500 5250 5500
Connection ~ 3800 5400
Connection ~ 3800 5500
$EndSCHEMATC
