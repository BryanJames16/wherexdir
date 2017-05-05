# wherexdir
Cross-Platform Executable Directory Search

A single-header file used for searching executable directory. Currently, the project is on its initial phase.

--------------------------------------------------------------------------------

## Usage
If you are a Linux user, you may want to run `sudo` command, or else you might want to use `argv[0]` <br>
-- char * GetCurrentWorkingPath(char * path); // Gets the working directory where the application is called <br>
-- char * GetExecutableDirectory(char * path); // Gets the directory where the executable is stored <br>
-- char * GetExecutableName(char * exec_name); // Gets the executable name <br>

## Contributing [![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)]
Contributions are indeed greatly appreciated and needed. Currently, I have no access to MAC Systems, Solaris, and BSD-like system. It's hard shooting the errors in the dark and in need of contributions.
