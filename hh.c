#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
        for (int i=0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;
            //int average = round((float)image[i][j].rgbtBlue + (float)image[i][j].rgbtRed + (float)image[i][j].rgbtGreen)/ 3;
            int average = round((Red + Green + Blue)/3);
            image[i][j].rgbtBlue = image[i][j].rgbtRed = image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * (float)image[i][j].rgbtRed + .769 * (float)image[i][j].rgbtGreen  + .189 * (float)image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 *(float) image[i][j].rgbtRed + .686 *(float) image[i][j].rgbtGreen + .168 * (float)image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 *(float) image[i][j].rgbtRed + .534 * (float)image[i][j].rgbtGreen + .131 *(float) image[i][j].rgbtBlue);
        if (sepiaRed > 255)
        {
            sepiaRed = 255;
        }
        if (sepiaBlue > 255)
        {
            sepiaBlue = 255;
        }
        if (sepiaGreen > 255)
        {
            sepiaGreen = 255;
        }
        image[i][j].rgbtRed = sepiaRed;
        image[i][j].rgbtGreen = sepiaGreen;
        image[i][j].rgbtBlue = sepiaBlue;
        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j+1)];
            image[i][width - (j+1)] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    	RGBTRIPLE imgCopy[height][width];
	float newRed;
	float newGreen;
	float newBlue;

	//create a copy of original image to save original pixel values
	for (int row = 0; row < height; row++)
	{
		for (int w = 0; w < width; w++)
		{
			imgCopy[row][w].rgbtRed = image[row][w].rgbtRed;
			imgCopy[row][w].rgbtGreen = image[row][w].rgbtGreen;
			imgCopy[row][w].rgbtBlue = image[row][w].rgbtBlue;


		}
	}

	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			//if the pixel is on the top left edge (1)
			if (w == 0 && h == 0)
			{
				newRed = (float)(imgCopy[h][w].rgbtRed + imgCopy[h][w+1].rgbtRed + imgCopy[h+1][w].rgbtRed + imgCopy[h+1][w+1].rgbtRed) / 4;

				newGreen = (float)(imgCopy[h][w].rgbtGreen + imgCopy[h][w+1].rgbtGreen + imgCopy[h+1][w].rgbtGreen + imgCopy[h+1][w+1].rgbtGreen) / 4;

				newBlue = (float)(imgCopy[h][w].rgbtBlue + imgCopy[h][w+1].rgbtBlue + imgCopy[h+1][w].rgbtBlue + imgCopy[h+1][w+1].rgbtBlue) / 4;
				newRed = round(newRed);
				newBlue = round(newBlue);
				newGreen = round(newGreen);

				image[h][w].rgbtRed = newRed;
				image[h][w].rgbtGreen = newGreen;
				image[h][w].rgbtBlue = newBlue;
			}

			//if the pixel is on the lower left edge (2)
			else if (w == 0 && h == (height - 1))
			{
				newRed =(float)(imgCopy[h-1][w].rgbtRed + imgCopy[h-1][w+1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h][w+1].rgbtRed) / 4;

				newGreen = (float)(imgCopy[h-1][w].rgbtGreen + imgCopy[h-1][w+1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h][w+1].rgbtGreen) / 4;

				newBlue = (float)(imgCopy[h-1][w].rgbtBlue + imgCopy[h-1][w+1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h][w+1].rgbtBlue) / 4;
				newRed = round(newRed);
				newBlue = round(newBlue);
				newGreen = round(newGreen);

				image[h][w].rgbtRed = newRed;
				image[h][w].rgbtGreen = newGreen;
				image[h][w].rgbtBlue = newBlue;
			}

			//if the pixel is on top Right (3)
			else if (h == 0 && w == (width - 1))
			{
				newRed = (float)(imgCopy[h][w-1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h+1][w-1].rgbtRed + imgCopy[h+1][w].rgbtRed)/ 4;

				newGreen = (float)(imgCopy[h][w-1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h+1][w-1].rgbtGreen + imgCopy[h+1][w].rgbtGreen) / 4;

				newBlue = (float)(imgCopy[h][w-1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h+1][w-1].rgbtBlue + imgCopy[h+1][w].rgbtBlue) / 4;

				newRed = round(newRed);
				newBlue = round(newBlue);
				newGreen = round(newGreen);

				image[h][w].rgbtRed = newRed;
				image[h][w].rgbtGreen = newGreen;
				image[h][w].rgbtBlue = newBlue;
			}

			//if the pixel is on lower right (4)
			else if(h == (height - 1) && w == (width - 1))
			{
				newRed = (float)(imgCopy[h-1][w-1].rgbtRed + imgCopy[h-1][w].rgbtRed + imgCopy[h][w-1].rgbtRed + imgCopy[h][w].rgbtRed) / 4;

		 		newBlue = (float)(imgCopy[h-1][w-1].rgbtBlue + imgCopy[h-1][w].rgbtBlue + imgCopy[h][w-1].rgbtBlue + imgCopy[h][w].rgbtBlue) / 4;

				newGreen = (float)(imgCopy[h-1][w-1].rgbtGreen + imgCopy[h-1][w].rgbtGreen + imgCopy[h][w-1].rgbtGreen + imgCopy[h][w].rgbtGreen) / 4;

				newRed = round(newRed);
				newBlue = round(newBlue);
				newGreen = round(newGreen);

				image[h][w].rgbtRed = newRed;
				image[h][w].rgbtGreen = newGreen;
				image[h][w].rgbtBlue = newBlue;
			}
       //if the pixel is on left side (5)

			else if (w == 0 && (h > 0 && h < height - 1))
			{
				newRed = (float)(imgCopy[h-1][w].rgbtRed + imgCopy[h-1][w+1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h][w+1].rgbtRed + imgCopy[h+1][w].rgbtRed + imgCopy[h+1][w+1].rgbtRed) / 6;

				newGreen = (float)(imgCopy[h-1][w].rgbtGreen + imgCopy[h-1][w+1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h][w+1].rgbtGreen + imgCopy[h+1][w].rgbtGreen + imgCopy[h+1][w+1].rgbtGreen) / 6;

				newBlue = (float)(imgCopy[h-1][w].rgbtBlue + imgCopy[h-1][w+1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h][w+1].rgbtBlue + imgCopy[h+1][w].rgbtBlue + imgCopy[h+1][w+1].rgbtBlue) / 6;

				newRed = round(newRed);
				newBlue = round(newBlue);
				newGreen = round(newGreen);

				image[h][w].rgbtRed = newRed;
				image[h][w].rgbtGreen = newGreen;
				image[h][w].rgbtBlue = newBlue;
			}
      //if the pixel is on right side (6)
			else if (w == (width - 1) && (h > 0 && h < height - 1))
			{
			    newRed = (float)(imgCopy[h-1][w-1].rgbtRed + imgCopy[h-1][w].rgbtRed + imgCopy[h][w-1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h+1][w-1].rgbtRed + imgCopy[h+1][w].rgbtRed) / 6;

				newGreen = (float)(imgCopy[h-1][w-1].rgbtGreen + imgCopy[h-1][w].rgbtGreen + imgCopy[h][w-1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h+1][w-1].rgbtGreen + imgCopy[h+1][w].rgbtGreen) / 6;

				newBlue = (float)(imgCopy[h-1][w-1].rgbtBlue + imgCopy[h-1][w].rgbtBlue + imgCopy[h][w-1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h+1][w-1].rgbtBlue + imgCopy[h+1][w].rgbtBlue) / 6;

				newRed = round(newRed);
				newBlue = round(newBlue);
				newGreen = round(newGreen);

				image[h][w].rgbtRed = newRed;
				image[h][w].rgbtGreen = newGreen;
				image[h][w].rgbtBlue = newBlue;
			}
       //if the pixel is on upper side (7)
			else if (h == 0 && (w > 0 &&  w < width - 1))
			{
				newRed = (float)(imgCopy[h][w-1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h][w+1].rgbtRed + imgCopy[h+1][w-1].rgbtRed + imgCopy[h+1][w].rgbtRed + imgCopy[h+1][w+1].rgbtRed) / 6;

				newGreen = (float)(imgCopy[h][w-1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h][w+1].rgbtGreen + imgCopy[h+1][w-1].rgbtGreen + imgCopy[h+1][w].rgbtGreen + imgCopy[h+1][w+1].rgbtGreen) / 6;

				newBlue = (float)(imgCopy[h][w-1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h][w+1].rgbtBlue + imgCopy[h+1][w-1].rgbtBlue + imgCopy[h+1][w].rgbtBlue + imgCopy[h+1][w+1].rgbtBlue) / 6;

				newRed = round(newRed);
				newBlue = round(newBlue);
				newGreen = round(newGreen);

				image[h][w].rgbtRed = newRed;
				image[h][w].rgbtGreen = newGreen;
				image[h][w].rgbtBlue = newBlue;
			}
       //if the pixel is on lower side (8)
			else if  (h == height - 1 && (w > 0 && w < width - 1))
			{
				newRed = (float)(imgCopy[h-1][w-1].rgbtRed + imgCopy[h-1][w].rgbtRed + imgCopy[h-1][w+1].rgbtRed + imgCopy[h][w-1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h][w+1].rgbtRed) / 6;

				newGreen = (float)(imgCopy[h-1][w-1].rgbtGreen + imgCopy[h-1][w].rgbtGreen + imgCopy[h-1][w+1].rgbtGreen + imgCopy[h][w-1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h][w+1].rgbtGreen) / 6;
				newBlue = (float)(imgCopy[h-1][w-1].rgbtBlue + imgCopy[h-1][w].rgbtBlue + imgCopy[h-1][w+1].rgbtBlue + imgCopy[h][w-1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h][w+1].rgbtBlue) / 6;

				newRed = round(newRed);
				newBlue = round(newBlue);
				newGreen = round(newGreen);

				image[h][w].rgbtRed = newRed;
				image[h][w].rgbtGreen = newGreen;
				image[h][w].rgbtBlue = newBlue;
			}
      //if the pixel is on the middle and can form a 3x3 grid (9)
			else
			{
				newRed = (float)(imgCopy[h-1][w-1].rgbtRed + imgCopy[h-1][w].rgbtRed + imgCopy[h-1][w+1].rgbtRed + imgCopy[h][w-1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h][w+1].rgbtRed + imgCopy[h+1][w-1].rgbtRed + imgCopy[h+1][w].rgbtRed + imgCopy[h+1][w+1].rgbtRed) / 9;
				newGreen = (float)(imgCopy[h-1][w-1].rgbtGreen + imgCopy[h-1][w].rgbtGreen + imgCopy[h-1][w+1].rgbtGreen + imgCopy[h][w-1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h][w+1].rgbtGreen + imgCopy[h+1][w-1].rgbtGreen + imgCopy[h+1][w].rgbtGreen + imgCopy[h+1][w+1].rgbtGreen) / 9;

				newBlue = (float)(imgCopy[h-1][w-1].rgbtBlue + imgCopy[h-1][w].rgbtBlue + imgCopy[h-1][w+1].rgbtBlue + imgCopy[h][w-1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h][w+1].rgbtBlue + imgCopy[h+1][w-1].rgbtBlue + imgCopy[h+1][w].rgbtBlue + imgCopy[h+1][w+1].rgbtBlue) / 9;

				newRed = round(newRed);
				newBlue = round(newBlue);
				newGreen = round(newGreen);

				image[h][w].rgbtRed = newRed;
				image[h][w].rgbtGreen = newGreen;
				image[h][w].rgbtBlue = newBlue;
			}

		}
	}
    return;
}
