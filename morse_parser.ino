/*
 String to Morse code (International, ITU)
 
 Durations:
 1. short signal (dot) (-): 1 interval
 2. long signal (dash) (---): 3 intervals
 3. intra-character gap (between signals within a character): 1 interval
 4. gap between letters: 3 intervals
 5. gap between words: 7 intervals
 */

const int INTERVAL = 100;
const int PIN = 3;

boolean spaceFlag;


void setup()
{
  pinMode( PIN, OUTPUT );

  Serial.begin( 9600 );  // initialize serial

  spaceFlag = true;
}

void loop()
{
}

void serialEvent()
{
  while ( Serial.available() )
  {
    char inChar = (char)Serial.read();  // get the new byte

    long pattern = convertToPattern( inChar );  

    if ( pattern > 0 )
    {
      transmit( pattern );
      spaceFlag = false;
    } 
    else if ( inChar == ' ' && !spaceFlag )  // if it's a first space after a word, add 4 more intervals (to the 3 we already have after each letter) to the gap, so that the pause between the words is 7 intervals
    {
      digitalWrite( PIN, LOW );
      delay( INTERVAL * 4 );
      spaceFlag = true;
    }
  }
}


long convertToPattern( char inChar )  // returns a binary-encoded Morse pattern representing a single letter. Starting with the least significant (rightmost) bit, short signal (dot) is represented by one bit set to 1, long signal (dash) is represented by 3 consecutive bits set to 1, intra-character gap is one 0-bit.
{
  long pattern;

  switch ( tolower(inChar) ) {
  case 'a':
    pattern = 0x1D;  // B1 1101 (- ---)
    break;
  case 'b':
    pattern = 0x157;  // B1 0101 0111 (---- - - -)
    break;
  case 'c':
    pattern = 0x5D7;  // B101 1101 0111 (--- - --- -)
    break;
  case 'd':
    pattern = 0x57;  // B101 0111 (--- - -)
    break;
  case 'e':
    pattern = 0x1;  // B1 (-)
    break;
  case 'f':
    pattern = 0x175;  // B1 0111 0101 (- - --- -)
    break;
  case 'g':
    pattern = 0x177;  // B1 0111 0111 (--- --- -)
    break;
  case 'h':
    pattern = 0x55;  // B101 0101 (- - - -)
    break;
  case 'i':
    pattern = 0x5;  // B101 (- -)
    break;
  case 'j':
    pattern = 0x1DDD;  // B1 1101 1101 1101 (- --- --- ---)
    break;
  case 'k':
    pattern = 0x1D7;  // B1 1101 0111 (--- - ---)
    break;
  case 'l':
    pattern = 0x15D;  // B1 0101 1101 (- --- - -)
    break;
  case 'm':
    pattern = 0x77;  // B111 0111 (--- ---)
    break;
  case 'n':
    pattern = 0x17;  // B1 0111 (--- -)
    break;
  case 'o':
    pattern = 0x777;  // B111 0111 0111 (--- --- ---)
    break;
  case 'p':
    pattern = 0x5DD;  // B101 1101 1101 (- --- --- -)
    break;
  case 'q':
    pattern = 0x1D77;  // B1 1101 0111 0111 (--- --- - ---)
    break;
  case 'r':
    pattern = 0x5D;  // B101 1101 (- --- -)
    break;
  case 's':
    pattern = 0x15;  // B1 0101 (- - -)
    break;
  case 't':
    pattern = 0x7;  // B111 (---)
    break;
  case 'u':
    pattern = 0x75;  // B111 0101 (- - ---)
    break;
  case 'v':
    pattern = 0x1D5;  // B1 1101 0101 (- - - ---)
    break;
  case 'w':
    pattern = 0x1DD;  // B1 1101 1101 (- --- ---)
    break;
  case 'x':
    pattern = 0x757;  // B111 0101 0111 (--- - - ---)
    break;
  case 'y':
    pattern = 0x1DD7;  // B1 1101 1101 0111 (--- - --- ---)
    break;
  case 'z':
    pattern = 0x577;  // B101 0111 0111 (--- --- - -)
    break;
  case '1':
    pattern = 0x1DDDD;  // B1 1101 1101 1101 1101 (- --- --- --- ---)
    break;
  case '2':
    pattern = 0x7775;  // B111 0111 0111 0101 (- - --- --- ---)
    break;
  case '3':
    pattern = 0x1DD5;  // B1 1101 1101 0101 (- - - --- ---)
    break;
  case '4':
    pattern = 0x755;  // B111 0101 0101 (- - - - ---)
    break;
  case '5':
    pattern = 0x155;  // B1 0101 0101 (- - - - -)
    break;
  case '6':
    pattern = 0x557;  // B101 0101 0111 (--- - - - -)
    break;
  case '7':
    pattern = 0x1577;  // B1 0101 0111 0111 (--- --- - - -)
    break;
  case '8':
    pattern = 0x5777;  // B101 0111 0111 0111 (--- --- --- - -)
    break;
  case '9':
    pattern = 0x17777;  // B1 0111 0111 0111 0111 (--- --- --- --- -)
    break;
  case '0':
    pattern = 0x77777;  // B111 0111 0111 0111 0111 (--- --- --- --- ---)
    break;
  default:
    pattern = 0;
  }

  return pattern;
}

void transmit( long pattern )  // sends signals to the PIN
{
  int gap = 0;

  for ( long i = 1; i < pow( 2, 31 ) && gap < 3; i *= 2 )  // loop through each bit of a pattern, starting from the least significant (rightmost), until 3 consecutive gaps (0s) are encountered (but no more than 31, because of sizeof(long) constraint)
  {
    if ( pattern & i )  // if current bit is set
    {
      digitalWrite( PIN, HIGH );
      gap = 0;
    } 
    else
    {
      digitalWrite( PIN, LOW );
      gap++;
    }

    delay( INTERVAL );
  }
}
