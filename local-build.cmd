REM run as Administrator
@echo off
cd /d %~dp0
set DOWNLOAD_DIR=%USERPROFILE%\Downloads
set DOWNLOAD_DIR_LINUX=%DOWNLOAD_DIR:\=/%
SET PATH=%DOWNLOAD_DIR%\PortableGit\bin;%DOWNLOAD_DIR%\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64;%DOWNLOAD_DIR%\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin;%DOWNLOAD_DIR%\cmake-3.22.2-windows-x86_64\bin;%PATH%

cmake.exe -G"MinGW Makefiles" -DTGUI_ROOT="%DOWNLOAD_DIR_LINUX%/TGUI-0.9.3-mingw-7.3.0-64bit-for-SFML-2.5.1/TGUI-0.9/lib/cmake/TGUI" -DSFML_ROOT="%DOWNLOAD_DIR_LINUX%/sfml-v2.5.1-mingw/SFML/build/sfml/lib/cmake/SFML" -B./build
cd build

:rebuild_and_startapp
mingw32-make.exe
pause
REM GOTO rebuild_and_startapp