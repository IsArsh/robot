/********************************************************************************************************************/
//文件名:   ultrasonic_A3U07.h
//描述:     超声波探头驱动
//版本:     V1.0
//日期:     2024-02-19
//作者:     Li Gang
/********************************************************************************************************************/

#ifndef _ULTRASONIC_A3U07_H_
#define _ULTRASONIC_A3U07_H_

#include "gd32f30x.h"
#include "adc.h"
#include "systick.h"
#include <stdio.h>
#include "protocol.h"

#define DEBUG
#ifdef DEBUG
    // #define DEBUG_self_check
	#define DEBUG_wave
	#define DEBUG_result
    #define DEBUG_average
#endif // DEBUG

#define FALSE   0
#define TRUE    1

#define FILTER_PARAM        0.5f                        // 一阶滤波系数
#define adc_num             200                         // 每次触发超声波采集的点数
#define CARPET_THRESHOLD_VALUE  35                      // 区分地毯和地板的阈值

/* 超声波配置宏定义 */
/* timer config */
#define RCU_TIMER           RCU_TIMER4
#define TIMER_PERIPH        TIMER4
#define TIMER_CH            TIMER_CH_1
#define TIMER_INT_CH        TIMER_INT_CH1
#define NVIC_IRQ_TIMER      TIMER4_IRQn
/* adc config */
#define RCU_ADC             RCU_ADC2
#define ADC_PERIPH          ADC2
#define ADC_CH              ADC_CHANNEL_10
/* adc dma config */
#define RCU_DMA             RCU_DMA1
#define ADC_DMA_PERIPH      DMA1
#define ADC_DMA_CH          DMA_CH4
#define NVIC_IRQ_DMA        DMA1_Channel3_Channel4_IRQn
/* power enable */
#define ULTRA_SONIC_POWER_GPIO_RCU    RCU_GPIOA
#define ULTRA_SONIC_POWER_PORT        GPIOA
#define ULTRA_SONIC_POWER_PIN         GPIO_PIN_11

typedef enum{
    EM_ULTRASONIC_DISCONTINUOUS = 0,                    // 单次采集模式
    EM_ULTRASONIC_CONTINUOUS                            // 连续采集模式
}EM_ULTRASONIC_MODE_t;

typedef enum{
    EM_MATERIAL_TYPE_UNKNOW = 0,
    EM_MATERIAL_TYPE_HARD,
    EM_MATERIAL_TYPE_SOFT
}EM_MATERIAL_TYPE_t;

typedef enum{
    EM_SONIC_RESULT_SOFT = 0,       // 地毯
    EM_SONIC_RESULT_HARD,           // 地板
    EM_SONIC_RESULT_DISCONNECTED,   // 线路连接异常
    EM_SONIC_RESULT_NOISE_0,        // 噪声1
    EM_SONIC_RESULT_NOISE_1,        // 噪声2
    EM_SONIC_RESULT_NO_DATA         // 无ADC数据
}EM_SONIC_RESULT_t;

typedef enum{
    EM_ERROR_NO_ERROR = 0,
    EM_ERROR_DISCONNECTED,
    EM_ERROR_NOISE_0,
    EM_ERROR_NOISE_1,
    EM_ERROR_NO_DATA
}EM_ERROR_TYPE_t;

typedef TUltraSonic UltraSonicResult_t;

void init_ultrasonic_A3U07(void);

extern void updateUltraSonicprocess(void);

extern void change_ultrasonic_debug_output(void);

extern UltraSonicResult_t getUltrasonicInfo();

void ultraSonicPowerInit(void);
void setUltraSonicPowerEnable(uint8_t en);
#endif /* ultrasonic_A3U07.h */

/* end of ultrasonic_A3U07.h */
