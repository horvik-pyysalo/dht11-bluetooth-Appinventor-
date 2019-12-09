
//partie Capteur 

#include <dht11.h>
#define DHT11PIN 9 // broche DATA -> broche 4
dht11 DHT11;

// partie bluetooth
int val;
int product ; 
 float f =0;
 float c =0;
 float h =0;
SoftwareSerial blueToothSerial(RxD,TxD);


void setup() {
  
  //general 
 Serial.begin(9600);
 Serial.print ( "DHT11 TEMPERATURE et HUMIDITY SENSOR");

// partie capteur 

 
}

void loop() {
 {
  //partie capteur 
  DHT11.read(DHT11PIN);
c= DHT11.temperature, 2;
f= product = (float)DHT11.temperature * 1.8 +32  , 2;
h= DHT11.humidity, 2 ;
  Serial.print("Humidity (%): ");
  Serial.print((float)h);
  Serial.print("\t");
  Serial.print("Temperature (°C): ");
  Serial.println(c);
  Serial.print("Temperature (°f): ");
  Serial.println( f  ); // f°


}
}
