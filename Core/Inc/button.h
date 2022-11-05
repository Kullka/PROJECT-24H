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
#define TIME_INCREASE_VALUE 1000
#define TIME_CHANGE_TO_AUTO 2000

extern int keyIsPressed[NO_BUTTONS];
extern int keyIsKeeped[NO_BUTTONS];

void getKeyInput();

#endif /* INC_BUTTON_H_ */
