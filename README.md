# hello-executable
This project is a Auto Log Utility for c++, which automatically generate logcat when entry and exit function. You can use this project to your own executable project in the source code environment, such as in external/xxx.

# local manifest
.repo/local_manifest/xxx.xml
```code:java
<?xml version="1.0" encoding="UTF-8"?>
<manifest>
    <remote fetch="github:/" name="github" />
    <project remote="github" path="external/xxx" name="liuxk99/sjlog4cxx.git" revision="master" />
</manifest>
```
You should modify the remote node by your own ssh config(~/.ssh/config).
After repo sync, you can get repository in external/xxx.
The tree of project like this:
```
$ tree
.
├── android
│   ├── Android.mk
│   ├── loggable4a.cpp
│   ├── sjdumper4a.cpp
│   ├── sjdumper4a.h
│   └── sjlog4a.cpp
├── Android.mk
├── dumper.h
├── hello.c
├── loggable.cpp
├── loggable.h
├── README.md
├── sjdumper.cpp
├── sjdumper.h
├── sjlog.cpp
└── sjlog.h

1 directory, 15 files
```

# sjlog
+ Test-Run
```
$ adb shell sjlog Android!
SjLog: => main
argv[0]: sjlog
argv[1]: Android!
Hello, Android!
SjLog: <- main
```

# sjlog4a
The minimal API-Level is 27
+ Test-Run
```
$ adb logcat -c; adb shell sjlog4a 'Android!'; sleep 1; adb logcat -v threadtime -d -s SjLog4A:V *:S
argv[0]: sjlog4a
argv[1]: Android!
Hello, Android!
--------- beginning of main
--------- beginning of system
03-16 17:37:37.762 14645 14645 I SjLog4A : => main
03-16 17:37:37.762 14645 14645 I SjLog4A : <- main
```

# Platforms
I have tested the build and run for this executable on AmlT920L AmlT972. The details as below.
## AmlT920L
andorid 5.1.1 API-Level 22
## AmlT972
andorid 9 API-Level 28
