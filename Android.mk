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

# >>>
# http://wiki.letv.cn/display/TVEUIDEV/13_API-Levels
# AmlT972(28)
ifeq (1,$(strip $(shell expr $(PLATFORM_SDK_VERSION) \>\= 27)))
	include $(call all-makefiles-under,$(LOCAL_PATH))
endif
# <<<
