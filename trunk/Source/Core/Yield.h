#ifndef __YIELD_H__
#define __YIELD_H__

#define YIELD_BEGIN { static int _y_times = 0; int _y_state=0; if (_y_times == _y_state++) {
#define YIELD _y_times++; return; } else if (_y_times == _y_state++) { 
#define YIELD_RET(x) _y_times++; return x; } else if (_y_times == _y_state++) { 
#define YIELD_END } else {}  _y_times = 0; }

#endif // __YIELD_H__