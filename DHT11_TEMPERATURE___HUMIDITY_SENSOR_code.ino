//partie bluethoot
#include <SoftwareSerial.h>
#define RxD         7
#define TxD        6
#define DEBUG_ENABLED  1

SoftwareSerial blueToothSerial(RxD,TxD);

//partie capteur
#include <dht11.h>
#define DHT11PIN 9 // broche DATA -> broche 4
dht11 DHT11;
int product ; 
 float f =0;
 float c =0;
 float h =0;
 
void setup() {
  
  //partie comunication 
   Serial.begin(9600);
   
  //partie capteur
  Serial.print ( "DHT11 TEMPERATURE et HUMIDITY SENSOR");
 
 //partie bluethoot
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  
 setupBlueToothConnection();
}

void loop() {

  //partie capteur 
c= DHT11.temperature, 2;
f= product = (float)DHT11.temperature * 1.8 +32  , 2;
h= DHT11.humidity, 2 ;
  DHT11.read(DHT11PIN);
  Serial.print("Humidity (%): ");
  Serial.print((float)h);
  Serial.print("\t");
  Serial.print("Temperature (°C): ");
  Serial.println(c);
  Serial.print("Temperature (°f): ");
  Serial.println( f  ); // f°
  
//partie bluethooth

blueToothSerial.print(c);
blueToothSerial.print(f);
blueToothSerial.print(h);

delay (1000); 
}

void setupBlueToothConnection()
  {
  
  blueToothSerial.begin(9600);  
  
  blueToothSerial.print("AT");
  delay(400); 

  blueToothSerial.print("AT+DEFAULT");             // Restore all setup value to factory setup
  delay(2000); 
  
  blueToothSerial.print("AT+yee");    // set the bluetooth name as "SeeedBTSlave" ,the length of bluetooth name must less than 12 characters.
  delay(400);
  
    blueToothSerial.print("AT+PIN0000");             // set the pair code to connect 
  delay(400);
  
  blueToothSerial.print("AT+AUTH1");             //
    delay(400);    

    blueToothSerial.flush();

} 
