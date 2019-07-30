void initFunc(){
  Serial.begin(115200);
  startlogo();
  separateStart;
  // Oled Init
  display.init();
  display.flipScreenVertically();
  delayProgress(2500);
  delay(500);
  display.clear();
  drawImageXBM();
  createTextCenter(52,F("Sys-Notifier - Manzz_Evo"));
  display.display();
  delay(5000);
  
  // PZEM Init
  Serial.println(F("Initializing PZEM-004T"));
  delayProgressWithText2(F("Init PZEM-004T"),500,500,0,50);
  pzem.setAddress(ip);
  delayContinue(250,50,100);
  Serial.println(F("Done"));
  
  // Wifi Init
  String ipStr = String(IP[0])+"."+String(IP[1])+"."+String(IP[2])+"."+String(IP[3]);
  Serial.println(F("Initializing WiFi"));
  delayProgressWithText2(F("Init WiFi"),500,500,0,100);
  createTextCenter(0,F("Connect to AP"));
  createTextCenter(12,"SSID :" + String(ssidAP));
  createTextCenter(24,"Pass :" + String(passAP));
  createTextCenter(38,"IP :" + ipStr);
  createTextCenter(52,F("If not connected"));
  WiFiManagerFunction();
  WiFi.mode(WIFI_STA); 
  ThingSpeak.begin(client);  // Initialize ThingSpeak
  delayContinue(250,50,100);
  Serial.println(F("Done"));

  //init NTP
  delayProgressWithText2(F("Init NTP"),500,500,0,50);
  initNTP();
  getTimeNTP();
  delayContinue(500,50,100);
  createTextCenter(0,F("Now Date Time"));
  createTextCenter(24,getTimeNTP());
  delay(4000);

  //initSDCard
  delayProgressWithText2(F("Init SDCard"),500,500,0,50);
  if(initSDCard()){
    delayContinue(250,50,100);
    SdFile::dateTimeCallback(fileDateTime);
    createTextCenterBig(F("SD Card OK"));
    delay(2000);
  } else {  
    delayContinue(500,50,100);
    createTextCenterBig(F("SD Card Fail"));
    delay(2000);
  }
  separateEnd;
}
