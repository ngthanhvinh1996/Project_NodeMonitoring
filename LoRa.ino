
void setupLoRa(){
  Serial.println("[LoRa] Setting up LoRa");

  SPI.begin();
  while(!LoRa.begin(LORA_FREQ)){
    Serial.println("[LoRa] Starting LoRa failed.");
    delay(1000);
  }

  LoRa.setSpreadingFactor(LORA_SF);
  LoRa.setCodingRate4(LORA_CR);
  LoRa.setSignalBandwidth(LORA_BW);
  LoRa.setPreambleLength(LORA_PREAMBLE_LENGTH);

  LoRa.enableCrc();
}

String receiveLoRaMessage(){
  int packetSize = LoRa.parsePacket();
  if(packetSize == 0){
    return "";
  }

  int recipient = LoRa.read();
  byte sender = LoRa.read();
//  int incomingMsg = LoRa.read();
//  byte incomingLength = LoRa.read();

  String incoming = "";
  while(LoRa.available()){
    incoming += (char)LoRa.read();
  }

  if(recipient != localAddress){
    Serial.println("[LoRa] This message not for me");
    return "";
  }

  Serial.println("Received from: 0x" + String(recipient,HEX));
  Serial.println("Send to: 0x" + String(sender,HEX));
  Serial.println("Message: " + incoming);
  Serial.println("RSSI: " + String(LoRa.packetRssi()));
  Serial.println("SNR: " + String(LoRa.packetSnr()));

  return incoming;
}

void sendGWMessage(String outgoing){
  LoRa.beginPacket();
  LoRa.write(destination);
  LoRa.write(localAddress);
  LoRa.print(outgoing);
  LoRa.endPacket();
  Serial.println("[LoRa]Sending: " + outgoing);
  Serial.println("RSSI GW: " + String(LoRa.packetRssi()));
  Serial.println("SNR GW: " + String(LoRa.packetSnr()));
}

void sendNodeMessage(){
  LoRa.beginPacket();
  LoRa.write(destination1);
  LoRa.write(localAddress);
  LoRa.write(t);
  LoRa.write(h);
  LoRa.write(l);
  LoRa.write(sr602);
  LoRa.endPacket();
  Serial.println("Send to Node");
  Serial.println("RSSI Node: " + String(LoRa.packetRssi()));
  Serial.println("SNR Node: " + String(LoRa.packetSnr()));
}
