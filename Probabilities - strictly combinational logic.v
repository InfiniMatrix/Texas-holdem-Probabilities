module Probabilities(input wire clock)
	
	//2 Players
	reg[31:0] 2Players_W1Probability_2Hand = 0, 2Players_W2Probability_2Hand = 0, 2Players_LProbability_2Hand = 0;
	reg[31:0] 2Players_W1Probability_5Hand = 0, 2Players_W2Probability_5Hand = 0, 2Players_LProbability_5Hand = 0;
	reg[31:0] 2Players_W1Probability_6Hand = 0, 2Players_W2Probability_6Hand = 0, 2Players_LProbability_6Hand = 0;
	reg[31:0] 2Players_W1Probability_7Hand = 0, 2Players_W2Probability_7Hand = 0, 2Players_LProbability_7Hand = 0;
	
	//3 Players
	reg[31:0] 3Players_W1Probability_2Hand = 0, 3Players_W2Probability_2Hand = 0, 3Players_W3Probability_2Hand = 0, 3Players_LProbability_2Hand = 0;
	reg[31:0] 3Players_W1Probability_5Hand = 0, 3Players_W2Probability_5Hand = 0, 3Players_W3Probability_5Hand = 0, 3Players_LProbability_5Hand = 0;
	reg[31:0] 3Players_W1Probability_6Hand = 0, 3Players_W2Probability_6Hand = 0, 3Players_W3Probability_6Hand = 0, 3Players_LProbability_6Hand = 0;
	reg[31:0] 3Players_W1Probability_7Hand = 0, 3Players_W2Probability_7Hand = 0, 3Players_W3Probability_7Hand = 0, 3Players_LProbability_7Hand = 0;
	
	//4 Players
	reg[31:0] 4Players_W1Probability_2Hand = 0, 4Players_W2Probability_2Hand = 0, 4Players_W3Probability_2Hand = 0, 4Players_W4Probability_2Hand = 0, 4Players_LProbability_2Hand = 0;
	reg[31:0] 4Players_W1Probability_5Hand = 0, 4Players_W2Probability_5Hand = 0, 4Players_W3Probability_5Hand = 0, 4Players_W4Probability_5Hand = 0, 4Players_LProbability_5Hand = 0;
	reg[31:0] 4Players_W1Probability_6Hand = 0, 4Players_W2Probability_6Hand = 0, 4Players_W3Probability_6Hand = 0, 4Players_W4Probability_6Hand = 0, 4Players_LProbability_6Hand = 0;
	reg[31:0] 4Players_W1Probability_7Hand = 0, 4Players_W2Probability_7Hand = 0, 4Players_W3Probability_7Hand = 0, 4Players_W4Probability_7Hand = 0, 4Players_LProbability_7Hand = 0;
	
	//5 Players
	reg[31:0] 5Players_W1Probability_2Hand = 0, 5Players_W2Probability_2Hand = 0, 5Players_W3Probability_2Hand = 0, 5Players_W4Probability_2Hand = 0, 5Players_W5Probability_2Hand = 0, 5Players_LProbability_2Hand = 0;
	reg[31:0] 5Players_W1Probability_5Hand = 0, 5Players_W2Probability_5Hand = 0, 5Players_W3Probability_5Hand = 0, 5Players_W4Probability_5Hand = 0, 5Players_W5Probability_5Hand = 0, 5Players_LProbability_5Hand = 0;
	reg[31:0] 5Players_W1Probability_6Hand = 0, 5Players_W2Probability_6Hand = 0, 5Players_W3Probability_6Hand = 0, 5Players_W4Probability_6Hand = 0, 5Players_W5Probability_6Hand = 0, 5Players_LProbability_6Hand = 0;
	reg[31:0] 5Players_W1Probability_7Hand = 0, 5Players_W2Probability_7Hand = 0, 5Players_W3Probability_7Hand = 0, 5Players_W4Probability_7Hand = 0, 5Players_W5Probability_7Hand = 0, 5Players_LProbability_7Hand = 0;
	
	//6 Players
	reg[31:0] 6Players_W1Probability_2Hand = 0, 6Players_W2Probability_2Hand = 0, 6Players_W3Probability_2Hand = 0, 6Players_W4Probability_2Hand = 0, 6Players_W5Probability_2Hand = 0, 6Players_W6Probability_2Hand = 0, 6Players_LProbability_2Hand = 0;
	reg[31:0] 6Players_W1Probability_5Hand = 0, 6Players_W2Probability_5Hand = 0, 6Players_W3Probability_5Hand = 0, 6Players_W4Probability_5Hand = 0, 6Players_W5Probability_5Hand = 0, 6Players_W6Probability_5Hand = 0, 6Players_LProbability_5Hand = 0;
	reg[31:0] 6Players_W1Probability_6Hand = 0, 6Players_W2Probability_6Hand = 0, 6Players_W3Probability_6Hand = 0, 6Players_W4Probability_6Hand = 0, 6Players_W5Probability_6Hand = 0, 6Players_W6Probability_6Hand = 0, 6Players_LProbability_6Hand = 0;
	reg[31:0] 6Players_W1Probability_7Hand = 0, 6Players_W2Probability_7Hand = 0, 6Players_W3Probability_7Hand = 0, 6Players_W4Probability_7Hand = 0, 6Players_W5Probability_7Hand = 0, 6Players_W6Probability_7Hand = 0, 6Players_LProbability_7Hand = 0;
	
	//7 Players
	reg[31:0] 7Players_W1Probability_2Hand = 0, 7Players_W2Probability_2Hand = 0, 7Players_W3Probability_2Hand = 0, 7Players_W4Probability_2Hand = 0, 7Players_W5Probability_2Hand = 0, 7Players_W6Probability_2Hand = 0, 7Players_W7Probability_2Hand = 0, 7Players_LProbability_2Hand = 0;
	reg[31:0] 7Players_W1Probability_5Hand = 0, 7Players_W2Probability_5Hand = 0, 7Players_W3Probability_5Hand = 0, 7Players_W4Probability_5Hand = 0, 7Players_W5Probability_5Hand = 0, 7Players_W6Probability_5Hand = 0, 7Players_W7Probability_5Hand = 0, 7Players_LProbability_5Hand = 0;
	reg[31:0] 7Players_W1Probability_6Hand = 0, 7Players_W2Probability_6Hand = 0, 7Players_W3Probability_6Hand = 0, 7Players_W4Probability_6Hand = 0, 7Players_W5Probability_6Hand = 0, 7Players_W6Probability_6Hand = 0, 7Players_W7Probability_6Hand = 0, 7Players_LProbability_6Hand = 0;
	reg[31:0] 7Players_W1Probability_7Hand = 0, 7Players_W2Probability_7Hand = 0, 7Players_W3Probability_7Hand = 0, 7Players_W4Probability_7Hand = 0, 7Players_W5Probability_7Hand = 0, 7Players_W6Probability_7Hand = 0, 7Players_W7Probability_7Hand = 0, 7Players_LProbability_7Hand = 0;
	
	//8 Players
	reg[31:0] 8Players_W1Probability_2Hand = 0, 8Players_W2Probability_2Hand = 0, 8Players_W3Probability_2Hand = 0, 8Players_W4Probability_2Hand = 0, 8Players_W5Probability_2Hand = 0, 8Players_W6Probability_2Hand = 0, 8Players_W7Probability_2Hand = 0, 8Players_W8Probability_2Hand = 0, 8Players_LProbability_2Hand = 0;
	reg[31:0] 8Players_W1Probability_5Hand = 0, 8Players_W2Probability_5Hand = 0, 8Players_W3Probability_5Hand = 0, 8Players_W4Probability_5Hand = 0, 8Players_W5Probability_5Hand = 0, 8Players_W6Probability_5Hand = 0, 8Players_W7Probability_5Hand = 0, 8Players_W8Probability_5Hand = 0, 8Players_LProbability_5Hand = 0;
	reg[31:0] 8Players_W1Probability_6Hand = 0, 8Players_W2Probability_6Hand = 0, 8Players_W3Probability_6Hand = 0, 8Players_W4Probability_6Hand = 0, 8Players_W5Probability_6Hand = 0, 8Players_W6Probability_6Hand = 0, 8Players_W7Probability_6Hand = 0, 8Players_W8Probability_6Hand = 0, 8Players_LProbability_6Hand = 0;
	reg[31:0] 8Players_W1Probability_7Hand = 0, 8Players_W2Probability_7Hand = 0, 8Players_W3Probability_7Hand = 0, 8Players_W4Probability_7Hand = 0, 8Players_W5Probability_7Hand = 0, 8Players_W6Probability_7Hand = 0, 8Players_W7Probability_7Hand = 0, 8Players_W8Probability_7Hand = 0, 8Players_LProbability_7Hand = 0;
	
	//9 Players
	reg[31:0] 9Players_W1Probability_2Hand = 0, 9Players_W2Probability_2Hand = 0, 9Players_W3Probability_2Hand = 0, 9Players_W4Probability_2Hand = 0, 9Players_W5Probability_2Hand = 0, 9Players_W6Probability_2Hand = 0, 9Players_W7Probability_2Hand = 0, 9Players_W8Probability_2Hand = 0, 9Players_W9Probability_2Hand = 0, 9Players_LProbability_2Hand = 0;
	reg[31:0] 9Players_W1Probability_5Hand = 0, 9Players_W2Probability_5Hand = 0, 9Players_W3Probability_5Hand = 0, 9Players_W4Probability_5Hand = 0, 9Players_W5Probability_5Hand = 0, 9Players_W6Probability_5Hand = 0, 9Players_W7Probability_5Hand = 0, 9Players_W8Probability_5Hand = 0, 9Players_W9Probability_5Hand = 0, 9Players_LProbability_5Hand = 0;
	reg[31:0] 9Players_W1Probability_6Hand = 0, 9Players_W2Probability_6Hand = 0, 9Players_W3Probability_6Hand = 0, 9Players_W4Probability_6Hand = 0, 9Players_W5Probability_6Hand = 0, 9Players_W6Probability_6Hand = 0, 9Players_W7Probability_6Hand = 0, 9Players_W8Probability_6Hand = 0, 9Players_W9Probability_6Hand = 0, 9Players_LProbability_6Hand = 0;
	reg[31:0] 9Players_W1Probability_7Hand = 0, 9Players_W2Probability_7Hand = 0, 9Players_W3Probability_7Hand = 0, 9Players_W4Probability_7Hand = 0, 9Players_W5Probability_7Hand = 0, 9Players_W6Probability_7Hand = 0, 9Players_W7Probability_7Hand = 0, 9Players_W8Probability_7Hand = 0, 9Players_W9Probability_7Hand = 0, 9Players_LProbability_7Hand = 0;
	
	reg[50:0] i1, reg[51:0] i2, reg[50:0] i3, reg[51:0] i4, reg[47:0] i5, reg[48:0] i6, reg[49:0] i7, reg[50:0] i8, reg[51:0] i9;//Or also 'wire', but given that we're in an always block...?
	always @ (posedge clock)
	begin
		i1 = 1;
		
		//Loop1
		always @ (i1)
		begin
			if(i1 < (1 << 50))
			begin
				i2 = i1 << 1;
			end
			if(i1 > (1 << 49))
			begin
				//End of program
			end
		end
		
		//Loop2
		always @ (i2)
		begin
			if(i2 < (1 << 51))
			begin
				2Players_W1Probability_2Hand = 0;
				2Players_W2Probability_2Hand = 0;
				2Players_LProbability_2Hand = 0;
				i3 = 1;
			end
			if(i2 > (1 << 50))
			begin
				i1 = i1 << 1;
			end
		end
		
		//Loop3
		always @ (i3)
		begin
			if((i3 < (1 << 50)) & (i3 != i1) & (i3 != i2))//'&' rather than '&&' (short-circuit evaluation)? //Is there an intrinsic boolean expression to check for equality, instead of using '!='?
			begin
				i4 = i3 << 1;
			end
			if((i3 < (1 << 50)) & ((i3 == i1) | (i3 == i2)))//I've decided to repeat some conditionals in order to fully parallelize the if, check if it's slower or not
			begin
				i3 = i3 << 1;
			end
			if(i3 > (1 << 49))
			begin
				//Pseudocode
				print(2Players_W1Probability_2Hand / right denominator);
				print(2Players_W2Probability_2Hand / right denominator);
				print(2Players_LProbability_2Hand / right denominator);
				//Pseudocode
				i2 = i2 << 1;
			end
		end
		
		//Loop4
		always @ (i4)
		begin
			if((i4 < (1 << 51)) & (i4 != i1) & (i4 != i2))//'&' rather than '&&' (short-circuit evaluation)? //Is there an intrinsic boolean expression to check for equality, instead of using '!='?
			begin
				i5 = 1;
			end
			if((i4 < (1 << 51)) & ((i4 == i1) | (i4 == i2)))//I've decided to repeat some conditionals in order to fully parallelize the if, check if it's slower or not
			begin
				i4 = i4 << 1;
			end
			if(i4 > (1 << 50))
			begin
				i3 = i3 << 1;
			end
		end
		
		//Loop5
		always @ (i5)
		begin
			if((i5 < (1 << 47)) & (i5 != i1) & (i5 != i2) & (i5 != i3) & (i5 != i4))//'&' rather than '&&' (short-circuit evaluation)? //Is there an intrinsic boolean expression to check for equality, instead of using '!='?
			begin
				2Players_W1Probability_5Hand = 0;
				2Players_W2Probability_5Hand = 0;
				2Players_LProbability_5Hand = 0;
				i6 = i5 << 1;
			end
			if((i5 < (1 << 47)) & ((i5 == i1) | (i5 == i2) | (i5 == i3) | (i5 == i4)))//I've decided to repeat some conditionals in order to fully parallelize the if, check if it's slower or not
			begin
				i5 = i5 << 1;
			end
			if(i5 > (1 << 46))
			begin
				i4 = i4 << 1;
			end
		end
		
		//Loop6
		always @ (i6)
		begin
			if((i6 < (1 << 48)) & (i6 != i1) & (i6 != i2) & (i6 != i3) & (i6 != i4))//'&' rather than '&&' (short-circuit evaluation)? //Is there an intrinsic boolean expression to check for equality, instead of using '!='?
			begin
				2Players_W1Probability_6Hand = 0;
				2Players_W2Probability_6Hand = 0;
				2Players_LProbability_6Hand = 0;
				i7 = i6 << 1;
			end
			if((i6 < (1 << 48)) & ((i6 == i1) | (i6 == i2) | (i6 == i3) | (i6 == i4)))//I've decided to repeat some conditionals in order to fully parallelize the if, check if it's slower or not
			begin
				i6 = i6 << 1;
			end
			if(i6 > (1 << 47))
			begin
				//Pseudocode
				print(2Players_W1Probability_5Hand / right denominator);
				print(2Players_W2Probability_5Hand / right denominator);
				print(2Players_LProbability_5Hand / right denominator);
				//Pseudocode
				2Players_W1Probability_2Hand = 2Players_W1Probability_2Hand + 2Players_W1Probability_5Hand;//I have to make sure to build a very fast adder (lookup table, or LUT) so that after the last addition, when the probability (in this case '2Players_W1Probability_2Hand') has to be printed it gets printed after the last addition has been performed, otherwise if it's too slow it will be printed before getting updated (in all the other cases there will be enough time to be sure this doesn't happen)
				2Players_W2Probability_2Hand = 2Players_W2Probability_2Hand + 2Players_W2Probability_5Hand;//The right way to do this algorithmically, using this pattern I'm using here (more high-level it seems) would be (say for '2Players_W1Probability_2Hands') 'always @ (2Players_W1Probability_2Hands & 2Players_W2Probability_2Hands & 2Players_LProbability_2Hands) begin i5 = i5 << 1; end' ... and then 'always @ (~(2Players_W1Probability_2Hands | 2Players_W2Probability_2Hands | 2Players_LProbability_2Hands)) begin i3 = 1; end' this is the only way, very specific, the same way I handled Loop9 ==> I have to understand exactly how 'always' works
				2Players_LProbability_2Hand = 2Players_LProbability_2Hand + 2Players_LProbability_5Hand;
				i5 = i5 << 1;
			end
		end
		
		//Loop7
		always @ (i7)
		begin
			if((i7 < (1 << 49)) & (i7 != i1) & (i7 != i2) & (i7 != i3) & (i7 != i4))//'&' rather than '&&' (short-circuit evaluation)? //Is there an intrinsic boolean expression to check for equality, instead of using '!='?
			begin
				2Players_W1Probability_7Hand = 0;
				2Players_W2Probability_7Hand = 0;
				2Players_LProbability_7Hand = 0;
				i8 = i7 << 1;
			end
			if((i7 < (1 << 49)) & ((i7 == i1) | (i7 == i2) | (i7 == i3) | (i7 == i4)))//I've decided to repeat some conditionals in order to fully parallelize the if, check if it's slower or not
			begin
				i7 = i7 << 1;
			end
			if(i7 > (1 << 48))
			begin
				//Pseudocode
				print(2Players_W1Probability_6Hand / right denominator);
				print(2Players_W2Probability_6Hand / right denominator);
				print(2Players_LProbability_6Hand / right denominator);
				//Pseudocode
				2Players_W1Probability_5Hand = 2Players_W1Probability_5Hand + 2Players_W1Probability_6Hand;//I have to make sure to build a very fast adder (lookup table, or LUT) so that after the last addition, when the probability (in this case '2Players_W1Probability_2Hand') has to be printed it gets printed after the last addition has been performed, otherwise if it's too slow it will be printed before getting updated (in all the other cases there will be enough time to be sure this doesn't happen)
				2Players_W2Probability_5Hand = 2Players_W2Probability_5Hand + 2Players_W2Probability_6Hand;
				2Players_LProbability_5Hand = 2Players_LProbability_5Hand + 2Players_LProbability_6Hand;
				i6 = i6 << 1;
			end
		end
		
		//Loop8
		always @ (i8)
		begin
			if((i8 < (1 << 50)) & (i8 != i1) & (i8 != i2) & (i8 != i3) & (i8 != i4))//'&' rather than '&&' (short-circuit evaluation)? //Is there an intrinsic boolean expression to check for equality, instead of using '!='?
			begin
				i9 = i8 << 1;
			end
			if((i8 < (1 << 50)) & ((i8 == i1) | (i8 == i2) | (i8 == i3) | (i8 == i4)))//I've decided to repeat some conditionals in order to fully parallelize the if, check if it's slower or not
			begin
				i8 = i8 << 1;
			end
			if(i8 > (1 << 49))
			begin
				//Pseudocode
				print(2Players_W1Probability_7Hand / right denominator);
				print(2Players_W2Probability_7Hand / right denominator);
				print(2Players_LProbability_7Hand / right denominator);
				//Pseudocode
				2Players_W1Probability_6Hand = 2Players_W1Probability_6Hand + 2Players_W1Probability_7Hand;//I have to make sure to build a very fast adder (lookup table, or LUT) so that after the last addition, when the probability (in this case '2Players_W1Probability_2Hand') has to be printed it gets printed after the last addition has been performed, otherwise if it's too slow it will be printed before getting updated (in all the other cases there will be enough time to be sure this doesn't happen)
				2Players_W2Probability_6Hand = 2Players_W2Probability_6Hand + 2Players_W2Probability_7Hand;
				2Players_LProbability_6Hand = 2Players_LProbability_6Hand + 2Players_LProbability_7Hand;
				i7 = i7 << 1;
			end
		end
		
		//Loop9
		always @ (i9)
		begin
			if((i9 < (1 << 51)) & (i9 != i1) & (i9 != i2) & (i9 != i3) & (i9 != i4))//'&' rather than '&&' (short-circuit evaluation)? //Is there an intrinsic boolean expression to check for equality, instead of using '!='?
			begin
				
				//Check which _7Hand beats the other (you can use the old concept of checking rank by rank at this point, or something like that) ('HandEval')
				
				if('i1_1 | i1_2 | i1_5 | i1_6 | i1_7 | i1_8 | i1_9 beats i1_3 | i1_4 | i1_5 | i1_6 | i1_7 | i1_8 | i1_9')
				begin
					2Players_W1Probability_7Hand = 2Players_W1Probability_7Hand + 1;//Come up with a formal classification for the probabilities //Should I make my own adder/incrementer? Would it be more efficient (I assume not, because this should all be done in 1 clock cycle ==> all these nested operation should perform almost instantaneously)?
				end
				if('i1_1 | i1_2 | i1_5 | i1_6 | i1_7 | i1_8 | i1_9 equals i1_3 | i1_4 | i1_5 | i1_6 | i1_7 | i1_8 | i1_9')
				begin
					2Players_W2Probability_7Hand = 2Players_W2Probability_7Hand + 1;
				end
				if('i1_3 | i1_4 | i1_5 | i1_6 | i1_7 | i1_8 | i1_9 beats i1_1 | i1_2 | i1_5 | i1_6 | i1_7 | i1_8 | i1_9')
				begin
					2Players_LProbability_7Hand = 2Players_LProbability_7Hand + 1;
				end
			end
			if((i9 < (1 << 51)) & ((i9 == i1) | (i9 == i2) | (i9 == i3) | (i9 == i4)))//I've decided to repeat some conditionals in order to fully parallelize the if, check if it's slower or not
			begin
				i9 = i9 << 1;
			end
			if(i9 > (1 << 50))
			begin
				i8 = i8 << 1;
			end
		end
		always @ (2Players_W1Probability_7Hand | 2Players_W2Probability_7Hand | 2Players_LProbability_7Hand)//'|' rather than '||' (short-circuit evaluation)?
		begin
			i9 = i9 << 1;
		end
	end
endmodule