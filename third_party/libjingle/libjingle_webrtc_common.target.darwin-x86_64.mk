# This file is generated by gyp; do not edit.

include $(CLEAR_VARS)

LOCAL_MODULE_CLASS := STATIC_LIBRARIES
LOCAL_MODULE := third_party_libjingle_libjingle_webrtc_common_gyp
LOCAL_MODULE_SUFFIX := .a
LOCAL_MODULE_TARGET_ARCH := $(TARGET_$(GYP_VAR_PREFIX)ARCH)
gyp_intermediate_dir := $(call local-intermediates-dir,,$(GYP_VAR_PREFIX))
gyp_shared_intermediate_dir := $(call intermediates-dir-for,GYP,shared,,,$(GYP_VAR_PREFIX))

# Make sure our deps are built first.
GYP_TARGET_DEPENDENCIES :=

GYP_GENERATED_OUTPUTS :=

# Make sure our deps and generated files are built first.
LOCAL_ADDITIONAL_DEPENDENCIES := $(GYP_TARGET_DEPENDENCIES) $(GYP_GENERATED_OUTPUTS)

LOCAL_CPP_EXTENSION := .cc
LOCAL_GENERATED_SOURCES :=

GYP_COPIED_SOURCE_ORIGIN_DIRS :=

LOCAL_SRC_FILES := \
	third_party/libjingle/source/talk/app/webrtc/audiotrack.cc \
	third_party/libjingle/source/talk/app/webrtc/audiotrackrenderer.cc \
	third_party/libjingle/source/talk/app/webrtc/datachannel.cc \
	third_party/libjingle/source/talk/app/webrtc/dtmfsender.cc \
	third_party/libjingle/source/talk/app/webrtc/jsepicecandidate.cc \
	third_party/libjingle/source/talk/app/webrtc/jsepsessiondescription.cc \
	third_party/libjingle/source/talk/app/webrtc/localaudiosource.cc \
	third_party/libjingle/source/talk/app/webrtc/mediaconstraintsinterface.cc \
	third_party/libjingle/source/talk/app/webrtc/mediastream.cc \
	third_party/libjingle/source/talk/app/webrtc/mediastreamhandler.cc \
	third_party/libjingle/source/talk/app/webrtc/mediastreamsignaling.cc \
	third_party/libjingle/source/talk/app/webrtc/peerconnection.cc \
	third_party/libjingle/source/talk/app/webrtc/peerconnectionfactory.cc \
	third_party/libjingle/source/talk/app/webrtc/portallocatorfactory.cc \
	third_party/libjingle/source/talk/app/webrtc/remoteaudiosource.cc \
	third_party/libjingle/source/talk/app/webrtc/remotevideocapturer.cc \
	third_party/libjingle/source/talk/app/webrtc/sctputils.cc \
	third_party/libjingle/source/talk/app/webrtc/statscollector.cc \
	third_party/libjingle/source/talk/app/webrtc/videosource.cc \
	third_party/libjingle/source/talk/app/webrtc/videotrack.cc \
	third_party/libjingle/source/talk/app/webrtc/videotrackrenderers.cc \
	third_party/libjingle/source/talk/app/webrtc/webrtcsdp.cc \
	third_party/libjingle/source/talk/app/webrtc/webrtcsession.cc \
	third_party/libjingle/source/talk/app/webrtc/webrtcsessiondescriptionfactory.cc \
	third_party/libjingle/source/talk/media/base/capturemanager.cc \
	third_party/libjingle/source/talk/media/base/capturerenderadapter.cc \
	third_party/libjingle/source/talk/media/base/codec.cc \
	third_party/libjingle/source/talk/media/base/constants.cc \
	third_party/libjingle/source/talk/media/base/filemediaengine.cc \
	third_party/libjingle/source/talk/media/base/mediaengine.cc \
	third_party/libjingle/source/talk/media/base/rtpdataengine.cc \
	third_party/libjingle/source/talk/media/base/rtpdump.cc \
	third_party/libjingle/source/talk/media/base/rtputils.cc \
	third_party/libjingle/source/talk/media/base/streamparams.cc \
	third_party/libjingle/source/talk/media/base/videoadapter.cc \
	third_party/libjingle/source/talk/media/base/videocapturer.cc \
	third_party/libjingle/source/talk/media/base/videocommon.cc \
	third_party/libjingle/source/talk/media/base/videoframe.cc \
	third_party/libjingle/source/talk/media/devices/dummydevicemanager.cc \
	third_party/libjingle/source/talk/media/devices/filevideocapturer.cc \
	third_party/libjingle/source/talk/media/webrtc/webrtcpassthroughrender.cc \
	third_party/libjingle/source/talk/media/webrtc/webrtctexturevideoframe.cc \
	third_party/libjingle/source/talk/media/webrtc/webrtcvideocapturer.cc \
	third_party/libjingle/source/talk/media/webrtc/webrtcvideoframe.cc \
	third_party/libjingle/source/talk/media/webrtc/webrtcvideoframefactory.cc \
	third_party/libjingle/source/talk/session/media/audiomonitor.cc \
	third_party/libjingle/source/talk/session/media/bundlefilter.cc \
	third_party/libjingle/source/talk/session/media/call.cc \
	third_party/libjingle/source/talk/session/media/channel.cc \
	third_party/libjingle/source/talk/session/media/channelmanager.cc \
	third_party/libjingle/source/talk/session/media/currentspeakermonitor.cc \
	third_party/libjingle/source/talk/session/media/externalhmac.cc \
	third_party/libjingle/source/talk/session/media/mediamessages.cc \
	third_party/libjingle/source/talk/session/media/mediamonitor.cc \
	third_party/libjingle/source/talk/session/media/mediasession.cc \
	third_party/libjingle/source/talk/session/media/mediasessionclient.cc \
	third_party/libjingle/source/talk/session/media/rtcpmuxfilter.cc \
	third_party/libjingle/source/talk/session/media/soundclip.cc \
	third_party/libjingle/source/talk/session/media/srtpfilter.cc \
	third_party/libjingle/source/talk/session/media/typingmonitor.cc \
	third_party/libjingle/source/talk/session/tunnel/pseudotcpchannel.cc \
	third_party/libjingle/source/talk/session/tunnel/tunnelsessionclient.cc \
	third_party/libjingle/source/talk/media/sctp/sctpdataengine.cc


# Flags passed to both C and C++ files.
MY_CFLAGS_Debug := \
	-fstack-protector \
	--param=ssp-buffer-size=4 \
	-fno-strict-aliasing \
	-Wno-unused-parameter \
	-Wno-missing-field-initializers \
	-fvisibility=hidden \
	-pipe \
	-fPIC \
	-Wno-unused-local-typedefs \
	-Wno-format \
	-m64 \
	-march=x86-64 \
	-ffunction-sections \
	-funwind-tables \
	-g \
	-fstack-protector \
	-fno-short-enums \
	-finline-limit=64 \
	-Wa,--noexecstack \
	-U_FORTIFY_SOURCE \
	-Wno-extra \
	-Wno-ignored-qualifiers \
	-Wno-type-limits \
	-Wno-unused-but-set-variable \
	-Wno-address \
	-Wno-format-security \
	-Wno-return-type \
	-Wno-sequence-point \
	-Os \
	-g \
	-gdwarf-4 \
	-fdata-sections \
	-ffunction-sections \
	-fomit-frame-pointer \
	-funwind-tables

MY_DEFS_Debug := \
	'-DEXPAT_RELATIVE_PATH' \
	'-DFEATURE_ENABLE_SSL' \
	'-DGTEST_RELATIVE_PATH' \
	'-DHAVE_SRTP' \
	'-DHAVE_WEBRTC_VIDEO' \
	'-DHAVE_WEBRTC_VOICE' \
	'-DLOGGING_INSIDE_WEBRTC' \
	'-DNO_MAIN_THREAD_WRAPPING' \
	'-DNO_SOUND_SYSTEM' \
	'-DSRTP_RELATIVE_PATH' \
	'-DUSE_WEBRTC_DEV_BRANCH' \
	'-DENABLE_EXTERNAL_AUTH' \
	'-DWEBRTC_CHROMIUM_BUILD' \
	'-DV8_DEPRECATION_WARNINGS' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DNO_TCMALLOC' \
	'-DDISABLE_NACL' \
	'-DLIBPEERCONNECTION_LIB=1' \
	'-DSSL_USE_OPENSSL' \
	'-DHAVE_OPENSSL_SSL_H' \
	'-DPOSIX' \
	'-DWEBRTC_POSIX' \
	'-DCHROMIUM_BUILD' \
	'-DUSE_LIBJPEG_TURBO=1' \
	'-DENABLE_WEBRTC=1' \
	'-DUSE_PROPRIETARY_CODECS' \
	'-DENABLE_BROWSER_CDMS' \
	'-DENABLE_CONFIGURATION_POLICY' \
	'-DDISCARDABLE_MEMORY_ALWAYS_SUPPORTED_NATIVELY' \
	'-DSYSTEM_NATIVELY_SIGNALS_MEMORY_PRESSURE' \
	'-DENABLE_EGLIMAGE=1' \
	'-DCLD_VERSION=1' \
	'-DENABLE_PRINTING=1' \
	'-DENABLE_MANAGED_USERS=1' \
	'-DDATA_REDUCTION_FALLBACK_HOST="http://compress.googlezip.net:80/"' \
	'-DDATA_REDUCTION_DEV_HOST="https://proxy-dev.googlezip.net:443/"' \
	'-DDATA_REDUCTION_DEV_FALLBACK_HOST="http://proxy-dev.googlezip.net:80/"' \
	'-DSPDY_PROXY_AUTH_ORIGIN="https://proxy.googlezip.net:443/"' \
	'-DDATA_REDUCTION_PROXY_PROBE_URL="http://check.googlezip.net/connect"' \
	'-DDATA_REDUCTION_PROXY_WARMUP_URL="http://www.gstatic.com/generate_204"' \
	'-DVIDEO_HOLE=1' \
	'-DENABLE_LOAD_COMPLETION_HACKS=1' \
	'-DHAVE_SCTP' \
	'-DPOSIX_AVOID_MMAP' \
	'-DXML_STATIC' \
	'-DHAVE_INT16_T' \
	'-DHAVE_INT32_T' \
	'-DHAVE_INT8_T' \
	'-DHAVE_UINT16_T' \
	'-DHAVE_UINT32_T' \
	'-DHAVE_UINT64_T' \
	'-DHAVE_UINT8_T' \
	'-DHAVE_STDINT_H' \
	'-DHAVE_INTTYPES_H' \
	'-DHAVE_NETINET_IN_H' \
	'-DINLINE=inline' \
	'-DCPU_CISC' \
	'-DWEBRTC_LINUX' \
	'-DWEBRTC_ANDROID' \
	'-DWEBRTC_ANDROID_OPENSLES' \
	'-DFEATURE_ENABLE_VOICEMAIL' \
	'-DANDROID' \
	'-DUSE_OPENSSL=1' \
	'-DUSE_OPENSSL_CERTS=1' \
	'-D__GNU_SOURCE=1' \
	'-DUSE_STLPORT=1' \
	'-D_STLP_USE_PTR_SPECIALIZATIONS=1' \
	'-DCHROME_BUILD_ID=""' \
	'-DDYNAMIC_ANNOTATIONS_ENABLED=1' \
	'-DWTF_USE_DYNAMIC_ANNOTATIONS=1' \
	'-D_DEBUG'


# Include paths placed before CFLAGS/CPPFLAGS
LOCAL_C_INCLUDES_Debug := \
	$(gyp_shared_intermediate_dir)/shim_headers/icuuc/target \
	$(gyp_shared_intermediate_dir)/shim_headers/icui18n/target \
	$(LOCAL_PATH)/third_party/libjingle/overrides \
	$(LOCAL_PATH)/third_party/webrtc/overrides \
	$(LOCAL_PATH)/third_party/libjingle/source \
	$(LOCAL_PATH) \
	$(LOCAL_PATH)/testing/gtest/include \
	$(LOCAL_PATH)/third_party \
	$(LOCAL_PATH)/third_party/libyuv/include \
	$(LOCAL_PATH)/third_party/usrsctp \
	$(gyp_shared_intermediate_dir) \
	$(LOCAL_PATH)/third_party/expat/files/lib \
	$(LOCAL_PATH)/third_party/boringssl/src/include \
	$(LOCAL_PATH)/third_party/libsrtp/config \
	$(LOCAL_PATH)/third_party/libsrtp/srtp/include \
	$(LOCAL_PATH)/third_party/libsrtp/srtp/crypto/include \
	$(LOCAL_PATH)/third_party/webrtc/overrides \
	$(LOCAL_PATH)/third_party \
	$(LOCAL_PATH)/third_party/webrtc/modules/media_file/interface \
	$(LOCAL_PATH)/third_party/webrtc/modules/interface \
	$(LOCAL_PATH)/third_party/usrsctp/usrsctplib \
	$(LOCAL_PATH)/third_party/usrsctp/usrsctplib/netinet \
	$(PWD)/frameworks/wilhelm/include \
	$(PWD)/bionic \
	$(PWD)/external/stlport/stlport


# Flags passed to only C++ (and not C) files.
LOCAL_CPPFLAGS_Debug := \
	-fno-exceptions \
	-fno-rtti \
	-fno-threadsafe-statics \
	-fvisibility-inlines-hidden \
	-Wno-deprecated \
	-std=gnu++11 \
	-Wno-narrowing \
	-Wno-literal-suffix \
	-Wno-non-virtual-dtor \
	-Wno-sign-promo \
	-Wno-non-virtual-dtor


# Flags passed to both C and C++ files.
MY_CFLAGS_Release := \
	-fstack-protector \
	--param=ssp-buffer-size=4 \
	-fno-strict-aliasing \
	-Wno-unused-parameter \
	-Wno-missing-field-initializers \
	-fvisibility=hidden \
	-pipe \
	-fPIC \
	-Wno-unused-local-typedefs \
	-Wno-format \
	-m64 \
	-march=x86-64 \
	-ffunction-sections \
	-funwind-tables \
	-g \
	-fstack-protector \
	-fno-short-enums \
	-finline-limit=64 \
	-Wa,--noexecstack \
	-U_FORTIFY_SOURCE \
	-Wno-extra \
	-Wno-ignored-qualifiers \
	-Wno-type-limits \
	-Wno-unused-but-set-variable \
	-Wno-address \
	-Wno-format-security \
	-Wno-return-type \
	-Wno-sequence-point \
	-Os \
	-fno-ident \
	-fdata-sections \
	-ffunction-sections \
	-fomit-frame-pointer \
	-funwind-tables

MY_DEFS_Release := \
	'-DEXPAT_RELATIVE_PATH' \
	'-DFEATURE_ENABLE_SSL' \
	'-DGTEST_RELATIVE_PATH' \
	'-DHAVE_SRTP' \
	'-DHAVE_WEBRTC_VIDEO' \
	'-DHAVE_WEBRTC_VOICE' \
	'-DLOGGING_INSIDE_WEBRTC' \
	'-DNO_MAIN_THREAD_WRAPPING' \
	'-DNO_SOUND_SYSTEM' \
	'-DSRTP_RELATIVE_PATH' \
	'-DUSE_WEBRTC_DEV_BRANCH' \
	'-DENABLE_EXTERNAL_AUTH' \
	'-DWEBRTC_CHROMIUM_BUILD' \
	'-DV8_DEPRECATION_WARNINGS' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DNO_TCMALLOC' \
	'-DDISABLE_NACL' \
	'-DLIBPEERCONNECTION_LIB=1' \
	'-DSSL_USE_OPENSSL' \
	'-DHAVE_OPENSSL_SSL_H' \
	'-DPOSIX' \
	'-DWEBRTC_POSIX' \
	'-DCHROMIUM_BUILD' \
	'-DUSE_LIBJPEG_TURBO=1' \
	'-DENABLE_WEBRTC=1' \
	'-DUSE_PROPRIETARY_CODECS' \
	'-DENABLE_BROWSER_CDMS' \
	'-DENABLE_CONFIGURATION_POLICY' \
	'-DDISCARDABLE_MEMORY_ALWAYS_SUPPORTED_NATIVELY' \
	'-DSYSTEM_NATIVELY_SIGNALS_MEMORY_PRESSURE' \
	'-DENABLE_EGLIMAGE=1' \
	'-DCLD_VERSION=1' \
	'-DENABLE_PRINTING=1' \
	'-DENABLE_MANAGED_USERS=1' \
	'-DDATA_REDUCTION_FALLBACK_HOST="http://compress.googlezip.net:80/"' \
	'-DDATA_REDUCTION_DEV_HOST="https://proxy-dev.googlezip.net:443/"' \
	'-DDATA_REDUCTION_DEV_FALLBACK_HOST="http://proxy-dev.googlezip.net:80/"' \
	'-DSPDY_PROXY_AUTH_ORIGIN="https://proxy.googlezip.net:443/"' \
	'-DDATA_REDUCTION_PROXY_PROBE_URL="http://check.googlezip.net/connect"' \
	'-DDATA_REDUCTION_PROXY_WARMUP_URL="http://www.gstatic.com/generate_204"' \
	'-DVIDEO_HOLE=1' \
	'-DENABLE_LOAD_COMPLETION_HACKS=1' \
	'-DHAVE_SCTP' \
	'-DPOSIX_AVOID_MMAP' \
	'-DXML_STATIC' \
	'-DHAVE_INT16_T' \
	'-DHAVE_INT32_T' \
	'-DHAVE_INT8_T' \
	'-DHAVE_UINT16_T' \
	'-DHAVE_UINT32_T' \
	'-DHAVE_UINT64_T' \
	'-DHAVE_UINT8_T' \
	'-DHAVE_STDINT_H' \
	'-DHAVE_INTTYPES_H' \
	'-DHAVE_NETINET_IN_H' \
	'-DINLINE=inline' \
	'-DCPU_CISC' \
	'-DWEBRTC_LINUX' \
	'-DWEBRTC_ANDROID' \
	'-DWEBRTC_ANDROID_OPENSLES' \
	'-DFEATURE_ENABLE_VOICEMAIL' \
	'-DANDROID' \
	'-DUSE_OPENSSL=1' \
	'-DUSE_OPENSSL_CERTS=1' \
	'-D__GNU_SOURCE=1' \
	'-DUSE_STLPORT=1' \
	'-D_STLP_USE_PTR_SPECIALIZATIONS=1' \
	'-DCHROME_BUILD_ID=""' \
	'-DNDEBUG' \
	'-DNVALGRIND' \
	'-DDYNAMIC_ANNOTATIONS_ENABLED=0'


# Include paths placed before CFLAGS/CPPFLAGS
LOCAL_C_INCLUDES_Release := \
	$(gyp_shared_intermediate_dir)/shim_headers/icuuc/target \
	$(gyp_shared_intermediate_dir)/shim_headers/icui18n/target \
	$(LOCAL_PATH)/third_party/libjingle/overrides \
	$(LOCAL_PATH)/third_party/webrtc/overrides \
	$(LOCAL_PATH)/third_party/libjingle/source \
	$(LOCAL_PATH) \
	$(LOCAL_PATH)/testing/gtest/include \
	$(LOCAL_PATH)/third_party \
	$(LOCAL_PATH)/third_party/libyuv/include \
	$(LOCAL_PATH)/third_party/usrsctp \
	$(gyp_shared_intermediate_dir) \
	$(LOCAL_PATH)/third_party/expat/files/lib \
	$(LOCAL_PATH)/third_party/boringssl/src/include \
	$(LOCAL_PATH)/third_party/libsrtp/config \
	$(LOCAL_PATH)/third_party/libsrtp/srtp/include \
	$(LOCAL_PATH)/third_party/libsrtp/srtp/crypto/include \
	$(LOCAL_PATH)/third_party/webrtc/overrides \
	$(LOCAL_PATH)/third_party \
	$(LOCAL_PATH)/third_party/webrtc/modules/media_file/interface \
	$(LOCAL_PATH)/third_party/webrtc/modules/interface \
	$(LOCAL_PATH)/third_party/usrsctp/usrsctplib \
	$(LOCAL_PATH)/third_party/usrsctp/usrsctplib/netinet \
	$(PWD)/frameworks/wilhelm/include \
	$(PWD)/bionic \
	$(PWD)/external/stlport/stlport


# Flags passed to only C++ (and not C) files.
LOCAL_CPPFLAGS_Release := \
	-fno-exceptions \
	-fno-rtti \
	-fno-threadsafe-statics \
	-fvisibility-inlines-hidden \
	-Wno-deprecated \
	-std=gnu++11 \
	-Wno-narrowing \
	-Wno-literal-suffix \
	-Wno-non-virtual-dtor \
	-Wno-sign-promo \
	-Wno-non-virtual-dtor


LOCAL_CFLAGS := $(MY_CFLAGS_$(GYP_CONFIGURATION)) $(MY_DEFS_$(GYP_CONFIGURATION))
LOCAL_C_INCLUDES := $(GYP_COPIED_SOURCE_ORIGIN_DIRS) $(LOCAL_C_INCLUDES_$(GYP_CONFIGURATION))
LOCAL_CPPFLAGS := $(LOCAL_CPPFLAGS_$(GYP_CONFIGURATION))
LOCAL_ASFLAGS := $(LOCAL_CFLAGS)
### Rules for final target.

LOCAL_SHARED_LIBRARIES := \
	libstlport \
	libdl

# Add target alias to "gyp_all_modules" target.
.PHONY: gyp_all_modules
gyp_all_modules: third_party_libjingle_libjingle_webrtc_common_gyp

# Alias gyp target name.
.PHONY: libjingle_webrtc_common
libjingle_webrtc_common: third_party_libjingle_libjingle_webrtc_common_gyp

include $(BUILD_STATIC_LIBRARY)
