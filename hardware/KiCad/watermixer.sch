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
L watermixer-symbols:ESP32-DevKitC U2
U 1 1 61402480
P 5500 2100
F 0 "U2" H 5575 3265 50  0000 C CNN
F 1 "ESP32-DevKitC" H 5575 3174 50  0000 C CNN
F 2 "Espressif:ESP32-DevKitC" H 5500 850 50  0000 C CNN
F 3 "https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/hw-reference/esp32/get-started-devkitc.html" H 5650 850 50  0001 C CNN
	1    5500 2100
	-1   0    0    1   
$EndComp
$Comp
L watermixer-rescue:LLC_4CH-watermixer-symbols-watermixer-rescue U3
U 1 1 6140B974
P 7750 4150
F 0 "U3" H 7750 5031 50  0000 C CNN
F 1 "LLC_4CH" H 7750 4940 50  0000 C CNN
F 2 "watermixer-footprints:LLC_4CH" H 7750 3400 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/txb0104.pdf" H 7860 4245 50  0001 C CNN
	1    7750 4150
	0    1    1    0   
$EndComp
$Comp
L watermixer-symbols:Barrel_Jack J_12V1
U 1 1 6141485A
P 6000 6950
F 0 "J_12V1" H 6150 7250 50  0000 C CNN
F 1 "Barrel_Jack" H 6200 6750 50  0000 C CNN
F 2 "watermixer-footprints:Barrel_Jack" H 6150 6700 50  0001 C CNN
F 3 "~" H 6100 6910 50  0001 C CNN
	1    6000 6950
	1    0    0    -1  
$EndComp
$Comp
L watermixer-symbols:Screw_Terminal_01x03 JD_VALVE1
U 1 1 61418706
P 10250 5700
F 0 "JD_VALVE1" H 10200 5500 50  0000 L CNN
F 1 "01x03" H 10200 5600 50  0000 L CNN
F 2 "watermixer-footprints:Screw_Termianl_01x03" H 10450 5600 50  0001 C CNN
F 3 "~" H 10250 5700 50  0001 C CNN
	1    10250 5700
	1    0    0    -1  
$EndComp
$Comp
L watermixer-symbols:Screw_Terminal_01x06 JHC_VALVES1
U 1 1 6141617A
P 10250 5100
F 0 "JHC_VALVES1" H 10200 5500 50  0000 L CNN
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
P 1150 3750
F 0 "R1" H 1080 3704 50  0000 R CNN
F 1 "4.7k" H 1080 3795 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1080 3750 50  0001 C CNN
F 3 "~" H 1150 3750 50  0001 C CNN
	1    1150 3750
	-1   0    0    1   
$EndComp
$Comp
L watermixer-symbols:Screw_Terminal_01x03 JTemp1
U 1 1 6143D1E5
P 650 3900
F 0 "JTemp1" H 550 3800 50  0000 L CNN
F 1 "Temperature sensor" H 50  4200 50  0000 L CNN
F 2 "watermixer-footprints:Screw_Termianl_01x03" H 650 3700 50  0001 C CNN
F 3 "~" H 650 3900 50  0001 C CNN
	1    650  3900
	-1   0    0    1   
$EndComp
Wire Wire Line
	3050 2350 2200 2350
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
	6950 700  950  700 
Wire Wire Line
	950  700  950  3600
Text Label 800  4000 0    50   ~ 0
GND
Text Label 800  4100 0    50   ~ 0
3.3V
Text Label 800  3900 0    50   ~ 0
SIGT
Wire Wire Line
	950  3600 1150 3600
Wire Wire Line
	800  4000 2200 4000
Wire Wire Line
	800  4100 1150 4100
Text Label 4850 4600 2    50   ~ 0
GND
Text Label 4850 4700 2    50   ~ 0
VCC
Wire Wire Line
	7650 3700 7650 1850
Wire Wire Line
	8100 5100 7650 5100
Wire Wire Line
	8100 5200 7450 5200
Wire Wire Line
	7450 3700 7450 1550
Wire Wire Line
	8700 4900 8700 4850
Text Label 8150 4850 0    50   ~ 0
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
	9950 4900 10100 4900
Wire Wire Line
	9950 4900 9950 5200
Wire Wire Line
	9950 5200 10100 5200
Wire Wire Line
	9950 5200 9950 5500
Wire Wire Line
	9950 5500 10100 5500
Connection ~ 9950 5200
Wire Wire Line
	7450 1550 6800 1550
Wire Wire Line
	7650 1850 6800 1850
Wire Wire Line
	6800 1650 7050 1650
Wire Wire Line
	7050 1650 7050 3750
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
Connection ~ 8450 4850
Wire Wire Line
	8450 4850 8700 4850
Wire Wire Line
	8450 4250 8450 4850
Wire Wire Line
	7050 4250 6850 4250
Wire Wire Line
	6800 1150 8700 1150
Connection ~ 8700 4850
NoConn ~ 4050 1150
NoConn ~ 4050 1250
NoConn ~ 4050 1350
NoConn ~ 4050 1650
NoConn ~ 4050 1850
NoConn ~ 4050 1950
NoConn ~ 4050 2750
NoConn ~ 4050 2650
NoConn ~ 4050 2550
NoConn ~ 6800 2250
NoConn ~ 6800 2350
NoConn ~ 6800 2450
NoConn ~ 6800 2650
NoConn ~ 6800 2750
NoConn ~ 6800 2850
NoConn ~ 6800 2050
NoConn ~ 6800 1950
NoConn ~ 6800 1750
NoConn ~ 6800 1450
NoConn ~ 6800 1350
NoConn ~ 6800 1250
NoConn ~ 7850 4600
NoConn ~ 8050 4600
NoConn ~ 8050 3700
NoConn ~ 7850 3700
NoConn ~ 1400 3350
$Comp
L power:GND #PWR08
U 1 1 6158DE4A
P 5600 7050
F 0 "#PWR08" H 5600 6800 50  0001 C CNN
F 1 "GND" H 5605 6877 50  0000 C CNN
F 2 "" H 5600 7050 50  0001 C CNN
F 3 "" H 5600 7050 50  0001 C CNN
	1    5600 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	9950 4650 9950 4900
Connection ~ 9950 4900
NoConn ~ 9300 5300
NoConn ~ 8100 5300
NoConn ~ 8100 5400
Wire Wire Line
	6800 2950 8450 2950
Wire Wire Line
	8450 2950 8450 4050
NoConn ~ 3000 2950
Wire Wire Line
	8700 1150 8700 4850
$Comp
L watermixer-symbols:CP C2
U 1 1 6148D5D9
P 4550 5200
F 0 "C2" V 4450 5100 50  0000 C CNN
F 1 "470uF" V 4700 5200 50  0000 C CNN
F 2 "Capacitor_THT:CP_Radial_Tantal_D8.0mm_P5.00mm" H 4550 4800 50  0001 C CNN
F 3 "~" H 4550 5200 50  0001 C CNN
	1    4550 5200
	0    1    1    0   
$EndComp
$Comp
L watermixer-symbols:CP C3
U 1 1 6149C94A
P 5200 6900
F 0 "C3" V 5100 6800 50  0000 C CNN
F 1 "470uF" V 5350 6900 50  0000 C CNN
F 2 "Capacitor_THT:CP_Radial_Tantal_D8.0mm_P5.00mm" H 5200 6500 50  0001 C CNN
F 3 "~" H 5200 6900 50  0001 C CNN
	1    5200 6900
	1    0    0    -1  
$EndComp
$Comp
L watermixer-symbols:MountingHole H4
U 1 1 614E9C53
P 600 6900
F 0 "H4" H 1250 6900 50  0000 L CNN
F 1 "MountingHole" H 700 6900 50  0000 L CNN
F 2 "watermixer-footprints:MountingHole_3.2mm_M3" H 600 6900 50  0001 C CNN
F 3 "~" H 600 6900 50  0001 C CNN
	1    600  6900
	1    0    0    -1  
$EndComp
$Comp
L watermixer-symbols:MountingHole H3
U 1 1 614EA463
P 600 6700
F 0 "H3" H 1250 6700 50  0000 L CNN
F 1 "MountingHole" H 700 6700 50  0000 L CNN
F 2 "watermixer-footprints:MountingHole_3.2mm_M3" H 600 6700 50  0001 C CNN
F 3 "~" H 600 6700 50  0001 C CNN
	1    600  6700
	1    0    0    -1  
$EndComp
$Comp
L watermixer-symbols:MountingHole H2
U 1 1 614EAA78
P 600 6500
F 0 "H2" H 1250 6500 50  0000 L CNN
F 1 "MountingHole" H 700 6500 50  0000 L CNN
F 2 "watermixer-footprints:MountingHole_3.2mm_M3" H 600 6500 50  0001 C CNN
F 3 "~" H 600 6500 50  0001 C CNN
	1    600  6500
	1    0    0    -1  
$EndComp
$Comp
L watermixer-symbols:MountingHole H1
U 1 1 614EB1BF
P 600 6300
F 0 "H1" H 1250 6300 50  0000 L CNN
F 1 "MountingHole" H 700 6300 50  0000 L CNN
F 2 "watermixer-footprints:MountingHole_3.2mm_M3" H 600 6300 50  0001 C CNN
F 3 "~" H 600 6300 50  0001 C CNN
	1    600  6300
	1    0    0    -1  
$EndComp
Connection ~ 2200 3550
NoConn ~ 6800 2550
Wire Wire Line
	6800 4400 7100 4400
Wire Wire Line
	7100 4400 7100 4650
Wire Wire Line
	6800 4500 7000 4500
Wire Wire Line
	7000 4500 7000 4750
Wire Wire Line
	7650 4750 7000 4750
Connection ~ 7650 4750
Wire Wire Line
	7650 4750 7650 4600
Wire Wire Line
	7650 4750 7650 5100
Wire Wire Line
	7450 4650 7100 4650
Connection ~ 7450 4650
Wire Wire Line
	7450 4650 7450 4600
Wire Wire Line
	7450 4650 7450 5200
Wire Wire Line
	6200 4700 6200 4850
Connection ~ 6200 4850
Wire Wire Line
	6200 4850 8450 4850
Connection ~ 7050 3750
Connection ~ 6850 3750
Wire Wire Line
	6850 3750 7050 3750
Wire Wire Line
	7050 3750 7050 4050
Wire Wire Line
	6850 3750 6850 4250
$Comp
L watermixer-symbols:Screw_Terminal_01x03 JPress1
U 1 1 6140DCC9
P 4550 4500
F 0 "JPress1" V 4650 4450 50  0000 L CNN
F 1 "Pressure sensor" H 4100 4350 50  0000 L CNN
F 2 "watermixer-footprints:Screw_Termianl_01x03" H 4550 4300 50  0001 C CNN
F 3 "~" H 4550 4500 50  0001 C CNN
	1    4550 4500
	-1   0    0    1   
$EndComp
Text Label 4850 4500 2    50   ~ 0
SIGP
NoConn ~ 6800 4200
NoConn ~ 6800 4300
NoConn ~ 5600 4300
NoConn ~ 5600 4200
NoConn ~ 5600 4400
$Comp
L watermixer-rescue:MCP4728-watermixer-symbols-watermixer-rescue U4
U 1 1 6170E8A7
P 8700 5200
F 0 "U4" H 8400 5450 50  0000 C CNN
F 1 "MCP4728" H 9000 5450 50  0000 C CNN
F 2 "watermixer-footprints:MCP4728_module" H 8700 4600 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22187E.pdf" H 8700 5450 50  0001 C CNN
	1    8700 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3750 6850 3750
Connection ~ 6200 3750
Wire Wire Line
	4400 5200 4300 5200
Connection ~ 4300 5200
Wire Wire Line
	4300 5200 4300 5400
Wire Wire Line
	4300 3750 4300 5200
Wire Wire Line
	4700 5200 4750 5200
Connection ~ 4750 5200
Wire Wire Line
	4750 4850 4750 5200
Wire Wire Line
	4750 5200 4750 5400
$Comp
L watermixer-symbols:ADS1115 U5
U 1 1 6171895F
P 6200 4400
F 0 "U5" H 5950 4700 50  0000 C CNN
F 1 "ADS1115" H 6450 4700 50  0000 C CNN
F 2 "watermixer-footprints:ADS1115_module" H 6200 3800 50  0001 C CNN
F 3 "" H 6200 4650 50  0001 C CNN
	1    6200 4400
	-1   0    0    1   
$EndComp
Wire Wire Line
	6200 3750 6200 4000
Wire Wire Line
	4750 4850 5200 4850
Wire Wire Line
	4700 4700 5200 4700
Wire Wire Line
	5200 4700 5200 4850
Connection ~ 5200 4850
Wire Wire Line
	5200 4850 6200 4850
Wire Wire Line
	4700 4600 5200 4600
Wire Wire Line
	2550 5800 2650 5800
Wire Wire Line
	2300 4800 2200 4800
Wire Wire Line
	2550 4800 2650 4800
Wire Wire Line
	4400 5700 4300 5700
Wire Wire Line
	4650 5700 4750 5700
Wire Wire Line
	9750 5600 9750 5850
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 61B12F2B
P 1650 7550
F 0 "#FLG0101" H 1650 7625 50  0001 C CNN
F 1 "PWR_FLAG" H 1650 7723 50  0000 C CNN
F 2 "" H 1650 7550 50  0001 C CNN
F 3 "~" H 1650 7550 50  0001 C CNN
	1    1650 7550
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 61B14379
P 2150 7550
F 0 "#FLG0102" H 2150 7625 50  0001 C CNN
F 1 "PWR_FLAG" H 2150 7723 50  0000 C CNN
F 2 "" H 2150 7550 50  0001 C CNN
F 3 "~" H 2150 7550 50  0001 C CNN
	1    2150 7550
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 61B14CE6
P 1150 7550
F 0 "#FLG0103" H 1150 7625 50  0001 C CNN
F 1 "PWR_FLAG" H 1150 7723 50  0000 C CNN
F 2 "" H 1150 7550 50  0001 C CNN
F 3 "~" H 1150 7550 50  0001 C CNN
	1    1150 7550
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG0104
U 1 1 61B156F2
P 700 7350
F 0 "#FLG0104" H 700 7425 50  0001 C CNN
F 1 "PWR_FLAG" H 700 7523 50  0000 C CNN
F 2 "" H 700 7350 50  0001 C CNN
F 3 "~" H 700 7350 50  0001 C CNN
	1    700  7350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 61B16151
P 700 7550
F 0 "#PWR0101" H 700 7300 50  0001 C CNN
F 1 "GND" H 705 7377 50  0000 C CNN
F 2 "" H 700 7550 50  0001 C CNN
F 3 "" H 700 7550 50  0001 C CNN
	1    700  7550
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0102
U 1 1 61B7D099
P 1150 7350
F 0 "#PWR0102" H 1150 7200 50  0001 C CNN
F 1 "+12V" H 1165 7523 50  0000 C CNN
F 2 "" H 1150 7350 50  0001 C CNN
F 3 "" H 1150 7350 50  0001 C CNN
	1    1150 7350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 61B7D835
P 1650 7350
F 0 "#PWR0103" H 1650 7200 50  0001 C CNN
F 1 "+5V" H 1665 7523 50  0000 C CNN
F 2 "" H 1650 7350 50  0001 C CNN
F 3 "" H 1650 7350 50  0001 C CNN
	1    1650 7350
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0104
U 1 1 61B7DEBD
P 2150 7350
F 0 "#PWR0104" H 2150 7200 50  0001 C CNN
F 1 "+3.3V" H 2165 7523 50  0000 C CNN
F 2 "" H 2150 7350 50  0001 C CNN
F 3 "" H 2150 7350 50  0001 C CNN
	1    2150 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	700  7350 700  7550
Wire Wire Line
	1150 7550 1150 7350
Wire Wire Line
	1650 7550 1650 7350
Wire Wire Line
	2150 7550 2150 7350
$Comp
L power:+12V #PWR0105
U 1 1 61C1E047
P 5600 6750
F 0 "#PWR0105" H 5600 6600 50  0001 C CNN
F 1 "+12V" H 5615 6923 50  0000 C CNN
F 2 "" H 5600 6750 50  0001 C CNN
F 3 "" H 5600 6750 50  0001 C CNN
	1    5600 6750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0106
U 1 1 61C30EB8
P 5000 5400
F 0 "#PWR0106" H 5000 5250 50  0001 C CNN
F 1 "+5V" H 5015 5573 50  0000 C CNN
F 2 "" H 5000 5400 50  0001 C CNN
F 3 "" H 5000 5400 50  0001 C CNN
	1    5000 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 5400 5000 5400
Connection ~ 4750 5400
Wire Wire Line
	4750 5400 4750 5700
$Comp
L watermixer-symbols:SD_BUCK3A U7
U 1 1 61C45D6A
P 2550 5450
F 0 "U7" V 2700 6050 50  0000 R CNN
F 1 "SD_BUCK3A" V 2655 5220 50  0000 R CNN
F 2 "watermixer-footprints:SD_BUCK3A" H 2650 5200 50  0001 C CNN
F 3 "" H 2550 5450 50  0001 C CNN
	1    2550 5450
	0    -1   -1   0   
$EndComp
Connection ~ 2650 4800
Connection ~ 2200 4800
$Comp
L power:+3.3V #PWR0107
U 1 1 61C475E7
P 2850 4500
F 0 "#PWR0107" H 2850 4350 50  0001 C CNN
F 1 "+3.3V" H 2865 4673 50  0000 C CNN
F 2 "" H 2850 4500 50  0001 C CNN
F 3 "" H 2850 4500 50  0001 C CNN
	1    2850 4500
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0108
U 1 1 61CD59E7
P 9950 4650
F 0 "#PWR0108" H 9950 4500 50  0001 C CNN
F 1 "+12V" H 9965 4823 50  0000 C CNN
F 2 "" H 9950 4650 50  0001 C CNN
F 3 "" H 9950 4650 50  0001 C CNN
	1    9950 4650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 61CD5E55
P 9750 5850
F 0 "#PWR0109" H 9750 5600 50  0001 C CNN
F 1 "GND" H 9755 5677 50  0000 C CNN
F 2 "" H 9750 5850 50  0001 C CNN
F 3 "" H 9750 5850 50  0001 C CNN
	1    9750 5850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 61CD6629
P 4100 5400
F 0 "#PWR0110" H 4100 5150 50  0001 C CNN
F 1 "GND" H 4105 5227 50  0000 C CNN
F 2 "" H 4100 5400 50  0001 C CNN
F 3 "" H 4100 5400 50  0001 C CNN
	1    4100 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 5400 4100 5400
Connection ~ 4300 5400
Wire Wire Line
	4300 5400 4300 5700
$Comp
L power:GND #PWR0111
U 1 1 61CDF90E
P 2000 4500
F 0 "#PWR0111" H 2000 4250 50  0001 C CNN
F 1 "GND" H 2005 4327 50  0000 C CNN
F 2 "" H 2000 4500 50  0001 C CNN
F 3 "" H 2000 4500 50  0001 C CNN
	1    2000 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 6950 6550 7050
Connection ~ 6550 7050
Connection ~ 4300 5700
Connection ~ 4750 5700
$Comp
L watermixer-symbols:SD_BUCK3A U6
U 1 1 61C43A3D
P 4650 6350
F 0 "U6" V 4750 6950 50  0000 R CNN
F 1 "SD_BUCK3A" V 4755 6120 50  0000 R CNN
F 2 "watermixer-footprints:SD_BUCK3A" H 4750 6100 50  0001 C CNN
F 3 "" H 4650 6350 50  0001 C CNN
	1    4650 6350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2300 5800 2200 5800
$Comp
L watermixer-symbols:CR2013-MI2120-touch U1
U 1 1 6142F819
P 2200 2950
F 0 "U1" H 1550 3500 50  0000 C CNN
F 1 "CR2013-MI2120-touch" H 2200 3640 50  0000 C CNN
F 2 "watermixer-footprints:CR2013-MI2120_touch" H 2200 2250 50  0001 C CNN
F 3 "http://pan.baidu.com/s/11Y990" H 1550 3450 50  0001 C CNN
	1    2200 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 7250 6550 7250
Wire Wire Line
	6550 7050 6550 7250
Wire Wire Line
	6550 6800 6550 6550
Wire Wire Line
	6550 6550 5750 6550
Wire Wire Line
	4300 6750 4400 6750
Wire Wire Line
	4400 6750 4400 6700
Wire Wire Line
	4300 6750 4300 6700
Wire Wire Line
	4650 6700 4650 6750
Wire Wire Line
	4650 6750 4750 6750
Wire Wire Line
	4750 6700 4750 6750
Connection ~ 4750 6750
Wire Wire Line
	4750 6750 5200 6750
Wire Wire Line
	5200 6750 5600 6750
Connection ~ 5200 6750
Connection ~ 5600 6750
Wire Wire Line
	5600 6750 5750 6750
Wire Wire Line
	5750 6750 5750 6550
Wire Wire Line
	5750 7050 5600 7050
Wire Wire Line
	5750 7050 5750 7250
Wire Wire Line
	5600 7050 5200 7050
Connection ~ 5600 7050
Connection ~ 5200 7050
Wire Wire Line
	4300 6750 4300 7050
Connection ~ 4300 6750
Wire Wire Line
	4300 7050 5200 7050
Wire Wire Line
	4300 7050 2200 7050
Connection ~ 4300 7050
Wire Wire Line
	2650 6850 4750 6850
Wire Wire Line
	4750 6850 4750 6750
$Comp
L watermixer-symbols:CP C1
U 1 1 61416FFF
P 2350 4500
F 0 "C1" V 2250 4400 50  0000 C CNN
F 1 "470uF" V 2500 4500 50  0000 C CNN
F 2 "Capacitor_THT:CP_Radial_Tantal_D8.0mm_P5.00mm" H 2350 4100 50  0001 C CNN
F 3 "~" H 2350 4500 50  0001 C CNN
	1    2350 4500
	0    1    1    0   
$EndComp
Wire Wire Line
	2200 3550 2200 4000
Connection ~ 2650 4100
Wire Wire Line
	2650 4100 3050 4100
Wire Wire Line
	3050 3150 3050 4100
Connection ~ 2200 4500
Wire Wire Line
	2200 4500 2200 4800
Wire Wire Line
	2200 4000 2200 4500
Wire Wire Line
	2650 4100 2650 4500
Wire Wire Line
	2200 4500 2000 4500
Wire Wire Line
	2500 4500 2650 4500
Connection ~ 2650 4500
Wire Wire Line
	2650 4500 2650 4800
Wire Wire Line
	2650 4500 2850 4500
Wire Wire Line
	1150 3900 1150 4100
Connection ~ 1150 4100
Wire Wire Line
	1150 4100 2650 4100
Wire Wire Line
	2200 7050 2200 5800
Connection ~ 2200 5800
Wire Wire Line
	2650 6850 2650 5800
Connection ~ 2650 5800
Wire Wire Line
	4300 3750 5200 3750
Wire Wire Line
	5200 4600 5200 3750
Connection ~ 5200 3750
Wire Wire Line
	5200 3750 6200 3750
Wire Wire Line
	4700 4500 5600 4500
Wire Wire Line
	800  3900 950  3900
Wire Wire Line
	950  3900 950  3600
Connection ~ 950  3600
Wire Wire Line
	6800 2150 6950 2150
Wire Wire Line
	6950 2150 6950 700 
$EndSCHEMATC
