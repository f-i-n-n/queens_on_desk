#include <iostream>
#include "check_queen.hpp"

using namespace std;

#define DECK_SIZE	(8)


bool insert_queen(int32_t* deck, int32_t x, int32_t y,int32_t numb)
{

	bool flag = false;
	int32_t i = 0,j = 0;

	if((x < DECK_SIZE) && (y < DECK_SIZE))
	{

		insert_value(&(deck[y*DECK_SIZE + x]),numb,"main insert");

        insert_vertical_value(deck,x,y,numb);
        insert_horizontal_value(deck,x,y,numb);
        insert_slash_diagonal_value(deck,x,y,numb);
        insert_backslash_diagonal_value(deck,x,y,numb);

	}

	return flag;
}


void print_deck(int32_t* deck)
{
	int32_t i = 0, j = 0;
	 
	 
	cout<<"******************"<<endl;

	for(i = 0; i < DECK_SIZE; ++i)
	{
		for(j = 0; j < DECK_SIZE; ++j)
		{
			cout<<deck[i*DECK_SIZE+j] << ' ';
		}

		cout<<endl;
	}

	cout<<"******************"<<endl;
}

// test function
void insert_value(int32_t* ptr, int32_t value,string message)
{
	ptr[0] += value;

	// 11 - my own test value. it's visible in "print_deck" function
	if(ptr[0] == 11) cout<<endl<<message<<endl;
}


void insert_vertical_value(int32_t* deck, int32_t x,int32_t y,int32_t numb)
{
    int32_t i = 0, j = 0;
    //insert vertical
    for(i=0;i<y; ++i)
    {
        insert_value(&(deck[i*DECK_SIZE + x]),numb,"insert vertical 1");
    }
    if(DECK_SIZE > (y+1))
    {
        for(i=y+1;i<DECK_SIZE; ++i)
        {
            insert_value(&(deck[i*DECK_SIZE + x]),numb,"insert vertical 2");
        }
    }
}


void insert_horizontal_value(int32_t* deck, int32_t x, int32_t y, int32_t numb)
{
    int32_t i = 0, j = 0;

    //insert horizontal
    for(i=0;i<x; ++i)
    {
        //deck[y*DECK_SIZE + i] += numb;
        insert_value(&(deck[y*DECK_SIZE + i]),numb,"horizontal insert 1");
    }
    if(DECK_SIZE > (x+1))
    {
        for(i=x+1;i<DECK_SIZE; ++i)
        {
 //           deck[y*DECK_SIZE + i] += numb;
            insert_value(&(deck[y*DECK_SIZE + i]),numb,"horizontal insert 2");
        }
    }
}

void insert_slash_diagonal_value(int32_t* deck, int32_t x, int32_t y, int32_t numb)
{
    int32_t i = 0, j = 0;

    //insert slash-diagonal
    i = y-1;j=x-1;
    while((i>=0) && (j >=0))
    {
 //       deck[i*DECK_SIZE + j] += numb;
        insert_value(&(deck[i*DECK_SIZE + j]),numb,"slash_diagonal insert 1");
        --i;
        --j;
    }
    i = y+1;j=x+1;
    while((i<DECK_SIZE) && (j <DECK_SIZE))
    {
 //       deck[i*DECK_SIZE + j] += numb;
        insert_value(&(deck[i*DECK_SIZE + j]),numb,"slash_diagonal insert 2");
        ++i;
        ++j;
    }

}

void insert_backslash_diagonal_value(int32_t* deck, int32_t x, int32_t y, int32_t numb)
{

    int32_t i = 0, j = 0;

    //insert backslash-diagonal
    i = y-1;j=x+1;
    while((i>=0) && (j <DECK_SIZE))
    {
 //       deck[i*DECK_SIZE + j] += numb;
        insert_value(&(deck[i*DECK_SIZE + j]),numb,"backslash_diagonal insert 1");
        --i;
        ++j;
    }
    i = y+1;j=x-1;
    while((i<DECK_SIZE) && (j >=0))
    {
//        deck[i*DECK_SIZE + j] += numb;
        insert_value(&(deck[i*DECK_SIZE + j]),numb,"backslash_diagonal insert 2");
        ++i;
        --j;
    }

}