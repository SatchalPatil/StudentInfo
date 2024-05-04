#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

void addstudent(){
ofstream f("StudentInfo.txt",ios::app);
string rollno,name,div;

cout<<"Enter Student details: "<<endl;
cout<<"Enter roll no : "<<endl;
cin>>rollno;
cout<<"enter name: "<<endl;
cin>>name;
cout<<"enter div: "<<endl;
cin>>div;

f<<left<<setw(20)<<rollno<<setw(20)<<name<<setw(20)<<div<<endl;
cout<<"student data saved success ";
f.close();
}

void display(){
ifstream f("StudentInfo.txt");
string line;
while(getline(f,line)){
cout<<"\n"<<line<<endl;
}
f.close();
}

void search(){
ifstream f("StudentInfo.txt",ios::app);
string line;
string rollno;
cout<<"enter student roll no to find: "<<endl;
cin>>rollno;
bool found;
while(getline(f,line)){
if(line.find(rollno) != string::npos){
cout<<"\n"<<line<<endl;
found=true;
}
}
f.close();

if(!found){
cout<<"student doesnt exist ";
}

}

void deletestudent(){
ifstream f("StudentInfo.txt");
string line;
string rollno;
cout<<"enter the no. to delete: "<<endl;
cin>>rollno;
string Filedata;
while(getline(f,line)){
if(line.find(rollno) == string::npos){
Filedata+=line;
Filedata="\n";
}
}
f.close();
ofstream f1("StudentInfo.txt",ios::app);
f1<<Filedata;
f1.close();
}

int main(){
ofstream f("Studentinfo.txt",ios::out);
f<<left<<setw(20)<<"Roll no."<<setw(20)<<"Name"<<setw(20)<<"DIV"<<endl;
f.close();

int choice;


while (choice != -1){
cout<<"what action u want to perform: \n1.Insert Student Info \n2.Display Student Info \n3.Search Student Info \n4.Delete Student Info \n5.exit"<<endl;
cin>>choice;
switch(choice){

case 1:
addstudent();
break;

case 2:
display();
break;

case 3:
search();
break;

case 4:
deletestudent();
break;

case 5:
return 0;
break;

default:
cout<<"re enter choice: ";
break;


}

}

}

