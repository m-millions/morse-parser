/*
  5 LED Animation: Wipe On/Wipe Off
*/

// give the LED pins a name:
//byte led_0 = 3;
//byte led_1 = 4;
//byte led_2 = 5;
byte leds[] = {3, 4, 5};

// set the time the LEDs should be delayed in milliseconds
int delayTime = 100;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as an outputs.
  //pinMode(led_0, OUTPUT);
  //pinMode(led_1, OUTPUT);
  //pinMode(led_2, OUTPUT);

  for(int i = 0; i < 4; i++)

  // start off with all LEDs on
  digitalWrite(led_0, HIGH);   // turn the LED on
  digitalWrite(led_1, HIGH);   // turn the LED on
  digitalWrite(led_2, HIGH);   // turn the LED on
}

// the loop routine runs over and over again forever:
void loop() {
  // Turn off one LED at a time
  digitalWrite(led_0, LOW);   // turn the LED on
  delay(delayTime);               // wait for a bit
  digitalWrite(led_1, LOW);    // turn the LED off
  delay(delayTime);               // wait for a bit
  digitalWrite(led_2, LOW);    // turn the LED off
  delay(delayTime);               // wait for a bit
  // wait for a bit
  
  // Turn on one LED at a time
  digitalWrite(led_0, HIGH);   // turn the LED on
  delay(delayTime);               // wait for a bit
  digitalWrite(led_1, HIGH);    // turn the LED off
  delay(delayTime);               // wait for a bit
  digitalWrite(led_2, HIGH);    // turn the LED off
  delay(delayTime);               // wait for a bit
  // wait for a bit
}
