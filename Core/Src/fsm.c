/*
 * fsm.c
 *
 *  Created on: Nov 4, 2022
 *      Author: loing
 */

#include "fsm.h"
#include "software_timer.h"
#include "led.h"
#include "button.h"
int status = COUNT_DOWN;
int counter = COUNTER;

void fsm() {
	switch(status) {
	case COUNT_DOWN:
		if (timer1Flag==1) {
			display_7SEG1(counter);
			if (counter>0)
				counter--;
			set_timer1(TIMER1);
		}
		break;
	case RES:
		if (keyIsPressed[0]==1) {
			keyIsPressed[0] = 0;
			counter = 0;
			display_7SEG1(counter);
			set_timer1(TIMER1);
		}
		break;
	case INCREASE:
		if (keyIsPressed[1]==1) {
			keyIsPressed[1] = 0;
			counter++;
			counter %= 10;
			display_7SEG1(counter);
			set_timer1(TIMER1);
		}
		break;
	case KEEP_INC:
		if (keyIsKeeped[1]==1 && timer1Flag==1) {
			counter++;
			counter %= 10;
			display_7SEG1(counter);
			set_timer1(TIME_INCREASE_VALUE);
		}
		break;
	case DECREASE:
		if (keyIsPressed[2]==1) {
			keyIsPressed[2] = 0;
			counter--;
			if (counter==-1)
				counter = 9;
			display_7SEG1(counter);
			set_timer1(TIMER1);
		}
		break;
	case KEEP_DEC:
		if (keyIsKeeped[2]==1 && timer1Flag==1) {
			counter--;
			if (counter==-1)
				counter = 9;
			display_7SEG1(counter);
			set_timer1(TIME_INCREASE_VALUE);
		}
		break;
	}
	if (timer2Flag==1) {
		HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
		set_timer2(TIMER2);
	}
}
