int colorPin[4] [3] = {{13, 12, 11},
                      {10, 9, 8},
                      {7, 6, 5},
                      {4, 3, 2}};
int button1Pin = 22;
int button2Pin = 23;

int check = 0;
int mode1 = 0;
int mode2 = 0;
int red = 0;
int green = 0;
int blue = 0;
bool switch1 = false;
bool switch2 = true;

void setup()
{
 pinMode(button1Pin, INPUT);
 pinMode(button2Pin, INPUT);

 for(int i = 0; i < 4; i++)
  for(int j = 0; j < 3; j++)
    pinMode(colorPin[i][j], OUTPUT);  
}

void loop()
{
  int buttonInput1 = digitalRead(button1Pin);
  int buttonInput2 = digitalRead(button2Pin);
  if(buttonInput1 == LOW)
  {
    switch1 = true;
  }
  if(switch1 == true && digitalRead(button1Pin) == HIGH)
  {
    switch1 = false;
    if(mode1 > 5)
      mode1 = 0;
    setColor(mode1);
    mode1++;
  }
  
  if(buttonInput2 == LOW)
  {
    switch2 = true;
  }
  if(switch2 == true && digitalRead(button2Pin) == HIGH)
  {
    switch2 = false;
    check++;
     if(check == 2)
        check = 0;

  }
  if(check == 1)
  {
    if(mode2 > 7)
      mode2 = 0;
    setShape(mode2);
    delay(300);
    mode2++;
  }
}
void setLed(int n, int r, int g, int b)
{
  switch(n) 
  {
    case 1:
    digitalWrite(colorPin[0][0], r);
    digitalWrite(colorPin[0][1], g);
    digitalWrite(colorPin[0][2], b); 
    break;
    case 2:
    digitalWrite(colorPin[1][0], r);
    digitalWrite(colorPin[1][1], g);
    digitalWrite(colorPin[1][2], b); 
    break;
    case 3:
    digitalWrite(colorPin[2][0], r);
    digitalWrite(colorPin[2][1], g);
    digitalWrite(colorPin[2][2], b);
    break; 
    case 4:
    digitalWrite(colorPin[3][0], r);
    digitalWrite(colorPin[3][1], g);
    digitalWrite(colorPin[3][2], b);
    break; 
  }
}

void setShape(int shape)
{
  switch(shape)
  {
    case 0:
    setLed(1, red, green, blue);
    setLed(2, 0, 0, 0);
    setLed(3, 0, 0, 0);
    setLed(4, 0, 0, 0);
    break;
    case 1:
    setLed(1, red, green, blue);
    setLed(2, red, green, blue);
    setLed(3, 0, 0, 0);
    setLed(4, 0, 0, 0);
    break;
    case 2:
    setLed(1, red, green, blue);
    setLed(2, red, green, blue);
    setLed(3, red, green, blue);
    setLed(4, 0, 0, 0);
    break;
    case 3: 
    setLed(1, red, green, blue);
    setLed(2, red, green, blue);
    setLed(3, red, green, blue);
    setLed(4, red, green, blue);
    break;
    case 4:
    setLed(1, 0, 0, 0);
    setLed(2, red, green, blue);
    setLed(3, red, green, blue);
    setLed(4, red, green, blue);
    break;
    case 5:
    setLed(1, 0, 0, 0);
    setLed(2, 0, 0, 0);
    setLed(3, red, green, blue);
    setLed(4, red, green, blue);
    break;
    case 6:
    setLed(1, 0, 0, 0);
    setLed(2, 0, 0, 0);
    setLed(3, 0, 0, 0);
    setLed(4, red, green, blue);
    break;
    case 7:
    setLed(1, 0, 0, 0);
    setLed(2, 0, 0, 0);
    setLed(3, 0, 0, 0);
    setLed(4, 0, 0, 0);
    break;
  }
}

void setColor(int color)
{
  switch(color)
  {
    case 0:
    red = 255;
    green = 255;
    blue = 255;
    break;
    case 1:
    red = 200;
    green = 0;
    blue = 0;
    break;
    case 2:
    red = 0;
    green = 0;
    blue = 200;
    break;
    case 3:
    red = 255;
    green = 255;
    blue = 0;
    break;
    case 4:
    red = 20;
    green = 0;
    blue = 150;
    break;
    case 5:
    red = 0;
    green = 0;
    blue = 0;
    break;
  }
}
