#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
//Function to check Validation of code
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
   //Function to check Validation of courseName
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
}
//Function to check validation for creditHours
bool isValidCreditHours(int a)
{ 
	if (a>0 && a<4)
	return 1;
	else
	return 0;
}//Function to check validation of semmester
bool isValidSemmester(int a)
{
	if (a>0 && a<9)
	return 1;
	else 
	return 0;
}
//Function to add course
void AddCourse(string codeList[],int i,string nameList[],int creditHoursList[],int semList[],string courseCode,string courseName,int creditHours,int semmester)
{  
	codeList[i]=courseCode;
    nameList[i]=courseName;
    creditHoursList[i]=creditHours;
    semList[i]=semmester;
    i++;
}
//Function to edit course
void EditCourse(string codeList[],int s1,string nameList[],int creditHoursList[],int semList[],string courseCode,string courseName,int creditHours,int semmester)

{ 
for (int i=0;i<s1;i++)
{ if (codeList[i]==courseCode)
  {codeList[i]=courseCode;
   nameList[i]=courseName;
   creditHoursList[i]=creditHours;
   semList[i]=semmester;
  }	
}
}//function to delete course
void DeleteCourse(string codeList[],int s1,string nameList[],int creditHours[],int semList[],string coursecode)
{
	for (int i=0;i<s1;i++)
{
    if (codeList[i]==coursecode)
        { for (int j=i;j<(s1-1);j++)
        {codeList[j]=codeList[j+1];
        nameList[j]=nameList[j+1];
        creditHours[j]=creditHours[j+1];
        semList[j]=semList[j+1];}
       }}
}//Function to view coourses
void ViewAllCourses(string codeList[],int s1,string nameList[],int creditHours[],int semList[])
{  cout<<"Course code"<<setw(14)<<"Name"<<setw(35)<<"Credit Hours"<<setw(20)<<"Semmester"<<endl;
	for (int i=0;i<s1;i++)
	{
		if (creditHours[i]!=0)
		cout<<codeList[i]<<setw(40)<<nameList[i]<<setw(12)<<creditHours[i]<<setw(20)<<semList[i]<<endl;
	}
}//Function to view semmester courses
void SemmesterCourses(string codeList[],int s1,string name[],int creditHours[],int semList[],int semmester)
{cout<<"Course code"<<setw(14)<<"Name"<<setw(35)<<"Credit Hours"<<endl;
	for (int i=0;i<s1;i++)
	{
	if (semList[i]==semmester)
   	{
		cout<<codeList[i]<<setw(40)<<name[i]<<setw(12)<<creditHours[i]<<endl;
	}
	}
	
}
//main work
int main()
{cout<<""<<"**"<<"Welcome to university of Engineering and Technolohgy"<<""<<"**"<<endl;
int n;
cout<<"Choose the following programe:"<<endl;
cout<<"(1)"<<" "<<setw(10)<<"Add course."<<endl;
cout<<"(2)"<<" "<<setw(14)<<"Upadate course."<<endl;
cout<<"(3)"<<" "<<setw(13)<<"Delete course."<<endl;
cout<<"(4)"<<" "<<setw(15)<<"View all courses"<<endl;
cout<<"(5)"<<" "<<setw(26)<<"View courses of a semester."<<endl;
cout<<"(6)"<<" "<<setw(11)<<"Exit program."<<endl;
string codeList[100]={"CS101","CS102"};
string nameList[100]={"programming fundamentals","Introduction to computing"};
int creditHours[100]={3,3};
int semList[100]={1,2};
string Code;
string courseName;
char discard;
int sem,credithours;
int i=2;
bool a,b,c,d,f,fg;

while(n!=6){
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
		    cout<<"course name is valid"<<endl;
			}
			
		
			cout<<"enter courseName"<<endl;
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
  AddCourse(codeList,i,nameList,creditHours,semList,Code,courseName,credithours,sem); 
  cout<<"the details of course which is added is"<<endl;         
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
		    cout<<"course name is valid"<<endl;
			}
				for (int j=0;j<100;j++)
          {
          	if (codeList[j]==Code)
          	f=1;
		  }
		  while (f!=1)
        {
	
	cout<<"enter again course code it is not matched"<<endl;
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
			
		for (int j=0;j<100;j++)
          {
          	if (codeList[j]==Code)
          	f=1;
		  }
	
		}	
		
			cout<<"enter courseName"<<endl;
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
  EditCourse(codeList,100,nameList,creditHours,semList,Code,courseName,credithours,sem);   
	cout<<"the new details of the course which is edited:"<<endl;
		cout<<Code<<" "<<credithours<<" "<<sem<<" "<<courseName<<endl;
		cout<<"your course has been edited successfully"<<endl;
		break;
    case 3:
    	cout<<"enter the course code to delete:"<<endl;
    	cin>>Code;
    	f=0;
          for (int j=0;j<100;j++)
          {
          	if (codeList[j]==Code)
          	f=1;
		  }
		  while (f!=1)
		  {
		  	cout<<"enter again code it is not matched"<<endl;
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
			for (int j=0;j<100;j++)
          {
          	if (codeList[j]==Code)
          	f=1;
		  }
		  }
    	DeleteCourse(codeList,100,nameList,creditHours,semList,Code );
    	
		cout<<"you course has been deleted successfully"<<endl;
		break;
    case 4:
    	ViewAllCourses(codeList,100,nameList,creditHours,semList);
    	break;
    case 5:
    	cout<<"enter the semmester";
    	cin>>sem;
    	 f=0;
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
			
    	cout<<":"<<sem<<endl;
   	SemmesterCourses(codeList,100,nameList,creditHours,semList,sem);
	break;
	case 6:
	cout<<"Exit the programe:"<<endl;
	break;
	default:
	cout<<"input is invalid"<<endl;}}
return 0;
}
