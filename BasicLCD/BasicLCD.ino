#include <avr/io.h>
#include <avr/interrupt.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>


LiquidCrystal_I2C  lcd(0x27,2,1,0,4,5,6,7); // 0x27 is the I2C bus address for an unmodified backpack


volatile bool RunTask_10ms = 0;

//**************************************
//  10 ms Task Rate
//  Creates a periodic Task 
//  Vector Address 15
//**************************************
ISR(TIMER0_COMPA_vect)
{
  //Check to see if the flag was not cleared, this will track 
  //overruns in the 10ms task
  if(RunTask_10ms)
  {
    //digitalWrite(LED_BUILTIN,1);
  }
  RunTask_10ms = 1;
}

//*********************************************
//  Configure Timer 0
//*********************************************
void SetupTimer0()
{
  TCCR0A = 0; // set entire TCCR0A register to 0
  TCCR0B = 0; // same for TCCR0B
  TCNT0  = 0; //initialize counter value to 0
  // set compare match register for 2khz increments
  OCR0A = 155;// = (16*10^6) / (100*1024) - 1 = 155(must be <256)
  // turn on CTC mode
  TCCR0A |= (1 << WGM01);
  // 1024 prescaler - page 142 of datasheet
  TCCR0B |= (1 << CS00); 
  TCCR0B |= (1 << CS02);  
  // enable timer compare interrupt
  TIMSK0 |= (1 << OCIE0A);
}

void setup() 
{
  // activate LCD module
  lcd.begin (16,2); // for 16 x 2 LCD module
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home (); // set cursor to 0,0
  lcd.print("X20 TRANSMISSION"); 
  lcd.setCursor (0,1);        // go to start of 2nd line
}

void loop() 
{
 
  if(RunTask_10ms)
  {
     //Read the encoder value
  }
}
