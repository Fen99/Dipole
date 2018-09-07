#include <iostream>
#include <fstream>

#define _USE_MATH_DEFINES
#include <cmath>

#include "Integrator.h"
#include "FreeWave.h"
#include "SampleFunction.h"
#include "EulerRotation.h"
#include "DipoleMomentOperator.h"

//========================================================================
//========================================================================

const double infinity = std::numeric_limits<double>::infinity();
const Bounds infinity_bounds = {-infinity, infinity};

//========================================================================

using BoundsIterator = std::vector<Bounds>::iterator;

void GetDistribution(const Integrator& integrator, const ComplexSpaceFunction& func, const std::vector<Bounds>& bounds, double step)
{
	assert(bounds.size() == 3);

	std::fstream file;
	file.open("Distribution_big_step.dat", std::ios_base::out);

	for (double x = bounds[0].first; x < bounds[0].second; x += step)
	{
		for (double y = bounds[0].first; y < bounds[0].second; y += step)
		{
			for (double z = bounds[0].first; z < bounds[0].second; z += step)
			{
				std::cout << std::endl << x << "\t" << y << "\t" << z << "\t" << std::endl;

				FreeWave wave({x, y, z});
				file << x << "\t" << y << "\t" << z << "\t";
				auto result = integrator.IntegrateFunction(wave * func);
				file << result.real() << "\t" << result.imag() << "\n";
				file.flush();
			}
		}
	}
}

//========================================================================

void MainFunction()
{
	Integrator integrator({infinity_bounds, infinity_bounds, infinity_bounds}, 1e-3);

	FreeWave f_wave({0, 0, 0});
	SampleFunction source_func(1.5);

	//Нормализация
	std::cout << "Normalization" << std::endl;
	auto norm = integrator.IntegrateFunction(source_func * GetConjugate(source_func));
	source_func.SetNormalization(sqrt(norm.real()));

	//Интегрирование
	std::cout << "Integration" << std::endl;

	EulerRotation rotation({0, 0, 0});
	DipoleMomentOperator dipole_moment;
	
 	auto subint_f = dipole_moment.GetModifiedFunction(rotation.GetModifiedFunction(source_func));
// 	auto result = integrator.IntegrateFunction(subint_f);
	GetDistribution(integrator, subint_f, {{-1, 1}, {-1, 1}, {-1, 1}}, 0.3);
}

int main()
{
	try
	{
		MainFunction();
	}
	catch (std::exception& e)
	{
		char tmp = '\0';

		std::cout << e.what() << std::endl;
		std::cin >> tmp;
		return 1;
	}

	char tmp = '\0';
	std::cin >> tmp;
	return 0;
}