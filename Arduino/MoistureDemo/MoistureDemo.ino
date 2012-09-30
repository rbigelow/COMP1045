//==========================================================================
//	Author		    : DFRobot (Modified by rbigelow)
//      Circuit Source: http://www.dfrobot.com/wiki/index.php/Moisture_Sensor_(SKU:SEN0114)
//	Program description : This program demonstrates the functionality of an Analog Moisture Sensor. 
//==========================================================================
/* The circuit uses the following pins:
Analog 0 Which provides input from the moisture sensor.

  # the sensor value description
  # 0  ~300     dry soil
  # 300~700     humid soil
  # 700~950     in water
*/
   
void setup(){
  Serial.begin(9600);  //Set serial port speed.
}
 
void loop(){ 
  //To view this output you need to click on Tools, Serial Port Monitor from the Arduino Editor menu.
  Serial.print("Moisture Sensor Value:");  
  Serial.println(analogRead(0));  
  delay(1000);  // Read the Sensor every second.
   
}
