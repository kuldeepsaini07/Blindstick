#include <TinyGPS++.h>
#include <HardwareSerial.h>

// GPS Setup
TinyGPSPlus gps;
HardwareSerial gpsSerial(1);

// Pins
#define TRIG_FRONT 5
#define ECHO_FRONT 18

#define TRIG_DOWN 19
#define ECHO_DOWN 21

#define BUZZER 23

// Distance variables
long duration;
int distanceFront;
int distanceDown;

void setup() {
  Serial.begin(115200);

  // GPS Serial
  gpsSerial.begin(9600, SERIAL_8N1, 16, 17);

  // Ultrasonic Pins
  pinMode(TRIG_FRONT, OUTPUT);
  pinMode(ECHO_FRONT, INPUT);

  pinMode(TRIG_DOWN, OUTPUT);
  pinMode(ECHO_DOWN, INPUT);

  pinMode(BUZZER, OUTPUT);
}

// Function to measure distance
int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  return distance;
}

void loop() {

  // -------- FRONT SENSOR --------
  distanceFront = getDistance(TRIG_FRONT, ECHO_FRONT);

  if (distanceFront < 100 && distanceFront > 0) {
    // Obstacle detected
    digitalWrite(BUZZER, HIGH);
    delay(200);
    digitalWrite(BUZZER, LOW);
    delay(200);
  }

  // -------- DOWN SENSOR --------
  distanceDown = getDistance(TRIG_DOWN, ECHO_DOWN);

  if (distanceDown > 50) {
    // Pit / stairs detected
    digitalWrite(BUZZER, HIGH);
    delay(1000);  // long alert
    digitalWrite(BUZZER, LOW);
  }

  // -------- GPS --------
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  if (gps.location.isUpdated()) {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 6);

    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6);
  }

  delay(100);
}