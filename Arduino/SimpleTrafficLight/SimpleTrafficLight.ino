/*
This program resembles a basic traffic light.
It cycles between 3 different coloured LEDs
and buzzes in between light changes.
*/

 int buzzer=8;//Connect the buzzer Pin to Digital Pin 8  
 int greenLed=9; //Connect green LED to Digital Pin 9
 int yellowLed=10; //Connect yellow LED to Digital Pin 10
 int redLed=11; //Connect red LED to Digital Pin 11 

void setup() 
{  //start of setup
  pinMode(buzzer,OUTPUT);//Set Pin Mode as output
  pinMode(greenLed,OUTPUT);//Set ledPin as output 
  pinMode(yellowLed,OUTPUT);//Set ledPin as output 
  pinMode(redLed,OUTPUT);//Set ledPin as output  
}  //end of setup

void loop() 
{ 

   digitalWrite(buzzer,HIGH); //Start making a sound
   delay(10); //Wait 1ms 
   digitalWrite(buzzer,LOW); //Stop making a sound
 
   digitalWrite(greenLed,HIGH); //Set green LED to high  
   delay(1000); //Wait 1 second 
   digitalWrite(greenLed,LOW); //Set green LED to low 

   digitalWrite(buzzer,HIGH);//Start making a sound 
   delay(10); //Wait 1ms 
   digitalWrite(buzzer,LOW);//Stop making a sound 
      
   digitalWrite(yellowLed,HIGH); //Set yellow LED to high  
   delay(1000); //Delay 1 second 
   digitalWrite(yellowLed,LOW); //Set yellow LED to low 

   digitalWrite(buzzer,HIGH);//Start making a sound 
   delay(10);//Delay 1ms 
   digitalWrite(buzzer,LOW);//Stop making a sound
      
   digitalWrite(redLed,HIGH); //Set red LED to high  
   delay(1000); //Delay 1 second 
   digitalWrite(redLed,LOW); //Set red LED to low   
   
}//end of loop
