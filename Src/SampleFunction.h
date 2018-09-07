#pragma once

#ifndef SAMPLE_FUNCTION_H
#define SAMPLE_FUNCTION_H

//========================================================================
//========================================================================

#include "Common.h"

//========================================================================
//========================================================================

class SampleFunction
{
	private:
		double alpha_;
		double norm_;

	public:
		SampleFunction(double alpha, double norm = 1.0);

		void SetNormalization(double norm);

		ComplexDouble operator()(const Vector3D& point);
};

//========================================================================
//========================================================================

#endif