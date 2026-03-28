#ifndef __EPT_CFG
#define __EPT_CFG

#define PROFILER         //Uncomment this if profiler needed
#define LOW_POWER_MODE

#ifdef LOW_POWER_MODE
extern volatile uint8_t tc_flag;
#define EPT_TICK() { ept_timer_tick(); tc_flag = 1; }
#else
#define EPT_TICK() ept_timer_tick();
#endif //#ifdef LOW_POWER_MODE

#endif //#ifndef __EPT_CFG

#ifdef EPT_SCHEDULER_IMPLEMENTATION

#ifndef __EPT_SCHEDULER_IMPLEMENTATION__
#define __EPT_SCHEDULER_IMPLEMENTATION__
//threadlist array must be filled manually by the user 
//All the top level threads must be placed in this array
#include "blinker.h"

extern blinker_ctx blctx1, blctx2; //Conetxts for threads.

const static thread_record threadlist[] = 
{
  {.name = "bl1", .thread = blinker,  .context = &blctx1, .init_state = RUN, .init_dbg_level = OFF}, 
  {.name = "bl2", .thread = blinker,  .context = &blctx2, .init_state = RUN, .init_dbg_level = OFF}
};

#endif
#endif