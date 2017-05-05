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
	#elif defined(__FreeBSD__)
		char working_path[PATH_MAX] = {"\0"};
		getcwd(working_path, PATH_MAX);
		strcpy(path, working_path);
		__ChangeToForward(path);
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

char * 
GetExecutableName(char * exec_name)
{
	#if defined (_WIN32) || defined (_WIN64)
		GetModuleFileName(NULL, exec_name, PATH_MAX);
		__ChangeToForward(exec_name);
		__SpliceString(exec_name, 2);
	#elif __APPLE__
		
	#elif defined(__FreeBSD__) || (__DragonFly__)
		char trace[PATH_MAX] = {"\0"};
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