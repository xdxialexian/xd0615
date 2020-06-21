char ch;
void setup()
{
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  Serial.println("start");
}

/*
'w':表示前进
's':表示后退
'd':表示右转
'a':表示左转
'b':表示停止
*/
void go()
{
   digitalWrite(6,HIGH);
   digitalWrite(7,LOW);
   digitalWrite(8,HIGH);
   digitalWrite(9,LOW);
   digitalWrite(2,LOW);
   digitalWrite(3,LOW);
} 
void back()
{
   digitalWrite(7,HIGH);
   digitalWrite(6,LOW);
   digitalWrite(9,HIGH);
   digitalWrite(8,LOW);
   digitalWrite(2,LOW);
   digitalWrite(3,LOW);
} 
void right()
{
   digitalWrite(7,HIGH);
   digitalWrite(6,LOW);
   digitalWrite(8,HIGH);
   digitalWrite(9,LOW);
   digitalWrite(2,LOW);
   digitalWrite(3,LOW);
} 
void left()
{
   digitalWrite(6,HIGH);
   digitalWrite(7,LOW);
   digitalWrite(9,HIGH);
   digitalWrite(8,LOW);
   digitalWrite(2,LOW); 
   digitalWrite(3,LOW);
} 
void stop()
{
   digitalWrite(6,LOW);
   digitalWrite(7,LOW);
   digitalWrite(8,LOW);
   digitalWrite(9,LOW);
   digitalWrite(2,HIGH); 
   digitalWrite(3,LOW);
}  
void loop()
{
  if(Serial.available()>0)
  {
    ch=Serial.read();
      switch(ch)
     {
     case 'w':
       go();
     break;
     case 's':
       back();
     break;
     case 'd':
       right();
     break;
     case 'a':
       left();
     break;
     case 'b':
       stop();
     break;
     default:
     break;
    }   
  }
}
