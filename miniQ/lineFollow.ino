#define LEFT 1
#define STRAIGHT 2
#define RIGHT 3
#define STRONGLEFT 5
#define STRONGRIGHT 4

#define EN1 5//pin for run the left motor 
#define IN1 12//pin for control left motor direction
#define EN2 6//pin for run the right motor 
#define IN2 7//pin for control right motor direction


#define Forward 0      // value for forward
#define Back 1         //value for go back
int data[5];
int direction = 0;


void Motor(int M1_DIR, int M1_EN, int M2_DIR, int M2_EN) //control the motor
{
  //////////M1-->left motor////////////////////////
  if (M1_DIR == Forward) //distinguish the command
    digitalWrite(IN1, Forward);
  else
    digitalWrite(IN1, Back);
  if (M1_EN == 0)
    analogWrite(EN1, LOW);
  else
    analogWrite(EN1, M1_EN);

  ///////////M2-->right motor//////////////////////
  if (M2_DIR == Forward)
    digitalWrite(IN2, Forward);
  else
    digitalWrite(IN2, Back);
  if (M2_EN == 0)
    analogWrite(EN2, LOW);
  else
    analogWrite(EN2, M2_EN);
}

void stopMotor()
{
  Motor(Forward, 0, Forward, 0);
}
void readArrayData()
{
  for (int i = 0; i < 5; ++i)
  {
    data[i] = map(analogRead(i), 400, 900, 1, 0); //AD Conversion
  }
}
void mLineFollow() {        //fährt der Linie nach
  if (modeChanged)
  {
    modeChanged = false;
  }
  else if (currentKey == 1) {   //zurück ins menu
    stopMotor();
    changeMode(M_MENU);
  }
  else if (currentKey == 3) { //standbybetrieb
    stopMotor();
    changeMode(M_STANDBY);
  }
  else {
    
    readArrayData();

    if (data[2] == 1 && direction != STRAIGHT) {
      Motor(Forward, 40, Forward, 40);
      direction = STRAIGHT;
    }
    else if (data[1] == 1 && direction != LEFT) {
      direction = LEFT;
      Motor(Forward, 35, Forward, 40);
    }
    else if (data[3] == 1 && direction != RIGHT) {
      Motor(Forward, 40, Forward, 35);
      direction = RIGHT;
    }
    else if (data[0] == 1 && direction != STRONGLEFT) {
      Motor(Forward, 10, Forward, 40);
      direction = STRONGLEFT;
    }
    else if (data[4] == 1 && direction != STRONGRIGHT) {
      Motor(Forward, 40, Forward, 10);
      direction = STRONGRIGHT;
    }
  }
}
