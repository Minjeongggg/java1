// C++ code
//

int PIN_LED1 =12;
int PIN_LED2 = 10;
int PIN_LED3 = 11;
int PIN_LED4 = 13;

int PIN_TRIGER = 7;
int PIN_ECHO = 3;

void setup()
{
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);
  pinMode(PIN_LED4, OUTPUT);
  pinMode(PIN_TRIGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  
  Serial.begin(9600);
}

void loop()
{/**
  digitalWrite(pIN_LED, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(pIN_LED, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  **/
  
  int distance =0;
  digitalWrite(PIN_TRIGER, HIGH);
  delayMicroseconds(10); 
  digitalWrite(PIN_TRIGER, LOW);
  
  distance= pulseIn(PIN_ECHO,HIGH);
  int cm = distance/ 58;
  
  Serial.println(cm);
  
  if(cm > 150){
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, HIGH);
    digitalWrite(PIN_LED3, HIGH);
    digitalWrite(PIN_LED4, HIGH);
   	Serial.println("led on"); 
  } else if (150>= cm >100){
  	digitalWrite(PIN_LED2, HIGH);
    digitalWrite(PIN_LED3, HIGH);
    digitalWrite(PIN_LED4, HIGH);
    digitalWrite(PIN_LED1, LOW);
    Serial.println("led off"); 
  } else if (100>= cm > 40 ){
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, HIGH);
    digitalWrite(PIN_LED4, HIGH);
    Serial.println("led off"); 
  } else if(40 >= cm >0){
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    digitalWrite(PIN_LED3, LOW);
    digitalWrite(PIN_LED4, HIGH);
    Serial.println("led on"); 
  }
    
  
}