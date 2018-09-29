void setup()
{
  pinMode(2,OUTPUT); 
  pinMode(3,OUTPUT); 
  pinMode(4,OUTPUT); 
  pinMode(5,OUTPUT);
  pinMode(8,OUTPUT); 
  pinMode(9,OUTPUT); 
  pinMode(10,OUTPUT); 
  pinMode(11,OUTPUT);
  pinMode(24,INPUT);
  pinMode(25,INPUT); 
  Serial.begin(9600);
}

// Scanning funtions

int Scan_Vertical()
{
  int count =0;
  while(digitalRead(25)==0)
  {
    count = count + Up(3,3);
  }
  Reset_VERTICAL(count);  
  Serial.println(count);  
  return count;
}


int Scan_Horizontal()
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
      Reset_HORIZONTAL(count);  
      Serial.println(count);
      return count;
    }
  }  
} 



//Reset Functions

void Reset_VERTICAL(int count)
{
  while(count)
  {
    count = count - Down(3,3);
  }
  digitalWrite(2,0); 
  digitalWrite(3,0); 
  digitalWrite(4,0); 
  digitalWrite(5,0);
}


void Reset_HORIZONTAL(int count)
{
  while(count)
  {
    count =count -Right(3,3);
  }

  digitalWrite(8,0); 
  digitalWrite(9,0); 
  digitalWrite(10,0); 
  digitalWrite(11,0);
}





// Basic Funtions Vertical

int Up(int Delay_ms,int Duration_ms)
{
  int count=0;
  unsigned long int t= millis();
  while(millis()-t <=Duration_ms)
  {
    digitalWrite(2,1);
    digitalWrite(3,1);
    delay(Delay_ms);
    digitalWrite(2,0);
    digitalWrite(4,1);
    delay(Delay_ms);
    digitalWrite(3,0);
    digitalWrite(5,1);
    delay(Delay_ms);
    digitalWrite(4,0);
    digitalWrite(2,1);
    delay(Delay_ms);
    digitalWrite(5,0);
    count++;
  }
  Reset_VERTICAL(0);
  return count;
}


int Down(int Delay_ms, int Duration_ms)
{
  int count=0;
  unsigned long int t= millis();
  while(millis()-t <= Duration_ms)
  {
    digitalWrite(5,1);
    digitalWrite(2,1);
    delay(Delay_ms);
    digitalWrite(2,0);
    digitalWrite(4,1);
    delay(Delay_ms);
    digitalWrite(5,0);
    digitalWrite(3,1);
    delay(Delay_ms);
    digitalWrite(4,0);
    digitalWrite(2,1);
    delay(Delay_ms);
    digitalWrite(3,0);
    count++;
  }
  Reset_VERTICAL(0);
  return count;
}


// Basic functions Horizontal

int Right(int Delay_ms,int Duration_ms)
{
  int count =0;
  unsigned long int t= millis();
  while(millis()-t <=Duration_ms)
  {
    digitalWrite(8,1);
    digitalWrite(9,1);
    delay(Delay_ms);
    digitalWrite(8,0);
    digitalWrite(10,1);
    delay(Delay_ms);
    digitalWrite(9,0);
    digitalWrite(11,1);
    delay(Delay_ms);
    digitalWrite(10,0);
    digitalWrite(8,1);
    delay(Delay_ms);
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
    digitalWrite(11,1);
    digitalWrite(8,1);
    delay(Delay_ms);
    digitalWrite(8,0);
    digitalWrite(10,1);
    delay(Delay_ms);
    digitalWrite(11,0);
    digitalWrite(9,1);
    delay(Delay_ms);
    digitalWrite(10,0);
    digitalWrite(8,1);
    delay(Delay_ms);
    digitalWrite(9,0);
    count++;
  }
  Reset_HORIZONTAL();
  return count;
}



