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
    switch(key)
    {
      case 0x1E:
        Serial.println("1");
        break;

      case 0x2E:
        Serial.println("2");
        break;
      
      case 0x4E:
        Serial.println("3");
        break;
      
      case 0x8E:
        Serial.println("A");
        break;

      case 0x1D:
        Serial.println("4");
        break;

      case 0x2D:
        Serial.println("5");
        break;
      
      case 0x4D:
        Serial.println("6");
        break;
      
      case 0x8D:
        Serial.println("B");
        break;

      case 0x1B:
        Serial.println("7");
        break;

      case 0x2B:
        Serial.println("8");
        break;
      
      case 0x4B:
        Serial.println("9");
        break;
      
      case 0x8B:
        Serial.println("C");
        break;

      case 0x17:
        Serial.println("*");
        break;

      case 0x27:
        Serial.println("0");
        break;
      
      case 0x47:
        Serial.println("#");
        break;
      
      case 0x87:
        Serial.println("D");
        break;
    }

  }

}
