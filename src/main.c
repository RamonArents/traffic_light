/**
 * Author: Ramon Arents
 * Date:2-3-2021
 * Application: A stopping light that goes on green when it senses a vehicle. After that it goes back to red.
 * */
//use this code with Platform.io

// import the required libraries
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
//include ultrasone sensor library (trig_pin: 6 (PD6), echo_pin: 8(PB0))
#include <HCSR04.h>
//constants (LEDS) 
#define LED1 0b00000010 // pin 9 (PB1)
#define LED2 0b00000100 //pin 10 (PB2)
#define LED3 0b00001000 // pin 11 (PB3)
//distance for ultrasone sensor
uint32_t distance;

int main(void){ 
  //setup
  DDRB = 0b00001110; //setup LED ports as input
  HCSR04_Init();//setup ultrasone sensor
  //loop
  while(1){
    //OPTIONAL TODO: Make the program so that it starts at the red light
    distance = getDistance(); //get distance from ultrasone sensor
    //check if car is before the sensor and update LEDS
    if(distance <= 5){
      updateLeds();//update the LEDS
    }else{
      PORTB = LED1; //set LED back to red
    }
   
  }
  return 0;
}
/**
 * Update LEDS
 * @return void
 **/
void updateLeds(){
   //set light on orange
  PORTB = LED2;
  _delay_ms(1000); // wait one second
  //set light on green
  PORTB = LED3;
  _delay_ms(5000); // wait five seconds
  //turn on orange again
  PORTB = LED2;
  _delay_ms(3000); // wait three seconds
}

