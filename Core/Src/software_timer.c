/*
 * software_timer.c
 *
 *  Created on: Nov 4, 2022
 *      Author: loing
 */

#include "software_timer.h"
#include "main.h"

int timer1Flag;
int timer2Flag;
int timer1Counter;
int timer2Counter;
int value = COUNTER;

void set_timer1(int duration){
	timer1Counter = duration/PERIOD;
	timer1Flag = 0;
}

void set_timer2(int duration) {
	timer2Counter = duration/PERIOD;
	timer2Flag = 0;
}

void timer1_run() {
	if (timer1Counter>0) {
		timer1Counter--;
		if (timer1Counter==0) timer1Flag = 1;
	}
	else
		timer1Flag = 0;
}

void timer2_run() {
	if (timer2Counter>0) {
		timer2Counter--;
		if (timer2Counter==0) timer2Flag = 1;
	}
	else
		timer2Flag = 0;
}
