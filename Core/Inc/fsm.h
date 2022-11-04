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
//extern int value1;

// enum Auto_led {STATE0, STATE1, STATE2, STATE3};
enum Mode {MODE1, MODE2};

void fsm();
//void fsm_manual();


#endif /* INC_FSM_H_ */
