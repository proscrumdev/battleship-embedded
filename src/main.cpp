#ifndef UNIT_TEST
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <GameController.h>
#include <DisplayManager.h>
#include <string>
#include <sstream>
namespace std {
    template<typename T>
    std::string to_string(const T &n) {
        std::ostringstream s;
        s << n;
        return s.str();
    }
}

LiquidCrystal_I2C lcd(0x27,20,4);
GameController gc = GameController();
DisplayManager dm = DisplayManager();

int x=0;
const String emptyLCDLine = "                    ";

const byte ROWS = 4; //four rows
const byte COLS = 5; //five columns
//define the cymbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'A','B','C','D','-'},
  {'E','F','G','H','+'},
  {'1','2','3','4','*'},
  {'5','6','7','8','#'}
};
byte rowPins[ROWS] = {23, 19, 18, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {15, 2, 4, 16, 17}; //connect to the column pinouts of the keypad

<<<<<<< HEAD
//initialize the keypad
=======
//initialize class for KeyPad
>>>>>>> 2a9c8f25569451edd84339e2e95f8d2db82ef34a
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

list<Ship> myFleet;
list<Ship> enemyFleet;

void UpdateDisplay() {
  lcd.clear();
  lcd.home();
  Page page = dm.GetCurrentPage();
  lcd.print(page.Line1.c_str());
  lcd.setCursor(0,1);
  lcd.print(page.Line2.c_str());
  lcd.setCursor(0,2);
  lcd.print(page.Line3.c_str());
  lcd.setCursor(0,3);
  lcd.print(page.Line4.c_str());
}

Position enterPosition(int offset) {
    char customKey;
    Letters letter;
    int digit;
    customKey = customKeypad.getKey();
    int x=0;

    while (customKey != '#')
    {
      customKey = customKeypad.getKey();

      if(customKey){
        if (!dm.IsCurrentPageLastPage() && customKey != '+' && customKey != '*') {
          customKey = '.';
        }      

        Serial.println(customKey);
        switch (customKey)
        {
        case '-':
          x--;
          lcd.print(" ");
          lcd.setCursor(x+offset,3);
          break;
        
        case '.':
          break;

        case '#':
          break;

        case '+':
          dm.CurrentPage--;
          lcd.cursor_off();
          UpdateDisplay();
          break;

        case '*':
          dm.CurrentPage++;
          UpdateDisplay();
          if (dm.IsCurrentPageLastPage()) {
            x=0;
            lcd.cursor_on();
          }          
          break;

        default:
          lcd.print(customKey);
          if (x == 0)
          {
            letter = gc.CharToLetter(customKey);
          }
          if (x == 1)
          {
            digit = customKey - '0';
          }
          x++;
          break;
        }
      }
    }
    Position pos = Position(letter, digit);
    Serial.println(pos.toString().c_str());

    return pos;
}

void enterPositions(Ship& ship) {
  Serial.println(ship.Name.c_str());

  for (int i=1; i<= ship.Size; i++)
  {
    Page newPage;
    newPage.Line1 = "Please position";
    newPage.Line2 = "your fleet (A1-H8)";
    newPage.Line3 = ship.Name;
    newPage.Line4 = "Pos " + std::to_string(i) + " of " + std::to_string(ship.Size) + ": ";
    dm.AddPage(newPage);
    UpdateDisplay();
    lcd.cursor_on();

    auto pos = enterPosition(12);
    ship.Positions.insert(ship.Positions.end(), pos);  
    dm.GetLastPage().Line4 += pos.toString();  
  }
}

void fleetPlacement(list<Ship> &fleet) {
  fleet = gc.InitializeShips();
  
  for(Ship ship : fleet)
  {
    enterPositions(ship);
    Serial.println("Ship positions are:");
    for (Position pos : ship.Positions)
    {
      Serial.print(gc.LetterToChar(pos.Column));
      Serial.println(pos.Row);
    }
  }

  Page newPage;  
  newPage.Line1 = "Placement Done";
  newPage.Line2 = "Press a key";
  newPage.Line3 = "to start the game";
  dm.AddPage(newPage);
  UpdateDisplay();

  char customKey = customKeypad.getKey();
  while (!customKey) {
    customKey = customKeypad.getKey();
    if (customKey == '+')
    {
      dm.CurrentPage--;
      UpdateDisplay();
      customKey=NULL;
    }
    if (customKey == '*')
    {
      dm.CurrentPage++;
      UpdateDisplay();
      customKey=NULL;
    }
  }
}

void initializeEnemyFleet(list<Ship> &Fleet) {
    Fleet = GameController::InitializeShips();
    for_each(Fleet.begin(), Fleet.end(), [](Ship &ship) {
        if (ship.Name == "Aircraft Carrier") {
            ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 4));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 5));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 6));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 7));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 8));
        }
        if (ship.Name == "Battleship") {
            ship.Positions.insert(ship.Positions.end(), Position(Letters::E, 6));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::E, 7));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::E, 8));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::E, 9));
        }
        if (ship.Name == "Submarine") {
            ship.Positions.insert(ship.Positions.end(), Position(Letters::A, 3));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 3));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::C, 3));
        }
        if (ship.Name == "Destroyer") {
            ship.Positions.insert(ship.Positions.end(), Position(Letters::F, 8));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::G, 8));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::H, 8));
        }
        if (ship.Name == "Patrol Boat") {
            ship.Positions.insert(ship.Positions.end(), Position(Letters::C, 5));
            ship.Positions.insert(ship.Positions.end(), Position(Letters::C, 6));
        }
    });
}

Position GetRandomPosition() {
  const int size = 8;
  srand((unsigned int) time(NULL));
  Letters lColumn = (Letters)(rand() % size);
  int nRow = (rand() % size);

  Position position(lColumn, nRow);
  return position;
}

void playGame() {
    while(true){
      Page playerPage = Page();
      playerPage.Line1 = "Enter your position";
      dm.AddPage(playerPage);
      UpdateDisplay();
      lcd.setCursor(0,1);
      auto pos = enterPosition(0);
      dm.GetCurrentPage().Line2 = pos.toString();
      Serial.println(pos.toString().c_str());      
      if (GameController::CheckIsHit(enemyFleet, pos)) {
        dm.GetCurrentPage().Line4 = "Yeah, nice hit!";
      }
      else {
        dm.GetCurrentPage().Line4 = "Miss";
      }
      UpdateDisplay();
      delay(3000);

      Page computerPage = Page();
      auto computerpos = GetRandomPosition();
      computerPage.Line1 = "Computer shoot at " + computerpos.toString();
      if (GameController::CheckIsHit(myFleet, computerpos)) {
        computerPage.Line2 = "      and hit";
      }
      else {
        computerPage.Line2 = "     and missed";
      }
      dm.AddPage(computerPage);
      UpdateDisplay();
      delay(3000);
  }
}

void setup() {
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(33, OUTPUT);

  int LED1Value = 0;
  int LED2Value = 4;

  // initialize the serial port
  Serial.begin(115200);
  Serial.println("Starting...");
  lcd.init();
  lcd.backlight();

  Page newPage;
  newPage.Line1 = "  *** WELCOME ***   ";
  newPage.Line2 = "   to the amazing   ";
  newPage.Line3 = "B A T T L E S H I P ";
  newPage.Line4 = "      Game v1.0     ";
  dm.AddPage(newPage);
  UpdateDisplay();
 
  char customKey = customKeypad.getKey();
  while (!customKey)
  {
    customKey = customKeypad.getKey();
    
    digitalWrite(26, LOW);
    digitalWrite(25, LOW);
    digitalWrite(33, LOW);
    digitalWrite(12, LED1Value&1);
    digitalWrite(14, LED1Value&2);
    digitalWrite(27, LED1Value&4);
    LED1Value++;

    delay(150);

    digitalWrite(12, LOW);
    digitalWrite(14, LOW);
    digitalWrite(27, LOW);
    digitalWrite(26, LED2Value&1);
    digitalWrite(25, LED2Value&2);
    digitalWrite(33, LED2Value&4);
    LED2Value++;

    delay(150);
  }

  // Ensure both LEDs are off when leaving the welcome screen
  digitalWrite(26, LOW);
  digitalWrite(25, LOW);
  digitalWrite(33, LOW);
  
  fleetPlacement(myFleet);
  initializeEnemyFleet(enemyFleet);

  playGame();
}

void loop() {

}
#endif
