(
// list available ports
SerialPort.listDevices;

// replace with your correct serial port, check port name in Arduino IDE
n = "/dev/cu.usbmodemF412FA68EAFC2";

// establish connection
p = SerialPort(n, baudrate: 9600, crtscts: true);
p.next;

// stop current routine
if(~myRoutine.notNil) {
    ~myRoutine.stop;
};

// create a routine to sent data to arduino
~myRoutine = Routine({
	var byte, str, res;
    loop {
		// read only a char
		// p.read.postln;

		// read all line
		if(p.read==10, {
            str = "";
            while({byte = p.read; byte !=13 }, {
                str = str++byte.asAscii;
            });
            str.postln;
        });
    }
}).play;

)

