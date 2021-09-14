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
P 1800 3700
F 0 "U1" H 1800 4181 50  0000 C CNN
F 1 "MCP4728" H 1800 4090 50  0000 C CNN
F 2 "watermixer-footprints:MCP4728_module" H 1800 3100 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22187E.pdf" H 1800 3950 50  0001 C CNN
	1    1800 3700
	1    0    0    -1  
$EndComp
$Comp
L watermixer-symbols:CR2013-MI2120-touch U?
U 1 1 613FCFDC
P 3850 4800
F 0 "U?" H 3850 5581 50  0000 C CNN
F 1 "CR2013-MI2120-touch" H 3850 5490 50  0000 C CNN
F 2 "Display:CR2013-MI2120" H 3850 4100 50  0001 C CNN
F 3 "http://pan.baidu.com/s/11Y990" H 3200 5300 50  0001 C CNN
	1    3850 4800
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
P 8850 2700
F 0 "U?" H 8850 3581 50  0000 C CNN
F 1 "LLC_4CH" H 8850 3490 50  0000 C CNN
F 2 "watermixer-footprints:LLC_4CH" H 8850 1950 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/txb0104.pdf" H 8960 2795 50  0001 C CNN
	1    8850 2700
	1    0    0    -1  
$EndComp
$Comp
L watermixer-symbols:SD_BUCK3A U_5V
U 1 1 61416868
P 7900 4350
F 0 "U_5V" H 7837 4967 50  0000 C CNN
F 1 "SD_BUCK3A" H 7837 4876 50  0000 C CNN
F 2 "watermixer-footprints:SD_BUCK3A" H 8000 4100 50  0001 C CNN
F 3 "" H 7900 4350 50  0001 C CNN
	1    7900 4350
	1    0    0    -1  
$EndComp
$Comp
L watermixer-symbols:SD_BUCK3A U_3.3V
U 1 1 61417027
P 7900 5350
F 0 "U_3.3V" H 7837 5967 50  0000 C CNN
F 1 "SD_BUCK3A" H 7837 5876 50  0000 C CNN
F 2 "watermixer-footprints:SD_BUCK3A" H 8000 5100 50  0001 C CNN
F 3 "" H 7900 5350 50  0001 C CNN
	1    7900 5350
	1    0    0    -1  
$EndComp
$EndSCHEMATC
