int L;
void setupLight(){
  pinMode(LIGHT,INPUT);
}

String Light_Message(){
  String message = "";
  L = digitalRead(LIGHT);
  if(L == HIGH){
    message = "Co";
  }
  else{
    message = "Khong";
  }

  return message;
}
int Relay2(){
  int light;
  L = digitalRead(LIGHT);
  if(L == HIGH){
    light = 3;
  }else{
    light = 4;
  }
  return light;
}
