#include "FreeWave.h"
#include <math.h>

//========================================================================
//========================================================================

FreeWave::FreeWave(Vector3D pulse) : pulse_(pulse)
{}

ComplexDouble FreeWave::operator()(const Vector3D& point)
{
	double scalar_product = point * pulse_;
	return {cos(scalar_product), sin(scalar_product)};
}