#pragma once
#ifndef EULER_ROTATION_H
#define EULER_ROTATION_H

//========================================================================
//========================================================================

#include "Common.h"
#include "FunctionalOperator.h"

//========================================================================
//========================================================================

class EulerRotation : public FunctionalOperator
{
	private:
		DoubleMatrix rotation_matrix_;
		
		Vector3D RotateVector_(const Vector3D& source_coord) const;

	public:
		// 0) psi - вращение вокруг начальной оси z
		// 1) theta - вращение вокруг новой оси y
		// 2) hi - вращение вокруг новой оси z
		EulerRotation(const Vector3D& angles);
		ComplexSpaceFunction GetModifiedFunction(ComplexSpaceFunction source_func) override;

		virtual ~EulerRotation() {}
};

//========================================================================
//========================================================================

#endif

