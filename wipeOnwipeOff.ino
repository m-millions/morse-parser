/*  5 LED Animation: Wipe On/Wipe Off
 */

//array for handling the 5 LEDs which do the basic pattern
byte randomLeds[] = {3, 4, 5, 6, 7}; 

//array to hold the numeric value for each letter in the alphabet
// which makes up the name; in this case the name is Claudia
byte myName[] = {3, 12, 1, 21, 4, 9, 1};

//array for handling 7 LEDs, which each blinks the number of times as the
//letter's position in the alphabet (ie.. C=3, L=12, A=1, U=21, D=4, I=9, A=1 )
//8=3, 10=12, 11=1, 12=21, 14=4, 15=9, 16=1
byte myNameLeds[] = {8, 10, 11, 12, 14, 15, 16};

// set the time the LEDs should be delayed in milliseconds
int delayTime = 250; //a nice delay to make the patter visible to the human eye :D

// the setup routine runs once when you press reset:
void setup(){                
  // initialize the digital pins as an outputs.
  for(int i = 0; i < 7; i++){ //im cheating and getting away with it should be two functions not one <5 and <7
   pinMode(randomLeds[i], OUTPUT);
   pinMode(myNameLeds[i], OUTPUT);
  }
}

//String glow = "HIGH"; //can a variable that holds the value LOW or HIGH be passed as the parameter
// the loop routine runs over and over again forever:
void loop() {
  // Turn off one LED at a time
  for(int i = 0; i < 7; i++){ //im cheating and getting away with it should be two functions not one <5 and <7
   digitalWrite(randomLeds[i], LOW);
   digitalWrite(myNameLeds[i], LOW);
   //digitalWrite(randomLeds[i], glow);
   delay(delayTime);  // wait for a bit
  }
  
  // Turn on one LED at a time
  for(int i = 0; i < 7; i++){  //im cheating and getting away with it should be two functions not one <5 and <7
   digitalWrite(randomLeds[i], HIGH);
   digitalWrite(myNameLeds[i], HIGH);
   //digitalWrite(randomLeds[i], glow);
   delay(delayTime);  // wait for a bit
  }
