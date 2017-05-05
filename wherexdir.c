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

#include "wherexdir.h"

#ifdef __cplusplus
extern "C" {
#endif

char * 
GetCurrentWorkingPath(char * path)
{
	#if defined (_WIN32) || defined (_WIN64)
		char working_path[PATH_MAX] = {"\0"};
		_getcwd(working_path, PATH_MAX);
		strcpy(path, working_path);
		__ChangeToForward(path);
	#elif __APPLE__
		char working_path[PATH_MAX] = {"\0"};
		getcwd(working_path, PATH_MAX);
		strcpy(path, working_path);
		__ChangeToForward(path);
	#elif defined(__linux__) || defined (__unix__)
		char working_path[PATH_MAX] = {"\0"};
		getcwd(working_path, PATH_MAX);
		strcpy(path, working_path);
		__ChangeToForward(path);
	#elif defined(__FreeBSD__) || definded(__DragonFly__)
		char working_path[PATH_MAX] = {"\0"};
		getcwd(working_path, PATH_MAX);
		strcpy(path, working_path);
		__ChangeToForward(path);
	#elif defined(__NetBSD__)
		char working_path[PATH_MAX] = {"\0"};
		getcwd(working_path, PATH_MAX);
		strcpy(path, working_path);
		__ChangeToForward(path);
	#endif
	
	return (path);
}

wchar_t * 
WGetCurrentWorkingPath(wchar_t * path)
{
	#if defined (_WIN32) || defined (_WIN64)
		wchar_t working_path[PATH_MAX] = {L"\0"};
		_wgetcwd(working_path, PATH_MAX);
		wcscpy(path, working_path);
		__WChangeToForward(path);
	#elif __APPLE__
		char working_path[PATH_MAX] = {L"\0"};
		getcwd(working_path, PATH_MAX);
		wcscpy(path, working_path);
		__WChangeToForward(path);
	#elif defined(__linux__) || defined (__unix__)
		char working_path[PATH_MAX] = {"\0"};
		getcwd(working_path, PATH_MAX);
		wcscpy(path, working_path);
		__WChangeToForward(path);
	#elif defined(__FreeBSD__) || definded(__DragonFly__)
		char working_path[PATH_MAX] = {"\0"};
		getcwd(working_path, PATH_MAX);
		wcscpy(path, working_path);
		__WChangeToForward(path);
	#elif defined(__NetBSD__)
		char working_path[PATH_MAX] = {"\0"};
		getcwd(working_path, PATH_MAX);
		wcscpy(path, working_path);
		__WChangeToForward(path);
	#endif
	
	return (path);
}

char * 
GetExecutableDirectory(char * path)
{
	#if defined (_WIN32) || defined (_WIN64)
		GetModuleFileName(NULL, path, PATH_MAX);
		__ChangeToForward(path);
		__SpliceString(path, 1);
	#elif __APPLE__
		char trace[PATH_MAX] = {"\0"};
		_NSGetExecutablePath(trace, PATH_MAX);
		stpcpy(path, trace);
		__SpliceString(path, 1);
	#elif defined(__FreeBSD__) || (__DragonFly__)
		char trace[PATH_MAX] = {"\0"};
		readlink("/proc/curproc/file", trace, PATH_MAX);
		stpcpy(path, trace);
		__SpliceString(path, 1);
	#elif defined(__NetBSD__)
		char trace[PATH_MAX] = {"\0"};
		readlink("/proc/curproc/exe", trace, PATH_MAX);
		stpcpy(path, trace);
		__SpliceString(path, 1);
	#elif defined(__linux__) || defined (__unix__)
		char trace[PATH_MAX] = {"\0"};
		readlink("/proc/self/exe", trace, PATH_MAX);
		stpcpy(path, trace);
		__SpliceString(path, 1);
	#elif defined(__sun)
		path = getexecname();
		__ChangeToForward(path);
		__SpliceString(path, 1);
	#endif
	
	return (path);
}

wchar_t * 
WGetExecutableDirectory(wchar_t * path)
{
	#if defined (_WIN32) || defined (_WIN64)
		GetModuleFileNameW(NULL, path, PATH_MAX);
		__WChangeToForward(path);
		__WSpliceString(path, 1);
	#elif __APPLE__
		wchar_t trace[PATH_MAX] = {"\0"};
		readlink("/proc/self/exe", trace, PATH_MAX);
		wcscpy(path, trace);
		__WSpliceString(path, 1);
	#elif defined(__FreeBSD__) || (__DragonFly__)
		wchar_t trace[PATH_MAX] = {L"\0"};
		readlink("/proc/curproc/file", trace, PATH_MAX);
		wcscpy(path, trace);
		__WSpliceString(path, 1);
	#elif defined(__NetBSD__)
		wchar_t trace[PATH_MAX] = {"\0"};
		readlink("/proc/curproc/exe", trace, PATH_MAX);
		wcscpy(path, trace);
		__WSpliceString(path, 1);
	#elif defined(__linux__) || defined (__unix__)
		wchar_t trace[PATH_MAX] = {"\0"};
		readlink("/proc/self/exe", trace, PATH_MAX);
		wcscpy(path, trace);
		__WSpliceString(path, 1);
	#elif defined(__sun)
		path = getexecname();
		__WChangeToForward(path);
		__WSpliceString(path, 1);
	#endif
	
	return (path);
}

char * 
GetExecutableName(char * exec_name)
{
	#if defined (_WIN32) || defined (_WIN64)
		GetModuleFileName(NULL, exec_name, PATH_MAX);
		__ChangeToForward(exec_name);
		__SpliceString(exec_name, 2);
	#elif __APPLE__
		char trace[PATH_MAX] = {"\0"};
		_NSGetExecutablePath(trace, PATH_MAX);
		stpcpy(path, trace);
		__SpliceString(path, 2);
	#elif defined(__FreeBSD__) || (__DragonFly__)
		char trace[PATH_MAX] = {"\0"};
		// wcs_readlink
		readlink("/proc/curproc/file", trace, PATH_MAX);
		stpcpy(path, trace);
		__SpliceString(path, 2);
	#elif defined(__NetBSD__)
		char trace[PATH_MAX] = {"\0"};
		readlink("/proc/curproc/exe", trace, PATH_MAX);
		stpcpy(path, trace);
		__SpliceString(path, 2);
	#elif defined(__linux__) || defined (__unix__)
		char trace[PATH_MAX] = {"\0"};
		readlink("/proc/self/exe", trace, PATH_MAX);
		stpcpy(path, trace);
		__SpliceString(path, 2);
	#elif defined(__sun)
		exec_name = getexecname();
		__ChangeToForward(exec_name);
		__SpliceString(exec_name, 2);
	#endif
	
	return (exec_name);
}

wchar_t * 
WGetExecutableName(wchar_t * exec_name)
{
	#if defined (_WIN32) || defined (_WIN64)
		GetModuleFileNameW(NULL, exec_name, PATH_MAX);
		__WChangeToForward(exec_name);
		__WSpliceString(exec_name, 2);
	#elif __APPLE__
		wchar_t trace[PATH_MAX] = {L"\0"};
		readlink("/proc/self/exe", trace, PATH_MAX);
		wcscpy(path, trace);
		__WSpliceString(path, 2);
	#elif defined(__FreeBSD__) || (__DragonFly__)
		wchar_t trace[PATH_MAX] = {L"\0"};
		// wcs_readlink
		readlink("/proc/curproc/file", trace, PATH_MAX);
		wcscpy(path, trace);
		__WSpliceString(path, 2);
	#elif defined(__NetBSD__)
		wchar_t trace[PATH_MAX] = {L"\0"};
		readlink("/proc/curproc/exe", trace, PATH_MAX);
		wcscpy(path, trace);
		__WSpliceString(path, 2);
	#elif defined(__linux__) || defined (__unix__)
		wchar_t trace[PATH_MAX] = {L"\0"};
		readlink("/proc/self/exe", trace, PATH_MAX);
		wcscpy(path, trace);
		__WSpliceString(path, 2);
	#elif defined(__sun)
		exec_name = getexecname();
		__WChangeToForward(exec_name);
		__WSpliceString(exec_name, 2);
	#endif
	
	return (exec_name);
}

char * 
__ChangeToForward(char * path)
{
	unsigned int count 			= 	0;
	unsigned int length 		= 	0;
	char translate[PATH_MAX] 	= 	{"\0"};
	
	strcpy (translate, path);
	length = strlen(translate);
	
	if (length > 0) {
		for (count = 0; count < length; count++) {
			if (translate[count] == '\\') {
				translate[count] = '/';
			}
		}
		
		strcpy (path, translate);
	}
	else {
		strcpy (path, "\0");
	}
	
	return (path);
}

wchar_t * 
__WChangeToForward(wchar_t * path)
{
	unsigned int count 			= 	0;
	unsigned int length 		= 	0;
	wchar_t translate[PATH_MAX] = 	{L"\0"};
	
	wcscpy (translate, path);
	length = wcslen(translate);
	
	if (length > 0) {
		for (count = 0; count < length; count++) {
			if (translate[count] == L'\\') {
				translate[count] = L'/';
			}
		}
		
		wcscpy (path, translate);
	}
	else {
		wcscpy (path, L"\0");
	}
	
	return (path);
}

char * 
__SpliceString(char * string, unsigned short int part)
{
	unsigned int occurence 			= 	0;
	unsigned int count 				= 	0;
	unsigned int length 			= 	0;
	char spliceString[PATH_MAX] 	= 	{"\0"};
	
	strcpy(spliceString, string);
	length = strlen(spliceString);
	if (length > 0) {
		for (count = 0; count < length; count++) {
			if (spliceString[count] == '/') {
				occurence = count;
			}
		}
		
		if (part == 1) {
			spliceString[occurence + 1] = '\0';
		}
		else {
			strncpy(spliceString, spliceString + occurence, length);
		}
		
		strcpy(string, spliceString);
	}
	else {
		strcpy(string, "\0");
	}
	
	return (string);
}

wchar_t * 
__WSpliceString(wchar_t * string, unsigned short int part)
{
	unsigned int occurence 			= 	0;
	unsigned int count 				= 	0;
	unsigned int length 			= 	0;
	wchar_t spliceString[PATH_MAX] 	= 	{L"\0"};
	
	wcscpy(spliceString, string);
	length = wcslen(spliceString);
	if (length > 0) {
		for (count = 0; count < length; count++) {
			if (spliceString[count] == L'/') {
				occurence = count;
			}
		}
		
		if (part == 1) {
			spliceString[occurence + 1] = L'\0';
		}
		else {
			wcsncpy(spliceString, spliceString + occurence, length);
		}
		
		wcscpy(string, spliceString);
	}
	else {
		wcscpy(string, L"\0");
	}
	
	return (string);
}

#ifdef __cplusplus
}
#endif
