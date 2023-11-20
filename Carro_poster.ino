#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
char estado = 'c';         // inicia detenido  

void setup() {
Serial.begin(9600);    // inicia el puerto serial para comunicacion con el Bluetooth
motor1.setSpeed(250);
motor2.setSpeed(250);                          

}

void loop() {
   while(Serial.available()){// lee el bluetooth y almacena en estado
   estado = Serial.read();
   Serial.println(estado);

  }
  if(estado=='c'){                                 // Boton Parar
 motor1.setSpeed(0);//izquierda
 motor2.setSpeed(0); //derecha
  }
 if(estado!='c'){         // Boton Parar
 motor1.setSpeed(150);//izquierda150
 motor2.setSpeed(150); //derecha130
 
     }
  if(estado=='a'){                                 // Boton desplazar al Frente
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
 
  
  }
  if(estado=='d'){                                  // Boton IZQ 
   motor1.run(FORWARD);//
   motor2.run(BACKWARD);  
   
   }

  if(estado=='b'){                                   // Boton DER
  motor1.run(BACKWARD);//
  motor2.run(FORWARD);

  } 

  if(estado=='e'){                                  // Boton Reversa
  motor1.run(FORWARD);//
  motor2.run(FORWARD);    
 
  }
 
 Serial.println(estado);
 }
