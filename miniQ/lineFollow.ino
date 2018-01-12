/***********************************************
   FHNW, ebs, HS17

   Stephanie Fernandez Andersson
   Philipp Kopf
   Manuel Sutter

   Modul: LineFollow
***********************************************
*/

#define FOLLOW_INTERVAL 2
#define LCD_INTERVAL 200

#define SPEED_MAX 40
#define SPEED_MID 35
#define SPEED_MIN 10
#define SPEED_STOP 0

#define DIRECTION_LEFT 1
#define DIRECTION_STRAIGHT 2
#define DIRECTION_RIGHT 3
#define DIRECTION_STRONGLEFT 5
#define DIRECTION_STRONGRIGHT 4

#define PIN_MOTOR_LEFT_SPEED 5
#define PIN_MOTOR_LEFT_DIRECTION 12
#define PIN_MOTOR_RIGHT_SPEED 6
#define PIN_MOTOR_RIGHT_DIRECTION 7


unsigned long followMillis = 0;
unsigned long lcdMillis = 0;
byte direction;
char lineString[5] = {'-', '-', '-', '-', '-'};

/**
 * liest den Wert eines Infrarotsensoren aus, gibt an ob der Wert
 * Dunkel ist (Linie erkennen) und gibt ein digitalen Wert entsprechend 
 * 0 oder 1 aus
 */
int getLineValue(unsigned int sensorIdx)
{
  if (sensorIdx < 5) {
    if (analogRead(sensorIdx) >= 500)
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }
}

/**
 * setzt die Geschwindigkeit beider Motoren gleichzeitig
 */
void setMotors(int speedLeft, int speedRight)
{
  analogWrite(PIN_MOTOR_LEFT_SPEED, speedLeft);
  analogWrite(PIN_MOTOR_RIGHT_SPEED, speedRight);
}

/**
 * stoppt beide Motoren
 */
void stopMotors()
{
  setMotors(LOW, LOW);
}

/**
 * Hauptfunktion für den Modus Linie Folgen, Linienposition anzeigen,
 * relative Lichtstärke anzeigen
 */
void mLineFollow() {
  if (modeChanged)
  {
    modeChanged = false;

    lcd.print("Line pos: ");
    lcd.setCursor(0, 1);
    lcd.print("Rel. bright: ");

    digitalWrite(PIN_MOTOR_LEFT_DIRECTION, 0);
    digitalWrite(PIN_MOTOR_RIGHT_DIRECTION, 0);
  }
  else if (currentKey == 1) {   //zurück ins menu
    stopMotors();
    changeMode(M_MENU);
  }
  else if (currentKey == 3) { //standbybetrieb
    stopMotors();
    changeMode(M_STANDBY);
  }
  else {
    
    if (currentMillis - followMillis > FOLLOW_INTERVAL) {
      followMillis = currentMillis;

      if (getLineValue(2) == 1 && direction != DIRECTION_STRAIGHT) {
        setMotors(SPEED_MAX, SPEED_MAX);
        direction = DIRECTION_STRAIGHT;
      }
      else if (getLineValue(1) == 1 && direction != DIRECTION_LEFT) {
        direction = DIRECTION_LEFT;
        setMotors(SPEED_MID, SPEED_MAX);
      }
      else if (getLineValue(3) == 1 && direction != DIRECTION_RIGHT) {
        setMotors(SPEED_MAX, SPEED_MID);
        direction = DIRECTION_RIGHT;
      }
      else if (getLineValue(0) == 1 && direction != DIRECTION_STRONGLEFT) {
        setMotors(SPEED_MIN, SPEED_MAX);
        direction = DIRECTION_STRONGLEFT;
      }
      else if (getLineValue(4) == 1 && direction != DIRECTION_STRONGRIGHT) {
        setMotors(SPEED_MAX, SPEED_MIN);
        direction = DIRECTION_STRONGRIGHT;
      }
      
    }

    if (currentMillis - lcdMillis > LCD_INTERVAL) {
      
      lcdMillis = currentMillis;

      brightnessValue = map(getBrightnessValue(), 0, 1023, 100, 0);

      for (int i = 0; i < 5; ++i)
      {
        if (i == direction)
        {
          lineString[i] = 'x';
        }
        else
        {
          lineString[i] = '-';
        }
      }

      lcd.setCursor(10, 0);
      lcd.print(lineString);

      lcd.setCursor(13, 1);
      lcd.print(brightnessValue);

    }
  }
}
