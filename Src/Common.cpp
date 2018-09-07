#include "Common.h"

//========================================================================
//========================================================================

double operator*(const Vector3D& first, const Vector3D& second)
{
	return first[0]*second[0] + first[1]*second[1] + first[2]*second[2];
}

ComplexSpaceFunction operator*(ComplexSpaceFunction first, ComplexSpaceFunction second)
{
	return [first, second](const Vector3D& point) { return first(point)*second(point); };
}

ComplexSpaceFunction GetConjugate(ComplexSpaceFunction func)
{
	return [func](const Vector3D& point) { return std::conj(func(point)); };
}

DoubleMatrix Make3DMatrixFromRows(std::vector<Vector3D> rows)
{
	assert(rows.size() == 3);

	DoubleMatrix result_matrix(3, 3);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result_matrix(i, j) = rows[i][j];
		}
	}

	return result_matrix;
}