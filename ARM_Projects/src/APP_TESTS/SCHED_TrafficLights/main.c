/*
 * main.c
 *
 *  Created on: Mar 17, 2024
 *      Author: NoteBook
 */

#include "SCHED/Sched.h"
#include "APP_1.h"
int main(void)
{
	TrafficLights_init();
	Sched_init();
	Sched_Start();
	return 0;
}


