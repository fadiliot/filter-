
Filter Project (CS50)

Overview
---------
The Filter Project is a part of the CS50 course, which implements a system for applying different filters (like grayscale, sepia, and blur) to an image. The goal of the project is to gain hands-on experience in working with C programming, image manipulation, and understanding algorithms used for applying filters to images.

Features
--------
- Grayscale Filter: Converts the image to grayscale by averaging the red, green, and blue values of each pixel.
- Sepia Filter: Applies a sepia effect to the image by adjusting the red, green, and blue values of each pixel according to a specified formula.
- Blur Filter: Uses a blur algorithm to average the color of each pixel with its neighboring pixels.
- Edge Detection: Implements an edge detection filter using the Sobel operator to highlight the edges in an image.

Requirements
------------
- CS50 Library: This project uses the CS50 library for ease of reading inputs and handling basic image operations.
- C Compiler: The project is written in C, so you will need a C compiler (like `gcc`) to compile the source code.

Installation
------------
1. Clone this repository:
   git clone https://github.com/yourusername/cs50-filter.git

2. Navigate to the project directory:
   cd cs50-filter

3. Compile the program using the following command:
   make filter

Usage
------
Once compiled, you can run the program with the following command:

./filter <filter_type> <input_image> <output_image>

Where:
- <filter_type> can be one of: grayscale, sepia, blur, or edges.
- <input_image> is the path to the image you want to apply the filter to.
- <output_image> is the path where the resulting image will be saved.

Example
-------
./filter grayscale beach.jpg output_beach.jpg

This will apply the grayscale filter to beach.jpg and save the result as output_beach.jpg.

Testing
-------
You can test different filters on your images by specifying the filter type as shown in the usage section. The program will automatically apply the selected filter and save the output.

License
-------
This project is licensed under the MIT License - see the LICENSE file for details.


