////EECE_DEMO

const int led = 6; /// declaring led at digital pmw6 
const int temp = A0; ///declaring the temp sensor pin at A0 to access signal
 
/*
setting up a threshold temp which less than melting point for demo
*/
float threshold = 60.0;

void setup(){

  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.print("Done by:B220620\n");
}

void loop(){

  int data = analogRead(temp); ///Reading temp from sensor 
  /*
  Convertion raw data into temperature 
  */
  float voltage = data * (5.0 / 1023.0);
  float readtemp = (voltage - 0.5) * 100.0;
  
  /*
  comapring the temp with threshold temp to make circuit break
   */

  if(threshold < readtemp){ 
  
    digitalWrite(led, LOW);
    Serial.println("Temperature is high");
    
  }
  else{
  
    digitalWrite(led, HIGH);
    Serial.println("Optimal Temperature:");
    Serial.print(readtemp);
    
  }
}
