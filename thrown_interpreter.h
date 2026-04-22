#ifndef	_COMMON_EXCEPTIONS_H_
#define	_COMMON_EXCEPTIONS_H_

/*
 * The following routines will instantiate a member of a specific
 * subclass of Exception, and fill in the stack backtrace
 * information from the current thread's ExecEnv stack .
 */
extern void OutOfMemoryError(void);

#endif	/* !_COMMON_EXCEPTIONS_H_ */
