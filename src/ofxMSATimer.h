/***********************************************************************
 
 Copyright (c) 2008, 2009, Memo Akten, www.memo.tv
 *** The Mega Super Awesome Visuals Company ***
 * All rights reserved.
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

#include <mach/mach_time.h>


class ofxMSATimer {
public:
	ofxMSATimer();
	
	inline double getTotalTime();			// elapsed seconds since beginning of time
	inline double getAppTime();				// elapsed seconds since start of app
	inline uint64_t getAppTimeMillis(); 	// elapsed millis since start of app
	inline double getTimeSinceLastCall();	// elapsed seconds since last time this function was called
    
	inline void setStartTime();			
	inline double getElapsedTime();			// elapsed seconds since you called setStartTime()
	
protected:
	double machMultiplier;
	double appStartTime;
	double lastCallTime;
	double startTime;
    uint64_t startMillis;
    uint64_t machStartime;
    mach_timebase_info_data_t info;
};

extern ofxMSATimer msaTimer;

inline uint64_t ofxMSATimer::getAppTimeMillis() {
    /* no float conversion here */
	return (mach_absolute_time() - machStartime) * info.numer / (info.denom * 1000000);
}

inline double ofxMSATimer::getTotalTime() {
	return mach_absolute_time() * machMultiplier;
}

inline double ofxMSATimer::getAppTime() {
	return mach_absolute_time() * machMultiplier - appStartTime;
}

inline double ofxMSATimer::getTimeSinceLastCall() {
	float nowTime = mach_absolute_time() * machMultiplier;
	float diff = nowTime - lastCallTime;
	lastCallTime = nowTime;
	return diff;
}

inline void ofxMSATimer::setStartTime() {
	startTime = mach_absolute_time() * machMultiplier;
}

inline double ofxMSATimer::getElapsedTime() {
	return mach_absolute_time() * machMultiplier - startTime;
}