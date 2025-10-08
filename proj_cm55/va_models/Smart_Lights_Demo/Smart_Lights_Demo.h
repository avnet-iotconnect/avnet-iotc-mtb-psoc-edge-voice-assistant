/*****************************************************************************
* \file Smart_Lights_Demo.h
*****************************************************************************
* \copyright
* Copyright 2024, Infineon Technologies.
* All rights reserved.
*****************************************************************************/

#ifndef SMART_LIGHTS_DEMO_H
#define SMART_LIGHTS_DEMO_H

#include <stdint.h>

#define SMART_LIGHTS_DEMO_NUM_INTENTS 4
#define SMART_LIGHTS_DEMO_NUM_COMMANDS 82
#define SMART_LIGHTS_DEMO_NUM_VARIABLES 3
#define SMART_LIGHTS_DEMO_NUM_VARIABLE_PHRASES 7
#define SMART_LIGHTS_DEMO_NUM_UNIT_PHRASES 16
#define SMART_LIGHTS_DEMO_INTENT_MAP_ARRAY_TOTAL_SIZE 326
#define SMART_LIGHTS_DEMO_UNIT_PHRASE_MAP_ARRAY_TOTAL_SIZE 100

extern const char* Smart_Lights_Demo_intent_name_list[SMART_LIGHTS_DEMO_NUM_INTENTS];

extern const char* Smart_Lights_Demo_variable_name_list[SMART_LIGHTS_DEMO_NUM_VARIABLES];

extern const char* Smart_Lights_Demo_variable_phrase_list[SMART_LIGHTS_DEMO_NUM_VARIABLE_PHRASES];

extern const char* Smart_Lights_Demo_unit_phrase_list[SMART_LIGHTS_DEMO_NUM_UNIT_PHRASES];

extern const int Smart_Lights_Demo_intent_map_array[SMART_LIGHTS_DEMO_INTENT_MAP_ARRAY_TOTAL_SIZE];

extern const int Smart_Lights_Demo_intent_map_array_sizes[SMART_LIGHTS_DEMO_NUM_COMMANDS];

extern const int Smart_Lights_Demo_variable_phrase_sizes[SMART_LIGHTS_DEMO_NUM_VARIABLES];

extern const int Smart_Lights_Demo_unit_phrase_map_array[SMART_LIGHTS_DEMO_UNIT_PHRASE_MAP_ARRAY_TOTAL_SIZE];

extern const int Smart_Lights_Demo_unit_phrase_map_array_sizes[SMART_LIGHTS_DEMO_NUM_COMMANDS];

#endif // SMART_LIGHTS_DEMO_H
