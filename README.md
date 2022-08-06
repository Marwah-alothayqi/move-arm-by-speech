# move-arm-by-speech
Moving arm from web page which convert audio to text

## The main idea:
The main idea is how to allow the Servo motor of the arm to move to 180 or 0 degree when the
user say to the webpage right or left this is basically done by Web Serial API.
## Web Serial API:
A serial port is a bidirectional communication interface that allows sending and receiving data byte by byte which mean it's provides a way for websites to read from and write to a serial device with JavaScript. Serial devices are connected either through a serial port on the user's system or through removable USB and Bluetooth devices that emulate a serial port.

## The important parts of the code :
```// Prompt user to select any serial port.
            const port = await navigator.serial.requestPort();
			// Wait for the serial port to open.
            await port.open({ baudRate: 9600 }); 
			//the end
			
			//Write to a serial port 
			textEncoder = new TextEncoderStream();
            writableStreamClosed = textEncoder.readable.pipeTo(port.writable);
            writer = textEncoder.writable.getWriter();
			//the end
		
		    //Read from a serial port
	        const textDecoder = new TextDecoderStream();
            const readableStreamClosed = port.readable.pipeTo(textDecoder.writable);
            const reader = textDecoder.readable.getReader();
            // Listen to data coming from the serial device.
            while (true) {
                const { value, done } = await reader.read();
                if (done) {
                 // Allow the serial port to be closed later.
                 reader.releaseLock();
                break;
                }
              // value is a string.
                console.log(value);
            }```


