void getData(){
  separateStart;
  Serial.println("Get Data..");
  //drawTextAlignmentDemo();
  //delay(2000);
  //printBuffer();
  //delay(1000);
  display.clear();
  delayProgressWithText(F("Get Voltage"), 600, 0, 50);
  getVoltage();
  delayContinue(600,50,100);
  
  delayProgressWithText(F("Get Current"), 1000, 0, 50);
  getArus();
  delayContinue(600,50,100);
  
  delayProgressWithText(F("Get Power"), 1000, 0, 50);
  getDaya();
  delayContinue(600,50,100);
  
  delayProgressWithText(F("Get Energy"), 1000, 0, 50);
  getEnergi();
  delayContinue(600,50,100);
/*  
  delayProgressWithText(F("Get LED Sensor"), 1000, 0, 50);
  kondisiLED = getLEDSensor();
  statusLED = getLEDSensorLogic();
  delayContinue(600,50,100);
*/  
  createTextCenterBig(F("Display Data"));
  delay(1000);
  displayAllData();
  SaveToSDCard(String(v)+ "," + String(i) + "," + String(p) + "," + String(e),".csv");
  numSampling++;
  delay(4000);
  separateEnd;
}

void displayAllData(){
  display.clear();
  createTextCenter(0,"Sampling Result");
  createTextLeft(12,"Voltage     : " + String(v) + " V");
  createTextLeft(22,"Current     : " + String(i) + " A");
  createTextLeft(32,"Power       : " + String(p) + " W");
  createTextLeft(42,"Energy      : " + String(e) + " Wh");
//  createTextLeft(52,"Kondisi LED : " + kondisiLED);
  display.display();

  Serial.println(F("-------------------------"));
  Serial.println  (" Sampling #" + String(numSampling));
  Serial.println  ("-> Voltage     : " + String(v) + " V");
  Serial.println  ("-> Current     : " + String(i) + " A");
  Serial.println  ("-> Power       : " + String(p) + " W");
  Serial.println  ("-> Energy      : " + String(e) + " Wh");
//  Serial.println  ("-> Kondisi LED : " + kondisiLED);
  Serial.println(F("-------------------------"));
}
