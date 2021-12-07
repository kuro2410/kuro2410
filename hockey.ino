#include <IRremote.h> //biar bisa make infrared
int RECV_PIN =12;
int ENA = 6;
int M1 = 2;
int M2 = 3;
int ENB = 9;
int M3 = 7;
int M4 = 8;
int IrData;
IRrecv irrecv(RECV_PIN);
const int LS = 4; 
const int LS1 = 11;            
void setup(){     
 Serial.begin(9600);     
 pinMode(ENA, OUTPUT);     
 pinMode(M1, OUTPUT);     
 pinMode(M2, OUTPUT);
 pinMode(ENB, OUTPUT);     
 pinMode(M3, OUTPUT);     
 pinMode(M4, OUTPUT); 
 pinMode(LS, INPUT_PULLUP);
 pinMode(LS1, INPUT_PULLUP);
 pinMode(LS, INPUT);    
 pinMode(LS1,INPUT);                                                                                                                                             
 irrecv.enableIRIn();
}     
int infrared(){ // kunci infrared
     if (IrReceiver.decode())
    IrData=IrReceiver.decodedIRData.command;
    IrReceiver.resume();
    delay(200); 
    return IrData;
}
void loop(){   
int value = infrared();   
Serial.println(value); 
int SW = digitalRead(LS);
int SW1 = digitalRead(LS1);      
Serial.println(value);      
Serial.println(SW);      

  // Robot maju mengejar bola
  if (value == 10)
  {
       analogWrite(ENA, 255); 
       digitalWrite(M1, HIGH);
       digitalWrite(M2, LOW);
       analogWrite(ENB, 255);
       digitalWrite(M3, HIGH);
       digitalWrite(M4, LOW);
       Serial.print("data bola terdeteksi");
  }
   // Robot maju menuju gawang
  else if (  value = 100 && SW == 0 )// 9945 Gawang
  {
       analogWrite(ENA, 100);
       digitalWrite(M1, HIGH);
       digitalWrite(M2, LOW);
       analogWrite(ENB, 100);
       digitalWrite(M3, HIGH);
       digitalWrite(M4, LOW);
       delay (1000); 
       Serial.print("Data gawang terdeteksi");
  }
  else if (   SW1 == 0 ) //
{
       analogWrite(ENA, 255); 
       digitalWrite(M1, LOW);
       digitalWrite(M2, HIGH);
       analogWrite(ENB, 255);
       digitalWrite(M3, LOW);
       digitalWrite(M4, HIGH);
       delay (100);

       analogWrite(ENA, 255); 
       digitalWrite(M1, HIGH);
       digitalWrite(M2, LOW);
       analogWrite(ENB, 255);
       digitalWrite(M3, LOW);
       digitalWrite(M4, HIGH);
       delay (200);
}
   
   // Robot maju menuju gawang
 /* else if ( SW == 0  )// 9945 Gawang B

  {
       analogWrite(ENA, 100);
       digitalWrite(M1, HIGH);
       digitalWrite(M2, LOW);
       analogWrite(ENB, 100);
       digitalWrite(M3, LOW);
       digitalWrite(M4, LOW);
       delay (1000); 
       Serial.print("Data gawang terdeteksi");
  }
  
   // Robot maju menuju gawang
  else if (  SW1 == 0 && SW == 0 )// 9945 Gawang B

  {
       analogWrite(ENA, 100);
       digitalWrite(M1, HIGH);
       digitalWrite(M2, LOW);
       analogWrite(ENB, 100);
       digitalWrite(M3, LOW);
       digitalWrite(M4, LOW);
       delay (1000); 
       Serial.print("Data gawang terdeteksi");
  }
    // Robot maju menuju gawang
  else if (  SW1 == 0 && SW == 0 && value == 5100 )// 9945 Gawang B

  {
       analogWrite(ENA, 255);
       digitalWrite(M1, HIGH);
       digitalWrite(M2, LOW);
       analogWrite(ENB, 255);
       digitalWrite(M3, HIGH);
       digitalWrite(M4, LOW); 
       Serial.print("Data gawang terdeteksi");
  }*/
  else{
     analogWrite(ENA, 100);
       digitalWrite(M1, HIGH);
       digitalWrite(M2, LOW);
       analogWrite(ENB, 100);
       digitalWrite(M3, LOW);
       digitalWrite(M4, HIGH);   
       Serial.print("cari bola ");
  }
  
}  
