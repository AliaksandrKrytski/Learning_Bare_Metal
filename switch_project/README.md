MICROCONTROLLER: arduino nano(atmega328p)

PINS: D2(PD2) - Button - GND; D5 - Resistor 330Ω - Led(+) Led(-) - GND

to flash an MCU(on linux):
    avr-gcc -Os -DF_CPU=16000000UL(Optional, if code haven't got this) -mmcu=atmega328p -c main.c -o main.o
    avr-gcc -mmcu=atmega328p main.o -o firmware.elf
    avr-objcopy -O ihex -R .eeprom firmware.elf firmware.hex
    sudo avrdude -F -V -c arduino -p m328p -P /dev/ttyUSB0(lsusb to look what usb use your mcu) -b 115200 -U flash:w:firmware.hex:i
