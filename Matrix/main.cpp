
#include <iostream>
#include <vector>

class Matrix
{	
	private:
		std::vector <std::vector<int>> mat;
		int x_size, y_size;

	public:
		Matrix(int temp_x_size, int temp_y_size);
		void print_matrix();
		~Matrix(){};

};

Matrix::Matrix(int temp_x_size, int temp_y_size)
{
	this->x_size = temp_x_size;
	this->y_size = temp_y_size;
	
	this->mat.resize(this->x_size);
	for(int i{}; i < this->x_size; i++)
	{
		this->mat[i].resize(this->y_size);
	}
}

void Matrix::print_matrix()
{
	for(std::vector<int> x_vecs : this->mat)
	{
		for(int y_int : x_vecs)
		{
			std::cout << y_int << " ";
		}
		std::cout << std::endl;
	}
}


int main()
{
	Matrix test(2, 5);
	test.print_matrix();
	std::cout << "test" << std::endl;
	return 0;
}
