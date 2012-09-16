//For Arduino Start kit
//Compatible with all Arduino version //Last updated 2011-1-13 //www.dfrobot.com
//Sound Demo

void setup() {
pinMode(6,OUTPUT);  //Connect buzzer to pin 6
}

void loop() {
  char i,j; 
  while(1) //This is an endless loop
  {
    for(i=0;i<80;i++) 
    {  
    digitalWrite(6,HIGH);  //Make some sound for a bit 
    delay(1); 
    digitalWrite(6,LOW);   //Stop making sound
    delay(1);
    }
    
    for(i=0;i<100;i++) //Make another sound 
    {
    digitalWrite(6,HIGH);
    delay(2);
    digitalWrite(6,LOW);
    delay(2);
    }
  } 
}

