int LS=2;    // left sensor
int RS=3;    // right sensor

/*-------definning Outputs------*/
int LM1=6;    // left motor
int LM2=7;    // left motor
int RM1=4;    // right motor
int RM2=5;     // right motor
int LSvcc = 12;
int RSvcc = 13;
int EN1 =9;
int EN2 =10;
 
int LM_speed = 0;
int RM_speed = 0;


void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(LSvcc, OUTPUT);
  pinMode(RSvcc, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);    
}
void loop(){
  digitalWrite(LSvcc, HIGH);
  digitalWrite(RSvcc, HIGH);
  //digitalWrite(EN1, HIGH);
  //digitalWrite(EN2, HIGH);
  
  //test first
  /*
  LM_speed = 60;
  RM_speed = 60;
  MoveForward();
  //end of test
  */
  
  if((digitalRead(LS)==LOW) && (digitalRead(RS)==LOW)) {    
  	LM_speed = 100;
  	RM_speed = 100;
    MoveForward();
  }
  if((digitalRead(LS)==HIGH) && (digitalRead(RS)==HIGH)) {
      Stop();
  }
  if((digitalRead(LS)==LOW) && (digitalRead(RS)==HIGH)) {  //RIGHT TURN
    LM_speed = 100;
    RM_speed = 100;
     TurnRight();
  }
  if((digitalRead(LS)==HIGH) && (digitalRead(RS)==LOW)) { //LEFT TURN
    LM_speed = 100;
    RM_speed = 100;
    TurnLeft();
  }
}



void MoveForward(){
  	analogWrite(EN1, LM_speed);
  	analogWrite(EN2, RM_speed);
    digitalWrite(LM1, LOW);
  	digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
 //	delay(20);
}

void TurnRight(){
	analogWrite(EN1, LM_speed);
  	analogWrite(EN2, RM_speed);
    digitalWrite(LM1, LOW);
  	digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
//    delay(30); 
}

void TurnLeft(){
 	analogWrite(EN1, LM_speed);
  	analogWrite(EN2, RM_speed);
    digitalWrite(LM1, HIGH);
  	digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
//    delay(30);
}

void Stop(){
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
//    delay(20);
}
