# automated version numbering

Here are two examples on how i create version numbers based on the last git commit.
The result will look something like:
```
2 20180405 7e59c63
```
count  - date - commit hash

## openframeworks
The openframeworks example check the last git commit in it's folder. If no git repository is present it uses the last stored version number in the gui_main.xml file.

## arduino
The arduino example has a create_git_versionNum.sh shell script. The shell script can be placed in the sketch's folder and then be run from the terminal.

Personally i use sourceTree to manage my git repos. There are two options to run this script
1. I place the create_git_versionNum.sh script in a general location, and create a "cutsom action" with sourceTree. You then have to manaully run this script via Actions->Custom Actions-> select your script
2. Use this [post-commit script](https://github.com/antimodular/version-numbers/blob/master/versionNum_arduino/git/hooks/post-commit). It need to have this path myRepo/.git/hooks/post-commit


The script writes the version number in to build_version.h, which get's called from the arduino sketch.

![](https://github.com/antimodular/version-numbers/blob/master/images/hook.png)
