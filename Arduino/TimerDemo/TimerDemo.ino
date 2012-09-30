//For Arduino Start kit
//Compatible with all Arduino version //Last updated 2011-1-13 //www.dfrobot.com
//7 segment Display Lesson
//The LED Display has a common anode //Define the Pinout of 7 segment display


/*
Pinouts
1: Digit 1             - 16: B
2: Digit 2             - 15: G
3: D                   - 14: A
4: Colon Anode         - 13: C
5: E                   - 12: Colon Cathode
6: Digit 3             - 11: F
7: Decimal Point       - 10:Apostrophe Anode
8: Digit 4             - 9: Apostrophe Cathode
*/

int a=7;
int b=6;
int c=5;
int d=11;
int e=10;
int f=8;
int g=9;
int dp=4;

//Display Number 0
void digital_0(void)
{
unsigned char j;
for(j=6;j<=11;j++)//Set the rest Segments to high which turn off this segment.
digitalWrite(j,LOW);
digitalWrite(g,HIGH); // Segment to low which lights this segment digitalWrite(b,LOW);//Set B Segment to low which lights this segment 

}


//Display Number 1
void digital_1(void)
{
unsigned char j;
digitalWrite(c,LOW);//Set C Segment to low which lights this segment digitalWrite(b,LOW);//Set B Segment to low which lights this segment 
for(j=7;j<=11;j++)//Set the rest Segments to high which turn off this segment.
digitalWrite(j,HIGH);
digitalWrite(dp,HIGH);//Turn off DP segment (the little dot on the right down part)
}
//Display Number 2 
void digital_2(void) {
unsigned char j;
digitalWrite(b,LOW);
digitalWrite(a,LOW); 
for(j=9;j<=11;j++)
digitalWrite(j,LOW); 
digitalWrite(dp,HIGH); 
digitalWrite(c,HIGH); 
digitalWrite(f,HIGH);
}
//Display Number 3 
void digital_3(void) {
unsigned char j; 
digitalWrite(g,LOW); 
digitalWrite(d,LOW);

for(j=5;j<=7;j++)
digitalWrite(j,LOW); 

digitalWrite(dp,HIGH); 
digitalWrite(f,HIGH); 
digitalWrite(e,HIGH);

}
//Display Number 4 
void digital_4(void) {
digitalWrite(c,LOW); 
digitalWrite(b,LOW); 
digitalWrite(f,LOW); 
digitalWrite(g,LOW); 
digitalWrite(dp,HIGH); 
digitalWrite(a,HIGH); 
digitalWrite(e,HIGH); 
digitalWrite(d,HIGH);
}
//Display Number 5 
void digital_5(void) {
unsigned char j; 
for(j=7;j<=9;j++)
digitalWrite(j,LOW);
digitalWrite(c,LOW); 
digitalWrite(d,LOW); 
digitalWrite(dp,HIGH); 
digitalWrite(b,HIGH); 
digitalWrite(e,HIGH);
}

//Display Number 6 
void digital_6(void) {
unsigned char j; 
for(j=7;j<=11;j++)
digitalWrite(j,LOW); 
digitalWrite(c,LOW); 
digitalWrite(dp,HIGH); 
digitalWrite(b,HIGH);
}
//Display Number 7 
void digital_7(void) {
unsigned char j;
for(j=5;j<=7;j++)
digitalWrite(j,LOW);
digitalWrite(dp,HIGH); 
for(j=8;j<=11;j++)
digitalWrite(j,HIGH); 
}

//Display Number 8 
void digital_8(void) {
unsigned char j; 
for(j=5;j<=11;j++)
digitalWrite(j,LOW); 
digitalWrite(dp,HIGH);
}


//Display Number 8 
void digital_9(void) {
unsigned char j; 
for(j=5;j<=11;j++)
digitalWrite(j,LOW); 
digitalWrite(e,HIGH);
digitalWrite(d,HIGH);
}

void setup() {
int i;//Set Pin Mode as output
for(i=4;i<=11;i++)
pinMode(i,OUTPUT);
}

void loop() {
  
digital_0();//Display Number 1 
delay(1000);
digital_1();//Display Number 1 
delay(1000);//Delay 1 seconds 
digital_2();
delay(1000);
digital_3();
delay(1000);
digital_4(); 
delay(1000); 
digital_5(); 
delay(1000); 
digital_6();
delay(1000);
digital_7(); 
delay(1000); 
digital_8(); 
delay(1000);
digital_9(); 
delay(1000);
} 

