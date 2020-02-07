
#define redled 5
#define greenled 6
#define blueled 7
#define ldr A0
float white[]={650,450,350};

float color[3];
float acolor[3];
void setup() {
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(blueled, OUTPUT);
  pinMode(ldr , INPUT);
  Serial.begin(9600);
  

}

void loop() {
  digitalWrite(redled, HIGH);
  delay(500);
  color[0] = analogRead(ldr);
  delay(500);
  digitalWrite(redled, LOW);


  digitalWrite(greenled, HIGH);
  delay(500);
  color[1] = analogRead(ldr);
  delay(500);
  digitalWrite(greenled, LOW);


  digitalWrite(blueled, HIGH);
  delay(500);
  color[2] = analogRead(ldr);
  delay(500);
  digitalWrite(blueled, LOW);

  Serial.print("R%=");
  Serial.println(acolor[0]);
  Serial.print("G%=");
  Serial.println(acolor[1]);
  Serial.print("B%=");
  Serial.println(acolor[2]);
  Serial.println("   ");

  acolor[0]=(color[0]/white[0])*100;
  acolor[1]=(color[1]/white[1])*100;
  acolor[2]=(color[2]/white[2])*100;


if(acolor[0]>50 && acolor[1]>50 && acolor[2]>50)
Serial.println("white");
else if(acolor[0]>50 && acolor[1]>50 && acolor[2]<50)
Serial.println("yellow");
else if(acolor[0]>50 && acolor[1]<50 && acolor[2]>50)
Serial.println("purple/pink");
else if(acolor[0]<50 && acolor[1]>50 && acolor[2]>50)
Serial.println("cyan");
else if(acolor[0]>50 && acolor[1]<50 && acolor[2]<50)
Serial.println("red");
else if(acolor[0]<50 && acolor[1]>50 && acolor[2]<50)
Serial.println("green");
else if(acolor[0]<50 && acolor[1]<50 && acolor[2]>50)
Serial.println("blue");
else if(acolor[0]<50 && acolor[1]<50 && acolor[2]<50)
Serial.println("black");





}
