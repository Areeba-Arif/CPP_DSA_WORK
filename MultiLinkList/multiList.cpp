#include <iostream>
using namespace std;
struct SL_Node
{
   int seatNo;
   SL_Node *SNext;
};

struct CL_Node{
    int courseNo;
    CL_Node *cNext;
    SL_Node *std_list;
};
CL_Node *cList = NULL; 

int searchCourse(int courseNo){
    
    CL_Node* cCurr = cList;
    if(cCurr==NULL){
        cout<<"List is empty"<<endl;
        return -1;
    }
    int position = 0;
    while(cCurr!=NULL){
        position++;
        if(cCurr->courseNo == courseNo){
            cout<<"Course Found at position "<<position<<endl;
            return position;
        }
        cCurr = cCurr->cNext;
    }
    cout<<"Course not found!"<<endl;
    return -1;
}


int searchStdInCourse(int SeatNo , int courseNo)
{
    CL_Node* cCurr = cList;
    if(cCurr==NULL)
    {
        cout<<"List is empty"<<endl;
        return -1;
    }

    while (cCurr!=NULL)
    {
        if(cCurr->courseNo==courseNo)
        {
            SL_Node* sCurr = cCurr->std_list;
            int position = 1;

            if(sCurr==NULL)
            {
                cout<<"No student is registered in this course!"<<endl;
                return -1;
            }

            while(sCurr!=NULL)
            {
                if(sCurr->seatNo == SeatNo)n
                {
                    cout<<"student found in a course "<<courseNo << " at position  "<<position<<endl;
                    return position;
                }
                sCurr = sCurr->SNext;
                position++;
            }


            // cout<<"Student not found in any course"<<endl;
            return -1;


        }

        cCurr = cCurr->cNext;

    }

    cout<<"Course Not Found!"<<endl;
    return -1;
    
}


int searchStudent(int seatNo)
{
    CL_Node* cCurr = cList;
    bool Found = false;
    if(cCurr==NULL){
        cout<<"List is empty"<<endl;
        return -1;
    }

    while(cCurr!=NULL)
    {
        SL_Node* sCurr = cCurr->std_list;

        while(sCurr!=NULL)
        {
            if(sCurr->seatNo == seatNo)
            {
                cout<<"Student "<<seatNo<<" found in course "<<cCurr->courseNo<<endl;
                Found = true;
            }

            sCurr = sCurr->SNext;
        }

        cCurr = cCurr->cNext;
    }

    if(!Found)
    {
        cout<<"Student not found in any course"<<endl;
        return -1;
    }

    return 1;
}

//add courses in a list
void addCourse(int cNo){
    if(searchCourse(cNo)!=-1){
        cout<<"This course already exist"<<endl;
        return;
    }
    CL_Node *temp = (CL_Node*)malloc(sizeof(CL_Node));
    temp->courseNo = cNo;
    temp->cNext = NULL;
    temp->std_list = NULL;
    if(cList==NULL){
        cList = temp;
    }else{
        //same as single linked list
        CL_Node* cCurr = cList;
        while(cCurr->cNext!=NULL){
            cCurr = cCurr->cNext;
        }
        cCurr->cNext = temp;
    }
}

void addStd(int seatNo , int courseNo){
    if(searchStdInCourse(seatNo , courseNo)!=-1){
        cout<<"This student already enrolled!"<<endl;
        return;
    }
    CL_Node *cCurr = cList;
    while ((cCurr!=NULL))
    {
        if(courseNo == cCurr->courseNo){
            SL_Node *temp;
            temp = (SL_Node*)malloc(sizeof(SL_Node));
            temp->SNext = NULL;
            temp->seatNo = seatNo;

            if(cCurr->std_list==NULL){
                cCurr->std_list = temp;
            }else{
                SL_Node *sCurr = cCurr->std_list;

                while(sCurr->SNext!=NULL){
                    sCurr = sCurr->SNext;
                }

                sCurr->SNext =  temp;
            }
            return;
        }

        cCurr = cCurr->cNext;
    }

    cout<<"ERROR! course number doesn't exist...";
    
}


void display(){
    CL_Node *cCurr = cList;

    if(cCurr==NULL){
        cout<<"The list is empty."<<endl;
        return;
    }
    while(cCurr!=NULL){
        //display courses
        cout<<"Course NO: "<<cCurr->courseNo<<" -> Students: ";

        //inner loop to display the std list for this course
        SL_Node *sCurr = cCurr->std_list;

        if(sCurr==NULL){
            cout<<"[No students registered]";
        }

        while(sCurr!=NULL){
            cout<<"("<< sCurr->seatNo<<") ";
            sCurr = sCurr->SNext;//move to the next student
        }

        cout<< endl << "|" << endl;
        cCurr = cCurr->cNext; //move to the next course
    }
}





void displayCourseOnly()
{
    CL_Node* cCurr = cList;

    if(cCurr==NULL)
    {
        cout<<"Courses are not available!";
        return ;
    }

    while(cCurr!=NULL)
    {
        cout<<cCurr->courseNo<<endl;
        cCurr = cCurr->cNext;
    }
}


void displayStudentCourses(int seatNo){
    CL_Node* cCurr = cList;
    bool found = false;

    if(cCurr==NULL)
    {
        cout<<"Courses are not available"<<endl;
        return;
    }

    cout<<"Student seat number: "<<seatNo<<endl;
    cout<<"Registered in courses"<<endl;

    while (cCurr!=NULL)
    {
        SL_Node* sCurr = cCurr->std_list; 
        while(sCurr!=NULL)
        {
            if(sCurr->seatNo==seatNo)
            {
                cout<<cCurr->courseNo<<" ";
                found = true;
                break;  //move to the next course
            }

            sCurr = sCurr->SNext;
        }

        cCurr = cCurr->cNext;
    }

    if(!found)
    {
        cout<<"Not registered in any course"<<endl;
        
    }

    cout<<endl;
    
}


void deleteCourse(int courseNo){
    if(cList==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }

    CL_Node* cCurr = cList;
    CL_Node* prev = NULL;

    while(cCurr!=NULL && cCurr->courseNo != courseNo){
         prev = cCurr;
         cCurr = cCurr->cNext;
    }

    if(cCurr==NULL){
        cout<<"Course not found!"<<endl;
        return;
    }

    //delete student list

        SL_Node* sCurr =cCurr->std_list;
        while(sCurr!=NULL){
            SL_Node* temp = sCurr;
            sCurr = sCurr->SNext;
            free(temp);
        }    
   

    //remove course
    if(prev==NULL)
    {
        cList = cCurr->cNext;
    }
    else
    {
        prev->cNext = cCurr->cNext;
    }

    free(cCurr);
    cout << "Course " << courseNo << " deleted successfully!" << endl;
}


void deleteStdCourse ( int sNo , int cNo )
{
    if( cList == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    CL_Node* cCurr = cList;
    CL_Node* cPrev = NULL;

    while ( cCurr != NULL && cCurr->courseNo != cNo)
    {
        cPrev = cCurr;
        cCurr = cCurr->cNext;
    }

    if(cCurr == NULL)
    {
        cout << "Course not found" <<endl;
        return;
    }

    SL_Node* sCurr = cCurr->std_list;
    SL_Node* sPrev = NULL;

    while(sCurr != NULL && sCurr->seatNo != sNo)
    {
        sPrev = sCurr;
        sCurr = sCurr->SNext;
    }

    if(sCurr == NULL)
    {
        cout<<"Student not found in this course"<<endl;
        return;
    }

    if(sPrev == NULL)
    {
        // first student
        cCurr->std_list = sCurr->SNext;
    }
    else
    {
        sPrev->SNext = sCurr->SNext;
    }

    free(sCurr);
    cout<<"Student "<<sNo<<" removed from course "<<cNo<<endl;

    


}

void deleteStd(int seatNo)
{
    if(cList == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    CL_Node* cCurr = cList;
    bool found = false;

    // traverse all courses
    while(cCurr != NULL)
    {
        SL_Node* sCurr = cCurr->std_list;
        SL_Node* sPrev = NULL;

        // traverse student list of current course
        while(sCurr != NULL)
        {
            if(sCurr->seatNo == seatNo)
            {
                // delete student node
                if(sPrev == NULL)
                {
                    // first student
                    cCurr->std_list = sCurr->SNext;
                }
                else
                {
                    sPrev->SNext = sCurr->SNext;
                }

                SL_Node* temp = sCurr;
                sCurr = sCurr->SNext;
                free(temp);

                found = true;
                continue;   // continue checking same course
            }

            sPrev = sCurr;
            sCurr = sCurr->SNext;
        }

        cCurr = cCurr->cNext;
    }

    if(found)
        cout<<"Student "<<seatNo<<" removed from all courses"<<endl;
    else
        cout<<"Student not found in any course"<<endl;
}



int main() {
    int yourChoice;
    
    while(true){
        cout << "\n--- MENU ---" << endl;
        cout <<"1. Add a Course" << endl;
        cout <<"2. Delete a course" <<endl;
        cout <<"3. Search a course" <<endl;
        cout <<"4. Display list of course" <<endl;
        // cout <<"5. Update a course" <<endl; //marziiiii.....
        cout <<"6. Add a student to a course" <<endl;
        cout <<"7. Delete a student from course" <<endl;
        cout <<"8. Delete a student" <<endl;
        cout <<"9. Search a student in a course" <<endl;
        cout <<"10. Search a student" <<endl;
        cout <<"11. Display student list of a course" <<endl;
        cout <<"12. Display All" << endl;
        cout <<"13. Exit" << endl;

        cout << "Enter your choice: " <<endl;

        cin>>yourChoice;
        switch(yourChoice){
            case 1:
            {
                int value;
                cout<<"Enter course u want to add..";
                cin>>value; 
                addCourse(value);
                cout<<"course inserted sucessfully!"<<endl;
                
                break;
            }

            case 2:
            {
                int course;
                cout << "Enter course number to delete: ";
                cin >> course;
                deleteCourse(course);
                break;
            }

            case 3:
            {
                int course;
                cout << "Enter course number to search: ";
                cin >> course;
                searchCourse(course);
                break;
            }

            case 4:
            {
                displayCourseOnly();
                break;
            }


            case 6:
            {   
                int course , seat;
                cout<<"In which course you want to register?";
                cin>>course;
                cout<<"Enter your seat number!";
                cin>>seat;
                addStd(seat , course);
                break;
            }

            
            case 7:
            {
                int sNo , cNo;
                cout<<"Enter course number u want to cancel registration?";
                cin>>cNo;
                cout<<"Enter your seat number : ";
                cin>>sNo;
                deleteStdCourse(sNo , cNo);
                break;
            }

            case 8 :
            {
                int seatNo;
                cout << "Enter your seat number: " << endl;
                cin >> seatNo;
                deleteStd(seatNo);
                break;
            }

            case 9:
            {
                int course, seat;
                cout << "Enter course number: ";
                cin >> course;
                cout << "Enter seat number: ";
                cin >> seat;
                searchStdInCourse(seat, course);
                break;
            }
            case 10:
            {
                int seatNo;
                cout<<"Enter Student seat number";
                cin>>seatNo;
                searchStudent(seatNo);
                break;
            }
            case 11:
            {
                int seat;
                cout << "Enter seat number: ";
                cin >> seat;
                displayStudentCourses(seat);
                break;
            }


            case 12:
            {
                display();
                break;
            }
            case 13:
            {
                cout << "Exiting..." << endl;
                return 0;
            }
            default:
            {
                cout << "Invalid choice!" << endl;
            }





        }
    }
    


    
   return 0;
}