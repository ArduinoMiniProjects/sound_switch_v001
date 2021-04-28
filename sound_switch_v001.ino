
int sound_sensor = 2; // pin 2 is used for sound sensor
bool current_state = true; // current state of sensor

bool relay_on = false;


void setup()
{
  //Serial.begin(9600); //initialize serial
  pinMode(sound_sensor, INPUT); // set sensor pin as input
  pinMode(sound_sensor, INPUT_PULLUP); // set pull up resistor
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT); // connceted to N-channel MOSFET transistor
}


void loop()
{
  current_state = digitalRead(sound_sensor);

  if( current_state )
  {
    //Serial.println(current_val);
    
    if( !relay_on )
    {
      relay_on = true;
      digitalWrite(13, HIGH);
      digitalWrite(7, HIGH);
      //Serial.println("Led ON.");
    }
    else if( relay_on)
    {
      relay_on = false;
      digitalWrite(13, LOW);
      digitalWrite(7, LOW);
      //Serial.println("Led OFF.");
    }
    
    delay(500);
  }
}
