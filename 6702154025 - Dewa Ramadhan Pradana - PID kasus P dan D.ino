int sensor1=A5;
int sensor2=A4;
int sensor3=A3;
int sensor4=A2;
int sensor5=A1;
int sensor6=A0;
int buttonatas=13;
int buttonbawah=12;
int led1=6;
int led2=9;

int in1=10;
int in2=9;
int in3=6;
int in4=5;

int Kp = 2;
int Ki = 0;
int Kd = 32;
int rate = 0;
int moveControl = 0;
int kecepatanMotorKanan = 0;
int kecepatanMotorKiri = 0;
int kecepatanSetPoint = 150;


int tombol1 = 12;
int tombol2 = 13;

char buff[100];

String stringkondisi="000000";
String lastkondisi="000000";
int Error=0;

int sensor[8],x, sensorBit, t, a_size;
char sendat[8];

int tekan;

void setup(){
  pinMode(buttonatas, INPUT_PULLUP);
  pinMode(buttonbawah, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(sensor6, INPUT);
  
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);

  Serial.println("Tekan tombol 1 untuk kalibrasi");
  Serial.println("Tekan tombol 2 untuk deteksi error");
}

String convertKeString(char* a, int size){
  int i;
  String s = "";
  for (i=0;i<size;i++){
    s=s+a[i];
  }
  return s;
}

void loop() {
  sensor[0]=digitalRead(sensor1);
  sensor[1]=digitalRead(sensor2);
  sensor[2]=digitalRead(sensor3);
  sensor[3]=digitalRead(sensor4);
  sensor[4]=digitalRead(sensor5);
  sensor[5]=digitalRead(sensor6);

  delay(50);
  for (x=5;x>=0;x--){
    if(sensor[x] != 0 || sensor[x]== HIGH){
      sendat[x]='0';
    }
    else {
      sendat[x]='1';
    }
  }

  sensorBit=0;
  for (x=0;x<=5;x++){
    sensorBit += sendat[x] * (1 << x);
  }
  
  

  if (digitalRead(tombol1)==HIGH){
    tekan=1;
  }
  if(tekan==1){
    Serial.print("| Sensor 1 : ");
    Serial.println(analogRead(sensor1));
    Serial.print("| Sensor 2 : ");
    Serial.println(analogRead(sensor2));
    Serial.print("| Sensor 3 : ");
    Serial.println(analogRead(sensor3));
    Serial.print("| Sensor 4 : ");
    Serial.println(analogRead(sensor4));
    Serial.print("| Sensor 5 : ");
    Serial.println(analogRead(sensor5));
    Serial.print("| Sensor 6 : ");
    Serial.println(analogRead(sensor6));
    delay(500);
  }
//asasasas
  if (digitalRead(tombol2)==HIGH){
    Serial.println("----------------------------");
    Serial.println("Kalibrasi selesai\n");
    tekan=3;
 }
  if (tekan==3){
    int a_size = sizeof(sendat)/sizeof(char);
    String stringkondisi = convertKeString(sendat, a_size);
 
    digitalWrite(in1,HIGH);
    digitalWrite(in3,HIGH);
   
  if(stringkondisi=="100000"){
    moveControl = (Kp*Error)+(Kd*rate);
    kecepatanMotorKanan = kecepatanSetPoint - moveControl;
    kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
    analogWrite(in1,kecepatanMotorKanan);
    analogWrite(in3,kecepatanMotorKiri);
    Error = -4;
    lastkondisi=stringkondisi;
  }
  else if(stringkondisi=="110000"){
    moveControl = (Kp*Error)+(Kd*rate);
    kecepatanMotorKanan = kecepatanSetPoint - moveControl;
    kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
    analogWrite(in1,kecepatanMotorKanan);
    analogWrite(in3,kecepatanMotorKiri);
    Error = -3;
    lastkondisi=stringkondisi;
  }
  else if(stringkondisi=="010000"){
    moveControl = (Kp*Error)+(Kd*rate);
    kecepatanMotorKanan = kecepatanSetPoint - moveControl;
    kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
    analogWrite(in1,kecepatanMotorKanan);
    analogWrite(in3,kecepatanMotorKiri);
    Error = -2;
    lastkondisi=stringkondisi;
  }
  else if(stringkondisi=="011000"){
    moveControl = (Kp*Error)+(Kd*rate);
    kecepatanMotorKanan = kecepatanSetPoint - moveControl;
    kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
    analogWrite(in1,kecepatanMotorKanan);
    analogWrite(in3,kecepatanMotorKiri);
    Error = -1;
    lastkondisi=stringkondisi;
  }
  else if(stringkondisi=="001000"){
    moveControl = (Kp*Error)+(Kd*rate);
    kecepatanMotorKanan = kecepatanSetPoint - moveControl;
    kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
    analogWrite(in1,kecepatanMotorKanan);
    analogWrite(in3,kecepatanMotorKiri);
    Error = 0;
    lastkondisi=stringkondisi;
  }
  else if(stringkondisi=="001100"){
    moveControl = (Kp*Error)+(Kd*rate);
    kecepatanMotorKanan = kecepatanSetPoint - moveControl;
    kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
    analogWrite(in1,kecepatanMotorKanan);
    analogWrite(in3,kecepatanMotorKiri);
    Error = 0;
    lastkondisi=stringkondisi;
  }
  else if(stringkondisi=="000100"){
    moveControl = (Kp*Error)+(Kd*rate);
    kecepatanMotorKanan = kecepatanSetPoint - moveControl;
    kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
    analogWrite(in1,kecepatanMotorKanan);
    analogWrite(in3,kecepatanMotorKiri);
    Error = 0;
    lastkondisi=stringkondisi;
  }
  
  else if(stringkondisi=="000110"){
    moveControl = (Kp*Error)+(Kd*rate);
    kecepatanMotorKanan = kecepatanSetPoint - moveControl;
    kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
    analogWrite(in1,kecepatanMotorKanan);
    analogWrite(in3,kecepatanMotorKiri);
    Error = 1;
    lastkondisi=stringkondisi;
  }
  else if(stringkondisi=="000010"){
    moveControl = (Kp*Error)+(Kd*rate);
    kecepatanMotorKanan = kecepatanSetPoint - moveControl;
    kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
    analogWrite(in1,kecepatanMotorKanan);
    analogWrite(in3,kecepatanMotorKiri);
    Error = 2;
    lastkondisi=stringkondisi;
  }
  else if(stringkondisi=="000011"){
    moveControl = (Kp*Error)+(Kd*rate);
    kecepatanMotorKanan = kecepatanSetPoint - moveControl;
    kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
    analogWrite(in1,kecepatanMotorKanan);
    analogWrite(in3,kecepatanMotorKiri);
    Error = 3;
    lastkondisi=stringkondisi;
  }
  else if(stringkondisi=="000001"){
    moveControl = (Kp*Error)+(Kd*rate);
    kecepatanMotorKanan = kecepatanSetPoint - moveControl;
    kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
    analogWrite(in1,kecepatanMotorKanan);
    analogWrite(in3,kecepatanMotorKiri);
    Error = 4;
    lastkondisi=stringkondisi;
  } 
  else if(stringkondisi=="000000"){
   analogWrite(in1, 15);
   analogWrite(in3, 15);
   lastkondisi=stringkondisi;
   Serial.println("Robot keluar lintasan!");
   
   digitalWrite(led1,HIGH);
   digitalWrite(led2,HIGH);
   delay(1000);
   digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
   delay(1000);
  }
 
  Serial.print(" Error= ");
  Serial.println(Error);
  delay(500);
 }
}