// method 1

unsigned columnToDelete = 2;

for (unsigned i = 0; i < myVector.size(); ++i)
{
  if (myVector[i].size() > columnToDelete)
  {
    myVector[i].erase(myVector[i].begin() + columnToDelete);
  }
}

// method 2
vector<vector<int>> deleteCol(vector<vector<int>> myVector, int columnToDelete){
	for (unsigned i = 0; i < myVector.size(); ++i)	
	{
  		if (myVector[i].size() > columnToDelete)
  		{
    			myVector[i].erase(myVector[i].begin() + columnToDelete);
  		}
	}
}
