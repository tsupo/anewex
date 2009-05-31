echo off

REM batch file for distribution of ANEWEX
REM $Header: /comm/anewex/dist.bat 1     09/05/14 3:29 tsupo $

chmod -R +w dist

rm -Rf dist\src

mkdir dist\src
mkdir dist\src\anewex
mkdir dist\src\anewex\res
mkdir dist\src\include
mkdir dist\src\lib

REM copy *.c dist\src\anewex
copy *.h dist\src\anewex
copy *.cpp dist\src\anewex
copy anewex.rc dist\src\anewex
copy res\*.ico dist\src\anewex\res
copy res\*.rc2 dist\src\anewex\res
copy res\*.bmp dist\src\anewex\res
copy res\*.cur dist\src\anewex\res
copy anewex.exe.manifest dist
copy readme.txt          dist
copy Release\anewex.exe  dist
copy Release\xmlRPC.dll  dist

copy ..\xmlRPC\xmlRPC.h           dist\src\include
copy ..\xmlRPC\Release\xmlRPC.lib dist\src\lib
