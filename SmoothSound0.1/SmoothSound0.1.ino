#define PIN_BRIGHTNESS A5
#define PIN_SPEAKER 16
long currentMicros;
long previousMicros;
int tuneValue;

void simpleBeep() {
  beep(1);
}

void beep(int freq)
{
  for (int i = 0; i < 30; i++) {
    digitalWrite(PIN_SPEAKER, HIGH);
    delay(freq);
    digitalWrite(PIN_SPEAKER, LOW);
    delay(freq);
  }
}

void beepSmooth(){
  tuneValue= map(analogRead(PIN_BRIGHTNESS),0,1023,4000,100);
  currentMicros= micros();
  if(currentMicros - previousMicros > tuneValue){
    digitalWrite(PIN_SPEAKER, !digitalRead(PIN_SPEAKER));
    previousMicros= currentMicros;
  }
}

void setup() {
  pinMode(PIN_SPEAKER, OUTPUT);
}

void loop() {
  beepSmooth();
}
