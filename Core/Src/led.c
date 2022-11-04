/*
 * led.c
 *
 *  Created on: Nov 4, 2022
 *      Author: loing
 */

#include "led.h"
#include "main.h"

#define ZERO 0x3F
#define ONE 0x06
#define TWO 0x5B
#define THREE 0x4F
#define FOUR 0x66
#define FIVE 0x6D
#define SIX 0x7D
#define SEVEN 0x07
#define EIGHT 0x7F
#define NINE 0x67
#define OFF 0x7F

void reset_7SEG1() {
	GPIOB->ODR |= OFF;
}

void display_7SEG1(int number) {
	reset_7SEG1();
	switch(number) {
	case 0:
		GPIOB->ODR &= ~ZERO;
		break;
	case 1:
		GPIOB->ODR &= ~ONE;
		break;
	case 2:
		GPIOB->ODR &= ~TWO;
		break;
	case 3:
		GPIOB->ODR &= ~THREE;
		break;
	case 4:
		GPIOB->ODR &= ~FOUR;
		break;
	case 5:
		GPIOB->ODR &= ~FIVE;
		break;
	case 6:
		GPIOB->ODR &= ~SIX;
		break;
	case 7:
		GPIOB->ODR &= ~SEVEN;
		break;
	case 8:
		GPIOB->ODR &= ~EIGHT;
		break;
	case 9:
		GPIOB->ODR &= ~NINE;
		break;
	default:
		GPIOB->ODR &= ~NINE;
		break;
	}
}
