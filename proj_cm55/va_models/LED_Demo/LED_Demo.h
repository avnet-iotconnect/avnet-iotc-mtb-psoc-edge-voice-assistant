/*****************************************************************************
* \file LED_Demo.h
*****************************************************************************
* \copyright
* Copyright 2024, Infineon Technologies.
* All rights reserved.
*****************************************************************************/

#ifndef LED_DEMO_H
#define LED_DEMO_H

#include <stdint.h>

#define LED_DEMO_NUM_INTENTS 6
#define LED_DEMO_NUM_COMMANDS 16
#define LED_DEMO_NUM_VARIABLES 1
#define LED_DEMO_NUM_VARIABLE_PHRASES 1
#define LED_DEMO_NUM_UNIT_PHRASES 16
#define LED_DEMO_INTENT_MAP_ARRAY_TOTAL_SIZE 38
#define LED_DEMO_UNIT_PHRASE_MAP_ARRAY_TOTAL_SIZE 22

extern const char* LED_Demo_intent_name_list[LED_DEMO_NUM_INTENTS];

extern const char* LED_Demo_variable_name_list[LED_DEMO_NUM_VARIABLES];

extern const char* LED_Demo_variable_phrase_list[LED_DEMO_NUM_VARIABLE_PHRASES];

extern const char* LED_Demo_unit_phrase_list[LED_DEMO_NUM_UNIT_PHRASES];

extern const int LED_Demo_intent_map_array[LED_DEMO_INTENT_MAP_ARRAY_TOTAL_SIZE];

extern const int LED_Demo_intent_map_array_sizes[LED_DEMO_NUM_COMMANDS];

extern const int LED_Demo_variable_phrase_sizes[LED_DEMO_NUM_VARIABLES];

extern const int LED_Demo_unit_phrase_map_array[LED_DEMO_UNIT_PHRASE_MAP_ARRAY_TOTAL_SIZE];

extern const int LED_Demo_unit_phrase_map_array_sizes[LED_DEMO_NUM_COMMANDS];

#endif // LED_DEMO_H
