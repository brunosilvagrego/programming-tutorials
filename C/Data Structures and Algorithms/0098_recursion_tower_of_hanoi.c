#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


// C recursive function to solve tower of hanoi puzzle
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
	{
		printf("\nMove disk 1 from rod %c to rod %c", from_rod, to_rod);

		return;
	}

	towerOfHanoi(n-1, from_rod, aux_rod, to_rod);

	printf("\nMove disk %d from rod %c to rod %c", n, from_rod, to_rod);

	towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
    // Number of disks
	int n = 3;

	// A, B and C are names of rods
	towerOfHanoi(n, 'A', 'C', 'B');

	return 0;
}
