#include <MsTimer2.h>     //定时器库的头文件
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
#define S1 13
#define LT 8
#define BT 3
#define key 1


int tick = 0; //计数值
int state = 0;
int pinInterrupt = 3; //接中断信号的脚
 
//中断服务程序
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
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(S1, OUTPUT);//片选1
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐
  pinMode(key, INPUT_PULLUP);
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH); 
  digitalWrite(S1,HIGH);
  Serial.begin(9600); //初始化串口
  
  MsTimer2::set(1000, onTimer); //设置中断，每1000ms进入一次中断服务程序 onTimer()
  MsTimer2::start(); //开始计时
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
