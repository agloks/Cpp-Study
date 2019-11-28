#include <iostream>
#include <vector>

/*
	1 - column even and row even == white
	2 - column old and row old == black
	3 - all two need combine (a^b)^(c^d)
	a / c / e / g == true == old == black
	b / d / f / h == false == even == white
*/

bool chessBoardCellColor(std::string cell1, std::string cell2)
{
	bool stament_one = (cell1[0] == 'A' || cell1[0] == 'C' || cell1[0] == 'E' || cell1[0] == 'G');
	bool stament_two = (cell1[1] == '1' || cell1[1] == '3' || cell1[1] == '5' || cell1[1] == '7');
	bool stament_three = (cell2[0] == 'A' || cell2[0] == 'C' || cell2[0] == 'E' || cell2[0] == 'G');
	bool stament_four = (cell2[1] == '1' || cell2[1] == '3' || cell2[1] == '5' || cell2[1] == '7');
	return ( stament_one == stament_two == stament_three == stament_four );
}


int main()
{
	std::cout << chessBoardCellColor( "A6", "H1" ) << std::endl;
	return 0;
}