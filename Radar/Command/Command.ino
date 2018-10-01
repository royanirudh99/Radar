void setup()
{
  Serial.begin(9600);pinMode(6,OUTPUT);pinMode(7,OUTPUT); pinMode(24,OUTPUT);pinMode(25,OUTPUT); 
}
char cmd;
void loop()
{
  if (Serial.available())
  {
    cmd = Serial.read();
    if(cmd=='V')
    {
      digitalWrite(6,0);  digitalWrite(7,0);      
    }
    else if(cmd == 'U')
    {
      digitalWrite(6,1);  digitalWrite(7,0);
    }
    else if (cmd== 'D')
    {
      digitalWrite(6,0);  digitalWrite(7,1);
    }

    else if( cmd=='H')
    {
     
      digitalWrite(24,0); digitalWrite(25,0);
    }

    else if(cmd == 'L')
    {
      
      digitalWrite(24,1); digitalWrite(25,0);
    }
    else if (cmd =='R')
    {
      
      digitalWrite(24,0); digitalWrite(25 ,1);
    }
  
      }
           
} 

