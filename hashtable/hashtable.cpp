#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
Word Pattern My Submissions Question

Here follow means a full match, such that there is a bijection between a letter in pattern and a non - empty word in str.

Examples :
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes :
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

*/

bool wordPattern(string pattern, string str) 
{
	stringstream ss(str);
	vector<string> cols;
	string tmp;
	while (ss>>tmp)
	{
		cols.push_back(tmp);
	}

	unordered_map<string, char> m_Map;

	for (int i = 0; i < cols.size();i++)
	{
		if (m_Map.find(cols[i])==m_Map.end())
		{
			m_Map[cols[i]] = pattern[i];
		}
		else
		{
			if (m_Map[cols[i]] != pattern[i])
			{
				return false;
			}
		}
	}

	unordered_set<char> m_Set;
	for (auto pairNode: m_Map)
	{
		m_Set.insert(pairNode.second);
	}


	if (m_Set.size() != m_Map.size() || cols.size() != pattern.size())
	{
		return false;
	}
	return true;
}

int main()
{
	wordPattern("abba","dog cat cat fish");
	return 0;
}
