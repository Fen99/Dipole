#include "DipoleMomentOperator.h"

//========================================================================
//========================================================================

ComplexSpaceFunction DipoleMomentOperator::GetModifiedFunction(ComplexSpaceFunction source_func)
{
	return [source_func](const Vector3D& point) -> ComplexDouble
		   {
				return source_func(point) * point[2]; //z * psi
		   };
}