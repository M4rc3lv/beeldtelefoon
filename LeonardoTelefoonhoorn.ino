#include <Keyboard.h>
#define LDR_PEN      A0
#define LDR_TRESHOLD 900
#define HOORN        7

// Toetsenbord instellen in Linux:
// Ctrl+Shift+Alt+M ==> mute.sh
// Ctrl+Shift+Alt+I ==> aan.sh
// Cttrl+Shift+Alt+O ==> Toggle Teams Mute

bool IsGemute=false;

void setup(){
 delay(1000);
 pinMode(HOORN,INPUT_PULLUP);
 Serial.begin(115200);
 Keyboard.begin();
 Mute();
}

void Toggle() { 
 Keyboard.press(KEY_LEFT_SHIFT);
 Keyboard.press(KEY_LEFT_ALT);
 Keyboard.press(KEY_LEFT_CTRL);
 Keyboard.press('O');
 delay(100);
 Keyboard.releaseAll();
 IsGemute = !IsGemute;
}


void Mute() {
 if(IsGemute) return;
 
 IsGemute=true;
 Keyboard.press(KEY_LEFT_SHIFT);
 Keyboard.press(KEY_LEFT_ALT);
 Keyboard.press(KEY_LEFT_CTRL);
 Keyboard.press('M');
 delay(100);
 Keyboard.releaseAll();
}

void Aan() {
 if(!IsGemute) return;
 
 IsGemute=false;
 Keyboard.press(KEY_LEFT_SHIFT);
 Keyboard.press(KEY_LEFT_ALT);
 Keyboard.press(KEY_LEFT_CTRL);
 Keyboard.press('I');
 delay(100);
 Keyboard.releaseAll();
}


void loop(){
 int LDRReading = analogRead(LDR_PEN); 
 Serial.println(LDRReading);
 if(LDRReading>=LDR_TRESHOLD || digitalRead(HOORN)==HIGH/*Hoorn neer*/) Mute();
 else Aan();
 
 //if(IsGemute && LDRReading<LDR_TRESHOLD
 //|| !IsGemute && LDRReading>=LDR_TRESHOLD)
 // Toggle();
 
 delay(200);
 Serial.println(digitalRead(HOORN)==LOW);
}
