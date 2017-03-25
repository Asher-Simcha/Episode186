fint pin1 = 6;

int PWMinput1;
int Remapped1;

void setup()
{
  pinMode(pin1, INPUT);
  Serial.begin(9600);
}


void loop()
{  
  int PWMlow1 = 900;
  int PWMhigh1 = 2091;
  
  PWMinput1 = pulseIn(pin1, HIGH);
  Remapped1 = map(PWMinput1, PWMlow1, PWMhigh1, 0, 100);
  
  Serial.print(PWMinput1);
  Serial.print("\t");
  Serial.println(Remapped1);
  delay(200);
}


