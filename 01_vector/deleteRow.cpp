// example
unsigned rowToDelete = 2;

if (myVector.size() > rowToDelete)
{
  myVector.erase( myVector.begin() + rowToDelete );
}

// function form

vector<vector<int>> deleteRow(vector<vector<int>> myVector, int rowToDelete){
	if (myVector.size() > rowToDelete)
	{
		myVector.erase( myVector.begin() + rowToDelete );
	}
	return myVector;
}
