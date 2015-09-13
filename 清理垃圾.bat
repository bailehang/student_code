@echo off 
echo 将要结束进程 
pause 
:sta 
taskkill /im stormliv.exe 
taskkill /im alg.exe 
taskkill /im ati2evxx.exe 
taskkill /f /im wmiprvse.exe 
taskkill /f /im wmiprvse.exe 
taskkill /im ati2evxx.exe 
pause 
cls 
set /p a=是否结束3Dmas服务(1为是，其他为跳过) 
if /i %a%==1 goto dmk 
if /i not %a%==1 goto ati 
:dmk 
taskkill /im raysat_3dsmax9_32server.e 
taskkill /im AdskScSrv.exe 
goto ati 
:ati 
set /p b=是否结束ATI显卡配置中心(1为是，其他为跳过) 
if /i %b%==1 goto ak 
if /i not %b%==1 goto ra 
:ak 
taskkill /im CLI.exe 
taskkill /im CLI.exe 
goto ra 
:ra 
set /p c=是否重新运行一次(1为是，7为添加到开机自动运行注册表，0为结束) 
if /i %c%==1 goto sta 
if /i %c%==7 goto reg 
if /i %c%==0 goto esc 
:reg 
copy *.bat D:\结束进程.bat 
reg add HKEY_CURRENT_USER\Software\Microsoft\Windows\Run /v 结束进程 /d D:\结束进程.bat 
goto esc 
:esc
