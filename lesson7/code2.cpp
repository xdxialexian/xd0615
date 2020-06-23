#include <MsTimer2.h>     //��ʱ�����ͷ�ļ�
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
#define S1 13
#define LT 8
#define BT 3
#define key 1


int tick = 0; //����ֵ
int state = 0;
int pinInterrupt = 3; //���ж��źŵĽ�
 
//�жϷ������
void onTimer()
{
    tick++;
    if(tick > 9)
    {
      tick=0;
    }
}
void control()
{
  tick=0;
}
 
void setup()
{
  pinMode(IN1, OUTPUT);//����1
  pinMode(IN2, OUTPUT);//����2
  pinMode(IN3, OUTPUT);//����3
  pinMode(IN4, OUTPUT);//����4
  pinMode(S1, OUTPUT);//Ƭѡ1
  pinMode(LT,OUTPUT);//����
  pinMode(BT,OUTPUT);//����
  pinMode(key, INPUT_PULLUP);
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH); 
  digitalWrite(S1,HIGH);
  Serial.begin(9600); //��ʼ������
  
  MsTimer2::set(1000, onTimer); //�����жϣ�ÿ1000ms����һ���жϷ������ onTimer()
  MsTimer2::start(); //��ʼ��ʱ
  attachInterrupt(key,control,CHANGE);
}

void loop()
{
    digitalWrite(S1,LOW);
    digitalWrite(4,tick&0x1);
    digitalWrite(5,(tick>>1)&0x1);
    digitalWrite(6,(tick>>2)&0x1);
    digitalWrite(7,(tick>>3)&0x1);
    delay(1000); 
}
