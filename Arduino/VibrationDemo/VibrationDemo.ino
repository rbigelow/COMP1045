//==========================================================================
//	Author		    : DFRobot (Modified by rbigelow)
//      Circuit Source: http://www.dfrobot.com/wiki/index.php?title=DFRobot_Digital_Vibration_Sensor_(SKU:DFR0027) 
//	Program description : This program demonstrates the functionality of a Digital Vibration Sensor. 
//==========================================================================
/* The circuit uses the following pins:
Digital 8 Which provides input from the sensor.
*/

#define SensorLED     13 // Output LED display
#define SensorINPUT   8  //Connect the sensor to digital Pin 3 which is Interrupts 1.
 
unsigned char state = 0;
 
void setup() 
{ 
  pinMode(SensorLED, OUTPUT); 
  pinMode(SensorINPUT, INPUT);
  attachInterrupt(1, blink, FALLING);// Trigger the blink function when the falling edge is detected
 
}
void loop()
{
      if(state!=0)
      {
        state = 0;
        digitalWrite(SensorLED,HIGH);
        delay(50);  // Turn on the indicator LED for 50mS.
      }  
      else
        digitalWrite(SensorLED,LOW);
} 
 
void blink()//Interrupts function
{
  state++;
}
