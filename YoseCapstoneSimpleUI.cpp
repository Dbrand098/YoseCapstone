#include <iostream>
#include <sqlite3.h>
#include <string>
#include <stdio.h>

using namespace std;

static int callback(void* data, int argc, char** argv, char** azColName){ 
    int i; 
    fprintf(stderr, "%s", (const char*)data); 
  
    for (i = 0; i < argc; i++) { 
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
    } 
  
    printf("\n"); 
    return 0; 

}

//BEGINING OF REMOVE FUNCTIONS
static int removeMRA(sqlite3* DB,string data){
    //insert logic here
    std::string mraid;
    int update_option = 0;
    std::cout << "Which Minimum Requirement Analysis would you like to remove? (mraid) \n";
    std::cin >> mraid;
    
    std::string sqlquery = "DELETE FROM MRA WHERE MRA_ID = " + mraid + " \n";
    std::cout << sqlquery;
  
    std::string sql(sqlquery); 
  
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 

    return (0); 
}
  
static int removePermit(sqlite3* DB,string data){
    //insert logic here
    std::string perid;
    int update_option = 0;
    std::cout << "Which Permit would you like to remove? (perid) \n";
    std::cin >> perid;
    
    std::string sqlquery = "DELETE FROM Permit WHERE PERMIT_ID = " + perid + " \n";
    std::cout << sqlquery;
  
    std::string sql(sqlquery); 
  
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 

    return (0); 
}
    
static int removePI(sqlite3* DB,string data){
    //insert logic here
    std::string piid;
    int update_option = 0;
    std::cout << "Which Private Investigator would you like to remove? (vacid) \n";
    std::cin >> piid;
    
    std::string sqlquery = "DELETE FROM PI WHERE PI_ID = "+piid+" \n";
    std::cout << sqlquery;
  
    std::string sql(sqlquery); 
  
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 

    return (0); 
}

static int removeAddendum(sqlite3* DB,string data){
    //insert logic here
    std::string addid;
    int update_option = 0;
    std::cout << "Which Addendum would you like to remove? (addid) \n";
    std::cin >> addid;
    
    std::string sqlquery = "DELETE FROM Addendum WHERE ADD_ID = " + addid + " \n";
    std::cout << sqlquery;
  
    std::string sql(sqlquery); 
  
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 

    return (0); 
}

//BEGINING OF ADDING FUNCTIONS
static int insertMRA(sqlite3* DB,string data){
    //inserty additional logic here
    std::string mraid;
    int update_option = 0;

    std::string MRA_ID, MRA_TITLE, STUDY_ID, MRA_YEAR, MRA_LINK, GIS_LINK;
    std::cout << "What would you like to insert? \n";
    std::cout << "MRA_ID?, " << "MRA_TITLE?, " << "STUDY_ID?, " << "MRA_YEAR?, " << "MRA_LINK?, " << "GIS_LINK?\n";
    std::cin >> MRA_ID >> MRA_TITLE >> STUDY_ID >> MRA_YEAR >> MRA_LINK >> GIS_LINK;

    std::string sqlquery = "INSERT INTO MRA Values ('" + MRA_ID + "', '" + MRA_TITLE + "', '" + STUDY_ID + "', '" + MRA_YEAR + "', '" + MRA_LINK + "', '" + GIS_LINK + "') \n";
    std::cout << sqlquery;
  
    std::string sql(sqlquery); 

  
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
    return (0); 
}//MRA insert function created

static int insertPermit(sqlite3* DB,string data){
    //inserty additional logic here
    std::string perid;
    int update_option = 0;

    std::string PERMIT_ID, PERMIT_TITLE, PI_ID, STUDY_ID, PERMIT_START, PERMIT_END, PERMIT_YEAR, PERMIT_LINK;
    std::cout << "What would you like to insert? \n";
    std::cout << "PERMIT_ID?, " << "PERMIT_TITLE?, " << "PI_ID?, " << "STUDY_ID?, " << "PERMIT_START?, " << "PERMIT_END?, " << "PERMIT_END? , " << "PERMIT_YEAR, " << "PERMIT_LINK?\n";
    std::cin >> PERMIT_ID >> PERMIT_TITLE >> PI_ID >> STUDY_ID >> PERMIT_START >> PERMIT_END >> PERMIT_YEAR >> PERMIT_LINK;

    std::string sqlquery = "INSERT INTO Permit Values ('" + PERMIT_ID + "', '" + PERMIT_TITLE + "', '" + PI_ID + "', '" + STUDY_ID + "', '" + PERMIT_START + "', '" + PERMIT_END + "', '" + PERMIT_END + "', '" + PERMIT_YEAR + "', '" + PERMIT_LINK + "') \n";
    std::cout << sqlquery;
  
    std::string sql(sqlquery); 

  
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
    return (0); 
}// Permit insert function created
   
static int insertPI(sqlite3* DB,string data){
    //inserty additional logic here
    std::string piid;
    int update_option = 0;

    std::string PI_ID, PI_NAME, PI_PHONE, PI_EMAIL;
    std::cout << "What would you like to insert? \n";
    std::cout << "PI_ID?, " << "PI_NAME?, " << "PI_PHONE?, " << "PI_EMAIL?\n";
    std::cin >> PI_ID >> PI_NAME >> PI_PHONE >> PI_EMAIL;

    std::string sqlquery = "INSERT INTO PI Values ('"+PI_ID+"', '"+PI_NAME+"', '"+PI_PHONE+"', '"+PI_EMAIL+"') \n";
    std::cout << sqlquery;
  
    std::string sql(sqlquery); 

  
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
    return (0); 
} //function adding PI data crea

static int insertAddendum(sqlite3* DB,string data){
    //insert additional logic here
    std::string addid;
    int update_option = 0;

    std::string ADD_ID, ADD_TITLE, MRA_ID, ADD_YEAR, ADD_LINK;
    std::cout << "What would you like to insert? \n";
    std::cout << "ADD_ID?, " << "ADD_TITLE?, " << "MRA_ID?, " << "ADD_YEAR?, " << "ADD_LINK?\n";
    std::cin >> ADD_ID >> ADD_TITLE >> MRA_ID >> ADD_YEAR >> ADD_LINK;

    std::string sqlquery = "INSERT INTO Addendum Values ('" + ADD_ID + "', '" + ADD_TITLE + "', '" + MRA_ID + "', '" + ADD_YEAR + "', '" + ADD_LINK + "') \n";
    std::cout << sqlquery;
  
    std::string sql(sqlquery); 

  
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
    return (0); 
}// Permit insert function created

//BEGINING OF MODIFYING FUNCTIONS
static int modifyMRA(sqlite3* DB,string data){

    std::string MRAID;
    int update_option = 0;
    std::cout << "Which MRA would you like to update? (MRA_ID) \n";
    std::cin >> MRAID;
    std:: cout << "What information do you want to update? \n";
    std:: cout << "Press 1 to change the MRA title \n";
    std:: cout << "Press 2 to change the Study ID \n";
    std:: cout << "Press 3 to change the MRA Year \n";
    std:: cout << "Press 4 to change the MRA Link \n";
    std:: cout << "Press 5 to change the GIS Link \n";

    std::cin >> update_option;

    std::string option;
    if (update_option == 1){
    	option = "MRA_TITLE";
    }
    else if (update_option == 2){
    	option = "STUDY_ID";
    }
    else if (update_option == 3){
    	option = "MRA_YEAR";
    }
    else if (update_option == 4){
    	option = "MRA_LINK";
    }
    else if (update_option == 5){
    	option = "GIS_LINK";
    }
    std::string modify;
    std::cout << "What would you like to change it to? \n";
    std::cin >> modify;
    //std::getline(std::cin,modify);
    
    std::string sqlquery = "Update MRA SET "+option+" = '"+modify+"' WHERE MRA_ID = " + MRAID + "\n";
    std::cout << sqlquery;
  
    std::string sql(sqlquery); 

  
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
    return (0); 
}

static int modifyPI(sqlite3* DB,string data){

    std::string PIID;
    int update_option = 0;
    std::cout << "Which PI would you like to update? (PI_ID) \n";
    std::cin >> PIID;
    std:: cout << "What information do you want to update? \n";
    std:: cout << "Press 1 to change the PI name \n";
    std:: cout << "Press 2 to change the PI phone number \n";
    std:: cout << "Press 3 to change the PI email \n";

    std::cin >> update_option;

    std::string option;
    if (update_option == 1){
    	option = "PI_NAME";
    }
    else if (update_option == 2){
    	option = "PI_PHONE";
    }
    else if (update_option == 3){
    	option = "PI_EMAIL";
    }
    std::string modify;
    std::cout << "What would you like to change it to? \n";
    std::cin >> modify;
    //std::getline(std::cin,modify);
    
    std::string sqlquery = "Update PI SET "+option+" = '"+modify+"' WHERE PI_ID = " + PIID + "\n";
    std::cout << sqlquery;
  
    std::string sql(sqlquery); 

  
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
    return (0); 
}

static int modifyPermit(sqlite3* DB,string data){

    std::string PERID;
    int update_option = 0;
    std::cout << "Which Permit would you like to update? (PERMIT_ID) \n";
    std::cin >> PERID;
    std:: cout << "What information do you want to update? \n";
    std:: cout << "Press 1 to change the Permit Title \n";
    std:: cout << "Press 2 to change the Private Investigator ID \n";
    std:: cout << "Press 3 to change the Study ID \n";
    std:: cout << "Press 4 to change the Permit Start \n";
    std:: cout << "Press 5 to change the Permit End \n";
    std:: cout << "Press 6 to change the Permit Year \n";
    std:: cout << "Press 7 to change the Permit Link \n";

    std::cin >> update_option;

    std::string option;
    if (update_option == 1){
    	option = "PERMIT_TITLE";
    }
    else if (update_option == 2){
    	option = "PI_ID";
    }
    else if (update_option == 3){
    	option = "STUDY_ID";
    }
    else if (update_option == 4){
    	option = "PERMIT_START";
    }
    else if (update_option == 5){
    	option = "PERMIT_END";
    }
    else if(update_option == 6){
        option = "PERMIT_YEAR";
    }
    else if(update_option == 7){
        option = "PERMIT_LINK";
    }
    std::string modify;
    std::cout << "What would you like to change it to? \n";
    std::cin >> modify;
    //std::getline(std::cin,modify);
    
    std::string sqlquery = "Update Permit SET " + option + " = '" + modify + "' WHERE PERMIT_ID = " + PERID + "\n";
    std::cout << sqlquery;
  
    std::string sql(sqlquery); 

  
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
    return (0); 
} 

static int modifyAddendum(sqlite3* DB,string data){
    //insert logic here
     std::string ADDID;
    int update_option = 0;
    std::cout << "Which Addendum would you like to update? (ADD_ID) \n";
    std::cin >> ADDID;
    std:: cout << "What information do you want to update? \n";
    std:: cout << "Press 1 to change the Addendum Title \n";
    std:: cout << "Press 2 to change the MRA ID \n";
    std:: cout << "Press 3 to change the Addendum Year \n";
    std:: cout << "Press 4 to change the Addendum Link \n";

    std::cin >> update_option;

    std::string option;
    if (update_option == 1){
    	option = "ADD_TITLE";
    }
    else if (update_option == 2){
    	option = "MRA_ID";
    }
    else if (update_option == 3){
    	option = "ADD_YEAR";
    }
    else if (update_option == 4){
    	option = "ADD_LINK";
    }
    std::string modify;
    std::cout << "What would you like to change it to? \n";
    std::cin >> modify;
    //std::getline(std::cin,modify);
    
    std::string sqlquery = "Update Addendum SET " + option + " = '" + modify + "' WHERE ADD_ID = " + ADDID + "\n";    
    std::cout << sqlquery;
  
    std::string sql(sqlquery); 

  
    int rc = sqlite3_exec(DB, sql.c_str(), NULL, (void*)data.c_str(), NULL); 
  
    if(rc != SQLITE_OK){ 
        std::cerr << "Error SELECT" << std::endl; 
    }else{ 
        std::cout << "Operation OK!" << std::endl; 
    } 
    return (0); 
}

// ALL OF THE FUNCTIONS BELOW CALL FOR ADDITIONAL FUCTIONS FOR adding, removing, OR modifying EXISTING PARAMETERS FOR MRAs, Permits, PIs, & Addendums.
int modify(sqlite3* DB,string data){                                       //work on this function Brandon
	std::cout << "Press 1 to modify data in the MRA Table \n";
	std::cout << "Press 2 to modify data in the Permit Table \n";
	std::cout << "Press 3 to modify data in the PI Table \n";
	std::cout << "Press 4 to modify data in the Addendum Table \n";
	int interest = 0;
	std::cin >> interest;

	    if(interest == 1){      
		    modifyMRA(DB, data);
	    }
	    else if(interest == 2){  
	    	modifyPermit(DB, data);    
    	}
        else if(interest == 3){ 
           modifyPI(DB, data);
        }
        else if(interest == 4){  
            modifyAddendum(DB, data);   
        }

	return 0;
}

int remove(sqlite3* DB,string data){       //work on this function Brandon
                                
	    std::cout << "Press 1 to remove data from the MRA Table \n";
	    std::cout << "Press 2 to remove data from the Permit Table \n";
	    std::cout << "Press 3 to remove data from the PI Table \n";
	    std::cout << "Press 4 to remove data from the Addendum Table \n";
	    int interest = 0;
	    std::cin >> interest;

        if(interest == 1){
            removeMRA(DB, data);//remove MRA data function created and finished
         }
        else if(interest == 2 ){
            removePermit(DB, data);//remove Permit data function created
        }
        else if(interest == 3){
	 	    removePI(DB, data); //function for PI data removal create
        }
	    else if(interest = 4){
	 	    removeAddendum(DB, data); //function for Addendums has been commented out
        }	 
	return 0;
}

static int insert(sqlite3* DB,string data){              //work on this function Brandon
	
	    std::cout << "Press 1 to insert data into the MRA Table \n";
	    std::cout << "Press 2 to insert data into the Permit Table \n";
	    std::cout << "Press 3 to insert data into the PI Table \n";
	    std::cout << "Press 4 to insert data into the Addendum Table \n";
	    int interest = 0;
	    std::cin >> interest;
	
        if(interest == 1){
            insertMRA(DB, data);//MRA insert function created
        }
        else if(interest == 2){
            insertPermit(DB, data);// Permit insert function created
        }
        else if(interest == 3){
	    	insertPI(DB, data); //function adding PI data created
	    }
        else if(interest == 4){
	    	insertAddendum(DB, data); //Function adding Addendum created.
        }

	return 0;
}


//ALL OF THESE FUNCTIONS BELOW ARE QUERIES
static int MRAList(sqlite3* DB,string data){ 
    std::string sql("SELECT MRA_ID AS ID, MRA_TITLE AS Title,STUDY_ID AS StudyNum,MRA_YEAR AS YEAR, MRA_LINK AS Link FROM MRA"); 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
    return (0); 
} 
static int PermitList(sqlite3* DB,string data){ 

    std::string sql("SELECT PERMIT_ID AS ID, PERMIT_TITLE AS Title,PI_NAME AS Investigator,STUDY_ID AS StudyNum,PERMIT_YEAR AS YEAR, PERMIT_START AS StartDate, PERMIT_END AS EndDate FROM Permit AS P, PI AS I WHERE P.PI_ID = I.PI_ID"); 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    }  
    return (0); 
} 
static int PIList(sqlite3* DB,string data){ 
  
    std::string sql("SELECT PI_ID AS ID, PI_NAME AS Investigator, PI_PHONE AS Phone, PI_EMAIL AS Email FROM PI"); 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    } 
    return (0); 
} 
static int ADDList(sqlite3* DB,string data){ 

    std::string sql("SELECT ADD_ID AS ID, ADD_TITLE AS Title, MRA_ID, ADD_YEAR AS YearSubmitted, ADD_LINK AS Link FROM Addendum"); 

    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        std::cerr << "Error SELECT" << std::endl; 
    else { 
        std::cout << "Operation OK!" << std::endl; 
    }
    return (0); 
} 

static int user(sqlite3* DB,string data){
	std::cout << "WELCOME TO THE YOSECAPSTONE SIMPLE UI \n" << std::endl;
	std::cout << "Press 1 to view all MRAs in our Database \n";
	std::cout << "Press 2 to view all Permits in our Database \n";
	std::cout << "Press 3 to view all PIs in our Database \n";
	std::cout << "Press 4 to view all Addendums in our Database \n";
	std::cout << "Press 5 to Modify Data in the Database. \n";
	std::cout << "Press 6 to Remove Data from the Database. \n";
	std::cout << "Press 7 to Insert Data to the Database. \n";


	int x = 0;
	std::cin >> x;

	if (x == 1){
		MRAList(DB, data);
	}
	else if(x == 2){
		PermitList(DB, data);
	}
	else if(x == 3){
		PIList(DB, data);
	}
	else if(x == 4){
		ADDList(DB, data);
	}
	else if(x == 5){
		modify(DB, data);
	}
    else if(x == 6){
    	remove(DB, data);
    }
	else if (x == 7){
	 	insert(DB, data);
	}

	return 0;
}

//MAIN FUNCTION
int main(int argc, char** argv)
{
	sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("YoseCapstone.db", &DB); 
    std::string data("\n"); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else{
    	user(DB, data);
    }

    sqlite3_close(DB); 

	return(0);
}