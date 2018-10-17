int ledFade = 3;
int ledBlink = 2;
int button = 4;
int buttonState = 0;
bool litt = true;
void setup(){
	pinMode(ledFade, OUTPUT);
	pinMode(ledBlink, OUTPUT);
	pinMode(button, OUTPUT);
	analogWrite(ledFade, 255);
	digitalWrite(ledBlink, LOW);
}
void loop(){
	buttonState = digitalRead(button);
	if(buttonState == 1 && litt == true){
	    fadetoL();
	    blinkOnce();
	}
	else if(litt == false && buttonState == 0){
		fadetoH();
	}

	delay(1);
}

void fadetoL(){
    for(int i=255; i>63; i--){
        analogWrite(ledFade, i);
        delay(1);
    }
    litt = false;
}

void fadetoH(){
    for(int i=64; i<256; i++){
        analogWrite(ledFade, i);
        delay(1);
    }
    litt = true;
}

void blinkOnce(){
	digitalWrite(ledBlink, HIGH);
	delay(100);
	digitalWrite(ledBlink, LOW);
}
