#include <IRremote.h>
int RECEIVE_PIN = 11;
IRrecv irrecv(RECEIVE_PIN);
decode_results results;
void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn();
}
void loop() {
    if (irrecv.decode(&results)) {
        switch (results.value) {
            case 0xFFA25D:
            Serial.println("CH-");
            break;
            case 0xFF629D:
            Serial.println("CH");
            break;
            case 0xFFE21D:
            Serial.println("CH+");
            break;
            case 0xFF22DD:
            Serial.println("PREV");
            break;
            case 0xFF02FD:
            Serial.println("NEXT");
            break;
            case 0xFFC23D:
            Serial.println("PLAY/PAUSE");
            break;
            case 0xFFE01F:
            Serial.println("+");
            break;
            case 0xFFA857:
            Serial.println("-");
            break;
            case 0xFF906F:
            Serial.println("EQ");
            break;
        }
        irrecv.resume();
    }
}
