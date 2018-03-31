const int PhotoTopRight = A1;
const int PhotoTopLeft = A0;
const int PhotoBottomRight = A3;
const int PhotoBottomLeft = A2;

const int WheelRightForward = 2;
const int WheelLeftForward = 4;
const int WheelRightBackward = 3;
const int WheelLeftBackward = 5;

const int HIGH_LIGHT = 800;
const int HIGH_LIGHT_THRESHOLD = 3;
 
void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
}

void loop() {

  int inputs[4];
  inputs[0] = analogRead(PhotoTopLeft);
  inputs[1] = analogRead(PhotoTopRight);
  inputs[2] = analogRead(PhotoBottomLeft);
  inputs[3] = analogRead(PhotoBottomRight);

  int bitIndex = 0;
  for(int i = 0; i < 4; i++)
  {
    if(HIGH_LIGHT < inputs[i])
    {
      bitIndex |= 1 << i;
    }
  }
  Serial.println("Found bitIndex: " + String(bitIndex));

  if(bitIndex == 0)
  {
    int maxLight = 0;
    for(int i = 1; i < 4; i++)
    {
      maxLight = max(inputs[i], inputs[i-1]);
    }

    maxLight -= HIGH_LIGHT_THRESHOLD;  
    for(int i = 0; i < 4; i++)
    {
      if(maxLight< inputs[i])
      {
        bitIndex |= 1 << i;
      }
    }
    Serial.println("New bit index: " + String(bitIndex));
  }
  
  switch(bitIndex){
    case 0: Move(0, 0); break;
    case 1: Move(0, 1); break; //Right Forward
    case 2: Move(1, 0); break; //Left Forward
    case 3: Move(1, 1); break; //Forward
    case 4: Move(0, -1); break;//Right Backward
    case 5: Move(-1, 1); break; //Right Forward & Left Backward
    case 6: Move(1, 0); break; // Diagonal WTF
    case 7: Move(0, -1); break;//Right Backward
    case 8: Move(-1, 0); break;//Left Backward
    case 9: Move(0, 1); break; //Right Forward
    case 10: Move(1, -1); break; //Left Forward & Right Backward
    case 11: Move(-1, 0); break; //Left backward
    case 12: Move(-1, -1); break;//Backward
    case 13: Move(0, 1); break; //Right forward
    case 14: Move(1, 0); break; //Left forward 
    case 15: Move(0, 0); break;
    default:
      Serial.println("What the fuck is that.");
      break;
  }

  delay(100);
}

void Move(int left, int right) {
  Serial.println("Move: " + String(left) + ", " + String(right));
  MoveWheel(WheelRightForward, WheelRightBackward, right);
  MoveWheel(WheelLeftForward, WheelLeftBackward, left);
}

void MoveWheel(int pinForward, int pinBackward, int value){
  if(value > 0)
  {
    digitalWrite(pinForward, HIGH);
    digitalWrite(pinBackward, LOW);
  }
  else if(value < 0)
  {
    digitalWrite(pinForward, LOW);
    digitalWrite(pinBackward, HIGH);
  }
  else
  {
    digitalWrite(pinForward, LOW);
    digitalWrite(pinBackward, LOW);
  }
}
