#include "bitmap/bitmap_image.hpp"

int main()
{
	std::cout << "this is a test" << std::endl;

	bitmap_image image(200, 200);


	image.set_all_channels(255, 150, 50);

	image_drawer draw(image);
	
	draw.pen_width(3);
	draw.pen_color(255,0,0);
	draw.circle(image.width() / 2, image.height() / 2, 50);

	image.save_image("output.bmp");

	return 0;
}	
