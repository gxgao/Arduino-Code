#include <AccelStepper.h>

// for the Arduino Uno + CNC shield V3 + A4988 + FL42STH47-1684A

#define MOTOR_X_ENABLE_PIN 8
#define MOTOR_X_STEP_PIN 2
#define MOTOR_X_DIR_PIN 5
#define MOTOR_Y_ENABLE_PIN 8
#define MOTOR_Y_STEP_PIN 3
#define MOTOR_Y_DIR_PIN 6
#define MOTOR_Z_ENABLE_PIN 8
#define MOTOR_Z_STEP_PIN 4
#define MOTOR_Z_DIR_PIN 7

AccelStepper motor_X(1, MOTOR_X_STEP_PIN, MOTOR_X_DIR_PIN);
AccelStepper motor_Y(1, MOTOR_Y_STEP_PIN, MOTOR_Y_DIR_PIN);
AccelStepper motor_Z(1, MOTOR_Z_STEP_PIN, MOTOR_Z_DIR_PIN);


void setup()
{
  Serial.begin(115200);
  motor_X.setEnablePin(MOTOR_X_ENABLE_PIN);
  motor_X.setPinsInverted(false, false, true);
  motor_X.setAcceleration(300);  
  motor_X.setMaxSpeed(8000);
  motor_X.moveTo(1000);
  motor_X.enableOutputs();

  motor_Y.setEnablePin(MOTOR_Y_ENABLE_PIN);
  motor_Y.setPinsInverted(false, false, true);
  motor_Y.setAcceleration(20);  
  motor_Y.move(200);
  motor_Y.setMaxSpeed(8000);
  motor_Y.setSpeed(4000);
  motor_Y.enableOutputs();

  motor_Z.setEnablePin(MOTOR_Z_ENABLE_PIN);
  motor_Z.setPinsInverted(false, false, true);
  motor_Z.setAcceleration(20);  
  motor_Z.move(200);
  motor_Z.setMaxSpeed(8000);
  motor_Z.setSpeed(4000);
  motor_Z.enableOutputs();
  
}

void loop()
{
  // Motor X oscillates between +- 1000
  if (motor_X.distanceToGo() == 0)
    motor_X.moveTo(-motor_X.currentPosition());
  motor_X.run();
  // Motor Y just runs straight
  motor_Y.runSpeed();
  long xPos = motor_X.currentPosition();
  long yPos = motor_Y.currentPosition();  
  Serial.print("X: ");
  Serial.print(xPos);
  Serial.print(", Y: ");
  Serial.println(yPos);
}
