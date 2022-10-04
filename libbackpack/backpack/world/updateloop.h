#pragma once

#include <chrono>
#include <algorithm>
#include "core/types.h"

namespace ch = std::chrono;

struct UpdateLoop {
	ch::high_resolution_clock::time_point lastTimePoint;
	uint64_bp nsFrameTime;
	float secTargetFrameTime;
	float secMaxFrameTime;
	float secFrameTime;
};

void initUpdateLoop(UpdateLoop& loop, float targetFrameTimeSeconds = (1.f/60.f), float maxFrameTimeSeconds = 1.f) {
	loop.lastTimePoint = ch::high_resolution_clock::now();
	loop.nsFrameTime = 0;
	loop.secTargetFrameTime = targetFrameTimeSeconds;
	loop.secMaxFrameTime = maxFrameTimeSeconds;
	loop.secFrameTime = targetFrameTimeSeconds;
}

float updateFrameTime(UpdateLoop& loop) {
	ch::high_resolution_clock::time_point now = ch::high_resolution_clock::now();
	ch::high_resolution_clock::duration diff = now - loop.lastTimePoint;

	uint64_bp ft = std::min<long long>(diff.count(), (long long)loop.secMaxFrameTime*1000000000);
	loop.nsFrameTime = ft;
	loop.secFrameTime = (float)ft/1000000000.f;
	loop.lastTimePoint = now;
	return ft;
}