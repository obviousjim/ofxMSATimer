/***********************************************************************
 
 Copyright (c) 2008, 2009, Memo Akten, www.memo.tv
 * Adapted for Windows by Juan Pablo Manson
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of MSA Visuals nor the names of its contributors
 *       may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ***********************************************************************/

#pragma once

#include "ofMain.h"

#if defined(TARGET_WIN32)
	#define NOMINMAX
	#include <windows.h>
#elif defined(TARGET_OSX)
	#include <sys/time.h>
	#include <mach/mach_time.h>
#elif defined(TARGET_LINUX)
	//TODO:
#endif

#include "stdio.h"
#include "stdint.h"

class ofxMSATimer {
  public:
    ofxMSATimer();
    
	float getAppTimeSeconds();
	uint32_t getAppTimeMillis();
	uint64_t getAppTimeMicros();
    
	void setStartTime();
	float getElapsedSeconds();
	uint32_t getElapsedMillis();
	uint64_t getElapsedMicros();
	
	float getSecondsSinceLastCall();
	uint32_t getMillisSinceLastCall();
	uint64_t getMicrosSinceLastCall();
	
protected:
    
	uint64_t timerStartTimeMicros;
    uint64_t lastCallTimeMicros;
    
	#if defined(TARGET_WIN32)
    LARGE_INTEGER ticksPerSecond;
    LARGE_INTEGER startTime, stopTime;
	#elif defined(TARGET_OSX)
    mach_timebase_info_data_t info;
    uint64_t machStartTime; //nanos
	#elif defined(TARGET_LINUX)
	//TODO:
	#endif
    
};
/*
class ofxMSATimer {
public:
	ofxMSATimer();
	
	inline double getTotalTime();			// elapsed seconds since beginning of time
	inline uint64_t getMachAbsoluteTime();	// elapsed machine time since beginning of time	(platform dependent)
	inline double getAppTime();				// elapsed seconds since start of app
	inline uint64_t getAppTimeMillis(); 	// elapsed millis since start of app
	inline double getTimeSinceLastCall();	// elapsed seconds since last time this function was called
    inline void initialize();
	inline void setStartTime();			
	inline double getElapsedTime();			// elapsed seconds since you called setStartTime()

	#if defined(_MSC_VER)
		void start() {
				QueryPerformanceCounter(&startTimeW);
		}
		void stop() {
				QueryPerformanceCounter(&stopTime);
		}
		double getSeconds() {
				return (double) elapsed() / ticksPerSecond.QuadPart;
		}
		double getMilliseconds() {
				return ((double) elapsed() * 1000) / ticksPerSecond.QuadPart;
		}
		double getMicroseconds() {
				return ((double) elapsed() * 1000000) / ticksPerSecond.QuadPart;
		}
		double getNanoseconds() {
				return ((double) elapsed() * 1000000000) / ticksPerSecond.QuadPart;
		}
	
	#endif
	
protected:
	double machMultiplier;
	double appStartTime;
	double lastCallTime;
	double startTime;
    uint64_t startMillis;
    uint64_t machStartime;
	#if defined(_MSC_VER)
	#else
		mach_timebase_info_data_t info;
	#endif
private:
	#if defined(_MSC_VER)
		LARGE_INTEGER ticksPerSecond;
        LARGE_INTEGER startTimeW, lastCallTimeW, stopTime;
		LONGLONG elapsed() {
			return stopTime.QuadPart - startTimeW.QuadPart;
		}
	#endif
 	
	uint64_t machAbsoluteTime() { //return nanos
		#if defined(_MSC_VER)
			return GetTickCount(); 
		#else
			return mach_absolute_time(); //return nanos
		#endif
	}
};

extern ofxMSATimer msaTimer;

inline uint64_t ofxMSATimer::getAppTimeMillis() {
	#if defined(_MSC_VER)
		return (machAbsoluteTime() - machStartime);  
	#else
		return (machAbsoluteTime() - machStartime) * info.numer / (info.denom * 1000000);
	#endif    
}

inline double ofxMSATimer::getTotalTime() {
	return machAbsoluteTime() * machMultiplier;
}

inline uint64_t ofxMSATimer::getMachAbsoluteTime() {
	return machAbsoluteTime();
}

inline double ofxMSATimer::getAppTime() {
	return machAbsoluteTime() * machMultiplier - appStartTime;
}

inline double ofxMSATimer::getTimeSinceLastCall() { 
	#if defined(_MSC_VER)
		LARGE_INTEGER lastCall = lastCallTimeW;
		QueryPerformanceCounter(&lastCallTimeW);
		return (double) (lastCallTimeW.QuadPart - lastCall.QuadPart) / ticksPerSecond.QuadPart;
	#else
		float nowTime = machAbsoluteTime() * machMultiplier;
		float diff = nowTime - lastCallTime;
		lastCallTime = nowTime;
		return diff;
	#endif
}

inline void ofxMSATimer::setStartTime() {
	#if defined(_MSC_VER)
        start();
        stopTime = startTimeW;
		QueryPerformanceCounter(&startTimeW);
	#else
		startTime = machAbsoluteTime() * machMultiplier;
	#endif
}

inline void ofxMSATimer::initialize() {
	#if defined(_MSC_VER)
		QueryPerformanceFrequency(&ticksPerSecond);
		QueryPerformanceCounter(&lastCallTimeW);
	#else
	#endif
}

inline double ofxMSATimer::getElapsedTime() {
	#if defined(_MSC_VER)
		QueryPerformanceCounter(&stopTime);
		return getSeconds();
	#else
		return machAbsoluteTime() * machMultiplier - startTime;
	#endif
}

*/

