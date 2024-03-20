#include <SoftwareSerial.h> 
#include<Servo.h>
Servo frnt;
Servo bck;
Servo seed;
#define motor_left 8
#define motor_right 6
#define motor_right_dir 7
#define motor_left_dir 9
#define motor_front 2 
#define motor_front_dir 3
#define motor_back 4 
#define motor_back_dir 5
SoftwareSerial MyBlue(0, 1); // RX | TX 
char flag = 'f'; 
int pos=0;
void setup() 
{   
 frnt.attach(10);
 bck.attach(11);
 seed.attach(12);
 pinMode(9,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 Serial.begin(9600); 
 MyBlue.begin(9600); 
 Serial.println("Ready to connect\nDefualt password is 1234 or 000");
  frnt.write(60);
  bck.write(60); 
} 
void loop() 
{ 
 if (MyBlue.available()) 
   flag = MyBlue.read(); 
 if(flag =='F'){          // action to be performed if input is 'f'
       frnt.write(45);
       bck.write(45);
       digitalWrite(motor_front_dir,HIGH);
       digitalWrite(motor_front,LOW);
       digitalWrite(motor_left_dir,HIGH);
       digitalWrite(motor_right_dir,HIGH);
       digitalWrite(motor_left,LOW);
       digitalWrite(motor_right,LOW);
       digitalWrite(motor_back_dir,HIGH);
       digitalWrite(motor_back,LOW);
     }
     else if(flag == 'B'){ // action to be performed if input is 'b'
       frnt.write(45);
       bck.write(45);
       digitalWrite(motor_front_dir,LOW);
       digitalWrite(motor_front,HIGH);
       digitalWrite(motor_left_dir,LOW);
       digitalWrite(motor_right_dir,LOW);
       digitalWrite(motor_left,HIGH);
       digitalWrite(motor_right,HIGH);
       digitalWrite(motor_back_dir,LOW);
       digitalWrite(motor_back,HIGH);
     }
     else if(flag == 'L'){       // action to be performed if input is 'l'
       frnt.write(0);
       bck.write(0);
       digitalWrite(motor_front_dir,HIGH);
       digitalWrite(motor_front,LOW);
       digitalWrite(motor_left_dir,HIGH);
       digitalWrite(motor_right_dir,LOW);
       digitalWrite(motor_left,LOW);
       digitalWrite(motor_right,HIGH);
       digitalWrite(motor_back_dir,HIGH);
       digitalWrite(motor_back,LOW);
     }
     else if(flag == 'R'){     // action to be performed if input is 'r'
       frnt.write(90); 
       bck.write(90);
       digitalWrite(motor_front_dir,HIGH);
       digitalWrite(motor_front,LOW);
       digitalWrite(motor_left_dir,LOW);
       digitalWrite(motor_right_dir,HIGH);
       digitalWrite(motor_left,HIGH);
       digitalWrite(motor_right,LOW);
       digitalWrite(motor_back_dir,HIGH);
       digitalWrite(motor_back,LOW);
       }
     else if(flag =='S'){  // action to be performed if input is 's'
       digitalWrite(motor_front_dir,LOW);
       digitalWrite(motor_front,LOW);
       digitalWrite(motor_left_dir,LOW);
       digitalWrite(motor_right_dir,LOW);
       digitalWrite(motor_left,LOW);
       digitalWrite(motor_right,LOW);
       digitalWrite(motor_back_dir,LOW);
       digitalWrite(motor_back,LOW); 
       Serial.println("stop");
     }
     else if(flag=='V')
     {
        while(flag!='G')
        {
          frnt.write(45);
          bck.write(45);
       digitalWrite(motor_front_dir,HIGH);
       digitalWrite(motor_front,LOW);
       digitalWrite(motor_left_dir,HIGH);
       digitalWrite(motor_right_dir,HIGH);
       digitalWrite(motor_left,LOW);
       digitalWrite(motor_right,LOW);
       digitalWrite(motor_back_dir,HIGH);
       digitalWrite(motor_back,LOW);
       Serial.println("front");
       delay(1500);
       digitalWrite(motor_front_dir,LOW);
       digitalWrite(motor_front,LOW);
       digitalWrite(motor_left_dir,LOW);
       digitalWrite(motor_right_dir,LOW);
       digitalWrite(motor_left,LOW);
       digitalWrite(motor_right,LOW);
       digitalWrite(motor_back_dir,LOW);
       digitalWrite(motor_back,LOW); 
       Serial.println("stop");
       seed.write(60);
       delay(500); 
       seed.write(0); 
       delay(500); 
       if (MyBlue.available())
       { 
       flag = MyBlue.read(); 
       }
      }      
     }
    }