#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<stdio.h>
#include<limits>
using namespace std;

struct Date//date struture drama//
{

int mm,dd,yyyy;// product date month year 1-10-2020// 
	
};

int ProNo,price,quant;//global //
 char ProName[30];
	Date d;
		

	ofstream myfile("AddProducts.dat",ios::out|ios::app);//file name input global  
	//When ios::app is set, all output operations are performed at the end of the file//


                                     //5 user defined finctions//
void menu();//Main menu//
void Add_Product();//Product functiom//
void Bill_Report();//Bill report output from file handling//
void Delete_Product();//data delete from file//
void Show_Products();//run time show //


                 ///////////////////////////Products Added//////////////

void Add_Product()
{

  

	
		cout<<"======================================================"<<endl;
			cout<<"                  1.  Add Product              "<<endl;
		cout<<"======================================================"<<endl;
	

		
		cout<<"Enter Product No. : ";
		cin>>ProNo;
		
		           ///////////////////validate user input for Product Numbers ////
			while(1)
	{
		if(cin.fail())//This function returns true when an input failure occurs. In this case it would be an input that is not an integer. 
		{
			cin.clear();// If the cin fails then the input buffer is kept in an error state. cin.clear() 
									//- This is used to clear the error state of the buffer so that 
										//further processing of input can take place. 
											//This ensures that the input does not lead to an infinite loop of error message display
			////- This function is used to ignore the rest of the line after the first instance of error 
			//that has occurred and it skips to or moves to the next line
			cin.ignore(numeric_limits<streamsize>::max(),'\n');//numeric limit is a libary we are using on it which used to count numers limits//
			cout<<"Enter Interger Please  :  ";
				cin>>ProNo;
		}	
						if(!cin.fail())
				break;
	
	}		
	
		cout<<"The Product No.  is :  "<<ProNo<<endl;
		
		//end of prod no;//
								
								
								//prodct name//
								
								
		cout<<"Enter Product Name : ";
		cin>>ProName;

				
                               ///price
		cout<<"Enter Product Price : ";
		cin>>price;
		
							while(1)
						{
							if(cin.fail())
			{
							cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(),'\n');
									cout<<"Enter Interger Please  :  ";
										cin>>price;
		}
		
						if(!cin.fail())
						break;
	
	}
			
			cout<<"The Product Price  is :  "<<price<<endl;
			//end of price//
		
		cout<<"Enter Product Quantity : ";
		cin>>quant;
		
								while(1)
						{
							if(cin.fail())
			{
							cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(),'\n');
									cout<<"Enter Interger Please  :  ";
										cin>>quant;
		}
			
		if(!cin.fail())
		break;
		
		}
			cout<<"The Product quantity  is :  "<<quant<<endl;
			//end of quant//
		
		
		
       		cout<<"Enter Date dd-mm-yyyy: ";
				cin>>d.dd>>d.mm>>d.yyyy;

				if(d.yyyy>=2000 && d.yyyy<=2020)
    {
        //check month
        if(d.mm>=1 && d.mm<=12)
        {
            //check days
            if((d.dd>=1 && d.dd<=31) && (d.mm==1 || d.mm==3 || d.mm==5 || d.mm==7 || d.mm==8 || d.mm==10 || d.mm==12))
                cout<<"Day is invalid.\n";
            else if((d.dd>=1 && d.dd<=30) && (d.mm==4 || d.mm==6 || d.mm==9 || d.mm==11))
                cout<<"Day is invalid.\n";
            else if((d.mm>=1 && d.dd<=28) && (d.mm==2))
                cout<<"Day is invalid.\n";
            else if(d.dd==29 && d.mm==2 && (d.yyyy%400==0 ||(d.yyyy%4==0 && d.yyyy%100!=0)))
                cout<<"Day is invalid.\n";
            else
                cout<<"Day is invalid.\n";
        }
        else
        {
           cout<<"Month is not valid.\n";
        }
    }
      else
       {
        cout<<"Year is not valid.\n";
       }
 
   
				
		
		
		
		
		
	 
	 
					
     //file name//
 if(!myfile)
 {
 	cout<<"File opening error"<<endl;
 		cout<<"Error!!"<<endl;
 	
	 
	  cout<<"Want to go back ? (y|n)"<<endl;
	     char yn;
	     cin>>yn;
	     if((yn=='Y')||(yn=='y'))
	     {
	     	
	     	system("CLS");
	       menu();
	     	
		 }
	     else if((yn=='n')||(yn=='n'))
	     {
	     	system("CLS");
	     	Add_Product();
	     	
		 }
 
 
 }
 
 
 	 myfile<<ProNo<<" "<<ProName<<"  "<<price<<"  "<<quant<<"  "<<d.dd<<d.mm<<d.yyyy<<endl; //added products in file//
 	 
  	 myfile.close();

	 cout<<"\n\t\tItem Added Successfully!"<<endl;
	 
	 


 cout<<"Want to go back ? (y|n)"<<endl;
	     char yn;
	     cin>>yn;
	     if((yn=='Y')||(yn=='y'))
	     {
	     	
	     	system("CLS");
	       menu();
	     	
		 }
	     else if((yn=='n')||(yn=='n'))
	     {
	     	system("CLS");
	     	Add_Product();
	     	
		 }






       
}//end added product fucntion


                            
							  
							     ///////file read only///////////
							   
void Bill_Report()//bill report file  probably garbeg value//
{
	
    
			
			cout<<"======================================================"<<endl;
				cout<<"                  2.  Bill Report                "<<endl;
			cout<<"======================================================"<<endl;
			

			
			
			ifstream ifile;//file name//
	char s[100], fname[20];
	cout<<"Enter file name to read and display its content (like file.txt) : ";//name Added//
	cin>>fname;//type file name AddProducts.dat//
	ifile.open(fname);
	if(!ifile)///if no file :(//
	{
		cout<<"Error in opening file..!!"<<endl;
		getch();
	
	 cout<<"Want to go back ? (y|n)"<<endl;
	     char yn;
	     cin>>yn;
	     if((yn=='Y')||(yn=='y'))
	     {
	     	
	     	system("CLS");
	       menu();
	     	
		 }
	     else if((yn=='n')||(yn=='n'))
	     {
	     	system("CLS");
	     	Bill_Report();
	     	
		 }
		
	}
	
	
	
	while(ifile.eof()==0)//used fucntion eof means end of file  when no data foend loop will run ///
	{
        ifile>>s;
        cout<<s<<" ";
        
	}
	cout<<"\n";
	ifile.close();///file close/////
			
			
			
			
			
			
			
			/////
				
		 
   cout<<"Want to go back ? (y|n)"<<endl;
	     char yn;
	     cin>>yn;
	     if((yn=='Y')||(yn=='y'))
	     {
	     	
	     	system("CLS");
	       menu();
	     	
		 }
	     else if((yn=='n')||(yn=='n'))
	     {
	     	system("CLS");
	     Bill_Report();
		 }


}

                     ///Permanent File deleted////////////// 
                     
                     
void Delete_Product()//delete kry///
{

	

			 
			 
	int status;//integer//
	char fname[20];//filename type//
	cout<<"Enter name of file, you want to delete : ";
	cin>>fname;//file name Added//
	status=remove(fname);//remove function which runs with libary stdio.h //
	if(status==0)
	{
		cout<<"file "<<fname<<" deleted successfully..!!\n";//
	}
	else
	{
		cout<<"Unable to delete file "<<fname<<"\n";
		cout<<"Error!Error!Error!"<<endl;
	}
	getch();
			 
			 
		
			 
			 
    cout<<"Want to go back ? (y|n)"<<endl;
	     char yn;
	     cin>>yn;
	     if((yn=='Y')||(yn=='y'))
	     {
	     	
	     	system("CLS");
	        menu();
	     	
		 }
	     else if((yn=='n')||(yn=='n'))
	     {
	     	system("CLS");
	     Delete_Product();
		 }



	
}

                                   //*/////Run time show///////

void Show_Products()///////////showing products only run time go back to menu to see it dont close program//////////
{
	
	int total=0;
	total=total+price;
	cout<<"======================================================"<<endl;
		cout<<"                  4.  Show Products              "<<endl;
	cout<<"======================================================"<<endl;
	
	cout<<"Product Number : "<<ProNo<<endl;
	cout<<"Product Name  : "<<ProName<<endl;
	cout<<"Product Price : "<<price<<endl;
	cout<<"Product Quantity : "<<quant<<endl;
	cout<<"Product  Date : "<<d.dd<<d.mm<<d.yyyy<<endl;
	
	
						//:D//
			cout<<"======================================================"<<endl;
		     cout<<"                 Total Price      :            "<<total<<endl;
			cout<<"======================================================"<<endl;			
	    
		
		 cout<<"Want to go back ? (y|n)"<<endl;
	     char yn;
	     cin>>yn;
	     if((yn=='Y')||(yn=='y'))
	     {
	     	
	     	system("CLS");
	       menu();
	     	
		 }
	     else if((yn=='n')||(yn=='n'))
	     {
	     	system("CLS");
	     	Show_Products();
		 }
	
	
}
 										//////////Program Closed end /////////
int Exit()///:D///
{

			cout<<"Want to Exit ?? (y|n)"<<endl;
			char yn;
			cin>>yn;
			
			
			
			if((yn=='Y')||(yn=='y'))
			{
        
            system("CLS");
            
            cout<<"************************** THANKS **************************************";
            
            exit(0);
           
			}
     else  if((yn=='N')||(yn=='n'))
     {
     	system("CLS");
     	 menu();
	 }

return 0;
    

	
}
                                  /*******Main menu ***********//////choose options ///
void menu()
{
	
	int ch;
                                             //menu:
    cout<<"------------------------------------------------------------------------------------------"<<endl;
	cout<<"------------------------------------------------------------------------------------------"<<endl;
	cout<<"------------------------------------------------------------------------------------------"<<endl;
	cout<<"                                                                                          "<<endl;
	cout<<"                                                                                          "<<endl;
	cout<<"                             Super Market Billing System                                  "<<endl;
	cout<<"                                                         By Hamza Momin                                          "<<endl;
	cout<<"                                                                                          "<<endl;
	cout<<"------------------------------------------------------------------------------------------"<<endl;
	cout<<"------------------------------------------------------------------------------------------"<<endl;
	cout<<"   "<<endl;
   cout<<"-----------------------------------Main Menu-----------------------------------------"<<endl;
	cout<<" 1. Add Product"<<endl;
	cout<<" 2. Bill Report"<<endl;
	cout<<" 3. Delete Product"<<endl;
	cout<<" 4. Show Products"<<endl;
	cout<<" 5. Exit"<<endl;
	

				  	              
				  cout<<"Select Options  :  ";
					cin>>ch;
					while(1)   //user validation//
						{
							if(cin.fail())
			{
							cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(),'\n');
									cout<<"Select From Options 1 - 5!!!  :  ";
										cin>>ch;
		}
		
						if(!cin.fail())
						break;
	
	}
 
	
	
	
switch(ch)
	{
	
		case 1:
			
			{
				
				{
				
				
				Add_Product();//fucntion call//addes products to file//
		       
			   }
			   
			             break;
			
			}//end case 1///
	
	case 2 : 
				
	{
			Bill_Report();
	                       //total products and their total prices//
	
	}//end case 2//
	                     break;
	
	case 3 : 
	{
				 
		Delete_Product();///deletes file ///
		
	}


                     	break;
		
	case 4 : 
	{
				
		Show_Products();//products  show //
	// ;
	}

                       	break;
	
	
	case 5 :
		{
			Exit();////
	//	goto menu;
		}
	
		break;
	
    	}//end switch//

}//end menu//



int main()// main call other functions//
{
	
	
	
                                    //function call  no arguments no return value//
				 menu();
		
			
	
}//end main//


