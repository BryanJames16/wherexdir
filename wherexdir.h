#ifndef __WHEREXDIR_H
#define __WHEREXDIR_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 	Standard Libraries
 */
#include <limits.h>
#include <stdio.h>
#include <string.h>


/**
 *  Non-Standard Libraries 
 */
#if defined (_WIN32) || defined (_WIN64)
	#include <windows.h>
#elif defined(__APPLE__)
	#include <mach-o/dyld.h>
#elif defined(__linux__) || defined(__unix__)
	#include <unistd.h>
#elif defined(__sun)
	#include <stdlib.h>
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

char * GetExecutableDirectory(char * path);

char * GetExecutableName();

//////////////////////////////////////////////
/**
 *  Library Supporting Functions
 */
//////////////////////////////////////////////
char * __ChangeToForward(char * path);

char * __SpliceString(char * string, unsigned short int part);

#ifdef __cplusplus
}
#endif

#endif /* __WHEREXDIR_H */