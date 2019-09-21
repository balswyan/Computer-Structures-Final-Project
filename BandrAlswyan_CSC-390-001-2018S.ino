// CSC-390-001
// Bandr AlSwyan

//Program that Drives Arduino Joystick to interact with PC games and apps, the board used here is SparkFun Fio Ver 3 

// Pin A1 = X Axis
// Pin A2 = Y Axis
// Pin 5 = Button 1


// Pin A3 = X2 Axis
// Pin A4 = Y2 Axis
// Pin 7 = Button 2

// Pin 15 = Led
// Pin 6 = Button 3
// Pin 8 = Button 4
//--------------------------------------------------------------

#include "Joystick.h"

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_JOYSTICK, 4, 0, true, true, true, true, true, true, true, true, true, true, true);

void setup() { 

pinMode(A1, INPUT);
pinMode(A2, INPUT);
pinMode(A3, INPUT);
pinMode(A4, INPUT);
pinMode(5, INPUT_PULLUP);
pinMode(6, INPUT_PULLUP);
pinMode(7, INPUT_PULLUP);
pinMode(8, INPUT_PULLUP);
pinMode(15, OUTPUT);

Joystick.begin();
}
  const int pinToButtonMap = 5; //2 3 4 5 are buttons so far

  int lastButtonState[4] = {0,0,0,0};
  
void loop() {



//X-Axis
int xAxis = analogRead(A1);
Joystick.setXAxisRange(0, 1023);
Joystick.setXAxis(xAxis);

//Y-Axis
int yAxis = analogRead(A2);
Joystick.setYAxisRange(0,1023);
Joystick.setYAxis(yAxis);

//X-RAxis
int RxAxis = analogRead(A3);
Joystick.setRxAxisRange(0, 1023);
Joystick.setRxAxis(RxAxis);

// Y-RAxis
int RyAxis = analogRead(A4);
Joystick.setRyAxisRange(0, 1023);
Joystick.setRyAxis(RyAxis);

  //Joystick.setXAxisRange(0, 127);
  //Joystick.setYAxisRange(-127, 127);
  //Joystick.setRxAxisRange(-127, 127);
  //Joystick.setRxAxisRange(-127, 127);

for (int index = 0; index < 4; index++)
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
    
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }


analogWrite(15,analogRead(A1));





delay(100);
}
