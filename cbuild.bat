@echo off
setlocal

:: ------------------------------------------ settings

set project_name=AtomSampleViewer
set install_dir="D:\AtomSampleViewer"
set ENGINE_PATH="C:\O3DE\25.10"
set GEMROOT="C:\Users\Administrator\O3DE\Gems\"
:: -----------------------------------------
set build_dir="build\windows"
set build_mono_dir="build\windows_mono"
set ThirdParty_path="%USERPROFILE%\.o3de\3rdParty"
set TOOL_PATH="%ENGINE_PATH%\bin\Windows\profile\Default"
set AssetProcessorBatch="%TOOL_PATH%\AssetProcessorBatch.exe"
:: ------------------------------------------ update gems

@REM call :update_gem APICaller
@REM call :update_gem CloudRender
@REM call :update_gem EntityManager
@REM call :update_gem GlobalBus
@REM call :update_gem ViewControl

:: ------------------------------------------ build steps

xcopy %ThirdParty_path%\_deps %build_dir%\_deps /E /I /Y
cmake -B %build_dir% ^
    -DFETCHCONTENT_FULLY_DISCONNECTED=ON ^
    -DLY_DISABLE_TEST_MODULES=ON ^
    -DLY_MONOLITHIC_GAME=OFF ^
    -DLY_UNITY_BUILD=OFF ^
    -DLY_3RDPARTY_PATH=%ThirdParty_path% ^
    --fresh || goto :fail
exit
:: ------------------------------------------ build project and assets

:: rmdir /S /Q Cache
cmake --build %build_dir% --config profile --target %project_name%.Assets -- -m || goto :fail

cmake -B %build_mono_dir% ^
    -DLY_DISABLE_TEST_MODULES=ON ^
    -DLY_MONOLITHIC_GAME=ON ^
    -DLY_UNITY_BUILD=OFF ^
    -DCMAKE_INSTALL_PREFIX=%install_dir% ^
    -DLY_3RDPARTY_PATH=%ThirdParty_path% ^
    --fresh || goto :fail

:: fix existing dir error
mkdir %build_mono_dir%/bin/release

cmake --build %build_mono_dir% --config release || goto :fail

cmake --install %build_mono_dir% --config release || goto :fail

echo.
echo ======================================
echo Build success!
echo ======================================
exit /b 0
:: ----------------------------------------------------------------------------------


:: steps to build O3DE project with mono build
cmake -B build\windows -DLY_UNITY_BUILD=OFF -DLY_DISABLE_TEST_MODULES=ON -DFETCHCONTENT_FULLY_DISCONNECTED=ON --fresh
cmake --build build\windows --config profile
cmake --build build\windows --config profile --target DreamEngine.Assets -- -m
cmake -B build\windows_mono -DLY_MONOLITHIC_GAME=ON --fresh
cmake --build build\windows_mono --config release
cmake --install build\windows_mono --config release

C:\O3DE\25.10\bin\Windows\profile\Default\AssetProcessorBatch.exe --project-path .
C:\O3DE\25.10\bin\Windows\profile\Default\AssetBundler.exe -project-path .


:update_gem
echo update %1 ...
pushd "%GEMROOT%\%1" || goto :fail
git pull || goto :fail
popd
exit /b 0


:fail
echo.
echo ======================================
echo Build FAILED.
echo ======================================
exit /b 1
