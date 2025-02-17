#include "helpers.h"
#include <math.h>
#include <stdio.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;
            int new = round((r + g + b)/3.0);
            image[i][j].rgbtRed = new;
            image[i][j].rgbtGreen = new;
            image[i][j].rgbtBlue = new;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;
            double sepiared = round(0.393 * r + 0.769 * g + 0.189 * b);
            double sepiagreen = round(0.349 * r + 0.686 * g + 0.168 * b);
            double sepiablue = round(0.272 * r + 0.534 * g + 0.131 * b);
            if (sepiared > 255)
            {
                sepiared = 255;
            }
            if (sepiagreen > 255)
            {
                sepiagreen = 255;
            }
            if (sepiablue > 255)
            {
                sepiablue = 255;
            }

            image[i][j].rgbtRed = sepiared;
            image[i][j].rgbtBlue = sepiablue;
            image[i][j].rgbtGreen = sepiagreen;
        }
    }
    return;


}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];

        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][width - j -1];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    float red,green,blue;
    for(int i = 0; i < height;i++)
    {
        for(int j = 0; j < width; j++)
        {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {

            if(i == 0 && j == 0) // top-left corner
            {
                // Average of 4 surrounding pixels including the pixel itself
                red = (float)((copy[i][j].rgbtRed + copy[i][j+1].rgbtRed +
                                       copy[i+1][j].rgbtRed + copy[i+1][j+1].rgbtRed)) / 4;
                green = (float)((copy[i][j].rgbtGreen + copy[i][j+1].rgbtGreen +
                                         copy[i+1][j].rgbtGreen + copy[i+1][j+1].rgbtGreen)) / 4;
                blue = (float)((copy[i][j].rgbtBlue + copy[i][j+1].rgbtBlue +
                                        copy[i+1][j].rgbtBlue + copy[i+1][j+1].rgbtBlue)) / 4;

                red = round(red);
				blue = round(blue);
				green = round(green);

                image[i][j].rgbtRed = red;
				image[i][j].rgbtGreen = green;
				image[i][j].rgbtBlue = blue;
            }
            else if(i == 0 && j == width - 1) // top-right corner
            {
                // Average of 4 surrounding pixels including the pixel itself
                red = (float)((copy[i][j-1].rgbtRed + copy[i][j].rgbtRed +
                                       copy[i+1][j-1].rgbtRed + copy[i+1][j].rgbtRed)) / 4;
                green = (float)((copy[i][j-1].rgbtGreen + copy[i][j].rgbtGreen +
                                         copy[i+1][j-1].rgbtGreen + copy[i+1][j].rgbtGreen)) / 4;
                blue = (float)((copy[i][j-1].rgbtBlue + copy[i][j].rgbtBlue +
                                        copy[i+1][j-1].rgbtBlue + copy[i+1][j].rgbtBlue) )/ 4;

                red = round(red);
				blue = round(blue);
				green = round(green);

                image[i][j].rgbtRed = red;
				image[i][j].rgbtGreen = green;
				image[i][j].rgbtBlue = blue;
                }
            else if(i == height - 1 && j == 0) // bottom-left corner
            {
                    // Average of 4 surrounding pixels including the pixel itself
                    red = (float)((copy[i-1][j].rgbtRed + copy[i-1][j+1].rgbtRed +
                                       copy[i][j].rgbtRed + copy[i][j+1].rgbtRed) )/ 4;
                    green = (float)((copy[i-1][j].rgbtGreen + copy[i-1][j+1].rgbtGreen +
                                         copy[i][j].rgbtGreen + copy[i][j+1].rgbtGreen) )/ 4;
                    blue = (float)((copy[i-1][j].rgbtBlue + copy[i-1][j+1].rgbtBlue +
                                        copy[i][j].rgbtBlue + copy[i][j+1].rgbtBlue) )/ 4;

                    red = round(red);
				    blue = round(blue);
				    green = round(green);

                    image[i][j].rgbtRed = red;
				    image[i][j].rgbtGreen = green;
				    image[i][j].rgbtBlue = blue;
            }
            else if(i == height - 1 && j == width - 1) // bottom-right corner
            {
                    // Average of 4 surrounding pixels including the pixel itself
                    red = (float)((copy[i-1][j-1].rgbtRed + copy[i-1][j].rgbtRed +
                                       copy[i][j-1].rgbtRed + copy[i][j].rgbtRed) )/ 4;
                    green = (float)((copy[i-1][j-1].rgbtGreen + copy[i-1][j].rgbtGreen +
                                         copy[i][j-1].rgbtGreen + copy[i][j].rgbtGreen)) / 4;
                    blue = (float)((copy[i-1][j-1].rgbtBlue + copy[i-1][j].rgbtBlue +
                                        copy[i][j-1].rgbtBlue + copy[i][j].rgbtBlue) )/ 4;

                    red = round(red);
				    blue = round(blue);
				    green = round(green);

                    image[i][j].rgbtRed = red;
				    image[i][j].rgbtGreen = green;
				    image[i][j].rgbtBlue = blue;
            }

            else if(i == 0 && (j > 0 && j < width - 1)) // top edge (excluding corners)
            {
                // Average of 6 surrounding pixels including the pixel itself
                red = (float)((copy[i][j-1].rgbtRed + copy[i][j].rgbtRed + copy[i][j+1].rgbtRed +
                                       copy[i+1][j-1].rgbtRed + copy[i+1][j].rgbtRed + copy[i+1][j+1].rgbtRed)) / 6;
                green = (float)((copy[i][j-1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j+1].rgbtGreen +
                                         copy[i+1][j-1].rgbtGreen + copy[i+1][j].rgbtGreen + copy[i+1][j+1].rgbtGreen) )/ 6;
                blue = (float)((copy[i][j-1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j+1].rgbtBlue +
                                        copy[i+1][j-1].rgbtBlue + copy[i+1][j].rgbtBlue + copy[i+1][j+1].rgbtBlue) )/ 6;

                red = round(red);
				blue = round(blue);
				green = round(green);

                image[i][j].rgbtRed = red;
				image[i][j].rgbtGreen = green;
				image[i][j].rgbtBlue = blue;
            }
            else if(i == height - 1 && (j > 0 && j < width - 1)) // bottom edge (excluding corners)
            {
                // Average of 6 surrounding pixels including the pixel itself
                red = (float)(copy[i-1][j-1].rgbtRed + copy[i-1][j].rgbtRed + copy[i-1][j+1].rgbtRed +
                                       copy[i][j-1].rgbtRed + copy[i][j].rgbtRed + copy[i][j+1].rgbtRed) / 6;
                green = (float)((copy[i-1][j-1].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i-1][j+1].rgbtGreen +
                                         copy[i][j-1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j+1].rgbtGreen)) / 6;
                blue = (float)((copy[i-1][j-1].rgbtBlue + copy[i-1][j].rgbtBlue + copy[i-1][j+1].rgbtBlue +
                                        copy[i][j-1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j+1].rgbtBlue)) / 6;

                red = round(red);
				blue = round(blue);
				green = round(green);

                image[i][j].rgbtRed = red;
				image[i][j].rgbtGreen = green;
				image[i][j].rgbtBlue = blue;
            }
            else if(j == 0 && (i > 0 && i < height - 1)) // left edge (excluding corners)
            {
                // Average of 6 surrounding pixels including the pixel itself
                red = (float)(copy[i-1][j].rgbtRed + copy[i-1][j+1].rgbtRed + copy[i][j].rgbtRed +
                                       copy[i][j+1].rgbtRed + copy[i+1][j].rgbtRed + copy[i+1][j+1].rgbtRed) / 6.0;
                green = (float)(copy[i-1][j].rgbtGreen + copy[i-1][j+1].rgbtGreen + copy[i][j].rgbtGreen +
                                         copy[i][j+1].rgbtGreen + copy[i+1][j].rgbtGreen + copy[i+1][j+1].rgbtGreen) / 6.0;
                blue = (float)(copy[i-1][j].rgbtBlue + copy[i-1][j+1].rgbtBlue + copy[i][j].rgbtBlue +
                                        copy[i][j+1].rgbtBlue + copy[i+1][j].rgbtBlue + copy[i+1][j+1].rgbtBlue) / 6.0;

                red = round(red);
				blue = round(blue);
				green = round(green);


                image[i][j].rgbtRed = red;
				image[i][j].rgbtGreen = green;
				image[i][j].rgbtBlue = blue;
            }
            else if(j == width - 1 && (i > 0 && i < height - 1)) // right edge (excluding corners)
            {
                // Average of 6 surrounding pixels including the pixel itself
                red = (float)(copy[i-1][j-1].rgbtRed + copy[i-1][j].rgbtRed + copy[i][j-1].rgbtRed +
                                       copy[i][j].rgbtRed + copy[i+1][j-1].rgbtRed + copy[i+1][j].rgbtRed) / 6.0;
                green = (float)(copy[i-1][j-1].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i][j-1].rgbtGreen +
                                         copy[i][j].rgbtGreen + copy[i+1][j-1].rgbtGreen + copy[i+1][j].rgbtGreen) / 6.0;
                blue = (float)(copy[i-1][j-1].rgbtBlue + copy[i-1][j].rgbtBlue + copy[i][j-1].rgbtBlue +
                                        copy[i][j].rgbtBlue + copy[i+1][j-1].rgbtBlue + copy[i+1][j].rgbtBlue) / 6.0;

                red = round(red);
				blue = round(blue);
				green = round(green);


                image[i][j].rgbtRed = red;
				image[i][j].rgbtGreen = green;
				image[i][j].rgbtBlue = blue;
            }
            else
            {
                red = (float)((copy[i-1][j-1].rgbtRed + copy[i-1][j].rgbtRed + copy[i-1][j+1].rgbtRed +
                                       copy[i][j-1].rgbtRed + copy[i][j].rgbtRed + copy[i][j+1].rgbtRed +
                                       copy[i+1][j-1].rgbtRed + copy[i+1][j].rgbtRed + copy[i+1][j+1].rgbtRed) )/ 9 ;
                green = (float)((copy[i-1][j-1].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i-1][j+1].rgbtGreen +
                                         copy[i][j-1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j+1].rgbtGreen +
                                         copy[i+1][j-1].rgbtGreen + copy[i+1][j].rgbtGreen + copy[i+1][j+1].rgbtGreen) )/ 9  ;
                blue = (float)((copy[i-1][j-1].rgbtBlue + copy[i-1][j].rgbtBlue + copy[i-1][j+1].rgbtBlue +
                                        copy[i][j-1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j+1].rgbtBlue +
                                        copy[i+1][j-1].rgbtBlue + copy[i+1][j].rgbtBlue + copy[i+1][j+1].rgbtBlue) )/ 9 ;

                red = round(red);
				blue = round(blue);
				green = round(green);

                image[i][j].rgbtRed = (red);
				image[i][j].rgbtGreen = (green);
				image[i][j].rgbtBlue = (blue);
            }

        }


   }
   return;
}
