USER_LIB_PATH = /home/eschulte/research/green/libs

# Board Information
BOARD_TAG     = atmega328
ARDUINO_PORT  = /dev/ttyUSB0

# Arduino Install
ARDUINO_LIBS  = avr/	\
		fft/
ARDUINO_DIR   = /usr/share/arduino

# AVR tools
AVRDUDE       = /usr/bin/avrdude
AVR_TOOLS_DIR = /usr/share/arduino/hardware/tools/avr
AVRDUDE_CONF  = /usr/share/arduino/hardware/tools/avrdude.conf

# Arduino Make
ARDMK_DIR     = /usr/local/src/Arduino-Makefile/
include ../Arduino.mk

.PHONY: real-clean console

real-clean:
	rm -rf build-cli/

console:
	stty -F /dev/ttyUSB0 cs8 9600 ignbrk -brkint -imaxbel \
		-opost -onlcr -isig -icanon -iexten \
		-echo -echoe -echok -echoctl -echoke noflsh -ixon -crtscts; \
	screen -c /dev/null /dev/ttyUSB0 9600

tail:
	stty -F /dev/ttyUSB0 cs8 9600 ignbrk -brkint -imaxbel -icrnl \
		-opost -onlcr -isig -icanon -iexten \
		-echo -echoe -echok -echoctl -echoke noflsh -ixon -crtscts ; \
	tail -f /dev/ttyUSB0

gnuplot:
	../bin/run-gnuplot
