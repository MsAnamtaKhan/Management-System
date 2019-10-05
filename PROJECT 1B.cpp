#include<iostream>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<fstream>
#include <algorithm>
#include <iterator>
using namespace std;
//Function for validation of code
bool isValidCode(string code)
{int noofAlp=0;
int noofDig=0;
int i;
int length=code.length();
for (i=0;i<length;i++)
{ if (i<2)
{
if (code[i]>=65 && code[i]<=122)
 noofAlp=noofAlp+1;}
 else
 {
 	if (code[i]>=48 && code[i]<=57)
 	noofDig=noofDig+1;
 }
}  
    if (noofAlp==2 && noofDig==3)
    return 1;
    else
    return 0;
   }
   //Function for validation of course name
bool isValidCourseName(string name)
{   bool f1,f2=1;
    int length=name.length();
	for (int i=0;i<length;i++)
	{
		if (name[i]>=65 && name[i]<=122 || name[i]==32)
	      f1=1;
	      else
	      f2=0;
	}
	if (f1==1 && f2==1)
	return 1;
	else
	return 0;
}//Function for validation of credit hours
bool isValidCreditHours(int a)
{ 
	if (a>0 && a<4)
	return 1;
	else
	return 0;
}//Function for validation semmester
bool isValidSemmester(int a)
{
	if (a>0 && a<9)
	return 1;
	else 
	return 0;
}
//FUnction to add course
void AddCourse(string codeList[],int &i,string nameList[],int creditHoursList[],int semList[],string courseCode,string courseName,int creditHours,int semmester)
{  
	codeList[i]=courseCode;
    nameList[i]=courseName;
    creditHoursList[i]=creditHours;
    semList[i]=semmester;
    i++;

}//Function to add course
void EditCourse(string codeList[],string nameList[],int creditHoursList[],int semList[],string courseCode,string courseName,int creditHours,int semmester,bool &f)

{ int index,size=sizeof(codeList);
cout<<"size="<<size;
for (int j=0;j<=size;j++)
{ if (codeList[j]==courseCode)
{ index=j;
  codeList[index]=courseCode;
   nameList[index]=courseName;
   creditHoursList[index]=creditHours;
   semList[index]=semmester;}}
} //Function to delete course
void DeleteCourse(string codeList[],int &count,int s1,string nameList[],int creditHours[],int semList[],string coursecode,bool &f)
{
	for (int k=0;k<s1;k++)
{
    if (codeList[k]==coursecode)
        { for (int j=k;j<(s1-1);j++)
        {codeList[j]=codeList[j+1];
        nameList[j]=nameList[j+1];
        creditHours[j]=creditHours[j+1];
        semList[j]=semList[j+1];}
       f=1;
	   }
	   }
	   count--;
}//function to view all courses
void ViewAllCourses(string codeList[],int count,int s1,string nameList[],int creditHours[],int semList[])
{  cout<<"Course code"<<setw(14)<<"Name"<<setw(35)<<"Credit Hours"<<setw(35)<<"Semmester"<<endl;
	for (int j=0;j<count;j++)
	{ 
		cout<<codeList[j]<<setw(40)<<nameList[j]<<setw(13)<<creditHours[j]<<setw(30)<<semList[j]<<endl;
	}
}//Function to view course of a semmester
void SemmesterCourses(string codeList[],int s1,string name[],int creditHours[],int semList[],int semmester)
{cout<<"Course code"<<setw(14)<<"Name"<<setw(35)<<"Credit Hours"<<endl;
	for (int j=0;j<s1;j++)
	{
	if (semList[j]==semmester)
   	{
		cout<<codeList[j]<<setw(40)<<name[j]<<setw(12)<<creditHours[j]<<endl;
	}
	}
	
}//function to save courses
bool saveCourses(string codeList[],int s,string nameList[],int creditHours[],int semList[],int n2)
{
		ofstream a;
	a.open("E:/Courses.txt");
	for (int j=0;j<s;j++)
	{   
		a<<codeList[j]<<","<<nameList[j]<<","<<creditHours[j]<<","<<semList[j]<<endl;
	}
	a.close();
}//function to load users
void  loadUsers(string arr[],int s,string arr1[],ifstream &t,int &count1)
{ 
count1=0;
for (int k=0;t!=0 && k<100;k++)
{getline(t,arr[k],',');
getline(t,arr1[k]);
count1++;
}
}//function to check if file exist or not
bool does_file_exist(const char *fileName)
{
    ifstream infile(fileName);
    return infile.good();
}//Function to check if data is valid
bool isValidData(string arr[],int s,string arr1[],string pas,string user)
{bool f;
	for (int j=0;j<s;j++)
	{
		if (arr[j]==user && arr1[j]==pas)
		f=1; 
	}
	return f;
}
//function to load courses
void loadCourses(string codeList[],int &count,int s,string nameList[],int creditHours[],int semList[],ifstream &a,int &n)
{ n=0;
char ch;
  	for (count=0;count<s && a!=0;count++)
	{   getline(a,codeList[count],',');
	     getline(a,nameList[count],',');
	     a>>creditHours[count]>>ch;
	     a>>semList[count];
	}
	count--;	
}
int main()
{int n1,n2;
char ch;
string username;
string  password;
string emailList[100];
  string passwordList[100];
  ifstream t;
  ifstream p;
  string codeList[100];
string nameList[100];
int creditHours[100];
int semList[100];
string Code;
char h;
 	bool a,b,c,d,f,fg;
 	int count=0;
 	bool r8=0;
 	bool r9=0;
string courseName;
char discard;
int sem,credithours;
int n;
bool k2;
	k2=does_file_exist("E:/Courses.txt");
	 p.open("E:/Courses.txt");
	 if(k2){
	   loadCourses(codeList,count,100,nameList,creditHours,semList,p,n2);}

cout<<""<<"**"<<"Welcome to university of Engineering and Technolohgy"<<""<<"**"<<endl;
cout<<"Dear user current software is intended for authorikzed users only"<<endl;
cout<<"Login to the system to get access"<<endl;
t.open("E:/Users.txt");
bool m=does_file_exist("E:/Users.txt");
if (!m)
cout<<"We are unable to run programe because data does not exist"<<endl;
else
{
loadUsers(emailList,100,passwordList,t,n1);
n2=count;
cout<<"Enter username :";
cin>>username;

cout<<"Enter password :";
cin>>password;

cout<<"Password:"<<password<<endl;
cout<<"Username:"<<username<<endl;
bool k=isValidData(emailList,n1,passwordList,password,username);
while (!k)
{cout<<""<<"**"<<"Welcome to university of Engineering and Technolohgy"<<""<<"**"<<endl;
cout<<"Dear user current software is intended foe authorized users only"<<endl;
cout<<"your email/password is not correct Login again  to the system to get access"<<endl;
cout<<"Enter username:";
cin>>username;

cout<<"Enter password :";
cin>>password;

cout<<"Dear user,username/password is incorrect.Again enter username/password to login access the system"<<endl;
cout<<"Password:"<<password<<endl;
cout<<"Username:"<<username<<endl;
 k=isValidData(emailList,n1,passwordList,password,username);
	
}
if (k)
{cout<<"You have successfully logged into the system"<<endl;
cout<<"Choose the following programe:"<<endl;
cout<<"(1)"<<" "<<setw(10)<<"Add course."<<endl;
cout<<"(2)"<<" "<<setw(14)<<"Upadate course."<<endl;
cout<<"(3)"<<" "<<setw(13)<<"Delete course."<<endl;
cout<<"(4)"<<" "<<setw(15)<<"View all courses"<<endl;
cout<<"(5)"<<" "<<setw(26)<<"View courses of a semester."<<endl;
cout<<"(6)"<<" "<<setw(11)<<"Exit program."<<endl;
while (n!=6){
cout<<"enter the option"<<endl;
cin>>n;
if (cin.fail())
{cin.clear();
cin.ignore(10000,'\n');
}
cout<<"Choose the option:"<<n<<endl;
switch (n)
 {
	case 1:
		cout<<"enter the details of the course"<<endl;
	
		cout<<endl<<"enter courseCode"<<endl;
	   cin>>Code;
	 cout<<endl;
	a=isValidCode(Code);
	    if (a==1)
	    cout<<"course code is valid"<<endl;
	    else
	    {
		
	while (a!=1)
        	{
			cout<<"input is not valid again enter course code"<<endl;
            cin>>Code;
		    a=isValidCode(Code);}
		    cout<<"course name is valid"<<endl;}
			cout<<"enter courseName "<<endl;
	        cin.ignore(1,',');
			getline(cin,courseName);
	        b=isValidCourseName(courseName);

            if (b==1)
            cout<<"course name is valid"<<endl;
            else
            {
           while (b!=1)
            	{
				cout<<"input is not valid again enter course name"<<endl;
               cin.ignore(1,',');
               getline(cin,courseName);
		        b=isValidCourseName(courseName);}
	}
		cout<<"enter credithours";
		cin>>credithours;
		cout<<endl;
			c=isValidCreditHours(credithours);
           if (c==1)
           cout<<"credit hours is valid"<<endl;
        else
            {
            	while(c!=1)
            {cout<<"credit hourse is not valid enter again credithours"<<endl;
            	cin>>credithours;
            	c=isValidCreditHours(credithours);
				}
				cout<<"credit hours is valid"<<endl;
			}
			cout<<"enter semmeser";
		cin>>sem;
			d=isValidSemmester(sem);
			if (d==1)
			cout<<"semmester is valid"<<endl;
			else
			{
				while (d!=1)
				{
					cout<<"semmester is not valid again enter semmester"<<endl;
					cin>>sem;
					d=isValidSemmester(sem);
				}
				cout<<"semmester is valid"<<endl;
		}
  AddCourse(codeList,count,nameList,creditHours,semList,Code,courseName,credithours,sem); 
  cout<<"the details of course which is added is"<<endl;   
  cout<<nameList[2];      
       cout<<Code<<" "<<credithours<<" "<<sem<<" "<<courseName<<endl;
	   cout<<"Course has been added successfully"<<endl;
    break;
    case 2:
    	cout<<"enter new details of course:"<<endl;
    	cout<<"enter course code to edit"<<endl;
    	cin>>Code;
    	 a=isValidCode(Code);
		    if (a==1)
	    cout<<"course code is valid"<<endl;
	    else
	    {
		
	while (a!=1)
        	{
			cout<<"input is not valid again enter course code"<<endl;
            cin>>Code;
		    a=isValidCode(Code);}
		    cout<<"courseCode is valid"<<endl;
		}
			cout<<"enter courseName"<<endl;
			cin.ignore(1,',');
			getline(cin,courseName);
			cout<<"coursename is"<<courseName<<endl;
        b=isValidCourseName(courseName);
            cout<<b;
            if (b==1)
            cout<<"course name is valid"<<endl;
            else
            {
           while (b!=1)
            	{
				cout<<"input is not valid again enter course name"<<endl;
                cin.ignore(1,',');
               getline(cin,courseName);
		        b=isValidCourseName(courseName);}
	}


	
		cout<<"enter credithours";
		cin>>credithours;
		cout<<endl;
			c=isValidCreditHours(credithours);
           if (c==1)
           cout<<"credit hours is valid"<<endl;
        else
            {
            	while(c!=1)
            {cout<<"credit hourse is not valid enter again credithours"<<endl;
            	cin>>credithours;
            	c=isValidCreditHours(credithours);
				}
				cout<<"credit hours is valid"<<endl;
			}
		
			
		
			
			cout<<"enter semmeser";
		cin>>sem;
			d=isValidSemmester(sem);
			if (d==1)
			cout<<"semmester is valid"<<endl;
			else
			{
				while (d!=1)
				{
					cout<<"semmester is not valid again enter semmester"<<endl;
					cin>>sem;
					d=isValidSemmester(sem);
				}
				cout<<"semmester is valid"<<endl;
		}
	   
		cout<<"the code of the course which is edited is"<<Code<<endl;		
  EditCourse(codeList,nameList,creditHours,semList,Code,courseName,credithours,sem,r8);   
if (r8==1)
	{cout<<"the new details of the course which is edited:"<<endl;
		cout<<Code<<" "<<credithours<<" "<<sem<<" "<<courseName<<endl;
		cout<<"your course has been edited successfully"<<endl;}
		else
		cout<<"Course is not present in the list"<<endl;
		break;
   case 3:
    	cout<<"enter the course code to delete:"<<endl;
    	cin>>Code;
    	a=isValidCode(Code);
		    if (a==1)
	    cout<<"course code is valid"<<endl;
	    else
	    {
		
	while (a!=1)
        	{
			cout<<"input is not valid again enter course code"<<endl;
            cin>>Code;
		    a=isValidCode(Code);}
		    cout<<"course name is valid"<<endl;
			} 
    	DeleteCourse(codeList,count,100,nameList,creditHours,semList,Code,r9);
    	if (r9==1)
		cout<<"you course has been deleted successfully"<<endl;
		else
		cout<<"This course is not present in the list"<<endl;
		break;
    case 4 :
    	ViewAllCourses(codeList,count,100,nameList,creditHours,semList);
    	break;
    case 5:
    	cout<<"enter the semmester";
    	cin>>sem;
    	cout<<":"<<sem<<endl;
    	d=isValidSemmester(sem);
			if (d==1)
			cout<<"semmester is valid"<<endl;
			else
			{
				while (d!=1)
				{
					cout<<"semmester is not valid again enter semmester"<<endl;
					cin>>sem;
					d=isValidSemmester(sem);
				}
				cout<<"semmester is valid"<<endl;
		} f=0;
	  for (int j=0;j<100;j++)
          {
          	if (semList[j]==sem)
          	f=1;
		  }
		  while (f!=1)
		  {
		  	cout<<"enter again semmester it is not matched"<<endl;
		  		cin>>sem;
    	d=isValidSemmester(sem);
		    if (d==1)
	    cout<<"semmester is valid"<<endl;
	    else
	    {
		
	while (d!=1)
        	{
			cout<<"input is not valid again enter semmester"<<endl;
            cin>>sem;
		    d=isValidSemmester(sem);}
		    cout<<"semmester is valid"<<endl;
			}
			for (int j=0;j<100;j++)
          {
          	if (semList[j]==sem)
          	f=1;
		  }
		  }
			
			
	SemmesterCourses(codeList,100,nameList,creditHours,semList,sem);
	break;
   case 6 :
	cout<<"Exit the programe"<<endl;	
  saveCourses(codeList,count,nameList,creditHours,semList,n2);
	cout<<" "<<"Logout"<<" "<<endl;
cout<<""<<"**"<<"Welcome to university of Engineering and Technolohgy"<<""<<"**"<<endl;
cout<<"Dear user current software is intended for authorized users only"<<endl;
cout<<"Login to the system to get access"<<endl;
break;}
}}
}
t.close();
p.close();
return 0;
 }
