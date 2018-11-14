#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 90;    // variable to store the servo position
int button1 = 4;
int button2 = 3;

void setup() {
  myservo.attach(7);  // attaches the servo on pin 9 to the servo object
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  myservo.write(pos);
  Serial.begin(9600);
}


void loop(){
  noTone(11);
	while (digitalRead(button1) == 1){
		delay(10);
		pos++;
		if (pos <= 180) {
			myservo.write(pos);
		}
		else {
		  buzz();
		  pos = 180;
		}
	}

	while (digitalRead(button2) == 1){
		delay(10);
    
		pos--;
		if (pos >= 0) {
			myservo.write(pos);
		}
		else {
		  buzz();
		  pos = 0;
		}
	}
}

void buzz() {
  tone(11, 440);
}
