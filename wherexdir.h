#ifndef __WHEREXDIR_H
#define __WHEREXDIR_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 	Standard Libraries
 */
#include <limits.h>
#include <string.h>
#include <wchar.h>

/**
 *  Non-Standard Libraries 
 */
#if defined (_WIN32) || defined (_WIN64)
	#include <windows.h>
	#include <direct.h>
#elif defined(__APPLE__)
	#include <mach-o/dyld.h>
	#include <unistd.h>
#elif defined(__linux__) || defined(__unix__)
	#include <unistd.h>
#elif defined(__sun)
	#include <stdlib.h>
#else 
	#include <unistd.h>
#endif


//////////////////////////////////////////////
/**
 *  Library Main Functions
 */
//////////////////////////////////////////////
 
/**
 *  Get the current working directory of the 
 *  calling location
 */
char * GetCurrentWorkingPath(char * path);

/**
 *  Get the current working directory of the 
 *  calling location (Wide Character Support)
 */
wchar_t * WGetCurrentWorkingPath(wchar_t * path);

/**
 *  Get the location where executable is stored
 */
char * GetExecutableDirectory(char * path);

/**
 *  Get the location where executable is stored
 *  (Wide Character Support)
 */
wchar_t * WGetExecutableDirectory(wchar_t * path);

/**
 *  Get the executable name 
 */
char * GetExecutableName(char * exec_name);

/**
 *  Get the executable name (Wide Character Support)
 */
wchar_t * WGetExecutableName(wchar_t * exec_name);

//////////////////////////////////////////////
/**
 *  Library Supporting Functions
 */
//////////////////////////////////////////////
char * __ChangeToForward(char * path);

wchar_t * __WChangeToForward(wchar_t * path);

char * __SpliceString(char * string, unsigned short int part);

wchar_t * __WSpliceString(wchar_t * string, unsigned short int part);

#ifdef __cplusplus
}
#endif

#endif /* __WHEREXDIR_H */
