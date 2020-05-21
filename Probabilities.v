module Probabilities(input wire clock)
	always @ (posedge clock)
	begin
		.Loop1(1);
	end
endmodule

module Loop1(input wire[50:0] i1)
	if(i1 < (1 << 50))
	begin
		.Loop2(i1, i1 << 1);
	end
	if(i1 > (1 << 49))
	begin
		//End of program
	end
endmodule

module Loop2(input wire[50:0] i1, input wire[51:0] i2)
	if(i2 < (1 << 51))
	begin
		.Loop3(i1, i2, 1, 0, 0, 0);
	end
	if(i2 > (1 << 50))
	begin
		.Loop1(i1 << 1);
	end
endmodule

module Loop3(input wire[50:0] i1, input wire[51:0] i2, input wire[50:0] i3, input wire[31:0] 2Players_W1Probability_2Hand, input wire[31:0] 2Players_W2Probability_2Hand, input wire[31:0] 2Players_LProbability_2Hand)
	if((i3 < (1 << 50)) & (i3 != i1) & (i3 != i2))//'&' rather than '&&' (short-circuit evaluation)? //Is there an intrinsic boolean expression to check for equality, instead of using '!='?
	begin
		.Loop4(i1, i2, i3, i3 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand);
	end
	if((i3 < (1 << 50)) & ((i3 == i1) | (i3 == i2)))//I've decided to repeat some conditionals in order to fully parallelize the if, check if it's slower or not
	begin
		.Loop3(i1, i2, i3 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand);
	end
	if(i3 > (1 << 49))
	begin
		//Pseudocode
		print(2Players_W1Probability_2Hand / right denominator);
		print(2Players_W2Probability_2Hand / right denominator);
		print(2Players_LProbability_2Hand / right denominator);
		//Pseudocode
		.Loop2(i1, i2 << 1);
	end
endmodule

module Loop4(input wire[50:0] i1, input wire[51:0] i2, input wire[50:0] i3, input wire[51:0] i4, input wire[31:0] 2Players_W1Probability_2Hand, input wire[31:0] 2Players_W2Probability_2Hand, input wire[31:0] 2Players_LProbability_2Hand)
	if((i4 < (1 << 51)) & (i4 != i1) & (i4 != i2))//'&' rather than '&&' (short-circuit evaluation)? //Is there an intrinsic boolean expression to check for equality, instead of using '!='?
	begin
		.Loop5(i1, i2, i3, i4, 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand);
	end
	if((i4 < (1 << 51)) & ((i4 == i1) | (i4 == i2)))//I've decided to repeat some conditionals in order to fully parallelize the if, check if it's slower or not
	begin
		.Loop4(i1, i2, i3, i4 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand);
	end
	if(i4 > (1 << 50))
	begin
		.Loop3(i1, i2, i3 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand);
	end
endmodule

module Loop5(input wire[50:0] i1, input wire[51:0] i2, input wire[50:0] i3, input wire[51:0] i4, input wire[47:0] i5, input wire[31:0] 2Players_W1Probability_2Hand, input wire[31:0] 2Players_W2Probability_2Hand, input wire[31:0] 2Players_LProbability_2Hand)
	if((i5 < (1 << 47)) & (i5 != i1) & (i5 != i2) & (i5 != i3) & (i5 != i4))//'&' rather than '&&' (short-circuit evaluation)? //Is there an intrinsic boolean expression to check for equality, instead of using '!='?
	begin
		.Loop6(i1, i2, i3, i4, i5, i5 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand, 0, 0, 0);
	end
	if((i5 < (1 << 47)) & ((i5 == i1) | (i5 == i2) | (i5 == i3) | (i5 == i4)))//I've decided to repeat some conditionals in order to fully parallelize the if, check if it's slower or not
	begin
		.Loop5(i1, i2, i3, i4, i5 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand);
	end
	if(i5 > (1 << 46))
	begin
		.Loop4(i1, i2, i3, i4 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand);
	end
endmodule

module Loop6(input wire[50:0] i1, input wire[51:0] i2, input wire[50:0] i3, input wire[51:0] i4, input wire[47:0] i5, input wire[48:0] i6, input wire[31:0] 2Players_W1Probability_2Hand, input wire[31:0] 2Players_W2Probability_2Hand, input wire[31:0] 2Players_LProbability_2Hand, input wire[31:0] 2Players_W1Probability_5Hand, input wire[31:0] 2Players_W2Probability_5Hand, input wire[31:0] 2Players_LProbability_5Hand)
	if((i6 < (1 << 48)) & (i6 != i1) & (i6 != i2) & (i6 != i3) & (i6 != i4))//'&' rather than '&&' (short-circuit evaluation)? //Is there an intrinsic boolean expression to check for equality, instead of using '!='?
	begin
		.Loop7(i1, i2, i3, i4, i5, i6, i6 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand, 2Players_W1Probability_5Hand, 2Players_W2Probability_5Hand, 2Players_LProbability_5Hand, 0, 0, 0);
	end
	if((i6 < (1 << 48)) & ((i6 == i1) | (i6 == i2) | (i6 == i3) | (i6 == i4)))//I've decided to repeat some conditionals in order to fully parallelize the if, check if it's slower or not
	begin
		.Loop6(i1, i2, i3, i4, i5, i6 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand, 2Players_W1Probability_5Hand, 2Players_W2Probability_5Hand, 2Players_LProbability_5Hand);
	end
	if(i6 > (1 << 47))
	begin
		//Pseudocode
		print(2Players_W1Probability_5Hand / right denominator);
		print(2Players_W2Probability_5Hand / right denominator);
		print(2Players_LProbability_5Hand / right denominator);
		//Pseudocode
		.Loop5(i1, i2, i3, i4, i5 << 1, 2Players_W1Probability_2Hand + 2Players_W1Probability_5Hand, 2Players_W2Probability_2Hand + 2Players_W2Probability_5Hand, 2Players_LProbability_2Hand + 2Players_LProbability_5Hand);
	end
endmodule

module Loop7(input wire[50:0] i1, input wire[51:0] i2, input wire[50:0] i3, input wire[51:0] i4, input wire[47:0] i5, input wire[48:0] i6, input wire[49:0] i7, input wire[31:0] 2Players_W1Probability_2Hand, input wire[31:0] 2Players_W2Probability_2Hand, input wire[31:0] 2Players_LProbability_2Hand, input wire[31:0] 2Players_W1Probability_5Hand, input wire[31:0] 2Players_W2Probability_5Hand, input wire[31:0] 2Players_LProbability_5Hand, input wire[31:0] 2Players_W1Probability_6Hand, input wire[31:0] 2Players_W2Probability_6Hand, input wire[31:0] 2Players_LProbability_6Hand)
	if((i7 < (1 << 49)) & (i7 != i1) & (i7 != i2) & (i7 != i3) & (i7 != i4))//'&' rather than '&&' (short-circuit evaluation)? //Is there an intrinsic boolean expression to check for equality, instead of using '!='?
	begin
		.Loop8(i1, i2, i3, i4, i5, i6, i7, i7 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand, 2Players_W1Probability_5Hand, 2Players_W2Probability_5Hand, 2Players_LProbability_5Hand, 2Players_W1Probability_6Hand, 2Players_W2Probability_6Hand, 2Players_LProbability_6Hand, 0, 0, 0);
	end
	if((i7 < (1 << 49)) & ((i7 == i1) | (i7 == i2) | (i7 == i3) | (i7 == i4)))//I've decided to repeat some conditionals in order to fully parallelize the if, check if it's slower or not
	begin
		.Loop7(i1, i2, i3, i4, i5, i6, i7 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand, 2Players_W1Probability_5Hand, 2Players_W2Probability_5Hand, 2Players_LProbability_5Hand, 2Players_W1Probability_6Hand, 2Players_W2Probability_6Hand, 2Players_LProbability_6Hand);
	end
	if(i7 > (1 << 48))
	begin
		//Pseudocode
		print(2Players_W1Probability_6Hand / right denominator);
		print(2Players_W2Probability_6Hand / right denominator);
		print(2Players_LProbability_6Hand / right denominator);
		//Pseudocode
		.Loop6(i1, i2, i3, i4, i5, i6 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand, 2Players_W1Probability_5Hand + 2Players_W1Probability_6Hand, 2Players_W2Probability_5Hand + 2Players_W2Probability_6Hand, 2Players_LProbability_5Hand + 2Players_LProbability_6Hand);
	end
endmodule

module Loop8(input wire[50:0] i1, input wire[51:0] i2, input wire[50:0] i3, input wire[51:0] i4, input wire[47:0] i5, input wire[48:0] i6, input wire[49:0] i7, input wire[50:0] i8, input wire[31:0] 2Players_W1Probability_2Hand, input wire[31:0] 2Players_W2Probability_2Hand, input wire[31:0] 2Players_LProbability_2Hand, input wire[31:0] 2Players_W1Probability_5Hand, input wire[31:0] 2Players_W2Probability_5Hand, input wire[31:0] 2Players_LProbability_5Hand, input wire[31:0] 2Players_W1Probability_6Hand, input wire[31:0] 2Players_W2Probability_6Hand, input wire[31:0] 2Players_LProbability_6Hand, input wire[31:0] 2Players_W1Probability_7Hand, input wire[31:0] 2Players_W2Probability_7Hand, input wire[31:0] 2Players_LProbability_7Hand)
	if((i8 < (1 << 50)) & (i8 != i1) & (i8 != i2) & (i8 != i3) & (i8 != i4))//'&' rather than '&&' (short-circuit evaluation)? //Is there an intrinsic boolean expression to check for equality, instead of using '!='?
	begin
		.Loop9(i1, i2, i3, i4, i5, i6, i7, i8, i8 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand, 2Players_W1Probability_5Hand, 2Players_W2Probability_5Hand, 2Players_LProbability_5Hand, 2Players_W1Probability_6Hand, 2Players_W2Probability_6Hand, 2Players_LProbability_6Hand, 2Players_W1Probability_7Hand, 2Players_W2Probability_7Hand, 2Players_LProbability_7Hand);
	end
	if((i8 < (1 << 50)) & ((i8 == i1) | (i8 == i2) | (i8 == i3) | (i8 == i4)))//I've decided to repeat some conditionals in order to fully parallelize the if, check if it's slower or not
	begin
		.Loop8(i1, i2, i3, i4, i5, i6, i7, i8 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand, 2Players_W1Probability_5Hand, 2Players_W2Probability_5Hand, 2Players_LProbability_5Hand, 2Players_W1Probability_6Hand, 2Players_W2Probability_6Hand, 2Players_LProbability_6Hand, 2Players_W1Probability_7Hand, 2Players_W2Probability_7Hand, 2Players_LProbability_7Hand);
	end
	if(i8 > (1 << 49))
	begin
		//Pseudocode
		print(2Players_W1Probability_7Hand / right denominator);
		print(2Players_W2Probability_7Hand / right denominator);
		print(2Players_LProbability_7Hand / right denominator);
		//Pseudocode
		.Loop7(i1, i2, i3, i4, i5, i6, i7 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand, 2Players_W1Probability_5Hand, 2Players_W2Probability_5Hand, 2Players_LProbability_5Hand, 2Players_W1Probability_6Hand + 2Players_W1Probability_7Hand, 2Players_W2Probability_6Hand + 2Players_W2Probability_7Hand, 2Players_LProbability_6Hand + 2Players_LProbability_7Hand);
	end
endmodule

module Loop9(input wire[50:0] i1, input wire[51:0] i2, input wire[50:0] i3, input wire[51:0] i4, input wire[47:0] i5, input wire[48:0] i6, input wire[49:0] i7, input wire[50:0] i8, input wire[51:0] i9, input wire[31:0] 2Players_W1Probability_2Hand, input wire[31:0] 2Players_W2Probability_2Hand, input wire[31:0] 2Players_LProbability_2Hand, input wire[31:0] 2Players_W1Probability_5Hand, input wire[31:0] 2Players_W2Probability_5Hand, input wire[31:0] 2Players_LProbability_5Hand, input wire[31:0] 2Players_W1Probability_6Hand, input wire[31:0] 2Players_W2Probability_6Hand, input wire[31:0] 2Players_LProbability_6Hand, input wire[31:0] 2Players_W1Probability_7Hand, input wire[31:0] 2Players_W2Probability_7Hand, input wire[31:0] 2Players_LProbability_7Hand)
	if((i9 < (1 << 51)) & (i9 != i1) & (i9 != i2) & (i9 != i3) & (i9 != i4))//'&' rather than '&&' (short-circuit evaluation)? //Is there an intrinsic boolean expression to check for equality, instead of using '!='?
	begin
		
		//Check which _7Hand beats the other (you can use the old concept of checking rank by rank at this point, or something like that) ('HandEval')
		
		if('i1_1 | i1_2 | i1_5 | i1_6 | i1_7 | i1_8 | i1_9 beats i1_3 | i1_4 | i1_5 | i1_6 | i1_7 | i1_8 | i1_9')
		begin
			.Loop9(i1, i2, i3, i4, i5, i6, i7, i8, i9 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand, 2Players_W1Probability_5Hand, 2Players_W2Probability_5Hand, 2Players_LProbability_5Hand, 2Players_W1Probability_6Hand, 2Players_W2Probability_6Hand, 2Players_LProbability_6Hand, 2Players_W1Probability_7Hand + 1, 2Players_W2Probability_7Hand, 2Players_LProbability_7Hand);//Come up with a formal classification for the probabilities //Should I make my own adder/incrementer? Would it be more efficient (I assume not, because this should all be done in 1 clock cycle ==> all these nested operation should perform almost instantaneously)?
		end
		if('i1_1 | i1_2 | i1_5 | i1_6 | i1_7 | i1_8 | i1_9 equals i1_3 | i1_4 | i1_5 | i1_6 | i1_7 | i1_8 | i1_9')
		begin
			.Loop9(i1, i2, i3, i4, i5, i6, i7, i8, i9 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand, 2Players_W1Probability_5Hand, 2Players_W2Probability_5Hand, 2Players_LProbability_5Hand, 2Players_W1Probability_6Hand, 2Players_W2Probability_6Hand, 2Players_LProbability_6Hand, 2Players_W1Probability_7Hand, 2Players_W2Probability_7Hand + 1, 2Players_LProbability_7Hand);
		end
		if('i1_3 | i1_4 | i1_5 | i1_6 | i1_7 | i1_8 | i1_9 beats i1_1 | i1_2 | i1_5 | i1_6 | i1_7 | i1_8 | i1_9')
		begin
			.Loop9(i1, i2, i3, i4, i5, i6, i7, i8, i9 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand, 2Players_W1Probability_5Hand, 2Players_W2Probability_5Hand, 2Players_LProbability_5Hand, 2Players_W1Probability_6Hand, 2Players_W2Probability_6Hand, 2Players_LProbability_6Hand, 2Players_W1Probability_7Hand, 2Players_W2Probability_7Hand, 2Players_LProbability_7Hand + 1);
		end
	end
	if((i9 < (1 << 51)) & ((i9 == i1) | (i9 == i2) | (i9 == i3) | (i9 == i4)))//I've decided to repeat some conditionals in order to fully parallelize the if, check if it's slower or not
	begin
		.Loop9(i1, i2, i3, i4, i5, i6, i7, i8, i9 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand, 2Players_W1Probability_5Hand, 2Players_W2Probability_5Hand, 2Players_LProbability_5Hand, 2Players_W1Probability_6Hand, 2Players_W2Probability_6Hand, 2Players_LProbability_6Hand, 2Players_W1Probability_7Hand, 2Players_W2Probability_7Hand, 2Players_LProbability_7Hand);
	end
	if(i9 > (1 << 50))
	begin
		.Loop8(i1, i2, i3, i4, i5, i6, i7, i8 << 1, 2Players_W1Probability_2Hand, 2Players_W2Probability_2Hand, 2Players_LProbability_2Hand, 2Players_W1Probability_5Hand, 2Players_W2Probability_5Hand, 2Players_LProbability_5Hand, 2Players_W1Probability_6Hand, 2Players_W2Probability_6Hand, 2Players_LProbability_6Hand, 2Players_W1Probability_7Hand, 2Players_W2Probability_7Hand, 2Players_LProbability_7Hand);
	end
endmodule