int i;
void setup()
{ for(i=0;i<8;)
  {
      pinMode(i, OUTPUT);
      i=i+2;
  }
}

void loop()
{ for(i=0;i<8;)
  {
      digitalWrite(i, HIGH);
      delay(500); // Wait for 1000 millisecond(s)
      digitalWrite(i, LOW);
      delay(500); // Wait for 1000 millisecond(s)
      i=i+2;  
  }
}
