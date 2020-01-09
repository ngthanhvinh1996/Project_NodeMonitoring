#include "Node_Monitoring.h"

DHT dht(DHTPIN, DHTTYPE);
byte destination = 0xFF;
byte destination1 = 0xA2;
byte localAddress = 0xA1;
int control;
int control1;
int sr602;

float h, t;
int l;
String s;
void setup() {
  Serial.begin(BAUD_RATE);
  dht.begin();
  setupLoRa();
  setupLight();
  pinMode(4,INPUT);
  pinMode(3,INPUT);
  pinMode(A0,INPUT);
}

void loop() {
  h = dht.readHumidity();
  t = dht.readTemperature();
  l = Relay2();

  sr602 = digitalRead(3);
  if(sr602 == LOW){
    s = "K"; 
  }else if(sr602 == HIGH){
    s = "C"; 
  }


  String Tem_Mess = String("\"T\":") + String(t);
  String Hum_Mess = String("\"H\":") + String(h);  
  String sr602_Mess = String("\"Tr\":") + String(s);
  String Light_Mess = String("\"N\":") + Light_Message();
  String Mq_Mess = String("\"KK\":") + MQ135_Sensor();
  sendGWMessage("{" + Tem_Mess + "," + Hum_Mess + "," + Light_Mess + "," + sr602_Mess + "," + Mq_Mess + ",");
  sendNodeMessage();
  delay(3000);
 
}
