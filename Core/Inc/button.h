/*
 * button.h
 *
 *  Created on: Nov 4, 2022
 *      Author: loing
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
#define NO_BUTTONS 			4
#define TIME_INCREASE_VALUE 50
#define TIME_CHANGE_TO_AUTO 100

void getKeyInput();
void key0Process();
void key1Process();
void key2Process();

#endif /* INC_BUTTON_H_ */
