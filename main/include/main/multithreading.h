#ifndef MULTITHREADING_H
#define MULTITHREADING_H

#ifdef _WIN32
    #include <windows.h>
    #include <process.h>
	// Windows uses _beginthreadex and _endthreadex for thread management
	typedef HANDLE thread_t;
	typedef unsigned (__stdcall *thread_func_t)(void*);
	#define thread_create(thr, func, arg) ((*(thr) = (HANDLE)_beginthreadex(NULL, 0, (thread_func_t)(func), (arg), 0, NULL)) != 0)
	#define thread_join(thr) (WaitForSingleObject((thr), INFINITE) == WAIT_OBJECT_0 && CloseHandle((thr)))
	#define thread_exit(retval) _endthreadex((unsigned)(uintptr_t)(retval))
	// Windows uses SRW locks for read-write locking
	typedef SRWLOCK rwlock_t;
    #define rwlock_init(lock) InitializeSRWLock(lock)
    #define rwlock_read_lock(lock) AcquireSRWLockShared(lock)
    #define rwlock_read_unlock(lock) ReleaseSRWLockShared(lock)
    #define rwlock_write_lock(lock) AcquireSRWLockExclusive(lock)
    #define rwlock_write_unlock(lock) ReleaseSRWLockExclusive(lock)
	#define rwlock_destroy(lock) ((void)0)
	// Windows handles critical sections differently from soft Read-Write locks
	typedef CRITICAL_SECTION crit_t;
	#define crit_init(lock) InitializeCriticalSection(lock)
	#define crit_lock(lock) EnterCriticalSection(lock)
	#define crit_unlock(lock) LeaveCriticalSection(lock)
	#define crit_destroy(lock) DeleteCriticalSection(lock)
	// Windows uses condition variables only with critical sections
	typedef CONDITION_VARIABLE cond_t;
	#define cond_init(cond) InitializeConditionVariable(cond)
	#define cond_destroy(cond) ((void)0)
	#define cond_wait(cond, lock) SleepConditionVariableCS(cond, lock, INFINITE)
	#define cond_signal(cond) WakeConditionVariable(cond)
	#define cond_broadcast(cond) WakeAllConditionVariable(cond)
#elif __unix__ || __APPLE__
    #include <pthread.h>
	#include <stdlib.h>
	typedef pthread_t thread_t;
	typedef void* (*thread_func_t)(void*);
	#define thread_create(thr, func, arg) (pthread_create((thr), NULL, (thread_func_t)(func), (arg)) == 0)
	#define thread_join(thr) (pthread_join((thr), NULL) == 0)
	#define thread_exit(retval) pthread_exit(retval)
	typedef pthread_rwlock_t rwlock_t;
    #define rwlock_init(lock) pthread_rwlock_init(lock, NULL)
    #define rwlock_read_lock(lock) pthread_rwlock_rdlock(lock)
    #define rwlock_read_unlock(lock) pthread_rwlock_unlock(lock)
    #define rwlock_write_lock(lock) pthread_rwlock_wrlock(lock)
    #define rwlock_write_unlock(lock) pthread_rwlock_unlock(lock)
    #define rwlock_destroy(lock) pthread_rwlock_destroy(lock)
	typedef pthread_mutex_t crit_t;
	#define crit_init(lock) pthread_mutex_init(lock, NULL)
	#define crit_lock(lock) pthread_mutex_lock(lock)
	#define crit_unlock(lock) pthread_mutex_unlock(lock)
	#define crit_destroy(lock) pthread_mutex_destroy(lock)
	typedef pthread_cond_t cond_t;
	#define cond_init(cond) pthread_cond_init(cond, NULL)
	#define cond_destroy(cond) pthread_cond_destroy(cond)
	#define cond_wait(cond, lock) pthread_cond_wait(cond, lock)
	#define cond_signal(cond) pthread_cond_signal(cond)
	#define cond_broadcast(cond) pthread_cond_broadcast(cond)
#else	
#error "Multithread support is not implemented for this platform. Please post an issue on the GitHub repository if you are not using Windows, Apple, or Unix."
#endif

#endif // MULTITHREADING_H