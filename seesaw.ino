/*
  Writer : Ege Selcuk
  Conductor : A. Arif Balik
*/

#define PLAY(PIN,SPEED) analogWrite(PIN,SPEED);
#define STOP(PIN) analogWrite(PIN,0);

#define SHAKE 1
#define S_SLOW 80
#define SLOW 100
#define NORMAL 100
#define S_NORMAL 150
#define FAST 200
#define S_FAST 255

#define MOTOR1_PWM 3
#define MOTOR2_PWM 4
#define MOTOR3_PWM 5
#define MOTOR4_PWM 6
#define MOTOR5_PWM 7
#define MOTOR6_PWM 8
#define MOTOR7_PWM 9
#define MOTOR8_PWM 10

#define MOTOR1_INA 28
#define MOTOR2_INA 26
#define MOTOR3_INA 30
#define MOTOR4_INA 14
#define MOTOR5_INA 22
#define MOTOR6_INA 24
#define MOTOR7_INA 2
#define MOTOR8_INA 11

#define MOTOR1_INB 29
#define MOTOR2_INB 27
#define MOTOR3_INB 31
#define MOTOR4_INB 15
#define MOTOR5_INB 23
#define MOTOR6_INB 25
#define MOTOR7_INB 13
#define MOTOR8_INB 12

#define METERIAL_A MOTOR1_PWM
#define METERIAL_B MOTOR2_PWM
#define METERIAL_D MOTOR3_PWM
#define METERIAL_C MOTOR4_PWM
#define METERIAL_E MOTOR5_PWM
#define METERIAL_F MOTOR6_PWM
#define METERIAL_G MOTOR7_PWM
#define METERIAL_H MOTOR8_PWM


uint8_t PWM_PIN[8] = {MOTOR1_PWM,
                      MOTOR2_PWM,
                      MOTOR3_PWM,
                      MOTOR4_PWM,
                      MOTOR5_PWM,
                      MOTOR6_PWM,
                      MOTOR7_PWM,
                      MOTOR8_PWM};
                      
uint8_t INA_PIN[8] = {MOTOR1_INA,
                      MOTOR2_INA,
                      MOTOR3_INA,
                      MOTOR4_INA,
                      MOTOR5_INA,
                      MOTOR6_INA,
                      MOTOR7_INA,
                      MOTOR8_INA};
                      
uint8_t INB_PIN[8] = {MOTOR1_INB,
                      MOTOR2_INB,
                      MOTOR3_INB,
                      MOTOR4_INB,
                      MOTOR5_INB,
                      MOTOR6_INB,
                      MOTOR7_INB,
                      MOTOR8_INB};

int prev_time = 0;

int shake(int motorNo, int delay1, int delay2){
  analogWrite(PWM_PIN[motorNo],255);
  digitalWrite(INA_PIN[motorNo],HIGH);
  digitalWrite(INB_PIN[motorNo],LOW);
  delay(delay1);
  digitalWrite(INB_PIN[motorNo],HIGH);
  digitalWrite(INA_PIN[motorNo],LOW);
  delay(delay2);
  return 1;
}

int first_movement(){
    switch((millis() - prev_time)/1000){ // get elapsed time
    //This part is decide when to BEGIN playing
    case 5: //second
      PLAY(METERIAL_D, FAST);
    break;
    case 9:
      PLAY(METERIAL_A, FAST);
    break;
    case 13:
      PLAY(METERIAL_B, S_FAST);
    break;
    case 17:
      PLAY(METERIAL_C, NORMAL);
    break;
    case 21:
      PLAY(METERIAL_G, S_NORMAL);
    break;
    case 25:
      PLAY(METERIAL_F, S_SLOW);
    break;
    case 30:
      PLAY(METERIAL_H, SHAKE);
    break;
    default:
    break;
  }
  switch((millis() - prev_time)/1000){
    //This part is decide when to STOP playing
    case 6: //second
      STOP(METERIAL_E);
      break;
    case 10:
      STOP(METERIAL_D);
    break;
    case 14:
      STOP(METERIAL_A);
    break;
    case 18:
      STOP(METERIAL_B);
    break;
    case 22:
      STOP(METERIAL_C);
    break;
    case 26:
      STOP(METERIAL_G);
    break;
    case 30:
      STOP(METERIAL_F);
    break;
    case 36:
    // The movement is over.
      PLAY(METERIAL_H, SHAKE);
      return 1; //performance was good!!
    break;
    default:
    break;
    }
    shake(8/*motor no 8*/, 20, 250); // this is an update function, Since meterial_h need a shake we must call this function frequently with those parameters
    
    return 0; //performance was not good enough OR just not over yet
}

int second_movement(){
   switch((millis() - prev_time)/1000){ // get elapsed time
    //This part is decide when to BEGIN playing
    case 3: //second
      PLAY(METERIAL_F, S_SLOW);
    break;
    case 18:
    case 5:
      shake(METERIAL_H, 20, 250);
    break;
    case 11:
      PLAY(METERIAL_C, NORMAL);
    break;
    case 12:
      PLAY(METERIAL_G, S_NORMAL);
    break;
    case 14:
      PLAY(METERIAL_E, FAST);
    break;
    case 16:
      PLAY(METERIAL_B, S_FAST);
    break;
    case 30:
      PLAY(METERIAL_H, SHAKE);
    break;
    default:
    break;
  }
  switch((millis() - prev_time)/1000){
    //This part is decide when to STOP playing
    case 6: //second
      STOP(METERIAL_E);
      break;
    case 10:
      STOP(METERIAL_D);
    break;
    case 14:
      STOP(METERIAL_A);
    break;
    case 18:
      STOP(METERIAL_B);
    break;
    case 22:
      STOP(METERIAL_C);
    break;
    case 26:
      STOP(METERIAL_G);
    break;
    case 30:
      STOP(METERIAL_F);
    break;
    case 36:
    // The movement is over.
      PLAY(METERIAL_H, SHAKE);
      return 1; //performance was good!!
    break;
    default:
    break;
    }
    shake(8/*motor no 8*/, 20, 250); // this is an update function, Since meterial_h need a shake we must call this function frequently with those parameters
    
  return 0; //performance was not good enough OR just not over yet
}

int third_movement(){

  return 0; //performance was not good enough OR just not over yet
}

int fourth_movement(){

  return 0; //performance was not good enough OR just not over yet
}
  
void setup() {
  for(int i = 0; i < 7; i++){
    pinMode(INA_PIN[i], OUTPUT);
    pinMode(INB_PIN[i], OUTPUT);

    digitalWrite(INA_PIN[i],HIGH); // default this direction
  }
  PLAY(METERIAL_E, FAST); // this insrument start playing at 0th second
}

void loop() {

  // Now, we need to wait about 10 second as all conductors do. Show about the start take your seat!!
  delay(10000); // contemporary slience!!!!!
  
  prev_time = millis(); // reset timer

  // First movement : more like Allegro or something
  while(!first_movement()); // wait until movement is over
  
    prev_time = millis(); // reset timer for next movement
    
  PLAY(METERIAL_A, FAST); // this insrument start playing at 0th second
  PLAY(METERIAL_D, FAST); // this insrument start playing at 0th second
  while(!second_movement()); 

    prev_time = millis(); 
  
  while(!third_movement()); 

    prev_time = millis(); 
  
  while(!fourth_movement()); 

  // Piece is over!
}
