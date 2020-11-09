#pragma once
std::vector<double>& vector_scalar_multiplication(std::vector<double>& v, const double& a)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] = v[i] * a;
    }
    return v;
}