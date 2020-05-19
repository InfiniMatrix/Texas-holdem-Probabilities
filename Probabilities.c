#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/mman.h>
#include <time.h>

FILE * fp;

uint64_t i1, i2, i3, i4, i5, i6, i7, i8, i9;
uint64_t * Cards = NULL;
uint64_t expression1 = 0, expression2;
uint64_t * StraightFlush = NULL;
uint32_t k1 = 0, j2 = 378304/*IMPORTANT*/, j3, j4 = 0, j5 = 0;
uint64_t * FourOfAKind = NULL;
uint64_t * Flush = NULL;
uint64_t * Straight = NULL;
uint64_t * ThreeOfAKind = NULL;
uint64_t * OnePair = NULL;
uint64_t * FullHouse = NULL;
uint64_t * HighCard = NULL;
uint64_t * ThreeOfAKind_Extended = NULL;
uint64_t * TwoPair_Extended = NULL;
uint64_t * OnePair_Extended = NULL;
uint32_t * StraightFlush_Values = NULL;
uint32_t * FourOfAKind_Values = NULL;
uint32_t * FullHouse_Values = NULL;
uint32_t * Flush_Values = NULL;
uint32_t * Straight_Values = NULL;
uint32_t * ThreeOfAKind_Extended_Values = NULL;
uint32_t * TwoPair_Extended_Values = NULL;
uint32_t * OnePair_Extended_Values = NULL;
uint32_t * HighCard_Values = NULL;
uint64_t _5Hand;
uint32_t i10;
uint64_t _7Hand;
uint32_t HandEval_My7Hand, HandEval_Oppo7Hand;

//LexicographicalOrder_Probabilities
//_2Players
//LexicographicalOrder_2Players_River_Probabilities
uint16_t * LexicographicalOrder_2Players_River_W1Probabilities = NULL;
uint16_t * LexicographicalOrder_2Players_River_W2Probabilities = NULL;
uint16_t * LexicographicalOrder_2Players_River_LProbabilities = NULL;
//LexicographicalOrder_2Players_Turn_Probabilities
uint16_t * LexicographicalOrder_2Players_Turn_W1Probabilities = NULL;
uint16_t * LexicographicalOrder_2Players_Turn_W2Probabilities = NULL;
uint16_t * LexicographicalOrder_2Players_Turn_LProbabilities = NULL;
//LexicographicalOrder_2Players_Flop_Probabilities
uint32_t * LexicographicalOrder_2Players_Flop_W1Probabilities = NULL;
uint32_t * LexicographicalOrder_2Players_Flop_W2Probabilities = NULL;
uint32_t * LexicographicalOrder_2Players_Flop_LProbabilities = NULL;
//LexicographicalOrder_2Players_PreFlop_Probabilities
uint32_t * LexicographicalOrder_2Players_PreFlop_W1Probabilities = NULL;
uint32_t * LexicographicalOrder_2Players_PreFlop_W2Probabilities = NULL;
uint32_t * LexicographicalOrder_2Players_PreFlop_LProbabilities = NULL;

uint32_t main(void)
{
	//Cards
	fp = fopen("/home/<USER>/Poker/Probabilities/Cards.bin", "wb+");
	for(i1 = 1; i1 != 4503599627370496; i1 <<= 1)//1 << 52 = 4503599627370496
	{
		fwrite_unlocked(&i1, 8, 1, fp);
	}
	Cards = mmap(NULL, 416, PROT_READ, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	
	//Rankings
	//StraightFlush
	fp = fopen("/home/<USER>/Poker/Probabilities/Rankings/StraightFlush.bin", "wb+");
	for(i1 = 0; i1 != 40; ++i1)
	{
		fwrite_unlocked(&expression1, 8, 1, fp);
	}
	StraightFlush = mmap(NULL, 320, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	//'A K Q J 10' 'K Q J 10 9' 'Q J 10 9 8' 'J 10 9 8 7' '10 9 8 7 6' '9 8 7 6 5' '8 7 6 5 4' '7 6 5 4 3' '6 5 4 3 2'
	for(i1 = 0; i1 != 36; ++i1)
	{
		StraightFlush[k1++] = Cards[i1] | Cards[i1+4] | Cards[i1+8] | Cards[i1+12] | Cards[i1+16];
	}
	//'5 4 3 2 A'
	for(i1 = 0; i1 != 4; ++i1)
	{
		StraightFlush[k1++] = Cards[i1] | Cards[i1+36] | Cards[i1+40] | Cards[i1+44] | Cards[i1+48];
	}
	
	//FourOfAKind
	fp = fopen("/home/<USER>/Poker/Probabilities/Rankings/FourOfAKind.bin", "wb+");
	for(i1 = 0; i1 != 624; ++i1)
	{
		fwrite_unlocked(&expression1, 8, 1, fp);
	}
	FourOfAKind = mmap(NULL, 4992, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	//'A A A A' 'K K K K' 'Q Q Q Q' 'J J J J' '10 10 10 10' '9 9 9 9' '8 8 8 8' '7 7 7 7' '6 6 6 6' '5 5 5 5' '4 4 4 4' '3 3 3 3' '2 2 2 2'
	for(i1 = 0, k1 = 0; i1 != 52; i1 += 4)
	{
		for(i2 = 0; i2 != i1; ++i2)
		{
			FourOfAKind[k1++] = Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3] | Cards[i2];
		}
		for(i2 += 4; i2 != 52; ++i2)
		{
			FourOfAKind[k1++] = Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3] | Cards[i2];
		}
	}
	
	//Flush
	fp = fopen("/home/<USER>/Poker/Probabilities/Rankings/Flush.bin", "wb+");
	for(i1 = 0; i1 != 5108; ++i1)
	{
		fwrite_unlocked(&expression1, 8, 1, fp);
	}
	Flush = mmap(NULL, 40864, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	//To get all the C(13,5) = 1287 combinations of Ranks
	for(i1 = 0, k1 = 0; i1 != 36; i1 += 4)
	{
		for(i2 = i1; i2 != 36; i2 += 4)
		{
			for(i3 = i2; i3 != 36; i3 += 4)
			{
				for(i4 = i3; i4 != 36; i4 += 4)
				{
					for(i5 = i4; i5 != 36; i5 += 4)
					{
						expression1 = Cards[i1] | Cards[i2+4] | Cards[i3+8] | Cards[i4+12] | Cards[i5+16];
						//To remove all the 'StraightFlush'
						for(i6 = 0; i6 != 40; ++i6)
						{
							switch(expression1 - StraightFlush[i6])
							{
								default:
									break;
								case 0:
									goto Flush_End;
							}
						}
						//To get the 4 Suits, one adjacent to the other
						for(i6 = 0; i6 != 4; ++i6)
						{
							Flush[k1++] = Cards[i1+i6] | Cards[i2+4+i6] | Cards[i3+8+i6] | Cards[i4+12+i6] | Cards[i5+16+i6];
						}
						Flush_End: ;
					}
				}
			}
		}
	}
	
	expression1 = 0;
	
	//Straight
	fp = fopen("/home/<USER>/Poker/Probabilities/Rankings/Straight.bin", "wb+");
	for(i1 = 0; i1 != 10200; ++i1)
	{
		fwrite_unlocked(&expression1, 8, 1, fp);
	}
	Straight = mmap(NULL, 81600, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	//'A K Q J 10' 'K Q J 10 9' 'Q J 10 9 8' 'J 10 9 8 7' '10 9 8 7 6' '9 8 7 6 5' '8 7 6 5 4' '7 6 5 4 3' '6 5 4 3 2'
	for(i1 = 0, k1 = 0; i1 != 36; i1 += 4)
	{
		for(i2 = 0; i2 != 4; ++i2)
		{
			for(i3 = 0; i3 != 4; ++i3)
			{
				for(i4 = 0; i4 != 4; ++i4)
				{
					for(i5 = 0; i5 != 4; ++i5)
					{
						for(i6 = 0; i6 != 4; ++i6)
						{
							expression1 = Cards[i1+i2] | Cards[i1+4+i3] | Cards[i1+8+i4] | Cards[i1+12+i5] | Cards[i1+16+i6];
							//To remove all the 'StraightFlush'
							for(i7 = 0; i7 != 40; ++i7)
							{
								switch(expression1 - StraightFlush[i7])
								{
									default:
										break;
									case 0:
										goto Straight_End1;
								}
							}
							Straight[k1++] = expression1;
							Straight_End1: ;
						}
					}
				}
			}
		}
	}
	//'5 4 3 2 A'
	for(i1 = 0; i1 != 4; ++i1)
	{
		for(i2 = 0; i2 != 4; ++i2)
		{
			for(i3 = 0; i3 != 4; ++i3)
			{
				for(i4 = 0; i4 != 4; ++i4)
				{
					for(i5 = 0; i5 != 4; ++i5)
					{
						expression1 = Cards[i1] | Cards[36+i2] | Cards[40+i3] | Cards[44+i4] | Cards[48+i5];
						//To remove all the 'StraightFlush'
						for(i6 = 0; i6 != 40; ++i6)
						{
							switch(expression1 - StraightFlush[i6])
							{
								default:
									break;
								case 0:
									goto Straight_End2;
							}
						}
						Straight[k1++] = expression1;
						Straight_End2: ;
					}
				}
			}
		}
	}
	
	expression1 = 0;
	
	//ThreeOfAKind
	fp = fopen("/home/<USER>/Poker/Probabilities/Rankings/ThreeOfAKind.bin", "wb+");
	for(i1 = 0; i1 != 52; ++i1)
	{
		fwrite_unlocked(&expression1, 8, 1, fp);
	}
	ThreeOfAKind = mmap(NULL, 416, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	//'A A A' 'K K K' 'Q Q Q' 'J J J' '10 10 10' '9 9 9' '8 8 8' '7 7 7' '6 6 6' '5 5 5' '4 4 4' '3 3 3' '2 2 2'
	for(i1 = 0, k1 = 0; i1 != 52; i1 += 4)
	{
		//To get all the C(4,3) = 4 combinations of Suits
		ThreeOfAKind[k1++] = Cards[i1] | Cards[i1+1] | Cards[i1+2];
		ThreeOfAKind[k1++] = Cards[i1] | Cards[i1+1] | Cards[i1+3];
		ThreeOfAKind[k1++] = Cards[i1] | Cards[i1+2] | Cards[i1+3];
		ThreeOfAKind[k1++] = Cards[i1+1] | Cards[i1+2] | Cards[i1+3];
	}
	
	//OnePair
	fp = fopen("/home/<USER>/Poker/Probabilities/Rankings/OnePair.bin", "wb+");
	for(i1 = 0; i1 != 78; ++i1)
	{
		fwrite_unlocked(&expression1, 8, 1, fp);
	}
	OnePair = mmap(NULL, 624, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	//'A A' 'K K' 'Q Q' 'J J' '10 10' '9 9' '8 8' '7 7' '6 6' '5 5' '4 4' '3 3' '2 2'
	for(i1 = 0, k1 = 0; i1 != 52; i1 += 4)
	{
		//To get all the C(4,2) = 6 combinations of Suits
		OnePair[k1++] = Cards[i1] | Cards[i1+1];
		OnePair[k1++] = Cards[i1] | Cards[i1+2];
		OnePair[k1++] = Cards[i1] | Cards[i1+3];
		OnePair[k1++] = Cards[i1+1] | Cards[i1+2];
		OnePair[k1++] = Cards[i1+1] | Cards[i1+3];
		OnePair[k1++] = Cards[i1+2] | Cards[i1+3];
	}
	
	//ThreeOfAKind_Extended
	fp = fopen("/home/<USER>/Poker/Probabilities/Rankings/ThreeOfAKind_Extended.bin", "wb+");
	for(i1 = 0; i1 != 54912; ++i1)
	{
		fwrite_unlocked(&expression1, 8, 1, fp);
	}
	ThreeOfAKind_Extended = mmap(NULL, 439296, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	for(i1 = 0, k1 = 0; i1 != 52; i1 += 4)
	{
		expression1 = Cards[i1] | Cards[i1+1] | Cards[i1+2];
		for(i2 = 0; i2 != 51; ++i2)
		{
			switch(Cards[i2] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
			{
				case 0:
					for(i3 = i2 + 1; i3 != 52; ++i3)
					{
						switch(Cards[i3] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
						{
							case 0:
								expression2 = Cards[i2] | Cards[i3];
								for(i4 = 0; i4 != 78; ++i4)
								{
									switch(expression2 & ~OnePair[i4])
									{
										default:
											break;
										case 0:
											goto ThreeOfAKind_Extended_End1;
									}
								}
								ThreeOfAKind_Extended[k1++] = expression1 | expression2;
								ThreeOfAKind_Extended_End1: ;
								break;
							default:
								break;
						}
					}
				default:
					break;
			}
		}
		expression1 = Cards[i1] | Cards[i1+1] | Cards[i1+3];
		for(i2 = 0; i2 != 51; ++i2)
		{
			switch(Cards[i2] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
			{
				case 0:
					for(i3 = i2 + 1; i3 != 52; ++i3)
					{
						switch(Cards[i3] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
						{
							case 0:
								expression2 = Cards[i2] | Cards[i3];
								for(i4 = 0; i4 != 78; ++i4)
								{
									switch(expression2 & ~OnePair[i4])
									{
										default:
											break;
										case 0:
											goto ThreeOfAKind_Extended_End2;
									}
								}
								ThreeOfAKind_Extended[k1++] = expression1 | expression2;
								ThreeOfAKind_Extended_End2: ;
								break;
							default:
								break;
						}
					}
				default:
					break;
			}
		}
		expression1 = Cards[i1] | Cards[i1+2] | Cards[i1+3];
		for(i2 = 0; i2 != 51; ++i2)
		{
			switch(Cards[i2] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
			{
				case 0:
					for(i3 = i2 + 1; i3 != 52; ++i3)
					{
						switch(Cards[i3] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
						{
							case 0:
								expression2 = Cards[i2] | Cards[i3];
								for(i4 = 0; i4 != 78; ++i4)
								{
									switch(expression2 & ~OnePair[i4])
									{
										default:
											break;
										case 0:
											goto ThreeOfAKind_Extended_End3;
									}
								}
								ThreeOfAKind_Extended[k1++] = expression1 | expression2;
								ThreeOfAKind_Extended_End3: ;
								break;
							default:
								break;
						}
					}
				default:
					break;
			}
		}
		expression1 = Cards[i1+1] | Cards[i1+2] | Cards[i1+3];
		for(i2 = 0; i2 != 51; ++i2)
		{
			switch(Cards[i2] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
			{
				case 0:
					for(i3 = i2 + 1; i3 != 52; ++i3)
					{
						switch(Cards[i3] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
						{
							case 0:
								expression2 = Cards[i2] | Cards[i3];
								for(i4 = 0; i4 != 78; ++i4)
								{
									switch(expression2 & ~OnePair[i4])
									{
										default:
											break;
										case 0:
											goto ThreeOfAKind_Extended_End4;
									}
								}
								ThreeOfAKind_Extended[k1++] = expression1 | expression2;
								ThreeOfAKind_Extended_End4: ;
								break;
							default:
								break;
						}
					}
				default:
					break;
			}
		}
	}
	
	expression1 = 0;
	
	//OnePair_Extended
	fp = fopen("/home/<USER>/Poker/Probabilities/Rankings/OnePair_Extended.bin", "wb+");
	for(i1 = 0; i1 != 1098240; ++i1)
	{
		fwrite_unlocked(&expression1, 8, 1, fp);
	}
	OnePair_Extended = mmap(NULL, 8785920, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	for(i1 = 0, k1 = 0; i1 != 52; i1 += 4)
	{
		expression1 = Cards[i1] | Cards[i1+1];
		for(i2 = 0; i2 != 50; ++i2)
		{
			switch(Cards[i2] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
			{
				case 0:
					for(i3 = i2 + 1; i3 != 51; ++i3)
					{
						switch(Cards[i3] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
						{
							case 0:
								for(i4 = i3 + 1; i4 != 52; ++i4)
								{
									switch(Cards[i4] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
									{
										case 0:
											expression2 = Cards[i2] | Cards[i3] | Cards[i4];
											for(i5 = 0; i5 != 52; ++i5)
											{
												switch(expression2 & ~ThreeOfAKind[i5])
												{
													default:
														break;
													case 0:
														goto OnePair_Extended_End1;
												}
											}
											for(i5 = 0; i5 != 78; ++i5)
											{
												switch(OnePair[i5] & ~expression2)
												{
													default:
														break;
													case 0:
														goto OnePair_Extended_End1;
												}
											}
											OnePair_Extended[k1++] = expression1 | expression2;
											OnePair_Extended_End1: ;
											break;
										default:
											break;
									}
								}
							default:
								break;
						}
					}
				default:
					break;
			}
		}
		expression1 = Cards[i1] | Cards[i1+2];
		for(i2 = 0; i2 != 50; ++i2)
		{
			switch(Cards[i2] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
			{
				case 0:
					for(i3 = i2 + 1; i3 != 51; ++i3)
					{
						switch(Cards[i3] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
						{
							case 0:
								for(i4 = i3 + 1; i4 != 52; ++i4)
								{
									switch(Cards[i4] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
									{
										case 0:
											expression2 = Cards[i2] | Cards[i3] | Cards[i4];
											for(i5 = 0; i5 != 52; ++i5)
											{
												switch(expression2 & ~ThreeOfAKind[i5])
												{
													default:
														break;
													case 0:
														goto OnePair_Extended_End2;
												}
											}
											for(i5 = 0; i5 != 78; ++i5)
											{
												switch(OnePair[i5] & ~expression2)
												{
													default:
														break;
													case 0:
														goto OnePair_Extended_End2;
												}
											}
											OnePair_Extended[k1++] = expression1 | expression2;
											OnePair_Extended_End2: ;
											break;
										default:
											break;
									}
								}
							default:
								break;
						}
					}
				default:
					break;
			}
		}
		expression1 = Cards[i1] | Cards[i1+3];
		for(i2 = 0; i2 != 50; ++i2)
		{
			switch(Cards[i2] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
			{
				case 0:
					for(i3 = i2 + 1; i3 != 51; ++i3)
					{
						switch(Cards[i3] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
						{
							case 0:
								for(i4 = i3 + 1; i4 != 52; ++i4)
								{
									switch(Cards[i4] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
									{
										case 0:
											expression2 = Cards[i2] | Cards[i3] | Cards[i4];
											for(i5 = 0; i5 != 52; ++i5)
											{
												switch(expression2 & ~ThreeOfAKind[i5])
												{
													default:
														break;
													case 0:
														goto OnePair_Extended_End3;
												}
											}
											for(i5 = 0; i5 != 78; ++i5)
											{
												switch(OnePair[i5] & ~expression2)
												{
													default:
														break;
													case 0:
														goto OnePair_Extended_End3;
												}
											}
											OnePair_Extended[k1++] = expression1 | expression2;
											OnePair_Extended_End3: ;
											break;
										default:
											break;
									}
								}
							default:
								break;
						}
					}
				default:
					break;
			}
		}
		expression1 = Cards[i1+1] | Cards[i1+2];
		for(i2 = 0; i2 != 50; ++i2)
		{
			switch(Cards[i2] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
			{
				case 0:
					for(i3 = i2 + 1; i3 != 51; ++i3)
					{
						switch(Cards[i3] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
						{
							case 0:
								for(i4 = i3 + 1; i4 != 52; ++i4)
								{
									switch(Cards[i4] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
									{
										case 0:
											expression2 = Cards[i2] | Cards[i3] | Cards[i4];
											for(i5 = 0; i5 != 52; ++i5)
											{
												switch(expression2 & ~ThreeOfAKind[i5])
												{
													default:
														break;
													case 0:
														goto OnePair_Extended_End4;
												}
											}
											for(i5 = 0; i5 != 78; ++i5)
											{
												switch(OnePair[i5] & ~expression2)
												{
													default:
														break;
													case 0:
														goto OnePair_Extended_End4;
												}
											}
											OnePair_Extended[k1++] = expression1 | expression2;
											OnePair_Extended_End4: ;
											break;
										default:
											break;
									}
								}
							default:
								break;
						}
					}
				default:
					break;
			}
		}
		expression1 = Cards[i1+1] | Cards[i1+3];
		for(i2 = 0; i2 != 50; ++i2)
		{
			switch(Cards[i2] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
			{
				case 0:
					for(i3 = i2 + 1; i3 != 51; ++i3)
					{
						switch(Cards[i3] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
						{
							case 0:
								for(i4 = i3 + 1; i4 != 52; ++i4)
								{
									switch(Cards[i4] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
									{
										case 0:
											expression2 = Cards[i2] | Cards[i3] | Cards[i4];
											for(i5 = 0; i5 != 52; ++i5)
											{
												switch(expression2 & ~ThreeOfAKind[i5])
												{
													default:
														break;
													case 0:
														goto OnePair_Extended_End5;
												}
											}
											for(i5 = 0; i5 != 78; ++i5)
											{
												switch(OnePair[i5] & ~expression2)
												{
													default:
														break;
													case 0:
														goto OnePair_Extended_End5;
												}
											}
											OnePair_Extended[k1++] = expression1 | expression2;
											OnePair_Extended_End5: ;
											break;
										default:
											break;
									}
								}
							default:
								break;
						}
					}
				default:
					break;
			}
		}
		expression1 = Cards[i1+2] | Cards[i1+3];
		for(i2 = 0; i2 != 50; ++i2)
		{
			switch(Cards[i2] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
			{
				case 0:
					for(i3 = i2 + 1; i3 != 51; ++i3)
					{
						switch(Cards[i3] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
						{
							case 0:
								for(i4 = i3 + 1; i4 != 52; ++i4)
								{
									switch(Cards[i4] & (Cards[i1] | Cards[i1+1] | Cards[i1+2] | Cards[i1+3]))
									{
										case 0:
											expression2 = Cards[i2] | Cards[i3] | Cards[i4];
											for(i5 = 0; i5 != 52; ++i5)
											{
												switch(expression2 & ~ThreeOfAKind[i5])
												{
													default:
														break;
													case 0:
														goto OnePair_Extended_End6;
												}
											}
											for(i5 = 0; i5 != 78; ++i5)
											{
												switch(OnePair[i5] & ~expression2)
												{
													default:
														break;
													case 0:
														goto OnePair_Extended_End6;
												}
											}
											OnePair_Extended[k1++] = expression1 | expression2;
											OnePair_Extended_End6: ;
											break;
										default:
											break;
									}
								}
							default:
								break;
						}
					}
				default:
					break;
			}
		}
	}
	
	expression1 = 0;
	
	//FullHouse
	fp = fopen("/home/<USER>/Poker/Probabilities/Rankings/FullHouse.bin", "wb+");
	for(i1 = 0; i1 != 3744; ++i1)
	{
		fwrite_unlocked(&expression1, 8, 1, fp);
	}
	FullHouse = mmap(NULL, 29952, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	for(i1 = 0, k1 = 0; i1 != 52; i1 += 4)//Splitting the inner loop to avoid using a switch
	{
		for(i2 = 0; i2*2 != i1*3; i2 += 6)
		{
			FullHouse[k1++] = ThreeOfAKind[i1] | OnePair[i2];
			FullHouse[k1++] = ThreeOfAKind[i1] | OnePair[i2+1];
			FullHouse[k1++] = ThreeOfAKind[i1] | OnePair[i2+2];
			FullHouse[k1++] = ThreeOfAKind[i1] | OnePair[i2+3];
			FullHouse[k1++] = ThreeOfAKind[i1] | OnePair[i2+4];
			FullHouse[k1++] = ThreeOfAKind[i1] | OnePair[i2+5];
			FullHouse[k1++] = ThreeOfAKind[i1+1] | OnePair[i2];
			FullHouse[k1++] = ThreeOfAKind[i1+1] | OnePair[i2+1];
			FullHouse[k1++] = ThreeOfAKind[i1+1] | OnePair[i2+2];
			FullHouse[k1++] = ThreeOfAKind[i1+1] | OnePair[i2+3];
			FullHouse[k1++] = ThreeOfAKind[i1+1] | OnePair[i2+4];
			FullHouse[k1++] = ThreeOfAKind[i1+1] | OnePair[i2+5];
			FullHouse[k1++] = ThreeOfAKind[i1+2] | OnePair[i2];
			FullHouse[k1++] = ThreeOfAKind[i1+2] | OnePair[i2+1];
			FullHouse[k1++] = ThreeOfAKind[i1+2] | OnePair[i2+2];
			FullHouse[k1++] = ThreeOfAKind[i1+2] | OnePair[i2+3];
			FullHouse[k1++] = ThreeOfAKind[i1+2] | OnePair[i2+4];
			FullHouse[k1++] = ThreeOfAKind[i1+2] | OnePair[i2+5];
			FullHouse[k1++] = ThreeOfAKind[i1+3] | OnePair[i2];
			FullHouse[k1++] = ThreeOfAKind[i1+3] | OnePair[i2+1];
			FullHouse[k1++] = ThreeOfAKind[i1+3] | OnePair[i2+2];
			FullHouse[k1++] = ThreeOfAKind[i1+3] | OnePair[i2+3];
			FullHouse[k1++] = ThreeOfAKind[i1+3] | OnePair[i2+4];
			FullHouse[k1++] = ThreeOfAKind[i1+3] | OnePair[i2+5];
		}
		for(i2 += 6; i2 != 78; i2 += 6)
		{
			FullHouse[k1++] = ThreeOfAKind[i1] | OnePair[i2];
			FullHouse[k1++] = ThreeOfAKind[i1] | OnePair[i2+1];
			FullHouse[k1++] = ThreeOfAKind[i1] | OnePair[i2+2];
			FullHouse[k1++] = ThreeOfAKind[i1] | OnePair[i2+3];
			FullHouse[k1++] = ThreeOfAKind[i1] | OnePair[i2+4];
			FullHouse[k1++] = ThreeOfAKind[i1] | OnePair[i2+5];
			FullHouse[k1++] = ThreeOfAKind[i1+1] | OnePair[i2];
			FullHouse[k1++] = ThreeOfAKind[i1+1] | OnePair[i2+1];
			FullHouse[k1++] = ThreeOfAKind[i1+1] | OnePair[i2+2];
			FullHouse[k1++] = ThreeOfAKind[i1+1] | OnePair[i2+3];
			FullHouse[k1++] = ThreeOfAKind[i1+1] | OnePair[i2+4];
			FullHouse[k1++] = ThreeOfAKind[i1+1] | OnePair[i2+5];
			FullHouse[k1++] = ThreeOfAKind[i1+2] | OnePair[i2];
			FullHouse[k1++] = ThreeOfAKind[i1+2] | OnePair[i2+1];
			FullHouse[k1++] = ThreeOfAKind[i1+2] | OnePair[i2+2];
			FullHouse[k1++] = ThreeOfAKind[i1+2] | OnePair[i2+3];
			FullHouse[k1++] = ThreeOfAKind[i1+2] | OnePair[i2+4];
			FullHouse[k1++] = ThreeOfAKind[i1+2] | OnePair[i2+5];
			FullHouse[k1++] = ThreeOfAKind[i1+3] | OnePair[i2];
			FullHouse[k1++] = ThreeOfAKind[i1+3] | OnePair[i2+1];
			FullHouse[k1++] = ThreeOfAKind[i1+3] | OnePair[i2+2];
			FullHouse[k1++] = ThreeOfAKind[i1+3] | OnePair[i2+3];
			FullHouse[k1++] = ThreeOfAKind[i1+3] | OnePair[i2+4];
			FullHouse[k1++] = ThreeOfAKind[i1+3] | OnePair[i2+5];
		}
	}
	
	//TwoPair_Extended
	fp = fopen("/home/<USER>/Poker/Probabilities/Rankings/TwoPair_Extended.bin", "wb+");
	for(i1 = 0; i1 != 123552; ++i1)
	{
		fwrite_unlocked(&expression1, 8, 1, fp);
	}
	TwoPair_Extended = mmap(NULL, 988416, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	for(i1 = 0, k1 = 0; i1 != 78; i1 += 6)
	{
		for(i2 = i1 + 6; i2 != 78; i2 += 6)
		{
			expression1 = OnePair[i1] | OnePair[i2];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1] | OnePair[i2+1];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1] | OnePair[i2+2];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1] | OnePair[i2+3];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1] | OnePair[i2+4];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1] | OnePair[i2+5];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+1] | OnePair[i2];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+1] | OnePair[i2+1];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+1] | OnePair[i2+2];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+1] | OnePair[i2+3];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+1] | OnePair[i2+4];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+1] | OnePair[i2+5];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+2] | OnePair[i2];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+2] | OnePair[i2+1];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+2] | OnePair[i2+2];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+2] | OnePair[i2+3];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+2] | OnePair[i2+4];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+2] | OnePair[i2+5];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+3] | OnePair[i2];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+3] | OnePair[i2+1];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+3] | OnePair[i2+2];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+3] | OnePair[i2+3];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+3] | OnePair[i2+4];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+3] | OnePair[i2+5];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+4] | OnePair[i2];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+4] | OnePair[i2+1];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+4] | OnePair[i2+2];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+4] | OnePair[i2+3];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+4] | OnePair[i2+4];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+4] | OnePair[i2+5];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+5] | OnePair[i2];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+5] | OnePair[i2+1];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+5] | OnePair[i2+2];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+5] | OnePair[i2+3];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+5] | OnePair[i2+4];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
			expression1 = OnePair[i1+5] | OnePair[i2+5];
			for(i3 = 0; i3 != 52; ++i3)
			{
				switch(Cards[i3] & (OnePair[i1] | OnePair[i1+5] | OnePair[i2] | OnePair[i2+5]))
				{
					case 0:
						TwoPair_Extended[k1++] = expression1 | Cards[i3];
						break;
					default:
						break;
				}
			}
		}
	}
	
	expression1 = 0;
	
	//HighCard
	fp = fopen("/home/<USER>/Poker/Probabilities/Rankings/HighCard.bin", "wb+");
	for(i1 = 0; i1 != 1302540; ++i1)
	{
		fwrite_unlocked(&expression1, 8, 1, fp);
	}
	HighCard = mmap(NULL, 10420320, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	//To get all the C(52,5) = 2598960 combinations of _5Hand
	for(i1 = 0, k1 = 0, j3 = 0; i1 != 48; ++i1)
	{
		for(i2 = i1 + 1; i2 != 49; ++i2)
		{
			for(i3 = i2 + 1; i3 != 50; ++i3)
			{
				for(i4 = i3 + 1; i4 != 51; ++i4)
				{
					for(i5 = i4 + 1; i5 != 52; ++i5)
					{
						_5Hand = Cards[i1] | Cards[i2] | Cards[i3] | Cards[i4] | Cards[i5];
						for(i6 = 0; i6 != 40; ++i6)
						{
							switch(StraightFlush[i6] & ~_5Hand)
							{
								default:
									break;
								case 0:
									goto HighCard_End;
							}
						}
						for(i6 = 0; i6 != 624; ++i6)
						{
							switch(FourOfAKind[i6] & ~_5Hand)
							{
								default:
									break;
								case 0:
									goto HighCard_End;
							}
						}
						for(i6 = 0; i6 != 3744; ++i6)
						{
							switch(FullHouse[i6] & ~_5Hand)
							{
								default:
									break;
								case 0:
									goto HighCard_End;
							}
						}
						for(i6 = 0; i6 != 5108; ++i6)
						{
							switch(Flush[i6] & ~_5Hand)
							{
								default:
									break;
								case 0:
									goto HighCard_End;
							}
						}
						for(i6 = 0; i6 != 10200; ++i6)
						{
							switch(Straight[i6] & ~_5Hand)
							{
								default:
									break;
								case 0:
									goto HighCard_End;
							}
						}
						for(i6 = 0; i6 != 54912; ++i6)
						{
							switch(ThreeOfAKind_Extended[i6] & ~_5Hand)
							{
								default:
									break;
								case 0:
									goto HighCard_End;
							}
						}
						for(i6 = 0; i6 != 123552; ++i6)
						{
							switch(TwoPair_Extended[i6] & ~_5Hand)
							{
								default:
									break;
								case 0:
									goto HighCard_End;
							}
						}
						for(i6 = 0; i6 != 1098240; ++i6)
						{
							switch(OnePair_Extended[i6] & ~_5Hand)
							{
								default:
									break;
								case 0:
									goto HighCard_End;
							}
						}
						HighCard[k1++] = _5Hand;
						HighCard_End: ;
					}
				}
			}
		}
	}
	
	
	//RankingValues
	//StraightFlush_Values
	fp = fopen("/home/<USER>/Poker/Probabilities/RankingValues/StraightFlush_Values.bin", "wb+");
	for(i1 = 0; i1 != 40; ++i1)
	{
		fwrite_unlocked(&expression1, 4, 1, fp);
	}
	StraightFlush_Values = mmap(NULL, 160, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	for(i1 = 0; i1 != 40; ++i1)
	{
		StraightFlush_Values[i1] = --j2;
		StraightFlush_Values[++i1] = j2;
		StraightFlush_Values[++i1] = j2;
		StraightFlush_Values[++i1] = j2;
	}
	
	//FourOfAKind_Values
	fp = fopen("/home/<USER>/Poker/Probabilities/RankingValues/FourOfAKind_Values.bin", "wb+");
	for(i1 = 0; i1 != 624; ++i1)
	{
		fwrite_unlocked(&expression1, 4, 1, fp);
	}
	FourOfAKind_Values = mmap(NULL, 2496, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	for(i1 = 0; i1 != 624; ++i1)
	{
		FourOfAKind_Values[i1] = --j2;
		FourOfAKind_Values[++i1] = j2;
		FourOfAKind_Values[++i1] = j2;
		FourOfAKind_Values[++i1] = j2;
	}
	
	//FullHouse_Values
	fp = fopen("/home/<USER>/Poker/Probabilities/RankingValues/FullHouse_Values.bin", "wb+");
	for(i1 = 0; i1 != 3744; ++i1)
	{
		fwrite_unlocked(&expression1, 4, 1, fp);
	}
	FullHouse_Values = mmap(NULL, 14976, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	for(i1 = 0, k1 = 0; i1 != 156; ++i1)
	{
		--j2;
		for(i2 = 0; i2 != 24; ++i2)
		{
			FullHouse_Values[k1++] = j2;
		}
	}
	
	//Flush_Values
	fp = fopen("/home/<USER>/Poker/Probabilities/RankingValues/Flush_Values.bin", "wb+");
	for(i1 = 0; i1 != 5108; ++i1)
	{
		fwrite_unlocked(&expression1, 4, 1, fp);
	}
	Flush_Values = mmap(NULL, 20432, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	for(i1 = 0; i1 != 5108; ++i1)
	{
		Flush_Values[i1] = --j2;
		Flush_Values[++i1] = j2;
		Flush_Values[++i1] = j2;
		Flush_Values[++i1] = j2;
	}
	
	//Straight_Values
	fp = fopen("/home/<USER>/Poker/Probabilities/RankingValues/Straight_Values.bin", "wb+");
	for(i1 = 0; i1 != 10200; ++i1)
	{
		fwrite_unlocked(&expression1, 4, 1, fp);
	}
	Straight_Values = mmap(NULL, 40800, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	for(i1 = 0; i1 != 10200;)
	{
		--j2;
		for(i2 = 0; i2 != 1020; ++i2)
		{
			Straight_Values[i1++] = j2;
		}
	}
	
	//ThreeOfAKind_Extended_Values
	fp = fopen("/home/<USER>/Poker/Probabilities/RankingValues/ThreeOfAKind_Extended_Values.bin", "wb+");
	for(i1 = 0; i1 != 54912; ++i1)
	{
		fwrite_unlocked(&expression1, 4, 1, fp);
	}
	ThreeOfAKind_Extended_Values = mmap(NULL, 219648, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	for(i1 = 0, k1 = 0; i1 != 13; ++i1)
	{
		for(i2 = 0; i2 != 4; ++i2)
		{
			j3 = j2;
			for(i3 = 0; i3 != 264; ++i3)
			{
				ThreeOfAKind_Extended_Values[k1++] = --j3;
				ThreeOfAKind_Extended_Values[k1++] = j3;
				ThreeOfAKind_Extended_Values[k1++] = j3;
				ThreeOfAKind_Extended_Values[k1++] = j3;
			}
		}
		j2 = j3;
	}
	
	//TwoPair_Extended_Values
	fp = fopen("/home/<USER>/Poker/Probabilities/RankingValues/TwoPair_Extended_Values.bin", "wb+");
	for(i1 = 0; i1 != 123552; ++i1)
	{
		fwrite_unlocked(&expression1, 4, 1, fp);
	}
	TwoPair_Extended_Values = mmap(NULL, 494208, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	for(i1 = 0, k1 = 0; i1 != 78; ++i1)
	{
		for(i2 = 0; i2 != 36; ++i2)
		{
			j3 = j2;
			for(i3 = 0; i3 != 11; ++i3)
			{
				TwoPair_Extended_Values[k1++] = --j3;
				TwoPair_Extended_Values[k1++] = j3;
				TwoPair_Extended_Values[k1++] = j3;
				TwoPair_Extended_Values[k1++] = j3;
			}
		}
		j2 = j3;
	}
	
	//OnePair_Extended_Values
	fp = fopen("/home/<USER>/Poker/Probabilities/RankingValues/OnePair_Extended_Values.bin", "wb+");
	for(i1 = 0; i1 != 1098240; ++i1)
	{
		fwrite_unlocked(&expression1, 4, 1, fp);
	}
	OnePair_Extended_Values = mmap(NULL, 4392960, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	for(i1 = 0, k1 = 0; i1 != 13; ++i1)
	{
		for(i2 = 0; i2 != 6; ++i2)
		{
			j3 = j2;
			for(i3 = 0; i3 != 3520; ++i3)
			{
				OnePair_Extended_Values[k1++] = --j3;
				OnePair_Extended_Values[k1++] = j3;
				OnePair_Extended_Values[k1++] = j3;
				OnePair_Extended_Values[k1++] = j3;
			}
		}
		j2 = j3;
	}
	
	//HighCard_Values
	fp = fopen("/home/<USER>/Poker/Probabilities/RankingValues/HighCard_Values.bin", "wb+");
	for(i1 = 0; i1 != 1302540; ++i1)
	{
		fwrite_unlocked(&expression1, 4, 1, fp);
	}
	HighCard_Values = mmap(NULL, 5210160, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	for(i1 = 0; i1 != 1302540; ++i1)
	{
		HighCard_Values[i1] = --j2;
		HighCard_Values[++i1] = j2;
		HighCard_Values[++i1] = j2;
		HighCard_Values[++i1] = j2;
	}
	
	printf("PRECOMPUTATION FINISHED, ENTERING THE MAIN ALGORITHM");
	getchar_unlocked();
	
	//LexicographicalOrder_2Players_River_Probabilities
	fp = fopen("/home/<USER>/Poker/Probabilities/LexicographicalOrder/_2Players/River/LexicographicalOrder_2Players_River_W1Probabilities/LexicographicalOrder_2Players_River_W1Probabilities.bin", "wb+");
	for(i1 = 0; i1 != 2809475760; ++i1)
	{
		fwrite_unlocked(&expression1, 2, 1, fp);
	}
	LexicographicalOrder_2Players_River_W1Probabilities = mmap(NULL, 5618951520, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	
	fp = fopen("/home/<USER>/Poker/Probabilities/LexicographicalOrder/_2Players/River/LexicographicalOrder_2Players_River_W2Probabilities/LexicographicalOrder_2Players_River_W2Probabilities.bin", "wb+");
	for(i1 = 0; i1 != 2809475760; ++i1)
	{
		fwrite_unlocked(&expression1, 2, 1, fp);
	}
	LexicographicalOrder_2Players_River_W2Probabilities = mmap(NULL, 5618951520, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	
	fp = fopen("/home/<USER>/Poker/Probabilities/LexicographicalOrder/_2Players/River/LexicographicalOrder_2Players_River_LProbabilities/LexicographicalOrder_2Players_River_LProbabilities.bin", "wb+");
	for(i1 = 0; i1 != 2809475760; ++i1)
	{
		fwrite_unlocked(&expression1, 2, 1, fp);
	}
	LexicographicalOrder_2Players_River_LProbabilities = mmap(NULL, 5618951520, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	
	//Linux specific benchmark
	struct timespec StartTime, StopTime;
	clock_gettime(CLOCK_MONOTONIC_RAW, &StartTime);//Start
	//Linux specific benchmark
	
	for(i1 = 0, k1 = 0, j2 = 0, j3 = 0, j4 = 0; i1 != 51; ++i1)
	{
		for(i2 = i1 + 1; i2 != 52; ++i2)
		{
			for(i3 = 0; i3 != 48; ++i3)
			{
				switch((i3 - i1) & (i3 - i2))//Check if '((i3 & ~i1) & (i3 & ~i2))' or even '((i3 != i1) & (i3 != i2))' are faster alternatives
				{
					default:
						for(i4 = i3 + 1; i4 != 49; ++i4)
						{
							switch((i4 - i1) & (i4 - i2))
							{
								default:
									for(i5 = i4 + 1; i5 != 50; ++i5)
									{
										switch((i5 - i1) & (i5 - i2))
										{
											default:
												for(i6 = i5 + 1; i6 != 51; ++i6)
												{
													switch((i6 - i1) & (i6 - i2))
													{
														default:
															for(i7 = i6 + 1; i7 != 52; ++i7)
															{
																switch((i7 - i1) & (i7 - i2))
																{
																	default:
																		for(i8 = 0; i8 != 51; ++i8)
																		{
																			switch((i8 - i1) & (i8 - i2) & (i8 - i3) & (i8 - i4) & (i8 - i5) & (i8 - i6) & (i8 - i7))
																			{
																				default:
																					for(i9 = i8 + 1; i9 != 52; ++i9)
																					{
																						switch((i9 - i1) & (i9 - i2) & (i9 - i3) & (i9 - i4) & (i9 - i5) & (i9 - i6) & (i9 - i7))
																						{
																							default:
																								//HandEval_My7Hand
																								_7Hand = Cards[i1] | Cards[i2] | Cards[i5] | Cards[i6] | Cards[i7] | Cards[i8] | Cards[i9];
																								//StraightFlush
																								for(i10 = 0; i10 != 40; ++i10)
																								{
																									switch(StraightFlush[i10] & ~_7Hand)
																									{
																										default:
																											break;
																										case 0:
																											//printf("My_7Hand is StraightFlush.\n");
																											HandEval_My7Hand = StraightFlush_Values[i10];
																											goto HandEval_My7Hand_End;
																									}
																								}
																								//FourOfAKind
																								for(i10 = 0; i10 != 624; ++i10)
																								{
																									switch(FourOfAKind[i10] & ~_7Hand)
																									{
																										default:
																											break;
																										case 0:
																											//printf("My_7Hand is FourOfAKind.\n");
																											HandEval_My7Hand = FourOfAKind_Values[i10];
																											goto HandEval_My7Hand_End;
																									}
																								}
																								//FullHouse
																								for(i10 = 0; i10 != 3744; ++i10)
																								{
																									switch(FullHouse[i10] & ~_7Hand)
																									{
																										default:
																											break;
																										case 0:
																											//printf("My_7Hand is FullHouse.\n");
																											HandEval_My7Hand = FullHouse_Values[i10];
																											goto HandEval_My7Hand_End;
																									}
																								}
																								//Flush
																								for(i10 = 0; i10 != 5108; ++i10)
																								{
																									switch(Flush[i10] & ~_7Hand)
																									{
																										default:
																											break;
																										case 0:
																											//printf("My_7Hand is Flush.\n");
																											HandEval_My7Hand = Flush_Values[i10];
																											goto HandEval_My7Hand_End;
																									}
																								}
																								//Straight
																								for(i10 = 0; i10 != 10200; ++i10)
																								{
																									switch(Straight[i10] & ~_7Hand)
																									{
																										default:
																											break;
																										case 0:
																											//printf("My_7Hand is Straight.\n");
																											HandEval_My7Hand = Straight_Values[i10];
																											goto HandEval_My7Hand_End;
																									}
																								}
																								//ThreeOfAKind_Extended
																								for(i10 = 0; i10 != 54912; ++i10)
																								{
																									switch(ThreeOfAKind_Extended[i10] & ~_7Hand)
																									{
																										default:
																											break;
																										case 0:
																											//printf("My_7Hand is ThreeOfAKind_Extended.\n");
																											HandEval_My7Hand = ThreeOfAKind_Extended_Values[i10];
																											goto HandEval_My7Hand_End;
																									}
																								}
																								//TwoPair_Extended
																								for(i10 = 0; i10 != 123552; ++i10)
																								{
																									switch(TwoPair_Extended[i10] & ~_7Hand)
																									{
																										default:
																											break;
																										case 0:
																											//printf("My_7Hand is TwoPair_Extended.\n");
																											HandEval_My7Hand = TwoPair_Extended_Values[i10];
																											goto HandEval_My7Hand_End;
																									}
																								}
																								//OnePair_Extended
																								for(i10 = 0; i10 != 1098240; ++i10)
																								{
																									switch(OnePair_Extended[i10] & ~_7Hand)
																									{
																										default:
																											break;
																										case 0:
																											//printf("My_7Hand is OnePair_Extended.\n");
																											HandEval_My7Hand = OnePair_Extended_Values[i10];
																											goto HandEval_My7Hand_End;
																									}
																								}
																								//HighCard
																								for(i10 = 0; i10 != 1302540; ++i10)
																								{
																									switch(HighCard[i10] & ~_7Hand)
																									{
																										default:
																											break;
																										case 0:
																											//printf("My_7Hand is HighCard.\n");
																											HandEval_My7Hand = HighCard_Values[i10];
																											goto HandEval_My7Hand_End;
																									}
																								}
																								HandEval_My7Hand_End: ;
																								
																								
																								//HandEval_Oppo7Hand
																								_7Hand = Cards[i3] | Cards[i4] | Cards[i5] | Cards[i6] | Cards[i7] | Cards[i8] | Cards[i9];
																								//StraightFlush
																								for(i10 = 0; i10 != 40; ++i10)
																								{
																									switch(StraightFlush[i10] & ~_7Hand)
																									{
																										default:
																											break;
																										case 0:
																											//printf("Oppo_7Hand is StraightFlush.\n");
																											HandEval_Oppo7Hand = StraightFlush_Values[i10];
																											goto HandEval_Oppo7Hand_End;
																									}
																								}
																								//FourOfAKind
																								for(i10 = 0; i10 != 624; ++i10)
																								{
																									switch(FourOfAKind[i10] & ~_7Hand)
																									{
																										default:
																											break;
																										case 0:
																											//printf("Oppo_7Hand is FourOfAKind.\n");
																											HandEval_Oppo7Hand = FourOfAKind_Values[i10];
																											goto HandEval_Oppo7Hand_End;
																									}
																								}
																								//FullHouse
																								for(i10 = 0; i10 != 3744; ++i10)
																								{
																									switch(FullHouse[i10] & ~_7Hand)
																									{
																										default:
																											break;
																										case 0:
																											//printf("Oppo_7Hand is FullHouse.\n");
																											HandEval_Oppo7Hand = FullHouse_Values[i10];
																											goto HandEval_Oppo7Hand_End;
																									}
																								}
																								//Flush
																								for(i10 = 0; i10 != 5108; ++i10)
																								{
																									switch(Flush[i10] & ~_7Hand)
																									{
																										default:
																											break;
																										case 0:
																											//printf("Oppo_7Hand is Flush.\n");
																											HandEval_Oppo7Hand = Flush_Values[i10];
																											goto HandEval_Oppo7Hand_End;
																									}
																								}
																								//Straight
																								for(i10 = 0; i10 != 10200; ++i10)
																								{
																									switch(Straight[i10] & ~_7Hand)
																									{
																										default:
																											break;
																										case 0:
																											//printf("Oppo_7Hand is Straight.\n");
																											HandEval_Oppo7Hand = Straight_Values[i10];
																											goto HandEval_Oppo7Hand_End;
																									}
																								}
																								//ThreeOfAKind_Extended
																								for(i10 = 0; i10 != 54912; ++i10)
																								{
																									switch(ThreeOfAKind_Extended[i10] & ~_7Hand)
																									{
																										default:
																											break;
																										case 0:
																											//printf("Oppo_7Hand is ThreeOfAKind_Extended.\n");
																											HandEval_Oppo7Hand = ThreeOfAKind_Extended_Values[i10];
																											goto HandEval_Oppo7Hand_End;
																									}
																								}
																								//TwoPair_Extended
																								for(i10 = 0; i10 != 123552; ++i10)
																								{
																									switch(TwoPair_Extended[i10] & ~_7Hand)
																									{
																										default:
																											break;
																										case 0:
																											//printf("Oppo_7Hand is TwoPair_Extended.\n");
																											HandEval_Oppo7Hand = TwoPair_Extended_Values[i10];
																											goto HandEval_Oppo7Hand_End;
																									}
																								}
																								//OnePair_Extended
																								for(i10 = 0; i10 != 1098240; ++i10)
																								{
																									switch(OnePair_Extended[i10] & ~_7Hand)
																									{
																										default:
																											break;
																										case 0:
																											//printf("Oppo_7Hand is OnePair_Extended.\n");
																											HandEval_Oppo7Hand = OnePair_Extended_Values[i10];
																											goto HandEval_Oppo7Hand_End;
																									}
																								}
																								//HighCard
																								for(i10 = 0; i10 != 1302540; ++i10)
																								{
																									switch(HighCard[i10] & ~_7Hand)
																									{
																										default:
																											break;
																										case 0:
																											//printf("Oppo_7Hand is HighCard.\n");
																											HandEval_Oppo7Hand = HighCard_Values[i10];
																											goto HandEval_Oppo7Hand_End;
																									}
																								}
																								HandEval_Oppo7Hand_End: ;
																								
																								if(HandEval_My7Hand > HandEval_Oppo7Hand)
																								{
																									++LexicographicalOrder_2Players_River_W1Probabilities[k1];
																									//printf("I win!\n");
																								}
																								else if(HandEval_My7Hand == HandEval_Oppo7Hand)
																								{
																									++LexicographicalOrder_2Players_River_W2Probabilities[k1];
																									//printf("We split!\n");
																								}
																								else
																								{
																									++LexicographicalOrder_2Players_River_LProbabilities[k1];
																									//printf("I lose!\n");
																								}
																								
																								//getchar_unlocked();
																								
																								HandEval_My7Hand = 0;
																								HandEval_Oppo7Hand = 0;
																								break;
																							case 0:
																								break;
																						}
																					}
																					break;
																				case 0:
																					break;
																			}
																		}
																		++k1;
																		break;
																	case 0:
																		break;
																}
															}
															break;
														case 0:
															break;
													}
												}
												break;
											case 0:
												break;
										}
									}
									break;
								case 0:
									break;
							}
						}
						break;
					case 0:
						break;
				}
			}
		}
	}*/
	munmap(Cards, 416);
	munmap(StraightFlush, 320);
	munmap(StraightFlush_Values, 160);
	munmap(FourOfAKind, 104);
	munmap(FourOfAKind_Values, 52);
	munmap(FullHouse, 29952);
	munmap(FullHouse_Values, 14976);
	munmap(Flush, 40864);
	munmap(Flush_Values, 20432);
	munmap(Straight, 81600);
	munmap(Straight_Values, 40800);
	munmap(ThreeOfAKind, 416);
	munmap(ThreeOfAKind_Extended, 439296);
	munmap(ThreeOfAKind_Extended_Values, 219648);
	munmap(TwoPair_Extended, 123552);
	munmap(TwoPair_Extended_Values, 494208);
	munmap(OnePair, 624);
	munmap(OnePair_Extended, 1098240);
	munmap(OnePair_Extended_Values, 4392960);
	munmap(HighCard, 10420320);
	munmap(HighCard_Values, 5210160);
	
	//LexicographicalOrder_Probabilities
	//_2Players
	//LexicographicalOrder_2Players_Turn_Probabilities
	fp = fopen("/home/<USER>/Poker/Probabilities/LexicographicalOrder/_2Players/Turn/LexicographicalOrder_2Players_Turn_W1Probabilities.bin", "wb+");
	for(i1 = 0; i1 != 305377800; ++i1)
	{
		fwrite_unlocked(&expression1, 2, 1, fp);
	}
	LexicographicalOrder_2Players_Turn_W1Probabilities = mmap(NULL, 610755600, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	fp = fopen("/home/<USER>/Poker/Probabilities/LexicographicalOrder/_2Players/Turn/LexicographicalOrder_2Players_Turn_W2Probabilities.bin", "wb+");
	for(i1 = 0; i1 != 305377800; ++i1)
	{
		fwrite_unlocked(&expression1, 2, 1, fp);
	}
	LexicographicalOrder_2Players_Turn_W2Probabilities = mmap(NULL, 610755600, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	fp = fopen("/home/<USER>/Poker/Probabilities/LexicographicalOrder/_2Players/Turn/LexicographicalOrder_2Players_Turn_LProbabilities.bin", "wb+");
	for(i1 = 0; i1 != 305377800; ++i1)
	{
		fwrite_unlocked(&expression1, 2, 1, fp);
	}
	LexicographicalOrder_2Players_Turn_LProbabilities = mmap(NULL, 610755600, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	for(i1 = 0, i2 = 0; i1 != 61075560; ++i1)
	{
		for(; i2 != 46*(i1 + 1); ++i2)
		{
			LexicographicalOrder_2Players_Turn_W1Probabilities[i1] += LexicographicalOrder_2Players_River_W1Probabilities[i2];
			LexicographicalOrder_2Players_Turn_W2Probabilities[i1] += LexicographicalOrder_2Players_River_W2Probabilities[i2];
			LexicographicalOrder_2Players_Turn_LProbabilities[i1] += LexicographicalOrder_2Players_River_LProbabilities[i2];
		}
	}
	
	//LexicographicalOrder_2Players_Flop_Probabilities
	fp = fopen("/home/<USER>/Poker/Probabilities/LexicographicalOrder/_2Players/Flop/LexicographicalOrder_2Players_Flop_W1Probabilities.bin", "wb+");
	for(i1 = 0; i1 != 25989600; ++i1)
	{
		fwrite_unlocked(&expression1, 4, 1, fp);
	}
	LexicographicalOrder_2Players_Flop_W1Probabilities = mmap(NULL, 103958400, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	fp = fopen("/home/<USER>/Poker/Probabilities/LexicographicalOrder/_2Players/Flop/LexicographicalOrder_2Players_Flop_W2Probabilities.bin", "wb+");
	for(i1 = 0; i1 != 25989600; ++i1)
	{
		fwrite_unlocked(&expression1, 4, 1, fp);
	}
	LexicographicalOrder_2Players_Flop_W2Probabilities = mmap(NULL, 103958400, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	fp = fopen("/home/<USER>/Poker/Probabilities/LexicographicalOrder/_2Players/Flop/LexicographicalOrder_2Players_Flop_LProbabilities.bin", "wb+");
	for(i1 = 0; i1 != 25989600; ++i1)
	{
		fwrite_unlocked(&expression1, 4, 1, fp);
	}
	LexicographicalOrder_2Players_Flop_LProbabilities = mmap(NULL, 103958400, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	for(i1 = 0, i2 = 0; i1 != 6497400; ++i1)
	{
		for(; i2 != 47*(i1 + 1); ++i2)
		{
			LexicographicalOrder_2Players_Flop_W1Probabilities[i1] += LexicographicalOrder_2Players_Turn_W1Probabilities[i2];
			LexicographicalOrder_2Players_Flop_W2Probabilities[i1] += LexicographicalOrder_2Players_Turn_W2Probabilities[i2];
			LexicographicalOrder_2Players_Flop_LProbabilities[i1] += LexicographicalOrder_2Players_Turn_LProbabilities[i2];
		}
	}
	
	//LexicographicalOrder_2Players_PreFlop_Probabilities
	fp = fopen("/home/<USER>/Poker/Probabilities/LexicographicalOrder/_2Players/PreFlop/LexicographicalOrder_2Players_PreFlop_W1Probabilities.bin", "wb+");
	for(i1 = 0; i1 != 1326; ++i1)
	{
		fwrite_unlocked(&expression1, 4, 1, fp);
	}
	LexicographicalOrder_2Players_PreFlop_W1Probabilities = mmap(NULL, 5304, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	fp = fopen("/home/<USER>/Poker/Probabilities/LexicographicalOrder/_2Players/PreFlop/LexicographicalOrder_2Players_PreFlop_W2Probabilities.bin", "wb+");
	for(i1 = 0; i1 != 1326; ++i1)
	{
		fwrite_unlocked(&expression1, 4, 1, fp);
	}
	LexicographicalOrder_2Players_PreFlop_W2Probabilities = mmap(NULL, 5304, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	fp = fopen("/home/<USER>/Poker/Probabilities/LexicographicalOrder/_2Players/PreFlop/LexicographicalOrder_2Players_PreFlop_LProbabilities.bin", "wb+");
	for(i1 = 0; i1 != 1326; ++i1)
	{
		fwrite_unlocked(&expression1, 4, 1, fp);
	}
	LexicographicalOrder_2Players_PreFlop_LProbabilities = mmap(NULL, 5304, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(fp), 0);
	fclose(fp);
	for(i1 = 0, i2 = 0; i1 != 1326; ++i1)
	{
		for(; i2 != 19600*(i1 + 1); ++i2)
		{
			LexicographicalOrder_2Players_PreFlop_W1Probabilities[i1] += LexicographicalOrder_2Players_Flop_W1Probabilities[i2];
			LexicographicalOrder_2Players_PreFlop_W2Probabilities[i1] += LexicographicalOrder_2Players_Flop_W2Probabilities[i2];
			LexicographicalOrder_2Players_PreFlop_LProbabilities[i1] += LexicographicalOrder_2Players_Flop_LProbabilities[i2];
		}
	}
	munmap(LexicographicalOrder_2Players_PreFlop_W1Probabilities, 5304);
	munmap(LexicographicalOrder_2Players_PreFlop_W2Probabilities, 5304);
	munmap(LexicographicalOrder_2Players_PreFlop_LProbabilities, 5304);
	munmap(LexicographicalOrder_2Players_Flop_W1Probabilities, 103958400);
	munmap(LexicographicalOrder_2Players_Flop_W2Probabilities, 103958400);
	munmap(LexicographicalOrder_2Players_Flop_LProbabilities, 103958400);
	munmap(LexicographicalOrder_2Players_Turn_W1Probabilities, 610755600);
	munmap(LexicographicalOrder_2Players_Turn_W2Probabilities, 610755600);
	munmap(LexicographicalOrder_2Players_Turn_LProbabilities, 610755600);
	munmap(LexicographicalOrder_2Players_River_W1Probabilities, 5618951520);
	munmap(LexicographicalOrder_2Players_River_W2Probabilities, 5618951520);
	munmap(LexicographicalOrder_2Players_River_LProbabilities, 5618951520);
	
	//Linux specific benchmark
	clock_gettime(CLOCK_MONOTONIC_RAW, &StopTime);//Stop
	printf("%lu\n", (StopTime.tv_sec - StartTime.tv_sec)*1000000000 + StopTime.tv_nsec - StartTime.tv_nsec);//To get the exact number of nanoseconds elapsed
	//Linux specific benchmark
	
	return 0;
}
