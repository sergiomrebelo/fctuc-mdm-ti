let connected = false;
let port = null;

// Filter on devices with the Arduino Uno USB Vendor/Product IDs.
const filters = [
    { usbVendorId: 0x2341, usbProductId: 0x0043 },
    { usbVendorId: 0x2341, usbProductId: 0x0001 }
];



window.onload = () => {
    document.getElementById(`writeBt`).onclick = async (e) => {
        e.preventDefault();
        if (!connected) {
            await init().then(async () => {
                console.log(`inside`);
                connected = true;
                await write(`H`);
            });
        }
    };
}

const init = async () => {

    if ("serial" in navigator) {
        // Prompt user to select any serial port.
        port = await navigator.serial.requestPort({ filters });
        const { usbProductId, usbVendorId } = port.getInfo();

        // Get all serial ports the user has previously granted the website access to.
        const ports = await navigator.serial.getPorts();
        console.log(`ports=${JSON.stringify(ports)}`);

        await port.open({ baudRate: 9800 });

    } else {
        console.warn(`the web serial API is not supported`);
    }
}

const write = async (msg = `H`) => {
    try {
        const textEncoder = new TextEncoderStream();
        console.log(textEncoder);
        console.log(port);
        /*const textEncoder = new TextEncoderStream();
        const writableStreamClosed = textEncoder.readable.pipeTo(port.writable);
        const writer = textEncoder.writable.getWriter();
        console.log(`writer=${writer}`);
        await writer.write(msg);
        writer.releaseLock();*/
    } catch (e) {
        console.error(e);
    }
}
