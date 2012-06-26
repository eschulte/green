# Board Information
BOARD_TAG     = atmega328
ARDUINO_PORT  = /dev/ttyUSB0

# Arduino Install
ARDUINO_LIBS  = /usr/share/arduino
ARDUINO_DIR   = /usr/share/arduino

# AVR tools
AVRDUDE       = /usr/bin/avrdude
AVR_TOOLS_DIR = /usr/share/arduino/hardware/tools/avr
AVRDUDE_CONF  = /usr/share/arduino/hardware/tools/avrdude.conf

# Arduino Make
ARDMK_DIR     = /usr/local/src/Arduino-Makefile/
include ../Arduino.mk

.PHONY: real-clean

real-clean:
	rm -rf build-cli/
