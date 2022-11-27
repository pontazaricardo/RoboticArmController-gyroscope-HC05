#include <SoftwareSerial.h>// import the serial library

int incomingByte = -1;   // for incoming serial data
long incomingByteBT = -1;   // for incoming serial data

int indexInKey = 0;
long k_pub[16];

int indexInPlainText = 0;
int plaintext[16];

int size = 16;



SoftwareSerial serialVirtual(10, 11); // RX, TX

void setup() {
  indexInPlainText = 0;
  indexInKey = 0;

  incomingByte = -1;
  incomingByteBT = -1;

  ClearPlainText();

  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  serialVirtual.begin(9600);
  //GeneratePublicKey();

}

void loop() {
  // send data only when you receive data:

  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    if (incomingByte == 13) {
      indexInPlainText = 0;

      PrintPlainText();

      Serial.println("Sending message!...");

      SendMessage();

      Serial.println("Message sent!");

      Serial.println(" ");
      
      ClearPlainText();
    }
    else {
      plaintext[indexInPlainText] = incomingByte;
      indexInPlainText++;
      // say what you got:
      //Serial.print("I received: ");
      //Serial.println(incomingByte, DEC);
    }
  }

  
}

void ClearPlainText() {
  for (int i = 0; i < size; i++) {
    plaintext[i] = 0;
  }
}


void SendMessage() {
  for (int i = 0; i < size; i++) {
    serialVirtual.write((int)plaintext[i]);
  }

  serialVirtual.write((int)13);
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
