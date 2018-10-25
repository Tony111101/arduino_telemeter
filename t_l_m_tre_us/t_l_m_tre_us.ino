const byte TRIGGER_PIN = 2;
const byte ECHO_PIN = 3;
const unsigned long MEASURE_TIMEOUT = 25000UL;
const float SOUND_SPEED = 340.0/1000;

void setup() {
Serial.begin(115200);

pinMode(TRIGGER_PIN,OUTPUT);
digitalWrite(TRIGGER_PIN,LOW);
pinMode(ECHO_PIN,INPUT);
pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(TRIGGER_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN,LOW);

  long measure =pulseIn(ECHO_PIN,HIGH,MEASURE_TIMEOUT);
  float distance_mm = measure/2.0*SOUND_SPEED;

/*Résultats en m*/    
{   if (distance_mm>=1000)
   Serial.print(F("Distance: "));
   Serial.print(distance_mm / 1000.0, 2);
   Serial.println(F("m"));
}
/* Résultats en cm */  
{   if(distance_mm<1000)
     Serial.print(F("Distance: "));
     Serial.print(distance_mm/10.0,2);
     Serial.println(F("cm,"));
}
    
    if (distance_mm>200)
    { digitalWrite(LED_BUILTIN, LOW);
}
    else if (150<distance_mm<=200)
    {digitalWrite (LED_BUILTIN,HIGH);
}
    if  (100<distance_mm<=150)
    { digitalWrite(LED_BUILTIN, HIGH);  
    delay(70);                     
    digitalWrite(LED_BUILTIN, LOW);    
    delay(70); 
}   
    else if (distance_mm<=100)
    { digitalWrite(LED_BUILTIN, HIGH);  
    delay(50);                     
    digitalWrite(LED_BUILTIN, LOW);    
    delay(50);    
}   
    
    delay(300);
}
