
SoftwareSerial bluetooth(8, 9);
const int motorA1  = 6;    // Pin  5 of L293.
const int motorA2  = 7;    // Pin  6 of L293.
const int motorB1  = 5;   // Pin 10 of L293.
const int motorB2  = 4;   // Pin 9 of L293.

const int buzzer = 13 ;  

const int BTState = 2;    

int i = 0;
int p = 0;
int led = 2;
int j = 0;
int state_rec;
int vSpeed = 200;  
char state;

void setup() 
{
 
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(BTState, INPUT);

  Serial.begin(9600);
  
}

void loop() 
{
  // Para o carro quando a conexão com Bluetooth é perdida ou desconectada.
  if (digitalRead(BTState) == LOW) 
  {
    state_rec = 'S';
  }

  // Salva os valores da variável 'state'
  if (Serial.available() > 0) 
  {
    state_rec = Serial.read();
    state = state_rec;
    Serial.println(state);
    //   Serial.println(vSpeed);
  }

  // Altera a velocidade de acordo com valores especificados.
  if (state == '0') 
  {
    vSpeed = 0;
  }

  if (state == '4') 
    {
     vSpeed = 100;
    }
 
  if (state == '6') 
    {
     vSpeed = 155;
    }
  if (state == '7') 
    {
      vSpeed = 180;
    }

   if (state == '8') 
    {
      vSpeed = 200;
    }

   if (state == '9') 
    {
      vSpeed = 230;
    }
    
   if (state == 'q') 
    {
      vSpeed = 255;
    }

  if (state == 'F') {
    analogWrite(motorB1, vSpeed);
    analogWrite(motorA1, vSpeed);
    analogWrite(motorA2, 0);
    analogWrite(motorB2, 0);
  }

    else if (state == 'I') { 
    analogWrite(motorA1, vSpeed); 
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 100);    
    analogWrite(motorB2, 0);
  }

    else if (state == 'G') {   
    analogWrite(motorA1, 100); 
    analogWrite(motorA2, 0);
    analogWrite(motorB1, vSpeed);      
    analogWrite(motorB2, 0);
  }

  else if (state == 'B') { 
    analogWrite(motorA1, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, vSpeed);
    analogWrite(motorA2, vSpeed);
  }

   else if (state == 'H') { 
    analogWrite(motorA1, 0);   
    analogWrite(motorA2, vSpeed);
    analogWrite(motorB1, 0); 
    analogWrite(motorB2, 100);
  }
  
  else if (state == 'J') {  
    analogWrite(motorA1, 0);   
    analogWrite(motorA2, 100);
    analogWrite(motorB1, 0);   
    analogWrite(motorB2, vSpeed);
  }

  else if (state == 'L') {  
    analogWrite(motorA1, 0);
    analogWrite(motorA2, vSpeed);
    analogWrite(motorB1, vSpeed);
    analogWrite(motorB2, 0);
  }
  else if (state == 'R') {   
    analogWrite(motorA1, vSpeed);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, vSpeed);
  }
  else if (state == 'S') {   
    analogWrite(motorA1, 0);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, 0);
  }


   if (state == 'V' || state == 'v') 
  { 
    if (j == 0) 
      {
        digitalWrite(buzzer, 1);
        j = 1;
      }
     else 
      {
        digitalWrite (buzzer,0);
        j = 0;
      }
  }


   if (state == 'W' || state == 'w') 
  { 
    if (p == 0) 
      {
        digitalWrite(led, 1);
        j = 1;
      }
     else 
      {
        digitalWrite (led,0);
        j = 0;
      }
  }
}
   
