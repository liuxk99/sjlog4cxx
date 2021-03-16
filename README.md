# hello-executable
This project is a template Native Executable project for AOSP. You can use this template to create your own executable project in the source code environment, such as in external/xxx.

# local manifest
.repo/local_manifest/xxx.xml
```code:java
<?xml version="1.0" encoding="UTF-8"?>
<manifest>
    <remote fetch="github:/" name="github" />
    <project remote="github" path="external/xxx" name="liuxk99/hello-executable.git" revision="master" />
</manifest>
```
You should modify the remote node by your own ssh config(~/.ssh/config).
After repo sync, you can get repository in external/xxx.
The tree of project like this:
```
external$ tree xxx/
xxx/
├── Android.mk
└── hello.c

0 directories, 2 files
```

# Test-Run
```
$ adb shell hello Android!
argv[0]: hello
argv[1]: Android!
Hello, Android!
```

# Platforms
I have tested the build and run for this executable on AmlT920L AmlT972. The details as below.
## AmlT920L
andorid 5.1.1 API-Level 22
## AmlT972
andorid 9 API-Level 28
