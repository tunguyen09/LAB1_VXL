/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int Yellow_Count_Group1 = 3;// yellow-led turn on 2 seconds
   int Red_Count_Group1 = 6;// red-led turn on 5 seconds
   int Green_Count_Group1 = 4;// green-led turn on 3 seconds

   int Yellow_Status_Group1 = 0;//yellow-led off
   int Red_Status_Group1 = 0;//red-led off
   int Green_Status_Group1 = 1;// green-led is turn on

   //initial for group2
   int Yellow_Count_Group2 = 3;;// yellow-led turn on 2 seconds
   int Red_Count_Group2 = 6;// red-led turn on 5 seconds
   int Green_Count_Group2 = 4;// green-led turn on 3 seconds

   int Yellow_Status_Group2 = 0;//yellow-led off
   int Red_Status_Group2 = 1;// red-led is turn on
   int Green_Status_Group2 = 0;//green-led off
  while (1)
  {
	  if(Green_Status_Group1 == 1)
	  	  {
	  		  Green_Count_Group1 --;
	  		  HAL_GPIO_WritePin(GREENA_GPIO_Port, GREENA_Pin, GPIO_PIN_SET);

	  		  if(Green_Count_Group1 == 0)
	  		  {
	  			 Green_Status_Group1 = 0;// green-led turn off
	  			 Green_Count_Group1 = 3;// update time of green-led
	  			 HAL_GPIO_WritePin(GREENA_GPIO_Port, GREENA_Pin, GPIO_PIN_RESET);
	  			 Yellow_Status_Group1 = 1;//yellow-led turn on
	  		  }
	  	  }

	  	  // yellow-led will turn on in 2 seconds untill yellow-status=0
	  	  if(Yellow_Status_Group1 == 1)
	  	  {
	  		  Yellow_Count_Group1 --;
	  		  HAL_GPIO_WritePin(YELLOWA_GPIO_Port, YELLOWA_Pin, GPIO_PIN_SET);

	  		  if(Yellow_Count_Group1 == 0)
	  		  {
	  			  Yellow_Status_Group1 = 0;// yellow-led turn off
	  			  Yellow_Count_Group1 = 3;// update time of yellow-led
	  			  HAL_GPIO_WritePin(YELLOWA_GPIO_Port, YELLOWA_Pin, GPIO_PIN_RESET);
	  			  Red_Status_Group1 = 1;// red-led turn on
	  		  }
	  	  }

	  	  // red-led will turn on in 5 seconds untill red-status=0
	  	  if(Red_Status_Group1 == 1)
	  	  {
	  		  Red_Count_Group1 --;
	  		  HAL_GPIO_WritePin(REDA_GPIO_Port, REDA_Pin, GPIO_PIN_SET);

	  		  if(Red_Count_Group1 == 0)
	  		  {
	  			  Red_Status_Group1 = 0;// red-led turn off
	  			  Red_Count_Group1 = 6;// update time of red-led
	  			  HAL_GPIO_WritePin(REDA_GPIO_Port, REDA_Pin, GPIO_PIN_RESET);

	  			  HAL_GPIO_WritePin(GREENA_GPIO_Port, GREENA_Pin, GPIO_PIN_SET);
	  			  Green_Status_Group1 = 1;// green-led turn on
	  		  }
	  	  }
	  	  //---------end group1 ( group horizontal)----------


	  	  //-------begin group2 ( group vertical)-----------
	  	  // in group2, red-led bright first

	  	  // red-led will turn on in 5 seconds untill red-status=0
	  	  if(Red_Status_Group2 == 1)
	  	  {
	  		  Red_Count_Group2 --;
	  		  HAL_GPIO_WritePin(REDB_GPIO_Port, REDB_Pin, GPIO_PIN_SET);

	  		  if(Red_Count_Group2 == 0)
	  		  {
	  			 Red_Status_Group2 = 0;// red-led turn off
	  			 Red_Count_Group2 = 5;// update time of red-led
	  			 HAL_GPIO_WritePin(REDB_GPIO_Port, REDB_Pin, GPIO_PIN_RESET);
	  			 Green_Status_Group2 = 1;// green-led turn on
	  		  }
	  	  }

	  	  //green-led will turn on in 3 seconds untill green-status=0
	  	  if(Green_Status_Group2 == 1)
	  	  {
	  		  Green_Count_Group2 --;
	  		  HAL_GPIO_WritePin(GREENB_GPIO_Port, GREENB_Pin, GPIO_PIN_SET);

	  		  if(Green_Count_Group2 == 0)
	  		  {
	  			 Green_Status_Group2 = 0;// green-led turn off
	  			 Green_Count_Group2 = 4;// update time of green-led
	  			 HAL_GPIO_WritePin(GREENB_GPIO_Port, GREENB_Pin, GPIO_PIN_RESET);
	  			 Yellow_Status_Group2 = 1;//yellow-led turn on
	  		  }
	  	  }

	  	  //yellow-led will turn on in 3 seconds untill yellow-status=0
	  	  if(Yellow_Status_Group2 == 1)
	  	  {
	  		  Yellow_Count_Group2 --;
	  		  HAL_GPIO_WritePin(YELLOWB_GPIO_Port, YELLOWB_Pin, GPIO_PIN_SET);

	  		  if(Yellow_Count_Group2 == 0)
	  		  {
	  			  Yellow_Status_Group2 = 0;// yellow-led turn off
	  			  Yellow_Count_Group2 = 3;// update time of yellow-led
	  			  HAL_GPIO_WritePin(YELLOWB_GPIO_Port, YELLOWB_Pin, GPIO_PIN_RESET);

	  			  HAL_GPIO_WritePin(REDB_GPIO_Port, REDB_Pin, GPIO_PIN_SET);
	  			  Red_Status_Group2 = 1;// red-led turn on
	  		  }
	  	  }
	  	  //---------end group2 ( group vertical)-------------

	  	  HAL_Delay(1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, REDB_Pin|GREENB_Pin|YELLOWB_Pin|REDA_Pin
                          |GREENA_Pin|YELLOWA_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : REDB_Pin GREENB_Pin YELLOWB_Pin REDA_Pin
                           GREENA_Pin YELLOWA_Pin */
  GPIO_InitStruct.Pin = REDB_Pin|GREENB_Pin|YELLOWB_Pin|REDA_Pin
                          |GREENA_Pin|YELLOWA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
