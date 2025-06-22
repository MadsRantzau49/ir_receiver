#include <Arduino.h>
#line 1 "C:\\Users\\madsr\\Documents\\code\\remote_remote_control\\remote_remote_control.ino"
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const int RECV_PIN = 5;  // Bedste pin: GPIO4 (D4)
IRrecv irrecv(RECV_PIN);
decode_results results;

#line 9 "C:\\Users\\madsr\\Documents\\code\\remote_remote_control\\remote_remote_control.ino"
void setup();
#line 17 "C:\\Users\\madsr\\Documents\\code\\remote_remote_control\\remote_remote_control.ino"
void loop();
#line 9 "C:\\Users\\madsr\\Documents\\code\\remote_remote_control\\remote_remote_control.ino"
void setup() {
  Serial.begin(115200);
  while (!Serial);  // Vent på Serial til debug
  
  irrecv.enableIRIn();  // Start modtager
  Serial.println("IR Receiver klar - venter på signal...");
}

void loop() {
  if (irrecv.decode(&results)) {
    // Print rå data i HEX + protokoltype
    Serial.print("Kode: 0x");
    serialPrintUint64(results.value, HEX);
    Serial.print(" | Protokol: ");
    Serial.println(typeToString(results.decode_type));
    
    irrecv.resume();  // Clear buffer
    delay(10);        // Watchdog-sikkerhed
  }
}
