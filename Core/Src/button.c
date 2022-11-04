/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: loing
 */

#include "software_timer.h"
#include "main.h"
#include "button.h"
#include "led.h"
#include "fsm.h"

int button[NO_BUTTONS] = {1<<13, 1<<14, 1<<15};
int keyReg0[NO_BUTTONS];
int keyReg1[NO_BUTTONS];
int keyReg2[NO_BUTTONS];
int keyReg3[NO_BUTTONS];
int timerForKeyPress = TIME_CHANGE_TO_AUTO;

void key0Process() {
	switch(status) {
	case MODE1:
		GPIOA->ODR |= (0x1<<3);
		set_timer2(DURATION2);
		status = MODE2;
		break;
	case MODE2:
		counter = value;
		set_timer1(DURATION1);
		status = MODE1;
		break;
	}
}

void key1Process() {
	if (status == MODE2) {
		value++;
		value %= 10;
	}
	else ;
}

void key2Process() {
	if (status == MODE2) {
		counter = value;
		set_timer1(DURATION1);
		status = MODE1;
	}
	else ;
}

void getKeyInput() {
	for (int i=0; i<NO_BUTTONS; i++) {
		keyReg0[i] = keyReg1[i];
		keyReg1[i] = keyReg2[i];
//		switch (i) {
//		case 0:
//			keyReg2[i] = HAL_GPIO_ReadPin(BUTTON0_GPIO_Port, BUTTON0_Pin);
//			break;
//		case 1:
//			keyReg2[i] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
//			break;
//		case 2:
//			keyReg2[i] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
//			break;
//		default:
//			break;
//		}
		keyReg2[i] = HAL_GPIO_ReadPin(GPIOA, button[i]);
		if ( (keyReg0[i]==keyReg1[i]) && (keyReg1[i]==keyReg2[i]) ) {
			if (keyReg3[i]!=keyReg2[i]) {
				keyReg3[i] = keyReg2[i];
				if (keyReg2[i] == PRESSED_STATE) {
					switch(i) {
					case 0:
						key0Process();
						break;
					case 1:
						key1Process();
						break;
					case 2:
						key2Process();
						break;
					default:
						break;
					}
					timerForKeyPress = TIME_CHANGE_TO_AUTO;
				}
			}
			else {
				timerForKeyPress--;
				if (timerForKeyPress==0) {
					if (keyReg2[i]==PRESSED_STATE) {
						switch(i) {
						case 0:
							key0Process();
							break;
						case 1:
							key1Process();
							break;
						case 2:
							key2Process();
							break;
						default:
							break;
						}
						timerForKeyPress = TIME_INCREASE_VALUE;
					}
				}
			}
		}
	}
}
