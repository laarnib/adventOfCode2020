/*--- Day 1: Report Repair ---
After saving Christmas five years in a row, you've decided to take a vacation at a nice resort on a tropical island. Surely, Christmas will go on without you.

The tropical island has its own currency and is entirely cash-only. The gold coins used there have a little picture of a starfish; the locals just call them stars. None of the currency exchanges seem to have heard of them, but somehow, you'll need to find fifty of these coins by the time you arrive so you can pay the deposit on your room.

To save your vacation, you need to get all fifty stars by December 25th.

Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!

Before you leave, the Elves in accounting just need you to fix your expense report (your puzzle input); apparently, something isn't quite adding up.

Specifically, they need you to find the two entries that sum to 2020 and then multiply those two numbers together.

For example, suppose your expense report contained the following:

1721
979
366
299
675
1456
In this list, the two entries that sum to 2020 are 1721 and 299. Multiplying them together produces 1721 * 299 = 514579, so the correct answer is 514579.

Of course, your expense report is much larger. Find the two entries that sum to 2020; what do you get if you multiply them together?

--- Part Two ---
The Elves in accounting are thankful for your help; one of them even offers you a starfish coin they had left over from a past vacation. They offer you a second one if you can find three numbers in your expense report that meet the same criteria.

Using the above example again, the three entries that sum to 2020 are 979, 366, and 675. Multiplying them together produces the answer, 241861950.

In your expense report, what is the product of the three entries that sum to 2020?*/



#include<stdio.h>

//void findTwoEntriesOfTargetSum(int * inputArray, int arraySize);

int main(void)
{
	const int targetSum = 2020;
	int expenseEntry[250], i, sizeOfList, product;

	FILE * filePointer;

	filePointer = fopen("input.txt", "r");
	if (filePointer == NULL)
	{
		printf("File not found...\n");
	}
	
	// Read the list of numbers in the file and store it in an array
	i = 0;
	sizeOfList = 0;
	while (!feof(filePointer) || filePointer == NULL)
	{
		fscanf(filePointer, "%i", &expenseEntry[i]);
		i++;
		sizeOfList++;
	}

	fclose(filePointer);

	//findTwoEntriesOfTargetSum(expenseEntry, sizeOfList);
	// Traverse through the array until the target sum is found
	// Finds the two entries that sum up to the target sum
	for (int i = 0; i < sizeOfList; i++)
	{
		for(int j = i + 1; j < sizeOfList; j++)
		{
			if (expenseEntry[i] + expenseEntry[j] == targetSum)
			{
				product = expenseEntry[i] * expenseEntry[j];
			}
		}
	}
	printf("Product of two entries = %i\n", product);

	// Traverse through the array until the target sum is found
	// Finds the three entries that sum up to the target sum
	for (int i = 0; i < sizeOfList; i++)
	{
		for(int j = i + 1; j < sizeOfList; j++)
		{
			for (int k = j + 1; k < sizeOfList; k++)
			{
				if (expenseEntry[i] + expenseEntry[j] + expenseEntry[k] == targetSum)
				{
					product = expenseEntry[i] * expenseEntry[j] * expenseEntry[k];
				}
			}
		}
	}
	printf("Product of three entries = %i\n", product);

	return 0;
}

/*void findTwoEntriesOfTargetSum(int * inputArray, int arraySize)
{
	// Traverse through the array until the target sum is found
	for (int i = 0; i < arraySize; i++)
	{
		for(int j = i + 1; j < arraySize; j++)
		{
			if (*inputArray + expenseEntry[j] == targetSum)
			{
				product = expenseEntry[i] * expenseEntry[j];
			}
		}
	}
}*/