#include <SoftwareSerial.h>// import the serial library

long incomingByteBT = -1;   // for incoming serial data


long k_pub[16];

int indexInPlainText = 0;
int plaintext[16];

int size = 16;


SoftwareSerial serialVirtual(10, 11); // RX, TX

void setup() {
	indexInPlainText = 0;

	incomingByteBT = -1;

	Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
	serialVirtual.begin(9600);

	ClearPlainText();

	//GeneratePublicKey();

}

void loop() {
	// send data only when you receive data:
	while (serialVirtual.available()) {
		//Guardamos en la variable dato el valor leido por el modulo bluetooth
		incomingByteBT = serialVirtual.read();

		if (incomingByteBT == 13) {
			indexInPlainText = 0;

			PrintPlainText();

			ClearPlainText();
		}
		else {
			plaintext[indexInPlainText] = incomingByteBT;

			indexInPlainText++;
		}

	}
	
}


void ClearPlainText() {
	for (int i = 0; i < size; i++) {
		plaintext[i] = 0;
	}
}


void PrintPlainText() {
	Serial.println("Message (char): ");

	for (int i = 0; i < size; i++)
	{
		Serial.print(char(plaintext[i]));
		Serial.print(" ");
	}
	Serial.println("");

	Serial.println("Message (int): ");

	for (int i = 0; i < size; i++)
	{
		Serial.print(plaintext[i], DEC);
		Serial.print(" ");
	}
	Serial.println("");
}
