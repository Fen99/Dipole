#pragma once
#ifndef COMMON_H
#define COMMON_H

//========================================================================
//========================================================================

#include <functional>

#include <array>
#include <complex>

#include <assert.h>

#include <boost/numeric/ublas/matrix.hpp>

//========================================================================

using namespace boost::numeric::ublas;

//========================================================================

using Vector3D = std::array<double, 3>;
using ComplexDouble = std::complex<double>;
using DoubleMatrix = matrix<double>;

using ComplexSpaceFunction = std::function<ComplexDouble(const Vector3D&)>;

//------------------------------------------------------------------------

double operator*(const Vector3D& first, const Vector3D& second); //Scalar product

ComplexSpaceFunction operator*(ComplexSpaceFunction first, ComplexSpaceFunction second);
ComplexSpaceFunction GetConjugate(ComplexSpaceFunction func);

//------------------------------------------------------------------------

DoubleMatrix Make3DMatrixFromRows(std::vector<Vector3D> rows);

//========================================================================

#endif //COMMON_H