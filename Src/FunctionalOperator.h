#pragma once
#ifndef FUNCTIONAL_OPERATOR_H
#define FUNCTIONAL_OPERATOR_H

//========================================================================
//========================================================================

#include <functional>
#include <memory>

//------------------------------------------------------------------------

#include "Common.h"

//========================================================================

class FunctionalOperator
{
	public:
		virtual ~FunctionalOperator() {}
		virtual ComplexSpaceFunction GetModifiedFunction(ComplexSpaceFunction source_func) = 0;
};

//========================================================================

#endif // !FUNCTIONAL_OPERATOR_H