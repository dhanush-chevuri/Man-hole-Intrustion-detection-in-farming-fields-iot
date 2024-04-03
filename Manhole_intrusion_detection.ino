/*#####PIR Motion Sensor GSM man Hole intrustion System - SMS Alert Arduino Project####
Connection:Buzzer        - Digital Pin 13
Motion Sensor - Digital Pin 02
GSM Modem RX  - Digital Pin 01(TX)
And Connect the supply to above module*/

int pin = 13; //Piezo Buzzer Connected
volatile int state = LOW;

void setup()
{
  pinMode(pin, OUTPUT);     // buzzer as output
  digitalWrite(pin, state); //make buzzer OFF
  //PIR Motion Sensor connected at digital pin 2 i.e. interrupt 0
  attachInterrupt(0, makeSMS_Alarm, RISING);
  Serial.begin(9600);  //set Baud Rate  
}

void loop()
{   

}

void makeSMS_Alarm()
{ 
  // Piezo Buzzer ON
  state = HIGH;
  digitalWrite(pin, state);
  
  //Send SMS
  Serial.print("AT+CMGF=1\r"); 
  //Phone number you want to send the sms
  Serial.print("AT+CMGS=+919121055818"); 
 
   //Text to send                             
  Serial.print("Manhole Alert - please be careful manhole infront of u");
  //sends ctrl+z, end of message    
  Serial.write(0x1A);                                                          
}
