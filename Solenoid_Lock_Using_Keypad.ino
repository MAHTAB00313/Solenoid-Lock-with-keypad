/*
#include <Keypad.h>

char * password = "1010"; // To increase the passcode length change the numerical to the size after position

int position = 0; 

int buzzer = 4;
bool buzz = false;


const byte ROWS = 4; // 4 rows
const byte COLS = 4; // 4 columns 

// 
char keys[ROWS][COLS] =
{
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
}; //mapping of the keys done w.r.t to the grid keypad

byte rowPins[ROWS] = { 13, 12, 11, 10 }; //connection of rows pins to the arduino 
byte colPins[COLS] = { 9, 8, 7, 6 }; // connection of the columns pins to the arduino 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int Lock = 5; // Connecting the relay to the 5th pin

void setup()
{

pinMode(Lock, OUTPUT);
LockedPosition(true);
}

void loop()
{
char key = keypad.getKey();
if (key == '*' || key == '#' ) //OR operator used to lock the device back again 
{
position = 0;
LockedPosition(true);
}
if (key == password[position])
{
position ++;
}
if (position == 4) // change this if you want to increase the password length
{
LockedPosition(false);
}
delay(100);
}
void LockedPosition(int locked)
{
if (locked)
{
digitalWrite(Lock, LOW);
}
else
{
digitalWrite(Lock, HIGH);
}
}
*/


/*
  #include <Keypad.h>

char * password = "3690"; // To increase the passcode length, change the numerical to the size after position
int position = 0;

const byte ROWS = 4; // 4 rows
const byte COLS = 4; // 4 columns

char keys[ROWS][COLS] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
}; // Mapping of the keys done w.r.t to the grid keypad

byte rowPins[ROWS] = {13, 12, 11, 10}; // Connection of rows pins to the Arduino
byte colPins[COLS] = {9, 8, 7, 6};   // Connection of the columns pins to the Arduino

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int Lock = 5;     // Connecting the relay to the 5th pin
int Buzzer = 4;   // Connecting the buzzer to the 4th pin
bool buzzerSounded = false;

void setup()
{
  pinMode(Lock, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  LockedPosition(true);
}

void loop()
{
  char key = keypad.getKey();
  if (key == '*' || key == 'A') // OR operator used to lock the device back again
  {
    position = 0;
    LockedPosition(true);
  }
  if (key == password[position])
  {
    position++;
  }
  if (position == 4) // Change this if you want to increase the password length
  {
    LockedPosition(false);
  }

  // Check if the lock has just been unlocked
  if (digitalRead(Lock) == HIGH && !buzzerSounded)
  {
    // Sound the buzzer once
    digitalWrite(Buzzer, HIGH);
    delay(100);
    digitalWrite(Buzzer, LOW);
    buzzerSounded = true;
  }
  delay(100);
}

void LockedPosition(int locked)
{
  if (locked)
  {
    digitalWrite(Lock, LOW);
    buzzerSounded = false; // Reset the buzzer flag when locking
  }
  else
  {
    digitalWrite(Lock, HIGH);
    buzzerSounded = true;
  }
}
*/


#include <Keypad.h>

char * password = "3690"; // To increase the passcode length, change the numerical to the size after position
int position = 0;

const byte ROWS = 4; // 4 rows
const byte COLS = 4; // 4 columns

char keys[ROWS][COLS] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
}; // Mapping of the keys done w.r.t to the grid keypad

byte rowPins[ROWS] = {6, 7, 8, 9}; // Connection of rows pins to the Arduino
byte colPins[COLS] = {10, 11, 12, 13};   // Connection of the columns pins to the Arduino
// byte rowPins[ROWS] = {13, 12, 11, 10}; // Connection of rows pins to the Arduino
// byte colPins[COLS] = {9, 8, 7, 6};   // Connection of the columns pins to the Arduino

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int Lock = 5;     // Connecting the relay to the 5th pin
int Buzzer = 4;   // Connecting the buzzer to the 4th pin
bool buzzerSoundedOpen = false;
bool buzzerSoundedClose = false;

void setup()
{
  pinMode(Lock, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  LockedPosition(true);
}

void loop()
{
  char key = keypad.getKey();
  if (key == '*' || key == 'A') // OR operator used to lock the device back again
  {
    position = 0;
    LockedPosition(true);
  }
  if (key == password[position])
  {
    position++;
  }
  if (position == 4) // Change this if you want to increase the password length
  {
    LockedPosition(false);
  }

  // Check if the lock has just been unlocked
  if (digitalRead(Lock) == HIGH && !buzzerSoundedOpen)
  {
    // Sound the buzzer for opening once
    digitalWrite(Buzzer, HIGH);
    delay(100);
    digitalWrite(Buzzer, LOW);
    buzzerSoundedOpen = true;
  }
  
  // Check if the lock has just been locked
  if (digitalRead(Lock) == LOW && !buzzerSoundedClose)
  {
    // Sound the buzzer for closing once
    digitalWrite(Buzzer, HIGH);
    delay(100);
    digitalWrite(Buzzer, LOW);
    buzzerSoundedClose = true;
  }
  delay(100);
}

void LockedPosition(int locked)
{
  if (locked)
  {
    digitalWrite(Lock, LOW);
    buzzerSoundedOpen = false; // Reset the open buzzer flag when locking
  }
  else
  {
    digitalWrite(Lock, HIGH);
    buzzerSoundedClose = false; // Reset the close buzzer flag when unlocking
  }
}




