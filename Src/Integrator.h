#pragma once

#ifndef INTEGRATOR_H
#define INTEGRATOR_H

//========================================================================
//========================================================================

#include <boost/math/quadrature/naive_monte_carlo.hpp>

#include "Common.h"

//========================================================================
//========================================================================

using namespace boost::math::quadrature;

using Bounds = std::pair<double, double>;

class Integrator
{
	private:
		std::vector<Bounds> domain_bounds_;
		double error_goal_;

		// Интегрирует функцию (std::vector<double> -> double)
		template<typename Function_type>
		double Integrate_(const Function_type& func) const;

	public:
		Integrator(const std::vector<Bounds>& bounds, double error_goal);

		ComplexDouble IntegrateFunction(const ComplexSpaceFunction& func) const;
};

//========================================================================
//========================================================================

#endif