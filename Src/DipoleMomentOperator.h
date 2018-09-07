#pragma once
#ifndef DIPOLE_MOMENT_OPERATOR_H
#define DIPOLE_MOMENT_OPERATOR_H

//========================================================================
//========================================================================

#include "FunctionalOperator.h"

//========================================================================
//========================================================================

class DipoleMomentOperator : public FunctionalOperator
{
	public:
		virtual ~DipoleMomentOperator() {}
		ComplexSpaceFunction GetModifiedFunction(ComplexSpaceFunction source_func) override;
};

//========================================================================
//========================================================================

#endif //DIPOLE_MOMENT_OPERATOR_H