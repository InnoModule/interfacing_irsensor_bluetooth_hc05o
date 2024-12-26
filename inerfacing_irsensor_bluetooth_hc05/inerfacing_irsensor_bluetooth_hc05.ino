#include <IRremote.h>
#include <SoftwareSerial.h>

const int recv_pin = 2;  


IRrecv irrecv(recv_pin);
decode_results results;
SoftwareSerial BTserial(10, 11);

void setup() {
  
  Serial.begin(9600);   
  BTserial.begin(9600);  

  irrecv.enableIRIn();  
  Serial.println("IR and Bluetooth test!");
}

void loop() {
  
  if (irrecv.decode(&results)) {
    long int decCode = results.value;
    Serial.println(decCode);  
    irrecv.resume();  
    
    BTserial.println(decCode);  

    delay(500);  
  }
}
