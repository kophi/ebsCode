#define tonepin 16

//Definition der Frequenzen der einzelnen Töne
#define C3 130.813
#define CIS3 138.591
#define D3 146.832
#define DIS3 155.563
#define E3 164.814
#define F3 174.614
#define FIS3 184.997
#define G3 195.998
#define GIS3 207.652
#define A3 220.000
#define B3 233.082
#define H3 246.942

#define C4 261.626
#define CIS4 277.183
#define D4 293.665
#define DIS4 311.127
#define E4 329.628
#define F4 349.228
#define FIS4 369.994
#define G4 391.995
#define GIS4 415.305
#define A4 440.000
#define B4 466.164
#define H4 493.883

#define C5 523.251
#define CIS5 554.365
#define D5 587.330
#define DIS5 622.254
#define E5 659.255
#define F5 698.456
#define FIS5 739.989
#define G5 783.991
#define GIS5 830.609
#define A5 880.00
#define B5 932.328
#define H5 987.767

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
int beeptone[]={A5};
//Array der Tondauer
float beepduration[]={H};
//--------------------------------------------------------------
//Definition der Arrays für DREIFACHTON
//Array der Tonfolge (Frequenz)
int threetone[]={C4,G4,C5};
//Array der Tondauer
float threeduration[]={Q,Q,Q};
//--------------------------------------------------------------
//Definition der Arrays für TETRIS
//Array der Tonfolge (Frequenz)
int tetristone[]=    
{
  E5,H4,C5,D5,C5,H4,  //Tackt1
  A4,A4,C5,E5,D5,C5,  //Tackt2
  H4,H4,C5,D5,E5,     //Tackt3
  C5,A4,P,A4,P,       //Tackt4
  P,D5,F5,A5,G5,F5,   //Tackt5
  E5,C5,E5,D5,C5,     //Tackt6
  H4,H4,C5,D5,E5,     //Tackt7
  C5,A4,P,A4,P        //Tackt8
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
  A4,P,A4,P,A4,F4,C5,             //Tackt1
  A4,F4,C5,A4,                    //Tackt2
  E5,P,E5,P,E5,F5,C5,             //Tackt3
  GIS4,F4,C5,A4,                  //Tackt4
  A5,A4,P,A4,A5,GIS5,G5,          //Tackt5
  FIS5,F5,FIS5,B4,DIS5,D5,CIS5,   //Tackt6
  C5,H4,C5,F4,GIS4,F4,GIS4,       //Tackt7
  C5,A4,C5,E5                     //Tackt8
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


