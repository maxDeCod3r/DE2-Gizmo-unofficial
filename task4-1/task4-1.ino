#define a1 9
#define a2 10

#define b1 5
#define b2 6

#define l1 A0
#define l2 A1

int l1Val = 0;
int l2Val = 0;

int M1 = 0;
int M2 = 0;
	
void setup() {
		Serial.begin(9600);
		pinMode(a1, OUTPUT);
		pinMode(a2, OUTPUT);
		pinMode(b1, OUTPUT);
		pinMode(b2, OUTPUT);
		digitalWrite(a1, LOW);
		digitalWrite(b1, LOW);
}

	
void loop() {
	l1Val = analogRead(l1);
	l2Val = analogRead(l2);


	M1 = map(l1Val, 300, 1023, 50, 255);
	M2 = map(l2Val, 300, 1023, 50, 255);
	Serial.print(l1Val);
  Serial.print("   ");
  Serial.print(l2Val);
  Serial.print("   ");
  Serial.print(M1);
  Serial.print("   ");
  Serial.println(M2);
	analogWrite(a1, M1);
	analogWrite(b1, M2);

	
}
