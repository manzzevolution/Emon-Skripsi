void initNTP(){
  timeClient.begin();
}

String getTimeNTP(){
  Serial.println("Getting NTP Time.....");
  for (int i = 0 ; i < 10 ; i++){
    timeClient.update();
    tahun = timeClient.getYear(); 
    bulan = timeClient.getMonth(); 
    tanggal = timeClient.getDate();
    
    jam = timeClient.getHours();
    menit = timeClient.getMinutes();
    detik = timeClient.getSeconds();
    Serial.println(timeClient.getFullFormattedTime());
    if ((tahun > 1970) && (tahun < 2050)){
      break;
    }
    delay(1000);
  }
  return timeClient.getFullFormattedTime();
}
