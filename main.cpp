#include <iostream>

using namespace std;

#define N	(8)

bool insert_queen(int32_t* deck, int32_t x, int32_t y, int32_t numb);

void print_deck(int32_t* deck);


int main(void)
{
	int32_t deck[N][N];	

	int32_t i=0,j=0;

	for(i=0;i<N;++i)
	{
		for(j=0;j<N;++j)
		{
			deck[i][j] = 0;
		}
	}
	

	insert_queen((int32_t*)deck,0,0,1);
	insert_queen((int32_t*)deck,7,7,5);
    insert_queen((int32_t*)deck,3,2,3);

	print_deck((int32_t*)(deck));

	return 0;
}
