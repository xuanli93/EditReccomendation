#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

void Search_Name_and_Change(string &first_name, string &Last_name, vector <string> &str)
{
    string str2 = first_name;
    string str3 = Last_name;
    string target = "Smith";
    int i = 0;
    for (; i < str.size(); i++)
    {
        string w = str[i];
        string Jonathan;
        Jonathan = w.substr(0, 8);
        if (Jonathan == "Jonathan")
        {
            w.replace(0, 8, str2, 0, str2.size());
        }
        str[i] = w;
        if (str[i] == target)
        {
            str[i] = Last_name;
        }
    }
}

void Search_SpecificWord_and_Replace(string &SpecificWord, vector <string> &str)
{
    string s;
    string target = SpecificWord;
    int i = 0;
    vector <string> Replacement_bank;
    
    
    //bleow codes provides user input interface, user can sepcify
    //which file to read
    //ifstream adjectivefile2("AdjectiveList2.txt");
    
    ifstream adjectivefile2;
    string filename;
    cout<<endl;
    cout<<"Enter the File name of your adjective2 file, ending with txt"<<endl;
    cin>>filename;
    adjectivefile2.open(filename.c_str());
    while(adjectivefile2.fail())
    {
        adjectivefile2.clear();
        cout<<"There is no such file, please enter again"<<endl;
        cin>>filename;
        adjectivefile2.open(filename.c_str());
    }
    cout<<"-------------------------------------------"<<endl;
    cout<<"adjective2 File Retrieved Successfully"<<endl;
    
    if (adjectivefile2.is_open())
    {
        while (getline(adjectivefile2, s))
        {
            istringstream iss(s);
            string word;
            while (iss >> word)
            {
                Replacement_bank.push_back(word);
            }
        }
        adjectivefile2.close();
    }
    
    for (; i< str.size(); i++)
    {
        if(str[i] == target)
        {
            int index = rand() % 5; //create a number randomly from 0 to 4
            /*cout<<index<<'\n';
             cout<<Replacement_bank[3]<<endl;
             cout<<Replacement_bank.size()<<endl;
             for (int j = 0; j<Replacement_bank.size();j++)
             {
             cout<<Replacement_bank[j]<<endl;
             }*/
            str[i] = Replacement_bank[index];
        }
        
    }
}

//the following function takes in the real user comment and convert it to our secret dmg
/*vector<string> conversion(){
    string letter ("abcdefghijklmnopqrstuvwxyz .");
    string binary[] = {"00000","00001","00010","00011","00100","00101","00110","00111","01000","01001","01010","01011","01100","01101","01110","01111","10000","10001","10010","10011","10100","10101","10110","10111","11000","11001","2","3"};
    cout<<"please enter the real comment you have on this student"<<endl;
    string test,placeholder;
    getline(cin, test);
    vector <string> test1;
    istringstream ss(test);
    while (ss>>placeholder)
    {
        test1.push_back(placeholder);
        test1.push_back(" ");
    }

    */


    /*for(vector<string>::iterator it = STRING.begin(); it!=STRING.end();++it){
     cout<<*it<<endl;
     }*/
    

    /*string user_input;
    for(int i=0; i< test1.size(); i++){
        for (int j=0; j< test1[i].size();j++){
            user_input.push_back(test1[i][j]);
        }
    }


    vector<string> numbers;
    cout<<letter.at(26)<<endl;
    for (int i=0; i<user_input.length()-1; i++)
    {
        for (int j=0; j<letter.length();j++)
        {
            if(letter.at(j)==user_input.at(i))
            {
                numbers.push_back(binary[j]);
            }
        }
    }
    return numbers;
}

*/


void change_name(string &first_name, string &Last_name)
{
    string s;
    vector <string> STRING;
    
    //bleow codes provides user input interface, user can sepcify
    //which file to read
    ifstream input;
    string filename;
    cout<<endl;
    cout<<"Enter the File name of your recommendation Template, including the subscript"<<endl;
    cin>>filename;
    input.open(filename.c_str());
    while(input.fail())
    {
        input.clear();
        cout<<"There is no such file, please enter again"<<endl;
        cin>>filename;
        input.open(filename.c_str());
    }
    
    cout<<"-------------------------------------------"<<endl;
    cout<<"Template Recommendation File Retrieved Successfully"<<endl;
    //ifstream myfile("recommandation.txt");
    if (input.is_open())
    {
        while (getline (input, s))
        {
            istringstream iss(s);
            string word;
            while (iss >> word)
            {
                STRING.push_back(word);
            }
            STRING.push_back("\n");
        }
        Search_Name_and_Change(first_name, Last_name, STRING);
        string word_replaced;
        cout<<"Please enter the specific word you are looking for to change"<<endl;
        cin>>word_replaced;
        Search_SpecificWord_and_Replace(word_replaced,STRING);
        //std::ofstream o("/home/xiao/Desktop/new_recommendation.txt");
        
        ofstream o;
        string output_filename;
        cout <<"-------------------------------------------"<<endl;
        cout << "Please name your output file ending with txt"<<endl;
        cin >> output_filename;
        o.open(output_filename.c_str());
        
        /*vector<string> criterion;
        criterion = conversion();
        vector<char> result1;
        for(int i=0; i< criterion.size(); i++){
            for (int j=0; j< criterion[i].size();j++){
                result1.push_back(criterion[i][j]);
            }
        }
        */
        for (int i = 0; i < STRING.size(); i++)
        {
            if (STRING[i] == "\n")
            {
                o << STRING[i];
            }
            else
            {
                o << STRING[i] <<" ";
            }
        }
        input.close();
    }
}

int main()
{
    srand(time(0));//this ensure a random number is generated between 0 and 4;
    cout<< "Please enter the name of the student you are recommending: " << endl;
    cout<< "First name, then space, then last name..." <<endl;
    cout<< "-------------------------------------------" <<endl;
    string full_name, name, first_name, Last_name;
    getline(cin, full_name);
    vector <string> N;
    istringstream ss(full_name);
    while (ss >> name)
    {
        N.push_back(name);
    }
    first_name = N[0];
    Last_name = N[1];
    change_name(first_name, Last_name);
    cout << "Proceeding..." <<endl;
    cout << "Done!" << endl;
}
