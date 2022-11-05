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

int keyIsPressed[NO_BUTTONS];
int keyIsKeeped[NO_BUTTONS];
void getKeyInput() {
	for (int i=0; i<NO_BUTTONS; i++) {
		keyReg0[i] = keyReg1[i];
		keyReg1[i] = keyReg2[i];
		keyReg2[i] = HAL_GPIO_ReadPin(GPIOA, button[i]);
		if ( (keyReg0[i]==keyReg1[i]) && (keyReg1[i]==keyReg2[i]) ) {
			if (keyReg3[i]!=keyReg2[i]) {
				keyReg3[i] = keyReg2[i];
				if (keyReg2[i] == PRESSED_STATE) {
					keyIsPressed[i] = 1;
					switch (i) {
					case 0:
						status = RES;
						break;
					case 1:
						status = INCREASE;
						break;
					case 2:
						status = DECREASE;
						break;
					}
					timerForKeyPress = TIME_CHANGE_TO_AUTO;
				}
				else {
					keyIsPressed[i] = 0;
					status = COUNT_DOWN;
				}
			}
			else {
				timerForKeyPress = timerForKeyPress - 10;
				if (timerForKeyPress==0) {
					if (keyReg2[i]==PRESSED_STATE) {
						keyIsKeeped[i] = 1;
						switch(i) {
						case 1:
							status = KEEP_INC;
							break;
						case 2:
							status = KEEP_DEC;
							break;
						}
						set_timer1(TIME_CHANGE_TO_AUTO - TIMER1);
					}
					else
						keyIsKeeped[i] = 0;
				}
			}
		}
	}
}
