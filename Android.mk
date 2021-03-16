# Copyright 2005 The Android Open Source Project
#
# Android.mk for adb
#

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	sjdumper.cpp \
	loggable.cpp \
	sjlog.cpp \

LOCAL_CFLAGS := \
	-O2 \
	-g \
	-Wall \
	-Wno-unused-parameter

LOCAL_SHARED_LIBRARIES := \
	libc

LOCAL_MODULE := sjlog

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	android/sjdumper4a.cpp \
	android/loggable4a.cpp \
	android/sjlog4a.cpp \

LOCAL_CFLAGS := \
	-O2 \
	-g \
	-Wall \
	-Wno-unused-parameter

LOCAL_SHARED_LIBRARIES := \
	libc

LOCAL_STATIC_LIBRARIES := libasync_safe

LOCAL_MODULE := sjlog4a

include $(BUILD_EXECUTABLE)
