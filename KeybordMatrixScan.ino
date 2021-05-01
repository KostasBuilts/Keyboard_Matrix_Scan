int reading, indicator;


int _scanKeyb ()
{
  static long last_time;

  if (millis()-last_time >100) {
    digitalWrite(12, LOW);
    reading = PINB & 0x0f;
    digitalWrite(12, HIGH);
    if (reading != 0x0f)   return reading | 0x10; ;

    digitalWrite(13, LOW);
    reading = PINB & 0x0f;
    digitalWrite(13, HIGH);
    if (reading != 0x0f)   return reading | 0x20; ;

    digitalWrite(4, LOW);
    reading = PINB & 0x0f;
    digitalWrite(4, HIGH);
    if (reading != 0x0f)   return reading | 0x40; ;

    digitalWrite(5, LOW);
    reading = PINB & 0x0f;
    digitalWrite(5, HIGH);
    if (reading != 0x0f)   return reading | 0x80; ;
    last_time=millis();
  }

  
  return 0xff;
}




int scanKeyb()
{
  static int last_scan;
  int current_scan;

  current_scan = _scanKeyb();

  if (current_scan == last_scan) {
    current_scan = 0xff;
  }
  else {
    last_scan = current_scan;
  }

  return current_scan;
}




void setup()
{
  Serial.begin(9600);
  pinMode(8, INPUT_PULLUP);//PB0
  pinMode(9, INPUT_PULLUP);//PB1
  pinMode(10, INPUT_PULLUP);//PB2
  pinMode(11, INPUT_PULLUP);//PB3
  pinMode(12, OUTPUT);//PB4
  pinMode(13, OUTPUT);//PB5
  pinMode(4, OUTPUT);//PD4
  pinMode(5, OUTPUT);//PD5

}

void loop()
{
  int key;
  key = scanKeyb();

  if (key != 0xff)
  {
    Serial.println(key, HEX);

  }

}
