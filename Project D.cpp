#include<iostream>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<fstream>
using namespace std;
//Function to unregister course
void unregisterCourse(string r1[],int k,string course[][100],string r,string c)
{            bool f=0;
          
			for (int j=0;j<2;j++)
  			{
  				course[k][j]=course[k][j+1];
  				f=1;
             }
  if (f==0)
  cout<<"course is not present in this list"<<endl;
  else
  cout<<"you are successfully unregistered this course"<<endl;
}
//Function to register course
void registerCourse(string regList[],int k,string course[100][100],string codeList[],string reg,string code)
{ bool f=0;
for (int i=0;i<1;i++)
{  course[k][i]=code;
   f=1;}
  
    if (f=1)
	cout<<"you have succesfully register the course"<<endl;
 if (f==0)
 cout<<"course is not present in this list"<<endl;
}
//Function to view all student
void viewAllStd(string arr1[],int s,string arr2[],string Course[100][100])
{  cout<<"Name"<<setw(50)<<"Registration number"<<setw(50)<<"Courses"<<endl;
for (int j=0;j<s;j++)
{  
  cout<<arr1[j]<<setw(38)<<arr2[j]<<setw(48);
  	for (int i=0;i<2;i++)
  	{ cout<<Course[j][i];
    }
 cout<<endl;   
}
}
//Function to delete student
void deleteStd(string arr1[],int &s,string arr2[],string r,string course[100][100])
{int k;
	int index;
	int size=sizeof(arr2);
	for (int v=0;v<s;v++)
{
    if (arr2[v]==r)
      { arr1[v]=arr1[v+1];
        arr2[v]=arr2[v+1];
        for (int j=0;j<1;j++)
        course[v][j]=course[v][j+1];}
}
cout<<"student has been deleted successfully"<<endl;
s--;
}
//Function to update student
bool updateStudent(string arr1[],int s,string arr2[],string n,string r)
{
	for (int j=0;j<s;j++)
	{
	if (arr2[j]==r)
	{
		arr1[j]=n;
		arr2[j]=r;
	}
		
	}
}
//Function to check validation for registration no
bool isValidReg(string r)
{int i;
int noofalp=0;
int noofspe=0;
int noofdig=0;
	int l=r.length();
	for (i=0;i<l;i++)
	{
	{
if (r[i]>=48 && r[i]<=57)
 noofdig=noofdig+1;}	
   if (r[i]==45)
 noofspe=noofspe+1;
 
 if (r[i]>=65 && r[i]<=90)
 noofalp=noofalp+1;
 	}
	if (noofalp==2 && noofdig==7 && noofspe==2)
	return 1;
	else 
	return 0;
}
//Function to check validation for course code
bool isValidCode(string code)
{int noofAlp=0;
int noofDig=0;
int i;
int length=code.length();
for (i=0;i<length;i++)
{ if (i<2)
{
if (code[i]>=65 && code[i]<=90)
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
   //Function to check validation for course name and student name
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
}//Function to check validation forcredit Hours
bool isValidCreditHours(int a)
{ 
	if (a>0 && a<4)
	return 1;
	else
	return 0;
}//Function to check validation for semmester
bool isValidSemmester(int a)
{
	if (a>0 && a<9)
	return 1;
	else 
	return 0;
}//Function to add course
void AddCourse(string codeList[],int &i,string nameList[],int creditHoursList[],int semList[],string courseCode,string courseName,int creditHours,int semmester)
{  
	codeList[i]=courseCode;
    nameList[i]=courseName;
    creditHoursList[i]=creditHours;
    semList[i]=semmester;
    i++;
}//Function to edit course
void EditCourse(string codeList[],int s1,string nameList[],int creditHoursList[],int semList[],string courseCode,string courseName,int creditHours,int semmester,bool &f)

{ 
for (int i=0;i<s1;i++)
{ if (codeList[i]==courseCode)
  {codeList[i]=courseCode;
   nameList[i]=courseName;
   creditHoursList[i]=creditHours;
   semList[i]=semmester;
  
  f=1;}	
}
}
//Function to edit course
void DeleteCourse(string codeList[],int &count,int s1,string nameList[],int creditHours[],int semList[],string coursecode,bool &f)
{
	for (int i=0;i<s1;i++)
{
    if (codeList[i]==coursecode)
        { for (int j=i;j<(s1-1);j++)
        {codeList[j]=codeList[j+1];
        nameList[j]=nameList[j+1];
        creditHours[j]=creditHours[j+1];
        semList[j]=semList[j+1];}       
		f=1;}
	   }
	   count--;
}
//Function to view all courses
void ViewAllCourses(string codeList[],int count,int s1,string nameList[],int creditHours[],int semList[])
{  cout<<"Course code"<<setw(14)<<"Name"<<setw(35)<<"Credit Hours"<<setw(35)<<"Semmester"<<endl;
	for (int j=0;j<count;j++)
	{
     cout<<codeList[j]<<setw(40)<<nameList[j]<<setw(13)<<creditHours[j]<<setw(30)<<semList[j]<<endl;
		
	}
}
//Function to view semmester courses
void SemmesterCourses(string codeList[],int s1,string name[],int creditHours[],int semList[],int semmester)
{
	for (int i=0;i<s1;i++)
	{
	if (semList[i]==semmester)
   	{cout<<"Course code"<<setw(14)<<"Name"<<setw(35)<<"Credit Hours"<<endl;
		cout<<codeList[i]<<setw(40)<<name[i]<<setw(12)<<creditHours[i]<<endl;
	}
	}
	
}//Function to save courses
bool saveCourses(string codeList[],int count,string nameList[],int creditHours[],int semList[])
{
		ofstream a;
	a.open("E:/Courses.txt");
	for (int j=0;j<count;j++)
	{  
		a<<codeList[j]<<" , "<<nameList[j]<<" , "<<creditHours[j]<<" , "<<semList[j]<<endl;
	}
	a.close();
}//Function to load Users
void  loadUsers(string arr[],int s,string arr1[],ifstream &t,int &count1)
{ 
count1=0;
for (int k=0;t!=0 && k<100;k++)
{getline(t,arr[k],',');
getline(t,arr1[k]);
count1++;
}
}//Function to check File Existance
bool does_file_exist(const char *fileName)
{
    ifstream infile(fileName);
    return infile.good();
}
//Function to check data  validation
bool isValidData(string arr[],int s,string arr1[],string pas,string user)
{bool f;
	for (int i=0;i<s;i++)
	{
		if (arr[i]==user && arr1[i]==pas)
		f=1; 
	}
	return f;
}
//Function to load courses
void loadCourses(string codeList[],int &count,int s,string nameList[],int creditHours[],int semList[],ifstream &a,int &n)
{ 
char ch;
  	for (count=0;count<s && a!=0;count++)
	{  
	   getline(a,codeList[count],',');
	     getline(a,nameList[count],',');
	     a>>creditHours[count]>>ch;
	     a>>semList[count];
	    
	}
	count--;}
	//Function to add  student
void addStd(string arr1[],int &count2,string arr2[],string name,string reg)
	{  arr1[count2]=name;
	   arr2[count2]=reg;
	   count2++;
		
	}//Function to load students
   void loadStudents(string regList[],int &count2,string nameList[],string course[][100],ifstream &t2)
   { for (count2=0;count2<100 && t2!='\0';count2++)
   	{
	getline(t2,regList[count2],',');
   	getline(t2,nameList[count2],'\n');
   	for (int i=0;i<1;i++)
   	{
	    getline(t2,course[count2][i],'\n');
   }} 
   count2--;  }
   
   //Function to save students
   void saveStudents(string regNoList[],int count2,string nameList[],string stdCourseList[][100])
   {ofstream b;
   b.open("E:/students.txt");
   for (int i=0;i<count2;i++)
   {b<<regNoList[i]<<","<<nameList[i]<<'\n';
   for (int j=0;j<1;j++)
   b<<stdCourseList[i][j]<<'\n';}
   b.close();
   }
   //view register courses of a student
void viewRegisterCourses(string reg[],string courses[][100],int s)
{  cout<<"courses"<<endl;   
   for (int j=0;j<1;j++)
	cout<<courses[s][j]<<endl;
}
int main()
{int n1,n2;
int count=0;
int count2=0;
char ch;
int k6;
int kh;
string username;
string  password;
string emailList[100];
  string passwordList[100];
  ifstream t,t2;
  ifstream p;
  string codeList[100];
string nameList[100];
int creditHours[100];
int semList[100];
string stdNameList[100];
string regNoList[100];
string stdCourseList[100][100];
string stdName;
string reg;
string Code;
char h;
bool r8=0,r9=0;
 int k3=2;
string courseName;
char discard;
int sem,credithours;
int n;
int  b7;
	bool a,b,c,d,f,f2;
cout<<"Choose the option for Login"<<endl;
cout<<"1"<<" "<<"For Admin"<<endl;
cout<<"2"<<" "<<"For Student"<<endl;
cout<<"Enter option"<<endl;
cin>>b7;

bool h5; 
h5=does_file_exist("E:/students.txt");
  t2.open("E:/students.txt");
  if (h5)
  {
  	loadStudents(regNoList,count2,stdNameList,stdCourseList,t2);
  }
 
bool k2;
k2=does_file_exist("E:/Courses.txt");
	 p.open("E:/Courses.txt");
	 if(k2){
	   loadCourses(codeList,count,100,nameList,creditHours,semList,p,n2);}
	   if (b7==1)
	   {
cout<<""<<"**"<<"Welcome to university of Engineering and Technolohgy"<<""<<"**"<<endl;
cout<<"Dear user current software is intended for authorized users only"<<endl;
cout<<"Login to the system to get access"<<endl;

t.open("E:/Users.txt");
bool m=does_file_exist("E:/Users.txt");
if (!m)
cout<<"We are unable to run programe because data does not exist"<<endl;
else
{
loadUsers(emailList,100,passwordList,t,n1);

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
cout<<"(6)"<<" "<<setw(15)<<"Add new student."<<endl;
cout<<"(7)"<<" "<<setw(15)<<"Update student."<<endl;
cout<<"(8)"<<" "<<setw(15)<<"Delete Student."<<endl;
cout<<"(9)"<<" "<<setw(16)<<"View all student."<<endl;
cout<<"(10)"<<" "<<setw(30)<<"Register courses for a student."<<endl;
cout<<"(11)"<<" "<<setw(31)<<"Unregister course for a student."<<endl;
cout<<"(12)"<<" "<<setw(18)<<"Logout from system."<<endl;
cout<<"(13)"<<" "<<setw(17)<<"Exit the programm."<<endl;
while (n!=13)
{cout<<"enter the option"<<endl;
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
		    cout<<"course code is valid"<<endl;}
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
	
		cout<<"the code of the course which is edited is"<<Code<<endl;		
  EditCourse(codeList,100,nameList,creditHours,semList,Code,courseName,credithours,sem,r8);   
     if (r8==1)
     {
	cout<<"the new details of the course which is edited:"<<endl;
		cout<<Code<<" "<<credithours<<" "<<sem<<" "<<courseName<<endl;
		cout<<"your course has been edited successfully"<<endl;}
		else
	cout<<"your course is not present in the list"<<endl;
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
    		cout<<"this course is not present in the list"<<endl;
		break;
    case 4:
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
		}
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
			
			
	SemmesterCourses(codeList,100,nameList,creditHours,semList,sem);
	break;
	case 6:
		cout<<"enter stdent name"<<endl;
		    cin.ignore(1,',');
		     getline(cin,stdName);
			a=isValidCourseName(stdName);
			
	    if (a==1)
	    cout<<"student name is valid"<<endl;
	    else
	    {
		
	while (a!=1)
        	{
			cout<<"input is not valid again enter sudent name"<<endl;
			cin.ignore(1,',');
             getline(cin,stdName);
		    a=isValidCourseName(stdName);}
		    cout<<"student name is valid"<<endl;}
            cout<<"Enter registration number:"<<endl;
            cin>>reg;
             b=isValidReg(reg);
             if (b==1)
            cout<<"registration no is valid"<<endl;
            else
            {
           while (b!=1)
            	{
				cout<<"input is not valid again enter registration no"<<endl;
               cin>>reg;
		        b=isValidReg(reg);}
	}
	  addStd(stdNameList,count2,regNoList,stdName,reg);
	  cout<<"student has been added successfully"<<endl;
    break;
		case 7:
			cout<<"enter registration no of student to be edited:"<<endl;
			cin>>reg;
             b=isValidReg(reg);
             if (b==1)
            cout<<"registration no is valid"<<endl;
            else
            {
           while (b!=1)
            	{
				cout<<"input is not valid again enter registration no"<<endl;
               cin>>reg;
		        b=isValidReg(reg);}
	}
	cout<<"Enter student name:"<<endl;
	 cin.ignore(1,',');
		     getline(cin,stdName);
			a=isValidCourseName(stdName);
			
	    if (a==1)
	    cout<<"student name is valid"<<endl;
	    else
	    {
		
	while (a!=1)
        	{
			cout<<"input is not valid again enter sudent name"<<endl;
			cin.ignore(1,',');
             getline(cin,stdName);
		    a=isValidCourseName(stdName);}
		    cout<<"student name is valid"<<endl;}
		    f=0;
		     for (int j=0;j<100;j++)
          {
          	if (regNoList[j]==reg)
          	f=1;
		  }
		  while (f!=1)
        {
	
	cout<<"enter again registration no it is not matched"<<endl;
    	cin>>reg;
    	 a=isValidReg(reg);
		    if (a==1)
	    cout<<"registration no is valid"<<endl;
	    else
	    {
		
	while (a!=1)
        	{
			cout<<"input is not valid again enter registration no"<<endl;
            cin>>reg;
		    a=isValidReg(reg);}
		    cout<<"registration no is valid"<<endl;
			}
			
		for (int j=0;j<100;j++)
          {
          	if (regNoList[j]==reg)
          	f=1;
		  }
		}
		
		updateStudent(stdNameList,count2,regNoList,stdName,reg);
		cout<<"Student has been edited successfully"<<endl;
	break;
	case 8:
		cout<<"Enter registration no student which is to be deleted:"<<endl;
		cin>>reg;
		  b=isValidReg(reg);
             if (b==1)
            cout<<"registration no is valid"<<endl;
            else
            {
           while (b!=1)
            	{
				cout<<"input is not valid again enter registration no"<<endl;
               cin>>reg;
		        b=isValidReg(reg);}
	}
	f=0;
		     for (int j=0;j<100;j++)
          {
          	if (regNoList[j]==reg)
          	f=1;
		  }
		  while (f!=1)
        {
	
	cout<<"enter again registration no it is not matched"<<endl;
    	cin>>reg;
    	 a=isValidReg(reg);
		    if (a==1)
	    cout<<"registration no is valid"<<endl;
	    else
	    {
		
	while (a!=1)
        	{
			cout<<"input is not valid again enter registration no"<<endl;
            cin>>reg;
		    a=isValidReg(reg);}
		    cout<<"registration no is valid"<<endl;
			}
			
		for (int j=0;j<100;j++)
          {
          	if (regNoList[j]==reg)
          	f=1;
		  }
		}
		deleteStd(stdNameList,count2,regNoList,reg,stdCourseList);
		break;
	case 9:
		viewAllStd(stdNameList,count2,regNoList,stdCourseList);
		break;
	case 10:
			cout<<"enter registration number of student to register course:"<<endl;
				cin>>reg;
		  b=isValidReg(reg);
           if (b==1)
            cout<<"registration no is valid"<<endl;
            else
            {
           while (b!=1)
            	{
				cout<<"input is not valid again enter registration no"<<endl;
               cin>>reg;
		        b=isValidReg(reg);}
	}
			
			f=0;
		     for (int j=0;j<100;j++)
          {
          	if (regNoList[j]==reg)
          	{ kh=j;
			  f=1;}
		  }
		  while (f!=1)
        {
	
	cout<<"enter again registration no it is not present in the list"<<endl;
    	cin>>reg;
    	 a=isValidReg(reg);
		    if (a==1)
	    cout<<"registration no is valid"<<endl;
	    else
	    {
		
	while (a!=1)
        	{
			cout<<"input is not valid again enter registration no"<<endl;
            cin>>reg;
		    a=isValidReg(reg);}
		    cout<<"registration no is valid"<<endl;
			}	
		for (int j=0;j<100;j++)
          {
          	if (regNoList[j]==reg)
          	f=1;
		  }
		}
		cout<<"enter course code to register:"<<endl;
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
	      f=0;
		 for (int j=0;j<100;j++)
          {
          	if (codeList[j]==Code)
          	f=1;
		  }
		  while (f!=1)
        {
	
	cout<<"enter again course code it is not present in the list"<<endl;
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
		registerCourse(regNoList,kh,stdCourseList,codeList,reg,Code);

   break;
   case 11:
   	cout<<"enter registration number of student to unregister course:"<<endl;
				cin>>reg;
		  b=isValidReg(reg);
             if (b==1)
            cout<<"registration no is valid"<<endl;
            else
            {
           while (b!=1)
            	{
				cout<<"input is not valid again enter registration no"<<endl;
               cin>>reg;
		        b=isValidReg(reg);}
	}
			
			f=0;
		     for (int j=0;j<100;j++)
          {
          	if (regNoList[j]==reg)
          	{ kh=j;
			  f=1;}
		  }
		  while (f!=1)
        {
	
	cout<<"enter again registration no it is not matched"<<endl;
    	cin>>reg;
    	 a=isValidReg(reg);
		    if (a==1)
	    cout<<"registration no is valid"<<endl;
	    else
	    {
		
	while (a!=1)
        	{
			cout<<"input is not valid again enter registration no"<<endl;
            cin>>reg;
		    a=isValidReg(reg);}
		    cout<<"registration no is valid"<<endl;
			}	
		for (int j=0;j<100;j++)
          {
          	if (regNoList[j]==reg)
          	f=1;
		  }
		}
		cout<<"enter course code to unregister:"<<endl;
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
	      f=0;
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
		unregisterCourse(regNoList,kh,stdCourseList,reg,Code);
   break;
   case 12:
		cout<<" "<<"Logout"<<" "<<endl;
cout<<""<<"**"<<"Welcome to university of Engineering and Technolohgy"<<""<<"**"<<endl;
cout<<"Dear user current software is intended for authorized users only"<<endl;
cout<<"Login to the system to get access"<<endl;
   break;
   case 13:
   	cout<<"Exit the programe"<<endl;
  saveCourses(codeList,count,nameList,creditHours,semList);
  saveStudents(regNoList,count2,stdNameList,stdCourseList);
  break;
}}
}
}}
int m8;
if (b7==2)
{
	cout<<"Enter registration number"<<endl;
	cin>>reg;
		  b=isValidReg(reg);
             if (b==1)
            cout<<"registration no is valid"<<endl;
            else
            {
           while (b!=1)
            	{
				cout<<"input is not valid again enter registration no"<<endl;
               cin>>reg;
		        b=isValidReg(reg);}
	}
	f=0;
		     for (int j=0;j<100;j++)
          {
          	if (regNoList[j]==reg)
          {	f=1;
          m8=j;
          }
		  }
		  while (f!=1)
        {
	
	cout<<"enter again registration no it is not matched"<<endl;
    	cin>>reg;
    	 a=isValidReg(reg);
		    if (a==1)
	    cout<<"registration no is valid"<<endl;
	    else
	    {
		
	while (a!=1)
        	{
			cout<<"input is not valid again enter registration no"<<endl;
            cin>>reg;
		    a=isValidReg(reg);}
		    cout<<"registration no is valid"<<endl;
			}
			
		for (int j=0;j<100;j++)
          {
          	if (regNoList[j]==reg)
          	{
			f=1;
			m8=j;}
		  }
		}
		cout<<"Enter password"<<endl;
		cin>>password;
		string p=stdNameList[m8];
	   int x=p.length();
	   int x2=0;
	   int j=3;
	   for (int i=x;j>0;i--)
		{
			if (password[j]==p[i])
			   x2=x2+1;
           j--;		
		}cout<<x2;
		if (x2==3)
		cout<<"Password is valid"<<endl;
		else
		{
		cout<<"password is invalid again enter password"<<endl;
		  x2=0;
	      j=3;
	   for (int i=x;j>0;i--)
		{
			if (password[j]==p[i])
			   x2=x2+1;
           j--;		
		}}
		if (x2==3)
		cout<<"Password is valid"<<endl;
		cout<<"Enter 1 To view registered courses"<<endl;
		cout<<"Enter 2 To logout of the system"<<endl;
		cout<<"Enter 3 To exit the system"<<endl;
		while (n!=3)
{cout<<"enter the option"<<endl;
cin>>n;

if (cin.fail())
{cin.clear();
cin.ignore(10000,'\n');
}
cout<<"Choose the option:"<<n<<endl;
switch (n)
{
	case 1:
		viewRegisterCourses(regNoList,stdCourseList,m8);
		break;
	case 2:
		cout<<" "<<"Logout"<<" "<<endl;
cout<<""<<"**"<<"Welcome to university of Engineering and Technolohgy"<<""<<"**"<<endl;
cout<<"Dear user current software is intended for authorized users only"<<endl;
cout<<"Login to the system to get access"<<endl;
   break;
   case 3:
   	cout<<"Exit the programe"<<endl;
   	break;
}
}
}
t.close();
p.close();
t2.close();
return 0;
}

