void UploadToThingSpeak(){
  // Connect or reconnect to WiFi
  separateStart;
  display.clear();
  Serial.println(F("Upload to ThingSpeak"));
  createTextCenter(32,F("Upload to ThingSpeak"));
  delay(2000);
  Serial.println(F("Connect to WiFi"));
  delayProgressWithText(F("Connect to WiFi"),1000,0,40);
  delay(500);
  if(WiFi.status() != WL_CONNECTED){
    Serial.print(F("Attempting to connect to SSID: "));
    delayContinue(500,40,50);
    Serial.println(SECRET_SSID);
    int n = 1;
    while((WiFi.status() != WL_CONNECTED) && (n <= retry)){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);    
      n++; 
    } 
    n = 1;
    if (WiFi.status() != WL_CONNECTED) {
      Serial.println(F("Failed to connect to Wi-Fi"));
      createTextCenter(32,F("Failed, try another Wi-Fi"));
      delay(2000);
      while((WiFi.status() != WL_CONNECTED) && (n <= retry)){
        WiFi.begin(ssid2, pass2);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
        Serial.print(".");
        delay(5000);    
        n++; 
      } 
    }
    getIPWiFi();
    delayContinue(500,50,100);
  } else {
    Serial.println(F("Already Connected"));
    getIPWiFi();
    delayContinue(1000,40,100);
  }

  delayProgressWithText(F("Initiate Upload"), 1000, 0, 30);
  Serial.println(F("Initiate Upload..."));
  // set the fields with the values
  ThingSpeak.setField(1, v);
  ThingSpeak.setField(2, i);
  ThingSpeak.setField(3, p);
  ThingSpeak.setField(4, e);
  ThingSpeak.setField(5, statusLED);
  Serial.println(F("Thingspeak Field Set!"));
  delayContinue(500,30,40);
  delay(1000);
  // write to the ThingSpeak channel
  Serial.println(F("Uploading..."));
  createTextCenterBig(F("Uploading"));
  delay(1000);
  display.clear();
  delayContinue(1000, 40, 50);
  //delay(2000);
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  display.clear();
  if(x == 200){
    Serial.println(F("Channel update successful."));
    delayContinue(1000,50,100);
    createTextCenterBig(F("Success"));
    delay(3000);
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
    delayContinue(1000,50,100);
    createTextCenterBig(F("Failed"));
    delay(3000);
  }
  separateEnd;
}

void getIPWiFi(){
    display.clear();
    IPAddress myIP = WiFi.localIP();
    String ipStr = String(myIP[0])+"."+String(myIP[1])+"."+String(myIP[2])+"."+String(myIP[3]);
    
    createTextCenter(12,F("WiFi Connected"));
    createTextCenter(22,F("IP address:"));
    createTextCenter(32,ipStr);
    
    Serial.println(F("WiFi connected"));
    Serial.println(F("IP address: "));
    Serial.println(WiFi.localIP());
    delay(2000);
}
