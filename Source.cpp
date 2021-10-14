#include <iostream>

using namespace std;

#include <vector>
#include <string>
#include <sstream>

vector<string> justify( string inputStr, int justifyWidth)
{
	vector <string> justifiedlines;

	vector<string> allWords;

	stringstream stream(inputStr);

	while (stream.good())
	{
		string str;
		getline(stream, str, ' ');
		allWords.push_back(str);
	}

	int i = 0;

	while (i < allWords.size())
	{
		int curWordWidth = allWords[i].length();
		if (curWordWidth >= justifyWidth)
		{
			justifyWidth = curWordWidth+1;
		}

		i++;
	}

	cout << "justifyWidth = " << justifyWidth << endl;

	i = 0;
	string lineStr;
	while (i < allWords.size())
	{
		int curWordWidth = allWords[i].length();
		int lineWidth = lineStr.length() + curWordWidth;

		if (lineWidth < justifyWidth)
		{
			lineStr += allWords[i] + " ";
			if (i == allWords.size() - 1)
			{
				justifiedlines.push_back(lineStr);
			}
		}
		else
		{
			justifiedlines.push_back(lineStr);
			lineStr = "";

			i--;
		}


		i++;

	}

	//insert spaces...
	i = 0;
	while (i < justifiedlines.size())
	{
		if (justifiedlines[i].length() == 0)
		{
			justifiedlines[i].append(" ");
		}

		if (justifiedlines[i][justifiedlines[i].length() - 1] == ' ')
		{
			//no space at end...
			justifiedlines[i] = justifiedlines[i].substr(0, justifiedlines[i].length() - 1);
		}

		do
		{
			bool spaceFound = false;

			if (i == justifiedlines.size() - 1)
			{
				justifiedlines[i].append(" ");
				continue;
			}

			for (int j = justifiedlines[i].length() - 1; j >= 0; j--)
			{
				if (justifiedlines[i].length() < justifyWidth)
				{
					if (justifiedlines[i][j] == ' ')
					{
						spaceFound = true;
						string::const_iterator spaceit = begin(justifiedlines[i]) + j;
						justifiedlines[i].insert(spaceit, ' ');
					}
				}
				else
				{
					break;
				}
			}

			if (spaceFound == false)
			{
				justifiedlines[i].append(" ");
			}

		} while (justifiedlines[i].length() < justifyWidth);

		i++;
	}

	return justifiedlines;

}

int main()
{
	string inputStr = "Proin nisi turpis, dignissim sed euismod in, \
tristique sed turpis. Integer consequat nunc eget \
vulputate dignissim. Phasellus luctus sapien a nulla \
facilisis, sed maximus lacus lacinia. Cras accumsan molestie \
dui tortor blandit leo, et fermentum arcu ante sit amet justo.";

	int justifyWidth = 50;

	while ( true )
	{
		cout << endl;
		cout << "Enter Justify width : ";
		cin >> justifyWidth;
		if (justifyWidth == -1)
		{
			break;
		}

		system("cls");


		vector <string> justifiedlines = justify(inputStr, justifyWidth);


		for (int i = 0; i < justifiedlines.size(); i++)
		{
			cout << justifiedlines[i] << endl;
		}
	}

	system("pause");
	return 0;
}
