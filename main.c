#include <stdint.h>
#include "stm32c0xx.h"

#define LED_RED_PIN_NUM     10   
#define LED_YELLOW_PIN_NUM  3    
#define LED_GREEN_PIN_NUM   10 

void delay_ms(uint32_t ms);

int main(void) {
    RCC->IOPENR |= (RCC_IOPENR_GPIOAEN | RCC_IOPENR_GPIOBEN);
    
    GPIOA->MODER &= ~GPIO_MODER_MODE10;
    GPIOA->MODER |= (0x1 << GPIO_MODER_MODE10_Pos);
    GPIOA->OTYPER &= ~GPIO_OTYPER_OT10;
    GPIOA->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED10;
    GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD10;
    
    GPIOB->MODER &= ~GPIO_MODER_MODE3;
    GPIOB->MODER |= (0x1 << GPIO_MODER_MODE3_Pos);
    GPIOB->OTYPER &= ~GPIO_OTYPER_OT3;
    GPIOB->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED3;
    GPIOB->PUPDR &= ~GPIO_PUPDR_PUPD3;
    
    GPIOB->MODER &= ~GPIO_MODER_MODE10;
    GPIOB->MODER |= (0x1 << GPIO_MODER_MODE10_Pos);
    GPIOB->OTYPER &= ~GPIO_OTYPER_OT10;
    GPIOB->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED10;
    GPIOB->PUPDR &= ~GPIO_PUPDR_PUPD10;

    while (1) {
        GPIOA->BSRR = (1 << LED_RED_PIN_NUM);           // Set PA10 (Red LED ON)
        GPIOB->BSRR = (1 << (LED_YELLOW_PIN_NUM + 16)); // Reset PB3 (Yellow LED OFF)
        GPIOB->BSRR = (1 << (LED_GREEN_PIN_NUM + 16));  // Reset PB10 (Green LED OFF)
        delay_ms(5000);

        // YELLOW ON (PB3 - D3)
        GPIOA->BSRR = (1 << (LED_RED_PIN_NUM + 16));    // Reset PA10 (Red LED OFF)
        GPIOB->BSRR = (1 << LED_YELLOW_PIN_NUM);        // Set PB3 (Yellow LED ON)
        GPIOB->BSRR = (1 << (LED_GREEN_PIN_NUM + 16));  // Reset PB10 (Green LED OFF)
        delay_ms(3000);

        // GREEN ON (PB10 - D4)
        GPIOA->BSRR = (1 << (LED_RED_PIN_NUM + 16));    // Reset PA10 (Red LED OFF)
        GPIOB->BSRR = (1 << (LED_YELLOW_PIN_NUM + 16)); // Reset PB3 (Yellow LED OFF)
        GPIOB->BSRR = (1 << LED_GREEN_PIN_NUM);         // Set PB10 (Green LED ON)
        delay_ms(5000);

        // Turn OFF all LEDs before restart
        GPIOA->BSRR = (1 << (LED_RED_PIN_NUM + 16));    // Reset PA10
        GPIOB->BSRR = (1 << (LED_YELLOW_PIN_NUM + 16)); // Reset PB3
        GPIOB->BSRR = (1 << (LED_GREEN_PIN_NUM + 16));  // Reset PB10
        delay_ms(100);
    }
}

// Simple blocking delay - adjusted for STM32C031C6 @ 48MHz
void delay_ms(uint32_t ms) {
    for (uint32_t i = 0; i < ms * 1200; i++) {
        __NOP();
    }
}
