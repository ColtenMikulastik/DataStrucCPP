

#include <iostream>
#include <string>
#include "exprtk/exprtk.hpp"


int main()
{
	std::string exp_str = "x := x + 3";
	
	int x {};

	symbol_table_t symbol_table;
	symbol_table.add_variable("x",x);

	expression_t expression;
	expression.register_symbol_table(symbol_table);
	
	parser_t parser;
	parser.compile(exp_str,expression)

	std::cout << "thing: " << x << std::endl;

	
	return 0;
}
