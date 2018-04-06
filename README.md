# automated version numbering

Here are two examples on how i create version numbers based on the last git commit.
The result will look something like:
```
2 20180405 7e59c63
```
count  - date - commit hash

The openframeworks example check the last git commit in it's folder. If no git repository is present it uses the last stored version number in the gui_main.xml file.

The arduino example has a create_git_versionNum.sh shell script. The shell script can either be placed in the sketch's folder and then be run from the terminal.
Personally i use sourceTree to manage my git repos. I place the create_git_versionNum.sh script in a general location, and create a "cutsom action" with sourceTree.
As of now i manually need to call this script but hope to find a way to have sourceTree call it after every commit.
The script writes in to build_version.h, which get's called from the arduino sketch.
