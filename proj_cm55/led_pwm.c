/******************************************************************************
* File Name : led_pwm.c
*
* Description :
* Code for the LED PWM driver.
********************************************************************************
* Copyright 2024-2025, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/

/*******************************************************************************
* Header Files
*******************************************************************************/

#include "led_pwm.h"

#include "cy_pdl.h"
#include "cybsp.h"

/*******************************************************************************
* Macros
*******************************************************************************/
#define LED_PWM_ON  (1u)
#define LED_PWM_OFF (0u)

/*******************************************************************************
* Global Variables
*******************************************************************************/
uint8_t led_pwm_blue_brightness = 0;
uint8_t led_pwm_blue_state = LED_PWM_OFF;
uint8_t led_pwm_green_brightness = 0;
uint8_t led_pwm_green_state = LED_PWM_OFF;

#define LED_PWM_BLUE_BASE        CYBSP_PWM_LED_CTRL_HW
#define LED_PWM_BLUE_CNT_NUM     CYBSP_PWM_LED_CTRL_NUM
#define LED_PWM_BLUE_CONFIG      CYBSP_PWM_LED_CTRL_config

#define LED_PWM_GREEN_BASE       CYBSP_PWM_LED_CTRL_2_HW
#define LED_PWM_GREEN_CNT_NUM    CYBSP_PWM_LED_CTRL_2_NUM
#define LED_PWM_GREEN_CONFIG     CYBSP_PWM_LED_CTRL_2_config

#define LED_PWM_PERIOD      (10U)
#define LED_PWM_FACTOR(x)   (((LED_PWM_PERIOD) * x) / 100)

/*******************************************************************************
* Functions Prototypes
*******************************************************************************/

/*******************************************************************************
 * Function Name: led_pwm_init
 ********************************************************************************
 * Summary:
 *  Initialize the the PWMs connected to the LEDs.
 *
 * Parameters:
 *  void
 *
 * Return:
 *  Return CY_RSLT_SUCCESS if successful, else return error code.
 *
 *******************************************************************************/
cy_rslt_t led_pwm_init(void)
{
    cy_rslt_t result;

    /* Init the BLUE LED */
    result = Cy_TCPWM_PWM_Init(LED_PWM_BLUE_BASE, LED_PWM_BLUE_CNT_NUM, &LED_PWM_BLUE_CONFIG);
    if (result != CY_RSLT_SUCCESS)
    {
        return result;
    }

    /* Init the GREEN LED */
    result = Cy_TCPWM_PWM_Init(LED_PWM_GREEN_BASE, LED_PWM_GREEN_CNT_NUM, &LED_PWM_GREEN_CONFIG);
    if (result != CY_RSLT_SUCCESS)
    {
        return result;
    }

    /* Enable the BLUE LED */
    Cy_TCPWM_PWM_SetPeriod0(LED_PWM_BLUE_BASE, LED_PWM_BLUE_CNT_NUM, LED_PWM_PERIOD);
    Cy_TCPWM_PWM_Enable(LED_PWM_BLUE_BASE, LED_PWM_BLUE_CNT_NUM);
    Cy_TCPWM_TriggerStart_Single(LED_PWM_BLUE_BASE, LED_PWM_BLUE_CNT_NUM);

    /* Enable the GREEN LED */
    Cy_TCPWM_PWM_SetPeriod0(LED_PWM_GREEN_BASE, LED_PWM_GREEN_CNT_NUM, LED_PWM_PERIOD);
    Cy_TCPWM_PWM_Enable(LED_PWM_GREEN_BASE, LED_PWM_GREEN_CNT_NUM);
    Cy_TCPWM_TriggerStart_Single(LED_PWM_GREEN_BASE, LED_PWM_GREEN_CNT_NUM);

    led_pwm_set_brightness(LED_PWM_BLUE_LED, 0);
    led_pwm_set_brightness(LED_PWM_GREEN_LED, 0);

    return result;
}

/*******************************************************************************
 * Function Name: led_pwm_on
 ********************************************************************************
 * Summary:
 *  Set the LED to ON state.
 *
 * Parameters:
 *  led: indicate which LED to use
 *
 * Return:
 *  void
 *
 *******************************************************************************/
void led_pwm_on(uint8_t led)
{
    if (led == LED_PWM_BLUE_LED)
    {
        led_pwm_blue_state = LED_PWM_ON;

        if (led_pwm_blue_brightness < LED_PWM_MIN_BRIGHTNESS)
        {
            led_pwm_blue_brightness = LED_PWM_MAX_BRIGHTNESS;
        }

        Cy_TCPWM_PWM_SetCompare0(LED_PWM_BLUE_BASE, LED_PWM_BLUE_CNT_NUM, 
                                 LED_PWM_FACTOR(led_pwm_blue_brightness));
    }
    else if (led == LED_PWM_GREEN_LED)
    {
        led_pwm_green_state = LED_PWM_ON;

        if (led_pwm_green_brightness < LED_PWM_MIN_BRIGHTNESS)
        {
            led_pwm_green_brightness = LED_PWM_MAX_BRIGHTNESS;
        }

        Cy_TCPWM_PWM_SetCompare0(LED_PWM_GREEN_BASE, LED_PWM_GREEN_CNT_NUM, 
                                 LED_PWM_FACTOR(led_pwm_green_brightness));
    }
}

/*******************************************************************************
 * Function Name: led_pwm_off
 ********************************************************************************
 * Summary:
 *  Set the LED to OFF state.
 *
 * Parameters:
 *  led: indicate which LED to use
 *
 * Return:
 *  void
 *
 *******************************************************************************/
void led_pwm_off(uint8_t led)
{
    if (led == LED_PWM_BLUE_LED)
    {
        led_pwm_blue_state = LED_PWM_OFF;

        Cy_TCPWM_PWM_SetCompare0(LED_PWM_BLUE_BASE, LED_PWM_BLUE_CNT_NUM, 0);
    }
    else if (led == LED_PWM_GREEN_LED)
    {
        led_pwm_green_state = LED_PWM_OFF;

        Cy_TCPWM_PWM_SetCompare0(LED_PWM_GREEN_BASE, LED_PWM_GREEN_CNT_NUM, 0);
    }
}

/*******************************************************************************
 * Function Name: led_pwm_off
 ********************************************************************************
 * Summary:
 *  Toggle the LED state.
 *
 * Parameters:
 *  led: indicate which LED to use
 *
 * Return:
 *  void
 *
 *******************************************************************************/
void led_pwm_toggle(uint8_t led)
{
    if (led == LED_PWM_BLUE_LED)
    {
        if (led_pwm_blue_state == LED_PWM_ON)
        {
            led_pwm_off(LED_PWM_BLUE_LED);
        }
        else
        {
            led_pwm_on(LED_PWM_BLUE_LED);
        }
    } 
    else if (led == LED_PWM_GREEN_LED)
    {
        if (led_pwm_green_state == LED_PWM_ON)
        {
            led_pwm_off(LED_PWM_GREEN_LED);
        }
        else
        {
            led_pwm_on(LED_PWM_GREEN_LED);
        }
    }
}

/*******************************************************************************
 * Function Name: led_pwm_set_brightness
 ********************************************************************************
 * Summary:
 *  Set the brightness of the LED in percent.
 *
 * Parameters:
 *  led: indicate which LED to use
 *  brightness: LED brightness in percent (0-100)
 *
 * Return:
 *  Return CY_RSLT_SUCCESS if successful, else return error code.
 *
 *******************************************************************************/
cy_rslt_t led_pwm_set_brightness(uint8_t led, uint8_t brightness)
{
    if (brightness > LED_PWM_MAX_BRIGHTNESS)
    {
        return CY_TCPWM_BAD_PARAM;
    }

    if (led == LED_PWM_BLUE_LED)
    {
        Cy_TCPWM_PWM_SetCompare0(LED_PWM_BLUE_BASE, LED_PWM_BLUE_CNT_NUM, 
                                LED_PWM_FACTOR(brightness));

        led_pwm_blue_brightness = brightness;

        if (brightness < LED_PWM_MIN_BRIGHTNESS)
        {
            led_pwm_blue_state = LED_PWM_OFF;
        }
        else
        {
            led_pwm_blue_state = LED_PWM_ON;
        }
    }
    else if (led == LED_PWM_GREEN_LED)
    {
        /* Mapping brightness level <0-10> to <0-100>*/
        brightness = 10 *brightness;
        
        Cy_TCPWM_PWM_SetCompare0(LED_PWM_GREEN_BASE, LED_PWM_GREEN_CNT_NUM, 
                                LED_PWM_FACTOR(brightness));

        led_pwm_green_brightness = brightness;

        if (brightness < LED_PWM_MIN_BRIGHTNESS)
        {
            led_pwm_green_state = LED_PWM_OFF;
        }
        else
        {
            led_pwm_green_state = LED_PWM_ON;
        }
    }
    
    return CY_RSLT_SUCCESS;
}

/*******************************************************************************
 * Function Name: led_pwm_get_brightness
 ********************************************************************************
 * Summary:
 *  Return the current brigthness of the LED in percent.
 *
 * Parameters:
 *  led: indicate which LED to use
 *  brigthness: current LED brightness
 *
 * Return:
 *  Return CY_RSLT_SUCCESS if successful, else return error code.
 *
 *******************************************************************************/
cy_rslt_t led_pwm_get_brightness(uint8_t led, uint8_t *brightness)
{
    if (brightness == NULL)
    {
        return CY_TCPWM_BAD_PARAM;
    }
    if (led == LED_PWM_BLUE_LED)
    {
        *brightness = led_pwm_blue_brightness;
    }
    else if (led == LED_PWM_GREEN_LED)
    {
        *brightness = led_pwm_green_brightness;
    }
    return CY_RSLT_SUCCESS;
}

/*******************************************************************************
 * Function Name: led_pwm_deinit
 ********************************************************************************
 * Summary:
 *  De-initialize the PWM connected to the LED.
 *
 * Parameters:
 *  void
 *
 * Return:
 *  Return CY_RSLT_SUCCESS if successful, else return error code.
 *
 *******************************************************************************/
void led_pwm_deinit(void)
{
    Cy_TCPWM_PWM_DeInit(LED_PWM_BLUE_BASE, LED_PWM_BLUE_CNT_NUM, &LED_PWM_BLUE_CONFIG);
    Cy_TCPWM_PWM_DeInit(LED_PWM_GREEN_BASE, LED_PWM_GREEN_CNT_NUM, &LED_PWM_GREEN_CONFIG);
}

/* [] END OF FILE */
