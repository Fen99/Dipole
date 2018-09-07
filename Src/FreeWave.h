#pragma once

#ifndef FREE_WAVE_H
#define FREE_WAVE_H

//========================================================================
//========================================================================

#include "Common.h"

//========================================================================
//========================================================================

class FreeWave
{
	private:
		Vector3D pulse_;

	public:
		FreeWave(Vector3D pulse);
		ComplexDouble operator()(const Vector3D& point);
};

//========================================================================
//========================================================================

#endif