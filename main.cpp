#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector <string> S1CS,S2CS,S3CS,S4CS,S5CS,S6CS,S7CS,S8CS;
vector<string> DCS,DEE,DBBA,DMT,DEL,DIS,DSS;
int totalnumber1=0;
int totalnumber2=0;
string CS_Subjects[32];

string BoardsofPakistan [29];
string student_department[4];
string teacher_department[7];
void tcourse (vector<int>& x, vector<string>& y,vector<string> A)
{
    string temp;
    int temp_no;
    cout << "Enter the number of courses you want to teach(max 2):";
    cin>>temp_no;
    x.push_back(temp_no);
    cout << "Enter index:"<<endl;
    cin.ignore();
    for (int i=1; i<=temp_no; i++)
    {
        cout << i << ".";
        cin>>temp_no;
        y.push_back(A[temp_no-1]);
    }
}

string teacher_ID (int a)
{
    if (a==0)
    {
        return "NUMDCS-";
    }
    else if (a==1)
    {
        return "NUMDEE-";
    }
    else if (a==2)
    {
        return "NUMDBBA-";
    }
    else if (a==3)
    {
        return "NUMDMT-";
    }
    else if (a==4)
    {
        return "NUMDEL-";
    }
    else if (a==5)
    {
        return "NUMDIS-";
    }
    else if (a==6)
    {
        return "NUMDSS-";
    }
}
int tdep ()
{
   teacher_department[0]="Department of Computer Sciences"; teacher_department[1]="Department of Electrical Engineering"; teacher_department[2]="Department of Business Administration"; teacher_department[3]="Department of Mathematics";
   teacher_department[4]="Department of English literature"; teacher_department[5]="Department of Islamic Studies"; teacher_department[6]= "Department of Social Sciences";
   cout << "Select your department:"<<endl;
   for (int i=0; i<7; i++)
   {
       cout << i+1 << ")"<<teacher_department[i]<<endl;
   }
   int temp;
   cin>>temp;
   return (temp-1);
}
int teacher_degree ()
{
    cout << "Select your highest qualification:"<<endl;
    cout << "1)Ph.D\n2)M.Phil\n3)BS"<<endl;
    int x;
    cin>>x;
    return x;
}
string Assign_gender ()
{
    string temp1 = "Male", temp2 = "Female", temp3 = "Non-Binary";
    cout << "Select your gender:"<<endl;
    cout << "1)Male \n2)Female \n3)Non-binary"<<endl;
    int a;
    cin>>a;
    if(a==1)
    {
        return temp1;
    }
    else if (a==2)
    {
        return temp2;
    }
    else if (a==3)
    {
        return temp3;
    }
}
bool CNICC (long long int A)
{
    int c=0;
    while (A!=0)
    {
        A/=10;
        c++;
    }
    if (c==13)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void init ()
{
   DCS = {"Programming Fundamentals","Object Oriented Programming","Data Structures","Software Engineering","Computer Organization and Assembly Language","Database Systems","Analysis of Algorithms","Theory of Automata","Computer Architecture","Computer Networks",
    "Operating Systems","Information Security","Artificial Intelligence","HCI and Graphics","Advance Database Management System","Compiler Construction","Application of ICT","Human-Computer Interaction (HCI)","Big Data Analytics","Machine Learning","Cloud Computing",
    "Internet of Things (IoT)","Cybersecurity","Web Development","Mobile Application Development","Natural Language Processing","Computer Vision","Robotics","Game Development","Blockchain Technology","Data Mining","Parallel and Distributed Computing"};
    DEE = {"Functional English","Expository Writing","Technical and Business Writing","Great Books"};
    DIS = {"Islamic Studies and Ethics","Quranic Studies I","Quranic Studies II"};
    DSS = {"Iqbaliyat","Civics and Community Engagement","Introduction to Constitution of Pakistan","Professional Ethics","Entrepreneurship"};

    S1CS = {"Programming Fundamentals", "Discrete Structures", "Application of ICT", "Functional English", "Pakistan Studies", "Islamic Studies and Ethics"};
    S2CS = {"Object-Oriented Programming", "Calculus and Analytical Geometery", "Digital Logic Design", "Expository Writing", "Applied Physics"};
    S3CS = {"Data Structures", "Multivariable Calculus", "Linear Algebra", "Computer Organization", "Quranic Studies I", "Software Engineering"};
    S4CS = {"Database Systems", "Probability and Statistics", "Analysis of Algorithms", "Theory of Automata", "Computer Architecture", "Quranic Studies II"};
    S5CS = {"Artificial Intelligence", "Computer Networks", "Operating Systems", "Information Security", "Entrepreneurship", "Professional Practices"};
    S6CS = {"HCI and Graphics", "Advanced Database Management System", "Compiler Construction", "Iqbaliyat", "Domain Elective I", "Domain Elective II"};
    S7CS = {"Parallel and Distributive Computing", "Introduction to Business Management", "FYP-I", "Domain Elective 3", "Domain Elective 4", "Domain Elective 5"};
    S8CS = {"Civics and Community Engagement", "Technical and Business Writing", "FYP-2", "Domain Elective 6", "Domain Elective 7"};


    BoardsofPakistan[0]="BISE Federal"; BoardsofPakistan[1]="BISE AJK"; BoardsofPakistan[2]="BISE Quetta";BoardsofPakistan[3]="BISE Turbat"; BoardsofPakistan[4]="BISE Zhob"; BoardsofPakistan[5]="BISE Sawat"; BoardsofPakistan[6]="BISE DI Khan"; BoardsofPakistan[7]="BISE Mardan"; BoardsofPakistan[8]="BISE Peshawar"; BoardsofPakistan[9]="BISE Kohat"; BoardsofPakistan[10]="BISE Malakand"; BoardsofPakistan[11]= "BISE Abbotabad"; BoardsofPakistan[12]="BISE Bannu";
    BoardsofPakistan[13]= "BISE Hyderabad"; BoardsofPakistan[14]="BISE Larkana"; BoardsofPakistan[15]="BISE MirpurKhas"; BoardsofPakistan[16]="BISE Sukkur"; BoardsofPakistan[17]="BISE Karachi"; BoardsofPakistan[18]= "BSEK Karachi"; BoardsofPakistan[19]="BSEK Agha Khan";
    BoardsofPakistan[20] = "BISE Lahore"; BoardsofPakistan[21]="BISE Gujrawala"; BoardsofPakistan[22]= "BISE Sahiwal"; BoardsofPakistan[23]= "BISE Bahawalpur"; BoardsofPakistan[24]= "BISE DG Khan"; BoardsofPakistan[25]="BISE Faisalabad"; BoardsofPakistan[26]="BISE Multan"; BoardsofPakistan[27]="BISE Rawalpindi"; BoardsofPakistan[28]="BISE Sargodha";
}
void subject_allocation (string temp,vector<int> &x, vector<string> & y)
{
    init();
    if (temp=="Department of Computer Sciences")
    {
        for(int i=0; i<DCS.size(); i++)
        {
            cout << i+1 <<  ")"<<DCS[i]<<endl;
        }
        tcourse(x,y,DCS);
    }
    else if (temp=="Department of Electrical Engineering")
    {
        for(int i=0; i<DEE.size(); i++)
        {
            cout << i+1 <<  ")"<<DEE[i]<<endl;
        }
        tcourse(x,y,DEE);
    }
    else if (temp=="Department of Business Administration")
    {
        for(int i=0; i<DBBA.size(); i++)
        {
            cout << i+1 <<  ")"<<DBBA[i]<<endl;
        }
        tcourse(x,y,DBBA);
    }
    else if (temp=="Department of Mathematics")
    {
        for(int i=0; i<DMT.size(); i++)
        {
            cout << i+1 <<  ")"<<DMT[i]<<endl;
        }
        tcourse(x,y,DMT);
    }
    else if (temp=="Department of English literature")
    {
        for(int i=0; i<DEL.size(); i++)
        {
            cout << i+1 <<  ")"<<DEL[i]<<endl;
        }
        tcourse(x,y,DEL);
    }
    else if (temp=="Department of Islamic Studies")
    {
        for(int i=0; i<DIS.size(); i++)
        {
            cout << i+1 <<  ")"<<DIS[i]<<endl;
        }
        tcourse(x,y,DIS);
    }
    else if (temp=="Department of Social Sciences")
    {
        for(int i=0; i<DSS.size(); i++)
        {
            cout << i+1 <<  ")"<<DSS[i]<<endl;
        }
        tcourse(x,y,DSS);
    }
}
int dep ()
{
    int yourdepartmnet;
    student_department[0]="CS"; student_department[1]="EE"; student_department[2]="BBA"; student_department[3]="MATH";
    cout << "Select department:"<<endl;
    for (int i=0; i<4; i++)
    {
        cout << i+1 << ")"<<student_department[i]<<endl;
    }
    cin>>yourdepartmnet;
    return (yourdepartmnet-1);
}
int eduation_board ()
{
    init();
    int board;
    cout << "Select Province:"<<endl;
    cout << "1)Islamabad\n2)Punjab\n3)Sindh\n4)Kyber Pakhtunkhaw\n5)Balochistan\n6)Azad-Jammu Kashmir"<<endl;
    int province;
    cin>>province;
    cout << "Select Board:"<<endl;
    if (province==1)
    {
        cout <<"1)"<< BoardsofPakistan[0]<<endl;
        cin>>board;
        return (board-1);
    }
    if (province==2)
    {
        for (int i=1; i<10; i++)
        {
            cout<< i<<")" << BoardsofPakistan[i+19]<<endl;
        }
        cin>>board;
        return (board+19);
    }
    if (province==3)
    {
        for (int i=1; i<8; i++)
        {
            cout << i << ")" << BoardsofPakistan[i+12]<<endl;
        }
        cin >> board;
        return (board+12);
    }
    if (province==4)
    {
        for (int i=1; i<9; i++)
        {
            cout << i << ")"<< BoardsofPakistan[i+5]<<endl;
        }
        cin>>board;
        return (board+5);
    }
    if (province==5)
    {
        for (int i=1; i<4; i++)
        {
            cout << i << ")" << BoardsofPakistan[i+1]<<endl;
        }
        cin>>board;
        return (board+1);
    }
    if (province==6)
    {
        cout << "1)" << BoardsofPakistan[1];
    }
    cin>>board;
    return board;
}
bool checkCaptcha(string& captcha, string& user_captcha)
{
    return captcha.compare(user_captcha) == 0;
}
string generateCaptcha(int n)
{

    time_t t;
    srand((unsigned)time(&t));
    char* chrs = "abcdefghijklmnopqrstuvwxyzABCDEFGHI"
                 "JKLMNOPQRSTUVWXYZ0123456789";
    string captcha = "";
    while (n--)
        captcha.push_back(chrs[rand() % 62]);

    return captcha;
}
class admin
{
private:
    string number[100];
    int matric_number[100];
    int inter_number[100];
    string city[100];
    string adress[100];
    string fname[100];
    string matricboard[100];
    string interboard[100];
    int matricyear[100];
    int interyear[100];
    long long int CNIC[100];
    string DOB[100];
    string tBS[100];
    int tBS_year[100];
    string tBS_inst[100];
    string tMPhil [100];
    int tMPhil_year[100];
    string tMPhil_inst[100];
    string tPHD[100];
    string tPHD_inst[100];
    string tWexp_inst1[100];
    string tWexp_inst2[100];
    string tWexp_inst3[100];
    string gender[100];
protected:
    string department [100];
    string name[1000];
    string regno[1000];
    string student_semester[200];
public:

    void student_input (int limit)
    {
        int year;
        int years[4]={2022,2023,2024,2025};
        cout<<"Enter Year :"<<endl;
        cout<<"1_ 2022"<<"                  2_2023"<<endl;
        cout<<"3_ 2024"<<"                  4_2025"<<endl;
        cin>>year;
        year=year-1;
        for (int i=totalnumber1; i<(totalnumber1+limit); i++)
        {
            cin.ignore();
            cout << "PERSONAL DETAILS:"<<endl;
            cout << "Enter name:";
            getline(cin,name[i]);
            cout << "Enter Father's name:";
            getline(cin,fname[i]);
            cout << "Enter your Date of birth in format (dd-mm-yyyy):";
            getline(cin,DOB[i]);
            do
            {
             cout << "Enter your CNIC number (13-digit):";
             cin>>CNIC[i];
            }
            while (CNICC(CNIC[i]!=true));
            cin.ignore();
            cout << "Enter your city name:";
            getline(cin,city[i]);
            cout << "Enter your address:";
            getline(cin,adress[i]);
            cout << "Enter your phone number:";
            cin>>number[i];
            cout << "EDUCATIONAL DETAILS:"<<endl;
            cout << "Enter your Matric marks:";
            cin >> matric_number[i];
            cout << "Enter year of passing:";
            cin>>matricyear[i];
            matricboard[i]= BoardsofPakistan[eduation_board()];
            cout << "Enter your Intermediate marks:";
            cin>> inter_number[i];
            cout << "Enter year of passing:";
            cin>>interyear[i];
            interboard[i]= BoardsofPakistan[eduation_board()];
            department[i]=student_department[dep()];
            regno[i] = "NUM-BS-" + department[i] + to_string(years[year])+ "-" + to_string(i+1);

            if (year==0)
            {
                string temp1;
                temp1 = department[i] + " -1st Semster";
                student_semester[i]=temp1;
            }
            else if(year==1)
            {
               string temp2;
                temp2= department[i] + " -3rd Semster";
                student_semester[i]=temp2;
            }
            else if(year==2)
            {
               string temp3;
                temp3= department[i] + " -5th Semster";
                student_semester[i]=temp3;
            }
            else if(year==3)
            {
               string temp4;
                temp4= department[i] + " -7th Semster";
                student_semester[i]=temp4;
            }

            cout <<endl;

        }
        totalnumber1+=limit;
    }

    void student_display ()
    {
         for (int i=0; i<totalnumber1; i++)
        {
            cout << i+1<<")Name:"<<name[i]<<endl;
            cout << "Father's name:"<<fname[i]<<endl;
            cout << "Registration number:"<< regno[i]<<endl;
            cout << "Department:"<< department[i]<<endl;
           cout<<"Department:"<<student_semester[i]<<endl;
            cout << "Matric marks:"<<matric_number[i]<<endl;
            cout << "Matric Board:"<<matricboard[i]<<endl;
            cout << "Intermediate marks:"<<inter_number[i]<<endl;
            cout << "Inter Board:"<<interboard[i]<<endl;
            cout << "City:"<<city[i]<<endl;
            cout << "Address:"<<adress[i]<<endl;
            cout << "Phone number:"<<number[i]<<endl;
            cout <<endl;

        }
    }
     void teacher_input (int limit)
    {
        loadDataFromFileT();
        for (int i=totalnumber2; i<(totalnumber2+limit); i++)
        {
            cin.ignore();
            cout << "PERSONAL DETAILS:"<<endl;
            cout << "Enter name:";
            getline(cin,name[i]);
            cout << "Enter Father's name:";
            getline(cin,fname[i]);
            cout << "Enter your Date of birth in format (dd-mm-yyyy):";
            getline(cin,DOB[i]);
            do
            {
             cout << "Enter your CNIC number (13-digit):";
             cin>>CNIC[i];
            }
            while (CNICC(CNIC[i])!=true);
            gender[i]= Assign_gender();
            cin.ignore();
            cout << "Enter your city name:";
            getline(cin,city[i]);
            cout << "Enter your address:";
            getline(cin,adress[i]);
            cout << "Enter your phone number:";
            cin>>number[i];
            cout << "EDUCATIONAL DETAILS:"<<endl;
            int t;
            t = teacher_degree();
            if (t==1)
            {
                cout << "Enter your Ph.D Subject:";
                cin.ignore();
                getline(cin,tPHD[i]);
                cout << "Institute:";
                getline(cin,tPHD_inst[i]);
                cout << "Enter your MPhil degree name:";
                getline(cin, tMPhil[i]);
                cout << "Year of completion:";
                cin>>tMPhil_year[i];
                cin.ignore();
                cout << "Institute:";
                getline(cin,tMPhil_inst[i]);
                cout << "Enter the name of your Bachelors' degree:";
                getline(cin,tBS[i]);
                cout << "Year of completion:";
                cin>>tBS_year[i];
                cin.ignore();
                cout << "Institute:";
                getline(cin, tBS_inst[i]);
            }
            if (t==2)
            {

                tPHD[i]="0";
                tPHD_inst[i]="0";
                cout << "Enter your MPhil degree name:";
                cin.ignore();
                getline(cin, tMPhil[i]);
                cout << "Year of completion:";
                cin>>tMPhil_year[i];
                cin.ignore();
                cout << "Institute:";
                getline(cin,tMPhil_inst[i]);
                cout << "Enter the name of your Bachelors' degree:";
                getline(cin,tBS[i]);
                cout << "Year of completion:";
                cin>>tBS_year[i];
                cin.ignore();
                cout << "Institute:";
                getline(cin, tBS_inst[i]);
            }
            if (t==3)
            {

                tPHD[i]= "0";
                tPHD_inst[i]= "0";
                tMPhil[i]= "0";
                tMPhil_year[i]=0;
                tMPhil_inst[i]= "0";
                cout << "Enter the name of your Bachelors' degree:";
                cin.ignore();
                getline(cin,tBS[i]);
                cout << "Year of completion:";
                cin>>tBS_year[i];
                cin.ignore();
                cout << "Institute:";
                getline(cin, tBS_inst[i]);
            }
            cout << "Enter your Intermediate marks:";
            cin>> inter_number[i];
            cout << "Enter year of passing:";
            cin>>interyear[i];
            interboard[i]= BoardsofPakistan[eduation_board()];
            cout << "Enter your Matric marks:";
            cin >> matric_number[i];
            cout << "Enter year of passing:";
            cin>>matricyear[i];
            matricboard[i]= BoardsofPakistan[eduation_board()];
            cin.ignore();
            string temp1;
            string temp2;
            cout << "WORK EXPERINECE:"<<endl;
            cout << "(enter 0 otherwise)"<<endl;
            cout << "Name of Institute-1:";
            getline(cin,temp1);
            if (temp1!="0")
            {
                cout << "Years (X-Y)";
                getline(cin,temp2);
                tWexp_inst1[i]= temp1 + "-" + temp2;
                cout << "Name of Institute-2:";
                getline(cin,temp1);
                if (temp1!="0")
                {
                    cout << "Years (X-Y)";
                    getline(cin,temp2);
                    tWexp_inst2[i]= temp1 + "-" + temp2;
                    cout << "Name of Institute-3:";
                    getline(cin,temp1);
                    if (temp1!="0")
                    {
                        cout << "Years (X-Y)";
                        getline(cin,temp2);
                        tWexp_inst3[i]= temp1 + "-" + temp2;
                    }
                    else
                    {
                        tWexp_inst3[i]= "0";
                    }

                }
                else
                {
                    tWexp_inst2[i] = "0";
                    tWexp_inst3[i] = "0";
                }
            }
            else
            {
                tWexp_inst1[i] = "0";
                tWexp_inst2[i] = "0";
                tWexp_inst3[i] = "0";
            }
            int temp;
            temp = tdep();
            department[i] = teacher_department[temp];
            regno[i] = teacher_ID(temp) + "2400" + to_string(i+1);
            cout <<endl;

        }
        totalnumber2+=limit;
        loadDatatoFileT();
    }


    void teacher_display ()
    {
         for (int i=0; i<totalnumber2; i++)
        {
            cout << i+1<<")Name:"<<name[i]<<endl;
            cout << "Father's name:"<<fname[i]<<endl;
            cout << "DOB:"<<DOB[i]<<endl;
            cout << "Gender:"<<gender[i]<<endl;
            cout << "Department:"<< department[i]<<endl;
            cout << "Teacher ID:" << regno[i]<<endl;
            cout << "Matric marks:"<<matric_number[i]<<endl;
            cout << "Matric Board:"<<matricboard[i]<<endl;
            cout << "Intermediate marks:"<<inter_number[i]<<endl;
            cout << "Inter Board:"<<interboard[i]<<endl;
            cout << "BS Degree:"<<tBS[i]<<endl;
            cout << "BS Institute:"<<tBS_inst[i]<<endl;
            if(tMPhil[i]!= "0")
            {
                cout << "MPhil:"<< tMPhil[i]<<endl;
                if (tPHD[i]!= "0")
                {
                    cout << "Ph.D Subject:"<<tPHD[i]<<endl;
                }
            }
            cout << "Work Experience:"<<endl;
            if (tWexp_inst1[i]!= "0")
            {
                cout << "1."<<tWexp_inst1[i]<<endl;
                if(tWexp_inst2[i]!= "0")
                {
                  cout << "2."<<tWexp_inst2[i]<<endl;
                  if (tWexp_inst3[i]!= "0")
                  {
                     cout << "3."<<tWexp_inst3[i]<<endl;
                  }
                }
            }
            else
            {
                cout << "No work Experience"<<endl;
            }
            cout << "City:"<<city[i]<<endl;
            cout << "Address:"<<adress[i]<<endl;
            cout << "Phone number:"<<number[i]<<endl;
            cout <<endl;

        }
    }
    void loadDatatoFileS ()
    {
        ofstream studentDataFile ("Student_data.txt");
        ofstream totalnumber1File ("Total_number1.txt");
        for (int i=0; i<totalnumber1; i++)
        {
          studentDataFile << name[i] << "," << fname[i] << "," <<DOB[i]<< "," << CNIC[i] << "," << regno[i] << "," << department[i]<<","<<student_semester[i] << "," << matric_number[i] << "," << matricyear[i] << "," << matricboard[i] << "," << inter_number[i] << "," << interyear[i] << "," <<
          interboard[i] << ","  << city[i] << "," << adress[i] << ","  << number[i]<<endl;
        }
        studentDataFile.close();
        totalnumber1File << totalnumber1;
        totalnumber1File.close();
    }
    void loadDataFromFileS()
    {
        ifstream studentDataFile ("Student_data.txt");
        ifstream totalnumber1File ("Total_number1.txt");
        vector <string> lines;
        string line;
        while (getline(studentDataFile,line))
        {

            if (line.empty())
            {
                break;
            }
            lines.push_back(line);
        }
        studentDataFile.close();
        for (int i=0; i<lines.size(); i++)
        {
            stringstream A(lines[i]);
            string B;
            getline(A,name[i],',');
            getline(A,fname[i], ',');
            getline(A,DOB[i], ',');
            getline(A,B, ',');
            CNIC[i]= stoll(B);
            getline(A,regno[i],',');
            getline(A,department[i], ',');
            getline(A,student_semester[i],',');
            getline(A,B, ',');
            matric_number[i]= stoi(B);
            getline(A,B, ',');
            matricyear[i] = stoi(B);
            getline(A,matricboard[i], ',');
            getline(A,B, ',');
            inter_number[i] = stoi(B);
            getline(A,B, ',');
            interyear[i] = stoi(B);
            getline(A,interboard[i], ',');
            getline(A,city[i], ',');
            getline(A,adress[i], ',');
            getline(A,number[i], ',');

        }
        totalnumber1File>>totalnumber1;
        totalnumber1File.close();
    }
  void loadDatatoFileT()
   {
        ofstream teacherDataFile("Teacher_data.txt");
        ofstream totalnumber2File("Total_number2.txt");
        for (int i = 0; i < totalnumber2; i++)
        {
            teacherDataFile << name[i] << "," << fname[i] << "," << DOB[i] << "," << CNIC[i] << "," << city[i] << "," << adress[i] << "," << number[i] << "," << gender[i] << "," << matric_number[i] << "," << matricyear[i] << ","
            << matricboard[i] << "," << inter_number[i] << "," << interyear[i] << "," << interboard[i] << "," << tBS[i] << "," << tBS_year[i] << "," << tBS_inst[i] << "," << tMPhil[i] << "," << tMPhil_year[i] << "," << tMPhil_inst[i]
            << "," << tPHD[i] << "," << tPHD_inst[i] << "," << tWexp_inst1[i] << "," << tWexp_inst2[i] << "," << tWexp_inst3[i] << "," << department[i] << "," <<regno[i]<< endl;
        }
        teacherDataFile.close();
        totalnumber2File << totalnumber2;
        totalnumber2File.close();
    }

    void loadDataFromFileT()
    {
        ifstream teacherDataFile("Teacher_data.txt");
        ifstream totalnumber2File("Total_number2.txt");
        vector<string> lines;
        string line;
        while (getline(teacherDataFile, line)) {
            lines.push_back(line);
        }
        teacherDataFile.close();
        for (int i = 0; i < lines.size(); i++) {
            stringstream A(lines[i]);
            string B;
            getline(A, name[i], ',');
            getline(A, fname[i], ',');
            getline(A, DOB[i], ',');
            getline(A, B, ',');
            CNIC[i] = stoll(B);
            getline(A, city[i], ',');
            getline(A, adress[i], ',');
            getline(A, number[i], ',');
            getline(A, gender[i], ',');
            getline(A, B, ',');
            matric_number[i] = stoi(B);
            getline(A, B, ',');
            matricyear[i] = stoi(B);
            getline(A, matricboard[i], ',');
            getline(A, B, ',');
            inter_number[i] = stoi(B);
            getline(A, B, ',');
            interyear[i] = stoi(B);
            getline(A, interboard[i], ',');
            getline(A, tBS[i], ',');
            getline(A, B, ',');
            tBS_year[i] = stoi(B);
            getline(A, tBS_inst[i], ',');
            getline(A, tMPhil[i], ',');
            getline(A, B, ',');
            tMPhil_year[i] = stoi(B);
            getline(A, tMPhil_inst[i], ',');
            getline(A, tPHD[i], ',');
            getline(A, tPHD_inst[i], ',');
            getline(A, tWexp_inst1[i], ',');
            getline(A, tWexp_inst2[i], ',');
            getline(A, tWexp_inst3[i], ',');
            getline(A, department[i], ',');
            getline(A, regno[i], ',');
        }
        totalnumber2File >> totalnumber2;
        totalnumber2File.close();
    }
};

class Teacher : public admin
{
private:
    vector<string> teacher_name;
    vector<string> teacher_password;
    vector<int> teacher_numberofcourses;
    vector<string> teacher_courses;
    vector<string> teacher_ID;
    vector<string> teacher_classes;

public:
 void teacher_credentials (int index)
 {
    loadDataFromFileT();
    LoadTeacherCredentialsFromFile();
    string temp;
    int temp_no;
    cout << "Name:"<<name[index]<<endl;
    cout << "ID:" <<regno[index]<<endl;
    teacher_name.push_back(name[index]);
    teacher_ID.push_back(regno[index]);
    cout << "Enter your password:";
    getline(cin,temp);
    teacher_password.push_back(temp);
    cout << department[index]<<endl;
    subject_allocation(department[index],teacher_numberofcourses,teacher_courses);
    LoadTeacherCredentailstoFile();
 }

 void display_teacher_credentials ()
 {
    int x=0;
    for (int i=0; i<teacher_name.size(); i++)
    {
       cout << "Name:"<<teacher_name[i]<<endl;
       cout << "ID:"<<teacher_ID[i]<<endl;
       cout << "Number of Courses:"<<teacher_numberofcourses[i]<<endl;
       int y=1;
       for (int l=x; l<x+teacher_numberofcourses[i]; l++)
       {
           cout << y << ")"<<teacher_courses[l]<<endl;
           y++;
       }
       x+=teacher_numberofcourses[i];
       cout << endl;
    }
 }

 void LoadTeacherCredentailstoFile ()
 {
        int x=0;
        ofstream TeacherCredentialsFile ("TCredentials.txt");
        for (int i=0; i<teacher_name.size(); i++)
        {
            TeacherCredentialsFile << teacher_name[i] << "," << teacher_password[i] << "," <<  teacher_ID[i] << "," << teacher_numberofcourses[i];
            for (int l=x; l<x+teacher_numberofcourses[i]; l++)
            {

                TeacherCredentialsFile << "," <<teacher_courses[l];
            }
            x+=teacher_numberofcourses[i];
            TeacherCredentialsFile<<endl;
        }
        TeacherCredentialsFile.close();
 }

 void LoadTeacherCredentialsFromFile()
 {
    int x=0;
    ifstream TeacherCredentialsFile("TCredentials.txt");
    string line;

    while (getline(TeacherCredentialsFile, line))
    {
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        teacher_name.push_back(token);
        getline(ss, token, ',');
        teacher_password.push_back(token);
        getline(ss,token, ',');
        teacher_ID.push_back(token);
        getline(ss, token, ',');
        int numCourses = stoi(token);
        teacher_numberofcourses.push_back(numCourses);
        for (int i = x; i < numCourses; ++i)
        {
            getline(ss, token, ',');
            teacher_courses.push_back(token);
        }
        x+=numCourses;
    }
    TeacherCredentialsFile.close();
 }

 int check1Tnameforlogin (string tname)
 {
    loadDataFromFileT();
    for (int i=0; i<totalnumber2; i++)
    {
        if (tname==name[i])
        {
            return i;
        }
    }
    return -1;
 }

 bool check2Tnameforlogin (string tname)
 {
    LoadTeacherCredentialsFromFile();
    for (int i=0; i<teacher_name.size(); i++)
    {
        if (tname==teacher_name[i])
        {
            return false;
        }
    }
    return true;
 }
bool check3TCredentialsforlogin (string tname, string tpassword)
{
    LoadTeacherCredentialsFromFile();
    for (int i=0; i<teacher_name.size();i++)
    {
        if(tname==teacher_name[i])
        {
            if(tpassword==teacher_password[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    }
}
string check4TCredentialsforlogin (string tID, string tname)
{
    LoadTeacherCredentialsFromFile();
    string message = "Come again next time!";
    for (int i=0; i<teacher_ID.size(); i++)
    {
        if (tID==teacher_ID[i])
        {
            teacher_name[i]==tname;
            return teacher_password[i];
        }
        else
        {
            return message;
        }
    }
}
bool check5TCredentialsforlogin (string tname)
{
    LoadTeacherCredentialsFromFile();
    for (int i=0; i<teacher_name.size(); i++)
    {
        if (tname==teacher_name[i])
        {
            return true;
        }
    }
    return false;
}
};
class student:public admin
{
private:
    vector<string> student_name;
    vector<string> student_password;
    vector<string> student_ID;
    vector<string>student_s;

public:
void student_credentials (int in)
 {
    loadDataFromFileS();
    LoadstudentCredentialsFromFile();
    string temp1;
    int temp_no1;
    cout << "Name:"<<name[in]<<endl;
    cout << "ID:" <<regno[in]<<endl;
    cout<<"Department:"<<student_semester[in]<<endl;
    student_name.push_back(name[in]);
    student_ID.push_back(regno[in]);
    student_s.push_back(student_semester[in]);
    cout << "Enter your password:";
    getline(cin,temp1);
    student_password.push_back(temp1);
    LoadstudentCredentailstoFile();
 }
void display_student_credentials ()
 {
    for (int i=0; i<student_name.size(); i++)
    {
       cout << "Name:"<<student_name[i]<<endl;
       cout << "ID:"<<student_ID[i]<<endl;
       cout<<"Department:"<<student_semester[i]<<endl;
       cout << endl;
    }
 }
 void LoadstudentCredentialsFromFile()
 {
     string line1;
     ifstream studentCredentialsFile("sCredentials.txt");
    while (getline(studentCredentialsFile, line1))
    {
        if (line1.empty())
        {
            break;
        }
        stringstream ss1(line1);
        string token1;
        getline(ss1, token1, ',');
        student_name.push_back(token1);
        getline(ss1, token1, ',');
        student_password.push_back(token1);
        getline(ss1,token1, ',');
        student_ID.push_back(token1);
        getline(ss1,token1, ',');
        student_s.push_back(token1);
        }
        studentCredentialsFile.close();
 }
  void LoadstudentCredentailstoFile ()
 {
        ofstream studentCredentialsFile ("sCredentials.txt");
        for (int i=0; i<student_name.size(); i++)
        {
            studentCredentialsFile << student_name[i] << "," << student_password[i] << "," <<  student_ID[i]<<","<<student_s[i];
            studentCredentialsFile<<endl;
        }
        studentCredentialsFile.close();
 }

int check1snameforlogin(string stname)
{
       loadDataFromFileS();
        for(int i=0; i<totalnumber1; i++)
        {
            if(stname==name[i])
            {
                return i;
            }
        }
        return -1;
}
 bool check2snameforlogin (string stname)
 {
    LoadstudentCredentialsFromFile();
    for (int i=0; i<student_name.size(); i++)
    {
        if (stname==student_name[i])
        {
            return false;
        }
    }
    return true;
 }
bool check3sCredentialsforlogin (string sname, string spassword)
{
    LoadstudentCredentialsFromFile();
    for (int i=0; i<student_name.size();i++)
    {
        if(sname==student_name[i])
        {
            if(spassword==student_password[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    }
}
string check4sCredentialsforlogin (string sID, string sname)
{
    LoadstudentCredentialsFromFile();
    string message = "Come again next time!";
    for (int i=0; i<student_ID.size(); i++)
    {
        if (sID==student_ID[i])
        {
           if( student_name[i]==sname)
           {
            return student_password[i];
           }
        }
        else
        {
            return message;
        }
    }
}
bool check5sCredentialsforlogin (string sname)
{
    LoadstudentCredentialsFromFile();
    for (int i=0; i<student_name.size(); i++)
    {
        if (sname==student_name[i])
        {
            return true;
        }
    }
    return false;
}




};
class Class:public admin
{
private:
  vector<string>temp1;
   vector<string>temp2;
   public:

  void loaddatacs1tofile()
  {
      for(int i=0; i<totalnumber1; i++)
      {
          if(student_semester[i]=="CS-1st semster")
          {
              temp1.push_back(name[i]);
              temp2.push_back(regno[i]);
          }
      }
      ofstream datacsto("CS-1st semster.txt");
      for(int i=0; i<temp1.size(); i++)
      {
          datacsto<< temp1[i]<<","<<temp2[i]<<endl;
      }

       datacsto.close();
  }
  void loaddatacs1fromfile()
  {
      string line;
      ifstream datacsf("CS-1st semster.txt");
      while(getline(datacsf,line))
      {
          if(line.empty())
          {
              break;
          }
          stringstream sss(line);
          string name,regno;
          getline(sss,name,',');
          temp1.push_back(name);
           getline(sss,regno,',');
          temp2.push_back(regno);
      }
      datacsf.close();
  }
   void loaddatacs2tofile()
  {
      for(int i=0; i<totalnumber1; i++)
      {
          if(student_semester[i]=="CS-2nd semster")
          {
              temp1.push_back(name[i]);
              temp2.push_back(regno[i]);
          }
      }
      ofstream datacs1to("CS-2nd semster.txt");
      for(int i=0; i<temp1.size(); i++)
      {
          datacs1to<< temp1[i]<<","<<temp2[i]<<endl;
      }

       datacs1to.close();
  }
  void loaddatacs2fromfile()
  {
      string line;
      ifstream datacs1f("CS-2nd semster.txt");
      while(getline(datacs1f,line))
      {
          if(line.empty())
          {
              break;
          }
          stringstream sss(line);
          string name,regno;
          getline(sss,name,',');
          temp1.push_back(name);
           getline(sss,regno,',');
          temp2.push_back(regno);
      }
      datacs1f.close();
  }
    void loaddatacs3tofile()
  {
      for(int i=0; i<totalnumber1; i++)
      {
          if(student_semester[i]=="CS-3rd semster")
          {
              temp1.push_back(name[i]);
              temp2.push_back(regno[i]);
          }
      }
      ofstream datacs2to("CS-3rd semster.txt");
      for(int i=0; i<temp1.size(); i++)
      {
          datacs2to<< temp1[i]<<","<<temp2[i]<<endl;
      }

       datacs2to.close();
  }
  void loaddatacs3fromfile()
  {
      string line;
      ifstream datacs2f("CS-3rd semster.txt");
      while(getline(datacs2f,line))
      {
          if(line.empty())
          {
              break;
          }
          stringstream sss(line);
          string name,regno;
          getline(sss,name,',');
          temp1.push_back(name);
           getline(sss,regno,',');
          temp2.push_back(regno);
      }
      datacs2f.close();
  }
  void loaddatacs4tofile()
  {
      for(int i=0; i<totalnumber1; i++)
      {
          if(student_semester[i]=="CS-4th semster")
          {
              temp1.push_back(name[i]);
              temp2.push_back(regno[i]);
          }
      }
      ofstream datacs3to("CS-4th semster.txt");
      for(int i=0; i<temp1.size(); i++)
      {
          datacs3to<< temp1[i]<<","<<temp2[i]<<endl;
      }

       datacs3to.close();
  }
  void loaddatacs4fromfile()
  {
      string line;
      ifstream datacs3f("CS-4th semster.txt");
      while(getline(datacs3f,line))
      {
          if(line.empty())
          {
              break;
          }
          stringstream sss(line);
          string name,regno;
          getline(sss,name,',');
          temp1.push_back(name);
           getline(sss,regno,',');
          temp2.push_back(regno);
      }
      datacs3f.close();
  }
    void loaddataee1tofile()
  {
      for(int i=0; i<totalnumber1; i++)
      {
          if(student_semester[i]=="EE-1st semster")
          {
              temp1.push_back(name[i]);
              temp2.push_back(regno[i]);
          }
      }
      ofstream dataeeto("EE-1st semster.txt");
      for(int i=0; i<temp1.size(); i++)
      {
          dataeeto<< temp1[i]<<","<<temp2[i]<<endl;
      }

       dataeeto.close();
  }
  void loaddataee1fromfile()
  {
      string line;
      ifstream dataeef("EE-1st semster.txt");
      while(getline(dataeef,line))
      {
          if(line.empty())
          {
              break;
          }
          stringstream sss(line);
          string name,regno;
          getline(sss,name,',');
          temp1.push_back(name);
           getline(sss,regno,',');
          temp2.push_back(regno);
      }
      dataeef.close();
  }
   void loaddataee2tofile()
  {
      for(int i=0; i<totalnumber1; i++)
      {
          if(student_semester[i]=="EE-2nd semster")
          {
              temp1.push_back(name[i]);
              temp2.push_back(regno[i]);
          }
      }
      ofstream dataee1to("EE-2nd semster.txt");
      for(int i=0; i<temp1.size(); i++)
      {
          dataee1to<< temp1[i]<<","<<temp2[i]<<endl;
      }

       dataee1to.close();
  }
  void loaddataee2fromfile()
  {
      string line;
      ifstream dataee1f("EE-2nd semster.txt");
      while(getline(dataee1f,line))
      {
          if(line.empty())
          {
              break;
          }
          stringstream sss(line);
          string name,regno;
          getline(sss,name,',');
          temp1.push_back(name);
           getline(sss,regno,',');
          temp2.push_back(regno);
      }
      dataee1f.close();
  }
   void loaddataee3tofile()
  {
      for(int i=0; i<totalnumber1; i++)
      {
          if(student_semester[i]=="EE-3rd semster")
          {
              temp1.push_back(name[i]);
              temp2.push_back(regno[i]);
          }
      }
      ofstream dataee2to("EE-3rd semster.txt");
      for(int i=0; i<temp1.size(); i++)
      {
          dataee2to<< temp1[i]<<","<<temp2[i]<<endl;
      }

       dataee2to.close();
  }
  void loaddataee3fromfile()
  {
      string line;
      ifstream dataee2f("EE-3rd semster.txt");
      while(getline(dataee2f,line))
      {
          if(line.empty())
          {
              break;
          }
          stringstream sss(line);
          string name,regno;
          getline(sss,name,',');
          temp1.push_back(name);
           getline(sss,regno,',');
          temp2.push_back(regno);
      }
      dataee2f.close();
  }
   void loaddataee4tofile()
  {
      for(int i=0; i<totalnumber1; i++)
      {
          if(student_semester[i]=="EE-4th semster")
          {
              temp1.push_back(name[i]);
              temp2.push_back(regno[i]);
          }
      }
      ofstream dataee3to("EE-4th semster.txt");
      for(int i=0; i<temp1.size(); i++)
      {
          dataee3to<< temp1[i]<<","<<temp2[i]<<endl;
      }

       dataee3to.close();
  }
  void loaddataee4fromfile()
  {
      string line;
      ifstream dataee3f("EE-4th semster.txt");
      while(getline(dataee3f,line))
      {
          if(line.empty())
          {
              break;
          }
          stringstream sss(line);
          string name,regno;
          getline(sss,name,',');
          temp1.push_back(name);
           getline(sss,regno,',');
          temp2.push_back(regno);
      }
      dataee3f.close();
  }

};
int main ()
{


    int program1=0;
    cout << "                                            WELCOME TO DB&LMA!!"<<endl;
    do
    {
        cout << "                                             Select Your Role:"<<endl;
        cout << "                                              1)ADMIN"<<endl;
        cout << "                                              2)TEACHER"<<endl;
        cout << "                                              3)STUDENT"<<endl;
        cout << "                                              4)Exit"<<endl;
        int role;
        cin>>role;
        admin obj1;
        admin obj2;
        Teacher obj3;
        student obj4;
        if (role==1)
        {
            int program2=0;
            do
            {
                cout << "Do you want to \n1)Enter Data\n2)Display Data\n3)Exit"<<endl;
                int choice1;
                cin>>choice1;
                if (choice1==1)
                {
                    cout << "Do you want to enter \n1)Student Data\n2)Teacher Data"<<endl;
                    int choice2;
                    cin>>choice2;
                    if (choice2==1)
                    {
                        obj1.loadDataFromFileS();
                        int limit;
                        cout << "How many students data you want to enter?";
                        cin>>limit;
                        obj1.student_input(limit);
                        obj1.student_display();
                        obj1.loadDatatoFileS();
                    }
                    else if (choice2==2)
                    {

                        int limit;
                        cout << "How many teachers' data you want to enter?";
                        cin>>limit;
                        obj2.teacher_input(limit);
                        obj2.teacher_display();

                    }
                }
                else if (choice1==2)
                {
                    cout << "Do you want to display \n1)Student Data\n2)Teacher Data"<<endl;
                    int choice2;
                    cin>>choice2;
                    if (choice2==1)
                    {
                        obj1.loadDataFromFileS();
                        obj1.student_display();
                    }
                    else if (choice2==2)
                    {
                        obj2.loadDataFromFileT();
                        obj2.teacher_display();
                    }
                }
                else if (choice1==3)
                {
                    break;
                }
            }
            while(program2==0);
        }
        else if (role==2)
        {
            int program3=0;
            do
            {
                cout << "1)Register \n2)Login \n3)Exit"<<endl;
                int choice2;
                cin>>choice2;
                if (choice2==1)
                {
                    cout << "Enter your name:";
                    string tempname;
                    cin.ignore();
                    getline(cin,tempname);
                    if (obj3.check1Tnameforlogin(tempname)!=-1)
                    {
                         obj3.teacher_credentials(obj3.check1Tnameforlogin(tempname));
                        if(obj3.check2Tnameforlogin(tempname)==true)
                        {
                            obj3.teacher_credentials(obj3.check1Tnameforlogin(tempname));
                            obj3.display_teacher_credentials();
                            break;
                        }
                        else if (obj3.check2Tnameforlogin(tempname)==false)
                        {
                            cout << "You are already registered, please login now!"<<endl;
                        }
                    }
                    else if (obj3.check1Tnameforlogin(tempname)==-1)
                    {
                        cout << "Your name doesn't exist in our system. Please request Admin to first enter your data"<<endl;
                        cout << "Do you want to send request to Admin (0/1):"<<endl;
                        bool request;
                        cin>>request;
                        if (request==0)
                        {
                            cout << "See you next time"<<endl;
                            break;
                        }
                        else if (request==1)
                        {
                            for (int i=1; i<=3; i++)
                            {
                                string captcha = generateCaptcha(7);
                                cout << captcha;
                                string user_captcha;
                                cout << "\nEnter above CAPTCHA to verify your request:";
                                cin >> user_captcha;
                                if (checkCaptcha(captcha, user_captcha)==true)
                                {
                                    cout << "Your request has been successfully accepted"<<endl;
                                    obj2.teacher_input(1);
                                    break;
                                }
                                else
                                {
                                    if (i<=2)
                                    {
                                       cout << "Try again"<<endl;
                                    }
                                    else
                                    {

                                    }
                                }
                            }
                        }
                    }
                }
                else if (choice2==2)
                {

                    string name;
                    string password;
                    string ID;
                    cin.ignore();
                    cout << "Enter your name:";
                    getline(cin,name);
                    if(obj3.check5TCredentialsforlogin(name)==true)
                    {
                        for (int i=1; i<=4; i++)
                        {
                            cout << "Enter your password:";
                            cin>>password;
                            if(obj3.check3TCredentialsforlogin(name,password)==true)
                            {
                                cout << "WELCOME " << name<<endl;
                                //the reaming code after successful login will be written here
                                break;
                            }
                            else
                            {
                                if (i<=2)
                                {
                                    cout << "Incorrect Credentials"<<endl;
                                }
                                else if (i==3)
                                {
                                    string message = "Come again next time";
                                    cout << "Incorrect Credentials"<<endl;
                                    cout << "Enter your ID:";
                                    cin>>ID;
                                    if(obj3.check4TCredentialsforlogin(ID,name)!=message)
                                    {
                                        cout << "Your password is:"<<obj3.check4TCredentialsforlogin(ID,name)<<endl;
                                    }
                                    else
                                    {
                                        cout << obj3.check4TCredentialsforlogin(ID,name)<<endl;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    else if (obj3.check5TCredentialsforlogin(name)==false)
                    {
                        cout << "Register First!"<<endl;
                    }
                }
                else if (choice2==3)
                {
                    break;
                }
            }
            while(program3==0);
        }
        else if (role==3)
        {
            int program4=0;
            do{
                cout << "1)Register \n2)Login \n3)Exit"<<endl;
                int choice3;
                cin>>choice3;
                if(choice3==1)
                {
                    string stuname;
                     cout << "Enter your name:";
                      cin.ignore();
                    getline(cin,stuname);
                    if (obj4.check1snameforlogin(stuname)!=-1)
                    {
                       if(obj4.check2snameforlogin(stuname)==true)
                        {
                            obj4.student_credentials(obj4.check1snameforlogin(stuname));
                            obj4.display_student_credentials();
                            break;
                        }
                        else if (obj4.check2snameforlogin(stuname)==false)
                        {
                            cout << "You are already registered, please login now!"<<endl;

                        }


                    }
                    else if (obj4.check1snameforlogin(stuname)==-1)
                    {
                        cout << "Your name doesn't exist in our system. Please request Admin to first enter your data"<<endl;
                        cout << "Do you want to send request to Admin (0/1):"<<endl;
                        bool request1;
                        cin>>request1;
                          if (request1==0)
                        {
                            cout << "See you next time"<<endl;
                            break;
                        }
                        else if (request1==1)
                        {
                            for (int i=1; i<=3; i++)
                            {
                                string captcha = generateCaptcha(7);
                                cout << captcha;
                                string user_captcha;
                                cout << "\nEnter above CAPTCHA to verify your request:";
                                cin >> user_captcha;
                                if (checkCaptcha(captcha, user_captcha)==true)
                                {
                                    cout << "Your request has been successfully accepted"<<endl;
                                    obj2.student_input(1);
                                    break;
                                }
                                else
                                {
                                    if (i<=2)
                                    {
                                       cout << "Try again"<<endl;
                                    }
                                    else
                                    {

                                    }
                                }
                            }
                        }
                    }

                }
                 else if (choice3==2)
                {

                    string name;
                    string password;
                    string ID;
                    cin.ignore();
                    cout << "Enter your name:";
                    getline(cin,name);
                    if(obj4.check5sCredentialsforlogin(name)==true)
                    {
                        for (int i=1; i<=4; i++)
                        {
                            cout << "Enter your password:";
                            cin>>password;
                            if(obj4.check3sCredentialsforlogin(name,password)==true)
                            {
                                cout << "WELCOME " << name<<endl;
                                //the reaming code after successful login will be written here
                                break;
                            }
                            else
                            {
                                if (i<=2)
                                {
                                    cout << "Incorrect Credentials"<<endl;
                                }
                                else if (i==3)
                                {
                                    string message = "Come again next time";
                                    cout << "Incorrect Credentials"<<endl;
                                    cout << "Enter your ID:";
                                    cin>>ID;
                                    if(obj4.check4sCredentialsforlogin(ID,name)!=message)
                                    {
                                        cout << "Your password is:"<<obj4.check4sCredentialsforlogin(ID,name)<<endl;
                                    }
                                    else
                                    {
                                        cout << obj4.check4sCredentialsforlogin(ID,name)<<endl;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    else if (obj4.check5sCredentialsforlogin(name)==false)
                    {
                        cout << "Register First!"<<endl;
                    }
                }
                 else if (choice3==3)
                {
                    break;
                }
            }while(program4==0);

        }
        else if (role==4)
        {
            cout << "Thank you for using our system"<<endl;
            break;
        }
    }
    while(program1==0);


    return 0;
}

