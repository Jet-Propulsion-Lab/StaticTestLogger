const int button = 13;
const int trigger = 12;
const int led = 2; 

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  int buttonvalue = analogRead(button);

  digitalWrite(led, LOW);
    for (int i = 0; i < 30; i++ )
    {
      digitalWrite(led,HIGH);
      delay(500);
      digitalWrite(led,LOW);
      delay(500);
    }
    analogWrite(trigger,255);
    for (int i = 0; i < 20; i++ )
    {
      delay(500);
    }
    analogWrite(trigger, 0);

}
