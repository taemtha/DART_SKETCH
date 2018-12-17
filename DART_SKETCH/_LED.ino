#if (shifter_active == 1 && stratos == 0)


void ledControl (byte stat)   // stat significa status 1 = acceso 0 = spento
{
   if (valuetable[general_mempos] == 0)
   {  if (stat >0 ) 
   buttonefx = 0; // ampiezza dell'effetto
 
   for (byte i = 0; i < 16; i++)
   {
   if (encledtable[i] == (lightable[chan]-1)) {buttonefxd = i; break;} else buttonefxd = 60;
   }

   shifter.setPin((lightable[chan]-1), stat); 

   bit_write(1,(lightable[chan]-1)+page,stat);

 }
else 
{
  if (
    lightable[chan] == 4 || 
     lightable[chan] == 5 || 
      lightable[chan] == 6 || 
       lightable[chan] == 10 || 
        lightable[chan] == 11 || 
         lightable[chan] == 12 )
      
      {
        digitalWrite(lightable[chan], stat);
        }

  }

 
}



#endif

#if (shifter_active == 1 && stratos == 0)

void led_enc_exe ()
{

if (qwertyvalue[general_mempos] > 0)
  {

   if (encled <0) { encled = 255 ; 
  shifter.setPin(encledtable[0], bit_read(1,encledtable[0]+(page)));
  shifter.setPin(encledtable[1], bit_read(1,encledtable[1]+(page)));
 } else


if (encled >255) { encled = 0; 
 shifter.setPin(encledtable[15], bit_read(1,encledtable[15]+(page))); 
  shifter.setPin(encledtable[14], bit_read(1,encledtable[14]+(page))); 
 } 

 if (cycletimer <  10) {shifter.setPin(encledtable[constrain(encled/16,0,15)] , 1);  }
 
byte ripristino_led = (encled/16) -2;
 shifter.setPin((encledtable[ripristino_led] ), bit_read(1,encledtable[ripristino_led]+(page))); 
  ripristino_led = (encled/16) +2;
if (encled < 240 ) shifter.setPin((encledtable[ripristino_led] ), bit_read(1,encledtable[ripristino_led]+(page)));

  shifterwrite=1; // on viene ripetuto ad ogni ciclo, ma solo quando vene mosso l'encoder
}
  }
  #endif

  #if (shifter_active == 1 && stratos == 0)
 
 
 void buttonledefx()
 
 {
 //  buttonefx - ampiezza dell'effetto
 //  buttonefxd - centro dell'effetto 
 
  if (buttonefx <5 && buttonefxd < 16) 

  if (cycletimer == 2) 
  {
 
     
      
    //  if (controlfx < 0) controlfx =60;
    //  if (controlfx >= 0 && controlfx < 8)
    byte controlfx  = constrain (buttonefxd-buttonefx,(buttonefxd/8)*8,(buttonefxd/8)*8+8);
      shifter.setPin(encledtable[controlfx], HIGH) ;
         controlfx  = constrain (buttonefxd+buttonefx,(buttonefxd/8)*8,(buttonefxd/8)*8+7);
      shifter.setPin(encledtable[controlfx], HIGH) ;
  
    
 shifterwrite=1;
   
      cycletimer = 0; 
      buttonefx++; 
    if (buttonefx==5) buttonefxu = 0; // a un certo punto si da il via alla fase di spegnimento - buttonefxu ÃƒÆ’Ã‚Â¨ come buttonfx, scala da 5 a zero ogni 30 millisecondi
}
    
     if (buttonefxu < 5 )
  //   if(previousMillis2<currentMillis) 
  if (cycletimer == 3)
     {
    //  shifter.setAll(LOW);
      ledrestore(page);
 
    
    shifterwrite=1; 
       //  previousMillis2=(currentMillis+30); 
         cycletimer = 0 ;
         buttonefxu = (buttonefxu -1) ; 
   

    
   if (buttonefxu==5) { shifter.setAll(LOW); //shifter.write(); 
 ledrestore(page); shifterwrite=1; }
 

 
   }
   
   }
   #endif

#if (shifter_active == 1 && stratos == 0)
   void beamefx()
 {
     cycletimer = 0;
      encled = lightable[distance_mempos] *2;
        led_enc_exe();
  }
  #endif

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if (shifter_active == 1 && stratos == 0)

void ledrestore (boolean numero) { // riscrive sullo shifter la pagina 1 con luci accese o spente

  for(int led = 0; led < max_modifiers; led++) 
{ 
  
shifter.setPin(led, bit_read(1,led+(numero*max_modifiers)) );
// if (lastbutton[touch_mempos[0]] == 1)  shifter.setPin(4+numero,HIGH); 
// if (lastbutton[touch_mempos[1]] == 1)  shifter.setPin(5+numero,HIGH); 
} 
  }
  #endif
