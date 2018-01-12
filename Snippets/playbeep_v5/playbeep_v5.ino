/***********************************************
   FHNW, ebs, HS17

   Stephanie Fernandez Andersson
   Philipp Kopf
   Manuel Sutter
***********************************************
*/

/*
 * Dieser Code konnte nicht erfolgreich integriert werden.
 * Bei der Verwendung von tone() läuft einer der MiniQ-Motoren nicht mehr.
 * Vermutlich ein Timer-Konflikt.
 */






 

#define tonepin 16

//Definition der Frequenzen der einzelnen Töne
#define TONE_C3 130.813
#define TONE_CIS3 138.591
#define TONE_D3 146.832
#define TONE_DIS3 155.563
#define TONE_E3 164.814
#define TONE_F3 174.614
#define TONE_FIS3 184.997
#define TONE_G3 195.998
#define TONE_GIS3 207.652
#define TONE_A3 220.000
#define TONE_B3 233.082
#define TONE_H3 246.942

#define TONE_C4 261.626
#define TONE_CIS4 277.183
#define TONE_D4 293.665
#define TONE_DIS4 311.127
#define TONE_E4 329.628
#define TONE_F4 349.228
#define TONE_FIS4 369.994
#define TONE_G4 391.995
#define TONE_GIS4 415.305
#define TONE_A4 440.000
#define TONE_B4 466.164
#define TONE_H4 493.883

#define TONE_C5 523.251
#define TONE_CIS5 554.365
#define TONE_D5 587.330
#define TONE_DIS5 622.254
#define TONE_E5 659.255
#define TONE_F5 698.456
#define TONE_FIS5 739.989
#define TONE_G5 783.991
#define TONE_GIS5 830.609
#define TONE_A5 880.00
#define TONE_B5 932.328
#define TONE_H5 987.767

#define P 0      //Tonpause

//Definition der Tondauer
#define W 1        //Ganzton
#define H 0.5      //Halbton
#define Q 0.25     //Viertel
#define QP 0.375   //Punktierter Viertel
#define E 0.125    //Achtel
#define EP 0.1875  //Punktierter Achtel
#define S 0.0625   //Sechzentel
#define XS 0.02    //Unterbruch zwischen zwei gleichen Tönen

//--------------------------------------------------------------
//Definition der Arrays für einfachen BEEP
//Array der Tonfolge (Frequenz)
int beeptone[]={TONE_A5};
//Array der Tondauer
float beepduration[]={H};
//--------------------------------------------------------------
//Definition der Arrays für DREIFACHTON
//Array der Tonfolge (Frequenz)
int threetone[]={TONE_C4,TONE_G4,TONE_C5};
//Array der Tondauer
float threeduration[]={Q,Q,Q};
//--------------------------------------------------------------
//Definition der Arrays für TETRIS
//Array der Tonfolge (Frequenz)
int tetristone[]=    
{
  TONE_E5,TONE_H4,TONE_C5,TONE_D5,TONE_C5,TONE_H4,    //Tackt1
  TONE_A4,TONE_A4,TONE_C5,TONE_E5,TONE_D5,TONE_C5,   //Tackt2
  TONE_H4,TONE_H4,TONE_C5,TONE_D5,TONE_E5,           //Tackt3
  TONE_C5,TONE_A4,P,TONE_A4,P,                      //Tackt4
  P,TONE_D5,TONE_F5,TONE_A5,TONE_G5,TONE_F5,        //Tackt5
  TONE_E5,TONE_C5,TONE_E5,TONE_D5,TONE_C5,          //Tackt6
  TONE_H4,TONE_H4,TONE_C5,TONE_D5,TONE_E5,          //Tackt7
  TONE_C5,TONE_A4,P,TONE_A4,P                        //Tackt8
};
//Array der Tondauer
float tetrisduration[]=
{
  Q,E,E,Q,E,E,        //Tackt1
  Q,E,E,Q,E,E,        //Tackt2
  Q,E,E,Q,Q,          //Tackt3
  Q,Q,XS,Q,Q,         //Tackt4
  S,Q,E,Q,E,E,        //Tackt5
  QP,E,Q,E,E,         //Tackt6
  Q,E,E,Q,Q,          //Tackt7
  Q,Q,XS,Q,Q          //Tackt8
};
//--------------------------------------------------------------
//--------------------------------------------------------------
//Definition der Arrays für STARWARS
//Array der Tonfolge (Frequenz)
int starwarstone[]=    
{
  TONE_A4,P,TONE_A4,P,TONE_A4,TONE_F4,TONE_C5,                        //Tackt1
  TONE_A4,TONE_F4,TONE_C5,TONE_A4,                                    //Tackt2
  TONE_E5,P,TONE_E5,P,TONE_E5,TONE_F5,TONE_C5,                        //Tackt3
  TONE_GIS4,TONE_F4,TONE_C5,TONE_A4,                                 //Tackt4
  TONE_A5,TONE_A4,P,TONE_A4,TONE_A5,TONE_GIS5,TONE_G5,               //Tackt5
  TONE_FIS5,TONE_F5,TONE_FIS5,TONE_B4,TONE_DIS5,TONE_D5,TONE_CIS5,   //Tackt6
  TONE_C5,TONE_H4,TONE_C5,TONE_F4,TONE_GIS4,TONE_F4,TONE_GIS4,       //Tackt7
  TONE_C5,TONE_A4,TONE_C5,TONE_E5                                    //Tackt8
};
//Array der Tondauer
float starwarsduration[]=
{
  Q,XS,Q,XS,Q,EP,S,               //Tackt1
  Q,EP,S,H,                       //Tackt2
  Q,XS,Q,XS,Q,EP,S,               //Tackt3
  Q,EP,S,H,                       //Tackt4
  Q,E,XS,E,Q,E,E,                 //Tackt5
  S,S,EP,EP,Q,EP,S,               //Tackt6
  S,S,EP,EP,Q,EP,S,               //Tackt7
  Q,EP,S,H                        //Tackt8
};
//--------------------------------------------------------------
int soundspeed=1800;
int soundheight=1;
int finalsoundpause=2000;
int length;
//--------------------------------------------------------------

void playBeep(int soundtrack)  
{
  
  if (soundtrack<=1|soundtrack>4){
    length=sizeof(beeptone)/sizeof(beeptone[0]);   //calculate the length of the array
 
    for(int x=0;x<length;x++)
     {
     tone(tonepin,beeptone[x]);
     delay(soundspeed*beepduration[x]);   //delay for some time for the rhythm
     noTone(tonepin);
     }
    
  }
  else
  {
      if (soundtrack==2){
        length=sizeof(threetone)/sizeof(threetone[0]);   //calculate the length of the array

          for(int x=0;x<length;x++)
          {
            tone(tonepin,threetone[x]);
            delay(soundspeed*threeduration[x]);   //delay for some time for the rhythm
            noTone(tonepin);
          }
      }
      else{
        if(soundtrack==3){      
          length=sizeof(tetristone)/sizeof(tetristone[0]);   //calculate the length of the array

          for(int x=0;x<length;x++)
          {
            tone(tonepin,tetristone[x]);
            delay(soundspeed*tetrisduration[x]);   //delay for some time for the rhythm
            noTone(tonepin);
          }
        }
        else{
          length=sizeof(starwarstone)/sizeof(starwarstone[0]);   //calculate the length of the array

          for(int x=0;x<length;x++)
          {
            tone(tonepin,starwarstone[x]);
            delay(soundspeed*1.5*starwarsduration[x]);   //delay for some time for the rhythm
            noTone(tonepin);
          }
         }
      }
  }
    delay(finalsoundpause);
}

void setup()
{
  pinMode(tonepin,OUTPUT);
}

void loop()
{
  playBeep(1);
  playBeep(2);
  playBeep(3);
  playBeep(4);
}


