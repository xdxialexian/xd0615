#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define S1 8
#define S2 9
#define S3 10
#define S4 11

#define LT 6
#define BT 7

void setup() 
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(S1, OUTPUT);//片选1
  pinMode(S2, OUTPUT);//片选2
  pinMode(S3, OUTPUT);//片选3
  pinMode(S4, OUTPUT);//片选4

  pinMode(LT, OUTPUT); //测试
  pinMode(BT, OUTPUT); //消隐
  digitalWrite(LT, HIGH);
  digitalWrite(BT, HIGH);
  digitalWrite(S1, HIGH);
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  digitalWrite(S4, HIGH);
}

int cnt1 = 0;
byte income[4] = {0};
void loop() 
{

  if (Serial.available() >> 0)
  {
    for (cnt1 = 0; cnt1 < 4; cnt1++) 
    {
      income[cnt1] = Serial.read();
      income[cnt1] -= '0';

      digitalWrite(cnt1 + 8, LOW);
      digitalWrite(2, income[cnt1] & 0x1);
      digitalWrite(3, (income[cnt1] >> 1) & 0x1);
      digitalWrite(4, (income[cnt1] >> 2) & 0x1);
      digitalWrite(5, (income[cnt1] >> 3) & 0x1);
      digitalWrite(cnt1 + 8, HIGH);
    }
  }
  delay(10); 
} 
