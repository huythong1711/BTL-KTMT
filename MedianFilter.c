#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
  
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
  
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
  
int array[2000][2000];
int arr[2000][2000];
int main()
{
    clock t time_req
    int window[9],row = 0, col = 0, numrows = 0, numcols = 0,MAX=0;
    ifstream infile("Saltpepper.pgm");
    stringstream ss;
    string inputLine = "";
  
    // First line : version
    getline(infile,inputLine);
    if(inputLine.compare("P2") != 0) cerr << "Version error" << endl;
    else cout << "Version : " << inputLine << endl;
  
    // Continue with a stringstream
    ss << infile.rdbuf();
  
    // Secondline : size of image
    ss >> numcols >> numrows >> MAX;
  
    //print total number of rows, columns and maximum intensity of image
    cout << numcols << " columns and " << numrows << " rows" <<endl<<" 
    Maximium Intesity "<< MAX <<endl; 
  
  //Thoi gian thuc thuc thi vong lap
    //Initialize a new array of same size of image with 0
    for(row = 0; row <= numrows; ++row)
        array[row][0]=0;
    for( col = 0; col<=numcols; ++col )
        array[0][col]=0;
    time_req= clock()
    // Following lines : data
    for(row = 1; row <= numrows; ++row)
    {
        for (col = 1; col <= numcols; ++col)
        {
            //original data store in new array
            ss >> array[row][col]; 
        }
    }
  
  
    // Now print the array to see the result
    for(row = 1; row <= numrows; ++row)
    {
        for(col = 1; col <= numcols; ++col)
        {
            //neighbor pixel values are stored in window including this pixel
            window[0] = array[row-1][col-1];
            window[1] = array[row-1][col];
            window[2] = array[row-1][col+1];
            window[3] = array[row][col-1];
            window[4] = array[row][col];
            window[5] = array[row][col+1];
            window[6] = array[row+1][col-1];
            window[7] = array[row+1][col];
            window[8] = array[row+1][col+1];
  
            //sort window array
            insertionSort(window,9); 
            //put the median to the new array
            arr[row][col]=window[4];    
        }
    }
cout<< "time to request"<< (float)time_req/ CLOCKS_PER_SEC << "seconds" << endl;
  
    ofstream outfile;
      
    //new file open to stroe the output image
    outfile.open("Medianfilter.pnm");
    outfile<<"P2"<<endl;
    outfile<<numcols<<" "<<numrows<<endl;
    outfile<<"255"<<endl;
      
    for(row = 1; row <= numrows; ++row)
    {
        for (col = 1; col <= numcols; ++col)
        {
            //store resultant pixel values to the output file
            outfile << arr[row][col]<<" ";
        }
    }
      
    outfile.close();
    infile.close();
    return 0 ;
}
