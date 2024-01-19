/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       VEX Brain Arduino - Controlled Arm                                                  */
/*    Author:       Eric Lind                                                    */
/*    Created:      1/19/2024, 1:07:08 PM                                     */
/*    Description:  Handshakes base station arduino for input/echo                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain Brain;
vex::potentiometer ArmPoten(Brain.ThreeWirePort.G);
vex::digital_in ArduinoIn(Brain.ThreeWirePort.H);
vex::motor ArmMotor(1, 200, false);

// define your global instances of motors and other devices here

const float kp = 1, 
            ki = 1, 
            kd = 1,
            allowedError = 10;

float lasterror = 0;

void spinToPosition(double pos, vex::rotationUnits units){

    int runningIntegral = 0;
    
    while(abs(pos - ArmMotor.position(degrees)) > allowedError){

        float error = pos - ArmMotor.position(degrees);
        float derivitive = (lasterror-error);
        runningIntegral += error;

        ArmMotor.spin(forward, error * kp + derivitive * kd + runningIntegral * ki, units);

        lasterror = error;
        wait(60, msec);
    }

}

int main() {

    bool hast = false;
    Motor1.setPosition(0,degrees);
    const double potenan = 0.61;
    const double HOLD = -307.2;
    const double FIRE = -360;
    Motor1.spinToPosition(HOLD, degrees);

    while (true){

        if(DigitalInH.value() == 1 && !hast){
            Motor1.spinToPosition(FIRE, degrees);
            Motor1.setPosition(0,degrees);
            wait(4, seconds);
            hast=true;
        }

        if (DigitalInH.value()== 0 && hast){
            hast=false;
        }

        Motor1.spinToPosition(HOLD, degrees);
        Brain.Screen.print(DigitalInH.value());
        Brain.Screen.print(" ");
        Brain.Screen.print(Brain.Timer.time(seconds));
        Brain.Screen.newLine();
    }
}
