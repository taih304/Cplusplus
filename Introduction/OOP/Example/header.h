#include <iostream>
#ifndef header_h
#define header_h

using namespace std;

class exampleClass
{
  	public:
		static int 	static_var;
		static void read_static_var();
		static int 	return_int_num();
		static void print_argument(int argument);
		int 		instance_var;
		void 		class_constructor();
		void 		add_number(int int_param);
		void 		call_private_function();
		
  	private:  
    	int 		_int_param;
		void		display_string();
};
#endif
