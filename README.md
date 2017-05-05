# wherexdir
Cross-Platform Executable Directory Search

A small header file used for searching executable directory. This library aims to lessen hardship in getting the excecutable path in different platforms. Currently, the project is on its initial phase.

--------------------------------------------------------------------------------

## Usage
If you are a Linux user, you may want to run `sudo` command, or else you might want to use `argv[0]` <br>
- `char * GetCurrentWorkingPath(char * path);`  Gets the working directory where the application is called 
- `char * GetExecutableDirectory(char * path);` Gets the directory where the executable is stored 
- `char * GetExecutableName(char * exec_name);` Gets the executable name 
- `wchar_t * WGetCurrentWorkingPath(char * path);`  Gets the working directory where the application is called (Wide Char)
- `wchar_t * WGetExecutableDirectory(char * path);` Gets the directory where the executable is stored (Wide Char)
- `wchar_t * WGetExecutableName(char * exec_name);` Gets the executable name (Wide Char)

## Issues
Project is in initial stage. There are no support for MAC Systems, Solaris, BSD-like systems, and some of linux based systems. Each of these files are needed to be tested on different environment and platforms.

## Currently Supported Platforms
- Windows
- Linux
- FreeBSD & DragonFly
- NetBSD
- OpenBSD
- Android

## Pending Platform(s)
- Mac

--------------------------------------------------------------------------------

## Contributing [![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](https://github.com/BryanJames16/wherexdir/issues)
Contributions are indeed greatly appreciated and needed. Currently, I have no access to MAC Systems, Solaris, and BSD-like system. It's hard shooting the errors in the dark and in need of contributions.

## Documentation [![Inline docs](http://inch-ci.org/github/BryanJames16/wherexdir.svg?branch=master&style=shields)](http://inch-ci.org/github/BryanJames16/wherexdir)
No documentations yet...
