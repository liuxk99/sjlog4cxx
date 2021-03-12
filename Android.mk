# Copyright 2005 The Android Open Source Project
#
# Android.mk for adb
#
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CFLAGS := \
	-O2 \
	-g \
	-Wall \
	-Wno-unused-parameter \
	-Werror

LOCAL_MODULE := hello
LOCAL_MODULE_TAGS := optional

LOCAL_FORCE_STATIC_EXECUTABLE := true

LOCAL_SRC_FILES := \
	hello.c

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_CFLAGS := \
    -O2 \
    -g \
    -Wall \
    -Wno-unused-parameter \
    -Werror

LOCAL_MODULE := sjlog
LOCAL_MODULE_TAGS := optional

LOCAL_FORCE_STATIC_EXECUTABLE := true

LOCAL_SRC_FILES := \
    sjlog.cpp

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_CFLAGS := \
    -O2 \
    -g \
    -Wall \
    -Wno-unused-parameter \
    -Werror

LOCAL_MODULE := sjlog4a
LOCAL_MODULE_TAGS := optional

LOCAL_FORCE_STATIC_EXECUTABLE := true

LOCAL_STATIC_LIBRARIES := libasync_safe

LOCAL_SRC_FILES := \
    android/logcat_dumper.cpp \
    android/loggable.cpp \
    android/sjlog4a.cpp

include $(BUILD_EXECUTABLE)
