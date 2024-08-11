const int VRx = A0;
const int VRy = A1;
const int SW = 6;

const int threshold = 200;

void setup() {
  Serial.begin(9600);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop() {
  int xValue = analogRead(VRx);
  int yValue = analogRead(VRy);
  int buttonState = digitalRead(SW);

  char direction = getDirection(xValue, yValue);

  Serial.println(direction);



  if (buttonState == HIGH) {
    Serial.println('1');
  }

  delay(100);
}

char getDirection(int x, int y) {
  int xCenter = 296;
  int yCenter = 313;
  
  if (x > xCenter + threshold) {
    return 'R';
  } else if (x < xCenter - threshold) {
    return 'L';
  } else if (y > yCenter + threshold) {
    return 'B';
  } else if (y < yCenter - threshold) {
    return 'F';
  } else {
    return 'C';
  }
}