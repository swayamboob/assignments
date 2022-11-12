#include <bits/stdc++.h>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string s;
	ifstream File1("input.txt");
	ofstream File2("MDT.txt");
	ofstream File3("output.txt");

	File2<<"Index	  Macro Definition"<<endl;

	int idx=1;

	int flag1=0;
	
	vector<int>index;

    while(getline(File1,s))
	{
    	if(s=="MACRO")
    	{
			flag1=1;
    		continue;
			idx--;
    	}
	    else if(s=="START")
	    {
	    	break;
	    }
	    if(idx < 10)
		{
			File2<<"0"<<idx;
		}
		else
		{
			File2<<idx;
		}
		File2<<"        "<<s<<endl;
		if(flag1==1)
		{
			index.push_back(idx);
			flag1=0;
		}
		idx++;
	}
    File3<<"START"<<endl;
    while(getline(File1,s))
    {
   	    File3<<s<<endl;
   	}
    File1.close();
    File2.close();
    File3.close();

    File1.open("input.txt");

    string s1,s2;
    string s3="";
	vector<string>v1;
	int flag2=0;

    while(getline(File1,s1))
    {
       	if(s1=="MACRO" && flag2==0)
       	{
			flag2=1;
      		continue;
       	}
       	else if(flag2==1)
       	{
			s2=s1;
			for(int i=0;i<s2.length();i++)
			{				
				if(s2[i]!=' ')
				{
					s3=s3+s2[i];
				}
				else
				{
					v1.push_back(s3);
					s3="";
					break;
				}
			}
			flag2=0;
       	}
		if(s1=="START")
		{
			break;
		}
    }

    ofstream File4("MNT.txt");
	File4<<"Index	  Macro Name	  MDT Index"<<endl;
    for(int i=0;i<v1.size();i++)
	{
		if(i < 10)
		{
			File4<<"0"<<i+1;
		}
		else
		{
			File4<<i+1;
		}
		File4<<"        "<<v1[i]<<"            ";
		if(i < 10)
		{
			File4<<"0";
		}
		File4<<index[i]<<endl;
	}

    File1.close();
	File4.close();

	File1.open("input.txt");

	vector<string>v2;
	string s4;
	string s5,s6;
	int flag3=0;

	while(getline(File1,s4))
	{
    	if(s4=="MACRO" && flag3==0)
    	{
			flag3=1;
    		continue;
    	}
		else if(flag3==1)
		{
			s5=s4;
			s6="";
			for(int i=0;i<s5.length();i++)
			{
				if(s5[i]!=' ')
				{
					s6=s6+s5[i];
				}
				else
				{
					if(s6[0] == '&')
					{
						v2.push_back(s6);
					}
					s6="";
				}
			}
			v2.push_back(s6);
			flag3=0;
		}
		if(s4=="START")
	    {
	    	break;
	    }
	}

	ofstream File5("ALA.txt");
	File5<<"Index	  Arguments"<<endl;

	for(int i=0;i<v2.size();i++)
	{
		if(i < 10)
		{
			File5<<"0"<<i+1;
		}
		else
		{
			File5<<i+1;
		}
		File5<<"        "<<v2[i]<<endl;
	}

	File5.close();
	cout<<"Run Successfully!"<<endl;
	return 0;
}
