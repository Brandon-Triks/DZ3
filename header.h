//
// Created by user on 07.12.2025.
//

#ifndef DZ3_HEADER_H
#define DZ3_HEADER_H

#include <ranges>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <format>
#include <cmath>
bool is_numb(std::string str);
bool is_operator(const std::string& str);
void edit_string(std::string& vhod, const std::vector <std::string>& op);
std::vector <std::string> pars(const std::string& vhod);
void replace_un_minus(std::vector <std::string>& pars,const std::vector <std::string>& op);
bool is_correct(const std::vector <std::string>& vec);
bool is_func(const std::string& str);
bool pr_comparing(const char& a, const char& b);
std::vector<std::string> repl_x(std::string& vihod, const std::string& x);
#endif //DZ3_HEADER_H