/////// Definition of the 8 commands that we can receive from the the phone///////

#define GOAHEAD 0        //if we receive this commande the car will go ahead in a straight line
#define GOAHEAD_RIGHT 1  //if we receive this commande the car will go ahead but with a deviation to the right as the vehicle go ahead
#define GORIGHT 2        //if we receive this commande the car will turn around itself in a clockwise direction
#define GORIGHT_BACK 3   //if we receive this commande the car will go back but with a deviation to the right as the vehicle go back
#define GOBACK 4         //if we receive this commande the car will go back in a straight line
#define GOBACK_LEFT 5    //if we receive this commande the car will go back but with a deviation to the left as the vehicle go back
#define GOLEFT 6         //if we receive this commande the car will turn around itself in a counterclockwise direction
#define GOLEFT_AHEAD 7   //if we receive this commande the car will go ahead but with a deviation to the left as the vehicle go ahead

////// Definition of the motors constants////
/*
 * This constants depends on the cables connections between the motors and the arduino board
*/
#define MOTOR_RIGHT_FRONT_SPEED_PIN    5  //couleur verte 9
#define MOTOR_RIGHT_FRONT_GOAHEAD_PIN  9  //couleur jaune 5
#define MOTOR_RIGHT_FRONT_GOBACK_PIN   4  //couleur orange

#define MOTOR_LEFT_FRONT_SPEED_PIN    11  //couleur verte 11
#define MOTOR_LEFT_FRONT_GOAHEAD_PIN  A3  //couleur bleu
#define MOTOR_LEFT_FRONT_GOBACK_PIN   A2  //couleur verte

#define MOTOR_RIGHT_BACK_SPEED_PIN     6  //couleur verte
#define MOTOR_RIGHT_BACK_GOAHEAD_PIN   2  //couleur verte
#define MOTOR_RIGHT_BACK_GOBACK_PIN    10  //couleur jaune 3

#define MOTOR_LEFT_BACK_SPEED_PIN     3  //couleur jaune 10
#define MOTOR_LEFT_BACK_GOAHEAD_PIN   A4  //coul-ur verte
#define MOTOR_LEFT_BACK_GOBACK_PIN    A5  //couleur verte



///////////DEFINITION OF THE SPEED LEVEL WE CAN USE WITH THE CAR///////////////////
#define HIGH_SPEED_LEVEL 200
#define LOW_SPEED_LEVEL 100
#define STOP_SPEED_LEVEL 0

/*
 * This short variable allow us to know what command has been given (from the phone though the bluetooth shield)
 * defult is -1 i.e. no commande has been given
*/
short commande = -1;

//The setup function
void setup() {

  //We define all the motor's pin in output mode
  pinMode(MOTOR_RIGHT_FRONT_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_RIGHT_FRONT_GOAHEAD_PIN, OUTPUT);
  pinMode(MOTOR_RIGHT_FRONT_GOBACK_PIN, OUTPUT);

  pinMode(MOTOR_LEFT_FRONT_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_LEFT_FRONT_GOAHEAD_PIN, OUTPUT);
  pinMode(MOTOR_LEFT_FRONT_GOBACK_PIN, OUTPUT);

  pinMode(MOTOR_RIGHT_BACK_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_RIGHT_BACK_GOAHEAD_PIN, OUTPUT);
  pinMode(MOTOR_RIGHT_BACK_GOBACK_PIN, OUTPUT);

  pinMode(MOTOR_LEFT_BACK_SPEED_PIN, OUTPUT);
  pinMode(MOTOR_LEFT_BACK_GOAHEAD_PIN, OUTPUT);
  pinMode(MOTOR_LEFT_BACK_GOBACK_PIN, OUTPUT);

  //////////////////////////////////////////////
  Serial.begin(9600);
}
/////////END SETUP//////////////////


//Loop function
void loop(){
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
      commande = Serial.read(); // Reads the data from the serial port
      //Serial.println(commande); // Debugging only
      if (commande == GOAHEAD) { //if we receive the GOAHEAD commande
        
        //We configure the rotation sense of each motor 
        digitalWrite(MOTOR_LEFT_FRONT_GOAHEAD_PIN, HIGH);
        digitalWrite(MOTOR_LEFT_FRONT_GOBACK_PIN, LOW);
  
        digitalWrite(MOTOR_LEFT_BACK_GOAHEAD_PIN, HIGH);
        digitalWrite(MOTOR_LEFT_BACK_GOBACK_PIN, LOW);
        
        digitalWrite(MOTOR_RIGHT_FRONT_GOAHEAD_PIN, HIGH);
        digitalWrite(MOTOR_RIGHT_FRONT_GOBACK_PIN, LOW);
       
        digitalWrite(MOTOR_RIGHT_BACK_GOAHEAD_PIN, HIGH);
        digitalWrite(MOTOR_RIGHT_BACK_GOBACK_PIN, LOW);

        //We give eache motor the necessary speed in order to drive the car forward
        analogWrite(MOTOR_LEFT_FRONT_SPEED_PIN, HIGH_SPEED_LEVEL); 
        analogWrite(MOTOR_LEFT_BACK_SPEED_PIN, HIGH_SPEED_LEVEL); 
        analogWrite(MOTOR_RIGHT_FRONT_SPEED_PIN, HIGH_SPEED_LEVEL); 
        analogWrite(MOTOR_RIGHT_BACK_SPEED_PIN, HIGH_SPEED_LEVEL);
     }
     else if (commande == GOAHEAD_RIGHT) { //if we receive the GOAHEAD_RIGHT commande
      
      //We configure the rotation sense each motor
        digitalWrite(MOTOR_LEFT_FRONT_GOAHEAD_PIN, HIGH);
        digitalWrite(MOTOR_LEFT_FRONT_GOBACK_PIN, LOW);
  
        digitalWrite(MOTOR_LEFT_BACK_GOAHEAD_PIN, HIGH);
        digitalWrite(MOTOR_LEFT_BACK_GOBACK_PIN, LOW);
        
        digitalWrite(MOTOR_RIGHT_FRONT_GOAHEAD_PIN, HIGH);
        digitalWrite(MOTOR_RIGHT_FRONT_GOBACK_PIN, LOW);
       
        digitalWrite(MOTOR_RIGHT_BACK_GOAHEAD_PIN, HIGH);
        digitalWrite(MOTOR_RIGHT_BACK_GOBACK_PIN, LOW);

        //We give eache motor the necessary speed in order to drive the car forward right
        analogWrite(MOTOR_LEFT_FRONT_SPEED_PIN, HIGH_SPEED_LEVEL); 
        analogWrite(MOTOR_LEFT_BACK_SPEED_PIN, HIGH_SPEED_LEVEL); 
        analogWrite(MOTOR_RIGHT_FRONT_SPEED_PIN, LOW_SPEED_LEVEL); 
        analogWrite(MOTOR_RIGHT_BACK_SPEED_PIN, LOW_SPEED_LEVEL);
     }
     else if (commande == GORIGHT) { //if we receive the GORIGHT commande

      //We configure the rotation sense of the eache motor
        digitalWrite(MOTOR_LEFT_FRONT_GOAHEAD_PIN, HIGH);
        digitalWrite(MOTOR_LEFT_FRONT_GOBACK_PIN, LOW);
  
        digitalWrite(MOTOR_LEFT_BACK_GOAHEAD_PIN, HIGH);
        digitalWrite(MOTOR_LEFT_BACK_GOBACK_PIN, LOW);
        
        digitalWrite(MOTOR_RIGHT_FRONT_GOAHEAD_PIN, LOW);
        digitalWrite(MOTOR_RIGHT_FRONT_GOBACK_PIN, HIGH);
       
        digitalWrite(MOTOR_RIGHT_BACK_GOAHEAD_PIN, LOW);
        digitalWrite(MOTOR_RIGHT_BACK_GOBACK_PIN, HIGH);

        //We give eache motor the necessary speed in order to drive the car around itself in a clockwise direction
        analogWrite(MOTOR_LEFT_FRONT_SPEED_PIN, LOW_SPEED_LEVEL); 
        analogWrite(MOTOR_LEFT_BACK_SPEED_PIN, LOW_SPEED_LEVEL); 
        analogWrite(MOTOR_RIGHT_FRONT_SPEED_PIN, LOW_SPEED_LEVEL); 
        analogWrite(MOTOR_RIGHT_BACK_SPEED_PIN, LOW_SPEED_LEVEL);
     }
     else if (commande == GORIGHT_BACK) { //if we receive the GORIGHT_BACK commande

      //We configure the rotation sense of the eache motor
        digitalWrite(MOTOR_LEFT_FRONT_GOAHEAD_PIN, LOW);
        digitalWrite(MOTOR_LEFT_FRONT_GOBACK_PIN, HIGH);
  
        digitalWrite(MOTOR_LEFT_BACK_GOAHEAD_PIN, LOW);
        digitalWrite(MOTOR_LEFT_BACK_GOBACK_PIN, HIGH);
        
        digitalWrite(MOTOR_RIGHT_FRONT_GOAHEAD_PIN, LOW);
        digitalWrite(MOTOR_RIGHT_FRONT_GOBACK_PIN, HIGH);
       
        digitalWrite(MOTOR_RIGHT_BACK_GOAHEAD_PIN, LOW);
        digitalWrite(MOTOR_RIGHT_BACK_GOBACK_PIN, HIGH);

        //We give eache motor the necessary speed in order to drive the car back right
        analogWrite(MOTOR_LEFT_FRONT_SPEED_PIN, HIGH_SPEED_LEVEL); 
        analogWrite(MOTOR_LEFT_BACK_SPEED_PIN, HIGH_SPEED_LEVEL); 
        analogWrite(MOTOR_RIGHT_FRONT_SPEED_PIN, LOW_SPEED_LEVEL); 
        analogWrite(MOTOR_RIGHT_BACK_SPEED_PIN, LOW_SPEED_LEVEL);
     }
     else if (commande == GOBACK) { //if we receive the GOBACK commande

      //We configure the rotation sense of the eache motor
        digitalWrite(MOTOR_LEFT_FRONT_GOAHEAD_PIN, LOW);
        digitalWrite(MOTOR_LEFT_FRONT_GOBACK_PIN, HIGH);
  
        digitalWrite(MOTOR_LEFT_BACK_GOAHEAD_PIN, LOW);
        digitalWrite(MOTOR_LEFT_BACK_GOBACK_PIN, HIGH);
        
        digitalWrite(MOTOR_RIGHT_FRONT_GOAHEAD_PIN, LOW);
        digitalWrite(MOTOR_RIGHT_FRONT_GOBACK_PIN, HIGH);
       
        digitalWrite(MOTOR_RIGHT_BACK_GOAHEAD_PIN, LOW);
        digitalWrite(MOTOR_RIGHT_BACK_GOBACK_PIN, HIGH);

        //We give eache motor the necessary speed in order to drive the car back
        analogWrite(MOTOR_LEFT_FRONT_SPEED_PIN, HIGH_SPEED_LEVEL); 
        analogWrite(MOTOR_LEFT_BACK_SPEED_PIN, HIGH_SPEED_LEVEL); 
        analogWrite(MOTOR_RIGHT_FRONT_SPEED_PIN, HIGH_SPEED_LEVEL); 
        analogWrite(MOTOR_RIGHT_BACK_SPEED_PIN, HIGH_SPEED_LEVEL);
     }
     else if (commande == GOBACK_LEFT) { //if we receive the GOBACK_LEFT commande

      //We configure the rotation sense of the eache motor
        digitalWrite(MOTOR_LEFT_FRONT_GOAHEAD_PIN, LOW);
        digitalWrite(MOTOR_LEFT_FRONT_GOBACK_PIN, HIGH);
  
        digitalWrite(MOTOR_LEFT_BACK_GOAHEAD_PIN, LOW);
        digitalWrite(MOTOR_LEFT_BACK_GOBACK_PIN, HIGH);
        
        digitalWrite(MOTOR_RIGHT_FRONT_GOAHEAD_PIN, LOW);
        digitalWrite(MOTOR_RIGHT_FRONT_GOBACK_PIN, HIGH);
       
        digitalWrite(MOTOR_RIGHT_BACK_GOAHEAD_PIN, LOW);
        digitalWrite(MOTOR_RIGHT_BACK_GOBACK_PIN, HIGH);

        //We give eache motor the necessary speed in order to drive the car back left
        analogWrite(MOTOR_LEFT_FRONT_SPEED_PIN, LOW_SPEED_LEVEL); 
        analogWrite(MOTOR_LEFT_BACK_SPEED_PIN, LOW_SPEED_LEVEL); 
        analogWrite(MOTOR_RIGHT_FRONT_SPEED_PIN, HIGH_SPEED_LEVEL); 
        analogWrite(MOTOR_RIGHT_BACK_SPEED_PIN, HIGH_SPEED_LEVEL);
     }
     else if (commande == GOLEFT) { //if we receive the GOLEFT commande

      //We configure the rotation sense of the eache motor
        digitalWrite(MOTOR_LEFT_FRONT_GOAHEAD_PIN, LOW);
        digitalWrite(MOTOR_LEFT_FRONT_GOBACK_PIN, HIGH);
  
        digitalWrite(MOTOR_LEFT_BACK_GOAHEAD_PIN, LOW);
        digitalWrite(MOTOR_LEFT_BACK_GOBACK_PIN, HIGH);
        
        digitalWrite(MOTOR_RIGHT_FRONT_GOAHEAD_PIN, HIGH);
        digitalWrite(MOTOR_RIGHT_FRONT_GOBACK_PIN, LOW);
       
        digitalWrite(MOTOR_RIGHT_BACK_GOAHEAD_PIN, HIGH);
        digitalWrite(MOTOR_RIGHT_BACK_GOBACK_PIN, LOW);

        //We give eache motor the necessary speed in order to drive the car around itself in a counterclockwise direction
        analogWrite(MOTOR_LEFT_FRONT_SPEED_PIN, LOW_SPEED_LEVEL); 
        analogWrite(MOTOR_LEFT_BACK_SPEED_PIN, LOW_SPEED_LEVEL); 
        analogWrite(MOTOR_RIGHT_FRONT_SPEED_PIN, LOW_SPEED_LEVEL); 
        analogWrite(MOTOR_RIGHT_BACK_SPEED_PIN, LOW_SPEED_LEVEL);
     }
     else if (commande == GOLEFT_AHEAD) { //if we receive the GOLEFT_AHEAD commande

      //We configure the rotation sense of the eache motor
        digitalWrite(MOTOR_LEFT_FRONT_GOAHEAD_PIN, HIGH);
        digitalWrite(MOTOR_LEFT_FRONT_GOBACK_PIN, LOW);
  
        digitalWrite(MOTOR_LEFT_BACK_GOAHEAD_PIN, HIGH);
        digitalWrite(MOTOR_LEFT_BACK_GOBACK_PIN, LOW);
        
        digitalWrite(MOTOR_RIGHT_FRONT_GOAHEAD_PIN, HIGH);
        digitalWrite(MOTOR_RIGHT_FRONT_GOBACK_PIN, LOW);
       
        digitalWrite(MOTOR_RIGHT_BACK_GOAHEAD_PIN, HIGH);
        digitalWrite(MOTOR_RIGHT_BACK_GOBACK_PIN, LOW);

        //We give eache motor the necessary speed in order to drive the car forward left
        analogWrite(MOTOR_LEFT_FRONT_SPEED_PIN, LOW_SPEED_LEVEL); 
        analogWrite(MOTOR_LEFT_BACK_SPEED_PIN, LOW_SPEED_LEVEL); 
        analogWrite(MOTOR_RIGHT_FRONT_SPEED_PIN, HIGH_SPEED_LEVEL); 
        analogWrite(MOTOR_RIGHT_BACK_SPEED_PIN, HIGH_SPEED_LEVEL);
     }
     commande = -1; //we reset the commande value to the default commande
    delay(300); //we delay 300ms before the next iteration
  }else{ //If no command has been given we set all the motor's speed to 0 in order to stop the car
    analogWrite(MOTOR_LEFT_FRONT_SPEED_PIN, STOP_SPEED_LEVEL); 
    analogWrite(MOTOR_LEFT_BACK_SPEED_PIN, STOP_SPEED_LEVEL); 
    analogWrite(MOTOR_RIGHT_FRONT_SPEED_PIN, STOP_SPEED_LEVEL); 
    analogWrite(MOTOR_RIGHT_BACK_SPEED_PIN, STOP_SPEED_LEVEL);  
  }
}

////////////END LOOP////////////////////
