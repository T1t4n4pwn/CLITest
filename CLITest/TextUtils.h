#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class TextUtilsBase {
public:
	static bool Split(const T& Text, const T& Separator, std::vector<T>& Results);

	static bool EqualsNocase(const T& Operand1, const T& Operand2);
};

using TextUtils = TextUtilsBase<std::string>;
using TextUtilsW = TextUtilsBase<std::wstring>;

template<typename T>
inline bool TextUtilsBase<T>::Split(const T& Text, const T& Separator, std::vector<T>& Results)
{
	size_t start = 0;
	size_t end = end = Text.find(Separator);

	while (end != T::npos) {
		Results.push_back(Text.substr(start, end - start));
		start = end + Separator.length();
		end = Text.find(Separator, start);
	}

	Results.push_back(Text.substr(start));

	return true;

}

template<typename T>
inline bool TextUtilsBase<T>::EqualsNocase(const T& Operand1, const T& Operand2)
{
	bool isEqual = std::equal(Operand1.begin(), Operand1.end(), Operand2.begin(), Operand2.end(),
		[](typename T::value_type c1, typename T::value_type c2) {
			return std::toupper(c1) == std::toupper(c2);
		});

	return isEqual;
}
