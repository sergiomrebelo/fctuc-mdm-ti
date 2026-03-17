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
    loop {
		n = (1.0.rand.round); // Random float between 0 and 1
		// n.postln;
		p.put(n); // sent to arduino
        1.wait; // Wait for 1 second
    }
}).play;

)

