#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const int RECV_PIN = 5;  
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(115200);
  while (!Serial);  
  
  irrecv.enableIRIn(); 
  Serial.println("IR Receiver klar - venter på signal...");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Kode: 0x");
    serialPrintUint64(results.value, HEX);
    Serial.print(" | Protokol: ");
    Serial.println(typeToString(results.decode_type));
    
    irrecv.resume();  
    delay(10);       
  }
}
