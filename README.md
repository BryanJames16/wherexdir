# wherexdir
Cross-Platform Executable Directory Search

A small header file used for searching executable directory. This library aims to lessen hardship in getting the excecutable path in different platforms. Currently, the project is on its initial phase.

--------------------------------------------------------------------------------

## Usage
If you are a Linux user, you may want to run `sudo` command, or else you might want to use `argv[0]` <br>
- `char * GetCurrentWorkingPath(char * path);`  Gets the working directory where the application is called 
- `char * GetExecutableDirectory(char * path);` Gets the directory where the executable is stored 
- `char * GetExecutableName(char * exec_name);` Gets the executable name 
- `wchar_t * WGetCurrentWorkingPath(wchar_t * path);`  Gets the working directory where the application is called (Wide Character Support)
- `wchar_t * WGetExecutableDirectory(wchar_t * path);` Gets the directory where the executable is stored (Wide Character Support)
- `wchar_t * WGetExecutableName(wchar_t * exec_name);` Gets the executable name (Wide Character Support)

Example:

	char path[PATH_MAX];
	
	GetCurrentWorkingPath(path);
	printf ("Calling Directory: %s\n", path);
	GetExecutableDirectory(path);
	printf ("Executable Directory: %s\n", path);
	GetExecutableName(path);
	printf ("Name: %s\n", path);

Outputs:

	Calling Directory: C:/Development/Sandbox
	Executable Directory: C:/Development
	Name: sample.exe

## Issues
Project is in initial stage. There are no support for MAC Systems, Solaris, BSD-like systems, and some of linux based systems. Each of these files are needed to be tested on different environment and platforms.

## Target Platforms
- Windows
- Linux
- FreeBSD & DragonFly
- Solaris
- NetBSD
- OpenBSD
- Android
- Mac

--------------------------------------------------------------------------------

## Contributing [![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](https://github.com/BryanJames16/wherexdir/issues)
Contributions are indeed greatly appreciated and needed. Currently, I have no access to Mac Systems, Solaris, and BSD-like system. It's hard shooting the errors in the dark and the project is in need of contributions.

## License  ![Public Domain](https://licensebuttons.net/p/zero/1.0/88x31.png)
Released in Public Domain
