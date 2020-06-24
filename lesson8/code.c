int sensorValue = 0;//定义变量sensorvalue并赋值为0

int outputValue = 0;//定义变量outputValue 并赋值为0

void setup()
{
  pinMode(A0, INPUT);//将引脚A0设置为输入
  pinMode(9, OUTPUT);//将引脚9设置为输出
  Serial.begin(9600);//打开串行端口，将数据速率设置为9600 bps

}

void loop()

  sensorValue = analogRead(A0);//从引脚A0读取模拟值并把值赋给变量sensorValue
  outputValue = map(sensorValue, 0, 1023, 0, 255);//将模拟值映射到8位(0到255)并把值赋给变量sensorValue
  analogWrite(9, outputValue);//将模拟值写入引脚9

  Serial.print("sensor = ");//把"sensor="打印在串行监视器上
  Serial.print(sensorValue);//把sensorValue的值打印到串行监视器上
  Serial.print("\t output = ");//在下一个水平制表位上打印"output="
  Serial.println(outputValue);//把outputValue的值打印到串行监视器上

  delay(2); // 最后一次读取之后等待两ms，让模拟转换器在下一次循环前稳定下来
}
