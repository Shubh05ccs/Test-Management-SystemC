#include<iostream>
#include<fstream>
using namespace std;
main()
{
	ifstream fin;
	ofstream fout;
	string ques,op1,op2,op3,op4,ans,x ,id, name, section , result , N;
	int ch,i,n,f,c1=0,c2=0,c3=0 ,p1,p2, pass ,standard,tm;
	
	while(true)
	{
		cout<<" Press 1 for Admin Login , Press 2 for Student Registration & Taking Test :-- ";
	    cin>>ch;
	    if(ch==1)
	    {
	    	// Admin Login & Check 
		    cout<<" Welcome Admin\n";
		    cout<<" Enter your Login Details :-- \n";
		
		    while(true)
			{
		    	cout<<" Enter Id & Password :--\n";
		        cin>>id>>pass;
		    
                if( ! (id=="ABC" && pass==123))
                {
        	        cout<<" Wrong Credentials , Enter the correct one !\n " ;
                }
                else
                {
            		// Adding Question and saving to a file .
		            cout<<" Enter no of ques you want for Test :-- \n";
	    	        cin>>n;
	    	        fout.open("Test_Question_Project.txt",ios::app);
	    	        for(i=1;i<=n;i=i+1)
		            {
	    	    	    cout<<" Enter Question, op1, op2, op3, op4, Ans, Total Marks :-- \n";
			            cin.ignore(); // Ignore newline left in the buffer.
                        getline(cin, ques);
	    		        cin>> ques>> op1>> op2>> op3>> op4>> ans>> tm;
			
                        fout<< ques << "\t" << op1 << "\t" << op2 << "\t" << op3 << "\t" << op4 << "\t" << ans << "\n";
					    fout<< tm << "\n";
	    		    }
	    		    cout<<"Your Question are saved successfully ! \n";
    		        fout.close();
    		        break;
                }
            }
		}
	    else if(ch==2)
	    {
		    cout<<" Welcome Student ! \n";
		    
		    while(true)
			{
	            cout<< "1) To Register yourself press - 1 \n2) To start Assesment press - 2  \n3) To Main Menu press - 3 \n4) To Exit press - 4\n";
	    	    cin>>ch;
	    	    
	    	    if(ch==1)
				{
	    	    	// Registration for student , name saving to new file & Check .
	    		    fout.open ("Student_Details_Project.txt",ios::app);
	    		
    		        cout<<" Enter your Full Name , Class , Section :-- \n";
    		        cin.ignore(); // Ignore newline left in the buffer.
                    getline(cin, ques);
    		        cin>> standard >> section ; 
    		    
    		        if(standard == 5 && section == "A")
    		        {
    		            fout<< name << "\t" << standard << "\t" << section << "\n";
    		    	    cout<<" You have Registered Successfully \n Thank-You ! \n";
				    }
				    else
				    {
					    cout<<" You are Not Eligible ! ";
				    }
    		        fout.close();
    		        
    		    
    		        while(true)
				    {
				    	cout<<"Continue to take Test press - 0 \nTo move out press - 9 \n";
    		    	    cin>>ch;
    		    	
	        	        if(ch == 0)
	        	        {
	        		       break;   // Go back to the beginning of the loop.
	    	            }
	    	            else if(ch == 9)
				        {
					        break;	// Move out of the current loop.
				        }    
	    	            else
	    	            {
	    	            	cout<<"Invalid Input !";
						}
	    	        }
	    	        
	    	        if (ch == 0)
                    {
                        continue; // Go back to the beginning of the loop.
                    }
                    else
                    {
                        break; // Move out of the current loop.
                    }
				}

	    		if(ch==2)
	    	    {
	    	        cout<<" Welcome Student ! \n Enter above details asked to verify :-- \n";
        		    fin.open ("Student_Details_Project.txt",ios::app);
        		    
        		    //Checking your Name and starting Assesment 
	    	
	                cout<<" Enter your Full Name(Name_Surname) :-- \n";
	    	        cin.ignore();
                    getline(cin, N);
	    	        
	    	        bool found = false;
                    while (fin >> name >> standard >> section)
                    {
                        if (name == N)
                        {
                            found = true;
                            break;
                        }
                    }

                    fin.close();

                    if (found)
                    {
                        cout << "Welcome " << N << "\n";
                        cout << "Assessment Started. All the Best!\n";

                        fin.open("Test_Question_Project.txt");

                        while (fin >> ques >> op1 >> op2 >> op3 >> op4 >> ans >> tm)
                        {
                            cout << "Question=> " << ques << "\n1) " << op1 << "\n2) " << op2 << "\n3) " << op3 << "\n4) " << op4 << "\n";
                            cout << "Total Marks-> " << tm << "\n";
                            cout << "Enter the answer = \t";

                            cin >> x;
                            if (x == ans)
                            {
                                c1 = c1 + tm;
                            }
                            else
                            {
                                c2 = c2 + tm;
                            }
                        }

                        cout << "Result will come shortly within 1-2 min :--\n";
                        cout << "\n";
                        cin.ignore();
                        system("pause");

                        c3 = c1 + c2;

                        // Percentage & Pass Fail
                        if (c3 > 0)
                        {
                            p1 = static_cast<double>(c1 * 100 / c3);
                            p2 = static_cast<double>(c2 * 100 / c3);

                            if (p1 >= 40)
                            {
                                cout << "PASS. Your percentage is " << p1 << "%\n";
                            }
                            else
                            {
                                cout << "FAIL. Your percentage is " << p2 << "%\n";
                            }
                        }
                        else
                        {
                            cout << "No marks obtained. Result not available.\n";
                        }

                        fin.close();
                        cout << "Thank you!\n";
                    }
                    else
                    {
                        cout << "You have not registered!\n";
                    }
	            }
	            
		        if(ch==3)
    		    {
    		        break;
			    }
			
    	        if(ch==4)
    	        {
    	    	    cout<<" Thank-You ! \n" ;   // Exit the program.
    	        }
		    }
	    }
    }
}







