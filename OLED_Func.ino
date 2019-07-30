
// Adapted from Adafruit_SSD1306
void drawLines() {
  for (int16_t i=0; i<DISPLAY_WIDTH; i+=4) {
    display.drawLine(0, 0, i, DISPLAY_HEIGHT-1);
    display.display();
    delay(10);
  }
  for (int16_t i=0; i<DISPLAY_HEIGHT; i+=4) {
    display.drawLine(0, 0, DISPLAY_WIDTH-1, i);
    display.display();
    delay(10);
  }
  delay(250);

  display.clear();
  for (int16_t i=0; i<DISPLAY_WIDTH; i+=4) {
    display.drawLine(0, DISPLAY_HEIGHT-1, i, 0);
    display.display();
    delay(10);
  }
  for (int16_t i=DISPLAY_HEIGHT-1; i>=0; i-=4) {
    display.drawLine(0, DISPLAY_HEIGHT-1, DISPLAY_WIDTH-1, i);
    display.display();
    delay(10);
  }
  delay(250);

  display.clear();
  for (int16_t i=DISPLAY_WIDTH-1; i>=0; i-=4) {
    display.drawLine(DISPLAY_WIDTH-1, DISPLAY_HEIGHT-1, i, 0);
    display.display();
    delay(10);
  }
  for (int16_t i=DISPLAY_HEIGHT-1; i>=0; i-=4) {
    display.drawLine(DISPLAY_WIDTH-1, DISPLAY_HEIGHT-1, 0, i);
    display.display();
    delay(10);
  }
  delay(250);
  display.clear();
  for (int16_t i=0; i<DISPLAY_HEIGHT; i+=4) {
    display.drawLine(DISPLAY_WIDTH-1, 0, 0, i);
    display.display();
    delay(10);
  }
  for (int16_t i=0; i<DISPLAY_WIDTH; i+=4) {
    display.drawLine(DISPLAY_WIDTH-1, 0, i, DISPLAY_HEIGHT-1);
    display.display();
    delay(10);
  }
  delay(250);
}

// Adapted from Adafruit_SSD1306
void drawRect(void) {
  for (int16_t i=0; i<DISPLAY_HEIGHT/2; i+=2) {
    display.drawRect(i, i, DISPLAY_WIDTH-2*i, DISPLAY_HEIGHT-2*i);
    display.display();
    delay(10);
  }
}

// Adapted from Adafruit_SSD1306
void fillRect(void) {
  uint8_t color = 1;
  for (int16_t i=0; i<DISPLAY_HEIGHT/2; i+=3) {
    display.setColor((color % 2 == 0) ? BLACK : WHITE); // alternate colors
    display.fillRect(i, i, DISPLAY_WIDTH - i*2, DISPLAY_HEIGHT - i*2);
    display.display();
    delay(10);
    color++;
  }
  // Reset back to WHITE
  display.setColor(WHITE);
}

// Adapted from Adafruit_SSD1306
void drawCircle(void) {
  for (int16_t i=0; i<DISPLAY_HEIGHT; i+=2) {
    display.drawCircle(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, i);
    display.display();
    delay(10);
  }
  delay(1000);
  display.clear();

  // This will draw the part of the circel in quadrant 1
  // Quadrants are numberd like this:
  //   0010 | 0001
  //  ------|-----
  //   0100 | 1000
  //
  display.drawCircleQuads(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, DISPLAY_HEIGHT/4, 0b00000001);
  display.display();
  delay(200);
  display.drawCircleQuads(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, DISPLAY_HEIGHT/4, 0b00000011);
  display.display();
  delay(200);
  display.drawCircleQuads(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, DISPLAY_HEIGHT/4, 0b00000111);
  display.display();
  delay(200);
  display.drawCircleQuads(DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, DISPLAY_HEIGHT/4, 0b00001111);
  display.display();
}

void printBuffer(void) {
  display.clear();
  // Initialize the log buffer
  // allocate memory to store 8 lines of text and 30 chars per line.
  display.setLogBuffer(5, 30);

  // Some test data
  const char* test[] = {
      "Hello",
      "World" ,
      "----",
      "Show off",
      "how",
      "the log buffer",
      "is",
      "working.",
      "Even",
      "scrolling is",
      "working"
  };

  for (uint8_t i = 0; i < 11; i++) {
    display.clear();
    // Print to the screen
    display.println(test[i]);
    // Draw it to the internal screen buffer
    display.drawLogBuffer(0, 0);
    // Display it on the screen
    display.display();
    delay(500);
  }
}

void drawImage(void){
  display.clear();
  //display.drawXbm(50,50, logo_width, logo_height, logo_bits);
  //delay(1000);
}

void drawProgress(int progress) {
  // The coordinates define the center of the text
  // draw the progress bar
  display.drawProgressBar(0, 32, 120, 10, progress);

  // draw the percentage as String
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(64, 15, "     ");
  display.display();
  display.drawString(64, 15, String(progress) + "%");
  display.display();
}

void drawTextAlignmentDemo() {
    // Text alignment demo
  display.clear();
  display.setFont(ArialMT_Plain_10);

  // The coordinates define the left starting point of the text
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0, 10, "Left aligned (0,10)");

  // The coordinates define the center of the text
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(64, 22, "Center aligned (64,22)");

  // The coordinates define the right end of the text
  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(128, 33, "Right aligned (128,33)");
  display.display();
}

void drawImageXBM() {
    // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
    // on how to create xbm files
    display.drawXbm((64 - (sensyncLogo_width/2)), (32 - (sensyncLogo_height/2)), sensyncLogo_width, sensyncLogo_height, sensyncLogo_bits);
}

void createTextCenter(int y, String text){
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(64, y, text);
  display.display();
}

void createTextCenterBig(String text){
  display.setFont(ArialMT_Plain_16);
  createTextCenter(24,text);
  display.setFont(ArialMT_Plain_10);
  display.display();
}

void createTextLeft(int y, String text){
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0, y, text);
}

void createTextRight(int y, String text){
  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(128, y, text);
}
void delayProgress(long delayTime){
  long tempTime = delayTime / 100;
  for(int i = 0;i<=100;i++){
    display.clear();
    drawProgress(i);
    delay(tempTime);
  }
}

void delayContinue(long delayTime,int fromProgressBar ,int toProgressBar){
  long tempTime = delayTime/ (toProgressBar - fromProgressBar);
  for(int i = fromProgressBar; i<=toProgressBar ; i++){
    //createTextCenter(0,text);
    drawProgress(i);
    delay(tempTime);
    display.clear();
  }
}

void delayProgressWithText(String text, long delayTime,int fromProgressBar ,int toProgressBar){
  long tempTime = (delayTime - 500) / (toProgressBar - fromProgressBar);
  display.clear();
  display.setFont(ArialMT_Plain_16);
  createTextCenter(24,text);
  display.setFont(ArialMT_Plain_10);
  delay(500);
  display.clear();
  for(int i = 0 ; i<=(toProgressBar - fromProgressBar) ; i++){
    //createTextCenter(0,text);
    drawProgress(i);
    delay(tempTime);
    display.clear();
  }
}
void delayProgressWithText2(String text, long delayTime, long initiateDelay,int fromProgressBar ,int toProgressBar){
  long tempTime = (delayTime - initiateDelay) / (toProgressBar - fromProgressBar);
  display.clear();
  display.setFont(ArialMT_Plain_16);
  createTextCenter(24,text);
  display.setFont(ArialMT_Plain_10);
  delay(initiateDelay);
  display.clear();
  for(int i = 0 ; i<=(toProgressBar - fromProgressBar) ; i++){
    //createTextCenter(0,text);
    drawProgress(i);
    delay(tempTime);
    display.clear();
  }
}
void noDelayProgress(int n){
  drawProgress(n);
  display.clear();
}
void delayProgressWithTextLong(String text, long delayTime,int fromProgressBar ,int toProgressBar){
  long tempTime = (delayTime - 500) / (toProgressBar - fromProgressBar);
  display.clear();
  display.setFont(ArialMT_Plain_16);
  createTextCenter(24,text);
  display.setFont(ArialMT_Plain_10);
  delay(500);
  display.clear();
  for(int i = 0 ; i<=(toProgressBar - fromProgressBar) ; i++){
    createTextCenter(0,text);
    drawProgress(i);
    delay(tempTime);
    display.clear();
  }
}
