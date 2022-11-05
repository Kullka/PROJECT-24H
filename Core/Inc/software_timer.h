/*
 * software_timer.h
 *
 *  Created on: Nov 4, 2022
 *      Author: loing
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define PERIOD 10
#define TIMER1 1000
#define TIMER2 1000
#define COUNTER 9

extern int timer1Counter;
extern int timer1Flag;
extern int timer2Counter;
extern int timer2Flag;

void set_timer1(int duration);
void set_timer2(int duration);
void timer1_run();
void timer2_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
