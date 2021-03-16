# Copyright 2005 The Android Open Source Project
#
# Android.mk for adb
#

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	hello.c

LOCAL_CFLAGS := \
	-O2 \
	-g \
	-Wall \
	-Wno-unused-parameter

LOCAL_SHARED_LIBRARIES := \
	libc

LOCAL_MODULE := hello

include $(BUILD_EXECUTABLE)
