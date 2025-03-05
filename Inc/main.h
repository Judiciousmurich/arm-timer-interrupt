#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f10x.h"  // Include the header file for your microcontroller

// Function prototypes
void Timer1_Init(void);
void GPIO_Init(void);
void NVIC_Configuration(void);

#endif /* __MAIN_H */