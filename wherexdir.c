#include "wherexdir.h"

#ifdef __cplusplus
extern "C" {
#endif

char * 
GetCurrentWorkingPath(char * path)
{
	#if defined (_WIN32) || defined (_WIN64)
		
	#elif __APPLE__
		
	#elif __linux__
		
	#elif __unix__
		
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
		
	#elif defined(__FreeBSD__) || (__DragonFly__)
		char trace[PATH_MAX] = {"\0"};
		readlink("/proc/curproc/file", trace, PATH_MAX);
		stpcpy(path, trace);
	#elif defined(__NetBSD__)
		char trace[PATH_MAX] = {"\0"};
		readlink("/proc/curproc/exe", trace, PATH_MAX);
		stpcpy(path, trace);
	#elif defined(__linux__) || defined (__unix__)
		char trace[PATH_MAX] = {"\0"};
		readlink("/proc/self/exe", trace, PATH_MAX);
		stpcpy(path, trace);
	#elif defined(__sun)
		path = getexecname();
		__ChangeToForward(path);
		__SpliceString(path, 1);
	#endif
	
	return (path);
}

char * 
GetExecutableName(char * exec_name)
{
	#if defined (_WIN32) || defined (_WIN64)
		GetModuleFileName(NULL, exec_name, PATH_MAX);
		__ChangeToForward(path);
		__SpliceString(path, 2);
	#elif __APPLE__
		
	#elif defined(__linux__) || defined (__unix__)
		
	#elif defined(__sun)
		path = getexecname();
		__ChangeToForward(path);
		__SpliceString(path, 2);
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

char * 
__SpliceString(char * string, unsigned short int part)
{
	unsigned int occurence 			= 	0;
	unsigned int count 				= 	0;
	unsigned int length 			= 	0;
	char spliceString[PATH_MAX] 	= 	{"\0"};
	//char newString[PATH_MAX]		= 	{"\0"};
	
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
			occurence++;
			strncpy(spliceString, spliceString + occurence, length);
		}
		
		strcpy(string, spliceString);
	}
	else {
		strcpy(string, "\0");
	}
	
	return (string);
}

#ifdef __cplusplus
}
#endif