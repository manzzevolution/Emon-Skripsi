void getVoltage(){
  v = pzem.voltage(ip);
  if (v < 0.0) v = 0.0;
  Serial.print(v);Serial.println("V; ");
}
void getArus(){
  i = pzem.current(ip);
  if(i >= 0.0){ Serial.print(i);Serial.println("A; "); }
}
void getDaya(){
  p = pzem.power(ip);
  if(p >= 0.0){ Serial.print(p);Serial.println("W; "); }
}
void getEnergi(){
  e = pzem.energy(ip);
  if(e >= 0.0){ Serial.print(e);Serial.println("Wh; "); }
}
