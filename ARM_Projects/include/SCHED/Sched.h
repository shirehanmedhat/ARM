/*
 * Sched.h
 *
 *  Created on: Mar 14, 2024
 *      Author: NoteBook
 */
#include "LIB/STD_TYPES.h"

#ifndef SCHED_SCHED_H_
#define SCHED_SCHED_H_



//creating a type of pointer to function for callback function
#define TICK_MS 500
typedef void (*RunnableCB_t) (void);

typedef enum
{

	Runnable_1,
	Runnable_2,
	_Max_RUNNABLE_NUM

}Max_Size;
/*User Struct*/
typedef struct
{
	char* name;
	uint32_t PeriodicityMs;
	uint32_t Priority;
	RunnableCB_t CallBack;
	uint32_t DelayMs;
}Runnable_t;





typedef enum
{
	Sched_NOK,
	Sched_OK
}Res_t;

// We register with pointer to the Task
void Sched_init(void);
void Sched_Start(void);


#endif /* SCHED_SCHED_H_ */
