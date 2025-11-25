# Creating Endless-Mobile Debug Build

#### Initial Setup

1. Run the *download_build_dependencies.sh* script to download and unpack the SDL2, turbojpeg, and png dependencies.
2. Set the ANDROID_SDK_ROOT environment variable.

#### Linux

3. Run `gradlew buildDebug` from the android directory
4. Run `gradlew build` from the android directory.

#### Windows

3. Run the *convert_linux_links_to_windows_links.ps1* to change the project's symbolic links from to a Windows format 
4. Run `gradlew.bat buildDebug` from the android directory
5. Run `gradlew.bat build` from the android directory.

#### Notes
- If gradle notifies you that you are missing the required ndk version, then install it via the sdk manager, and try again. 
- Debug apk location
  - Linux: _endless-mobile/android/app/build/outputs/apk/debug/app-debug.apk_
  - Windows: _endless-mobile\android\app\build\outputs\apk\debug\app-debug.apk_
- Builds can be installed directly to an attached Android device or emulator
    - To install, run `gradlew installDebug` or `gradlew.bat installDebug`
    - To uninstall, run `gradlew uninstallDebug` or `gradlew.bat uninstallDebug`
