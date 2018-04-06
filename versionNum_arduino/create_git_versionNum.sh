#!/bin/bash
#do chmod 755 git_version.sh before this script can be run

echo "----list directory content----"
ls


if [[ `git status` ]]; then
echo "----found git----"
else

echo "let's try different base directory"
#when running via SourceTree custom "actions option" we do not need to cd to proper directory
BASEDIR=$(dirname "$0")
echo "$BASEDIR"
cd /$BASEDIR
ls

if [[ `git status` ]]; then
echo "----2nd found git----"
else
echo "no git Repository exits here."
echo "maybe use this code to generate a version number based on date+time."
echo "https://github.com/jjssoftware/autoVersioning"
exit
fi

fi

commit=$(git rev-parse --short HEAD);
echo $commit

versionCount=$(git rev-list HEAD --count);
echo $versionCount

versionDate=$(git log -1 --date=short --pretty=format:%cd);
echo $versionDate
versionDate_mod=$(echo "$versionDate" | tr -d '-')

echo $versionDate_mod

commitVersion=$versionCount
commitVersion+=" "
commitVersion+=$versionDate_mod
commitVersion+=" "
commitVersion+=$commit
echo $commitVersion

> build_version.h
cat <<EOT >> build_version.h
#ifndef BUILD_VERSION_H
#define BUILD_VERSION_H
#include <stdio.h>
#define VERSIONNUM "$commitVersion"
#endif // BUILD_VERSION_H
EOT
