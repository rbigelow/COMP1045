/*
 * WiiChuckDemo -- 
 *
 * 2008 Tod E. Kurt, http://thingm.com/
 *
 */

#include <Wire.h>
#include "nunchuck_funcs.h"

int loop_cnt=0;

byte accx,accy,accz,zbut,cbut,xjoy,yjoy;
int ledPin = 13;


void setup()
{
    Serial.begin(19200);
    nunchuck_setpowerpins();
    nunchuck_init(); // send the initilization handshake
    
    Serial.print("WiiChuckDemo ready\n");
}

void loop()
{

        nunchuck_get_data(); //Read data from numchuck

        accx  = nunchuck_accelx(); // ranges from approx 70 - 182
        accy  = nunchuck_accely(); // ranges from approx 65 - 173
        accz  = nunchuck_accelz(); // ranges from approx 65 - 173
        zbut = nunchuck_zbutton(); // (0 or 1)
        cbut = nunchuck_cbutton(); //(0 or 1)
        xjoy = nunchuck_joyx();    // X axis of Joystick (Between aprox 35-220)
        yjoy = nunchuck_joyy();    // Y axis of Joystick (Between aprox 35-220)       
        Serial.print("AccelX: "); Serial.print(accx);
        Serial.print("\tAccelY:"); Serial.print(accy);
        Serial.print("\tAccelZ:"); Serial.print(accy);
        Serial.print("\tJoy X:"); Serial.print(xjoy);
        Serial.print("\tJoy Y:"); Serial.print(yjoy);   
        Serial.print("\tZ:"); Serial.print(zbut);
        Serial.print("\tC:"); Serial.println(cbut);
        delay(500);  //sample data every 500mS
}

