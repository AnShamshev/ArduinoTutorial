#define PIN_PHOTO_SENSOR A1

void setup() {
  pinMode(PIN_PHOTO_SENSOR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(PIN_PHOTO_SENSOR);
  Serial.println(val);
}
      
    
