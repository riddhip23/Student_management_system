#include<iostream>
#include<vector>
using namespace std;

class Student
{
    int roll_num;int age;
    string stu_name;
    public:
    
    Student(int roll_num,int age,string stu_name)
    {
        this->roll_num=roll_num;
        this->age=age;
        this->stu_name=stu_name; 
    }

    void setRoll_no(int roll)
    {
        roll_num=roll;
    }
    int getRoll_no(){//return type should be int
        return roll_num;
    }
    void set_age(int age_num)
    {
        age=age_num;
    }
    int get_age()
    {
        return age;
    }
    void set_name(string name)
    {
        stu_name=name;
    }
    string get_name()
    {
        return stu_name;
    }

    void displaystudent()
    {
        cout<<"Name: "<<stu_name<<endl;
        cout<<"Roll_Number: "<<roll_num<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

//Function to add new student
void add_NewStudent(vector<Student>&students)
{
    int roll_num,age;
    string stu_name;
    cout<<" Enter Name of the Student : ";
    cin>>stu_name;
    cout<<" Enter Roll Number of the Student : ";
    cin>>roll_num;
    //to check if student already exists
     for(int i=0;i<students.size();i++)
     {
        if(students[i].getRoll_no()==roll_num)
        {
            cout<<"\n\t\tStudent Already Exists "<<endl;
            return;
        }
     }
    cout<<" Enter Age of the Student : ";
    cin>>age;

    Student newStudent(roll_num,age,stu_name);//created new object newStudent
    students.push_back(newStudent);//added new object to array of objects

    cout<<"\n\t\tNew Student Added Successfully..."<<endl;
}

//to display all students in vector
void display_Students(vector<Student>&students)
{
   if(students.empty())
   {
    cout<<"\n\t\tNo Student Found "<<endl;
    return;
   }
   for(int i=0;i<students.size();i++)
   {
    students[i].displaystudent();
    cout<<endl;
   }
}

//to search a student
void search_Student(vector<Student>&students)
{
    int roll_num;
    cout<<"Enter Roll Number of the Required Student : ";
    cin>>roll_num;
    int i=0;
    for(;i<students.size();i++)
    {
        if(students[i].getRoll_no()==roll_num)
        {
            cout<<"\n\t\tStudent Found "<<endl;
            students[i].displaystudent();
            return;
        }

    }
    if(i==students.size())
    cout<<"\n\t\tSorry,Student is not present "<<endl;

}

//to update student record
void update_Student(vector<Student>&students)
{
     string name;
     bool found=false;
     int choice;

     cout<<" Enter Nameof Required Student : ";
     cin>>name;

     for(int i=0;i<students.size();i++)
     {
        if(students[i].get_name()==name)
        {
            found=true;

            cout<<"\t\t---Student Found -----"<<endl;
			cout<<"\t\t 1. Update Rollno "<<endl;
			cout<<"\t\t 2. Update Name "<<endl;
			cout<<"\t\t 3. Update Age "<<endl;
			cout<<"\t\tEnter Your Choice : ";

			cin>>choice;
            switch(choice)
            {
                case 1:
                {
                    int roll_num;
                    cout<<"Enter New Roll Number : ";
                    cin>>roll_num;
                    students[i].setRoll_no(roll_num);
                }
                break;

                case 2:
                {
                    string name;
                    cout<<" Enter New Name : ";
                    cin>>name;
                    students[i].set_name(name);
                }
                break;

                case 3:
                {
                    int age;
                    cout<<" Enter New Age : ";
                    cin>>age;
                    students[i].set_age(age);
                }
                break;

                default:
                cout<<" Invalid Choice "<<endl;
         
            }
        }
        if(!found)
        {
            cout<<" Record Not found "<<endl;
            return;
        }

     }

}

//to delete a student
void delete_Student(vector<Student>&students)
{
    string name;
    cout<<" Enter Name of Student to Delete : ";
    cin>>name;
     for(int i=0;i<students.size();i++)
     {
        if(students[i].get_name()==name)
        {
            students.erase(students.begin()+i);
            cout<<"\n\t\tStudent Removed Successfully "<<endl;
        }
     }

}
int main()
{
   vector<Student> students;//vector of multiple student object
   char choice;
   do{
        int option;
        cout<<"\t\t--------------------------------";
        cout<<"\n\t\t*** Student Management System ***";
        cout<<"\n\t\t--------------------------------";
        cout<<"\n\t\t1.Add New Student "<<endl;
        cout<<"\t\t2.Display All Students "<<endl;
        cout<<"\t\t3.Search Student "<<endl;
        cout<<"\t\t4.Update Student Record "<<endl;
        cout<<"\t\t5.Delete Student Record"<<endl;
        cout<<"\t\t6.Exit "<<endl;

        cout<<" Enter Your Choice : "<<endl;
        cin>>option;

        switch(option)
        {
            case 1:
               add_NewStudent(students);
               break;
            case 2:
               display_Students(students);
               break;
            case 3:
                search_Student(students);
                break;
            case 4:
                update_Student(students);
                break;
            case 5:
                delete_Student(students);
                break;
            case 6:
                exit(1);
            default:
               cout<<"\n\t\tInvalid Choice "<<endl;

        }
       cout<<"\n\t\tDo yoy want to continue?[y/n] :";
       cin>>choice;
   }while(choice=='y'||choice=='Y');
   return 0;

}