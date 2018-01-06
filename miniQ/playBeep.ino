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

#define P 0       //Tonpause

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
float beeptone[]={TONE_A5};
//Array der Tondauer
float beepduration[]={S};
//--------------------------------------------------------------
//Definition der Arrays für DREIFACHTON
//Array der Tonfolge (Frequenz)
float threetone[]={TONE_C4,TONE_G4,TONE_C5};
//Array der Tondauer
float threeduration[]={Q,Q,Q};
//--------------------------------------------------------------
//Definition der Arrays für TETRIS-Theme
//Array der Tonfolge (Frequenz)
float tetristone[]=    
{
  TONE_E5,TONE_H4,TONE_C5,TONE_D5,TONE_C5,TONE_H4,  //Tackt1
  TONE_A4,TONE_A4,TONE_C5,TONE_E5,TONE_D5,TONE_C5,  //Tackt2
  TONE_H4,TONE_H4,TONE_C5,TONE_D5,TONE_E5,     //Tackt3
  TONE_C5,TONE_A4,P,TONE_A4,P,       //Tackt4
  P,TONE_D5,TONE_F5,TONE_A5,TONE_G5,TONE_F5,   //Tackt5
  TONE_E5,TONE_C5,TONE_E5,TONE_D5,TONE_C5,     //Tackt6
  TONE_H4,TONE_H4,TONE_C5,TONE_D5,TONE_E5,     //Tackt7
  TONE_C5,TONE_A4,P,TONE_A4,P        //Tackt8
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
//Definition der Arrays für STARWARS-Theme (Imperial March)
//Array der Tonfolge (Frequenz)

float starwarstone[]=    
{
  TONE_A4,P,TONE_A4,P,TONE_A4,TONE_F4,TONE_C5,             //Tackt1
  TONE_A4,TONE_F4,TONE_C5,TONE_A4,                    //Tackt2
  TONE_E5,P,TONE_E5,P,TONE_E5,TONE_F5,TONE_C5,             //Tackt3
  TONE_GIS4,TONE_F4,TONE_C5,TONE_A4,                  //Tackt4
  TONE_A5,TONE_A4,P,TONE_A4,TONE_A5,TONE_GIS5,TONE_G5,          //Tackt5
  TONE_FIS5,TONE_F5,TONE_FIS5,TONE_B4,TONE_DIS5,TONE_D5,TONE_CIS5,   //Tackt6
  TONE_C5,TONE_H4,TONE_C5,TONE_F4,TONE_GIS4,TONE_F4,TONE_GIS4,       //Tackt7
  TONE_C5,TONE_A4,TONE_C5,TONE_E5                     //Tackt8
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
//-----------------------------------------------------------------------------------
int finalsoundpause=0;
int length;
//-----------------------------------------------------------------------------------
//playBeep()
//Stephanie Fernandez Andersson
//v_6                 2017-12-18            variable Soundhöhe und Geschwindigkeit
//
//Auswahl des Soundtracks --> Zahl (int) zwischen 1 und 4
//Wenn Auswahl <= 1 oder > 4 dann wird Track 1 gespielt
//
//Track 1: Einzelton
//Track 2: Dreifachton
//Track 3: Tetris Theme
//Track 4: Imperial March 
//
//Abspielhöhe variabel --> Zahl (float) zwischen 1.0 und 10.0 (1.0 = tief und 10.0 = hoch)
//
//Abspielgeschwindigkeit variabel --> Zahl (int) zwischen 1 und 10 (1=langsam und 10 gleich schnell)
//

void playBeeep()
{
  tone(tonepin,TONE_A5,100);
}

void playBeep(int soundtrack, float soundheight, int soundspeed)
{
  return;
  if(soundspeed < 1)
  {
    soundspeed = 5000;
  }
  else{
    if(soundspeed > 10)
    {
      soundspeed = 1000;
    }
    else{
      soundspeed = 5000-((soundspeed-1)*445);            //Umrechnung Soundgeschwindigkeit
    }
  }

//Umrechnung der Soundhöhe
//Bei Eingegebenen Zahlen kleiner 1 oder grösser 10 wird automaitsch ein fixer Minimal- bzw. Maximalwert definiert

  if(soundheight < 1)
  {
    soundheight = 1;
  }
  else{
    if(soundheight > 10)
    {
      soundheight = 1.5;
    }
    else
    {
      soundheight = 1.0+((soundheight-1)*0.6);
    }
  }
  

 //Auswahl des Soundtracks
 //Bei Eingegebenen Zahlen kleiner 1 oder grösser 10 wird automaitsch ein fixer Minimal- bzw. Maximalwert definiert
  
  if (soundtrack<=1|soundtrack>4){
    length=sizeof(beeptone)/sizeof(beeptone[0]);                    //Arraylänge
 
    for(int x=0;x<length;x++)
     {
     tone(tonepin,soundheight*beeptone[x]);
     //delay(soundspeed*beepduration[x]);
     noTone(tonepin);
     }
    
  }
  else
  {
      if (soundtrack==2){
        length=sizeof(threetone)/sizeof(threetone[0]);              //Arraylänge

          for(int x=0;x<length;x++)
          {
            tone(tonepin,soundheight*threetone[x]);                 //Ton
            //delay(soundspeed*threeduration[x]);                     //Rhytmus
            noTone(tonepin);
          }
      }
      else{
        if(soundtrack==3){      
          length=sizeof(tetristone)/sizeof(tetristone[0]);          //Arraylänge

          for(int x=0;x<length;x++)
          {
            tone(tonepin,soundheight*tetristone[x]);                //Ton
            //delay(soundspeed*tetrisduration[x]);                    //Rhytmus
            noTone(tonepin);
          }
        }
        else{
          length=sizeof(starwarstone)/sizeof(starwarstone[0]);      //Arraylänge

          for(int x=0;x<length;x++)
          {
            tone(tonepin,soundheight*starwarstone[x]);              //Ton
            //delay(soundspeed*starwarsduration[x]);                  //Rhytmus   
            noTone(tonepin);
          }
         }
      }
  }
    //delay(finalsoundpause);                                         //Pause (defaultwert = 0)
}
