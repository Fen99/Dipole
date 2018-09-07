#include "SampleFunction.h"
#include <math.h>

SampleFunction::SampleFunction(double alpha, double norm) : alpha_(alpha), norm_(norm)
{
	assert(norm > 0);
}

ComplexDouble SampleFunction::operator()(const Vector3D& point)
{
	ComplexDouble result = {exp(-alpha_*(point [0] * point [0] + point [1] * point [1] + abs(point [2]))), 0};
	return result / norm_;
}

void SampleFunction::SetNormalization(double norm)
{
	assert(norm > 0);
	norm_ = norm;
}