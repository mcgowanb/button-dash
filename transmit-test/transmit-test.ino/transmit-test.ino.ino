#include <SPI.h>
#include<RF24.h>
RF24 radio(9, 10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int msg[1];
String message[] = {"T","E","S","T", "0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"};

int SW1 = 7;
void setup(void) {
  Serial.begin(9600);
  radio.begin();
  pinMode(SW1, INPUT);
   Serial.println("Initialising");
   radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(0x76);
  radio.openWritingPipe(0xF0F0F0F0E1LL);
  const uint64_t pipe = 0xE8E8F0F0E1LL;
  radio.openReadingPipe(1, pipe);

  radio.enableDynamicPayloads();
  radio.powerUp();
  
}
void loop(void) {
  if (digitalRead(SW1) == HIGH) {
    //message[] = {'T','E','S','T'};
    radio.write(message, 1);
    Serial.println("Sending MessageW");;
  }
 
}
