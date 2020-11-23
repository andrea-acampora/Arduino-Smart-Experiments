#ifndef __GLOBALS__
#define __GLOBALS__

extern int frequency;
enum State { READY, SLEEPING, ABORTED, IN_EXECUTION, TERMINATED} ;
extern State state;
extern int timer;

#endif
