//Send.ino

#include<SPI.h>
#include<RF24.h>

// ce, csn pins
RF24 radio(9, 10);

void setup(void){
  Serial.begin(9600); 
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(0x76);
  radio.openWritingPipe(0xF0F0F0F0E1LL);
  radio.enableDynamicPayloads();
  radio.powerUp();

}

void loop(void){
    const char text[] = "Hello World is awesome";
  radio.write(&text, sizeof(text));
  Serial.println("Just sent a message");
  delay(1000);

}
