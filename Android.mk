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
