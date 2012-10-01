
    
int tempPin = 0;        //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade with a
                        //500 mV offset to allow for negative temperatures
int SensorReading;        // the analog reading from the sensor
int waitTime=3000;     //Amount of time in mS to wait in between temperature readings

void setup(void) {
  Serial.begin(9600);   // We'll send information via the Serial monitor
}
 
 
void loop(void) {
  SensorReading = analogRead(tempPin);  //Read from the temperature sensor 
  Serial.print("Sensor reading = "); //Serial.print displays to the Serial Monitor. Click Tools, Serial montior to view the output.
  Serial.print(SensorReading);     // This is the raw analog reading
 
  // converting that reading to voltage, which is based off the reference voltage (5V)
  float voltage = SensorReading * 5;
        voltage = voltage / 1024.0; 
 
  // Display the voltage
  Serial.print(" - ");
  Serial.print(voltage); Serial.println(" volts");
 
  // now print out the temperature
  float temperatureC = (5.0 * SensorReading * 100.0) / 1024; //converting from 10 mv per degree with 500 mV offset for negavite temperatures.
  
  
  //Note you can shorten all of the above lines and just store the temperature by using this line.
  //float temperatureC = (5.0 * analogRead(tempPin) * 100.0) / 1024; 
  
  Serial.print(temperatureC); Serial.println(" degrees C");
 
  // Convert and output to Fahrenheight
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF); Serial.println(" degrees F");
 
  delay(waitTime); //Wait until it's time to loop again.
}
