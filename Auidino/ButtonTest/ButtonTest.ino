//For Arduino Start kit
//Compatible with all Arduino version //Last updated 2011-1-13 //www.dfrobot.com
//Button Control Lesson
int light=7;//Connect the led to Digital Pin 7 
void setup()
{
pinMode(light,OUTPUT);//Set the Pinmode to output
}

void loop()
{
  int i; 
  while(1)
  {
  i=analogRead(0);//Connect the button to analog pin 0 
  if(i>512)     //If the analog read is over 512 which is 2.5V
  digitalWrite(light,HIGH);//Turn on the led else
  else{
  digitalWrite(light,LOW);//Turn off the led 
      }
  }
}
