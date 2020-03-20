
int Relay1 = 13;
int Relay2 = 12;
int Relay3 = 11;
int Relay4 = 10;
int Realy5 = 9;
int delay1 = 1000*60*60*4;
#define moisture_pin A0  //moisture sensor A0 pin connected to arduino A0
#define ldr_pin A1
void setup() {
  //setup function
  Serial.begin(9600); //start serial communication with 9600 baudrate
  pinMode(moisture_pin, INPUT);//set moisture pin as input
  pinMode(ldr_pin, INPUT);
  delay(1000); //wait 1second
}

void loop() { //loop functiuon
  int moisture_level = map(analogRead(moisture_pin), 0, 1023, 100, 0); //read sensor and scale the reading 100% to 0%
  int ldr_level = analogRead(ldr_pin);
  delay(500); //wait 0.5seconds
  if(moisture_level <= 70) 
  {
  digitalWrite(13,LOW); //if soil moisture sensor provides LOW value send LOW value to relay
  }
  else
  {
  digitalWrite(13,HIGH); //if soil moisture sensor provides HIGH value send HIGH value to relay
  }
  delay(400); 
  if(ldr_level <=220) 
  {
  digitalWrite(12,LOW);
  delay(delay1);
  digitalWrite(11,LOW);
  delay(delay1);
  digitalWrite(10,LOW);
  delay(delay1);
  digitalWrite(9,LOW);
  delay(delay1);
  }
  else
  {
  digitalWrite(12,HIGH);
  delay(delay1);
  digitalWrite(11,HIGH);
  delay(delay1);
  digitalWrite(10,HIGH);
  delay(delay1);
  digitalWrite(9,HIGH);
  delay(delay1);
  }
 
}
