#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int ID;//global variable 
class student
{
    public :
        int id;
        string name;
        int age;
        string stream;

    void addStudent()
    {
        cout<<"Enter your name"<<endl;
        cin.get();//to empty the buffer
        getline(cin,name);//taking input from keyboard and saving it inside name
        cout<<"Enter your age"<<endl;
        cin>>age;
        cout<<"Enter your stream"<<endl;
        cin>>stream;
        ID++;

        ofstream fout;
        fout.open("c:/file/student.txt",ios::app);
        fout<<"\n"<<ID;
        fout<<"\n"<<name;
        fout<<"\n"<<age;
        fout<<"\n"<<stream;
        fout.close();

        fout.open("c:/file/id.txt",ios::app);
        fout<<"\n"<<ID;
        fout.close();

        cout<<"Record Added Successfully"<<endl;
    }
    void printAllStudent()
    {
        ifstream fin;

        fin.open("c:/file/student.txt");
        student s;
        while(!fin.eof())
        {
            fin>>s.id;
            fin.ignore();   //to empty the buffer
            getline(fin,s.name);
            fin>>s.age;
            fin>>s.stream;

            s.print();
        }

        fin.close();
    }

    void print()
    {
        cout<<" ID = "<<id<<endl;
        cout<<" Name = "<<name<<endl;
        cout<<" Age = "<<age<<endl;
        cout<<" Stream = "<<stream<<endl;
        cout<<"####################################"<<endl<<endl;
    }
    void searchStudent(int id)
    {
        ifstream fin;
        fin.open("c:/file/student.txt");

        student s;
        while(!fin.eof())
        {
            fin>>s.id;
            fin.ignore();
            getline(fin,s.name);
            fin>>s.age;
            fin>>s.stream;

           if(s.id == id)   //to check if student id and given id are same or not
           {
               s.print();
               break;
           }
        }
        fin.close();
    }

    void deleteStudent(int id)
    {
        ifstream fin;
        fin.open("c:/file/student.txt");

        ofstream fout;
        fout.open("c:/file/temp.txt",ios::app);

        student s;
        while(!fin.eof())
        {
            fin>>s.id;
            fin.ignore();
            getline(fin,s.name);
            fin>>s.age;
            fin>>s.stream;

           if(s.id != id)   //if student id doesn't match with given id,copy the data into temporary file
           {
            fout<<"\n"<<s.id;
            fout<<"\n"<<s.name;
            fout<<"\n"<<s.age;
            fout<<"\n"<<s.stream;
           }
        }

        fin.close();
        fout.close();

        remove("c:/file/student.txt");  //delete the student file
        rename("c:/file/temp.txt","c:/file/student.txt");//rename the temporary file to student file

        cout<<"Record Deleted Successfully"<<endl;
    }
     void updateStudent(int id)
     {
        deleteStudent(id);

        cout<<"Enter your name"<<endl;
        cin.get();
        getline(cin,name);
        cout<<"Enter your age"<<endl;
        cin>>age;
        cout<<"Enter your stream"<<endl;
        cin>>stream;
        ID++;

        ofstream fout;
        fout.open("c:/file/student.txt",ios::app);
        fout<<"\n"<<id;
        fout<<"\n"<<name;
        fout<<"\n"<<age;
        fout<<"\n"<<stream;
        fout.close();

        cout<<"Record Added Successfully"<<endl;

     }

};
int main()
{
   int choice;

   ifstream fin;
   fin.open("c:/file/id.txt");

   if(!fin)
   {
       cout<<"File Not Found"<<endl;
   }
   else{
     while(!fin.eof())
     {
       fin>>ID;         //Here,after closing the program and starting again we'll still get to know the last stored ID
     }
   }

   fin.close();
   cout<<"ID = "<<ID<<endl;



   while(true)
   {   cout<<"Enter Your choice"<<endl;
       cout<<"1. Add Student"<<endl;
       cout<<"2. Print all the students"<<endl;
       cout<<"3. Search a student"<<endl;
       cout<<"4. Update a student"<<endl;
       cout<<"5. Delete a student"<<endl;


       cin>>choice;

       student s;
       int id;
       switch(choice)
       {
           case 1 : s.addStudent();
                    break;
           case 2 : s.printAllStudent();
                    break;
           case 3 :
                    cout<<"Enter student id"<<endl;
                    cin>>id;
                    s.searchStudent(id);
                    break;

        case 4 :    cout<<"Enter student id"<<endl;
                    cin>>id;
                    s.updateStudent(id);
                    break;

           case 5 :
                    cout<<"Enter student id"<<endl;
                    cin>>id;
                    s.deleteStudent(id);
                    break;


           default : return 0;
       }
   }

   return 0;
}
