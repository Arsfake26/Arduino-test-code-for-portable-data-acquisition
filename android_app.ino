void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
  randomSeed(analogRead(0));
  delay(4000);
}

int msgCounter = 1;
unsigned long previousMillis = 0;
const long interval = 1000;

void loop() {
  // Get the current time
  unsigned long x = millis();

  // Check if 3 seconds have passed
  if (x - previousMillis >= interval) {
    previousMillis = x; // Save the last time data was sent
    // Generate random data
    int data1 = 1000 + random(100);
    int data2 = 800 + random(150);
    int data3 = 1100 + random(100);
    int data4 = 900 + random(50);
    int data5 = 850 + random(20);
    int data6 = 750 + random(75);
    int data7 = 800 + random(30);
    int data8 = 500 + random(200);
    // Construct the message string
    String listen ="#" + String(msgCounter) + ";" + String(data1) + ";" + String(data2) + ";" + String(data3) + ";" + 
                    String(data4) + ";" + String(data5) + ";" + String(data6) + ";" + String(data7) + ";" + String(data8);
    //
    // Send the constructed message to the serial monitor
    Serial.println("{"+listen+"}");
    // Increment msgCounter and reset it if it reaches 13
    msgCounter++;
  }
}

//{#47;1034;880;1147;928;869;784;804;643} + shs8yen
