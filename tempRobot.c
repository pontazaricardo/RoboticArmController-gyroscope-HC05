//CODIGO SLAVE
#include <SoftwareSerial.h>// import the serial library
#include <AFMotor.h>

AF_DCMotor motor1(1);  // shoulder
AF_DCMotor motor2(2);// finger
AF_DCMotor motor3(3);// arm
AF_DCMotor motor4(4);//Rotation

int claw = 0;
int resetNumber = 0;

SoftwareSerial serialVirtual(50,51); // RX, TX
void setup() {
	serialVirtual.begin(9600);
	Serial.begin(9600);
}

void loop() {
	//Mientras el puerto serie del modulo bluetooth esta disponible
	while (serialVirtual.available()) {
		//Guardamos en la variable dato el valor leido por el modulo bluetooth
		int leido = serialVirtual.read();

		if(leido != 13)
		{
			Serial.println((char)leido);
			moverMotor((char)leido);
                
		}

		delay(50);
		
	}
}

void moverMotor(char n) {
	if (n == 'a') {
		Serial.println("Stoping");
		motor1.setSpeed(0);
		motor2.setSpeed(0);
		motor3.setSpeed(0);
		motor4.setSpeed(0);
	}
	if ((n == 'b') || (n == 'c')) {
		Serial.println("Moving shoulder");
		motor1.setSpeed(90);
		motor2.setSpeed(0);
		motor3.setSpeed(0);
		motor4.setSpeed(0);
		if (n == 'b') {
			motor1.run(FORWARD);
		} else {
			motor1.run(BACKWARD);
		}
		delay(10);
	}
	if ((n == 'd') || (n == 'e')) {
		Serial.println("Moving arm");
		motor1.setSpeed(0);
		motor2.setSpeed(0);
		motor3.setSpeed(90);
		motor4.setSpeed(0);
		if (n == 'd') {
			motor3.run(FORWARD);
		} else {
			motor3.run(BACKWARD);
		}
		delay(10);
	}
	if ((n == 'f') || (n == 'g')) {
		Serial.println("Rotating");
		motor1.setSpeed(0);
		motor2.setSpeed(0);
		motor3.setSpeed(0);
		motor4.setSpeed(90);
		if (n == 'f') {
			motor4.run(FORWARD);
		} else {
			motor4.run(BACKWARD);
		}
		delay(10);
	}/*
	if (n == 'j') {
		Serial.println("Finger");
		if (resetNumber == 0) {

			resetNumber = 1;
			motor1.setSpeed(0);
			motor2.setSpeed(90);
			motor3.setSpeed(0);
			motor4.setSpeed(0);
			if (claw == 0) {
				motor2.run(FORWARD);
				claw = 1;
			} else {
				motor2.run(BACKWARD);
				claw = 0;
			}
			delay(300);
		}
	} else {
		resetNumber = 0;
	}*/
      if ((n == 'h') || (n == 'i')) {
		Serial.println("Rotating");
		motor1.setSpeed(0);
		motor2.setSpeed(90);
		motor3.setSpeed(0);
		motor4.setSpeed(0);
		if (n == 'h') {
			motor2.run(FORWARD);
		} else {
			motor2.run(BACKWARD);
		}
		delay(10);
	}

}