#include <msp430.h> 
#include "ADC10.h"
#include "Movement.h"

//#define TURN_90 450000

/*
 * main.c
 */
void main(void) {
//	unsigned short sampleLeft;
//	unsigned short sampleRight;
//	unsigned short sampleFront;

    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    IFG1 = 0;					// clear interrupt flag1

    // configure LEDs as outputto see the lights with the movement
//    P1DIR = BIT0 | BIT6;

    // configure pins for use with motor
    P2DIR |= BIT0;
    P2DIR |= BIT1;
    P2DIR |= BIT3;
    P2DIR |= BIT5;

    // configure the pwms for both motors
    P2DIR |= BIT2;
    P2SEL |= BIT2;

    P2DIR |= BIT4;
    P2SEL |= BIT4;

	TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
    TA1CCR0 = 0x0100;						// set signal period

    // way coded, moves faster as number gets smaller
    TA1CCR1 = 0x0050;
    TA1CCR2 = 0x0050;

    while(1){
//   	sampleLeft = leftSensorReading();
//    	sampleFront = frontSensorReading();
//    	sampleRight = rightSensorReading();
//    	moveForward();
//		__delay_cycles(1000000);
    	if(leftSensorReading()){
    		if(!frontSensorReading()){
            	moveForward();
        		__delay_cycles(500000);
    		}
    		else if(frontSensorReading()){
        		stop();
        		__delay_cycles(2000000);
        		turnRight(1);
        		__delay_cycles(1200000);
    		}
    	}
//   	else if(leftSensorReading()){
//   		__delay_cycles(1000000);
//    	}
    	else{
    		stop();
    		__delay_cycles(2000000);
        	turnLeft(1);
    		__delay_cycles(1500000);
//        	stop();
//        	__delay_cycles(1000000);
        	moveForward();
    		__delay_cycles(3500000);
    	}
    }
}
