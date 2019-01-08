/*main.cpp*/

//
// Chicago Crime Analysis program in modern C++.
//
// KRISTI GJONI
// U. of Illinois, Chicago
// CS 341: Spring 2018
// Project 02
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

#include "classes.h"

using namespace std;

//------------------------------------------------------------------------------------
// Print top five crimes
void printTopFiveCrimes(vector <CrimeCode>& CC){
  int m = 0;
  for(CrimeCode& s: CC){
    
    // print first crime
    if(m == 0){
    cout << s.getIucr() << "      " << s.getCount() << ",   " << s.getPrimary() << ": " << s.getSecondary() << endl;
    }
    
    // print second crime
    if(m == 1){
    cout << s.getIucr() << "      " << s.getCount() << ",   " << s.getPrimary() << ": " << s.getSecondary() << endl;
    }
    
    // print third crime
    if(m == 2){
    cout << s.getIucr() << "      " << s.getCount() << ",   " << s.getPrimary() << ": " << s.getSecondary() << endl;
    }
    
    // print fourth crime
    if(m == 3){
    cout << s.getIucr() << "      " << s.getCount() << ",   " << s.getPrimary() << ": " << s.getSecondary() << endl;
    }
    
    // print fifth crime
    if(m == 4){
    cout << s.getIucr() << "      " << s.getCount() << ",   " << s.getPrimary() << ": " << s.getSecondary() << endl;
    }
    m++;
    
  }
}
//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
// Sort top five crimes
void sortTopFiveCrimes(vector <CrimeCode>& CC){
  std::sort(CC.begin(), CC.end(),
            [](CrimeCode s1, CrimeCode s2)
            {
              if( s1.getCount() > s2.getCount()){
                return true;
              }
              else{
                return false;
              }
            }       
  );
}
//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
// Get a count for each crime 
void updateCrimeCount(vector <CrimeCode>& CC, vector <CrimeReport>& CR, int count_iucr){
  for(CrimeCode& s: CC){
    for(CrimeReport& c: CR){
      if(s.getIucr() == c.getIucr2()){
        s.updateCount(count_iucr);
      }
    }
  }
}
//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
// Print Crime Report (first 3 lines and last 3 lines)
void printCrimeReport(vector <CrimeReport>& CR){
  int j = 0;
  for(CrimeReport& s : CR){
    // Print first line
    if(j == 0){
      cout << s.getIucr2() << ":  " <<  s.getDateAndTime() << ", " << s.getBeat() <<
      ", " << s.getDistrict() << ", " << s.getWard() << ", " << s.getCommunity();
      if ((s.getArrest()) == true){
        cout << ", arrested";
      }
      if ((s.getDomestic()) == true){
        cout << ", domestic violence";
      }
      cout << endl;
    }
    // Print second line
    if(j == 1){
      cout << s.getIucr2() << ":  " <<  s.getDateAndTime() << ", " << s.getBeat() <<
      ", " << s.getDistrict() << ", " << s.getWard() << ", " << s.getCommunity();
      if ((s.getArrest()) == true){
        cout << ", arrested";
      }
      if ((s.getDomestic()) == true){
        cout << ", domestic violence";
      }
      cout << endl;
    }
    // Print third line
    if(j == 2){
      cout << s.getIucr2() << ":  " <<  s.getDateAndTime() << ", " << s.getBeat() <<
      ", " << s.getDistrict() << ", " << s.getWard() << ", " << s.getCommunity();
      if ((s.getArrest()) == true){
        cout << ", arrested";
      }
      if ((s.getDomestic()) == true){
        cout << ", domestic violence";
      }
      cout << endl;
    }
    if(j == 3){
      cout << "..." << endl;
    }
    // Print third-to-last line
    if(j == (CR.size() - 3)){
      cout << s.getIucr2() << ":  " <<  s.getDateAndTime() << ", " << s.getBeat() <<
      ", " << s.getDistrict() << ", " << s.getWard() << ", " << s.getCommunity(); 
      if ((s.getArrest()) == true){
        cout << ", arrested";
      }
      if ((s.getDomestic()) == true){
        cout << ", domestic violence";
      }
      cout << endl;
    }
    // Print second-to-last line
    if(j == (CR.size() - 2)){
      cout << s.getIucr2() << ":  " <<  s.getDateAndTime() << ", " << s.getBeat() <<
      ", " << s.getDistrict() << ", " << s.getWard() << ", " << s.getCommunity(); 
      if ((s.getArrest()) == true){
        cout << ", arrested";
      }
      if ((s.getDomestic()) == true){
        cout << ", domestic violence";
      }
      cout << endl;
    }
    // Print last line
    if(j == (CR.size() - 1)){
      cout << s.getIucr2() << ":  " <<  s.getDateAndTime() << ", " << s.getBeat() <<
      ", " << s.getDistrict() << ", " << s.getWard() << ", " << s.getCommunity(); 
      if ((s.getArrest()) == true){
        cout << ", arrested";
      }
      if ((s.getDomestic()) == true){
        cout << ", domestic violence";
      }
      cout << endl;
    }
      j++;      // update counter
  }
}
//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
// Print sorted Crime Code (first 3 lines and last 3 lines)
void printCrimeCode(vector <CrimeCode>& CC){
  int i = 0;
  for(CrimeCode& s : CC){
    // print first line
    if(i == 0){
      cout << s.getIucr() << ":  " << s.getPrimary() << ":" << s.getSecondary() <<
        endl;
    }
    // print second line
    if(i == 1){
      cout << s.getIucr() << ":  " << s.getPrimary() << ":" << s.getSecondary() <<
        endl;
    }
    // print third line
    if(i == 2){
      cout << s.getIucr() << ":  " << s.getPrimary() << ":" << s.getSecondary() << endl;
    }
    if(i == 3){
      cout << "..." << endl;
    }
    // print third-to-last line
    if(i == (CC.size() - 3)){
      cout << s.getIucr() << ":  " << s.getPrimary() << ":" << s.getSecondary() << endl;
    }
    // print second-to-last line
    if(i == (CC.size() - 2)){
      cout << s.getIucr() << ":  " << s.getPrimary() << ":" << s.getSecondary() << endl;
    }
    // print last line
    if(i == (CC.size() - 1)){
      cout << s.getIucr() << ":  " << s.getPrimary() << ":" << s.getSecondary() << endl;
    }
      i++;    // increment counter
  }
}
//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
// Sort the vector Crime Code by the crime code
void sortCrimeCode(vector<CrimeCode>& CC){
  std::sort(CC.begin(), CC.end(),
            [](CrimeCode s1, CrimeCode s2)
            {
              if( s1.getIucr() < s2.getIucr()){
                return true;
              }
              else{
                return false;
              }
            }       
  );
}
//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
// Print the date range from CrimeReport (already sorted)
void printDateRange(vector<CrimeReport>& CR){
  int x = 0;
  for(CrimeReport& s : CR){
    
    //print the first date
    if(x == 0){
      cout << s.getDateAndTime() << " - ";
    }
    
    // print the last date
    if(x == CR.size() - 1){
      cout << s.getDateAndTime() << endl;
    }
    x++;    // update counter
  }
  cout << endl;
}
//------------------------------------------------------------------------------------


int main()
{
  string  crimeCodesFilename, crimesFilename;

  cin >> crimeCodesFilename;
  cout << crimeCodesFilename << endl;
  
  cin >> crimesFilename;
  cout << crimesFilename << endl;

  ifstream  codesFile(crimeCodesFilename);
  ifstream  crimesFile(crimesFilename);

  cout << std::fixed;
  cout << std::setprecision(2);

  if (!codesFile.good())
  {
    cout << "**ERROR: cannot open crime codes file: '" << crimeCodesFilename << "'" << endl;
    return -1;
  }
  if (!crimesFile.good())
  {
    cout << "**ERROR: cannot open crimes file: '" << crimesFilename << "'" << endl;
    return -1;
  }
  
  // Declare variables
  std::vector <CrimeCode> CC;
  std::vector <CrimeReport> CR;
  string line, ignoreLine, iucr, primary_description, secondary_description, date_time, iucr_2, arrest, domestic, beat, district, ward, community, year;
  int count = 0;
  int counter = 0;
  int count_iucr = 0;
  
  // Ignore first line
  getline(codesFile, ignoreLine);
  
  // Read file from second line
  while(getline(codesFile, line))
  {
    stringstream ss(line);
    
    //parse line
    getline(ss, iucr, ',');
    getline(ss, primary_description, ',');
    getline(ss, secondary_description);
    
    CrimeCode S(iucr, primary_description, secondary_description);
    
    //insert at end
    CC.push_back(S);
  }
  
  // Ignore first line 
  getline(crimesFile, ignoreLine);
  
  // Read file from second line
  while(getline(crimesFile, line))
  {
    stringstream ss(line);
    
    //parse line
    getline(ss, date_time, ',');
    getline(ss, iucr_2 ,',');
    getline(ss, arrest , ',');
    getline(ss, domestic , ',');
    getline(ss, beat , ',');
    getline(ss, district , ',');
    getline(ss, ward , ',');
    getline(ss, community , ',');
    getline(ss, year);
    
    
    CrimeReport C(date_time, iucr_2, arrest, domestic, stoi(beat), stoi(district),
                  stoi(ward), stoi(community), stoi(year));
    
    //insert at end
    CR.push_back(C);
  }
  
    
  cout << "** Crime Analysis **" << endl;
  cout << endl;
  cout << "Date range: ";
  
  // Print date range
  printDateRange(CR);
  
  // for loop to get the count of the number of codes
  for(CrimeCode& s : CC){
    count++;      // update counter every iteration
  }
  
  cout << "# of crime codes: " << count << endl;
  
  // Sort CrimeCode 
  sortCrimeCode(CC);
  
  // Print sorted Crime Code
  printCrimeCode(CC);
  
  // for loop to get the count of the number of crimes
  for(int i = 0; i < CR.size(); i++){
    counter++;      // update counter every iteration
  }
  
  cout << endl;
  cout << "# of crimes: " << counter << endl;
  
  // Print Crime Report 
  printCrimeReport(CR);
  
  // Update the count for each crime
  updateCrimeCount(CC, CR, count_iucr);
  
  // Sort the top five crimes
  sortTopFiveCrimes(CC);
  
  cout << endl;
  cout << "** Top-5 Crimes **" << endl;
  cout << "Code:     Total,  Description" << endl; 
  
  // Print the top five crimes
  printTopFiveCrimes(CC);
  
  cout << endl;
  cout << "** Done **" << endl;
  
  return 0;
}

