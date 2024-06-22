#include <HID-Project.h>  //include HID_Project library
#include <HID-Settings.h>

#define REVERSED false

int val = 0;
int previousval = 0;
int val2 = 0;
bool ledState = LOW;  // Status LED

void setup() {
  Keyboard.begin();
  pinMode(2, INPUT_PULLUP);  // Pin 2 sebagai input dengan pull-up internal
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);

  Consumer.begin();  //initialize computer connection
  delay(1000);       //wait for computer to connect
  for (int a = 0; a < 52; a++) {
    Consumer.write(MEDIA_VOLUME_DOWN);  //set the volume to 0
    delay(2);
  }
}

void loop() {
  if (digitalRead(2) == LOW) {
    // Jika tombol ditekan, ubah pin 2 menjadi output dan nyalakan LED
    pinMode(2, OUTPUT);
    digitalWrite(2, HIGH);
    Keyboard.press('1');
    ledState = HIGH;  // Update status LED
  } else {
    // Jika tombol tidak ditekan, kembalikan pin 2 ke input
    pinMode(2, INPUT_PULLUP);
    Keyboard.release('1');
    ledState = LOW;  // Update status LED
  }

  // Proses pin lainnya
  if (digitalRead(3) == LOW) {
    Keyboard.press('w');
  } else {
    Keyboard.release('w');
  }

  if (digitalRead(4) == LOW) {
    Keyboard.press('3');
  } else {
    Keyboard.release('3');
  }

  if (digitalRead(5) == LOW) {
    Keyboard.press('4');
  } else {
    Keyboard.release('4');
  }

  if (digitalRead(6) == LOW) {
    Keyboard.press('a');
  } else {
    Keyboard.release('a');
  }

  if (digitalRead(7) == LOW) {
    Keyboard.press('s');
  } else {
    Keyboard.release('s');
  }

  if (digitalRead(8) == LOW) {
    Keyboard.press('d');
  } else {
    Keyboard.release('d');
  }

  if (digitalRead(9) == LOW) {
    Keyboard.press('8');
  } else {
    Keyboard.release('8');
  }

  if (digitalRead(15) == LOW) {
    Keyboard.press('9');
  } else {
    Keyboard.release('9');
  }

  if (digitalRead(14) == LOW) {
    Keyboard.press('0');
  } else {
    Keyboard.release('0');
  }

  if (digitalRead(10) == LOW) {
    Keyboard.press('B');
  } else {
    Keyboard.release('B');
  }

  delay(10);  // Delay kecil untuk debounce
  volumeCon();
}

void volumeCon() {
  val = analogRead(A1);              //read potentiometer value
  val = map(val, 0, 1023, 0, 101);  //map it to 102 steps
  if (REVERSED) {
    val = 101 - val;
  }
  if (abs(val - previousval) > 1) {  //check if potentiometer value has changed
    previousval = val;
    val /= 2;  //divide it by 2 to get 51 steps

    while (val2 < val) {
      Consumer.write(MEDIA_VOLUME_UP);  //turn volume up to appropiate level
      val2++;
      delay(2);
    }
    while (val2 > val) {
      Consumer.write(MEDIA_VOLUME_DOWN);  //turn volume down to appropiate level
      val2--;
      delay(2);
    }
  }
  delay(30);
}
