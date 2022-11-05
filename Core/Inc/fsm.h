/*
 * fsm.h
 *
 *  Created on: Nov 4, 2022
 *      Author: loing
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

extern int status;
extern int counter;

enum STATE {RELEASED, COUNT_DOWN, RES, INCREASE, KEEP_INC, DECREASE, KEEP_DEC};

void fsm();

#endif /* INC_FSM_H_ */
