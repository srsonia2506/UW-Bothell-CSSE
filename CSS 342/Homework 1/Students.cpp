//-----------------------------------------------------------------------------
// Data: last name, first name, and marks. (eg duck donald 50)
// Sort student data (by their last name) and ensure validity of grades
// Sort a list of students using a insertion sort.
// Conjures a histogram based on the filtered data
// 
// Assumptions, implementation details:  
//    -- Format of data is correct.
//    -- All names are no more in length than MAXLENGTH.
//    -- Data beyond MAXSIZE number of names is not stored in the list. 

#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int const MAXSIZE = 100;            // maximum number of records in total
int const MAXLENGTH = 31;           // maximum string length 
int const MAXGRADE = 100;           // highest possible grade
int const LOWGRADE = 0;             // lowest possible grade
int const GROUP = 10;               // group amount
int const HISTOGRAMSIZE = (MAXGRADE - LOWGRADE) / GROUP + 1;    // grouped by GROUP

struct StudentType {                 // information of one student
    int grade;                       // the grade of the student
    char last[MAXLENGTH];            // last name (MAXLENGTH-1 at most)
    char first[MAXLENGTH];           // first name (MAXLENGTH-1 at most)
};

// prototypes go here
// reads and sorts data for students arr
bool sortInput(istream&, StudentType[], int&);
// print the list of students
void displayList(const StudentType[], int);      
// average of the student grades
int findAverage(const StudentType[], int);
// choose elements for the histogram array
void setHistogram(const StudentType[], int[], int);
// prints histogram
void displayHistogram(int[], int);               

//-----------------------------------------------------------------------------
int main() {
    StudentType students[MAXSIZE];   // list of MAXSIZE number of students
    int size = 0;                    // total number of students
    int histogram[HISTOGRAMSIZE];    // grades grouped by GROUP
    int average = 0;                 // average exam score, truncated

    // creates file object and opens the data file
    ifstream infile("data1.txt");
    if (!infile) {
        cout << "File could not be opened." << endl;
        return 1;
    }

    // read and sort input by last then first name
    bool successfulRead = sortInput(infile, students, size);
    
    // display list, histogram, and class average 
    if (successfulRead) {
        displayList(students, size);
        setHistogram(students, histogram, size);
        displayHistogram(histogram, size);
        average = findAverage(students, size);
        cout << "Average grade: " << average << endl << endl;
    }
    infile.close();
    return 0;
}

//-----------------------------------------------------------------------------
// sortInput
// reads and sorts data in students arr by last name using insertion sort
// students with invalid scores ie below 0 or above 100 ignored

bool sortInput(istream& infile, StudentType studentClass[], int& size) {
    while (size < MAXSIZE && !infile.eof()) {
        StudentType temp;
        infile >> temp.last >> temp.first >> temp.grade;
        if (temp.grade >= LOWGRADE && temp.grade <= MAXGRADE) {
            //cout << temp.last << endl;
            int i;
            for (i = size - 1; 0 <= i; i--) {
               if (strncmp(temp.last, studentClass[i].last, MAXLENGTH) < 0) {
                    studentClass[i + 1] = studentClass[i];
               }else if((strncmp(temp.last,studentClass[i].last,MAXLENGTH) == 0)
                  && (strncmp(temp.first,studentClass[i].first,MAXLENGTH) < 0)){
                    studentClass[i + 1] = studentClass[i];
               }else
                    break;
               }
               studentClass[i + 1] = temp;
               size++;
            }
        }
    return true;

}

//-----------------------------------------------------------------------------
// displayList
// print the list of students in the following format:
// grades, last Name, first Name

void displayList(const StudentType studentClass[], int size) {
    cout << "List of names sorted :" << endl;
    for (int i = 0; i < size; i++)
        cout << setw(3) << studentClass[i].grade
        <<  " "  << studentClass[i].last
        << " " << studentClass[i].first << endl;
    cout << endl;
}

//-----------------------------------------------------------------------------
// findAverage
// finds the average grades in the StudentClass arrau

int findAverage(const StudentType studentClass[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)sum += studentClass[i].grade;
    return sum / size;
}

//-----------------------------------------------------------------------------
// setHistogram
// Determining the values to be used for the histogram

void setHistogram(const StudentType stud[], int histogram[], int size) {
    for (int i = 0; i < HISTOGRAMSIZE; i++) {
        histogram[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        histogram[stud[i].grade/10]++;
    }

    //testing code
    /*for (int i = 0; i < HISTOGRAMSIZE; i++) {
       cout << histogram[i] << endl;
    }*/
}

//-----------------------------------------------------------------------------
// displayHistogram
// print the histogram for the list of students

void displayHistogram(int histogram[], int size) {
    cout << "Histogram of grades :" << endl;
    int min = 0;
    for (int min = 0; min <= 99; min += 10) {
        cout << setw(3) << min << "-->" << setw(4) << min +9 << ": ";
        for (int i = 0; i < histogram[min / 10]; i++) {
            cout << "*";
        }
        cout << endl;
    }
    cout << setw(3) << MAXGRADE << "-->" << setw(4) << MAXGRADE << ": ";
    for (int i = 0; i < histogram[min / 10]; i++) {
        cout << "*";
    }
    cout << endl << endl;
}
