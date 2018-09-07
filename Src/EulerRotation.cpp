#include "EulerRotation.h"
#include <math.h>
#include <iostream>

//========================================================================
//========================================================================

EulerRotation::EulerRotation(const Vector3D& angles)
{
	auto first_matrix = Make3DMatrixFromRows({{cos(angles[0]), sin(angles[0]), 0},
											  {-sin(angles[0]), cos(angles[0]), 0},
											  {0, 0, 1}});
	DoubleMatrix second_matrix = prod(first_matrix, Make3DMatrixFromRows({{cos(angles[1]), 0, -sin(angles[1])},
																		  {0, 1, 0},
																		  {sin(angles[1]), 0, cos(angles[1])}}));
	rotation_matrix_ = prod(second_matrix, Make3DMatrixFromRows({{cos(angles[2]), sin(angles[2]), 0},
														   	     {-sin(angles [2]), cos(angles [2]), 0},
															     {0, 0, 1}}));
}

Vector3D EulerRotation::RotateVector_(const Vector3D& source_coord) const
{
	return {rotation_matrix_(0, 0)*source_coord[0] + rotation_matrix_(0, 1)*source_coord[1] + rotation_matrix_(0, 2)*source_coord[2],
			rotation_matrix_(1, 0)*source_coord[0] + rotation_matrix_(1, 1)*source_coord[1] + rotation_matrix_(1, 2)*source_coord[2],
			rotation_matrix_(2, 0)*source_coord[0] + rotation_matrix_(2, 1)*source_coord[1] + rotation_matrix_(2, 2)*source_coord[2]};
}

ComplexSpaceFunction EulerRotation::GetModifiedFunction(ComplexSpaceFunction source_func)
{
	return [this, source_func](const Vector3D& point) -> ComplexDouble
		   {
			   return source_func(RotateVector_(point));
		   };
}