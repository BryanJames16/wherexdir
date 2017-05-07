/**
 *  Unlicense
 *  This is free and unencumbered software released into the public domain.
 *  
 *  Anyone is free to copy, modify, publish, use, compile, sell, or
 *  distribute this software, either in source code form or as a compiled
 *  binary, for any purpose, commercial or non-commercial, and by any
 *  means.
 * 
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 * For more information, please refer to <http://unlicense.org>
 */

#ifndef __WHEREXDIR_H
#define __WHEREXDIR_H 1

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 	Standard Libraries
 */
#include <limits.h>		// <-- PATH_MAX Definition
#include <string.h>		// <-- String Handling
#include <wchar.h>		// <-- Wide Character Support

/**
 *  Non-Standard Libraries 
 */
#if defined (_WIN32) || defined (_WIN64)
	#include <windows.h> 		// <-- Functions: GetModuleFileName(), GetModuleFileNameW()
	#include <direct.h>			// <-- Functions: _getcwd(), _wgetcwd()
#elif defined(__APPLE__)
	#include <mach-o/dyld.h> 	// <-- Function: _NSGetExecutablePath() 
	#include <unistd.h>			// <-- Function: readlink()
#elif defined(__linux__) || defined(__unix__)
	#include <unistd.h> 		// <-- Function: readlink()
#elif defined(__sun)
	#include <stdlib.h> 		// <-- Function: getexecname()
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
/**
 *  Change all backward slash to forward slash
 */
char * __ChangeToForward(char * path);

/**
 *  Change all backward slash to forward slash
 *  (Wide Character Support)
 */
wchar_t * __WChangeToForward(wchar_t * path);

/**
 *  Split the directory from the executable name
 */
char * __SpliceString(char * string, unsigned short int part);

/**
 *  Split the directory from the executable name
 *  (Wide Character Support)
 */
wchar_t * __WSpliceString(wchar_t * string, unsigned short int part);

#ifdef __cplusplus
}
#endif

#endif /* __WHEREXDIR_H */
