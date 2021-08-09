/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>

#include "wifi.h"

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */


/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

#define LogUsart1Enable 1

#if LogUsart1Enable
//#define log_usart1(format,...) printf("File:"__FILE__",Line:%d:"format"",__LINE__,##__VA_ARGS__)
#define log_usart1(format,...) printf(format,##__VA_ARGS__)//不打印行
#else
  #define log_usart1(format,...) ;
  
  
#endif
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DI1_Pin GPIO_PIN_4
#define DI1_GPIO_Port GPIOA
#define DI1_EXTI_IRQn EXTI4_IRQn
#define DI2_Pin GPIO_PIN_5
#define DI2_GPIO_Port GPIOA
#define DI2_EXTI_IRQn EXTI9_5_IRQn
#define DI3_Pin GPIO_PIN_6
#define DI3_GPIO_Port GPIOA
#define DI3_EXTI_IRQn EXTI9_5_IRQn
#define DI4_Pin GPIO_PIN_7
#define DI4_GPIO_Port GPIOA
#define DI4_EXTI_IRQn EXTI9_5_IRQn
#define DO4_Pin GPIO_PIN_10
#define DO4_GPIO_Port GPIOC
#define DO3_Pin GPIO_PIN_11
#define DO3_GPIO_Port GPIOC
#define DO2_Pin GPIO_PIN_12
#define DO2_GPIO_Port GPIOC
#define DO1_Pin GPIO_PIN_2
#define DO1_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */

#define FanClose() do{ HAL_GPIO_WritePin(DO1_GPIO_Port,DO1_Pin,GPIO_PIN_RESET);\
                     HAL_GPIO_WritePin(DO2_GPIO_Port,DO2_Pin,GPIO_PIN_RESET);\
                     HAL_GPIO_WritePin(DO3_GPIO_Port,DO3_Pin,GPIO_PIN_RESET);\
                     HAL_GPIO_WritePin(DO4_GPIO_Port,DO4_Pin,GPIO_PIN_RESET);\
                     SWITCH = 0;}while(0)


#define FanGear_1() do{HAL_GPIO_WritePin(DO1_GPIO_Port,DO1_Pin,GPIO_PIN_SET);\
                        mcu_dp_value_update(DPID_FAN_SPEED,1);\
                        mcu_dp_enum_update(DPID_GEAR,0);\
                        SWITCH = 1;SPEED = 1;GEAR = 0;}while(0)
#define FanGear_2() do{HAL_GPIO_WritePin(DO2_GPIO_Port,DO2_Pin,GPIO_PIN_SET);\
                        mcu_dp_value_update(DPID_FAN_SPEED,26);\
                        mcu_dp_enum_update(DPID_GEAR,1);\
                        SWITCH = 1;SPEED = 26;GEAR = 1;}while(0)
#define FanGear_3() do{HAL_GPIO_WritePin(DO3_GPIO_Port,DO3_Pin,GPIO_PIN_SET);\
                        mcu_dp_value_update(DPID_FAN_SPEED,51);\
                        mcu_dp_enum_update(DPID_GEAR,2);\
                        SWITCH = 1;SPEED = 51;GEAR = 2;}while(0)
#define FanGear_4() do{HAL_GPIO_WritePin(DO4_GPIO_Port,DO4_Pin,GPIO_PIN_SET);\
                        mcu_dp_value_update(DPID_FAN_SPEED,76);\
                        mcu_dp_enum_update(DPID_GEAR,3);\
                        SWITCH = 1;SPEED = 76;GEAR = 3;}while(0)                   

extern uint8_t SWITCH;//开关
extern uint8_t SPEED;//风速
extern uint8_t GEAR;//档位
                        
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
