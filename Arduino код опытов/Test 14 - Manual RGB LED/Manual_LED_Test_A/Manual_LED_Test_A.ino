//RGB LED
//The RGB LED will appear red, green, and blue first, then red, orange, yellow, green, blue, indigo, and purple.
//www.RobotLinking.com
//2015.5.7
/*************************************************************************/
const int redPin = 11;  // R petal on RGB LED module connected to digital pin 11 
const int greenPin = 10;  // G petal on RGB LED module connected to digital pin 9 
const int bluePin = 9;  // B petal on RGB LED module connected to digital pin 10 
/**************************************************************************/      
//
int RChannel;
int GChannel;
int BChannel;
//

void color (unsigned char red, unsigned char green, unsigned char blue)     // the color generating function  
{    
          analogWrite(redPin, red);   
          analogWrite(bluePin, blue); 
          analogWrite(greenPin, green); 
}

void setup()
{ 
         pinMode(redPin, OUTPUT); // sets the redPin to be an output 
         pinMode(greenPin, OUTPUT); // sets the greenPin to be an output 
         pinMode(bluePin, OUTPUT); // sets the bluePin to be an output 
         Serial.begin(9600);
         RChannel=0;
         GChannel=0;
         BChannel=0;
}    
/***************************************************************************/      
void loop()  // run over and over again  
{    
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    int RChannel = Serial.parseInt();
    // do it again:
    int GChannel = Serial.parseInt();
    // do it again:
    int BChannel = Serial.parseInt();

    // look for the newline. That's the end of your sentence:
    if (Serial.read() == '\n') {
      // constrain the values to 0 - 255 and invert
      // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
      //RChannel = constrain(RChannel, 0, 255);
      //GChannel = constrain(GChannel, 0, 255);
      //BChannel = constrain(BChannel, 0, 255);

      color(RChannel,GChannel,BChannel);
    }
  }         
}     
/******************************************************/     
