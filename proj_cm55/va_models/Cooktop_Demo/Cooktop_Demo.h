/*****************************************************************************
* \file Cooktop_Demo.h
*****************************************************************************
* \copyright
* Copyright 2024, Infineon Technologies.
* All rights reserved.
*****************************************************************************/

#ifndef COOKTOP_DEMO_H
#define COOKTOP_DEMO_H

#include <stdint.h>

#define COOKTOP_DEMO_NUM_INTENTS 4
#define COOKTOP_DEMO_NUM_COMMANDS 7
#define COOKTOP_DEMO_NUM_VARIABLES 3
#define COOKTOP_DEMO_NUM_VARIABLE_PHRASES 4
#define COOKTOP_DEMO_NUM_UNIT_PHRASES 16
#define COOKTOP_DEMO_INTENT_MAP_ARRAY_TOTAL_SIZE 22
#define COOKTOP_DEMO_UNIT_PHRASE_MAP_ARRAY_TOTAL_SIZE 12

extern const char* Cooktop_Demo_intent_name_list[COOKTOP_DEMO_NUM_INTENTS];

extern const char* Cooktop_Demo_variable_name_list[COOKTOP_DEMO_NUM_VARIABLES];

extern const char* Cooktop_Demo_variable_phrase_list[COOKTOP_DEMO_NUM_VARIABLE_PHRASES];

extern const char* Cooktop_Demo_unit_phrase_list[COOKTOP_DEMO_NUM_UNIT_PHRASES];

extern const int Cooktop_Demo_intent_map_array[COOKTOP_DEMO_INTENT_MAP_ARRAY_TOTAL_SIZE];

extern const int Cooktop_Demo_intent_map_array_sizes[COOKTOP_DEMO_NUM_COMMANDS];

extern const int Cooktop_Demo_variable_phrase_sizes[COOKTOP_DEMO_NUM_VARIABLES];

extern const int Cooktop_Demo_unit_phrase_map_array[COOKTOP_DEMO_UNIT_PHRASE_MAP_ARRAY_TOTAL_SIZE];

extern const int Cooktop_Demo_unit_phrase_map_array_sizes[COOKTOP_DEMO_NUM_COMMANDS];

#endif // COOKTOP_DEMO_H
