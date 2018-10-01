void setup()
{
  pinMode(2,OUTPUT); pinMode(3,OUTPUT); pinMode(4,OUTPUT); pinMode(5,OUTPUT);pinMode(6,INPUT);pinMode(7,INPUT);
  pinMode(8,OUTPUT); pinMode(9,OUTPUT); pinMode(10,OUTPUT); pinMode(11,OUTPUT);pinMode(24,INPUT);pinMode(25,INPUT); 
  pinMode(22,OUTPUT);pinMode(23,OUTPUT); pinMode(26,OUTPUT); pinMode(27,OUTPUT); pinMode(28,OUTPUT); pinMode(29,OUTPUT);

   Serial.begin(9600);
}

void Drive(char dir)
{
  if (dir == 'F')
  {
    digitalWrite(28,0); digitalWrite(29,1);
    digitalWrite(26,0); digitalWrite(27,1);
  }
  else if (dir == 'B')
  {
    digitalWrite(28,1); digitalWrite(29,0);
    digitalWrite(26,1); digitalWrite(27,0);    
  }
  else if ( dir == 'S')
  {
    digitalWrite(28,0); digitalWrite(29,0);
    digitalWrite(26,0); digitalWrite(27,0);  
  }
 
}

void Lift(int Delay_ms,char dir)
{
  if(dir == 'U')
  {
     digitalWrite(22,1);
     digitalWrite(23,0);
     delay(Delay_ms);
  }
  else if(dir == 'L')
  {
     digitalWrite(22,0);
     digitalWrite(23,1);
     delay(Delay_ms);
  }
  else
  {
    digitalWrite(23,0);
    digitalWrite(22,0);    
  }
}
void Scan_Vertical()
{
  int count =0;
  while(digitalRead(25)==0)
  {
    count = count +Up(3,3);
  }
  Reset_VERTICAL();  
  Serial.println(count);  
}
void Scan_Horizontal()
{
  int t=0,count =0;
  while(t<2)
  {
    if(digitalRead(24)==0)
    {
      t++;
    }
    else
    {
      Left(3,2);
    }
   if (t==1)
   {
      while(digitalRead(25)==0)
       {
       count = count+Left(3,3);
       }
       t++;
       Reset_HORIZONTAL();  
       Serial.println(count);
   }
  }  
}

void Reset_VERTICAL()
{
  digitalWrite(2,0); digitalWrite(3,0); digitalWrite(4,0); digitalWrite(5,0);
}
 int Up(int Delay_ms,int Duration_ms)
{
  int count=0;
  unsigned long int t= millis();
  while(millis()-t <=Duration_ms)
  {
  digitalWrite(2,1);digitalWrite(3,1);delay(Delay_ms);
  digitalWrite(2,0);digitalWrite(4,1);delay(Delay_ms);
  digitalWrite(3,0);digitalWrite(5,1);delay(Delay_ms);
  digitalWrite(4,0);digitalWrite(2,1);delay(Delay_ms);
  digitalWrite(5,0);
  count++;
  }
  Reset_VERTICAL();
  return count;
}
int Down(int Delay_ms, int Duration_ms)
{
  int count=0;
  unsigned long int t= millis();
  while(millis()-t <= Duration_ms)
  {
  digitalWrite(5,1);digitalWrite(2,1);delay(Delay_ms);
 digitalWrite(2,0);digitalWrite(4,1);delay(Delay_ms);
 digitalWrite(5,0);digitalWrite(3,1);delay(Delay_ms);
 digitalWrite(4,0);digitalWrite(2,1);delay(Delay_ms);
 digitalWrite(3,0);
 count++;
  }
  Reset_VERTICAL();
  return count;
}

//Horizontal

void Reset_HORIZONTAL()
{
  digitalWrite(8,0); digitalWrite(9,0); digitalWrite(10,0); digitalWrite(11,0);
}

void Right(int Delay_ms,int Duration_ms)
{
  int count =0;
  unsigned long int t= millis();
  while(millis()-t <=Duration_ms)
  {
  digitalWrite(8,1);digitalWrite(9,1);delay(Delay_ms);
 digitalWrite(8,0);digitalWrite(10,1);delay(Delay_ms);
 digitalWrite(9,0);digitalWrite(11,1);delay(Delay_ms);
 digitalWrite(10,0);digitalWrite(8,1);delay(Delay_ms);
 digitalWrite(11,0);
 count++;
  }
  Reset_HORIZONTAL();
  return count;
}
int Left(int Delay_ms, int Duration_ms)
{
  int count =0;
  unsigned long int t= millis();
  while(millis()-t <= Duration_ms)
  {
  digitalWrite(11,1);digitalWrite(8,1);delay(Delay_ms);
 digitalWrite(8,0);digitalWrite(10,1);delay(Delay_ms);
 digitalWrite(11,0);digitalWrite(9,1);delay(Delay_ms);
 digitalWrite(10,0);digitalWrite(8,1);delay(Delay_ms);
 digitalWrite(9,0);
 count++;
  }
  Reset_HORIZONTAL();
  return count;
}

int val_6,val_7,val_24,val_25;
void loop()
{
  /*
  val_6 = digitalRead(6);  val_7 = digitalRead(7);
  val_24 = digitalRead(24);  val_25 = digitalRead(25);
  if(val_24 ==1 && val_25 ==0)
 {
  Left(3,5);
 }
 else if (val_25 ==1 && val_24 ==0)
 {
  Right(3,5);
 }
 else if (val_24==0 && val_25 ==0)
 {
  Reset_HORIZONTAL();
 }
  if(val_6 && !(val_7))
  {
    Up(3,5);
  }
 else if(val_7 && !(val_6))
 {
  Down(3,5);
 }
 else if (val_6==0 && val_7 ==0)
 {
  Reset_VERTICAL();
 }

*/
char cmd;
if (Serial.available())
{
  cmd = Serial.read();
  Lift(5000,cmd);
  Drive(cmd);
  if (cmd=='V')
  {
   Scan_Vertical(); 
  }
  else if(cmd =='D')
  {
    Down(3,2000);
  }
  else if(cmd=='S')
  {
    Reset_VERTICAL();
    Reset_HORIZONTAL();
    Lift(0,'R');
  }
  else if (cmd == 'H')
  {
    Scan_Horizontal(); 
  }
  else if (cmd == 'R')
  {
    Right(3,3000);
  } 
 
}

 
 
}

