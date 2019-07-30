#include "config.h"
void setup() {
  initFunc();
}

void loop() { 
  display.clear();
  createTextCenterBig("Sampling #" + String(numSampling));
  delay(2000);
  getData();
  UploadToThingSpeak();
  //UploadToDashboard();
  delayProgressWithTextLong(F("Next Upload In"), (timeSampling*1000), 0, 100);
}
