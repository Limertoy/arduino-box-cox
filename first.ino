#define DECODE_NEC
#include <IRremote.hpp>

const int RELAY1_PIN = 9;
const int RELAY2_PIN = 3;
const int RECV_PIN = 7;
//IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  digitalWrite(RELAY1_PIN, LOW);
  digitalWrite(RELAY2_PIN, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(IrReceiver.decode()){
    if(IrReceiver.decodedIRData.decodedRawData == 3927295800){
      digitalWrite(RELAY2_PIN, LOW);
      delay(4000);
      digitalWrite(RELAY2_PIN, HIGH);
      digitalWrite(RELAY1_PIN, HIGH);
      delay(9000);
      digitalWrite(RELAY1_PIN, LOW);
    } else if (IrReceiver.decodedIRData.decodedRawData == 3910584120){
      digitalWrite(RELAY2_PIN, LOW);
      delay(4500);
      digitalWrite(RELAY2_PIN, HIGH);
      digitalWrite(RELAY1_PIN, HIGH);
      delay(8500);
      digitalWrite(RELAY1_PIN, LOW);
    } else if (IrReceiver.decoded
    IRData.decodedRawData == 3893872440){
      digitalWrite(RELAY2_PIN, LOW);
      delay(5000);
      digitalWrite(RELAY2_PIN, HIGH);
      digitalWrite(RELAY1_PIN, HIGH);
      delay(8000);
      digitalWrite(RELAY1_PIN, LOW);
    }
    Serial.println(IrReceiver.decodedIRData.decodedRawData);
    
    IrReceiver.resume();
  }
}
