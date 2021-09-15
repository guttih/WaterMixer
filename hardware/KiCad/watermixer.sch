EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Watermixer"
Date "2021-09-15"
Rev "v1.0"
Comp ""
Comment1 "Repository: https://github.com/guttih/watermixer"
Comment2 "https://creativecommons.org/licenses/by/4.0/"
Comment3 "Licence: CC BY 4.0"
Comment4 "Author:Gudjon Holm Sigurdsson"
$EndDescr
$Comp
L watermixer-symbols:MCP4728 U1
U 1 1 613FB3CB
P 8700 5200
F 0 "U1" H 8500 5450 50  0000 C CNN
F 1 "MCP4728" H 8950 5450 50  0000 C CNN
F 2 "watermixer-footprints:MCP4728_module" H 8700 4600 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22187E.pdf" H 8700 5450 50  0001 C CNN
	1    8700 5200
	1    0    0    -1  
$EndComp
$Comp
L Espressif:ESP32-DevKitC U?
U 1 1 61402480
P 5500 2100
F 0 "U?" H 5575 3265 50  0000 C CNN
F 1 "ESP32-DevKitC" H 5575 3174 50  0000 C CNN
F 2 "Espressif:ESP32-DevKitC" H 5500 850 50  0000 C CNN
F 3 "https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/hw-reference/esp32/get-started-devkitc.html" H 5650 850 50  0001 C CNN
	1    5500 2100
	-1   0    0    1   
$EndComp
$Comp
L watermixer-symbols:LLC_4CH U?
U 1 1 6140B974
P 7750 4150
F 0 "U?" H 7750 5031 50  0000 C CNN
F 1 "LLC_4CH" H 7750 4940 50  0000 C CNN
F 2 "watermixer-footprints:LLC_4CH" H 7750 3400 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/txb0104.pdf" H 7860 4245 50  0001 C CNN
	1    7750 4150
	0    1    1    0   
$EndComp
$Comp
L watermixer-symbols:Barrel_Jack J_12V
U 1 1 6141485A
P 8950 4150
F 0 "J_12V" H 9050 4550 50  0000 C CNN
F 1 "Barrel_Jack" H 9100 4450 50  0000 C CNN
F 2 "watermixer-footprints:Barrel_Jack" H 9100 3900 50  0001 C CNN
F 3 "~" H 9050 4110 50  0001 C CNN
	1    8950 4150
	1    0    0    -1  
$EndComp
$Comp
L watermixer-symbols:Screw_Terminal_01x03 JD_VALVE
U 1 1 61418706
P 10250 5700
F 0 "JD_VALVE" H 10200 5500 50  0000 L CNN
F 1 "01x03" H 10200 5600 50  0000 L CNN
F 2 "watermixer-footprints:Screw_Termianl_01x03" H 10450 5600 50  0001 C CNN
F 3 "~" H 10250 5700 50  0001 C CNN
	1    10250 5700
	1    0    0    -1  
$EndComp
$Comp
L watermixer-symbols:Screw_Terminal_01x06 JHC_VALVES
U 1 1 6141617A
P 10250 5100
F 0 "JHC_VALVES" H 10200 5500 50  0000 L CNN
F 1 "01x06" H 10200 5400 50  0000 L CNN
F 2 "watermixer-footprints:Screw_Termianl_01x06" H 10250 5100 50  0001 C CNN
F 3 "~" H 10250 5100 50  0001 C CNN
	1    10250 5100
	1    0    0    -1  
$EndComp
Text Label 10450 5000 0    39   ~ 0
HotValve_GND
Text Label 10450 5100 0    39   ~ 0
HotValve_SIG
Text Label 10450 5200 0    39   ~ 0
ColdValve_VCC
Text Label 10450 5300 0    39   ~ 0
ColdValve_GND
Text Label 10450 5400 0    39   ~ 0
ColdValve_SIG
Text Label 10450 5500 0    39   ~ 0
DrainValve_VCC
Text Label 10450 5600 0    39   ~ 0
DrainValve_GND
Text Label 10450 5700 0    39   ~ 0
DrainValve_SIG
Text Label 10450 4900 0    39   ~ 0
HotValve_VCC
$Comp
L watermixer-symbols:R R1
U 1 1 61439517
P 1200 3750
F 0 "R1" H 1130 3704 50  0000 R CNN
F 1 "4.7k" H 1130 3795 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1130 3750 50  0001 C CNN
F 3 "~" H 1200 3750 50  0001 C CNN
	1    1200 3750
	-1   0    0    1   
$EndComp
$Comp
L watermixer-symbols:R R2
U 1 1 6143A5C1
P 4350 3650
F 0 "R2" H 4500 3600 50  0000 R CNN
F 1 "4.7k" H 4550 3700 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4280 3650 50  0001 C CNN
F 3 "~" H 4350 3650 50  0001 C CNN
	1    4350 3650
	-1   0    0    1   
$EndComp
$Comp
L watermixer-symbols:R R3
U 1 1 6143B052
P 4550 3650
F 0 "R3" H 4500 3600 50  0000 R CNN
F 1 "3.3k" H 4500 3700 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4480 3650 50  0001 C CNN
F 3 "~" H 4550 3650 50  0001 C CNN
	1    4550 3650
	-1   0    0    1   
$EndComp
$Comp
L watermixer-symbols:Screw_Terminal_01x03 JTemp
U 1 1 6143D1E5
P 650 3900
F 0 "JTemp" H 550 3800 50  0000 L CNN
F 1 "Temperature sensor" H 50  4200 50  0000 L CNN
F 2 "watermixer-footprints:Screw_Termianl_01x03" H 650 3700 50  0001 C CNN
F 3 "~" H 650 3900 50  0001 C CNN
	1    650  3900
	-1   0    0    1   
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 61448603
P 9600 3800
F 0 "#PWR?" H 9600 3650 50  0001 C CNN
F 1 "+12V" H 9615 3973 50  0000 C CNN
F 2 "" H 9600 3800 50  0001 C CNN
F 3 "" H 9600 3800 50  0001 C CNN
	1    9600 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 3800 9600 4000
Wire Wire Line
	9600 4000 9500 4000
$Comp
L power:GND #PWR?
U 1 1 6144B091
P 9600 4400
F 0 "#PWR?" H 9600 4150 50  0001 C CNN
F 1 "GND" H 9605 4227 50  0000 C CNN
F 2 "" H 9600 4400 50  0001 C CNN
F 3 "" H 9600 4400 50  0001 C CNN
	1    9600 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 4400 9600 4250
Wire Wire Line
	9600 4250 9500 4250
Wire Wire Line
	9600 4250 9600 4150
Wire Wire Line
	9600 4150 9500 4150
Connection ~ 9600 4250
$Comp
L watermixer-symbols:SD_BUCK3A U_5V
U 1 1 61416868
P 4700 5500
F 0 "U_5V" V 4700 5600 50  0000 C CNN
F 1 "SD_BUCK3A" V 4550 5600 50  0000 C CNN
F 2 "watermixer-footprints:SD_BUCK3A" H 4800 5250 50  0001 C CNN
F 3 "" H 4700 5500 50  0001 C CNN
	1    4700 5500
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 6144D59F
P 2100 6000
F 0 "#PWR?" H 2100 5750 50  0001 C CNN
F 1 "GND" H 2105 5827 50  0000 C CNN
F 2 "" H 2100 6000 50  0001 C CNN
F 3 "" H 2100 6000 50  0001 C CNN
	1    2100 6000
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 614522A9
P 4600 6250
F 0 "#PWR?" H 4600 6100 50  0001 C CNN
F 1 "+12V" H 4615 6423 50  0000 C CNN
F 2 "" H 4600 6250 50  0001 C CNN
F 3 "" H 4600 6250 50  0001 C CNN
	1    4600 6250
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 61453729
P 4250 6250
F 0 "#PWR?" H 4250 6000 50  0001 C CNN
F 1 "GND" H 4255 6077 50  0000 C CNN
F 2 "" H 4250 6250 50  0001 C CNN
F 3 "" H 4250 6250 50  0001 C CNN
	1    4250 6250
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 61459696
P 2450 6000
F 0 "#PWR?" H 2450 5850 50  0001 C CNN
F 1 "+12V" H 2465 6173 50  0000 C CNN
F 2 "" H 2450 6000 50  0001 C CNN
F 3 "" H 2450 6000 50  0001 C CNN
	1    2450 6000
	-1   0    0    1   
$EndComp
Wire Wire Line
	4450 4950 4450 4800
Wire Wire Line
	4450 4800 4350 4800
Wire Wire Line
	4350 4800 4350 4950
$Comp
L watermixer-symbols:SD_BUCK3A U_3.3V
U 1 1 61417027
P 2550 5200
F 0 "U_3.3V" V 2550 5350 50  0000 C CNN
F 1 "SD_BUCK3A" V 2400 5350 50  0000 C CNN
F 2 "watermixer-footprints:SD_BUCK3A" H 2650 4950 50  0001 C CNN
F 3 "" H 2550 5200 50  0001 C CNN
	1    2550 5200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3050 2350 2200 2350
$Comp
L watermixer-symbols:CP C1
U 1 1 61416FFF
P 2400 3800
F 0 "C1" V 2300 3700 50  0000 C CNN
F 1 "470uF" V 2550 3800 50  0000 C CNN
F 2 "Capacitor_THT:CP_Radial_Tantal_D8.0mm_P5.00mm" H 2400 3400 50  0001 C CNN
F 3 "~" H 2400 3800 50  0001 C CNN
	1    2400 3800
	0    1    1    0   
$EndComp
$Comp
L watermixer-symbols:CR2013-MI2120-touch U?
U 1 1 6143BF69
P 2200 2950
F 0 "U?" H 1900 3400 50  0000 C CNN
F 1 "Display" H 2600 3400 50  0000 C CNN
F 2 "watermixer-footprints:CR2013-MI2120_touch" H 2200 2250 50  0001 C CNN
F 3 "http://pan.baidu.com/s/11Y990" H 1550 3450 50  0001 C CNN
	1    2200 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 2350 3950 2350
Wire Wire Line
	3000 2850 3100 2850
Connection ~ 3100 2850
Wire Wire Line
	3100 2850 4050 2850
Wire Wire Line
	3150 2150 3150 3050
Wire Wire Line
	3150 3050 3000 3050
Wire Wire Line
	4050 2150 3150 2150
Connection ~ 3150 2150
Wire Wire Line
	3000 2750 3250 2750
Wire Wire Line
	3250 2750 3250 1450
Wire Wire Line
	3250 1450 4050 1450
Wire Wire Line
	4050 1750 3850 1750
Wire Wire Line
	4050 1550 3350 1550
Wire Wire Line
	3350 1550 3350 2650
Wire Wire Line
	3350 2650 3000 2650
Wire Wire Line
	4050 2050 1350 2050
Wire Wire Line
	3000 3150 3050 3150
Wire Wire Line
	3050 3150 3050 2350
Wire Wire Line
	3100 2300 3100 2850
Wire Wire Line
	2650 4650 2650 4550
Wire Wire Line
	2550 4550 2550 4650
Wire Wire Line
	2550 4550 2650 4550
Wire Wire Line
	2200 4500 2300 4500
Wire Wire Line
	2300 4500 2300 4650
Connection ~ 2200 4500
Wire Wire Line
	2200 4500 2200 4650
Connection ~ 3050 3150
Wire Wire Line
	2200 4000 3950 4000
Wire Wire Line
	3950 2350 3950 4000
Connection ~ 2200 4000
Wire Wire Line
	1350 3050 1400 3050
Wire Wire Line
	1350 2550 1350 2050
Wire Wire Line
	1350 2550 1400 2550
Wire Wire Line
	1250 3150 1250 2650
Connection ~ 1250 2650
Wire Wire Line
	1250 2650 1250 2300
Wire Wire Line
	1250 2300 3100 2300
Wire Wire Line
	1250 3150 1400 3150
Wire Wire Line
	1250 2650 1400 2650
Wire Wire Line
	1050 2950 1050 2850
Wire Wire Line
	1050 2850 1050 2150
Connection ~ 1050 2850
Wire Wire Line
	1050 2150 3150 2150
Wire Wire Line
	1050 2950 1400 2950
Wire Wire Line
	1050 2850 1400 2850
Wire Wire Line
	1150 2250 1150 2750
Wire Wire Line
	1150 2750 1150 3250
Connection ~ 1150 2750
Wire Wire Line
	1150 3250 1400 3250
Wire Wire Line
	1150 2750 1400 2750
Wire Wire Line
	1150 2250 4050 2250
Wire Wire Line
	3850 3250 3850 1750
Wire Wire Line
	3000 3250 3850 3250
Wire Wire Line
	3750 2450 4050 2450
Wire Wire Line
	2250 3800 2200 3800
Connection ~ 2200 3800
Wire Wire Line
	2200 3800 2200 4000
Wire Wire Line
	2200 3550 2200 3800
Wire Wire Line
	2550 3800 2650 3800
Connection ~ 2650 3800
Wire Wire Line
	2650 3800 2650 4100
Wire Wire Line
	2650 3800 3050 3800
Wire Wire Line
	3050 3150 3050 3800
Wire Wire Line
	6800 2150 6950 2150
Wire Wire Line
	6950 700  950  700 
Wire Wire Line
	950  700  950  3600
Wire Wire Line
	950  3600 950  3900
Connection ~ 950  3600
Text Label 800  4000 0    50   ~ 0
GND
Text Label 800  4100 0    50   ~ 0
3.3V
Text Label 800  3900 0    50   ~ 0
SIG
Wire Wire Line
	950  3600 1200 3600
Wire Wire Line
	1200 3900 1200 4100
Connection ~ 1200 4100
Wire Wire Line
	1200 4100 2650 4100
Wire Wire Line
	800  3900 950  3900
Wire Wire Line
	800  4000 2200 4000
Wire Wire Line
	800  4100 1200 4100
Wire Wire Line
	6800 2550 6850 2550
Wire Wire Line
	4550 3500 4550 3350
Connection ~ 4550 3350
Wire Wire Line
	4550 3350 6850 3350
Connection ~ 4350 4800
Wire Wire Line
	4350 3500 4350 3350
Wire Wire Line
	4350 3350 4550 3350
Text Label 4550 4300 1    50   ~ 0
SIG
Text Label 4650 4300 1    50   ~ 0
GND
Text Label 4750 4300 1    50   ~ 0
VCC
Wire Wire Line
	7650 3700 7650 1850
Wire Wire Line
	8100 5100 7650 5100
Wire Wire Line
	7650 5100 7650 4600
Wire Wire Line
	8100 5200 7450 5200
Wire Wire Line
	7450 5200 7450 4600
Wire Wire Line
	7450 3700 7450 1550
Wire Wire Line
	8700 4900 8700 4850
Wire Wire Line
	4700 4950 4700 4850
Wire Wire Line
	4700 4850 4800 4850
Wire Wire Line
	4800 4950 4800 4850
Connection ~ 4800 4850
Wire Wire Line
	4800 4850 4900 4850
Text Label 8300 4850 0    50   ~ 0
5V
Wire Wire Line
	10100 5100 9300 5100
Wire Wire Line
	9300 5200 9400 5200
Wire Wire Line
	9400 5200 9400 5400
Wire Wire Line
	9400 5400 10100 5400
Wire Wire Line
	9300 5400 9300 5700
Wire Wire Line
	9300 5700 10100 5700
Wire Wire Line
	8700 5600 9750 5600
Wire Wire Line
	10100 5300 9750 5300
Wire Wire Line
	9750 5300 9750 5600
Connection ~ 9750 5600
Wire Wire Line
	9750 5600 10100 5600
Wire Wire Line
	10100 5000 9750 5000
Wire Wire Line
	9750 5000 9750 5300
Connection ~ 9750 5300
Wire Wire Line
	9750 5000 9750 4150
Wire Wire Line
	9750 4150 9600 4150
Connection ~ 9750 5000
Connection ~ 9600 4150
Wire Wire Line
	9600 4000 9950 4000
Wire Wire Line
	9950 4000 9950 4900
Wire Wire Line
	9950 4900 10100 4900
Connection ~ 9600 4000
Wire Wire Line
	9950 4900 9950 5200
Wire Wire Line
	9950 5200 10100 5200
Connection ~ 9950 4900
Wire Wire Line
	9950 5200 9950 5500
Wire Wire Line
	9950 5500 10100 5500
Connection ~ 9950 5200
Wire Wire Line
	8450 2950 8450 4050
Wire Wire Line
	6850 2550 6850 3350
Wire Wire Line
	6950 700  6950 2150
Wire Wire Line
	7450 1550 6800 1550
Wire Wire Line
	7650 1850 6800 1850
Wire Wire Line
	6800 1650 7050 1650
Wire Wire Line
	7050 1650 7050 4050
Wire Wire Line
	6800 2950 8450 2950
Connection ~ 4900 4850
Wire Wire Line
	2200 4000 2200 4500
Wire Wire Line
	2650 4100 2650 4550
Connection ~ 2650 4100
Connection ~ 2650 4550
Wire Wire Line
	1350 3650 3750 3650
Wire Wire Line
	3750 2450 3750 3650
Wire Wire Line
	1350 3050 1350 3650
Wire Wire Line
	2200 3550 4050 3550
Wire Wire Line
	4050 3550 4050 2950
Connection ~ 2200 3550
Wire Wire Line
	4900 4850 8450 4850
Connection ~ 8450 4850
Wire Wire Line
	8450 4850 8700 4850
Wire Wire Line
	8450 4250 8450 4850
Wire Wire Line
	4750 4350 4900 4350
Wire Wire Line
	4900 4350 4900 4850
Wire Wire Line
	7050 4250 6850 4250
Wire Wire Line
	4550 3800 4550 4350
Wire Wire Line
	4350 3800 4350 3950
Wire Wire Line
	4650 3950 4350 3950
Connection ~ 4350 3950
Wire Wire Line
	4350 3950 4350 4800
Connection ~ 4650 3950
Wire Wire Line
	4650 3950 4650 4350
Wire Wire Line
	6850 4250 6850 3950
Wire Wire Line
	4650 3950 6850 3950
Wire Wire Line
	4250 5850 4450 5850
Wire Wire Line
	4250 5850 4250 6250
Wire Wire Line
	4600 5850 4600 6250
Wire Wire Line
	4600 5850 4800 5850
Wire Wire Line
	2100 5550 2100 6000
Wire Wire Line
	2100 5550 2300 5550
Wire Wire Line
	2450 5550 2450 6000
Wire Wire Line
	2450 5550 2650 5550
$Comp
L watermixer-symbols:Screw_Terminal_01x03 JPress
U 1 1 6140DCC9
P 4550 4500
F 0 "JPress" V 4650 4450 50  0000 L CNN
F 1 "Pressure sensor" V 4600 4850 50  0000 L CNN
F 2 "watermixer-footprints:Screw_Termianl_01x03" H 4550 4300 50  0001 C CNN
F 3 "~" H 4550 4500 50  0001 C CNN
	1    4550 4500
	0    1    1    0   
$EndComp
$EndSCHEMATC
