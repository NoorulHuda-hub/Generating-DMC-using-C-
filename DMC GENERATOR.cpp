#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <iomanip>
#define noor cout<<endl;
using namespace std;
string grp;
//defining a class named studentinfo
class studentinfo
{      		
        public:
        int comp,math,phy,eng,isl,urdu,bio,chem;
		char finame[60];
		char fname[45];
		char fcol[100];
		int rollno;
		int failedPaperValues[6];
		float totalmarks;
		float percent;
		string fail[6];
		char gradePerSubject[6];
		string remarksPerSubject[6];
	    int getmarksmed();
	
	//member function which takes the basic info of the student
		void getinfo(){
		cout<<endl<<"Enter Your details Such as Roll no and Name and Group"<<endl;
		cout<<"Please enter your roll no "<<endl;
		cin>>rollno;
		cout<<"";
		cin.getline(finame,60);
		cout<<"\n Please enter your Full name  : "<<endl;
		cin.getline(fname,45);
		cout<<"\n Please enter your college name:"<<endl;
		cin.getline(fcol,60);
		cout<<"\n Please enter your Group:"<<endl;
		cout<<"1. PRE MEDICAL"<<endl;
		cout<<"2. Pre Engineering"<<endl;
		cout<<"3. ICS"<<endl;
		cin>>grp;
}

	char gradeingPerSujbect(int submarks){
	   char subjectGrades;
        if(submarks>=85 && submarks<=100){
            subjectGrades = 'A';
        }else if(submarks>=75 && submarks<85){
            subjectGrades = 'B';
        }else if(submarks>=65 && submarks<75){
            subjectGrades = 'C';
        }else if(submarks>=55 && submarks<65){
            subjectGrades = 'D';
        }else if(submarks>=40 && submarks<55){
                subjectGrades = 'E';
        }else {
                subjectGrades = 'F';
        }

        return subjectGrades;
	}
string remarks_of_Subject(int submarks)
{
    string remarking;
            if(submarks>=85 && submarks<=100){
            remarking = "OutStanding";
        }else if(submarks>=75 && submarks<85){
            remarking = "Excellent";
        }else if(submarks>=65 && submarks<75){
            remarking = "Very Good";
        }else if(submarks>=55 && submarks<65){
            remarking = "Good";
        }else if(submarks>=40 && submarks<55){
                remarking = "Poor";
        }else {
                remarking = "Fail";
        }
            return remarking;

     }
//member function named getmarks() which takes the marks from the student
int getmarks()
{
			cout<<"Enter Marks for six Subjects"<<endl;
			if(grp=="MED")
		{
	    sbio:
		cout<<"\nEnter your Biology marks "<<endl;
		cin>>bio;
		if(bio<=100 && bio>=0){

                gradePerSubject[0] = gradeingPerSujbect(bio);
                remarksPerSubject[0] = remarks_of_Subject(bio);
			if(bio<40 ){
				fail[0]="Biology";
				failedPaperValues[0]=bio;
			}else{

				fail[0]="";
           }

		}else{
			cout<<"Invalid marks : The marks must be between 0 and 100"<<endl;
			goto sbio;
		}
	}
	else if(grp=="ENG" || grp=="ICS")
	{
	
		smath:
		cout<<"Enter your Mathematics marks "<<endl;
		cin>>math;
			if(math<=100 && math>=0){
                    gradePerSubject[0] = gradeingPerSujbect(math);
                    remarksPerSubject[0] = remarks_of_Subject(math);
	         	
					if(math<40)
				{

					fail[0]="Mathematics";
					failedPaperValues[0] = math;
				}else{
					fail[0]="";

				}

	}else{
			cout<<"Invalid marks : The marks must be between 0 and 100"<<endl;
			goto smath;
		}	
	}	
		
	if(grp=="ENG" || grp=="MED")
	{
		schem:
		cout<<"Enter your Chemistry marks "<<endl;
		cin>>chem;
			if(chem<=100 && chem>=0){
                    gradePerSubject[1] = gradeingPerSujbect(chem);
                    remarksPerSubject[1] = remarks_of_Subject(chem);
	         	
					if(chem<40)
				{

					fail[1]="Chemistry";
					failedPaperValues[1] = chem;
				}else{
					fail[1]="";

				}

	     }else{
			cout<<"Invalid marks : The marks must be between 0 and 100"<<endl;
			goto schem;
		}}

		else{
			scomp:
		cout<<"\nEnter your Computer marks "<<endl;
		cin>>comp;
		if(comp<=100 && comp>=0){

                gradePerSubject[1] = gradeingPerSujbect(comp);
                remarksPerSubject[1] = remarks_of_Subject(comp);
			if(comp<40 ){
				fail[0]="Computer";
				failedPaperValues[1]=comp;
			}else{

				fail[1]="";
           }

		}else{
			cout<<"Invalid marks : The marks must be between 0 and 100"<<endl;
			goto scomp;
		}
			
		}
			sphy:
		cout<<"Enter your Physics marks "<<endl;
		cin>>phy;
			if(phy<=100 && phy>=0 ){

                gradePerSubject[2] = gradeingPerSujbect(phy);
                remarksPerSubject[2] = remarks_of_Subject(phy);

				if(phy<40 )
			{
				fail[2]="Physics";
				failedPaperValues[2]= phy;

			}else{
				fail[2]="";
			}

		}else{
			cout<<"Invalid marks : The marks must be between 0 and 100"<<endl;
			goto sphy;
		}

			seng:
		cout<<"Enter your English marks "<<endl;
		cin>>eng;
			if(eng<=100 && eng>=0){
                    gradePerSubject[3] = gradeingPerSujbect(eng);
                    remarksPerSubject[3] = remarks_of_Subject(eng);
            if(eng<40 )
			{

				fail[3]="English";
				failedPaperValues[3]= eng;
			}else{
				fail[3]="";
			}

		}else{
			cout<<"Invalid marks : The marks must be between 0 and 100"<<endl;
			goto seng;
		}

			sisl:
		cout<<"Enter your Islamyat marks "<<endl;
		cin>>isl;
			if(isl<=50 && isl>=0){
                    float islper;
                islper = (isl*100)/50;
                gradePerSubject[4] = gradeingPerSujbect(islper);
                remarksPerSubject[4] = remarks_of_Subject(islper);
				if(isl<18 )	{
				fail[4]="Islamyat";
				failedPaperValues[4]= isl;
			}else{
				fail[4]="";
			}

		} else{
			cout<<"Invalid marks : The marks must be between 0 and 50"<<endl;
			goto sisl;
		}

			surdu:
		cout<<"Enter your Urdu marks "<<endl;
		cin>>urdu;
			if(urdu<=100 && urdu>=0){
                    gradePerSubject[5] = gradeingPerSujbect(urdu);
                    remarksPerSubject[5] = remarks_of_Subject(urdu);
				if(urdu<40 )
			{

				fail[5]="Urdu";
				failedPaperValues[5]= urdu;
			}else{

				fail[5]="";
			}

		}else{
			cout<<"Invalid marks : The marks must be between 0 and 100"<<endl;
			goto surdu;
		}
}
	// ending of getting marks function
 int  MinimumMarking(){
 	int minimumMarks = 100;
 	if(grp=="ICS")
 	{
 	int mini[6]={comp,math,phy,eng,isl,urdu};	
	 for(int i=0;i<6;i++){
 		if(mini[i]<minimumMarks){
 			minimumMarks = mini[i];
     }
	 }
 	return minimumMarks;}
 	else if(grp=="MED")
 	{
 			int mini[6]={bio,chem,phy,eng,isl,urdu};
			 	for(int i=0;i<6;i++){
 		if(mini[i]<minimumMarks){
 			minimumMarks = mini[i];
     }
	 }
 	return minimumMarks;;
	 }
	 	else
 	{
 	int mini[6]={chem,math,phy,eng,isl,urdu};
 	for(int i=0;i<6;i++){
 		if(mini[i]<minimumMarks){
 			minimumMarks = mini[i];
     }
	 }
 	return minimumMarks;}
 }

string MinimumMarksPaperName(){
	 	string checkMinimumMarks;
	 		int minimumMarks = 100;
	if(grp=="ICS")
 	{int mini[6]={comp,math,phy,eng,isl,urdu};
	 string final[6]={"Computer","Mathematics","Physics","English","Islamyat","Urdu"};
	 	for(int i=0;i<6;i++){
 		if(mini[i]<minimumMarks){
 			minimumMarks = mini[i];
 			checkMinimumMarks = final[i];

 		}}	return checkMinimumMarks;}
 	else if(grp=="ENG")
 	{int mini[6]={chem,math,phy,eng,isl,urdu};
	 string final[6]={"Chemistry","Mathematics","Physics","English","Islamyat","Urdu"};
	 	for(int i=0;i<6;i++){
 		if(mini[i]<minimumMarks){
 			minimumMarks = mini[i];
 			checkMinimumMarks = final[i];

 		}}	return checkMinimumMarks;}
 	else
 	{int mini[6]={chem,bio,phy,eng,isl,urdu};
	 string final[6]={"Biology","Mathematics","Physics","English","Islamyat","Urdu"};
	 	for(int i=0;i<6;i++){
 		if(mini[i]<minimumMarks){
 			minimumMarks = mini[i];
 			checkMinimumMarks = final[i];

 		}}
 		return checkMinimumMarks;}}
 
 
  int MaximumMarking(){
  	string checkhigh;
  		int maximumMarks = 0;
  	int maxi[6];
  	if(grp=="ICS")
  	{int maxi[6]={comp,math,phy,eng,isl,urdu};
	  	for(int i=0;i<6;i++){
 		if(maxi[i]>maximumMarks){
 			maximumMarks = maxi[i];
 		}
	 }return maximumMarks;
 	}
  	else if(grp=="ENG")
  	{ int maxi[6]={chem,math,phy,eng,isl,urdu};
	  	  	for(int i=0;i<6;i++){
 		if(maxi[i]>maximumMarks){
 			maximumMarks = maxi[i];
 		}
	 } 
	 return maximumMarks; }
  	else
  	{int maxi[6]={chem,bio,phy,eng,isl,urdu};
	  	  	  	for(int i=0;i<6;i++){
 		if(maxi[i]>maximumMarks){
 			maximumMarks = maxi[i];
 			
 		}
 		
	 }return maximumMarks; }
 	

}
	string MaximumMarksPaperName(){
  	string checkGreater;
  	 	int maximumMarks = 0;
 	if(grp=="ICS"){int maxi[6]={comp,math,phy,eng,isl,urdu};
	 string subjects[6]={"Computer","Mathematics","Physics","English","Islamyat","Urdu"};
	  	for(int i=0;i<6;i++){
 		if(maxi[i]>maximumMarks){
 			maximumMarks = maxi[i];
 			checkGreater = subjects[i];
 		}
	 }	return checkGreater;}
 		else if(grp=="ENG"){ int maxi[6]={chem,math,phy,eng,isl,urdu};
		 string subjects[6]={"Chemistry","Mathematics","Physics","English","Islamyat","Urdu"};
		  	for(int i=0;i<6;i++){
 		if(maxi[i]>maximumMarks){
 			maximumMarks = maxi[i];
 			checkGreater = subjects[i];
 		}
	 }	return checkGreater;}
 			else{int maxi[6]={bio,chem,phy,eng,isl,urdu};
 		string	subjects[6]={"Chemistry","Biology","Physics","English","Islamyat","Urdu"};
		  	for(int i=0;i<6;i++){
 		if(maxi[i]>maximumMarks){
 			maximumMarks = maxi[i];
 			checkGreater = subjects[i];
 		}
	 }	return checkGreater;}}
// starting of gettotalmarks
 int  gettotalmarks(){
if(grp=="MED")
{
 	totalmarks=chem+eng+isl+phy+bio+urdu;
 	 return totalmarks;
 }
 else if(grp=="ENG")
 {
 	totalmarks=chem+eng+isl+phy+math+urdu;
 	 return totalmarks;
 }
 else
 {
 		totalmarks=comp+eng+isl+phy+math+urdu;
 	 return totalmarks;
 }

 }
 // ending of gettotalmarks function

// grading function
 char grading(){
 	 char  grade;
 	 if(percentage()>=80 && percentage()<=100){
 	 	 grade='A';
 	 }else if (percentage()>=70 && percentage()<80){
 	 	grade='A';
 	 }else if (percentage()>=60 && percentage()<70){
 	 	grade='B';
 	 }else if(percentage()>=50 && percentage()<60){
 	 	grade='C';
 	 }else if(percentage()>=40 && percentage()<50){
 	 	grade='D';
 	 }else if(percentage()>=33 && percentage()<40){
 	 	grade='E';
 	 }else if(percentage()<33){

 	 	grade = 'F';
 	 }

        return (grade);
 }

// starting of percentage function
 float percentage(){
 	 float percent=0;
 	 percent=float(totalmarks/550)*100;
 	 return percent;
     }

    string overallRemarking(){

        string remarking;
         if(percentage()>=85 && percentage()<=100){
                remarking = "Outstanding";
 	 }else if (percentage()>=70 && percentage()<85){
                remarking = "Excellent";
 	 }else if (percentage()>=60 && percentage()<70){
                remarking = "Very Good";
 	 }else if(percentage()>=50 && percentage()<60){
                    remarking="Weak";
 	 }else if(percentage()>=40 && percentage()<50){
                    remarking="Study Hard";
 	 }else if(percentage()<40){
            remarking = "Not Eligible for next class";
 	 }

        return remarking;
    }


  void dmcSeparateFile();

int countfail(){	//this function counts the paper which are failed
				int failed = 0;
		for(int i=0;i<6;i++){
			if(fail[i]!=""){
				failed++;
			}
		}

		return (failed);
	}


	void  showFailedPapers() 	// function which shows failed papers
{
int count = 0;
 for(int i=0;i<6;i++){

 	if(fail[i]!="")
	 {
            count++;
		cout<<count<<"."<<fail[i]<<" =  "<<failedPaperValues[i]<<"  \t";
	 }

  }

 }

	// status function which decide wether the status of the student is passed or not
 string checkstatus(){
 	string status;
 	if(percentage()<33 || countfail()>=3){
 		status="Failed";

 	}else{
 		status="Passed";
 	}
 	return status;
 }


    string checkqualification(){

        string promotion;
        if(checkstatus()=="Passed"){
            promotion="Promoted";
        }else if(checkstatus()=="Failed"){

            promotion="Not Promoted";
        }
        return promotion;
    }

// custon function printing line
 void line(){
 for(int i=0;i<=120;i++){
 	cout<<"_";
 }
 cout<<endl<<endl;
}

// custon function for another line

void line1(){
 for(int i=0;i<=120;i++){
 	cout<<"-";
 }
 cout<<endl;
}

void dashline();
void solidline();
void FailedPapers();


//function for console

    void showinfo(){

   	cout<<endl<<endl;
   	cout<<"***********************************FEDERAL BOARD OF INTERMEDIATE & SECONDARY EDUCATION ISLAMABAD***********************************"<<endl<<endl;
	cout<<"************************************************ Detail Marks Certificate ************************************************"<<endl<<endl;
	cout<<setw(20)<<"Roll No : \t"<<rollno<<endl;
	cout<<setw(20)<<"Group   : \t"<<grp<<endl;
	cout<<setw(20)<<"Name    : \t"<<fname<< "\tfrom\t"<<fcol<<"\tappeared as Regular Student"<<endl;
    line();
   	cout<<"\tSubjects   :\tObtained Marks\t \t  Total Marks \t\t Grade";cout<<"\t\t Remarks"; cout<<endl;
    line();if(grp=="MED"){
   	cout<<"\tBiology    : \t\t"<<bio <<"\t\t\t 100 \t\t   "<<gradePerSubject[0]<<"\t\t "<<remarksPerSubject[0]<<endl; line1();}
   	else{
	cout<<"\tMathematics: \t\t"<<math<<"\t\t\t 100 \t\t   "<<gradePerSubject[0]<<"\t\t "<<remarksPerSubject[0]<<endl; line1(); }if(grp=="ICS"){
   	cout<<"\tComputer   : \t\t"<<comp<<"\t\t\t 100 \t\t   "<<gradePerSubject[1]<<"\t\t "<<remarksPerSubject[1]<<endl; line1();}
   	else{
	cout<<"\tChemistry  : \t\t"<<chem<<"\t\t\t 100 \t\t   "<<gradePerSubject[1]<<"\t\t "<<remarksPerSubject[1]<<endl; line1() ; }
   	cout<<"\tPhysics    : \t\t"<<phy<<"\t\t\t 100 \t\t   "<<gradePerSubject[2]<<"\t\t "<<remarksPerSubject[2]<<endl; line1();
   	cout<<"\tEnglish    : \t\t"<<eng<<"\t\t\t 100 \t\t   "<<gradePerSubject[3]<<"\t\t "<<remarksPerSubject[3]<<endl; line1();
   	cout<<"\tIslamyat   : \t\t"<<isl<<"\t\t\t  50 \t\t   "<<gradePerSubject[4]<<"\t\t "<<remarksPerSubject[4]<<endl; line1();
   	cout<<"\tUrdu       : \t\t"<<urdu<<"\t\t\t 100 \t\t   "<<gradePerSubject[5]<<"\t\t "<<remarksPerSubject[5]<<endl; line1();
   	cout<<"\tObtained Marks  = \t"<<gettotalmarks()<<"\t\t\t 550"<<endl;
   	line1();   	cout<<"Percentage    : "<<percentage();   cout<<"                              Minimum Marks Subject Name : "<<MinimumMarksPaperName()<<endl;
   	cout<<"Overall Grade : "<<grading();      cout<<"                        \t     Maximum Marks Subject Name : "<<MaximumMarksPaperName()<<endl;
   	cout<<"Status        : " <<checkstatus(); cout<<"                               Minimum Subject Marks     : "<<MinimumMarking()<<endl;
    cout<<"Failed Papers : "<<countfail();    cout<<"                        \t     Maximum Subject  Marks     : "<<MaximumMarking()<<endl;
    cout<<"Remarks       : "<<overallRemarking()<<endl;
    cout<<"Qualified     : "<<checkqualification();
   	if(countfail()==0){

	   }else {

	   	cout<<endl; cout<<"Failed Papers include : ";
		showFailedPapers();
		}

	cout<<endl;
   	cout<<endl;
   	cout<<endl;

   }
};
// ending of main class

ofstream data;   // object of ofstream class dealing with files

void studentinfo::dashline(){

 for(int i=0;i<=120;i++){
 	data<<"-";
 }
 data<<endl;
}


 void studentinfo::solidline()
 {
 for(int i=0;i<=120;i++){
 	data<<"_";
 }
 data<<endl<<endl;
}

void studentinfo::FailedPapers()
{
	int count=0;
 for(int i=0;i<6;i++)
 	{


 	if(fail[i]!="")
	 {
	 	count++;
		data<<count<<"."<<fail[i]<<" =  "<<failedPaperValues[i]<<"  \t";
	 }
  	}
}


 void studentinfo::dmcSeparateFile(){
		data.open("DMCFILE.txt");
	data<<"***********************************FEDERAL BOARD OF INTERMEDIATE & SECONDARY EDUCATION ISLAMABAD***********************************"<<endl<<endl;
	data<<"************************************************ Detail Marks Certificate ********************************************************"<<endl<<endl;
	data<<setw(20)<<"Roll No : \t"<<rollno<<endl;
	data<<setw(20)<<"Group   : \t"<<grp<<endl;
	data<<setw(20)<<"Name    : \t"<<fname<<"\tfrom\t "<<fcol<<endl;	solidline();
   	data<<"Subjects    : \t\tObtained Marks\t\tTotal Marks \tGrade";      data<<"\tRemarks";data<<endl;solidline();if(grp=="MED"){
   	data<<"Biology     : \t\t"<<bio<<"\t\t\t 100 \t\t   "<<gradePerSubject[0]<<"\t\t "<<remarksPerSubject[0]<<endl; dashline();}else{
	data<<"Mathematics : \t\t"<<math<<"\t\t\t 100 \t\t   "<<gradePerSubject[0]<<"\t\t "<<remarksPerSubject[0]<<endl; dashline();}if(grp=="ICS"){
   	data<<"Computer    : \t\t"<<comp<<"\t\t\t 100 \t\t   "<<gradePerSubject[1]<<"\t\t "<<remarksPerSubject[1]<<endl; dashline();}else{
   	data<<"Chemistry   : \t\t"<<chem<<"\t\t\t 100 \t\t   "<<gradePerSubject[1]<<"\t\t "<<remarksPerSubject[1]<<endl; dashline();}	
   	data<<"Physics     : \t\t"<<phy<<"\t\t\t  100 \t\t   "<<gradePerSubject[2]<<"\t\t "<<remarksPerSubject[2]<<endl;  dashline();
   	data<<"English     : \t\t"<<eng<<"\t\t\t  100 \t\t   "<<gradePerSubject[3]<<"\t\t "<<remarksPerSubject[3]<<endl;  dashline();
   	data<<"Islamyat    : \t\t"<<isl<<"\t\t\t   50 \t\t   "<<gradePerSubject[4]<<"\t\t "<<remarksPerSubject[4]<<endl;  dashline();
   	data<<"Urdu         : \t\t"<<urdu<<"\t\t 100 \t\t   "<<gradePerSubject[5]<<"\t\t "<<remarksPerSubject[5]<<endl; dashline();
   	data<<"Obtained Marks  = \t\t"  <<gettotalmarks()<<"\t\t\t 550"<<endl; dashline(); data<<endl;
   	data<<"Percentage    : "<<percentage();   data<<"                                    Minimum Marks Subject Name : "<<MinimumMarksPaperName()<<endl;
   	data<<"Overall Grade : "<<grading();      data<<"                        \t     Maximum Marks Subject Name : "<<MaximumMarksPaperName()<<endl;
   	data<<"Status        : " <<checkstatus(); data<<"                               Minimum Subjects Marks     : "<<MinimumMarking()<<endl;
    data<<"Failed Papers : "<<countfail();    data<<"                        \t     Maximum Sujbect  Marks     : "<<MaximumMarking()<<endl;
    data<<"Remarks       : "<<overallRemarking()<<endl;
    data<<"Qualified     : "<<checkqualification();
      	if(countfail()==0){
  		}else {
	   	data<<endl; data<<"Failed Papers Include :  ";
		FailedPapers();
	    }
		data.close();
		//	ShellExecute( NULL,"open","DMCFILE.txt",NULL,NULL,SW_NORMAL);
			ShellExecute( 0,"open","DMCFILE.txt",0,0,SW_SHOW);

		   }

line()
{
   for(int i=0;i<120;i++)
   {
   	cout<<"_";
   }
}
fbise()
{
	for(int i=0;i<10;i++){
	cout<<"FBISE\t\t\t\t";}
}

main()
{

	studentinfo project;
	    char choice;

    cout<<"\tWELCOME TO THE OFFICIAL WEBSITE OF FEDERAL BOARD OF INTERMEDIATE AND SECONDARY EDUCATION, ISLAMABAD\t"<<endl;
    cout<<"\tHere you can generate your DMC:"<<endl;
    fbise();
    cout<<endl;
	cout<<"****NEW****  ****NEW****   ****NEW****"<<endl;
	cout<<"RESULTS  OF  SSC-1  SSC-2  ARE  OUT "<<endl; 
    cout<<endl;
    cout<<"1. Enter 1 to continue "<<endl;
    cout<<"2. Exit Program "<<endl;
    cin>>choice;
   switch(choice){
            case '1':
                cout<<"Welcome to My C++ Project (\"GENERATING STUDENT DETAILED MARKS CERTIFCATE (DMC)\")"<<endl;
                cout<<"Enter your group";
		               project.getinfo();
		                project.getmarks();
                properCommand:
            cout<<"\n Generating DMC \n"<<endl;
            cout<<endl;
            cout<<"1. Console "<<endl;
            cout<<"2. Exit Project without Printing DMC"<<endl;
            cin>>choice;
              switch(choice){
            case '1':
                project.showinfo();
              cout<<"\n Now printing on a Separate File"<<endl;
                cout<<"Type Y for Yes or N for No "<<endl;
                cin>>choice;
                if(choice=='Y' || choice=='y')
				{
                 project.dmcSeparateFile();
                }
				else if(choice=='n' || choice=='N')
				{
                    exit(0);
                }
                break;
            case '3':
                exit(0);
            default:
                cout<<"Pleas Enter proper command again "<<endl;
               goto  properCommand;
              }
                case '2':
                cout<<"Project Access Denied"<<endl;
                exit(0);
            default:
                cout<<"Please Enter value command such as 1 or 2"<<endl;
                cout<<"Try again"<<endl;
            }
}
        



