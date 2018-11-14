from gpiozero import Button, PWMLED, LED
from time import sleep

pled = PWMLED(4)
led = LED(3)
button = Button(2)
litt = True
pled.value = 1
led.off

while True:
	if button.is_pressed and litt:
		fadetoL()
		blickOnce()
	elif not litt and not button.is_pressed:
		fadetoH()



def fadetoL(curVal = 1):
	for i in range(75):
		curVal-=0.01
		pled.value = curVal
		time.sleep(0.01)
	litt = False

def fadetoH(curVal = 0.25):
	for i in range(75):
		curVal+=0.01
		pled.value = curVal
		time.sleep(0.01)
	litt = True

def blickOnce():
	led.on()
	sleep(0.3)
	led.off()