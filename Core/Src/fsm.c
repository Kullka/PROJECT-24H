/*
 * fsm.c
 *
 *  Created on: Nov 4, 2022
 *      Author: loing
 */

#include "fsm.h"
#include "software_timer.h"
#include "led.h"

int status = MODE1;
int counter = COUNTER;

void fsm() {
	switch(status) {
	case MODE1:
		if (timer1Flag==1) {
			display_7SEG1(counter);
			counter--;
			if (counter==0)
				counter = value;
			set_timer1(DURATION1);
		}
		break;
	case MODE2:
		if (timer2Flag==1) {
			display_7SEG1(value);
			set_timer2(DURATION2);
		}
		break;
	}
}
