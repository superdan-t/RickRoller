#include <Keyboard.h>


String inString = "";
boolean inputComplete = false;

void setup() {

  Serial.begin(9600);
  Serial1.begin(9600);  //Bluetooth on Serial1

  Keyboard.begin();

}

void loop() {


  if (inputComplete) {

    if (inString.equals("cmd")) {


      //Windows Key + R for Run
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('r');
      Keyboard.releaseAll();


      delay(100);


      //Type "cmd.exe" and press enter
      Keyboard.println("cmd.exe");


    } else if (inString.equals("rick")) {

      //Assuming cmd prompt is open, type the command to open the video
      Keyboard.println("rundll32 url.dll,FileProtocolHandler https://www.youtube.com/watch?v=dQw4w9WgXcQ");

    } else if (inString.equals("roll")) {

      //Full screen the browser. Then fullscreen YouTube.
      Keyboard.write(KEY_F11);
      delay(100);
      Keyboard.write('f');

    }

    inString = "";

    inputComplete = false;

  }
  
}
void serialEvent1() {
  while (Serial1.available()) {
    char c = Serial1.read();
    if (c != ';') {
      inString += c;
    } else {
      inputComplete = true;
    }
  }
}
