# move-arm-by-speech
Moving arm from web page which convert audio to text

## The main idea:
The main idea is how to allow the Servo motor of the arm to move to 180 or 0 degree when the
user say to the webpage right or left this is basically done by Web Serial API.
## Web Serial API:
A serial port is a bidirectional communication interface that allows sending and receiving data byte by byte which mean it's provides a way for websites to read from and write to a serial device with JavaScript. Serial devices are connected either through a serial port on the user's system or through removable USB and Bluetooth devices that emulate a serial port.

## The important parts of javascript code :
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
            }
```
this part is responsible for make a connection to the serial port and determine the desired baud rate will open the serial port. The baudRate dictionary member specifies how fast data is sent over a serial line. It is expressed in units of bits-per-second (bps). Check your device's documentation for the correct value as all the data you send and receive will be gibberish if this is specified incorrectly,
and allow to read and write to and from the serial port.
```
//to check the specific words

			var textomove = document.getElementById("TE").innerHTML = transcript;
			
			if ( textomove=="يمين") {
                    console.log(textomove)
                    sendSerialR(); //go to the method

                }else if(textomove == "يسار") {
                    console.log(textomove)
                    sendSerialL();//go to the method

                }
```
## Result
![Screenshot (1095)](https://user-images.githubusercontent.com/108452991/183269257-7c4eba76-0066-4d02-986d-2cf701929581.png)

## The important parts of arduino code :
```
pos = Serial.read();
  if (Serial.available() > 0) {
    if (pos == 'R') {
     myservo.write(180);
      delay(100);

    }
    if (pos == 'L') {
     myservo.write(0);
      delay(100);}
  }
}
```
if(Serial.available( ) > 0) //  It will only send data when the received data is greater than 0. 
 Serial.read( );  // It will read the incoming or arriving data byte
it will move to 180 dgree if it read 'R'
and 0 dgree if it read 'L'

## How to try it?
1.install arduino ide to run the servo code on it.
2.download the html code.
3.the components to try the code which are (arduino uno ,arm has servo motor).




