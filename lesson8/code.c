int sensorValue = 0;//�������sensorvalue����ֵΪ0

int outputValue = 0;//�������outputValue ����ֵΪ0

void setup()
{
  pinMode(A0, INPUT);//������A0����Ϊ����
  pinMode(9, OUTPUT);//������9����Ϊ���
  Serial.begin(9600);//�򿪴��ж˿ڣ���������������Ϊ9600 bps

}

void loop()

  sensorValue = analogRead(A0);//������A0��ȡģ��ֵ����ֵ��������sensorValue
  outputValue = map(sensorValue, 0, 1023, 0, 255);//��ģ��ֵӳ�䵽8λ(0��255)����ֵ��������sensorValue
  analogWrite(9, outputValue);//��ģ��ֵд������9

  Serial.print("sensor = ");//��"sensor="��ӡ�ڴ��м�������
  Serial.print(sensorValue);//��sensorValue��ֵ��ӡ�����м�������
  Serial.print("\t output = ");//����һ��ˮƽ�Ʊ�λ�ϴ�ӡ"output="
  Serial.println(outputValue);//��outputValue��ֵ��ӡ�����м�������

  delay(2); // ���һ�ζ�ȡ֮��ȴ���ms����ģ��ת��������һ��ѭ��ǰ�ȶ�����
}
