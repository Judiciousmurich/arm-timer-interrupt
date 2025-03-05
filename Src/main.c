#include "main.h"

// Function to initialize Timer 1
void Timer1_Init(void) {
    // Enable the clock for TIM1
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
    
    // Timer configuration
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_Period = 1000 - 1;  // Reload value (1 ms interrupt)
    TIM_TimeBaseStructure.TIM_Prescaler = 48 - 1; // Prescaler value (48 MHz / 48 = 1 MHz)
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
    
    // Enable the TIM1 update interrupt
    TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);
    
    // Enable TIM1
    TIM_Cmd(TIM1, ENABLE);
}

// Function to initialize GPIO for LED
void GPIO_Init(void) {
    // Enable the clock for GPIOC
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    
    // Configure PC5 as output push-pull
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

// Function to configure NVIC for Timer 1 interrupt
void NVIC_Configuration(void) {
    NVIC_InitTypeDef NVIC_InitStructure;
    
    // Enable the TIM1 global interrupt
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

// Timer 1 Interrupt Service Routine (ISR)
void TIM1_UP_IRQHandler(void) {
    if (TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET) {
        // Toggle LED (assuming LED is connected to GPIO Pin 5 of Port C)
        GPIOC->ODR ^= GPIO_Pin_5;
        
        // Clear the interrupt flag
        TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
    }
}

// Main function
int main(void) {
    // Initialize GPIO and Timer
    GPIO_Init();
    Timer1_Init();
    
    // Configure NVIC
    NVIC_Configuration();
    
    // Enable global interrupts
    __enable_irq();
    
    while (1) {
        // Main loop - do nothing, everything is handled in the ISR
    }
}