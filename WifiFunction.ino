void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  Serial.println(myWiFiManager->getConfigPortalSSID());
}

void WiFiManagerFunction(){
  WiFiManager wifiManager;
//  wifiManager.resetSettings();
  
  wifiManager.setAPStaticIPConfig(IP, Gateway, Subnet);
  
  wifiManager.setTimeout(180);
  wifiManager.setAPCallback(configModeCallback);
  if (!wifiManager.autoConnect(ssidAP,passAP)) {
    Serial.println("failed to connect and hit timeout");
    ESP.reset();
    delay(1000);
  }
  Serial.println("connected...yeey :)");
}

void connectToWifi(){
  Serial.println(F("Connect to WiFi"));
  delay(500);
  if(WiFi.status() != WL_CONNECTED){
    Serial.print(F("Attempting to connect to SSID: "));
    Serial.println(SECRET_SSID);
    int n = 1;
    while((WiFi.status() != WL_CONNECTED) && (n <= retry)){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    //WiFi.setAutoReconnect(true);
    getIPWiFi();
  } else {
    Serial.println(F("Already Connected"));
    getIPWiFi();
  }
}
