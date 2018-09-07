#include "Integrator.h"
#include <iostream>

Integrator::Integrator(const std::vector<Bounds>& bounds, double error_goal) : domain_bounds_(bounds),
																						  error_goal_(error_goal)
{}

template<typename Function_type>
double Integrator::Integrate_(const Function_type& func) const
{
	naive_monte_carlo<double, decltype(func)> mc_part(func, domain_bounds_, error_goal_);
	std::future<double> task = mc_part.integrate();
	//task.wait();

	while (task.wait_for(std::chrono::seconds(1)) != std::future_status::ready)
	{
		std::cout << "Progress: " << mc_part.progress() << "; " << "; Error est.: " << mc_part.current_error_estimate() <<
				     "; Curr. est.: " << mc_part.current_estimate() << "; Est. to end: " <<
				     mc_part.estimated_time_to_completion().count() << std::endl;
	}

	return task.get();
}

ComplexDouble Integrator::IntegrateFunction(const ComplexSpaceFunction& func) const
{
	auto real_part = [&func](const std::vector<double>& point) { return std::real(func({point [0], point [1], point [2]})); };
	auto imag_part = [&func](const std::vector<double>& point) { return std::imag(func({point [0], point [1], point [2]})); };

	return { Integrate_(real_part), Integrate_(imag_part) };
}