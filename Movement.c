/*
 * Movement.c
 *
 *  Created on: Dec 9, 2014
 *      Author: C16Matthew.Bergstedt
 */
#include <msp430.h>

#define TURN_90 450000

/*
 * stop function
 * Description: stops the robot
 */
void stop(void){
	// turn off the enables
	P2OUT &= ~(BIT0 | BIT3);
}

/*
* moveForward function
* Description: moves the robot to forward
*/
void moveForward(void){
	// turn on the enables
	P2OUT |= BIT0 | BIT3;

	// left motor ccw
	P2OUT |= BIT1;
	TA1CCTL1 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode

	// right motor cw
	P2OUT &= ~BIT5;
	TA1CCTL2 = OUTMOD_3;					// set TACCTL2 to Set / Reset mode

//	__delay_cycles(3000000);
}

/*
 * moveBackward function
 * Description: moves the robot to backwards
 */
void moveBackward(void){
	// turn on the enables
	P2OUT |= BIT0 | BIT3;

	// left motor cw
	P2OUT &= ~BIT1;
	TA1CCTL1 = OUTMOD_3;

	// right motor ccw
	P2OUT |= BIT5;
	TA1CCTL2 = OUTMOD_7;
}

/*
 * turnLeft function
 * Description: turns the robot to the left
 */
void turnLeft(char turnType){
	// turn on the enables
	P2OUT |= BIT0 | BIT3;

	// left motor cw
	P2OUT &= ~BIT1;
	TA1CCTL1 = OUTMOD_3;

	// right motor cw
	P2OUT &= ~BIT5;
	TA1CCTL2 = OUTMOD_3;

	// long turn as 1, short turn as 0
	if(turnType){
		__delay_cycles(TURN_90);
	}
	else{
		__delay_cycles(TURN_90/2);
	}
}

/*
 * turnRight function
 * Description: turns the robot to the right
 */
void turnRight(char turnType){
	// turn on the enables
	P2OUT |= BIT0 | BIT3;

	// left motor ccw
	P2OUT |= BIT1;
	TA1CCTL1 = OUTMOD_7;

	// right motor ccw
	P2OUT |= BIT5;
	TA1CCTL2 = OUTMOD_7;

	// long turn as 1, short turn as 0
	if(turnType){
		__delay_cycles(TURN_90);
	}
	else{
		__delay_cycles(TURN_90/2);
	}
}
