/*
    Copyright Giuseppe Di Cillo (www.coagula.org)
    Contact: dicillo@coagula.org
    
    Modified by R. Bigelow to work with the DFRobot 2x16 LCD Shield.
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
IMPORTANT: to use the menubackend library by Alexander Brevig download it at http://www.arduino.cc/playground/uploads/Profiles/MenuBackend_1-4.zip and add the next code at line 195
	void toRoot() {
		setCurrent( &getRoot() );
	}
*/
#include <MenuBackend.h>    //MenuBackend library - copyright by Alexander Brevig
#include <LiquidCrystal.h>  //this library is included in the Arduino IDE

int lastButtonPushed = 0;
int lastButtonEnterState = LOW;   // the previous reading from the Enter input pin
int lastButtonEscState = LOW;   // the previous reading from the Esc input pin
int lastButtonLeftState = LOW;   // the previous reading from the Left input pin
int lastButtonRightState = LOW;   // the previous reading from the Right input pin

long lastEnterDebounceTime = 0;  // the last time the output pin was toggled
long lastEscDebounceTime = 0;  // the last time the output pin was toggled
long lastLeftDebounceTime = 0;  // the last time the output pin was toggled
long lastRightDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 200;    // the debounce time

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  

//These LCD shields us an analog input.
int analogPin = A0; 
int buttonIn;
int button_val[5] ={30, 150, 360, 535, 760 }; //Right, up, down, left, seclect

//Menu variables
MenuBackend menu = MenuBackend(menuUsed,menuChanged);
//initialize menuitems
    MenuItem menu1Item1 = MenuItem("Item1");
      MenuItem menuItem1SubItem1 = MenuItem("Item1SubItem1");
      MenuItem menuItem1SubItem2 = MenuItem("Item1SubItem2");
    MenuItem menu1Item2 = MenuItem("Item2");
      MenuItem menuItem2SubItem1 = MenuItem("Item2SubItem1");
      MenuItem menuItem2SubItem2 = MenuItem("Item2SubItem2");
      MenuItem menuItem3SubItem3 = MenuItem("Item2SubItem3");
    MenuItem menu1Item3 = MenuItem("Item3");

void setup()
{
  lcd.begin(16, 2);
  
  menu.getRoot().add(menu1Item1);
  menu1Item1.addRight(menu1Item2).addRight(menu1Item3);
  menu1Item1.add(menuItem1SubItem1).addRight(menuItem1SubItem2);
  menu1Item2.add(menuItem2SubItem1).addRight(menuItem2SubItem2).addRight(menuItem3SubItem3);
 
  menu.toRoot();
  lcd.setCursor(0,0);  
}  

void loop()
{
  readButtons();  //I splitted button reading and navigation in two procedures because 
  navigateMenus();  //in some situations I want to use the button for other purpose (eg. to change some settings)                 
} 

void menuChanged(MenuChangeEvent changed){
  
  MenuItem newMenuItem=changed.to; //get the destination menu  
  lcd.setCursor(0,1); //set the start position for lcd printing to the second row
  
  if(newMenuItem.getName()==menu.getRoot()){
      lcd.print("Main Menu       ");
  }else if(newMenuItem.getName()=="Item1"){
      lcd.print("Item1           ");
  }else if(newMenuItem.getName()=="Item1SubItem1"){
      lcd.print("Item1SubItem1");
  }else if(newMenuItem.getName()=="Item1SubItem2"){
      lcd.print("Item1SubItem2   ");
  }else if(newMenuItem.getName()=="Item2"){
      lcd.print("Item2           ");
  }else if(newMenuItem.getName()=="Item2SubItem1"){
      lcd.print("Item2SubItem1   ");
  }else if(newMenuItem.getName()=="Item2SubItem2"){
      lcd.print("Item2SubItem2   ");
  }else if(newMenuItem.getName()=="Item2SubItem3"){
      lcd.print("Item2SubItem3   ");
  }else if(newMenuItem.getName()=="Item3"){
      lcd.print("Item3           ");
  }
}

void menuUsed(MenuUseEvent used){
  lcd.setCursor(0,0);  
  lcd.print("You used        ");
  lcd.setCursor(0,1); 
  lcd.print(used.item.getName());
  delay(3000);  //delay to allow message reading
  lcd.setCursor(0,0);  
  lcd.print("Super Menu Program");
  menu.toRoot();  //back to Main
}

void  readButtons(){  //read buttons status
  buttonIn = analogRead(analogPin);     // read ADC value

 //Allow for time to debounce
  if ((millis() - lastEnterDebounceTime) > debounceDelay) {
                      lastButtonPushed = get_key(buttonIn);                   
                    lastEnterDebounceTime=millis();
                  }
}
  
// The get_key function converts the analog value to number between 0 to 4
int get_key(unsigned int input)
{
  int k;  //K is for Counter
	for (k = 0; k < 5; k++)  //Loop 5 times
	{
	 if (input < button_val[k]){   //Compare the value of Analog 0 with the values stored in
         Serial.println(k);  
         return k;
	}
    // No valid key pressed
    if (k >= 5){    
       return -1;
    }
  }     
}

void navigateMenus() {
  MenuItem currentMenu=menu.getCurrent();
  
  switch (lastButtonPushed){
    case 0:
      if(!(currentMenu.moveDown())){  //if the current menu has a child and has been pressed enter then menu navigate to item below
        menu.use();
      }else{  //otherwise, if menu has no child and has been pressed enter the current menu is used
        menu.moveDown();
       } 
      break;
    case 1:
      menu.moveLeft();
      break; 
    case 2:
      menu.moveRight();
      break;      
    case 3:
      menu.moveUp();
      break;
    case 4:
      menu.toRoot();  //back to main
      break; 
  }
  
  lastButtonPushed=-1; //reset the lastButtonPushed variable
}



